# System Shock Remake VR Mod

One small Windows program, `SystemReShockVRMod.exe`, that installs the System
Shock Remake UEVR mod and then launches the game with UEVR injected. It does
not include UEVR itself.

Mod releases: https://github.com/gwizdek/SystemReShock-UEVR-Plugin/releases

## For players

First run:

1. Download the latest UEVR nightly from
   https://github.com/praydog/UEVR-nightly/releases/latest and extract it to
   any folder.
2. Run `SystemReShockVRMod.exe`.
3. Point the wizard at the UEVR folder and the System Shock Remake folder. The
   Steam and the GOG version both work. The game folder is filled in when the
   program finds the game; when it finds both versions, pick one with the
   buttons at the top of the page.
4. Press Install, then Continue.

Every run after that opens the launcher:

1. Pick OpenXR or OpenVR (SteamVR). The choice is remembered.
2. Press Launch game. The Steam version starts through Steam, the GOG version
   starts from its game folder. Fifteen seconds after the game window appears,
   UEVR is injected. Watch the status line.
3. Put on your headset. The launcher can be closed; the game keeps running.

If a new mod version is installed over an old one, the program offers to update
first. Use Reinstall on the launcher page to repair an install. Use Uninstall,
on the launcher page or on the first wizard page, to remove the mod. It deletes
only the files listed in the table below and asks before it does.

The program writes to these places:

| What | Where |
|------|-------|
| UEVR profile | `%AppData%\UnrealVRMod\SystemReShock-Win64-Shipping\` |
| Mod paks | `<game>\SystemShock\Content\Paks\` |
| Settings | `%AppData%\SystemReShockVR\settings.json` |

Requirements: 64-bit Windows 10 or 11 with .NET Framework 4.8, which both
include. Antivirus software sometimes blocks the injection step. Add an
exception for this program and the UEVR folder if that happens.

## For developers

Requirements: .NET SDK 8 or newer, or Visual Studio 2022 with the .NET desktop
workload.

The installer is part of the plugin repository. Its two projects live in the
repository solution, `SystemReShockVR.sln`, next to the C++ plugin. Build them
alone from this folder:

```
dotnet build src\SystemReShockInstaller\SystemReShockInstaller.csproj -c Release
dotnet test  tests\SystemReShockInstaller.Tests\SystemReShockInstaller.Tests.csproj
```

The EXE lands in `src\SystemReShockInstaller\bin\Release\net48\`.

Command line and environment:

| Option | Effect |
|--------|--------|
| `--install` | Always open the install wizard, even when the mod is installed. |
| `SYSTEMRESHOCKVR_APPDATA=<folder>` | Use this folder instead of `%AppData%` for the profile and settings. For testing. |

### Layout

| Folder | Contents |
|--------|----------|
| `mod_files/` | The mod as shipped. Rebuilt from its sources on every build, then zipped and embedded in the EXE. Not in git. Do not edit it by hand; see **Where the mod files come from**. |
| `assets/` | Shodan image and UEVR logo. |
| `src/SystemReShockInstaller/` | WPF app. `Services/` holds all file, process, and injection work, `ViewModels/` the page logic, `Views/` the XAML pages. |
| `tests/SystemReShockInstaller.Tests/` | xUnit tests for the services. They use temp folders with non-ASCII names and inject a system DLL into a child process to prove the injector. |
| `../documentation/installer-spec.md` | Design decisions, the startup decision table, and the full wizard and launcher behaviour. |

### Where the mod files come from

Every build empties `mod_files/` and fills it again from three sources. Each
source is an MSBuild property in `src/SystemReShockInstaller/SystemReShockInstaller.csproj`
and can be overridden on the command line with `/p:Name=value`.

| Property | Default | Copied to |
|----------|---------|-----------|
| `ProfileSourceDir` | `<repo>\profile\` | `mod_files\` (all files and folders, except `imgui.ini`) |
| `PluginDllPath` | `<repo>\SystemShockVR\x64\Release\SystemReShockVR.dll` | `mod_files\plugins\` |
| `PakSourceDir` | `d:\Unreal Engine\Projects\SystemReShock-UE4-Project\WindowsNoEditor\SystemShock\Content\Paks\` | `mod_files\paks\` |

From `PakSourceDir` only `pakchunk10-WindowsNoEditor.pak` is taken. It is
renamed to `SystemShockVRModCore_P.pak`. The other cooked chunks are not
shipped. `SystemShockVRModAddon_P.pak` is not cooked; it lives in
`<repo>\profile\paks\` and comes in with the profile copy.

The build stops with an error when the profile folder, the plugin DLL or the
Core chunk is missing, or when either pak is missing from `mod_files\paks\`
after the copy.

### Releasing a new mod version

1. Build the plugin in Release so `<repo>\SystemShockVR\x64\Release\SystemReShockVR.dll` is current.
2. Package the Unreal project so `pakchunk10-WindowsNoEditor.pak` is current.
3. Update the files in `<repo>\profile\` if the profile changed.
4. Set `InformationalVersion` in `src/SystemReShockInstaller/SystemReShockInstaller.csproj`
   to the release tag, for example `2.0-beta.3`.
5. Build in Release and publish the EXE from `bin\Release\net48\`.
