# Game Installs

> These rules apply whenever something needs the game's files, its exe, or its pak folder.

The game is installed twice on this machine. Both are the UE 4.27 Shipping build of the
System Shock remake and have the same folder layout below the install folder.

| Install | Folder | Exe |
|---|---|---|
| **Steam** | `D:\Steam\steamapps\common\System Shock Remake\` | `SystemShock\Binaries\Win64\SystemReShock-Win64-Shipping.exe` |
| **GOG** | `D:\GOG\System Shock Remake\` | `SystemShock\Binaries\Win64\SystemReShock-Win64-Shipping.exe` |

The pak folder of each install is `SystemShock\Content\Paks\`. The game's own pak is
`SystemShock-Windows.pak`. The mod's paks (`SystemShockVRModAddon_P.pak`,
`SystemShockVRModCore_P.pak`) are copied into that folder. `scripts\deploy-paks.ps1` copies the
Core pak there from the Unreal project's packaged output (see `build.md`).

## Development uses the Steam install

The Steam install is the one that runs with UEVR during development. Use it for:

- running and testing the plugin, the hot reloader and the hot loader;
- deploying paks for a test;
- reading code addresses from the exe, for example when disassembling engine functions.

`scripts\run-and-inject.ps1` (the `/run-and-inject` skill) starts the Steam game if it is not
running and injects UEVR from `D:\Modding\UEVR`. It does nothing when UEVR is already injected.

The two exes are different builds, so a code address found in one is wrong in the other.
When a plugin feature depends on an exe address, resolve it at run time from something
both builds share, such as a string or a UFunction's native pointer, and verify the result
before using it. Record static addresses for both builds when they are known.

The GOG install is a second copy for checking that a feature also works on that build. Do
not deploy development paks or plugins there unless asked.
