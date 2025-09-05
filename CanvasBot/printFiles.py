#!/usr/bin/env python3
"""
List all *accessible* files in a Canvas course by walking Modules.

Usage:
  python printFiles.py \
    --base-url https://your.canvas.domain \
    --token-file ~/.canvas_token \
    --course-id 122711 \
    [--show-urls]
"""
import argparse, json, os, sys, time
from collections import defaultdict
from typing import Dict, Iterable, List, Optional
import requests

# ---------- auth & helpers ----------

def read_token(path: str) -> str:
    with open(os.path.expanduser(path), "r", encoding="utf-8") as f:
        content = f.read().strip()
    if not content:
        sys.exit("Token file is empty.")
    if content[:1] in "{[":
        data = json.loads(content)
        for k in ("token", "access_token", "api_token"):
            if k in data and str(data[k]).strip():
                return str(data[k]).strip()
        sys.exit("JSON token file missing 'token' or 'access_token'.")
    return content.splitlines()[0].strip()

def session(base_url: str, token: str) -> requests.Session:
    s = requests.Session()
    s.base_url = base_url.rstrip("/")  # type: ignore[attr-defined]
    s.headers.update({
        "Authorization": f"Bearer {token}",
        "Accept": "application/json",
        "User-Agent": "canvas-mod-files/0.1",
    })
    return s

def get_with_retry(sess: requests.Session, url: str, params=None, max_tries=5) -> requests.Response:
    """Handle Canvas 403 rate-limit retries; raise for other 4xx/5xx."""
    for attempt in range(1, max_tries + 1):
        r = sess.get(url, params=params, timeout=30)
        if r.status_code != 403:
            r.raise_for_status()
            return r
        body = (r.text or "").lower()
        if "rate limit exceeded" in body:
            time.sleep(min(2 ** attempt, 30))  # exponential backoff
            continue
        r.raise_for_status()
    r.raise_for_status()

def iter_paginated(sess: requests.Session, url: str, params: Optional[dict] = None) -> Iterable[dict]:
    next_url, next_params = url, dict(params or {}, per_page=100)
    while next_url:
        r = get_with_retry(sess, next_url, next_params)
        data = r.json()
        if isinstance(data, list):
            for item in data:
                yield item
        else:
            yield data
        next_url = None
        link = r.headers.get("Link", "")
        for part in link.split(","):
            segs = [s.strip() for s in part.split(";")]
            if len(segs) >= 2 and segs[1] == 'rel="next"':
                if segs[0].startswith("<") and segs[0].endswith(">"):
                    next_url = segs[0][1:-1]
                break
        next_params = None

# ---------- Canvas fetchers ----------

def fetch_modules(sess: requests.Session, course_id: int) -> List[dict]:
    url = f"{sess.base_url}/api/v1/courses/{course_id}/modules"
    return list(iter_paginated(sess, url))

def fetch_module_items(sess: requests.Session, course_id: int, module_id: int) -> List[dict]:
    url = f"{sess.base_url}/api/v1/courses/{course_id}/modules/{module_id}/items"
    return list(iter_paginated(sess, url))

def fetch_file(sess: requests.Session, file_id: int) -> dict:
    url = f"{sess.base_url}/api/v1/files/{file_id}"
    return get_with_retry(sess, url).json()

# ---------- bytes formatting ----------

_UNITS = ["B", "KB", "MB", "GB", "TB"]
def human_bytes(n: Optional[int]) -> str:
    if n is None: return "?"
    f = float(n); u = 0
    while f >= 1024 and u < len(_UNITS) - 1:
        f /= 1024.0; u += 1
    return f"{f:.1f} {_UNITS[u]}"

# ---------- main ----------

def main():
    ap = argparse.ArgumentParser(description="List Canvas course files via Modules (student-safe).")
    ap.add_argument("--base-url", required=True)
    ap.add_argument("--token-file", required=True)
    ap.add_argument("--course-id", required=True, type=int)
    ap.add_argument("--show-urls", action="store_true")
    args = ap.parse_args()

    tok = read_token(args.token_file)
    sess = session(args.base_url, tok)

    modules = fetch_modules(sess, args.course_id)
    seen: Dict[int, dict] = {}
    grouped = defaultdict(list)

    for m in modules:
        mid = m["id"]; mname = m.get("name", f"Module {mid}")
        for it in fetch_module_items(sess, args.course_id, mid):
            if it.get("type") == "File" and it.get("content_id"):
                fid = int(it["content_id"])
                if fid not in seen:
                    try:
                        fobj = fetch_file(sess, fid)
                        seen[fid] = fobj
                    except requests.HTTPError:
                        # locked or not visible yet
                        continue
                grouped[mname].append(seen[fid])

    if not any(grouped.values()):
        print("(no accessible files via Modules)")
        return

    # Stable output
    for mname in sorted(grouped.keys(), key=str.lower):
        print(f"\n=== 📚 {mname} ===")
        for f in sorted(grouped[mname], key=lambda x: str(x.get("display_name") or x.get("filename") or "").lower()):
            name = f.get("display_name") or f.get("filename") or f"file-{f.get('id')}"
            size = human_bytes(f.get("size"))
            updated = f.get("updated_at") or f.get("modified_at") or ""
            flags = []
            if f.get("locked_for_user"): flags.append("🔒 locked")
            if f.get("hidden"): flags.append("🙈 hidden")
            flags_str = f" [{' | '.join(flags)}]" if flags else ""
            print(f"  📄 {name} (id={f.get('id')}, {size}, updated {updated}){flags_str}")
            if args.show_urls:
                u = f.get("url") or f.get("href") or ""
                if u: print(f"      → {u}")

if __name__ == "__main__":
    main()
