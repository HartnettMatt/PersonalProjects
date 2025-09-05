#!/usr/bin/env python3
"""
Download Canvas files, either from a course (via Modules) or starting at a folder id.

Examples:
  # 1) Course mode (works even if Files tab is hidden)
  python downloadFiles.py --base-url https://canvas.colorado.edu \
    --token-file ./api_key.txt --course-id 122711 --download \
    --output-dir ~/Documents/Education/CanvasBackup/ECEN4003-5003

  # 2) Folder mode (e.g., "My Files" folder id = 515601)
  python downloadFiles.py --base-url https://canvas.colorado.edu \
    --token-file ./api_key.txt --folder-id 515601 --download \
    --output-dir ~/Documents/Education/CanvasBackup/MyFiles
"""
import argparse
import json
import os
import re
import sys
import time
from collections import defaultdict, deque
from typing import Dict, Iterable, List, Optional, Tuple

import requests

# ----------------------- auth & session -----------------------

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
        "User-Agent": "canvas-downloader/0.3",
    })
    return s

# ----------------------- HTTP helpers -----------------------

def get_with_retry(sess: requests.Session, url: str, params=None, max_tries: int = 5) -> requests.Response:
    """Retry on Canvas 403 'Rate Limit Exceeded'; otherwise raise."""
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

# ----------------------- Canvas fetchers -----------------------
# Course/Modules (for student-accessible files)
def fetch_modules(sess: requests.Session, course_id: int) -> List[dict]:
    url = f"{sess.base_url}/api/v1/courses/{course_id}/modules"
    return list(iter_paginated(sess, url))  # Modules API. :contentReference[oaicite:4]{index=4}

def fetch_module_items(sess: requests.Session, course_id: int, module_id: int) -> List[dict]:
    url = f"{sess.base_url}/api/v1/courses/{course_id}/modules/{module_id}/items"
    return list(iter_paginated(sess, url))  # Module items. :contentReference[oaicite:5]{index=5}

def fetch_file(sess: requests.Session, file_id: int) -> dict:
    url = f"{sess.base_url}/api/v1/files/{file_id}"
    return get_with_retry(sess, url).json()  # Files API. :contentReference[oaicite:6]{index=6}

# Folders (for user/course/group files)
def fetch_folder(sess: requests.Session, folder_id: int) -> dict:
    url = f"{sess.base_url}/api/v1/folders/{folder_id}"
    r = sess.get(url, timeout=30)
    if r.status_code == 403 and "Rate Limit Exceeded" in (r.text or ""):
        r = get_with_retry(sess, url)
    r.raise_for_status()
    return r.json()  # Folders API. :contentReference[oaicite:7]{index=7}

def list_folder_folders(sess: requests.Session, folder_id: int) -> List[dict]:
    url = f"{sess.base_url}/api/v1/folders/{folder_id}/folders"
    return list(iter_paginated(sess, url))  # List subfolders. :contentReference[oaicite:8]{index=8}

def list_folder_files(sess: requests.Session, folder_id: int) -> List[dict]:
    url = f"{sess.base_url}/api/v1/folders/{folder_id}/files"
    return list(iter_paginated(sess, url))  # List files in folder. :contentReference[oaicite:9]{index=9}

# ----------------------- path & size helpers -----------------------

_UNITS = ["B", "KB", "MB", "GB", "TB"]
def human_bytes(n: Optional[int]) -> str:
    if n is None: return "?"
    f = float(n); u = 0
    while f >= 1024 and u < len(_UNITS) - 1:
        f /= 1024.0; u += 1
    return f"{f:.1f} {_UNITS[u]}"

_invalid_component = re.compile(r'[\\/:*?"<>|\x00-\x1f]')
def safe_component(s: str) -> str:
    s = s.strip().replace("\u202f", " ").replace("\u00a0", " ")
    s = _invalid_component.sub("_", s)
    s = re.sub(r"\s+", " ", s)
    return s or "_"

def strip_root_prefix(full_name: str) -> str:
    parts = [p for p in full_name.split("/") if p]
    if parts and parts[0].lower() in ("course files", "user files", "group files"):
        parts = parts[1:]
    return "/".join(parts)

