# Build Rules

> These rules apply whenever something in this repository is built.

## Naming

The repository holds two things that can be built. Use these names:

| Name | Project | What it is |
|---|---|---|
| **plugin** | `SystemShockVR\SystemShockVR.vcxproj` | The C++ UEVR plugin, `SystemReShockVR.dll`. |
| **installer** | `SystemShockInstaller\src\SystemReShockInstaller\SystemReShockInstaller.csproj` | The C# WPF installer and launcher, `SystemReShockVRMod.exe`. Its tests are in `SystemShockInstaller\tests\`. |

"Build the plugin" means the plugin only. "Build the installer" means the installer only. "Build everything" means both. When the request does not say which one, ask.

## Plugin

From a Developer PowerShell at the repository root:

```powershell
msbuild SystemShockVR\SystemShockVR.vcxproj /p:Configuration=Release /p:Platform=x64 /m
```

The platform is always x64. The Win32 configurations are not used. Use Debug only when asked to.

### Where the plugin output lands

The shippable files are always in `SystemShockVR\x64\<Configuration>\`, whether the build comes from Visual Studio or the command line:

- `SystemReShockVR.dll`
- `SystemReShockVR.exp`
- `SystemReShockVR.lib`
- `SystemReShockVR.pdb`

The project file sets `OutDir` and `IntDir` for x64 on purpose. Without them, Visual Studio would write the output to the repository root `x64\` folder and put the `.obj` files next to the DLL.

### Deploying the plugin for testing

To test a build in the game, the DLL must be copied into the UEVR profile plugins folder
`%APPDATA%\UnrealVRMod\SystemReShock-Win64-Shipping\plugins\` and then reloaded from the UEVR overlay.
The reload is always a manual step done by the user.

`scripts\build-and-deploy.ps1` builds the plugin and copies the DLL and PDB there. The `/build-and-deploy`
skill runs that script. "Build and deploy" means the plugin only.

The game keeps the loaded DLL locked. Unload the plugin in the UEVR overlay before deploying. If the DLL is
still locked, the script stops with a message and does not rename, move or delete the file.

### Plugin rules

- Take the built DLL from `SystemShockVR\x64\<Configuration>\`. Nothing should be written to the repository root `x64\` folder.
- Do not delete `SystemShockVR\x64\<Configuration>\obj\`. It holds the `.obj` and `.tlog` files that make the next build incremental.
- Do not override `OutDir` or `IntDir` on the MSBuild command line, and do not remove the `OutDir` setting from the project file.

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
