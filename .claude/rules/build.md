# Build Rules

> These rules apply whenever something in this repository is built.

## Naming

The repository holds two things that can be built. Use these names:

| Name | Project | What it is |
|---|---|---|
| **plugin** | `SystemShockVR\SystemShockVR.vcxproj` | The C++ UEVR plugin, `SystemReShockVR.dll`. |
| **installer** | `SystemShockInstaller\src\SystemReShockInstaller\SystemReShockInstaller.csproj` | The C# WPF installer and launcher, `SystemReShockVRMod.exe`. Its tests are in `SystemShockInstaller\tests\`. |
| **hot reloader** | `tools\PakHotReloader\PakHotReloader.vcxproj` | A development-only UEVR plugin, `PakHotReloader.dll`, that mounts a rebuilt pak into the running game. Not shipped by the installer. See `documentation\pak-hot-reload.md`. |
| **hot loader** | `tools\PluginHotLoader\PluginHotLoader.vcxproj` | A development-only UEVR plugin, `PluginHotLoader.dll`, that loads the plugin from a copy and swaps in a new build while the game runs. Not shipped by the installer. See `documentation\plugin-hot-reload.md`. |
| **bytecode exporter** | `tools\BytecodeExporter\BytecodeExporter.csproj` | A C# command line tool, `BytecodeExporter.exe`, that writes the Blueprint bytecode, variables, components, widget tree and enums of one `.uasset` as JSON. Development only, not shipped. See `tools\BytecodeExporter\README.md`. |

"Build the plugin" means the plugin only. "Build the installer" means the installer only. "Build the hot reloader" means the hot reloader only. "Build the hot loader" means the hot loader only. "Build the bytecode exporter" means the bytecode exporter only. "Build everything" means the plugin and the installer. When the request does not say which one, ask.

## Plugin

From a Developer PowerShell at the repository root:

```powershell
msbuild SystemShockVR\SystemShockVR.vcxproj /p:Configuration=Release /p:Platform=x64 /m
```

The platform is always x64. The Win32 configurations are not used. Use Debug only when asked to.

### Build index and version

Every plugin build raises the number in `SystemShockVR\build_index.txt` by one. A target in the
project file runs `scripts\bump-build-index.ps1` before compiling. The script also writes
`SystemShockVR\build_version_generated.hpp` (gitignored) with that index and the plugin version,
which it reads from `InformationalVersion` in the installer project file. The plugin shows both in
the title of its ImGui window, for example `2.0-beta.3 [45]`. Commit `build_index.txt` with the
build it belongs to. Do not edit the generated header; it is overwritten on the next build.

### Where the plugin output lands