# Resolve a folder's relative path using full_name when possible (cached)
class FolderPathCache:
    def __init__(self, sess: requests.Session):
        self.sess = sess
        self.cache: Dict[int, Optional[str]] = {}

    def path_for(self, folder_id: Optional[int]) -> Optional[str]:
        if folder_id is None:
            return ""
        fid = int(folder_id)
        if fid in self.cache:
            return self.cache[fid]
        try:
            fobj = fetch_folder(self.sess, fid)
        except requests.HTTPError:
            self.cache[fid] = None
            return None
        full_name = fobj.get("full_name")
        if isinstance(full_name, str) and full_name:
            rel = strip_root_prefix(full_name)
            self.cache[fid] = rel
            return rel
        name = fobj.get("name", f"folder-{fid}")
        parent = fobj.get("parent_folder_id")
        parent_path = self.path_for(int(parent)) if parent is not None else ""
        rel = (parent_path + "/" if parent_path else "") + name
        self.cache[fid] = rel
        return rel

# ----------------------- downloads -----------------------

def best_download_url(sess: requests.Session, file_id: int, file_obj: dict) -> Optional[str]:
    """Prefer files/:id/public_url; fallback to file['url']."""
    try:
        r = get_with_retry(sess, f"{sess.base_url}/api/v1/files/{file_id}/public_url")
        j = r.json()
        if isinstance(j, dict) and j.get("public_url"):
            return str(j["public_url"])  # public download URL. :contentReference[oaicite:10]{index=10}
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

# ----------------------- core modes -----------------------

def course_mode(sess: requests.Session, course_id: int, show_urls: bool, do_download: bool, out_root: Optional[str]):
    """Discover files via Modules and optionally download."""
    try:
        modules = fetch_modules(sess, course_id)
    except requests.HTTPError as e:
        # Auto-fallback: if 404, this probably isn't a course id. Try folder mode.
        if e.response is not None and e.response.status_code == 404:
            print(f"[info] {course_id} is not a course id (Modules 404). Trying as --folder-id …")
            return folder_mode(sess, course_id, show_urls, do_download, out_root)
        raise

    seen: Dict[int, dict] = {}
    grouped = defaultdict(list)
    for m in modules:
        mid = m["id"]; mname = m.get("name", f"Module {mid}")
        for it in fetch_module_items(sess, course_id, mid):
            if it.get("type") == "File" and it.get("content_id"):
                fid = int(it["content_id"])
                if fid not in seen:
                    try:
                        seen[fid] = fetch_file(sess, fid)
                    except requests.HTTPError:
                        continue
                grouped[mname].append(seen[fid])

    folder_cache = FolderPathCache(sess)

    total_downloaded = 0
    total_skipped = 0
    for mname in sorted(grouped.keys(), key=str.lower):
        print(f"\n=== 📚 {mname} ===")
        for f in sorted(grouped[mname], key=lambda x: str(x.get("display_name") or x.get("filename") or "").lower()):
            name = f.get("display_name") or f.get("filename") or f"file-{f.get('id')}"
            size = human_bytes(f.get("size"))
            updated = f.get("updated_at") or f.get("modified_at") or ""
            print(f"  📄 {name} (id={f.get('id')}, {size}, updated {updated})")
            if show_urls:
                u = f.get("url") or f.get("href") or ""
                if u: print(f"      → {u}")

            if not do_download or not out_root:
                continue

            folder_id = f.get("folder_id")
            rel_folder = folder_cache.path_for(folder_id)
            if rel_folder is None:
                rel_folder = f"By Module/{safe_component(mname)}"
            rel_folder = "/".join(safe_component(p) for p in rel_folder.split("/") if p)
            filename = safe_component(name)
            dest_dir = os.path.join(os.path.expanduser(out_root), rel_folder)
            dest_path = os.path.join(dest_dir, filename)

            try:
                if os.path.exists(dest_path) and f.get("size") is not None and os.path.getsize(dest_path) == int(f["size"]):
                    print(f"      ↪ already exists, skipping: {dest_path}")
                    total_skipped += 1
                    continue
            except OSError:
                pass

            durl = best_download_url(sess, int(f["id"]), f)
            if not durl:
                print("      [warn] no download URL available for this file")
                continue
            print(f"      ↓ saving to {dest_path}")
            stream_download(sess, durl, dest_path)
            total_downloaded += 1

    if do_download and out_root:
        print(f"\nDone. Downloaded {total_downloaded} file(s), skipped {total_skipped} existing.")
        print(f"Output root: {os.path.abspath(os.path.expanduser(out_root))}")

