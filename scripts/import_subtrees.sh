#!/usr/bin/env bash
# import_subtrees.sh
#
# Import multiple repos into the current Git repository using `git subtree`,
# preserving full history (Option A). Reads a CSV with lines:
#   <repo_url>,<destination_folder_path>,<branch>
#
# Example:
#   git@github.com:org/lab01.git,labs/lab01,main
#   git@github.com:org/lab02.git,labs/lab02,master
#
# Notes:
# - If <destination_folder_path> already exists, this script will run
#   `git subtree pull` instead of `git subtree add` (idempotent reruns).
# - Remotes are auto-generated, unique, and removed after each import.
# - Lines beginning with `#` or blank lines are skipped.
# - Requires: git with subtree support, sha1sum (or shasum).

set -Euo pipefail

die() { echo "Error: $*" >&2; exit 1; }
require_cmd() { command -v "$1" >/dev/null 2>&1 || die "Missing required command: $1"; }

# sha1sum fallback for macOS (shasum)
sha1_8() {
  local s="$1"
  if command -v sha1sum >/dev/null 2>&1; then
    printf '%s' "$s" | sha1sum | awk '{print $1}' | cut -c1-8
  elif command -v shasum >/dev/null 2>&1; then
    printf '%s' "$s" | shasum | awk '{print $1}' | cut -c1-8
  else
    die "Need sha1sum or shasum"
  fi
}

# Ensure we are inside a git repo and git subtree exists
require_cmd git
git rev-parse --is-inside-work-tree >/dev/null 2>&1 || die "Run this from inside your destination Git repository."

# # Correct presence check for git-subtree (Arch/others can return non-zero on -h)
# (command -v git-subtree >/dev/null 2>&1) || die "Your Git doesn't have 'git subtree' (the 'git-subtree' helper). On Arch: 'sudo pacman -S git' (it's included)."

# CSV file arg
if [[ $# -ne 1 ]]; then
  echo "Usage: $0 <repos.csv>" >&2
  exit 1
fi
CSV="$1"
[[ -f "$CSV" ]] || die "CSV file not found: $CSV"

# Generate a safe remote name from dest path + url hash
gen_remote_name() {
  local dest="$1"
  local url="$2"
  local base hash name
  base="$(printf '%s' "$dest" | tr -c '[:alnum:]' '_' | sed -e 's/^_\\+//' -e 's/_\\+$//')"
  hash="$(sha1_8 "$url")"
  name="import_${base}_${hash}"
  name="$(printf '%s' "$name" | sed -E 's/^[^A-Za-z]+/r_/')"   # ensure starts with a letter
  echo "$name"
}

remote_exists() { git remote | grep -qx -- "$1"; }

add_remote_unique() {
  local name="$1" url="$2" candidate
  if remote_exists "$name"; then
    local i=1
    while true; do
      candidate="${name}_${i}"
      if ! remote_exists "$candidate"; then
        name="$candidate"
        break
      fi
      i=$((i+1))
    done
  fi
  git remote add "$name" "$url"
  echo "$name"
}

dest_exists_in_repo() {
  local dest="$1"
  [[ -d "$dest" || -f "$dest" ]] && return 0
  if git rev-parse -q --verify HEAD >/dev/null 2>&1; then
    if git ls-tree -r --name-only HEAD -- "$dest" | grep -q . 2>/dev/null; then
      return 0
    fi
  fi
  return 1
}

cleanup_remote() {
  local remote="$1"
  if remote_exists "$remote"; then
    git remote remove "$remote" || true
  fi
}

# Process CSV
# Expected fields per line: URL,DEST,BRANCH
line_no=0
while IFS=, read -r raw_url raw_dest raw_branch; do
  line_no=$((line_no+1))

  # Skip blank/comment lines
  if [[ -z "${raw_url-}" && -z "${raw_dest-}" && -z "${raw_branch-}" ]]; then
    continue
  fi
  [[ "${raw_url:-}" =~ ^[[:space:]]*# ]] && continue

  # Trim
  url="$(printf '%s' "${raw_url:-}" | sed 's/^[[:space:]]*//; s/[[:space:]]*$//')"
  dest="$(printf '%s' "${raw_dest:-}" | sed 's/^[[:space:]]*//; s/[[:space:]]*$//')"
  branch="$(printf '%s' "${raw_branch:-}" | sed 's/^[[:space:]]*//; s/[[:space:]]*$//')"

  # Validate
  if [[ -z "$url" || -z "$dest" || -z "$branch" ]]; then
    die "CSV line $line_no malformed. Expect: <url>,<dest>,<branch>. Got: '$raw_url,$raw_dest,$raw_branch'"
  fi

  echo
  echo "==> [$line_no] URL='$url'  DEST='$dest'  BRANCH='$branch'"

  remote_name="$(gen_remote_name "$dest" "$url")"
  remote_name="$(add_remote_unique "$remote_name" "$url")"

  # Verify branch exists on remote
  if ! git ls-remote --exit-code --heads "$remote_name" "$branch" >/dev/null 2>&1; then
    cleanup_remote "$remote_name"
    die "Remote branch '$branch' not found at '$url' (line $line_no)."
  fi

  echo "    Fetching '$remote_name' (with tags)..."
  git fetch "$remote_name" --tags

  mkdir -p "$(dirname -- "$dest")"

  if dest_exists_in_repo "$dest"; then
    echo "    '$dest' exists; running 'git subtree pull'..."
    if ! git subtree pull --prefix="$dest" "$remote_name" "$branch"; then
      echo "    'subtree pull' failed; attempting one-time 'subtree add' fallback..."
      git subtree add --prefix="$dest" "$remote_name" "$branch" || {
        cleanup_remote "$remote_name"
        die "Both 'subtree pull' and fallback 'subtree add' failed for '$dest' (line $line_no)."
      }
    fi
  else
    echo "    '$dest' not present; running 'git subtree add'..."
    git subtree add --prefix="$dest" "$remote_name" "$branch" || {
      cleanup_remote "$remote_name"
      die "'git subtree add' failed for '$dest' (line $line_no)."
    }
  fi

  echo "    Removing temporary remote '$remote_name'..."
  cleanup_remote "$remote_name"
  echo "    Done with '$dest'."

done < "$CSV"

echo
echo "All done. Review with:"
echo "  git log --graph --decorate --oneline"
echo "  git status"
