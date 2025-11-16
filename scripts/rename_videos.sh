#!/usr/bin/env bash
# rename_videos.sh — Rename class recordings in ~/Videos to CLASS-YYYY-MM-DD.ext
# Usage:
#   ./rename_videos.sh           # dry-run (shows what would change)
#   ./rename_videos.sh --apply   # perform the renames

set -Eeuo pipefail
shopt -s nullglob

VIDEOS_DIR="${HOME}/Videos"
APPLY=0
[[ "${1:-}" == "--apply" ]] && APPLY=1

month_to_num() {
  local m="${1,,}"
  case "$m" in
    1|01|jan|january) echo 01 ;;
    2|02|feb|february) echo 02 ;;
    3|03|mar|march) echo 03 ;;
    4|04|apr|april) echo 04 ;;
    5|05|may) echo 05 ;;
    6|06|jun|june) echo 06 ;;
    7|07|jul|july) echo 07 ;;
    8|08|aug|august) echo 08 ;;
    9|09|sep|sept|september) echo 09 ;;
    10|oct|october) echo 10 ;;
    11|nov|november) echo 11 ;;
    12|dec|december) echo 12 ;;
    *) return 1 ;;
  esac
}

# Skip if already in desired format: CLASS-YYYY-MM-DD.ext
already_ok_re='^([A-Za-z][A-Za-z0-9]*)-[0-9]{4}-[0-9]{2}-[0-9]{2}\.[A-Za-z0-9]+$'

for path in "${VIDEOS_DIR}"/*; do
  [[ -f "$path" ]] || continue
  fname="$(basename -- "$path")"

  # Skip already-correct names
  if [[ "$fname" =~ $already_ok_re ]]; then
    continue
  fi

  # Split base/ext
  base="${fname%.*}"
  ext="${fname##*.}"

  # Split by underscores
  IFS='_' read -r -a parts <<< "$base"
  n=${#parts[@]}

  # Need at least: CLASS ... MONTH DAY YEAR
  if (( n < 4 )); then
    echo "SKIP (too few underscore parts): $fname"
    continue
  fi

  class="${parts[0]}"
  m_raw="${parts[n-3]}"
  d_raw="${parts[n-2]}"
  y="${parts[n-1]}"

  # Validate/normalize pieces
  if ! m="$(month_to_num "$m_raw")"; then
    echo "SKIP (bad month '$m_raw'): $fname"
    continue
  fi

  if ! [[ "$d_raw" =~ ^[0-9]{1,2}$ ]]; then
    echo "SKIP (bad day '$d_raw'): $fname"
    continue
  fi
  printf -v d "%02d" "$d_raw"

  if ! [[ "$y" =~ ^[0-9]{4}$ ]]; then
    echo "SKIP (bad year '$y'): $fname"
    continue
  fi

  new="${class}-${y}-${m}-${d}.${ext,,}"
  dst="${VIDEOS_DIR}/${new}"

  if [[ -e "$dst" ]]; then
    echo "SKIP (target exists): $fname -> $new"
    continue
  fi

  if (( APPLY )); then
    mv -v -- "$path" "$dst"
  else
    echo "DRY-RUN: $fname -> $new"
  fi
done
