# BridgeSDK warm-up

The BridgeSDK headers in `SystemShockVR/BridgeSDK/` find every Blueprint class,
variable and function by name through the UEVR API. Each name is looked up once,
on first use, and then cached. The warm-up moves all of those first lookups to
one moment during level setup, so no gameplay frame pays for them.

## Why it exists

After the first use, a bridge accessor is cheap. A variable read is a cached
offset added to the object address. A function call costs the same as a
Dumper-7 wrapper, because both end in `ProcessEvent`.

The first use is not cheap:

- Finding a class scans the whole Unreal object array and builds a name string
  for every object. This takes tens of milliseconds.
- Finding a variable or function walks the class and its parents by name.
  This takes microseconds, but a class can have hundreds of accessors.

Without the warm-up, a code path that runs for the first time in the middle of
the game pays for all of its call sites in one frame. The first melee swing or
the first time the MFD opens are examples. That shows up as a one-time stutter.

## How it works

Every accessor in a generated header has a companion that holds its cached
lookup. In `_BP_VRMovementComponent_classes.hpp`:

```cpp
static bridge::Prop& BridgeProp_ShowLowerBody() { static bridge::Prop Ref{ L"ShowLowerBody" }; return Ref; }
bool& ShowLowerBody() { return BridgeProp_ShowLowerBody().ref<bool>(this, BridgeClass()); }

static bridge::Func& BridgeFunc_SetCrouch() { static bridge::Func Ref{ L"SetCrouch", { L"InValue" } }; return Ref; }
void SetCrouch(bool InValue)
{
    bridge::Call BridgeCall(BridgeFunc_SetCrouch(), bridge::as_uobject(this));
    ...
}
```

The companion lets the warm-up resolve a name without reading an object or
calling a function.

Each generated class and struct has a `static bool BridgeWarmup()`. It finds the
class, then resolves every `BridgeProp_*` and `BridgeFunc_*` companion against
it. `bridge::warm()` in `Bridge.hpp` does the loop. A name that fails to resolve
is logged as `[bridge] ... not found`, and the loop continues with the next
name.

`BridgeSDK.hpp` defines `SDK::BridgeWarmupAll()`. It calls `BridgeWarmup()` on
every generated class and struct. The plugin does not use it. Finding a class
is the expensive part of a warm-up, and the plugin only touches about a third
of the generated classes.

`SystemShockVR/bridge_warmup_used.hpp` defines `SDK::BridgeWarmupUsed()`. It is
a hand-kept list of `BridgeWarmup()` calls for the classes the plugin uses. It
returns `true` only if all of them succeeded. The log says when the list is
missing a class, see below.

The plugin calls `PluginUtils::warmup_bridge()` right after `initialize_vr_body`
returns a valid VR body, in both branches of `handle_level_change` in
`plugin.cpp`. That is a moment where a hitch does not matter, and most of the
mod's Blueprint classes are loaded by then. The call is timed and logged:

```
[plugin_utils][warmup_bridge] Complete in <milliseconds> ms
```

or

```
[plugin_utils][warmup_bridge] Incomplete in <milliseconds> ms, <count> not loaded, see [bridge] lines above
```

`Incomplete` means at least one class was not loaded or one name failed to
resolve. The `[bridge]` lines above it in the log say which. All of these
messages use the warn level, because UEVR does not write plugin info messages
to `log.txt`.

## Caches are dropped at every level change

Every cache holds raw pointers into the Unreal object array. When the engine
unloads a Blueprint class and loads it again, the new class object can sit at
another address and, after a pak hot reload, have another layout. The cached
class pointer, property offsets and function pointers are then wrong.

`bridge::invalidate()` in `Bridge.hpp` handles this. It increments a generation
counter; every `ObjectRef`, `Prop` and `Func` remembers the generation it
resolved under and resolves again on its next use when the counter has moved.
`handle_level_change` in `plugin.cpp` calls it right after the pointer cleanup,
when `m_level` has changed, before the VR body is created. The warm-up that
follows refills the caches, so the lookups land in level setup again. A pawn
state change without a level change does not invalidate.

