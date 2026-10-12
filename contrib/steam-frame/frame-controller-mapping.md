# Steam Frame controller mapping

How the Steam Frame's buttons reach System Shock through UEVR and this plugin, the
full list of things the game can do, and the mapping we want.

Tested with the joeyhodge UEVR build that has native Steam Frame support (October 2026
builds, `SteamFrameBindings.hpp` / `SteamFrameInput.hpp`), OpenXR mode.

---

## 1. How input flows

The plugin reads **XInput only**. It never reads OpenXR or SteamVR actions. So every
Steam Frame input has to become an Xbox button or axis before the plugin sees it.

Three layers sit between the hand and the game:

```
Frame physical input
  -> UEVR OpenXR Frame binding   (path -> UEVR action)
    -> UEVR action -> Xbox       (fixed in the UEVR build)
      -> plugin reads Xbox       (LB/RB/L3/R3/LT/RT: fixed in plugin.cpp)
         or the game reads Xbox  (A/B/X/Y, D-pad, Start, View: the game's own control map)
```

What each layer lets you change:

| Layer | Who owns it | How to change it |
|---|---|---|
| Frame path -> UEVR action | UEVR | Override JSON `_interaction_profiles_valve_frame_controller_valve.json` (adds bindings) |
| UEVR action -> Xbox | UEVR build | Not changeable without rebuilding UEVR |
| Xbox -> plugin action | `SystemShockVR/plugin.cpp` | Rebuild the plugin |
| Xbox -> game action | the game | Remap in the game's Controller settings |

Two consequences:

- The game's own keybindings only matter for the buttons the plugin forwards:
  **A, B, X, Y, D-pad, Start, View**. The plugin intercepts **LB, RB, L3, R3, LT, RT**
  in the states where it uses them, so an in-game remap does nothing for those.
- The plugin's older note that "B = Interact, X = Crouch" is wrong. The game's real
  defaults are **X = Interact, B = Crouch** (see section 3).

---

## 2. UEVR action set

These are all the actions UEVR can bind on the Frame (`Bindings.cpp`,
`SteamFrameInput.hpp`). This is the ceiling on what a Frame input can become.

| UEVR action | Type | Becomes |
|---|---|---|
| `pose`, `grippose` | pose | hand pose |
| `trigger` | bool | LT / RT |
| `triggeraxis` | float | LT / RT analog |
| `grip` | bool | LB / RB |
| `squeeze` | float | analog grip |
| `joystick` | vector2 | stick |
| `joystickclick` | bool | L3 / R3 |
| `abuttonright` | bool | **A** |
| `bbuttonright` | bool | **X** |
| `abuttonleft` | bool | **B** |
| `bbuttonleft` | bool | **Y** |
| `dpad_up/down/left/right` | bool | D-pad |
| `bumper` | bool | LB / RB (takes priority over `grip`) |
| `startbutton`, `backbutton` | bool | Start / View |
| `systembutton` | bool | Start / View |
| `teleport`, `touchpad`, `touchpadclick` | bool / v2 | unused by this mod |
| `haptic` | out | rumble |

Note: on the Frame, UEVR's shoulder (LB/RB) comes from `bumper` if it is bound,
otherwise from `grip` (squeeze). See section 6.

---

## 3. Full game control list

Taken from the game's own saved settings
(`%USERPROFILE%\Saved Games\Nightdive Studios\SystemShock\Saved\SaveGames\ShockSettings.sav`)
and the dumped SDK. UE face buttons: Bottom = **A**, Right = **B**, Left = **X**, Top = **Y**.

### Realspace (default gamepad)

| Game action | Default button |
|---|---|
| Jump | A |
| Crouch (toggle) | B |
| Interact | X |
| ModeNext (weapon fire mode) | Y |
| PrimaryAttack (fire) | RT |
| Aim | LT |
| UseConsumable | LB |
| UseExplosive | RB |
| Sprint (hold) | L3 |
| AcquireTarget | R3 |
| HotbarCycle next / previous | D-pad right / left |
| ToggleMFD | View (Back) |
| Pause / Escape | Start |

### Cyberspace (default gamepad)

| Game action | Default button |
|---|---|
| Ascend | A |
| Descend | B |
| PrimaryAttack | RT |
| SecondaryAttack | LT |
| RollLeft | LB |
| RollRight | RB |
| TurboDash | L3 |
| Recall | Y |
| Decoy | X |

Power and Shield have no gamepad button by default; they are keyboard-only.

### Every remappable action name the game exposes

- **Realspace:** `Real_` Jump, Crouch, Interact, Reload, ModeNext, PrimaryAttack, Aim,
  AcquireTarget, UseConsumable, UseExplosive, Sprint, Lean, LeanLeft, LeanRight,
  ToggleMFD, ToggleInventory, ToggleMap, Accept, QuickSave, QuickLoad, and
  Hardware{BioScan, Boots, Enviropack, Lantern, NavUnit, Sensaround, Shield, TargetID}.
