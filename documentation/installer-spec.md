# System Shock Remake VR Mod – Specification

One Windows EXE, `SystemReShockVRMod.exe`, that both installs and launches the
System Shock Remake UEVR mod. It does not ship UEVR.

- **Installer**: copies the bundled UEVR profile and pak files into place, and
  removes them again on request.
- **Launcher**: starts the game, through Steam or from its exe depending on
  the store, waits for the main menu, and injects UEVR.

The Steam and the GOG version of the game are both supported. The plugin
itself runs on both builds; the installer only has to find the game and start
it the right way.

## Stack

- .NET Framework 4.8, C#, WPF, MVVM. 64-bit only, because the launcher injects
  DLLs into the 64-bit game.
- Single EXE, no runtime download. Manifest: `asInvoker`, per-monitor DPI aware.
- Window title "System Shock Remake VR Mod Setup" on wizard pages and
  "System Shock Remake VR Mod" on the launcher page.
- Assembly version `2.0.0.0`. Informational version `2.0-beta.2` (shown in the UI).
  Matches the latest release at
  https://github.com/gwizdek/SystemReShock-UEVR-Plugin/releases
- Folder picker: COM `IFileOpenDialog` with `FOS_PICKFOLDERS`. No NuGet dependency.
- Tests: xUnit on net48. Services only, no UI tests.

## Bundled files

- On every build, MSBuild targets in the project file empty `mod_files/`, fill
  it from the repository `profile/` folder (without `imgui.ini`), the plugin
  DLL in `SystemShockVR/x64/Release/` and the cooked Core chunk from the
  Unreal project, then zip it into `obj/` and embed the zip as a resource.
- The three source paths are MSBuild properties (`ProfileSourceDir`,
  `PluginDllPath`, `PakSourceDir`) and can be overridden with `/p:`.
- `mod_files/` is not in git. Adding a file to `profile/` needs no code change.
- The empty `mod_files/scripts/` folder is not created. UEVR creates it itself.
- `mod_files/ProfileMeta.json` `fileCopies` lists both real paks:
  `SystemShockVRModCore_P.pak` and `SystemShockVRModAddon_P.pak`.

## Targets

