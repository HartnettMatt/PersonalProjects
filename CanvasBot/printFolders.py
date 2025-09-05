#!/usr/bin/env python3
"""
List Canvas folders hierarchically.

Usage:
  python canvas_tree.py --base-url https://your.canvas.domain \
                        --token-file ~/.canvas_token \
                        [--skip-user] [--skip-courses] [--include-groups]

The token file can be either:
  - a plain text file with the token on the first line, or
  - a JSON file with a key named "token" or "access_token".
"""
from __future__ import annotations

import argparse
import json
import os
import sys
from typing import Dict, Iterable, List, Optional, Tuple

import requests


def read_token(path: str) -> str:
    """Read a Canvas API token from a file."""
    try:
        with open(os.path.expanduser(path), "r", encoding="utf-8") as f:
            content = f.read().strip()
    except FileNotFoundError:
        sys.exit(f"Token file not found: {path}")

    if not content:
        sys.exit("Token file is empty.")

    # Allow JSON or raw text
    if content[:1] in "{[":
        try:
            data = json.loads(content)
            for key in ("token", "access_token", "api_token"):
                if key in data:
                    return str(data[key]).strip()
        except json.JSONDecodeError:
            sys.exit("Token file looks like JSON but could not be parsed.")
        sys.exit("JSON token file found, but no 'token' or 'access_token' key.")
    else:
        return content.splitlines()[0].strip()


def make_session(base_url: str, token: str) -> requests.Session:
    """Create a requests session with Authorization and base URL."""
    base = base_url.rstrip("/")
    sess = requests.Session()
    sess.headers.update({
        "Authorization": f"Bearer {token}",
        "Accept": "application/json",
        "User-Agent": "canvas-tree/0.1 (+https://example.local)"
    })
    # store base for convenience
    sess.base_url = base  # type: ignore[attr-defined]
    return sess


def iter_paginated(sess: requests.Session, url: str, params: Optional[dict] = None) -> Iterable[dict]:
    """
    Iterate all items from a paginated Canvas endpoint.
    Follows RFC5988 Link headers per Canvas docs.
    """
    next_url = url
    next_params = dict(params or {})
    if "per_page" not in next_params:
        next_params["per_page"] = 100  # Canvas allows custom per_page; still follow Link headers
    while next_url:
        resp = sess.get(next_url, params=next_params, timeout=30)
        resp.raise_for_status()
        data = resp.json()
        if isinstance(data, list):
            for item in data:
                yield item
        else:
            # Some endpoints may return an object; yield as single item
            yield data

        # Parse Link header for next page
        link = resp.headers.get("Link", "")
        next_link = None
        if link:
            # requests has a helper, but it expects a slightly different format in some cases
            for part in link.split(","):
                segs = part.split(";")
                if len(segs) < 2:
                    continue
                url_part = segs[0].strip()
                rel_part = ";".join(segs[1:]).strip()
                if 'rel="next"' in rel_part:
                    # <https://...>
                    if url_part.startswith("<") and url_part.endswith(">"):
                        next_link = url_part[1:-1]
                        break
        next_url = next_link
        next_params = None  # next link already contains query params


def fetch_active_courses(sess: requests.Session) -> List[dict]:
    """Return the current user's active courses."""
    url = f"{sess.base_url}/api/v1/courses"
    return list(iter_paginated(sess, url, params={"enrollment_state": "active"}))


def fetch_course_folders(sess: requests.Session, course_id: int) -> List[dict]:
    """Return all folders for a given course (flat list)."""
    url = f"{sess.base_url}/api/v1/courses/{course_id}/folders"
    return list(iter_paginated(sess, url))


def fetch_user_folders(sess: requests.Session) -> List[dict]:
    """Return all folders in the current user's personal 'User Files' space."""
    url = f"{sess.base_url}/api/v1/users/self/folders"
    return list(iter_paginated(sess, url))


def fetch_group_folders(sess: requests.Session, group_id: int) -> List[dict]:
    """Return all folders for a given group."""
    url = f"{sess.base_url}/api/v1/groups/{group_id}/folders"
    return list(iter_paginated(sess, url))


def fetch_my_groups(sess: requests.Session) -> List[dict]:
    """Return the current user's groups (optional)."""
    url = f"{sess.base_url}/api/v1/users/self/groups"
    return list(iter_paginated(sess, url))


