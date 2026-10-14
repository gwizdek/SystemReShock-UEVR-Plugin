# Plugin hot reload (PluginHotLoader)

PluginHotLoader is a development-only UEVR plugin in `tools/PluginHotLoader/`. It
loads the real plugin, `SystemReShockVR.dll`, from a copy and swaps it for a new
build while the game runs. Deploying a build is then a plain file copy. Nothing
has to be clicked in the UEVR overlay. It is not shipped by the installer.

## Why the overlay step is normally needed

UEVR loads every DLL in the profile's `plugins\` folder at start-up and keeps it
locked, so the file cannot be overwritten. The only way UEVR offers to unload or
reload plugins is the "Reload Plugins" button in its overlay. There is no
hotkey, no plugin API call and no frontend command for it.

The hot loader works around this by being the only plugin UEVR knows about. It
loads the real plugin itself, from a renamed copy, so the real plugin's file is
never locked. When that file changes, the loader frees the old copy and loads
the new one.

## How to use it

1. Build and deploy the loader once. It goes into the `plugins\` folder like any
   other plugin, so the game must not have an older copy of it loaded:

   ```powershell
   powershell -ExecutionPolicy Bypass -File scripts\build-and-deploy.ps1 -Target PluginHotLoader
   ```

2. Remove `SystemReShockVR.dll` from the `plugins\` folder if it is there. UEVR
   would load it directly, and the loader would load a second copy. The deploy
   script refuses to deploy while that file exists.

3. Deploy the plugin. This is the default target of the script:

   ```powershell
   powershell -ExecutionPolicy Bypass -File scripts\build-and-deploy.ps1
   ```

   The DLL lands in `%APPDATA%\UnrealVRMod\SystemReShock-Win64-Shipping\hot_plugins\`.
   If the game is running with the loader, the loader swaps to the new build within
   a few seconds. If the game is not running, the loader loads it at the next start.

4. Repeat step 3 for every build. `-SkipBuild` copies the DLL built last.

The `/build-and-deploy` skill runs the same script.

To go back to the plain setup, delete `PluginHotLoader.dll` from `plugins\` and
deploy the plugin with `-Direct`, which copies it into `plugins\` as before.

## Folders and files

| Path, under the profile folder | What it is |
|---|---|
| `plugins\PluginHotLoader.dll` | The loader. The only mod plugin UEVR loads. |
| `hot_plugins\SystemReShockVR.dll` | The real plugin, watched by the loader. Never locked. |
| `plugin_hot_load\SystemReShockVR_s<pid>_<n>.dll` | The copy that is loaded. A new name per load. Old copies are deleted at the next game start. |
| `PluginHotLoader.ini` | Settings, written with defaults and comments on the first start. |

The watched file lives next to `plugins\`, not inside it, because UEVR loads
every DLL inside `plugins\`.

## Settings

| Section | Key | Meaning |
|---|---|---|
| `plugin` | `file` | The DLL to load and watch. Default `<profile>\hot_plugins\SystemReShockVR.dll`. |
| `watch` | `poll_ms` | How often the file's write time is checked. Default 500. |
| `watch` | `settle_ms` | How long a new write time must stay unchanged before the swap. Default 1000. |

## How a swap works

The loader checks the watched file on the present thread, which is the thread
UEVR initializes plugins on. A change counts once the write time has stayed the
same for `settle_ms` and the file can be opened with no sharing, so a copy still
in progress is not picked up. The deploy script also writes the file under a
temporary name and renames it into place, which is atomic.

The swap then runs in this order:

1. Take the lifetime lock exclusively. Every forwarded callback holds it shared
   while it runs, so no callback is inside the old DLL during the next two steps.
2. Empty the callback lists and free the old DLL. Its staged copy is deleted.
3. Release the lock, copy the new file to a new staged name, load it, check its
   required UEVR version the way UEVR does, and call its `uevr_plugin_initialize`.

A build that fails to load leaves the loader running with no inner plugin. Fix
the build and deploy again; the loader keeps watching.

## What the inner plugin sees

The loader hands the inner plugin a copy of UEVR's `UEVR_PluginInitializeParam`.
Every function table is the real one, except:

- the two callback tables, `callbacks` and `sdk->callbacks`, register into the
  loader's lists, which forward to the inner plugin while it is loaded;
- `functions->remove_callback` removes from those lists;
- `functions->register_inline_hook` and `sdk->ufunction->hook_ptr` still install
  the hook, but mark the inner plugin as pinned. The loader has no way to remove
  such a hook, so it refuses to swap a pinned plugin and logs why. "Reload
  Plugins" in the UEVR overlay removes those hooks and reloads everything.

`SystemReShockVR.dll` installs UFunction hooks with `hook_ptr` once the HUD's key widget
classes are loaded (`button_legend_mode.cpp`), so it is pinned from then on. A new build
dropped into the watched folder is refused; use "Reload Plugins" in the UEVR overlay, which
removes the hooks and loads the new build. Before the hooks are installed, at the title
screen, the loader still swaps the plugin.

## Build notes

The loader links the CRT statically and defines
`_DISABLE_CONSTEXPR_MUTEX_CONSTRUCTOR`. The game loads its own `MSVCP140.dll`
version 14.24, and a `std::mutex` built with a current Visual Studio needs
14.40 or newer. Without one of the two settings every lock in the loader throws
and UEVR logs "Exception occurred in ... callback" for every forwarded callback
on every frame.

## Limits

- **UEVR's own "Reload Plugins" frees the loader without notice.** The inner
  DLL is left loaded on purpose, because freeing a DLL inside `DllMain` is not
  allowed. Nothing in UEVR points at it any more, so this is harmless, and the
  next loader instance loads a fresh copy under a new name.
- **The same unload rules as before apply.** Static state in the plugin dies
  with the DLL. The plugin re-creates everything on the next level change.
- **No `.pdb` next to the loaded copy.** The debugger finds the symbols through
  the build path stored in the DLL.

## Reading the log

Every line carries a `[plugin]`, `[inner_plugin]`, `[api_proxy]` or `[config]`
prefix from the loader's source files.

- `[plugin][initialize] watching ...` confirms the loader is active.
- `[inner_plugin][load] loaded ... as ...` after each start and each swap.
- `[plugin][swap_inner] ... changed, swapping` marks a detected deploy.
- `[api_proxy][pin] ...` means the inner plugin installed a hook the loader
  cannot remove; swaps are off until "Reload Plugins" in the overlay.