The shippable files are always in `SystemShockVR\x64\<Configuration>\`, whether the build comes from Visual Studio or the command line:

- `SystemReShockVR.dll`
- `SystemReShockVR.exp`
- `SystemReShockVR.lib`
- `SystemReShockVR.pdb`

The project file sets `OutDir` and `IntDir` for x64 on purpose. Without them, Visual Studio would write the output to the repository root `x64\` folder and put the `.obj` files next to the DLL.

### Deploying the plugin for testing

`scripts\build-and-deploy.ps1` builds the plugin and deploys it. The `/build-and-deploy` skill runs that
script. "Build and deploy" means the plugin only, unless the hot reloader or the hot loader is named.

By default the script copies the DLL into the hot loader's watched folder
`%APPDATA%\UnrealVRMod\SystemReShock-Win64-Shipping\hot_plugins\`. The hot loader, `PluginHotLoader.dll`
in the profile `plugins\` folder, loads a copy of it and swaps to the new build by itself while the game
runs. No overlay step is needed. The watched file must stay outside `plugins\`, because UEVR loads every DLL
in that folder. See `documentation\plugin-hot-reload.md`.

With `-Direct` the script copies the DLL and PDB into the profile `plugins\` folder instead, and the plugin
must then be unloaded in the UEVR overlay before deploying and reloaded there afterwards. Both are manual
steps done by the user. The game keeps a loaded DLL in `plugins\` locked; if the DLL is still locked, the
script stops with a message and does not rename, move or delete the file. The script refuses the default
mode while `plugins\SystemReShockVR.dll` exists, since UEVR and the hot loader would both load the plugin.

### Plugin rules

- The game loads its own `MSVCP140.dll` version 14.24 from its `Binaries\Win64\` folder. A `std::mutex`
  built with a current Visual Studio needs runtime 14.40 or newer, so its first lock throws inside the
  game. Any plugin in this repository that uses `std::mutex` must link the CRT statically
  (`RuntimeLibrary` = `MultiThreaded`) or define `_DISABLE_CONSTEXPR_MUTEX_CONSTRUCTOR`. The hot loader
  does both. `std::shared_mutex` is not affected.
- Take the built DLL from `SystemShockVR\x64\<Configuration>\`. Nothing should be written to the repository root `x64\` folder.
- Do not delete `SystemShockVR\x64\<Configuration>\obj\`. It holds the `.obj` and `.tlog` files that make the next build incremental.
- Do not override `OutDir` or `IntDir` on the MSBuild command line, and do not remove the `OutDir` setting from the project file.

### Deploying the Core pak for testing

`scripts\deploy-paks.ps1` copies `pakchunk10-WindowsNoEditor.pak` from the Unreal project's
packaged output (`WindowsNoEditor\SystemShock\Content\Paks\`) into the Steam game's pak folder as
`SystemShockVRModCore_P.pak`. Before the copy it removes `pakchunk10-WindowsNoEditor.pak`,
`pakchunk10-WindowsNoEditor_P.pak` and `SystemShockVRModCore_P.pak` from that folder, so only one
copy of the Core pak is mounted. `scripts\build-and-deploy.ps1 -Target Paks` runs the same script
and builds nothing. "Deploy paks" means this. A mounted pak is locked by the game; the script stops
with a message and the game must be closed first.

## Hot reloader

From a Developer PowerShell at the repository root:

```powershell
msbuild tools\PakHotReloader\PakHotReloader.vcxproj /p:Configuration=Release /p:Platform=x64 /m
```

The output lands in `tools\PakHotReloader\x64\<Configuration>\PakHotReloader.dll`. It shares the UEVR API
headers and the ini reader with the plugin through an include path into `SystemShockVR\`; it has no other
dependencies. The same plugin rules apply: x64 only, do not touch `OutDir`, `IntDir` or the `obj\` folder.

`scripts\build-and-deploy.ps1 -Target PakHotReloader` builds it and copies the DLL and PDB into the UEVR
profile plugins folder. UEVR loads every DLL in that folder, so the hot reloader runs as an independent
plugin. Remove the DLL from the folder to switch it off.

## Hot loader

From a Developer PowerShell at the repository root:

```powershell
msbuild tools\PluginHotLoader\PluginHotLoader.vcxproj /p:Configuration=Release /p:Platform=x64 /m
```

The output lands in `tools\PluginHotLoader\x64\<Configuration>\PluginHotLoader.dll`. Like the hot
reloader it shares the UEVR API headers and the ini reader with the plugin through an include path into
`SystemShockVR\`, and the same plugin rules apply.

`scripts\build-and-deploy.ps1 -Target PluginHotLoader` builds it and copies the DLL and PDB into the UEVR
profile plugins folder. It is itself locked while loaded, so replacing it needs the overlay step. It rarely
changes. Remove the DLL from the folder to switch it off, and deploy the plugin with `-Direct` from then on.

## Bytecode exporter

From PowerShell at the repository root:

```powershell
dotnet build tools\BytecodeExporter\BytecodeExporter.csproj -c Release
```

The EXE lands in `tools\BytecodeExporter\bin\Release\net8.0\BytecodeExporter.exe`. It needs the
.NET 8 SDK and downloads `UAssetAPI` from NuGet on the first build. It has no tests.

## Installer

From PowerShell at the repository root:

```powershell
dotnet build SystemShockInstaller\src\SystemReShockInstaller\SystemReShockInstaller.csproj -c Release
dotnet test  SystemShockInstaller\tests\SystemReShockInstaller.Tests\SystemReShockInstaller.Tests.csproj -c Release
```

The EXE lands in `SystemShockInstaller\src\SystemReShockInstaller\bin\Release\net48\SystemReShockVRMod.exe`.

### Installer rules

- Run the tests after building the installer unless told not to.
- The build empties and refills `SystemShockInstaller\mod_files\` from three sources, then zips it into the EXE. Never edit `mod_files\` by hand and never commit it; it is gitignored.
- The sources are MSBuild properties in the installer project file: `ProfileSourceDir` (default `<repo>\profile\`), `PluginDllPath` (default `<repo>\SystemShockVR\x64\Release\SystemReShockVR.dll`) and `PakSourceDir` (default the Unreal project's `WindowsNoEditor\SystemShock\Content\Paks\` folder). Override with `/p:Name=value` when asked to build from another location.
- Only `pakchunk10-WindowsNoEditor.pak` is taken from `PakSourceDir`; it becomes `SystemShockVRModCore_P.pak`. `pakchunk0-WindowsNoEditor.pak` is never shipped. `SystemShockVRModAddon_P.pak` comes from `<repo>\profile\paks\`.
- Build the plugin before the installer when the installer must ship a fresh plugin. The installer build fails if the plugin DLL, the profile folder or the Core chunk is missing.
- Do not build the installer with `dotnet build SystemReShockVR.sln`. The solution also holds the C++ project, which the `dotnet` CLI cannot build.
