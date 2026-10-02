# Steam Frame controller bindings — findings and options

Status: research/analysis. Local only. Target: gwizdek/SystemReShock-UEVR-Plugin `v2`.

## Answer to "where are the JSON files?"

There aren't any to copy. UEVR **embeds** its default binding profiles in the
backend (they are string literals in `src/mods/vr/Bindings.cpp`). On disk, UEVR
only looks for optional **override** files, named after the interaction profile
with slashes turned into underscores:

- per-game: `%APPDATA%\UnrealVRMod\<GameProfile>\` (here
  `SystemReShock-Win64-Shipping\`)
- globally: `%APPDATA%\UnrealVRMod\UEVR\Profiles\`

Neither folder contains any `_interaction_profiles_*.json` on a fresh install —
verified on this machine. Projects like `mark-mon/uevr-index-controls` are where
those override files come from; they are not shipped by UEVR.

## Root cause (verified — and it's not fixable with a profile JSON)

UEVR only reads/suggests bindings for a **hard-coded controller list**
(`UEVR/src/mods/vr/runtimes/OpenXR.hpp`, `s_supported_controllers`):

```
/interaction_profiles/khr/simple_controller
/interaction_profiles/oculus/touch_controller
/interaction_profiles/oculus/go_controller
/interaction_profiles/valve/index_controller
/interaction_profiles/microsoft/motion_controller
/interaction_profiles/htc/vive_controller
```

The Steam Frame profile is **not in that list**, and UEVR does not request
Valve's `XR_VALVE_frame_controller_interaction` extension. Consequences:

1. A `frame_controller` override JSON is **never loaded** — UEVR's loop only
   iterates `s_supported_controllers`.
2. Per Valve's docs, with no Frame profile suggested the runtime **emulates
   Oculus Touch** and remaps it to the Frame layout, lossily:
   - Touch **menu → View**
   - Touch **B/Y → all three top Frame buttons** (Dpad L/Up/R ↔ X/Y/B)

So the mismap is upstream of both gwizdek's plugin and any UEVR profile file.
It cannot be fixed from inside this repository, and my earlier draft profile
JSON would have been ignored.

## Options

### A. Fix it in UEVR (correct, benefits everyone)
Add Frame support to UEVR:
- request `XR_VALVE_frame_controller_interaction`
- add `/interaction_profiles/valve/frame_controller_valve` to
  `s_supported_controllers` (path changed from `.../frame_controller` to
  `.../frame_controller_valve` in SteamVR 2.15.1+)
- ship default bindings for it

Then the per-game/global `_interaction_profiles_valve_frame_controller_valve.json`
override (the schema we designed) becomes usable. This should be filed upstream
to `praydog/UEVR`; note UEVR is source-available but "all rights reserved", so
this is an upstream request, not something we merge here.

### B. Use the OpenVR/SteamVR runtime instead of OpenXR (workaround)
In the UEVR launcher, choose **OpenVR (SteamVR)** rather than OpenXR. UEVR then
registers its SteamVR action manifest, and SteamVR's **Controller Binding UI**
lets you create a `frame_controller` binding mapping the Frame's inputs to
UEVR's actions. No UEVR change needed, and the binding can be shared as a
SteamVR community binding. Needs testing.

### C. What does NOT work
- Editing SteamVR bindings while on the OpenXR runtime: the app never suggested
  a Frame profile, so there is nothing Frame-specific to bind.
- A Frame `_interaction_profiles_*.json` override: ignored (see root cause).

## The mapping we'd want (still valid as the target layout)

If/when UEVR supports Frame (route A), or for the SteamVR binding (route B),
this is the proposed player layout. UEVR exposes four face actions
(`abuttonright`→Xbox A, `bbuttonright`→Xbox X, `abuttonleft`→Xbox B,
`bbuttonleft`→Xbox Y), triggers, grips, stick clicks, a D-pad and one system
button.

| Frame physical | UEVR action | Xbox | Plugin action |
|---|---|---|---|
| Right A | `abuttonright` | A | Jump |
| Right B | `bbuttonright` | X | Crouch / exit |
| Right X | `abuttonleft` (cross-bound) | B | Interact / reload |
| Right Y | `bbuttonleft` (cross-bound) | Y | Weapon mode |
| Left D-pad | `dpad_up/down/left/right` | D-pad | menu / hotbar nav |
| RT / LT | `trigger` | RT / LT | Fire / Aim |
| RGrip / LGrip | `grip` / `squeeze` | RB / LB | Grab / loot·card·lever |
| R3 / L3 | `joystickclick` | R3 / L3 | Hotbar / run·VR menu |
| View / Menu | `systembutton` | Start/Select | Pause / back |

Exact action short names (UEVR lowercases the manifest names): `abuttonleft`,
`bbuttonleft`, `abuttonright`, `bbuttonright`, `trigger`, `grip`, `squeeze`,
`joystick`, `joystickclick`, `dpad_up`, `dpad_right`, `dpad_down`, `dpad_left`,
`systembutton`, `pose`, `grippose`, `haptic`.

Frame OpenXR input paths (from Valve's docs) are
`/user/hand/right/input/{a,b,x,y}/click`, `/user/hand/left/input/dpad_{up,down,left,right}/click`,
`/user/hand/left/input/view/click`, `/user/hand/right/input/menu/click`,
`/user/hand/{left,right}/input/{trigger,grip,bumper,thumbstick,thumbstick/click,system}`.

## Recommendation

1. File the UEVR upstream request (route A) with the exact code change — it
   unblocks Frame for every UEVR game, not just System Shock.
2. Meanwhile test route B (OpenVR runtime + SteamVR binding) so the user can
   actually play.
3. Keep `_interaction_profiles_valve_frame_controller_valve.json` as the
   ready-to-use schema for once route A lands (or adapt it to SteamVR's binding
   export format for route B).

## Files

- `_interaction_profiles_valve_frame_controller_valve.json` — the intended
  override schema. **Inert until UEVR is updated (route A).**
- `movement-analysis.md` — the separate movement/body-detachment investigation.
