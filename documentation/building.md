# Building the plugin

This repository builds `SystemReShockVR.dll`, a UEVR plugin for System Shock
Remake. The mod also needs two `.pak` files with the mod's Blueprints. Those are
built from a separate Unreal Engine 4.27 project, described at the end.

## What you need

- Visual Studio 2022 with the "Desktop development with C++" workload. The
  project uses the v143 toolset, the Windows 10 SDK and C++20.
- The game, the Steam version. The profile does not work with the GOG version
  or the Steam demo.
- UEVR nightly, to run the plugin. The root `README.md` has the link and the
  install steps.
- Unreal Engine 4.27.2 and the mod's Unreal project, only if you change
  Blueprints or the BridgeSDK generator. Plain plugin work does not need them.

## Repository layout

| Path | What it is |
|---|---|
| `SystemReShockVR.sln` | The solution. It holds the C++ plugin and the two installer projects. |
| `SystemShockInstaller/` | The Windows installer and launcher for the mod, a C# WPF app with its tests. See `installer-spec.md` and its own `README.md`. |
| `SystemShockVR/` | Plugin source. `plugin.cpp` is the entry point and the frame callbacks; `vr_*.cpp` hold the features. |
| `SystemShockVR/SDK/` | Dumper-7 dump of the game's classes. Tracked in git, so no dump is needed to build. |
| `SystemShockVR/BridgeSDK/` | Generated wrappers for the mod's own Blueprints. Do not edit; see `bridge-sdk-generator.md`. |
| `SystemShockVR/uevr/` | The UEVR plugin API headers. |
| `SystemShockVR/imgui/`, `SystemShockVR/rendering/` | Dear ImGui and the DX11/DX12 hooks for the plugin's debug view. |
| `tools/UEVRBridgeGen/` | The BridgeSDK generator, an Unreal editor plugin. |
| `uobjecthook/`, `utils/` | Files that belong in the UEVR profile folder, not in the build. |
| `assets/` | Modified game widget assets used by the Unreal project. |
| `documentation/` | These documents. |

## Build

Open `SystemReShockVR.sln` in Visual Studio, pick **Release** and **x64**, and
build. Or from a Developer PowerShell:

```powershell
msbuild SystemShockVR\SystemShockVR.vcxproj /p:Configuration=Release /p:Platform=x64 /m
```

The DLL lands in `x64\Release\SystemReShockVR.dll` at the repository root
either way. A Visual Studio build writes there directly. A command-line build of
the project alone writes to `SystemShockVR\x64\Release\` and then copies the
`.dll`, `.exp`, `.lib` and `.pdb` to the repository folder. The copy is the
`CopyShipFilesToRepoOutDir` target in the project file. Leave
`SystemShockVR\SystemReShockVR\x64\` alone; it holds the `.obj` and `.tlog`
files that keep builds incremental.

Notes on the configurations:

- **Release x64** is the one to use. The game is 64-bit.
- **Debug x64** is the same build with optimisation off, for stepping through
  the plugin in a debugger attached to the game.
- The Win32 configurations exist in the project file but are not used.

A full build compiles about forty Dumper-7 source files plus the plugin and
ImGui, and takes a few minutes. The x64 configurations do not use a
precompiled header, so a change to a widely included header recompiles most of
the plugin.

There are no external libraries to install. Everything the plugin links
against is a Windows system library, pulled in by `#pragma comment(lib, ...)`.

## Deploy and run

UEVR loads plugins from the game's profile folder:

```
%APPDATA%\UnrealVRMod\SystemReShock-Win64-Shipping\plugins\
```

1. Make sure the profile exists. The easiest way is to import the release zip
   through the UEVR frontend once, as the root `README.md` describes. That
   brings the config, the `uobjecthook` state and the paks.
2. Close the game if it is running. UEVR keeps the DLL locked while injected.
3. Copy `SystemReShockVR.dll` into the `plugins` folder above.
4. Launch the game, wait for the main menu, and inject UEVR.

The plugin writes to `log.txt` in the profile folder through the UEVR log.
Its lines are tagged `[Plugin]`, followed by the source file and function, for
example `[Plugin] [vr_body][initialize_vr_body] Begin`. Errors from the
BridgeSDK are tagged `[bridge]`.

Nothing in the build copies the DLL for you. If you want that, add a post-build
step in Visual Studio that copies to the folder above.

## The mod's Blueprints and the paks

The plugin spawns and drives Blueprint actors that ship in two pak files,
`SystemShockVRModCore_P.pak` and `SystemShockVRModAddon_P.pak`. They are built
from the Unreal project, not from this repository. The release zip carries them
in its `paks` folder, and the install steps in the root `README.md` copy them
into the game's `Content\Paks` folder.

The project lives where `tools/UEVRBridgeGen/bridgegen.config.json` says, in
its `project` key. Its own `README.md` explains the editor settings, the chunk
setup and how to package the paks. In short: set Build Configuration to
Shipping, package for Windows 64-bit, take the paks from
`WindowsNoEditor\SystemShock\Content\Paks\`, and give them a `_P` suffix so the
game loads them last.

When a Blueprint's variables or functions change, the wrappers in
`SystemShockVR/BridgeSDK/` must be regenerated before the plugin is rebuilt:

```powershell
.\tools\UEVRBridgeGen\Generate.ps1
```

`bridge-sdk-generator.md` covers the script, the config file and first-time
setup of the generator. The compiler then reports every call site that a
renamed or removed member breaks.

## Changing the game's own classes

`SystemShockVR/SDK/` is a Dumper-7 dump of the game. It only needs a new dump
when the game updates. Dumping is done at runtime with Dumper-7 against the
running game, and the result replaces the folder. The mod's own Blueprints are
not part of that dump; they come from the generator above.

## Git

`master` is the default branch. Work on a branch named after
`.claude/rules/git-workflow.md`, for example `feature/...` or `fix/...`, and
use the conventional commit format described there.
