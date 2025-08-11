#!/usr/bin/env python3
"""
Summarize EV charging sessions from a Home Assistant history CSV.

Logic:
- Track the running 'state' value (kWh) reported by the charger.
- Whenever it transitions from >0 to exactly 0, add the last non-zero value
  to the total (i.e., count one completed session).
- Ongoing sessions (file ends while >0) are ignored.

CSV columns expected: at least 'state' and a timestamp like 'last_changed'.
Extra columns are ignored.
"""

import argparse
import csv
import datetime as dt
from typing import List, Optional, Tuple

def read_series(path: str) -> List[Tuple[Optional[dt.datetime], float]]:
    rows: List[Tuple[Optional[dt.datetime], float]] = []
    with open(path, newline="") as f:
        r = csv.DictReader(f)
        if not r.fieldnames or "state" not in r.fieldnames:
            raise SystemExit("CSV must contain a 'state' column.")
        # Find a timestamp column if present (used only for sorting)
        ts_field = next((c for c in ("last_changed", "last_updated", "time", "timestamp") if c in r.fieldnames), None)

        for row in r:
            try:
                val = float(row.get("state", ""))
            except (TypeError, ValueError):
                continue
            t = None
            if ts_field:
                ts = row.get(ts_field, "")
                if ts:
                    try:
                        # Handle ISO-8601 with 'Z'
                        t = dt.datetime.fromisoformat(ts.replace("Z", "+00:00"))
                    except Exception:
                        t = None
            rows.append((t, val))

    # Sort by timestamp if available (None at end)
    rows.sort(key=lambda x: (x[0] is None, x[0]))
    return rows

def compute_total_kwh(series: List[Tuple[Optional[dt.datetime], float]], eps: float = 1e-9) -> float:
    total = 0.0
    last_nonzero = 0.0
    prev: Optional[float] = None

    for _, val in series:
        if val > eps:
            last_nonzero = val
        if prev is not None and prev > eps and abs(val) <= eps:
            total += last_nonzero
            last_nonzero = 0.0
        prev = val
    return total

def main():
    ap = argparse.ArgumentParser(description="Compute total energy and cost from Home Assistant EV history.")
    ap.add_argument("-f", "--file", default="history.csv", help="Path to CSV (default: history.csv)")
    ap.add_argument("-r", "--rate", required=True, type=float, help="Cost per kWh in dollars (e.g., 0.17734)")
    args = ap.parse_args()

    series = read_series(args.file)
    if not series:
        raise SystemExit("No numeric 'state' values found.")

    total_kwh = compute_total_kwh(series)
    total_cost = round(total_kwh * args.rate, 2)

    print(f"Total energy: {total_kwh:.3f} kWh")
    print(f"Rate: ${args.rate:.5f} per kWh")
    print(f"Total cost: ${total_cost:.2f}")

if __name__ == "__main__":
    main()
