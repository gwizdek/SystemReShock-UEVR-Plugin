---
name: run-and-inject
description: Start the game if it is not running and inject UEVR into it. Does nothing when UEVR is already injected. Use when the user says "run and inject", "start the game", "inject UEVR", or a test needs the game running with UEVR.
disable-model-invocation: true
allowed-tools: PowerShell, Bash, Read
---

# Run the game and inject UEVR

Runs `scripts\run-and-inject.ps1`. It uses the Steam install, which is the development install
(see `.claude/rules/game-installs.md`), and UEVR from `D:\Modding\UEVR`.

- Game not running: the script starts it through Steam, waits for the game window, waits 5 s
  and injects UEVR.
- Game running without UEVR: it waits for the game window and injects UEVR.
- Game running with UEVR: it says so and stops.

UEVR counts as injected when the game has `UEVRBackend.dll` loaded. Injection works like the
installer's launcher: the runtime loader DLL first, then `UEVRBackend.dll`.

## Steps

1. From the repository root, run:

   ```powershell
   powershell -ExecutionPolicy Bypass -File scripts\run-and-inject.ps1
   ```

   Use a timeout of at least 3 minutes. Steam and the game start slowly.
   Pass `-Runtime OpenVR` only when the user asks for OpenVR. OpenXR is the default.
   Pass `-DelaySeconds <n>` only when the user asks for another delay.

2. If the script fails, show its message and stop. Do not start the game a second way and do not
   kill the game process.

3. On success, report in one line what happened: already injected, injected into the running
   game, or started and injected. `[inner_plugin][load]` in
   `%APPDATA%\UnrealVRMod\SystemReShock-Win64-Shipping\log.txt` shows when the hot loader has
   loaded the plugin.

## Rules

- Never run this against the GOG install unless the user asks. Then pass
  `-GamePath 'D:\GOG\System Shock Remake'`; the script starts the GOG exe directly.
- A game process that is already running is used whichever install it came from.