| What | Where |
|------|-------|
| Profile (everything except `paks/`) | `%AppData%\UnrealVRMod\SystemReShock-Win64-Shipping\` |
| Paks (`paks/*.pak`) | `<game>\SystemShock\Content\Paks\` |
| Settings | `%AppData%\SystemReShockVR\settings.json` |

`<game>` is the folder the user picks, for example
`D:\Steam\steamapps\common\System Shock Remake` or
`D:\GOG Games\System Shock Remake`. Both stores use the same folder layout.

The environment variable `SYSTEMRESHOCKVR_APPDATA` replaces `%AppData%` for
both the profile and the settings file. It exists for testing.

## settings.json

```json
{
  "uevrPath": "D:\\UEVR",
  "gamePath": "D:\\Steam\\steamapps\\common\\System Shock Remake",
  "installedVersion": "2.0-beta.2",
  "installedAt": "2026-09-18T23:10:00+02:00",
  "runtime": "openxr",
  "injectDelaySeconds": 15,
  "store": "steam"
}
```

`runtime` is `openxr` or `openvr`. Missing means OpenXR. `injectDelaySeconds`
is the wait between the game window appearing and injection. Missing means 15.
Only the launcher page writes `runtime`; the delay is edited by hand.

`store` is `steam`, `gog` or `other` and decides how the launcher starts the
game. The install step writes it. When it is missing, the startup check works
it out from the game folder for that run and does not rewrite the file.

### How the store is decided

The folder decides, not where the detector found it:

| Folder | Store |
|--------|-------|
| Contains a `goggame-*.info` file at its root | `gog` |
| Path contains `\steamapps\common\` | `steam` |
| Anything else, for example a copied install | `other` |

`other` behaves like `gog`: the game starts from its exe.

## Startup decision

The startup check compares the embedded bundle with the installed files.
Paks and plugin DLLs must match byte for byte. Every other profile file only
has to exist, because UEVR rewrites `config.txt`, `cameras.txt`, `cvars_*.txt`,
the imgui ini, and `uobjecthook\*.json` while the player changes settings.

| Found | Page shown |
|-------|-----------|
| No settings | Wizard |
| A saved folder no longer validates, or a mod file is missing | Wizard, with Uninstall offered |
| Files present, `installedVersion` equals this EXE | Launcher |
| Files present, `installedVersion` differs | Welcome page in update mode |
| Version equal but a pak or plugin differs | Wizard, with the reason shown |

Any version difference counts as "update available". The text shows both
versions so a user running an older setup can still choose Launch.

The `--install` command line flag forces the wizard.

## Wizard pages

No Back buttons on any page. Cancel returns to the launcher when a working
install exists, otherwise it closes the app.

1. **Welcome.** Shodan image, UEVR logo at the bottom, version text.
   Buttons: Next, Cancel. In update mode the text "Mod vX is installed. This
   setup contains vY." appears and the buttons are Update, Launch game, Close.
   When the wizard opened because a pak or plugin changed, the reason appears
   in the same place. An Uninstall button appears whenever `settings.json`
   exists; see **Uninstall** below.
2. **Paths.** Two folder fields with Browse buttons.
   - UEVR folder. Must contain `UEVRInjector.exe`.
   - Game folder. Must contain
     `SystemShock\Binaries\Win64\SystemReShock-Win64-Shipping.exe`.
   - Text explaining how to get UEVR: download the latest nightly from
     https://github.com/praydog/UEVR-nightly/releases/latest, extract it to any
     folder, and point the field at that folder. The link opens in the browser.
   - The page looks for the game in both stores. Steam: registry install path
     plus a `libraryfolders.vdf` scan. GOG: the `path` value under
     `HKLM\SOFTWARE\GOG.com\Games\1439637285` (32-bit view first).
   - Both fields are pre-filled from `settings.json` when it exists. Without
     settings, the game field is pre-filled when exactly one store has the
     game. When both stores have it, the field stays empty.
   - When both stores have the game, two buttons, "Use Steam version" and
     "Use GOG version", appear under the heading with the folder under each.
     A click fills the game field. They appear even when the field was
     pre-filled from settings.
   - Under a valid game field a line says which version the folder holds:
     "Steam version found.", "GOG version found." or "Not a Steam or GOG
     install. The launcher will start the game from its exe."
   - Inline red error under a field that fails validation. Next is disabled
     until both fields pass.
   - Buttons: Next, Cancel.
3. **Confirmation.** Lists the exact actions with resolved paths:
   - delete the old profile folder and copy the new profile
   - delete old `SystemShockVRModCore_P.pak` and `SystemShockVRModAddon_P.pak`
     and copy the new ones
   - save settings
   Buttons: Install, Cancel.
4. **Result.** One line per step with a success or failure mark and the error
   text on failure. Shows the resolved target paths and next steps.
   Button: Continue (opens the launcher) on success, Close on failure.

## Install steps (in order)

Before starting: if a `SystemReShock-Win64-Shipping` process is running, block
with "Close the game first".

1. **Paks.** Delete the two known pak names if present, then copy the new ones.
   Runs first because it is the most likely step to fail.
2. **Profile.** Delete `%AppData%\UnrealVRMod\SystemReShock-Win64-Shipping\`
   entirely, then extract every zip entry except `paks/`.
3. **Settings.** Write `settings.json` with `uevrPath`, `gamePath`, `store`,
   `installedVersion`, `installedAt`. Existing `runtime` and
   `injectDelaySeconds` values are not carried over; the file is rewritten.

No rollback. If a step fails, later steps do not run, and the result page shows
which steps finished.

Access denied or locked file errors show: "Access denied. <detail> Close the
game and try running the installer as administrator."

## Uninstall

Reachable from the Welcome page whenever `settings.json` exists, and from the
launcher. Both run the same flow:

1. If the game is running, a message box says to close it first. Nothing else
   happens.
2. A Yes/No message box titled "Remove the mod?" lists every step with its
   paths, the same text the confirmation page would show, and ends with "Your
   game files and save games are not touched. Continue?"
3. On Yes, the steps run in order and stop at the first failure, like an
   install. Missing files and folders are skipped, not errors.
   1. **Paks.** Delete `SystemShockVRModCore_P.pak` and
      `SystemShockVRModAddon_P.pak` from the game's `Paks` folder.
   2. **Profile.** Delete `%AppData%\UnrealVRMod\SystemReShock-Win64-Shipping\`.
   3. **Settings.** Delete `settings.json`, and its folder when nothing else
      is in it.
4. The result page shows "Mod removed" or "Removal failed" with one line per
   step. Its only button is Close, which exits the app, because there is
   nothing left to launch.

The saved paths are kept in memory for this even when a folder no longer
exists or a mod file is missing, so a broken install can still be removed.

## Launcher page

Same layout as the welcome page: Shodan image left, UEVR logo bottom left.

- Heading "System Shock Remake VR Mod" and "Mod vX installed".
- A line naming the store and how the game starts, for example "GOG version.
  The game is started from the game folder."
- VR runtime selector: OpenXR (default) or OpenVR. Saved to `settings.json`
  the moment it is clicked.
- Info line: "UEVR is injected 15 seconds after the game window appears."
- Status box that follows the launch.
- Buttons: Reinstall (opens the paths page), Uninstall, Exit, Launch game.

### Launch flow

1. If a ready game process exists, skip to step 4. Ready means: process named
   `SystemReShock-Win64-Shipping` with a main window and `d3d11.dll` or
   `d3d12.dll` loaded. Steam's bootstrap briefly shares the exe name, so the
   name alone is not enough.
2. Steam version: open `steam://rungameid/482400`, and if that throws, start
   the exe directly. GOG and other versions: start
   `SystemShock\Binaries\Win64\SystemReShock-Win64-Shipping.exe` with its own
   folder as the working directory. GOG Galaxy is not used; GOG games are
   DRM-free, Galaxy is often not installed, and starting it first could push
   the game window past the timeout below. The status line reads "Starting
   System Shock Remake through Steam..." or "... from the game folder...".
3. Poll every 500 ms for a ready process. Give up after 2 minutes.
4. Count down `injectDelaySeconds`, updating the status line each second.
5. Inject the runtime loader (`openxr_loader.dll` or `openvr_api.dll`) from the
   UEVR folder, then `UEVRBackend.dll`. This is the same order the UEVR
   frontend uses. The plugin nullifier is not injected because the profile has
   `nullifyPlugins: false`.
6. Status reads "UEVR injected. Put on your headset." Launch stays disabled;
   Reinstall and Exit come back. Closing the window never touches the game.

Injection is remote-thread `LoadLibraryW`: open the process, write the DLL
path into it, start a thread at `LoadLibraryW`, wait up to 10 seconds, then
confirm the module is listed in the process. On failure the status shows the
Win32 error and a note that antivirus software often blocks this step, and
Launch is enabled again for a retry.

## Unicode

All paths go through `System.IO` with full Unicode strings. Tests use temp
folders with non-ASCII names, for example `Gra – Zażółć gęślą jaźń`.

## Graphics

`assets/shodan.png` (600 x 842) and `assets/uevr_logo.PNG` in the installer
folder are linked into the app as WPF resources.

## Layout

The installer lives in `SystemShockInstaller/` at the root of the plugin
repository. Both projects below are part of the repository solution,
`SystemReShockVR.sln`. All paths in this section are relative to
`SystemShockInstaller/`.

```
README.md                        player and developer guide
assets/                          shodan.png, uevr_logo.PNG
mod_files/                       the mod, rebuilt from its sources, zipped and embedded at build time; not in git
src/SystemReShockInstaller/
  App.xaml(.cs)                  composes services, reads --install and the AppData override
  MainWindow.xaml                fixed-size shell hosting the current page
  Interop/                       COM folder dialog and kernel32 injection declarations
  Models/                        ModPaths (fixed names), InstallPlan, InstallState, StepResult,
                                 InstallerSettings, BundleEntry, VrRuntime, GameStore, LaunchRequest
  Services/                      install: ModBundle, InstallService, PakInstallStep,
                                 ProfileInstallStep, SettingsSaveStep, SettingsStore,
                                 SteamLocator, GogLocator, GameLocators, GameStoreDetector,
                                 PathValidator, FolderPicker, ProcessChecker, InstallErrorFormatter
                                 uninstall: PakRemoveStep, ProfileRemoveStep, SettingsRemoveStep,
                                 IDialogs, MessageBoxDialogs
                                 launch: InstallVerifier, InstallStateResolver, GameStarter,
                                 GameProcessWatcher, DllInjector, UevrInjector,
                                 GameLaunchService, LaunchErrorFormatter
  ViewModels/                    ShellViewModel (routing) + one per page, UninstallFlow, RelayCommand
  Views/                         Theme.xaml, HeroFrame, WelcomePage, PathsPage, ConfirmPage,
                                 ResultPage, LauncherPage
tests/SystemReShockInstaller.Tests/
```

Every install and uninstall step implements `IInstallStep` with a `Describe`
method for the confirmation page or the uninstall question, and an `Execute`
method. `InstallService` runs a list in order; `App.xaml.cs` builds one list
for installing and one for uninstalling. Adding a step means adding a class
and one line there.

`HeroFrame` is the shared page frame (Shodan column, content, bottom bar with
logo and buttons) used by the welcome and launcher pages.

Repo rules apply: methods under 30 lines, files under 500 lines, services hold
the logic, views stay thin.