This is what makes the pak hot reloader (`documentation/pak-hot-reload.md`)
work with the bridge: the reload needs a trip through the title screen, which
is a level change, so the next load resolves every name against the classes
from the new pak.

## What happens when a class is not loaded

`BridgeWarmup()` returns `false` and logs
`[bridge] warm-up skipped, not loaded: <class path>`. It also adds the path to
`bridge::warm_skipped_paths()`. Nothing is cached for that class, so its names
resolve on first use as before. `A_BP_VRAvatar_C` is an example: it is only
loaded in cyberspace, so the warm-up skips it on Citadel Station.

Right after UEVR is injected, some classes are often not in memory yet. Nothing
retries the lookup during gameplay. A lookup that misses scans the whole object
array and finds nothing, and that is exactly the hitch the warm-up exists to
avoid. Instead, the log records when a skipped class becomes usable, in one of
two ways:

- The class resolves on first use. `ObjectRef::get()` sees that the path is in
  `warm_skipped_paths()`, removes it, and logs
  `[bridge] loaded on first use, after warm-up skipped it: <class path>`. The
  scan that this costs happens anyway on first use.
- The next level change runs `warmup_bridge()` again. It compares the new
  skipped list with the previous one and logs each class it now finds:
  `[plugin_utils][warmup_bridge] Loaded now, warmed up: <class path>`.

Calling the warm-up again later is cheap for everything that is already
resolved. Call `bridge::warm_begin()` before it and `bridge::warm_end()` after
it, so `warm_skipped_paths()` only holds the result of that run and lookups
made by the warm-up are not logged as lazy ones.

## What happens when a class is not in the warm-up list

Every class lookup made outside a warm-up is logged:

```
[bridge] resolved on first use, not pre-warmed: <class path>
```

When this line shows up for a class during gameplay, add the class to
`BridgeWarmupUsed()` in `bridge_warmup_used.hpp`. One case is expected and
needs no change: `A_BP_VRBody_C` is resolved when the VR body is spawned, which
happens before the first warm-up, so this line appears for it once per
injection.

## What the warm-up does not cover

- **Interface functions.** The static functions in `I_BI_VRWeapon_C`,
  `I_BI_InteractionSource_C`, `I_BI_PickableAnim_C` and `I_BP_VRMeleeWeapon_C`
  resolve against the class of the target object. That class is only known at
  call time, so these functions resolve on first call. Their interface classes
  are still found by the warm-up.
- **Dumper-7 game classes.** `StaticClass()` on a class from `SystemShockVR/SDK/`
  scans the object array on its first use, the same way a bridge class does.
  The warm-up does not touch those.
- **Calls on a subclass.** A bridge function caches its lookup per target class.
  Calling a wrapper on an object of a Blueprint subclass resolves once more for
  that subclass, so the override is used.

## Where the code lives

| What | File |
|---|---|
| `bridge::warm()`, `bridge::warm_begin()`, `bridge::warm_end()`, `bridge::warm_skipped()`, `bridge::warm_skipped_paths()`, `bridge::warm_resolved_late()` | `SystemShockVR/BridgeSDK/Bridge.hpp` |
| `BridgeWarmup()` per class | `SystemShockVR/BridgeSDK/_*_classes.hpp` |
| `BridgeWarmup()` per struct | `SystemShockVR/BridgeSDK/_STRUCT_*_structs.hpp` |
| `SDK::BridgeWarmupAll()` | `SystemShockVR/BridgeSDK/BridgeSDK.hpp` |
| `SDK::BridgeWarmupUsed()` | `SystemShockVR/bridge_warmup_used.hpp` |
| `PluginUtils::warmup_bridge()` | `SystemShockVR/plugin_utils.cpp` |
| Call sites | `SystemShockVR/plugin.cpp`, `handle_level_change` |

The BridgeSDK headers are generated. Do not edit them by hand. The generator and
the copy of `Bridge.hpp` it ships are in `tools/UEVRBridgeGen/`, and its
`README.md` explains how to run it.
