#!/usr/bin/env bash
set -u

echo "[steam-fix] Cleaning up lingering game/runtime processes..."

# 1) Ask all Proton wineservers to exit gracefully (covers any game prefixes)
if compgen -G "$HOME/.steam/steam/steamapps/compatdata/*/pfx" > /dev/null; then
  for pfx in "$HOME/.steam/steam/steamapps/compatdata/"*/pfx; do
    [ -d "$pfx" ] || continue
    WINEPREFIX="$pfx" wineserver -k >/dev/null 2>&1 || true
  done
fi

# 2) Kill common lingering containers/overlays if still around
pkill -f pressure-vessel >/dev/null 2>&1 || true
pkill -f SteamLinuxRuntime >/dev/null 2>&1 || true
pkill -x gamescope >/dev/null 2>&1 || true
pkill -f mangohud >/dev/null 2>&1 || true
pkill -f vkBasalt >/dev/null 2>&1 || true

# 3) Stop Steam processes
pkill -x steamwebhelper >/dev/null 2>&1 || true
pkill -x steam >/dev/null 2>&1 || true
sleep 2

# 4) Remove stale PID/socket/IPC files that can block relaunch
RUNTIME_DIR="${XDG_RUNTIME_DIR:-/run/user/$(id -u)}"
rm -rf "/tmp/steam-$USER" 2>/dev/null || true
rm -rf "$RUNTIME_DIR/steam" 2>/dev/null || true
rm -f "$RUNTIME_DIR/steam.pid" 2>/dev/null || true
rm -f "$HOME/.steam/steam.pid" "$HOME/.steam/steam.pipe" 2>/dev/null || true

echo "[steam-fix] Relaunching Steam..."
( nohup steam >/dev/null 2>&1 & disown )

echo "[steam-fix] Done. If Steam doesn't open, wait ~5–10 seconds and run again."
