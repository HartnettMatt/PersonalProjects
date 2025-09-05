#!/usr/bin/env python3
"""
List all *accessible* files in a Canvas course by walking Modules and (optionally)
download them into a local directory structure that mirrors Canvas folders.

Usage:
  python printFiles.py \
    --base-url https://your.canvas.domain \
    --token-file ~/.canvas_token \
    --course-id 122711 \
    [--show-urls] [--download --output-dir ./Downloads/ECEN4003]

Notes:
- Files are discovered via Modules (Module Items of type "File"), then each file
  is resolved with GET /api/v1/files/:id. Module Items schema includes
  `type` and `content_id`.  [Modules docs]  :contentReference[oaicite:1]{index=1}
- Folder paths are derived from GET /api/v1/folders/:id (uses `full_name`
  and `parent_folder_id`) and we strip the leading "course files/". [Files/Folder docs]  :contentReference[oaicite:2]{index=2}
- Download URLs are obtained from GET /api/v1/files/:id/public_url (preferred),
  or from the file object's `url` as a fallback. [Files docs]  :contentReference[oaicite:3]{index=3}
- Handles Canvas throttling (403 "Rate Limit Exceeded") with backoff. [Throttling]  :contentReference[oaicite:4]{index=4}
"""
import argparse
import json
import os
import re
import sys
import time
from collections import defaultdict
from typing import Dict, Iterable, List, Optional, Tuple

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
        "User-Agent": "canvas-mod-files/0.2",
    })
    return s

def get_with_retry(sess: requests.Session, url: str, params=None, max_tries: int = 5) -> requests.Response:
    """Handle Canvas 403 throttling; raise for other 4xx/5xx."""
    for attempt in range(1, max_tries + 1):
        r = sess.get(url, params=params, timeout=30)
        if r.status_code != 403:
            r.raise_for_status()
            return r
        body = (r.text or "").lower()
        if "rate limit exceeded" in body:
            time.sleep(min(2 ** attempt, 30))
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

def fetch_folder(sess: requests.Session, folder_id: int) -> dict:
    """Get a single folder; may 401/403 if the folder is hidden to your role."""
    url = f"{sess.base_url}/api/v1/folders/{folder_id}"
    r = sess.get(url, timeout=30)  # don't retry non-throttle 403s here
    if r.status_code == 403 and "Rate Limit Exceeded" in (r.text or ""):
        r = get_with_retry(sess, url)
    r.raise_for_status()
    return r.json()

# ---------- bytes + path helpers ----------

_UNITS = ["B", "KB", "MB", "GB", "TB"]
def human_bytes(n: Optional[int]) -> str:
    if n is None:
        return "?"
    f = float(n); u = 0
    while f >= 1024 and u < len(_UNITS) - 1:
        f /= 1024.0; u += 1
    return f"{f:.1f} {_UNITS[u]}"

_invalid_component = re.compile(r'[\\/:*?"<>|\x00-\x1f]')  # Windows-illegal, safe on Unix too
def safe_component(s: str) -> str:
    s = s.strip().replace("\u202f", " ").replace("\u00a0", " ")
    s = _invalid_component.sub("_", s)
    # collapse repeated separators/whitespace
    s = re.sub(r"\s+", " ", s)
    return s or "_"

def strip_root_prefix(full_name: str) -> str:
    """Drop leading 'course files/' | 'user files/' | 'group files/' if present."""
    parts = [p for p in full_name.split("/") if p]
    if parts and parts[0].lower() in ("course files", "user files", "group files"):
        parts = parts[1:]
    return "/".join(parts)

# ---------- folder path resolver ----------

class FolderPathCache:
    def __init__(self, sess: requests.Session):
        self.sess = sess
        self.cache: Dict[int, Optional[str]] = {}  # id -> path or None (inaccessible)

    def path_for(self, folder_id: Optional[int]) -> Optional[str]:
        if folder_id is None:
            return ""  # root
        fid = int(folder_id)
        if fid in self.cache:
            return self.cache[fid]
        try:
            fobj = fetch_folder(self.sess, fid)
        except requests.HTTPError:
            self.cache[fid] = None  # inaccessible/hidden
            return None
        # Prefer full_name (already includes parents); otherwise recurse
        full_name = fobj.get("full_name")
        if isinstance(full_name, str) and full_name:
            rel = strip_root_prefix(full_name)
            self.cache[fid] = rel
            return rel
        # Fallback: reconstruct using parents
        name = fobj.get("name", f"folder-{fid}")
        parent = fobj.get("parent_folder_id")
        parent_path = self.path_for(int(parent)) if parent is not None else ""
        rel = (parent_path + "/" if parent_path else "") + name
        self.cache[fid] = rel
        return rel

