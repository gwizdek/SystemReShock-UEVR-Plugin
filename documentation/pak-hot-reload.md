# Pak hot reload (PakHotReloader)

PakHotReloader is a development-only UEVR plugin in `tools/PakHotReloader/`. It
mounts a freshly cooked mod pak into the running game, so a content change can be
checked without restarting the game. It is not shipped by the installer.

## Why a restart is normally needed

The engine builds its file index when a pak is mounted at start-up, and it keeps
the pak file open, so the file cannot be replaced while the game runs. Objects
that are already loaded are never read from disk again. The hot reloader works
around the first two points by mounting a copy of the new pak above the old one.
The third point is handled by the game itself: a map change drops the objects of
the old level, and the next load reads them from the new pak.

## How to use it

1. Build and deploy it once:

   ```powershell
   powershell -ExecutionPolicy Bypass -File scripts\build-and-deploy.ps1 -Target PakHotReloader
   ```

   UEVR loads every DLL in the profile plugins folder, so the hot reloader runs as a
   second plugin next to `SystemReShockVR.dll`. Delete `PakHotReloader.dll` from
   that folder to switch it off.

2. Start the game once with the plugin loaded. On first start it writes
   `%APPDATA%\UnrealVRMod\SystemReShock-Win64-Shipping\PakHotReloader.ini` with
   comments. Edit it and reload the plugin in the UEVR overlay.

3. Iterate:
   - Cook the mod project. The default setting points at the cooked
     `pakchunk10-WindowsNoEditor.pak` of the Unreal project, the same file the
     installer ships as `SystemShockVRModCore_P.pak`.
   - In the game, quit to the title screen.
   - Press the hotkey (F9 by default) while the game window has focus.
   - Load your save. With `mode = quick`, `auto` or `manual` the plugin starts
     that load itself through the game's GameInstance.

Every step is written to the UEVR `log.txt` with a `[pak_mounter]`,
`[engine_resolver]`, `[save_loader]` or `[plugin]` prefix.

## Settings

| Section | Key | Meaning |
|---|---|---|
| `paks` | `files` | Pak files to copy and mount, separated by `;`. Later files are mounted above earlier ones. |
| `hotkey` | `key` | Virtual-key code in hex. `0x78` is F9. |
| `load` | `mode` | `none`, `quick` (`QuickLoad`), `auto` (`AutoLoad`) or `manual` (`ManualLoad` with `save_name`). |
| `load` | `save_name` | Save slot name for `manual`. |
| `diagnostics` | `probe_files` | Files as the engine names them, separated by `;`, for example `../../../SystemShock/Content/Mods/VRBody/_BP_VRBody.uasset`. Each is checked before and after a mount. The default list holds the VR body asset, its `.uexp` and one base-game file as a control. Empty skips it. |
| `diagnostics` | `loaded_prefix` | Package name prefix, default `/Game/Mods/`. Loaded packages under it and live instances of their classes are listed before and after the garbage collection. Empty skips it. |

## What happens on the hotkey, and how to read the log

A reload runs in two phases so the log shows what a garbage collection frees:

1. `[plugin][begin_reload]`: the plugin lists the loaded mod packages and the
   live instances of mod classes, then asks the engine for a garbage
   collection through `KismetSystemLibrary::CollectGarbage`.
2. About 90 ticks later, `[plugin][finish_reload]`: the same two lists again,
   the file probes, the mount, the probes once more, and the optional save load.

Lines to look at:

- `[diagnostics][log_loaded_packages] still in memory: /Game/Mods/...` lists mod
  packages that are loaded. The engine never reads a loaded package from disk
  again, so every class in those packages keeps its old content until the
  package is unloaded. For a hot reload to take effect the list after the
  garbage collection must not contain the package you changed.
- `[diagnostics][log_live_instances] alive: ...` lists objects made from mod
  classes, with their outer chain. These are what keep the packages alive. An
  instance that survives the title screen points at the owner to fix.
- `[referencers][log_referencers] <object> .<property> -> <mod object>` lists,
  after the garbage collection, every reflected property of a non-mod object
  that still points at a mod class, default object or asset. These are the
  references that keep the packages loaded when no instance is left. Only
  UPROPERTY references are visible; a reference held in native code is not.
- `[diagnostics][log_file_probes] before mount` and `after mount` show each probe
  file as the engine's pak layer sees it. A mod file must exist in both; the
  control file must not change. A mod file that exists before and not after
  means the new pak claims the path but the engine cannot serve it from there.
- `[pak_mounter][mount_copy] ... -> mounted` confirms the engine accepted the pak.

## What it does on the hotkey

For each configured pak it copies the file into
`%APPDATA%\UnrealVRMod\SystemReShock-Win64-Shipping\pak_hot_reload\` under a new
name, `<stem>_s<pid>_<n>_P.pak`, and calls the engine's `FPakPlatformFile::Mount`
on the copy with a mount order above everything the game loaded at start-up. The
copy is needed because the previous mount keeps its file open; the new name is
needed because the file index is keyed by path. Old copies stay mounted but are
shadowed. Copies from earlier game sessions are deleted at plugin start.

Nothing is unmounted. Each reload therefore keeps one more pak index in memory.
That is fine for a development session and avoids resolving a fourth engine
function.

## How the engine functions are found

The shipping executable exports nothing and its log strings are stripped, so the
three functions are found from two strings that survive in every build:

- `L"_P.pak"` appears once, and exactly one instruction references it. That
  instruction is inside `FPakPlatformFile::Mount`. The Windows function table
  (`RtlLookupFunctionEntry`, following chained entries) gives the function start.
- `L"PakFile"` is used by several call sites of the form
  `call FPlatformFileManager::Get` / `mov rcx, rax` / `lea rdx, [L"PakFile"]` /
  `call FPlatformFileManager::FindPlatformFile`. Each site votes for the two call
  targets; the most common answer wins.

The resolver then calls `Get` and `FindPlatformFile(L"PakFile")` once and logs the
resulting `FPakPlatformFile` pointer and the three offsets. If any lookup is not
unique the plugin logs an error and stays inactive. The same code resolves the
GOG and the Steam build; byte signatures are not used because the two builds
differ in code layout.

## What the main plugin does to make a reload possible

The engine only reads a package from disk when it is not in memory. At the
title screen the level's actors are gone, but the mod's packages stay loaded
as long as any object still references one of their classes. The main plugin
removes the one reference that survives a level: it moves panels of the game's
HUD into the mod's 3D widgets, and the game's HUD outlives the level. At every
level change `release_game_panels_from_mod_widgets` in `plugin_utils.cpp`
detaches those panels again, so the next garbage collection can free the mod's
widgets, their classes and everything those classes reference.

## BridgeSDK after a reload

The main plugin reaches the mod's Blueprints through the BridgeSDK headers,
which cache class, property and function pointers. Those caches are dropped at
every level change (`bridge::invalidate()`, see
`documentation/bridge-sdk-warmup.md`), so after the trip through the title
screen the next level load resolves every name against the classes from the
new pak. No signal between the two plugins is needed.

## Limits

- **Blueprint classes with live instances are not replaced.** The old class
  stays in memory while an instance exists. Quit to title before reloading so the
  level objects are released, or spawn from the new class after the load.
- **Objects held by persistent owners stay old.** Anything referenced by the
  GameInstance or other objects that survive a map change is not reloaded.
- **Shared shader code.** If the mod project cooks with shared material shader
  code, changed materials render wrong after a hot mount, because the shader
  library is opened only at start-up. Cook with inline shaders for hot reload.
- **The hotkey is read with `GetAsyncKeyState`** and only accepted while the game
  window is in the foreground.
