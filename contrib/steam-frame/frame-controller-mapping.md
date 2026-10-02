# Steam Frame ↔ SystemReShock bindings: complete mapping

Status: **proposed, for local testing**. Supersedes the summary in `README.md`.

Three layers have to line up:

```
Frame physical input
  → OpenXR interaction profile we author (action ↔ path)
    → UEVR action (fixed set of 25, see below)
      → Xbox/XInput button  ← the ONLY thing the mod's plugin actually reads
        → game action / motion gesture
```

Because gwizdek's plugin reads XInput exclusively (`memo_structs.hpp`), a
mapping is "correct" when the right **Xbox** button fires. Many mod actions are
also **motion gestures** (move hand to a body socket + press a button); those
ride along automatically as long as the underlying button identity is right, so
the real job is getting button identity correct.

---

## 1. Frame controller inputs (complete — Valve's OpenXR profile)

Per hand. Format: `path (click, touch, analog)`.

**Left** `/user/hand/left/input/…`
- `dpad_up`, `dpad_down`, `dpad_left`, `dpad_right` — click, touch
- `view` — click, touch
- `system` — click, touch
- `bumper` — click, touch
- `squeeze` — touch, click, value (this is the **grip**; not `grip/`)
- `trigger` — touch, click, value
- `thumbstick` — touch, click, vector2
- `aim/pose`, `grip/pose`, `output/haptic`

**Right** `/user/hand/right/input/…`
- `a`, `b`, `x`, `y` — click, touch
- `menu` — click, touch
- `system` — click, touch
- `bumper` — click, touch
- `squeeze` — touch, click, value
- `trigger` — touch, click, value
- `thumbstick` — touch, click, vector2
- `aim/pose`, `grip/pose`, `output/haptic`

Count of digital buttons: 11 left + 10 right, plus capacitive touch on almost
everything. That is far more than UEVR can currently address.

---

## 2. UEVR actions (complete — the ceiling on what's bindable)

From `UEVR/src/mods/vr/Bindings.cpp` + `OpenXR.hpp`. Short names are what our
override JSON uses.

| UEVR action | Type | Becomes (Xbox) |
|---|---|---|
| `pose`, `grippose` | pose | hand/head pose |
| `skeletonlefthand`, `skeletonrighthand` | skeleton | finger tracking |
| `trigger` | bool | LT / RT (per hand) |
| `grip` | bool | LB / RB (per hand) |
| `squeeze` | float | analog LB / RB |
| `joystick` | vector2 | L / R stick |
| `joystickclick` | bool | L3 / R3 (per hand) |
| `abuttonright` | bool | **A** |
| `bbuttonright` | bool | **X** |
| `abuttonleft` | bool | **B** |
| `bbuttonleft` | bool | **Y** |
| `abuttontouchleft` / `right`, `bbuttontouchleft` / `right` | bool | touch |
| `thumbresttouchleft` / `right` | bool | touch |
| `dpad_up`, `dpad_down`, `dpad_left`, `dpad_right` | bool | D-pad |
| `systembutton` | bool | Start (short) / Select (long) |
| `teleport` | bool | (unused by mod) |
| `touchpad`, `touchpadclick` | v2/bool | Index/Vive only |
| `haptic` | out | rumble |

**Key limit:** UEVR exposes only **four face buttons total** (two per hand), a
D-pad, one system button, triggers, grips, stick clicks, and two unused actions
(`teleport`, `touchpadclick`). No action exists for **bumpers, View, Menu, or a
second system button**.

---

## 3. Current mod bindings (complete inventory)

Everything gwizdek's `v2` plugin reads, from `plugin.cpp` + `plugin.hpp` +
`README.md` / `ProfileDescription.md`. Xbox-level, since that's what the plugin
sees.

### Buttons / sticks
| Xbox | Where read | Function |
|---|---|---|
| LT | `handle_ads` (via `IsAimingDownSights`), combos | Aim / ADS |
| RT | `plugin.cpp:818-863` | Fire; throw grenade; enable laser pointer (empty hand); charged Laser Rapier; muted for consumables |
| LB | `:925-971` | Left-hand grab / loot; access card; Energy Shield & VisionUnit gestures; in MFD sends `X` (close); cyberspace = `B` |
| RB | `:874-922`, `:751` | Right-hand grab / point; holster/draw at backpack; Sensaround & MFD gestures; cyberspace = `A` |
| A | `:760-762`, `:634` | Jump; cyberspace ascend |
| B | game | Interact / Reload; cyberspace descend |
| X | `:554-556` | Crouch / exit menus; muted while interactable |
| Y | game | Switch weapon mode |
| L3 | `:974-1006` | Run (hold); near-ear = recalibrate/recenter; near-ear long = VR height menu |
| R3 | `:1008-1018`, `:1485-1541`, `:641` | Hold = hotbar item selector; over left wrist = open game menu; cyberspace = Escape |
| Start/Select | system | Pause / back |
| LS | move | Movement |
| RS | `handle_smooth_turning` `:1025` | Turn; cyberspace steer; MFD = scroll (sent as mouse wheel) |
| D-pad | (UEVR Oculus emulation) | Game D-pad navigation |

