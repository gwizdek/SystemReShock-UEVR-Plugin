---
name: build-and-deploy
description: Build the UEVR plugin (Release x64) and copy the DLL into the UEVR profile plugins folder so it can be reloaded from the UEVR overlay. Use when the user says "build and deploy", "deploy the plugin", or wants to test a plugin change in the running game.
disable-model-invocation: true
allowed-tools: PowerShell, Bash, Read
---

# Build and deploy the plugin

Builds `SystemShockVR\SystemShockVR.vcxproj` and copies `SystemReShockVR.dll` (and `.pdb`)
into the UEVR profile plugins folder:

```
%APPDATA%\UnrealVRMod\SystemReShock-Win64-Shipping\plugins\
```

Reloading the plugin is a manual step the user does in the UEVR overlay. Never try to do it.

## Steps

1. From the repository root, run:

   ```powershell
   powershell -ExecutionPolicy Bypass -File scripts\build-and-deploy.ps1
   ```

   Pass `-Configuration Debug` only when the user asks for a Debug build.
   Pass `-SkipBuild` when the user only wants the existing DLL copied.

2. If the build fails, show the compiler or linker errors and stop. Do not copy a stale DLL.

3. If the copy fails because the game has the DLL loaded, the script says so and stops.
   Tell the user to unload the plugin in the UEVR overlay, then run the script again with `-SkipBuild`.
   Never rename, move or delete the locked DLL.

4. On success, report in one or two lines: build result, the deployed path and timestamp,
   and remind the user to reload the plugin in the UEVR overlay.

## Rules

- This builds the plugin only. It never builds the installer.
- Follow `.claude/rules/build.md`: x64 only, output stays in `SystemShockVR\x64\<Configuration>\`.