# ---------- downloads ----------

def best_download_url(sess: requests.Session, file_id: int, file_obj: dict) -> Optional[str]:
    """
    Try files/:id/public_url first (user-scoped, usually S3). Fallback to file['url'].
    """
    try:
        r = get_with_retry(sess, f"{sess.base_url}/api/v1/files/{file_id}/public_url")
        j = r.json()
        if isinstance(j, dict) and j.get("public_url"):
            return str(j["public_url"])
    except requests.HTTPError:
        pass
    return file_obj.get("url")

def stream_download(sess: requests.Session, url: str, dest_path: str) -> None:
    os.makedirs(os.path.dirname(dest_path), exist_ok=True)
    with sess.get(url, stream=True, timeout=60) as r:
        r.raise_for_status()
        with open(dest_path, "wb") as f:
            for chunk in r.iter_content(chunk_size=1024 * 256):
                if chunk:
                    f.write(chunk)

# ---------- main ----------

def main():
    ap = argparse.ArgumentParser(description="List Canvas course files via Modules (and optionally download).")
    ap.add_argument("--base-url", required=True)
    ap.add_argument("--token-file", required=True)
    ap.add_argument("--course-id", required=True, type=int)
    ap.add_argument("--show-urls", action="store_true")
    ap.add_argument("--download", action="store_true", help="download files to --output-dir using Canvas folder paths")
    ap.add_argument("--output-dir", help="destination directory for downloads (required with --download)")
    args = ap.parse_args()

    if args.download and not args.output_dir:
        sys.exit("Please supply --output-dir when using --download.")

    tok = read_token(args.token_file)
    sess = session(args.base_url, tok)

    modules = fetch_modules(sess, args.course_id)
    seen: Dict[int, dict] = {}
    grouped_by_module = defaultdict(list)

    # Discover files through module items
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
                        continue  # locked/unpublished
                grouped_by_module[mname].append(seen[fid])

    if not any(grouped_by_module.values()):
        print("(no accessible files via Modules)")
        return

    # Resolve folder paths for downloads
    folder_cache = FolderPathCache(sess)

    total_downloaded = 0
    total_skipped = 0

    for mname in sorted(grouped_by_module.keys(), key=str.lower):
        print(f"\n=== 📚 {mname} ===")
        for f in sorted(grouped_by_module[mname], key=lambda x: str(x.get("display_name") or x.get("filename") or "").lower()):
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

            if not args.download:
                continue

            # Choose folder path (Canvas folders if accessible, else By Module/<Module Name>)
            folder_id = f.get("folder_id")
            rel_folder = folder_cache.path_for(folder_id)
            if rel_folder is None:
                rel_folder = f"By Module/{safe_component(mname)}"
            # sanitize path components
            rel_folder = "/".join(safe_component(p) for p in rel_folder.split("/") if p)

            # pick filename and destination
            filename = safe_component(name)
            dest_dir = os.path.join(os.path.expanduser(args.output_dir), rel_folder)
            dest_path = os.path.join(dest_dir, filename)

            # skip if exists with same size
            try:
                if os.path.exists(dest_path) and f.get("size") is not None and os.path.getsize(dest_path) == int(f["size"]):
                    print(f"      ↪ already exists, skipping: {dest_path}")
                    total_skipped += 1
                    continue
            except OSError:
                pass

            # obtain download URL and save
            durl = best_download_url(sess, int(f["id"]), f)
            if not durl:
                print("      [warn] no download URL available for this file")
                continue
            try:
                print(f"      ↓ saving to {dest_path}")
                stream_download(sess, durl, dest_path)
                total_downloaded += 1
            except requests.HTTPError as e:
                print(f"      [warn] download failed ({e})")

    if args.download:
        print(f"\nDone. Downloaded {total_downloaded} file(s), skipped {total_skipped} existing.")
        if args.output_dir:
            print(f"Output root: {os.path.abspath(os.path.expanduser(args.output_dir))}")

if __name__ == "__main__":
    main()