### Motion gestures (hand-to-socket + button — button identity must be right)
| Gesture | Trigger |
|---|---|
| Holster / draw weapon | Right hand to shoulder/backpack + **RGrip** |
| Toggle Sensaround (minimap) | Right hand to `MinimapSocket` + **RGrip** |
| Toggle MFD | Right hand to `LeftInnerWristSocket` + **RGrip** |
| Open game menu | Right hand over left wrist + **R3** |
| Toggle Energy Shield | Left hand to `RightInnerWristSocket` + **LGrip** |
| Toggle VisionUnit (head-lamp) | Left hand to backpack + **LGrip** release (empty) |
| Holster consumable | Left hand to backpack + **LGrip** release (consumable) |
| Recalibrate / recenter | Left hand to ear + **L3** |
| VR height menu | Left hand to ear + **L3** long-press |
| Access card swipe | **LGrip** on waist card, swipe scanner |
| Use lever | **LGrip** on lever + move hand |
| Item selector | **R3** hold, point/RS to choose, release to equip |
| Consumable use | Touch equipped consumable with pointing hand |
| Hacker Hardware toggle | Pointing hand onto right-forearm hardware icons |
| Physical melee | Swing right hand (velocity); heavy = swing + **RT** |
| Cyberspace ascend/descend | **RS** up/down, or **RGrip**/**LGrip** |
| MFD pointer | **RT** = left click, **RGrip** = right click, **RS** = scroll |

---

## 4. Proposed Frame mapping (core — bindable today once UEVR supports Frame)

| Frame physical | UEVR action | Xbox | Result |
|---|---|---|---|
| Right **A** | `abuttonright` | A | Jump / cyberspace ascend |
| Right **B** | `bbuttonright` | X | Crouch / exit |
| Right **X** † | `abuttonleft` | B | Interact / Reload |
| Right **Y** † | `bbuttonleft` | Y | Weapon mode |
| Left **D-pad** ↑↓←→ | `dpad_up/down/left/right` | D-pad | menu / hotbar nav |
| **RT** (right trigger) | `trigger` (right) | RT | Fire / grenade / laser / rapier charge |
| **LT** (left trigger) | `trigger` (left) | LT | Aim / ADS |
| Right **Grip** | `grip`/`squeeze` (right) | RB | Right grab / holster / Sensaround / MFD |
| Left **Grip** | `grip`/`squeeze` (left) | LB | Left grab / loot / card / shield / lamp |
| Right **Stick click** | `joystickclick` (right) | R3 | Hotbar selector / game menu / cyberspace Esc |
| Left **Stick click** | `joystickclick` (left) | L3 | Run / recalibrate / VR height menu |
| Right **System** | `systembutton` | Start/Select | Pause / back |
| Left **System** | `systembutton` | Start/Select | Pause / back (duplicate) |

† cross-bound: the Frame has no left A/B, so the right hand's X/Y are bound to
UEVR's *left-hand* actions. This recreates a normal Xbox A/B/X/Y diamond under
the right thumb and is the single biggest improvement over the Touch fallback.

All gestures in §3 keep working unchanged, because they only depend on RB/LB/
R3/L3/RT and hand position.

## 5. Frame inputs that have **no** UEVR action

Left bumper, right bumper, left View, right Menu, and the second system button
cannot be addressed through UEVR's action set today. Options:

- **A. Upstream UEVR change** — add Frame inputs as actions (the real fix).
- **B. Reuse UEVR's unused actions** — `teleport` and `touchpadclick` exist in
  the action set; bind a spare Frame button to one of them, then have a small
  companion plugin read it with `is_action_active`. This exposes an extra button
  *without* changing UEVR. Sensible candidates: **right bumper → reload**,
  **left bumper → laser pointer**, **View → toggle MFD**, **Menu → pause**.
- **C. Leave unbound** for v1.

Recommendation: ship the core now, wire spares via option B once the core is
verified in-headset.

## 6. Corrections to the earlier draft

- Grip input path is `/input/squeeze` (click/value), not `/input/grip`.
- Trigger should bind `/input/trigger/click` for the boolean action.
- Right X/Y must be cross-bound to `abuttonleft`/`bbuttonleft` for Xbox B/Y.
- Include `dpad_*` and `systembutton` (they exist in UEVR's manifest).
- Bumpers / View / Menu are explicitly out of scope (no UEVR action).

## 7. Test plan

1. Confirm whether UEVR's current build actually registers the Frame profile:
   open the **UEVR overlay → VR/openxr tab** and read the **"Interaction Profile"**
   line while the game + Frame are running.
   - If it shows `/interaction_profiles/valve/frame_controller_valve`, UEVR
     supports Frame and this JSON override can be dropped into the UEVR profile
     folder and tested directly.
   - If it shows `/interaction_profiles/oculus/touch_controller`, UEVR is
     falling back and the profile will be **ignored** — we need route A (UEVR
     change) or route B (SteamVR binding UI) before it can be tested.
2. Drop `_interaction_profiles_valve_frame_controller_valve.json` into
   `%APPDATA%\UnrealVRMod\SystemReShock-Win64-Shipping\` (or the global
   `%APPDATA%\UnrealVRMod\UEVR\Profiles\`).
3. Reload the plugin from the UEVR overlay, then verify each row of §4 by
   pressing the corresponding Frame button and watching the in-game result.
