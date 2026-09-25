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

The shippable files are always in the repository `x64\<Configuration>\` folder:

- `SystemReShockVR.dll`
- `SystemReShockVR.exp`
- `SystemReShockVR.lib`
- `SystemReShockVR.pdb`

A command-line build of the project alone writes to `SystemShockVR\x64\<Configuration>\` and then copies these four files to the repository folder. A Visual Studio build through the solution writes to the repository folder directly. The copy is a target inside the project file, `CopyShipFilesToRepoOutDir`, so it runs for every build.

### Plugin rules

- Take the built DLL from the repository `x64\<Configuration>\` folder, never from `SystemShockVR\x64\`.
- Do not delete `SystemShockVR\SystemReShockVR\x64\`. It holds the `.obj` and `.tlog` files that make the next build incremental.
- Do not add `OutDir` or `IntDir` overrides to the project file or to the MSBuild command line.

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
- The sources are MSBuild properties in the installer project file: `ProfileSourceDir` (default `<repo>\profile\`), `PluginDllPath` (default `<repo>\x64\Release\SystemReShockVR.dll`) and `PakSourceDir` (default the Unreal project's `WindowsNoEditor\SystemShock\Content\Paks\` folder). Override with `/p:Name=value` when asked to build from another location.
- Only `pakchunk10-WindowsNoEditor.pak` is taken from `PakSourceDir`; it becomes `SystemShockVRModCore_P.pak`. `pakchunk0-WindowsNoEditor.pak` is never shipped. `SystemShockVRModAddon_P.pak` comes from `<repo>\profile\paks\`.
- Build the plugin before the installer when the installer must ship a fresh plugin. The installer build fails if the plugin DLL, the profile folder or the Core chunk is missing.
- Do not build the installer with `dotnet build SystemReShockVR.sln`. The solution also holds the C++ project, which the `dotnet` CLI cannot build.