def folder_mode(sess: requests.Session, root_folder_id: int, show_urls: bool, do_download: bool, out_root: Optional[str]):
    """Recursively walk folders from a starting folder id and optionally download all files."""
    folder_cache = FolderPathCache(sess)

    # BFS through folders
    queue = deque([int(root_folder_id)])
    visited = set()
    total_downloaded = 0
    total_skipped = 0

    while queue:
        fid = queue.popleft()
        if fid in visited:
            continue
        visited.add(fid)

        # Determine path for this folder (strip "user files/" etc.)
        try:
            fobj = fetch_folder(sess, fid)
        except requests.HTTPError as e:
            print(f"[warn] cannot read folder {fid}: {e}")
            continue
        full = fobj.get("full_name") or fobj.get("name", f"folder-{fid}")
        rel_path = strip_root_prefix(full) if isinstance(full, str) else f"folder-{fid}"
        rel_path = "/".join(safe_component(p) for p in rel_path.split("/") if p)
        print(f"\n=== 📁 {rel_path} (id={fid}) ===")

        # List files in this folder
        for f in sorted(list_folder_files(sess, fid), key=lambda x: str(x.get("display_name") or x.get("filename") or "").lower()):
            name = f.get("display_name") or f.get("filename") or f"file-{f.get('id')}"
            size = human_bytes(f.get("size"))
            updated = f.get("updated_at") or f.get("modified_at") or ""
            print(f"  📄 {name} (id={f.get('id')}, {size}, updated {updated})")
            if show_urls:
                u = f.get("url") or f.get("href") or ""
                if u: print(f"      → {u}")

            if do_download and out_root:
                filename = safe_component(name)
                dest_dir = os.path.join(os.path.expanduser(out_root), rel_path)
                dest_path = os.path.join(dest_dir, filename)

                try:
                    if os.path.exists(dest_path) and f.get("size") is not None and os.path.getsize(dest_path) == int(f["size"]):
                        print(f"      ↪ already exists, skipping: {dest_path}")
                        total_skipped += 1
                        continue
                except OSError:
                    pass

                durl = best_download_url(sess, int(f["id"]), f)
                if not durl:
                    print("      [warn] no download URL available for this file")
                    continue
                print(f"      ↓ saving to {dest_path}")
                stream_download(sess, durl, dest_path)
                total_downloaded += 1

        # Enqueue subfolders
        for sf in list_folder_folders(sess, fid):
            sid = int(sf["id"])
            if sid not in visited:
                queue.append(sid)

    if do_download and out_root:
        print(f"\nDone. Downloaded {total_downloaded} file(s), skipped {total_skipped} existing.")
        print(f"Output root: {os.path.abspath(os.path.expanduser(out_root))}")

# ----------------------- CLI -----------------------

def main():
    ap = argparse.ArgumentParser(description="Download Canvas files from a course (via Modules) or a starting folder.")
    ap.add_argument("--base-url", required=True)
    ap.add_argument("--token-file", required=True)
    ap.add_argument("--course-id", type=int, help="Canvas course id (walks Modules)")
    ap.add_argument("--folder-id", type=int, help="Canvas folder id (e.g., a 'My Files' folder)")
    ap.add_argument("--show-urls", action="store_true")
    ap.add_argument("--download", action="store_true", help="actually download files")
    ap.add_argument("--output-dir", help="destination directory (required when --download)")
    args = ap.parse_args()

    # Require one of the ids
    if args.course_id is None and args.folder_id is None:
        sys.exit("Please provide --course-id OR --folder-id.")
    if args.download and not args.output_dir:
        sys.exit("Please supply --output-dir when using --download.")

    tok = read_token(args.token_file)
    sess = session(args.base_url, tok)

    if args.folder_id is not None:
        folder_mode(sess, args.folder_id, args.show_urls, args.download, args.output_dir)
    else:
        course_mode(sess, args.course_id, args.show_urls, args.download, args.output_dir)

if __name__ == "__main__":
    main()