def build_forest(folders: List[dict]) -> List[dict]:
    """
    Build a forest (list of root nodes) from a flat folder list using parent_folder_id.
    Each node is {'info': folder_dict, 'children': [nodes...]}.
    """
    nodes: Dict[int, dict] = {}
    roots: List[dict] = []

    for f in folders:
        fid = int(f["id"])
        nodes[fid] = {"info": f, "children": []}

    for f in folders:
        fid = int(f["id"])
        pid = f.get("parent_folder_id")
        if pid is None:
            roots.append(nodes[fid])
        else:
            parent = nodes.get(int(pid))
            if parent:
                parent["children"].append(nodes[fid])
            else:
                # Orphan (parent not included); treat as root
                roots.append(nodes[fid])

    def sort_recursive(n: dict):
        n["children"].sort(key=lambda c: str(c["info"].get("name", "")).lower())
        for c in n["children"]:
            sort_recursive(c)

    for r in roots:
        sort_recursive(r)

    # Sort roots as well
    roots.sort(key=lambda c: str(c["info"].get("name", "")).lower())
    return roots


def print_tree(nodes: List[dict], indent: str = ""):
    """Pretty-print the folder tree."""
    for n in nodes:
        f = n["info"]
        name = f.get("name", "(unnamed)")
        fid = f.get("id")
        # full_name often contains a path like "course files/Subfolder" (if present)
        path_hint = f.get("full_name") or ""
        meta = f" [id={fid}]"
        if path_hint and path_hint != name:
            meta += f" — {path_hint}"
        print(f"{indent}📁 {name}{meta}")
        if n["children"]:
            print_tree(n["children"], indent + "    ")


def main():
    ap = argparse.ArgumentParser(description="Print Canvas folders hierarchically.")
    ap.add_argument("--base-url", required=True, help="Base Canvas domain, e.g. https://canvas.colorado.edu")
    ap.add_argument("--token-file", required=True, help="Path to file containing your Canvas API token")
    ap.add_argument("--skip-user", action="store_true", help="Skip personal 'User Files'")
    ap.add_argument("--skip-courses", action="store_true", help="Skip course folders")
    ap.add_argument("--include-groups", action="store_true", help="Also list group folders (if any)")
    args = ap.parse_args()

    token = read_token(args.token_file)
    sess = make_session(args.base_url, token)

    # Personal folders
    if not args.skip_user:
        try:
            user_folders = fetch_user_folders(sess)
            print("\n=== Personal: User Files ===")
            if user_folders:
                user_tree = build_forest(user_folders)
                print_tree(user_tree)
            else:
                print("(no folders)")
        except requests.HTTPError as e:
            print(f"[warn] Could not read user folders: {e}", file=sys.stderr)

    # Courses
    if not args.skip_courses:
        try:
            courses = fetch_active_courses(sess)
            for c in sorted(courses, key=lambda x: str(x.get("name") or x.get("course_code") or "")):
                cid = c["id"]
                cname = c.get("name") or c.get("course_code") or f"Course {cid}"
                print(f"\n=== Course: {cname} (id={cid}) ===")
                try:
                    folders = fetch_course_folders(sess, cid)
                    if folders:
                        forest = build_forest(folders)
                        print_tree(forest)
                    else:
                        print("(no folders)")
                except requests.HTTPError as e:
                    print(f"[warn] Could not read folders for course {cid}: {e}", file=sys.stderr)
        except requests.HTTPError as e:
            print(f"[warn] Could not list courses: {e}", file=sys.stderr)

    # Groups (optional)
    if args.include_groups:
        try:
            groups = fetch_my_groups(sess)
            for g in groups:
                gid = g["id"]
                gname = g.get("name", f"Group {gid}")
                print(f"\n=== Group: {gname} (id={gid}) ===")
                try:
                    gfolders = fetch_group_folders(sess, gid)
                    if gfolders:
                        gforest = build_forest(gfolders)
                        print_tree(gforest)
                    else:
                        print("(no folders)")
                except requests.HTTPError as e:
                    print(f"[warn] Could not read folders for group {gid}: {e}", file=sys.stderr)
        except requests.HTTPError as e:
            print(f"[warn] Could not list groups: {e}", file=sys.stderr)


if __name__ == "__main__":
    main()