- **Cyberspace:** `Cyber_` Ascend, Descend, MoveForward, MoveBackward, MoveLeft,
  MoveRight, RollLeft, RollRight, PrimaryAttack, SecondaryAttack, Decoy, Power, Recall,
  Shield, TurboDash.
- **Menu:** `MenuNav_` Up, Down, Left, Right, Accept, Back, Alt1, Alt2, Alt3, Alt4,
  Sort, Vaporize, TabLeft, TabRight.
- **Minigame:** Primary, Secondary.

---

## 4. Current Frame mapping (what the native UEVR binding does now)

| Frame physical | UEVR action | Xbox | Result |
|---|---|---|---|
| R A / B / X / Y | abuttonright / abuttonleft / bbuttonright / bbuttonleft | A / B / X / Y | Jump / Crouch / Interact / ModeNext |
| R trigger / L trigger | trigger | RT / LT | Fire / LT is muted (no ADS; used for the left-hand pointer) |
| R bumper / L bumper | bumper | RB / LB | plugin right-grab / left-grab |
| R stick click / L stick click | joystickclick | R3 / L3 | plugin hotbar / run+recenter |
| L D-pad | dpad_* | D-pad | game hotbar cycle |
| L View | backbutton | Back | game ToggleMFD |
| R Menu | startbutton | Start | game pause |
| squeeze / grip | grip | *ignored* | nothing (bumper wins) |

So the layout is already a normal Xbox layout. The two awkward parts are:

1. **Squeeze does nothing.** The grip is the natural "grab" on a VR controller, but the
   bumper is what grabs, because UEVR prefers `bumper` over `grip`.
2. **The right stick can't look up.** In Citadel, the plugin reads right-stick up and
   injects A (jump) (`plugin.cpp:783`). Pushing the stick up jumps instead of looking.

---

## 5. The mapping we want

| Frame physical | Target Xbox | Meaning | Change needed |
|---|---|---|---|
| R thumbstick | RS | turn; stick down = **crouch (hold)** | the stick is consumed, so the game does not look with it |
| R stick click | R3 | hotbar selector | none |
| R A | A | Jump / menu Accept | none |
| R B | freed | nothing (crouch moved to the stick) | none |
| R X | X | Interact | none |
| R Y | Y | ModeNext | none |
| R trigger | RT | Fire (+ right-hand pointer) | none |
| R bumper | D-pad down | **action (interact)** | the bumpers are routed to D-pad up/down |
| R squeeze | RB | **right-hand grab** | section 6 |
| R Menu | Start | Pause | none |
| L thumbstick | LS | move | none |
| L stick click | L3 | Sprint / recenter, VR menu | none |
| L D-pad left / right | D-pad | hotbar cycle | none |
| L trigger | (none) | **left-hand pointer** | LT is muted; no ADS (aiming is physical) |
| L bumper | D-pad up | **action (interact)** | |
| L squeeze | LB | **left-hand grab** | section 6 |
| L View | Back | Toggle MFD | none |

Crouch is on the right stick: hold it down to crouch, release to stand. It drives the
game's crouch toggle by pulsing B on each stick transition, so the physical B is free.
Aiming down sights is done with the physical body, so the game's Aim (LT) is muted and
LT is used for the left-hand pointer instead.

---

## 6. Moving grab from bumper to squeeze

File: `_interaction_profiles_valve_frame_controller_valve.json` in this folder.
Copy it to the per-game profile folder:

```
%APPDATA%\UnrealVRMod\SystemReShock-Win64-Shipping\_interaction_profiles_valve_frame_controller_valve.json
```

The file lists every Frame binding for the profile **except** the two bumper bindings.
UEVR submits its native Frame bindings first, then submits this override. Per the OpenXR
spec, a second `xrSuggestInteractionProfileBindings` call for the same profile replaces
the previous bindings for it. So this file's set becomes the profile's bindings, the
bumpers stop reporting, and the squeeze becomes LB/RB (grab).

This only happens when every path in the file is valid for the Frame profile. If any
path is not, the runtime returns `XR_ERROR_PATH_UNSUPPORTED`, UEVR keeps the native
defaults, and nothing changes. The file mirrors UEVR's own native Frame binding list
(minus the bumper entries), so it should pass.

Check the result in `%APPDATA%\UnrealVRMod\SystemReShock-Win64-Shipping\log.txt`:

- `[VR] Loaded customized Steam Frame bindings from ...` - the override replaced the
  native bindings.
- `[VR] Keeping native Steam Frame defaults; rejected ...` - a path was rejected; the
  native bindings are still active and the bumper still grabs.

---

## 7. Files

- `_interaction_profiles_valve_frame_controller_valve.json` - the override from section 6.
- `launch-vr.ps1` - starts SteamVR-gated launch and injects UEVR.
- `README.md` - folder index.
- `movement-analysis.md` - separate movement/body-detachment investigation.
