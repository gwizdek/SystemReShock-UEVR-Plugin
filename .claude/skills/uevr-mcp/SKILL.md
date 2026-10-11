---
name: uevr-mcp
description: Inspect and drive the running System Shock Remake through the UEVR MCP server (tools named uevr_*). Use when a task needs live game state - finding objects, reading or writing fields, calling UFunctions, running Lua in the game, watching ProcessEvent calls, taking screenshots, or reading the UEVR log - or when the uevr tools fail to connect.
---

# UEVR MCP server for System Shock Remake

The UEVR MCP server gives the `uevr_*` tools live access to the game while it runs with UEVR.
The server's source and docs are in `C:\_Dev\mods\uevr-mcp\` (`README.md`, `AGENT.md`,
`UEVR_GUIDE.md`). This file covers how it is set up for this project.

## How it fits together

1. **In-game plugin** `uevr_mcp.dll`. UEVR loads it into the game. It serves an HTTP API on
   `127.0.0.1:8899` (the next free port if 8899 is taken) and a named pipe `\\.\pipe\UEVR_MCP`.
2. **MCP server** `UevrMcpServer.exe`. Claude Code starts it from `.mcp.json` in the
   repository root. It turns tool calls into HTTP requests to the plugin.
3. **The game.** The `uevr_*` tools that read game state only work while the game runs and
   UEVR is injected. Host-side tools (`uevr_setup_paths`, `uevr_uevr_log`, the dump
   converters, the patternsleuth tools) work without the game.

## Where things are

| What | Path |
|---|---|
| MCP server EXE (used by `.mcp.json`) | `C:\_Dev\mods\uevr-mcp\mcp-server\bin\Release\net9.0\UevrMcpServer.exe` |
| Built in-game plugin | `C:\_Dev\mods\uevr-mcp\plugin\build\Release\uevr_mcp.dll` |
| Installed in-game plugin | `%APPDATA%\UnrealVRMod\SystemReShock-Win64-Shipping\plugins\uevr_mcp.dll` |
| UEVR injector and backend | `D:\Modding\UEVR\UEVRInjector.exe`, `D:\Modding\UEVR\UEVRBackend.dll` |
| UEVR log (also shows this mod's plugin messages) | `%APPDATA%\UnrealVRMod\SystemReShock-Win64-Shipping\log.txt` |

`uevr_mcp.dll` is installed only in the Steam profile. The plugin links the CRT statically,
so the game's old `MSVCP140.dll` does not affect it (see `.claude/rules/build.md`). It is
built against UEVR plugin API 2.39, the same as this mod's plugin.

## Start a session

1. The user starts the game from Steam and injects UEVR with `D:\Modding\UEVR\UEVRInjector.exe`,
   as usual. UEVR loads `uevr_mcp.dll` together with the hot loader and the hot reloader.
2. Call `uevr_is_ready` or `uevr_get_status`. If the plugin does not answer yet, call
   `uevr_wait_for_plugin`.
3. Call `uevr_get_player` or `uevr_get_singletons` to get the first object addresses.

`uevr_setup_game` can also inject `UEVRBackend.dll` into an already running game. It reads the
backend path from `UEVR_BACKEND_DLL` in `.mcp.json`. It is not tested with this game, so prefer
the injector. Do not let it launch the exe directly: start the game from Steam.

## Tools that help most with this mod

- **Find and read objects:** `uevr_search_objects`, `uevr_objects_by_class`, `uevr_summary`
  (start here, it is small), `uevr_read_field`, `uevr_inspect_object`, `uevr_chain`.
- **Read a type without an instance:** `uevr_get_type "/Script/Engine.Character"`.
- **Change state:** `uevr_write_field`, `uevr_invoke_method`, `uevr_exec_command`, `uevr_set_cvar`.
- **Find what the game calls when something happens:** `uevr_process_event_start`,
  `uevr_process_event_ignore_all` (set a baseline), do the action in game,
  `uevr_process_event_functions`, then `uevr_process_event_stop`.
- **Before/after comparison:** the snapshot and diff tools (`uevr_snapshot`, `uevr_diff`).
- **Run Lua in the game:** `uevr_lua_exec`. The Lua state stays between calls.
- **See the game:** `uevr_screenshot`.
- **Logs:** `uevr_uevr_log` reads the UEVR log, which also holds this mod's plugin messages
  (they are `warn` level, see `.claude/rules/plugin-logging.md`). `uevr_get_log` reads only
  the MCP plugin's own log.
- **VR state:** `uevr_vr_status`, `uevr_vr_poses`, `uevr_vr_settings`.
- **Plugin inventory:** `uevr_get_loaded_plugins` lists which plugin DLLs UEVR loaded.

Object addresses change when a level loads or an object is garbage collected. Look them up
again after a level change.

## Lua: dot or colon

Most `uevr.api` functions are plain functions. Call them with a dot:
`uevr.api.find_uobject(name)`, `uevr.api.execute_command(cmd)`. A colon passes the table as
the first argument and fails with "expected string, received table".
`get_player_controller`, `get_engine` and `get_local_pawn` are methods on userdata. Call them
with a colon: `uevr.api:get_local_pawn()`. Methods on UObjects also use a colon:
`obj:get_full_name()`, `obj:get_class()`.

## Update the in-game plugin

UEVR keeps `uevr_mcp.dll` locked while the game runs, and the hot loader does not handle it.
Close the game first. Then, from `C:\_Dev\mods\uevr-mcp\`:

```powershell
cmake --build plugin\build --config Release --target uevr_mcp
Copy-Item plugin\build\Release\uevr_mcp.dll "$env:APPDATA\UnrealVRMod\SystemReShock-Win64-Shipping\plugins\"
```

`uevr_plugin_info SystemReShock-Win64-Shipping` shows whether the installed copy is older than
the build. To switch the MCP plugin off, remove `uevr_mcp.dll` from the `plugins\` folder.

## Update the MCP server

From `C:\_Dev\mods\uevr-mcp\`:

```powershell
dotnet build mcp-server\UevrMcpServer.csproj -c Release
```

Then restart Claude Code, or reconnect the server with `/mcp`. The build fails while Claude
Code runs the EXE, because Windows locks it. Run the build with the server disconnected.
`.mcp.json` starts the built EXE and not `dotnet run`, because the project uses floating NuGet
versions and `dotnet run` would restore and rebuild on every start.
