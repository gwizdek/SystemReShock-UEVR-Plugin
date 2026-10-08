---
name: build-and-deploy
description: Build the UEVR plugin (Release x64) and deploy the DLL so the running game picks it up through the plugin hot loader. Use when the user says "build and deploy", "deploy the plugin", or wants to test a plugin change in the running game.
disable-model-invocation: true
allowed-tools: PowerShell, Bash, Read
---

# Build and deploy the plugin

Builds `SystemShockVR\SystemShockVR.vcxproj` and copies `SystemReShockVR.dll` into the hot
loader's watched folder:

```
%APPDATA%\UnrealVRMod\SystemReShock-Win64-Shipping\hot_plugins\
```

`PluginHotLoader.dll` in the profile `plugins\` folder swaps to the new build by itself within a
few seconds. Nothing has to be done in the UEVR overlay. See `documentation\plugin-hot-reload.md`.

## Steps

1. From the repository root, run:

   ```powershell
   powershell -ExecutionPolicy Bypass -File scripts\build-and-deploy.ps1
   ```

   Pass `-Configuration Debug` only when the user asks for a Debug build.
   Pass `-SkipBuild` when the user only wants the existing DLL copied.
   Pass `-Direct` only when the user asks to deploy without the hot loader; the DLL then goes
   into `plugins\`, and the user must unload the plugin in the UEVR overlay before and reload it after.
   Pass `-Target PluginHotLoader` only when the user names the hot loader; it then builds
   `tools\PluginHotLoader\PluginHotLoader.vcxproj` and deploys `PluginHotLoader.dll` into `plugins\`.
   Pass `-Target PakHotReloader` only when the user names the hot reloader; it then builds
   `tools\PakHotReloader\PakHotReloader.vcxproj` and deploys `PakHotReloader.dll` into `plugins\`.

2. If the build fails, show the compiler or linker errors and stop. Do not copy a stale DLL.

3. If the script refuses because `plugins\SystemReShockVR.dll` exists, tell the user: unload the
   plugin in the UEVR overlay, delete that file, deploy the hot loader once with
   `-Target PluginHotLoader`, then run the script again with `-SkipBuild`. Never delete the file yourself.

4. If a copy into `plugins\` fails because the game has the DLL loaded, the script says so and stops.
   Tell the user to unload that plugin in the UEVR overlay, then run the script again with `-SkipBuild`.
   Never rename, move or delete the locked DLL.

5. On success, report in one or two lines: build result, the deployed path and timestamp. In the default
   mode say that the hot loader picks it up and that `[inner_plugin][load]` in `log.txt` confirms it.
   For `-Direct` and the two tool targets, remind the user to reload the plugin in the UEVR overlay.

## Rules

- This builds the plugin only. It never builds the installer.
- Follow `.claude/rules/build.md`: x64 only, output stays in `SystemShockVR\x64\<Configuration>\`.
