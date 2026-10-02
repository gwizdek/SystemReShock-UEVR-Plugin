# Steam Frame: game-state fix + controller-binding findings

This documents two Steam Frame issues found while testing the mod on a Steam
Frame, and what can and cannot be fixed inside this repository.

- **Movement / head-body detachment — FIXED here.** `SystemShockVR/plugin.cpp`.
- **Steam Frame button bindings — NOT fixable here.** Root cause is in UEVR
  (praydog/UEVR); this document explains why and proposes the upstream change.

---

## 1. Movement: head and body detached, right stick turns the body but not the HMD

### Symptom

On the Steam Frame the player moved "like a mech": the in-game body and the HMD
were detached, and the right stick turned the body but not the view. The mod's
own per-state VR options (`VR_RoomscaleMovement`, `bUseControllerRotationYaw`,
decoupled pitch, `recenter_view()`) were never applied.

### Root cause

All movement-critical UEVR options are applied in `handle_game_state_change()`
when the game state changes (e.g. into `GAME_STATE_CITADEL_STATION`). That
function only acts when `m_game_state.has_changed()` is true.

`prepare_game_state()` is called from **every** `on_xinput_get_state()` callback
and mutates `m_game_state` through `MemoProperty::set_value()`, which does
`prev = value; value = new`. A second call with the same value therefore
**clears the "changed" flag**.

On the Steam Frame the game polls **two** XInput slots (we log index 1 in
addition to index 0 — almost certainly Steam Input's gamepad emulation of the
Frame controllers). Each extra callback called `prepare_game_state()` again and
wiped the state transition before `handle_game_state_change()` (which runs from
`on_pre_engine_tick`) ever saw it. Result: the state options were never applied.

### Fix

In `SystemShockVR/plugin.cpp`:

1. **Only process the VR XInput slot.** `on_xinput_get_state()` now returns
   early unless `user_index == vr->get_lowest_xinput_index()`, and logs the
   first ignored index. This keeps extra devices/polls from reaching the state
   machine.
2. **Apply the state change immediately.** `handle_game_state_change()` is now
   also called right after `handle_level_change()` in both callbacks, so it runs
   while the change is fresh regardless of callback ordering.
3. **Consume the state** (`m_game_state.consume()`) at the end of
   `handle_game_state_change()` so the options are applied once per transition.

Net effect: the log now shows the transitions that were previously missing:

```
[plugin][handle_game_state_change] New Game State: Main Menu
[plugin][handle_game_state_change] New Game State: Citadel Station
[plugin][handle_game_state_change] New Game State: Pause Menu
[plugin][on_xinput_get_state] Ignoring non-VR XInput index 1 (VR index 0)
```

and movement/turning behave normally on the Steam Frame.

### Notes

- The index filter is correct for any multi-slot setup, not just the Frame; the
  extra-index log line confirms the cause.
- The fix is small and local to the plugin; no change to paks or the profile.

---

## 2. Steam Frame button bindings

### Symptom

Buttons are mismapped on the Steam Frame: e.g. **D-pad down** triggers the
"back/interact" action, and the right face buttons do not map to A/B/X/Y.

### Root cause (in UEVR + SteamVR, not this plugin)

The plugin reads **XInput**; UEVR synthesises that XInput from the VR runtime.
UEVR ships default binding profiles for Oculus Touch / Index / Vive / etc., but
**not for the Steam Frame**, and it does not request Valve's
`XR_VALVE_frame_controller_interaction` extension. When no Frame binding exists,
SteamVR **emulates Oculus Touch and remaps it onto the Frame**, and that remap is
lossy by Valve's own rules
(`SteamVR/drivers/frame_controller/resources/input/frame_controller_remapping.json`):

```
Oculus Touch left x  -> Frame dpad_down
Oculus Touch left y  -> Frame dpad_left / dpad_right / dpad_up
Oculus Touch right b -> Frame b / x / y
Oculus Touch trigger -> Frame trigger + bumper
```

So the Frame's four face buttons and four D-pad directions are collapsed to a
handful of Touch inputs **before the plugin ever sees anything**. The plugin then
applies its normal Touch handling, which is why D-pad down behaves as a face
button. The plugin cannot recover the lost distinctions.

### Why it can't be fixed in this repository

- UEVR only reads/suggests bindings for a hard-coded controller list
  (`src/mods/vr/runtimes/OpenXR.hpp`, `s_supported_controllers`) that does not
  include the Frame, and it never requests the Frame extension. An override file
  named for the Frame profile is therefore never loaded.
- SteamVR regenerates its per-app `auto-remapping_*.json` on every launch from
  the app's suggested binding, so hand-editing those files does not persist.
- SteamVR's Controller Binding UI only lists apps that register a SteamVR action
  manifest. In **OpenXR** mode (what the mod uses) the injected non-VR game does
  not appear, so a custom Frame binding cannot be created there.

### Proposed fix (upstream, in UEVR)

1. Request `XR_VALVE_frame_controller_interaction`.
2. Add `/interaction_profiles/valve/frame_controller_valve` to
   `s_supported_controllers` in `src/mods/vr/runtimes/OpenXR.hpp`
   (note: the path changed from `/interaction_profiles/valve/frame_controller`
   to `.../frame_controller_valve` in SteamVR 2.15.1+).
3. Ship default Frame bindings (and/or read the override file below).

Once UEVR suggests the Frame profile, SteamVR uses it directly and the plugin
receives distinct A/B/X/Y and D-pad inputs. A ready override is included at
`contrib/steam-frame/_interaction_profiles_valve_frame_controller_valve.json`
(its intended mapping: right A/B/X/Y → the four face actions, left D-pad →
DPad_*, triggers → Trigger, grips → Grip, stick clicks → JoystickClick,
View/System → SystemButton). It is inert until step 2 lands.

> Note: UEVR's `UESDK` submodule is a private repository, so this could not be
> built and tested locally — it needs a change by someone with access.

### Workaround (no UEVR change)

Run UEVR in **OpenVR** mode instead of OpenXR. The app then registers a SteamVR
action manifest and appears in **Settings -> Controllers -> Manage Controller
Bindings**, where a **Custom** binding can map the Frame's physical inputs to the
mod's actions directly. The entry only exists while the game is running.

---

## Testing / reproduction

- Built `SystemShockVR.dll` (Release x64) and copied it to
  `%APPDATA%\UnrealVRMod\SystemReShock-Win64-Shipping\plugins\`.
- Launched the game through Steam with UEVR injected after a short delay
  (`contrib/steam-frame/launch-vr.ps1` reproduces the installer's launch without
  re-verifying/overwriting the plugin DLL).
- Confirmed from `log.txt`: `New Game State` lines now appear and the extra
  XInput index is logged; movement/turning fixed.

## Files in this change

- `SystemShockVR/plugin.cpp` — the fix.
- `documentation/steam-frame.md` — this document.
- `contrib/steam-frame/` — supporting analysis:
  - `frame-controller-mapping.md` — full current-binding inventory + proposed
    Frame mapping.
  - `_interaction_profiles_valve_frame_controller_valve.json` — proposed UEVR
    override (inert until UEVR supports the Frame).
  - `launch-vr.ps1` — launch + inject helper.
