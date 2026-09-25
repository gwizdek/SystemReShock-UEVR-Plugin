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
every generated class and struct and returns `true` only if all of them
succeeded.

The plugin calls `PluginUtils::warmup_bridge()` right after `initialize_vr_body`
returns a valid VR body, in both branches of `handle_level_change` in
`plugin.cpp`. That is a moment where a hitch does not matter, and the mod's
Blueprint classes are loaded by then. The call is timed and logged:

```
[plugin_utils][warmup_bridge] Complete in <milliseconds> ms
```

`Incomplete` in that line means at least one class was skipped or one name
failed. The `[bridge]` lines above it in the log say which.

## What happens when a class is not loaded

`BridgeWarmup()` returns `false` and logs
`[bridge] warm-up skipped, not loaded: <class path>`. Nothing is cached for that
class, so its names resolve on first use as before. `A_BP_VRAvatar_C` is an
example: it is only loaded in cyberspace, so the warm-up skips it on Citadel
Station.

Calling `BridgeWarmupAll()` again later is cheap. Every entry that is already
resolved is skipped.

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
| `bridge::warm()`, `bridge::warm_skipped()` | `SystemShockVR/BridgeSDK/Bridge.hpp` |
| `BridgeWarmup()` per class | `SystemShockVR/BridgeSDK/_*_classes.hpp` |
| `BridgeWarmup()` per struct | `SystemShockVR/BridgeSDK/_STRUCT_*_structs.hpp` |
| `SDK::BridgeWarmupAll()` | `SystemShockVR/BridgeSDK/BridgeSDK.hpp` |
| `PluginUtils::warmup_bridge()` | `SystemShockVR/plugin_utils.cpp` |
| Call sites | `SystemShockVR/plugin.cpp`, `handle_level_change` |

The BridgeSDK headers are generated. Do not edit them by hand. The generator and
the copy of `Bridge.hpp` it ships are in `tools/UEVRBridgeGen/`, and its
`README.md` explains how to run it.
