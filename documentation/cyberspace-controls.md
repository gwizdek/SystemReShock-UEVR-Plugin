# Cyberspace player controls

In cyberspace the player flies a different pawn, `PAWN_Avatar`, with six degrees of freedom.
This page explains how the game moves and turns that pawn, how the plugin makes the same
controls work in VR, and what is still open.

## How VR flight works

The game keeps full control of the flight. The plugin adds six things around it.

| Part | What it does | Where |
|---|---|---|
| Game controls | The VR controllers send the game's own gamepad bindings, unchanged: right stick turns and pitches, grips roll, A and B go up and down. The game's roll snap to 0°, 90°, 180° and 270° works as in the flat game. | `handle_xinput`, `apply_cyberspace_vr_settings` (`plugin.cpp`) |
| Pitch snap turn | An option. The right stick pitches in steps to the next world axis instead of smoothly. | `CyberspacePitchSnap` (`cyberspace_pitch_snap.cpp`) |
| Cockpit view | UEVR uses the avatar's full rotation, pitch and roll included, as the view, with the head rotation on top. Aim method "game", decoupled pitch off. | `apply_cyberspace_vr_settings` |
| Body turn | The head's yaw is moved into the avatar every tick, so the avatar's forward, and with it the stick direction and the UI, follow where the player faces. | `CyberspaceBodyTurn` (`cyberspace_body_turn.cpp`) |
| Head steering | The left stick flies along the head's pitch: looking up while moving forward moves the avatar up. | `CyberspaceHeadSteering` (`cyberspace_head_steering.cpp`) |
| Controller aim | The weapons shoot from a camera on the right controller. The plugin corrects the controller pose that UEVR gives, and shows a reticle on the aim line. | `VRAvatar` (`vr_avatar.cpp`) |

Order on entering cyberspace:

1. The possessed pawn becomes `PAWN_Avatar_C`. `handle_level_change` saves the player's
   roomscale sweep and turns it off (`RoomscaleSweepSetting`), then calls
   `VRAvatar::initialize_vr_avatar`: it spawns `_BP_VRAvatar`, adds the aim pivot and aim
   camera, points the avatar's `Camera` at the aim camera and hides the HUD crosshair.
2. The game state becomes `GAME_STATE_CYBERSPACE`. `apply_cyberspace_vr_settings` sets the
   UEVR options, enables UObjectHook and does a full VR center.

Order on every engine tick (`on_pre_engine_tick`, before the world tick):

1. `VRAvatar::update_aim`: moves the aim pivot to the controller pose, then places the
   reticle. See "The controller pose".
2. `CyberspaceBodyTurn::handle`, only in `GAME_STATE_CYBERSPACE`.
3. `CyberspaceHeadSteering::handle_tick`, only in `GAME_STATE_CYBERSPACE`.
4. `CyberspacePitchSnap::handle_tick`, only in `GAME_STATE_CYBERSPACE`.
5. `CyberspaceFlightReticle::handle`, only in `GAME_STATE_CYBERSPACE`. See "The flight
   reticle".

On leaving cyberspace, `cleanup_actors` calls `VRAvatar::restore_game_camera` and destroys
the VR avatar, and `RoomscaleSweepSetting::restore` sets the player's roomscale sweep back.

The sections below give the details: first the game's own logic, then each part of the
plugin.

## Pawns and the transition

Both pawns live in the persistent level `/Game/Maps/CitadelStation` at all times. The game
possesses one or the other when the player enters or leaves cyberspace.

| Pawn | Class | Role |
|---|---|---|
| Station pawn | `PAWN_Hacker_Implant_C` (`/Game/Blueprints/Characters/Hacker/PAWN_Hacker_Implant`) | The player on the station. A `Character` with `CollisionCylinder`, `CharMoveComp`, `CharacterMesh0` (anim BP `CH_Hacker_AnimBP_C`) and `COMP_AttribManager`. |
| Cyberspace pawn | `PAWN_Avatar_C` (`/Game/Blueprints/Characters/CyberCharacters/PAWN_Avatar`) | The player in cyberspace. Has `CyberspaceUI` (a `WIDGET_CyberspaceHUD_C`) and an arrow component `Arrow1`. |

While the player is in cyberspace, `PAWN_Hacker_Implant_C` stays in the level, parked far
below the map. One reading in cyberspace showed it at Z = -690000, with the avatar at about
(-10689, -4918, -3941).

The controller is `CON_Hacker` in both places. It tracks the transition in
`CyberspaceTransitionState`; see `cyberspace_atmosphere_fix.hpp` for the values.

## How the game moves the view in cyberspace

This section describes the game without the mod. It comes from the bytecode of
`PAWN_Avatar`, `CON_Hacker`, `FUNCLIB_CoreUtility` and `FUNCLIB_GameSettings`, exported with
the bytecode exporter, and from live tests with the avatar's `bUseControllerRotation*` flags
set back to `false`.

### The actor owns the rotation

`PAWN_Avatar_C` derives from `PAWN_SystemShockCharacter_C`, then the native
`ASystemShock_CharacterBase`, then `ACharacter`. Its class default has all three
`bUseControllerRotation*` flags set to `false`. The Blueprint turns the actor itself with
`K2_AddActorLocalRotation`; the control rotation is not used. No Blueprint in the chain writes
the control rotation, and with the flags off it does not follow the actor (a live test left it
at its old value while the actor turned). `CON_Hacker` has no rotation code for the avatar.
It only possesses the pawns during the cyber rift transition.

The camera is `Camera`, a `CameraComponent` attached to the root `CollisionCylinder` at
relative location 0. `bUsePawnControlRotation` is `false` and `bLockToHmd` is `true`. So the
view is the actor rotation plus a small tilt (see below), plus the HMD pose under UEVR.

### Per-tick order

`ReceiveTick` → `UpdateAvatar(dt)`. Unless the avatar is dying, that calls, in order:

1. `UpdateMovement(dt)`, which first calls `UpdateDashPower` and `UpdateRotation(dt)`, then
   moves the actor;
2. `UpdateSecurityTimer`, `UpdateCameraShake`, `UpdateCameraPOV` (field of view);
3. `UpdateCameraRotation(dt)` (camera tilt);
4. then it sets `KeyboardFramePitch`, `KeyboardFrameYaw`, `GamepadFramePitch`,
   `GamepadFrameYaw` and `FrameRelativeInput` back to 0 for the next frame.

### Look input (yaw and pitch)

The input handlers only add to per-frame values. Nothing turns until `UpdateRotation` runs.

- `HandleInputLookX/Y` (mouse): `KeyboardFrameYaw/Pitch += value × CyberspaceLookSensitivity / 50`.
  Y is inverted when `CyberspaceInvertY` is set. Gyro input is added to the pitch.
- `HandleGamepadInputLookX/Y`: the same into `GamepadFrameYaw/Pitch`, with gyro added to the
  yaw.
- All four do nothing while the in-game main menu is open.
- In `UpdateRotation`, `FUNCLIB_GameSettings.GetAcceleratedGamepadInputRotation` turns the
  gamepad values into degrees for this frame: the stick vector's length (clamped to 1) is
  eased (`Ease`, exponent 2.5) to a top rate of 270°/s (960°/s when the mouse cursor is
  shown), along the stick direction.
- The frame rotation is then `MakeRotator(Roll = FrameRoll, Pitch = gamepad + keyboard pitch,
  Yaw = gamepad + keyboard yaw)`, applied with `K2_AddActorLocalRotation`. It is a local
  rotation: yaw turns around the avatar's own up axis, not the world's. There is no pitch
  limit.

### Roll input

| Variable | Live value | Meaning |
|---|---|---|
| `RollRate` | 200 | degrees per second at full roll |
| `RollAcceleration` | 5 | how fast `RollScaleCurrent` follows the target, per second |
| `RollScaleTarget` | -1, 0 or 1 | sum of the held roll buttons |
| `RollScaleCurrent` | -1 to 1 | ramped roll amount |

- The roll buttons call `HandleRollRight` / `HandleRollLeft`. A press adds +1 or -1 to
  `RollScaleTarget`; a release adds the opposite. The value is clamped to -1..1.
- Each tick `RollScaleCurrent` moves toward the target by `RollAcceleration × dt`, so a full
  ramp takes 0.2 s.
- `FrameRoll = RollScaleCurrent × RollRate × dt`, applied as the roll part of the local frame
  rotation above.

### Auto-level: the roll snap to 0°, 90°, 180°, 270°

Auto-level is a step in `UpdateRotation`. It turns the avatar around its own forward axis
until its right vector lies on a world axis (±X, ±Y or ±Z). The view's roll then sits at a
multiple of 90° relative to the level's axes. Live tests: a 20° roll went back to 0°, a 25°
roll after a roll input went back to 0°, and a 70° roll went on to 90° (the right vector
ended at world -Z).

| Variable | Live value |
|---|---|
| `AutoLevel` | `true` (a class default; no user setting changes it) |
| `AutoLevelThreshold` | 0.22 |
| `MaxRollAdjustmentRate` | 20 (degrees per second) |
| `DEBUG_DrawAutoLevelArrow` | `false`; when `true` it draws a red arrow toward the target axis |

It runs only when `AutoLevel` is `true` and `FrameRoll` is 0 for this frame. So it waits
until roll input has stopped and the ramp has reached 0. Each tick:

1. `upAligned`: the largest absolute component of the actor's up vector, plus 0.22, is at
   least 1. That means the up vector is within about 39° of a world axis. `fwdAligned` is the
   same test for the forward vector.
2. The threshold is 1 when `upAligned`, `fwdAligned` or a domain link is active, and 0.22
   otherwise.
3. `FUNCLIB_CoreUtility.GetBestAxisDirection(rightVector, threshold)` takes the largest
   absolute component of the right vector. If that component plus the threshold is at least
   1, it returns that world axis with the component's sign. Otherwise it returns the right
   vector unchanged, which gives an angle of 0 and no correction. With threshold 1 it always
   returns an axis.
4. `AdjustmentAngle = CoreGameFunctionLibrary.SignedAngleBetweenOnPlane(targetAxis,
   rightVector, forwardVector)`, the signed angle between the two around the forward axis.
5. `step = sign(angle) × min(|angle × dt × 2|, MaxRollAdjustmentRate × k × dt)`, with k = 4
   while a domain link is active and 1 otherwise. So the roll approaches the target at twice
   the remaining angle per second, at most 20°/s (80°/s on a domain link).
6. `K2_AddActorLocalRotation(Roll = step)`.

In short: once the player looks roughly along or across a world axis, the roll is always
pulled to the nearest 90° step. In a diagonal pose where neither the up nor the forward vector
is near an axis, it only corrects when the right vector itself is already within about 39°
of an axis.

### Domain links

While `CurrentDomainLink` is valid, `UpdateRotation` also eases the actor rotation toward the
link direction (`REase` with `dt` as the alpha, exponent 2), and `UpdateMovement` moves the
actor along the link with `K2_SetActorLocation`. `UpdateCameraPOV` eases the field of view to
`FOV_DomainLink` (120).

### Movement

The move inputs build `FrameRelativeInput` in the avatar's local frame: X forward, Y right,
Z up. `Gamepad_Cyber_MoveAxisX/Y` is the left stick. Ascend, descend and the keyboard move
keys go through `HandleInputMoveAction`, which adds their direction, for ascend and descend
(0, 0, ±1), to `PersistentRelativeInput` while the key is held. `UpdateMovement` adds
`PersistentRelativeInput` to the frame input every frame. `UpdateMovement` normalizes the input, turns it by the actor rotation into a world
direction and calls `AddMovementInput`. `CharacterMovement` flies at `MaxFlySpeed` 800 with
acceleration 2048 (`CachedDefaultMaxFlySpeed`, `CachedDefaultAcceleration`). Turbo dash and
domain links change these values.

### Camera tilt

`UpdateCameraRotation` sets the camera's relative rotation each tick, as a cosmetic tilt:
roll up to `CameraRoll_Strafe_Max` (5°) from sideways input, and pitch up to
`CameraPitch_Move_Max` (4°) from up/down input. It is smoothed with
`CameraSmoothHistory` (`WeightedAverageVec2`). The actor rotation does not change.

### Flight reticle (the gyroscope)

The HUD's `WIDGET_FlightReticle` is the ring in the middle of the screen. Its
`RotateUpward`, which the HUD calls every tick from `UpdateGryoscope`, turns
`MESH_FlightReticle` to minus the pawn's roll, smoothed: `CurrentAngle = Lerp(CurrentAngle,
-Roll, 0.45)`. The plugin replaces this; see "The flight reticle".

### Field of view

`UpdateCameraPOV` eases from `FOV_WarpIn` (170) to the user's cyberspace FOV during the
first second after the avatar spawns. It goes to `FOV_DomainLink` (120) on a domain link, and
widens by up to 10° (at most 120) while turbo dash is active. The plugin's
`VRGameOptions::apply_display` sets the user's cyberspace FOV.

## The flight reticle

The game's flight reticle shows minus the avatar's roll (see "Flight reticle (the gyroscope)").
That is wrong at 90° pitch up or down, where the pitch snap can leave the avatar: a rotator's
yaw and roll are not defined there, and Unreal can split the same rotation into any pair of
them. A live test read roll -82.9° and, a moment later for the same rotation, -97.1°.

In VR the ring shows only its top triangle, the "up" marker: the Core pak replaces the
reticle's texture (see `hud-materials-in-vr.md`, "The cyberspace flight reticle").

`CyberspaceFlightReticle` (`cyberspace_flight_reticle.cpp`) does three things:

- It patches the bytecode of `RotateUpward`: the first instruction becomes a jump to the
  final `Return Nothing`, so the function does nothing. The function is only called from
  other Blueprint code, which UEVR's UFunction hook does not see. The patch is checked again
  every 600 ticks, in case the class was loaded anew.
- Every tick in `GAME_STATE_CYBERSPACE` it sets the ring's angle to the direction of world up
  in the camera's frame: `atan2(up.Y, up.Z)`, with `up` = world up turned back by the camera
  manager's rotation. Screen right is the camera's Y axis and screen up its Z axis. With
  `UI_FollowView=false` UEVR keeps the HUD quad turned with the game camera, so this is the
  direction of world up on the HUD. When world up is within about 1° of straight behind or in
  front of the screen, it has no direction there and the ring keeps its last angle.
- In the same tick it sets the render opacity of `WIDGET_FlightReticle` (0.5 in the HUD asset)
  and of `MESH_FlightReticle` (0.8) to 1, when they differ. Dimmed like that, the triangle was
  hard to see in VR. No game code sets these opacities.

## How the plugin detects cyberspace

`plugin.cpp` sets the pawn state to `PAWN_AVATAR` when the possessed pawn is a
`PAWN_Avatar_C`. The game state is then:

- `GAME_STATE_PAUSE_MENU` when the main menu widget of `CyberspaceUI` is enabled
  (`CyberspaceUI.WIDGET_MainMenu_InGame.IsMainMenuEnabled`). The HUD's own
  `GetMainMenuWidget` returns null in cyberspace, so the plugin reads the widget variable;
- `GAME_STATE_CYBERSPACE` otherwise.

In `GAME_STATE_PAUSE_MENU` the plugin uses the same settings as in the station's pause menu:
the menu stick deadzone (`apply_menu_stick_deadzone`), decoupled pitch on, the menu UI
distance and size, and a recenter. Body turn, head steering and pitch snap do not run.

The pawn state change runs `handle_level_change`, which calls
`VRAvatar::initialize_vr_avatar` (see below). The game state change that follows runs
`apply_cyberspace_vr_settings`.

## Controls in VR

The VR player has the same controls as a gamepad player. The plugin passes the game's own
cyberspace bindings through and does not remap them. The game turns the avatar itself, so
pitch, yaw, roll and the roll snap work as described above.

| VR controller input | Game action |
|---|---|
| Left stick | Move and strafe. The plugin takes the stick from the game and flies along the head's pitch (see Flying where the head looks). |
| Right stick | `Gamepad_LookYaw`, `Gamepad_LookPitch`. With pitch snap turn on, the plugin takes the stick's Y away from the game (see Pitch snap turn). |
| Left grip / right grip | `Gamepad_Cyber_RollLeft` / `RollRight` (UEVR sends the grips as the shoulders) |
| A / B | `Gamepad_Cyber_Ascend` / `Descend` |
| Right trigger / left trigger | `Gamepad_Cyber_PrimaryAttack` / `SecondaryAttack` |
| Left stick click | `Gamepad_Cyber_TurboDash` |
| X / Y | `Gamepad_Cyber_Decoy` / `Recall` |
| Right stick click | The plugin calls `InpActEvt_Locked_Escape` on the avatar, which opens the pause menu. UEVR keeps the menu buttons of the controllers, so the game's `Gamepad_Escape` (Start) cannot be pressed. |

`handle_cyberspace_look_pivot` hides `Arrow1` on the avatar each tick. The rest of that
function would set the control rotation from the right controller's aim pose, but it returns
before that code. It is left from an earlier controller-steered flight mode and does nothing.
Removing it is a fair change to propose.

## Pitch snap turn

The VR options page has a Cyberspace group with four settings, stored in `[cyberspace]` of
`system_reshock_vr_config.ini` and read through `VRSettings`. The first three are about pitch
snap turn; Crosshair Scale is described under "Aim reticle".

| Setting | ini key | Meaning |
|---|---|---|
| Pitch Snap Turn | `pitch_snap_turn` | On: the right stick pitches in steps that end on a world axis. Off (default): the game's smooth pitch. |
| Pitch Deadzone | `pitch_deadzone` | How far, 0 to 1, the stick must be pushed up or down to start a step. Default 0.8. |
| Pitch Snap Duration | `pitch_snap_duration` | How long one snap takes, in seconds, 0 to 1. 0 is instant. Default 0.5. |
| Crosshair Scale | `crosshair_scale` | Size of the aim reticle in percent, 50 to 150 in steps of 10. Default 100. |

`CyberspacePitchSnap` (`cyberspace_pitch_snap.cpp`) has two parts:

- `handle_input` runs in the XInput callback in `GAME_STATE_CYBERSPACE`. While the option is
  on, it sets `sThumbRY` to 0 in the state the game reads, so the game's own pitch input is 0.
  The yaw stays with the game. When the stick's Y passes the deadzone (at least 0.05), it
  queues a snap and waits until the stick is back under 80% of that value before it accepts
  the next push.
- `handle_tick` runs every engine tick in `GAME_STATE_CYBERSPACE`. It starts a queued snap and
  turns the avatar with `K2_AddActorLocalRotation` by this tick's part of the snap, around the
  avatar's own right axis, as the game's own look input does.

A snap ends with the avatar's forward vector on a world axis (±X, ±Y or ±Z). A pitch turns
the forward vector in the plane of the avatar's forward and up vectors, so only an axis in or
near that plane can be reached. The game's auto-level keeps the right vector on a world axis,
so that plane normally holds four world axes, 90° apart. To pick the axis, `start_snap`:

1. takes the pitch from the forward vector to each of the six axes, positive up, from the
   axis' parts along the forward and up vectors. An axis whose part in the plane is shorter
   than 0.5 is skipped: it lies close to the right axis;
2. takes the nearest axis in the push direction that is at least 30° away. So a snap is never
   only a few degrees: 12° below an axis, a push up goes on to the next axis, 102° away.

A push during a snap counts from the snap's axis instead of the forward vector, so it goes on
to the next axis, and starts the ease again. A push the other way turns back.

The snap eases out (cubic): it starts at three times the average speed and slows to 0 at the
end. The pitch still to turn is measured again each tick, because body turn and the game
can move the avatar during a snap. Each tick turns the same share of it as the ease curve
does, and the last tick turns all of it, so the snap ends on the axis. The measured pitch is
taken in whole turns closest to the last value, so a snap of 180° or more after several pushes
keeps its direction. The snap stops when its axis leaves the pitch plane, for example when the
avatar yaws by 90° during it.

Without Invert Y a push up pitches the nose up; this direction was chosen in the headset.
When the game's Invert Y for cyberspace (`CyberspaceInvertY` in `SAVE_Settings`) is on, the
direction is turned around. `game_pitch_direction` reads that setting at each push.

The snap does not block anything else. The game's yaw, roll, auto-level and movement run in
the same ticks. The game moves the avatar along its forward vector, so a forward flight
follows the new pitch while it turns. Auto-level only turns the avatar around its forward
axis toward a world axis for the right vector, and a pitch snap leaves the right vector
where it is.

A snap keeps running when the option is turned off, and stops when the possessed pawn
changes. While the pause menu is open the game state is not `GAME_STATE_CYBERSPACE`, so the
snap waits.

## UEVR settings in cyberspace

`apply_cyberspace_vr_settings` runs when `GAME_STATE_CYBERSPACE` is entered, also when the
player comes back from the pause menu:

- sets `bUseControllerRotationPitch`, `bUseControllerRotationYaw` and
  `bUseControllerRotationRoll` on the avatar to `false`, the game's default. With them on,
  `APawn::FaceRotation` would copy the control rotation to the actor every frame and undo the
  game's own rotation;
- sets UEVR aim method 0 (game), decoupled pitch off and snap turn off. UEVR turns decoupled
  pitch back on with any other aim method;
- sets roomscale movement on, `VR_DecoupledPitchUIAdjust` off, `UI_Distance` 4,
  `UI_Size` 2, camera offsets 0;
- sets `VR_ControllerPitchOffset` to 0. The station uses -25 (set in the
  `GAME_STATE_CITADEL_STATION` case); in cyberspace the aim must follow the controller as it
  is;
- enables UObjectHook when the VR avatar exists, and disables it otherwise;
- does a full VR center (`PluginUtils::full_vr_center`), the three UEVR overlay buttons in
  order: Set Standing Height, Set Standing Origin (the head's current position), Recenter
  View.

Roomscale movement works with the rolled and pitched avatar. UEVR moves the pawn by the
head's horizontal offset from the standing origin, turned by the full view rotation
(`head_offset_flat` in `FFakeStereoRenderingHook.cpp`), then moves the standing origin to the
head. So a real step moves the avatar along its own floor plane, as the view shows it. The
head's height is not moved.

### Roomscale sweep is off in cyberspace

UEVR's roomscale sweep (`VR_RoomscaleMovementSweep`) makes it move the pawn with a sweep for
a real step, so the pawn collides. In cyberspace that cannot be used: stepping into a wall
made the avatar's health drop fast. With the sweep off, a real step can pass through a wall.
Moving with the sticks still collides, because that is the game's own movement
(`AddMovementInput` on `CharacterMovement`).

`RoomscaleSweepSetting` (`roomscale_sweep_setting.cpp`) handles this. `handle_level_change`
calls it on every pawn change, after the cleanup:

- When the new pawn is the avatar, `disable_for_cyberspace` saves the player's current value
  and sets the sweep to `false`. It saves only when no value is saved yet, so it never saves
  its own `false`.
- For any other pawn, `restore` sets the saved value back and deletes it.

The saved value is a file in the UEVR profile folder, `cyberspace_saved_sweep.txt`, not a
variable. A variable would be lost when the hot loader swaps the plugin, or when the game
closes in cyberspace. The next plugin copy would then read the cyberspace value, `false`, as
the player's. With the file, a value left by a crash or an exit in cyberspace is restored on
the next pawn that is not the avatar, usually the station after loading.

The profile that ships with the mod (`profile\config.txt`) has the sweep off, so for most
players the saved and restored value is `false`.

With aim method "game" and decoupled pitch off, UEVR uses the game's full view rotation,
including pitch and roll, and multiplies the HMD rotation onto it
(`FFakeStereoRenderingHook.cpp`: `new_rotation = view × hmd`). The player sits in the
avatar like in a cockpit. When the avatar rolls, the view rolls with it.

`GAME_STATE_PAUSE_MENU` enables UObjectHook and decoupled pitch, for the station and for
cyberspace alike.

The field of view is set by `VRGameOptions::apply_display` for both the station and
cyberspace (`SetFOV(kFieldOfView, false)` is the cyberspace value). It does not change the
HMD view.

## Turning with the body

The game moves the avatar along its own forward vector. With aim method "game", UEVR shows
the head turn in the view but never turns the avatar. Without a fix, after the player turns
around, the left stick moves the avatar in the old direction, and the UEVR UI stays where it
was.

`CyberspaceBodyTurn::handle` (`cyberspace_body_turn.cpp`) runs every engine tick while the
game state is `GAME_STATE_CYBERSPACE`, after `VRAvatar::update_aim`:

1. Reads the HMD rotation and UEVR's rotation offset, and takes the forward vector of
   offset × HMD, the head direction in view space.
2. Its yaw, in Unreal terms (positive to the right), is `atan2(forward.x, -forward.z)` in
   UEVR's tracking axes (-Z forward, +Y up).
3. Turns the avatar by that yaw around its own up axis (`K2_AddActorLocalRotation`).
4. Turns the rotation offset by the same yaw the other way, around the tracking space's up
   axis, and sets it with `set_rotation_offset`.

UEVR renders the view as game view × rotation offset × HMD rotation, so the view does not
change. The avatar's forward follows the head's yaw: the head is always looking along the
avatar's forward, turned only by pitch and roll. UEVR places its UI by the rotation offset, so
the UI follows the head's yaw as well.

It does nothing when the head looks almost straight up or down (the forward vector's up part
is above 0.95), because the yaw is not defined there, or when the yaw is below 0.05°. The
new offset is worked out from the same HMD pose that was read. `recenter_view` would read the
pose again, and the difference between the two reads would be lost every tick.

Turning only the head also turns the avatar. The HMD cannot tell a head turn from a body turn.

Only the yaw is moved into the avatar. Every tick's turn is then around the tracking space's
up axis, so the rotation offset stays a pure yaw and the view's roll is always the head's real
roll. Moving the head's pitch into the avatar the same way does not work. A head that turns
to the side while it looks up also turns a little around its line of sight. Left in the
offset, those small turns add up to a rolled view over a few minutes. Taken out of the view,
they roll the world while the player looks around.

## Flying where the head looks

The flight direction follows the head's pitch as well, without turning the avatar: looking up
while moving forward moves the avatar up.

The game's left stick handlers (`HandleInputMoveAxisX/Y`) only add the stick to
`FrameRelativeInput`, X forward and Y right. `UpdateMovement` adds `PersistentRelativeInput`
to it (normally set by the keyboard move keys), normalizes the sum, turns it by the avatar's
rotation and calls `AddMovementInput`. Only the direction counts; any stick push flies at
full speed.

`CyberspaceHeadSteering` (`cyberspace_head_steering.cpp`) has two parts:

- `handle_input` runs in the XInput callback in `GAME_STATE_CYBERSPACE`. It keeps the left
  stick, with XInput's left stick deadzone (radial, 7849 of 32767), and sets the stick to 0 in
  the state the game reads.
- `handle_tick` runs every engine tick in `GAME_STATE_CYBERSPACE`, after body turn. It takes
  the head's pitch against the avatar from the forward vector of offset × HMD and writes
  `PersistentRelativeInput = (forward × cos(pitch), right, forward × sin(pitch) + up)`. The
  stick's forward part goes along the head's pitch, and its right part stays level with the
  avatar. A stick reading older than 0.25 s counts as no push, so the avatar stops when the
  XInput callback stops.

Ascend and descend (A and B) set `PersistentRelativeInput` too, so the plugin's write every
tick would remove them. `handle_input` therefore also keeps A and B as `up`: +1 for A, -1 for
B. The buttons still reach the game, so its own held-key count stays right. The game
scales the move by `MoveStrafeScale` the further the direction is from the avatar's forward,
so flying steeply up or down along the head is slower than flying straight ahead, as
strafing is.

## Aiming with the right controller

The game spawns cyberspace projectiles at the avatar's `Camera` component.
`ITEM_CyberWeapon_Base.SpawnProjectile` places each one at
`Camera location + Camera forward × SpawnDistance + LocalOffset`, with the camera's world
rotation. The pulser alternates `LocalOffset` between (40, 40, -40) and (40, -40, -40), turned
by the camera rotation, so its two streams run parallel to the camera's forward vector. The
ice drill's lock-on cone (`IsActorInLockOnRange`) uses the same camera.

`Camera` is a Blueprint variable. The view does not come from it: `AActor::CalcCamera` takes
the first active `CameraComponent` owned by the pawn. So the plugin points `Camera` at a
second camera that follows the right controller, and the view stays where it is. A live test
confirmed that the avatar Blueprint then writes to the new camera.

`VRAvatar::initialize_vr_avatar` (`vr_avatar.cpp`) does this:

1. Spawns `/Game/Mods/VRAvatar/_BP_VRAvatar._BP_VRAvatar_C`, tags it `VRAvatarActor`,
   attaches its root to the avatar's root (`CollisionCylinder`) and sets its `Pawn`.
2. Adds a `SceneComponent` (the aim pivot) to the VR avatar's `DefaultSceneRoot`, and a
   `CameraComponent` attached to the pivot at relative 0. The camera is deactivated and
   `bLockToHmd` is `false`. The plugin moves the pivot, not the camera: the avatar Blueprint
   writes the relative rotation (`UpdateCameraRotation`) and relative location
   (`UpdateCameraShake`) of `Camera` every tick. A camera placed directly would snap back to
   its parent during the avatar tick. The autofire shots come from a timer that runs after the
   avatar tick, so they would fly along the avatar's forward vector.
3. Remembers the avatar's own camera (`GetComponentByClass(CameraComponent)` on the pawn),
   then sets the avatar's `Camera` to the aim camera.
4. Sets `CameraRoll_Strafe_Max` and `CameraPitch_Move_Max` on the avatar to 0. The avatar
   Blueprint writes a tilt from those to the relative rotation of `Camera` every tick
   (`UpdateCameraRotation`). On the aim camera that tilt would bend the shots away from the
   controller.

`VRAvatar::restore_game_camera` sets `Camera` back to the avatar's own camera. It runs at the
start of `initialize_vr_avatar` and in `cleanup_actors`, before the VR avatar is destroyed.

### The controller pose

UObjectHook moves `MotionControllerRight` to the right controller each frame, but only while
UObjectHook is enabled. That pose is wrong in cyberspace. `UObjectHook::tick_attachments`
places the hands with the view's yaw only (`view_quat_inverse_flat`), but the stereo hook
renders the head with the full view rotation, pitch and roll included. On the station the view
is level and the two agree. In cyberspace the controller is off by the avatar's pitch and
roll.

Turning that pose back by the view's yaw does not work when the view looks straight up or
down. A rotator's yaw and roll are not defined there, and the yaw of the camera's rotator
differs from the yaw UEVR flattened with. A live test after a pitch snap to exactly -90°
measured the aim 97° away from the controller, so the reticle was out of view.

So `VRAvatar::controller_pose_from_tracking` builds the pose the way UEVR builds the head's,
and does not read `MotionControllerRight` at all. With P and R the game camera's location
and rotation, O the rotation offset, S the standing origin and T the change from tracking
axes (-Z forward, +Y up, +X right) to Unreal axes:

- location = P + R(T(O × (grip position - S))) × world to meters × `VR_WorldScale`
- forward and up = R(T(O × aim rotation × (0, 0, -1))) and R(T(O × aim rotation × (0, 1, 0)))

The grip position and the aim rotation are the ones UObjectHook uses. World to meters comes
from the stereo view offset callback (`VRAvatar::set_world_to_meters`). `update_aim` sets the
aim pivot to that location, with `MakeRotFromXZ(forward, up)`. The pivot hangs on the VR
avatar's root, so during the tick it moves and turns with the avatar, like the view.

The pose depends only on R × O. Body turn changes the avatar and the offset by opposite
amounts and leaves R × O as it is, so the order of `update_aim` and body turn does not matter.

The grip position and aim rotation are smoothed first, the same way UObjectHook smooths the
hands it places ("attach lerp"). The same UEVR settings control it: `UObjectHook_AttachLerpEnabled`
and `UObjectHook_AttachLerpSpeed` (15 in the profile). The aim uses 1.3 times that speed
(`kAimLerpSpeedFactor`), so it is smoothed a little less than the hands. With speed s and frame time t, the
rotation moves `min(1, s × t × |cos|)` of the way to the new rotation (a slerp, where cos is
the dot product of the two quaternions), and the position `min(1, s × t × max(1, distance in
meters))` of the way. Without it, the reticle shakes with the tracking noise.

Other avatar Blueprint code now works on the aim camera instead of the view camera:

| Function | Effect |
|---|---|
| `UpdateCameraShake` | Shakes the relative location of the aim camera; the view does not shake. |
| `UpdateCameraPOV` | Sets the field of view of the aim camera; it has no effect. |
| `AddOrUpdateBlendable` (in the ubergraph) | The intro post process goes to the aim camera and is not seen. |
| `GetDamageDirectionIndex` | The damage direction arrows are worked out from the controller, not the head. |
| `UpdateRotation` debug arrow | Drawn from the controller. |

## Aim reticle

The HUD draws its crosshair (`PANEL_Crosshairs` in `WIDGET_CyberspaceHUD`, the material
`MAT_CrosshairCursor` at 80 × 80) at the screen centre. That is where the head looks, not
where the controller aims. `initialize_vr_avatar` hides it by setting the panel's render
opacity to 0, and `restore_game_camera` sets it back to 1. `ShowCrosshairs(false)` is not
used, because it also changes the input mode and shows the mouse cursor. The HUD sets the
panel's visibility itself in `OnCrosshairVisibilityChanged`.

The bands across the top and the bottom of the HUD (`MESH_Dashboard` in `PANEL_DashboardTop`,
and `MESH_DashboardBottom`) are hidden the same way, by `set_hud_dashboards_visible`. The scan
text in the top panel (`TEXT_ScanDescription`) stays visible.

Two decorations are hidden by `set_hud_decorations_visible`: the two large arcs at the sides of
the HUD (`WIDGET_CyberspaceOccularRing`, meshes `OccularRing_L` and `OccularRing_L_1`) and the
readout at the bottom left (`WIDGET_CyberspaceGreeble`: position, rotation, data rate and
VIRT). It sets the widgets' visibility to Hidden, and back to Visible in `restore_game_camera`.
Render opacity does not work here: set on a user widget, it does not reach the mesh widgets
inside it. No game code changes the visibility of these two widgets.

`_BP_VRAvatar` has a `WidgetComponent` named `AimReticle`, with the material
`Widget3DPassThrough_Translucent_NoDepth`. That material is translucent with depth test
disabled, so walls and enemies do not hide the reticle. A masked material cannot disable the
depth test. In the Blueprint it is a child of `MotionControllerRight`. `initialize_vr_avatar`
moves it to `DefaultSceneRoot`, keeping its world transform, because UEVR moves
`MotionControllerRight` with the uncorrected pose late in the frame, and sets the draw size
to 80 × 80.

`update_aim` places it after the aim camera, from the controller pose (`place_reticle`):

1. Traces the Visibility channel (`TraceTypeQuery1`) along the aim line, at most 2500 units
   (25 m) from the controller. The avatar and the VR avatar are ignored.
2. Puts `AimReticle` at that distance on the aim line, facing back along it, with the
   controller's up vector as its up.
3. Scales it to a world size of `N × (distance / 50) ^ 0.75` units, divided by the draw size
   80. N is the Crosshair Scale setting divided by 10: 10 at the default 100 %, 5 at 50 % and
   15 at 150 %. At 100 % the reticle covers about 11° of view at 50 cm, 6.4° at 5 m and 4.3° at
   25 m. With a
   constant angle, a far reticle looks much bigger than a near one, because it is seen as
   far away.

The component's **Blend Mode** must be Transparent for the reticle to be see-through. With
Masked, the default, the widget's alpha is only used as a cut-out and the render proxy is
drawn as masked, even with a translucent material. UE 4.27 has no Blueprint function to change
the blend mode, so it belongs in `_BP_VRAvatar`. A live test showed the reticle see-through
after writing `BlendMode` = 2 and calling `SetTwoSided(true)`, which rebuilds the render
proxy. `_BP_VRAvatar` still has Masked; see Open questions.

The widget class of `AimReticle` is `/Game/Mods/VRAvatar/_WIDGET_AimReticle`. It holds one
image, `IMAGE_Reticle`, 80 × 80 at the centre, with a placeholder brush. The game's
crosshair material is not in the Unreal project. On the first tick that finds the widget,
`VRAvatar::apply_reticle_brush` sets the image's brush resource to the one of the HUD's
`IMAGE_CrosshairCursor`, which is `MAT_CrosshairCursor`. The widget component creates its
widget on `BeginPlay`, so this waits until the widget exists.

## How UObjectHook attaches the camera

`profile\uobjecthook\camera_state.json` attaches the UEVR camera to this path, with no offset:

```
Acknowledged Pawn
  Components → CapsuleComponent CollisionCylinder
  Properties → AttachChildren → SceneComponent DefaultSceneRoot
  Properties → AttachChildren → SceneComponent UEVRCameraAttachComponent
```

`DefaultSceneRoot` and `UEVRCameraAttachComponent` are not part of the game's pawns. They
belong to the VR body `_BP_VRBody` on the station and to `_BP_VRAvatar` in cyberspace. Both
are attached to the root component of the pawn, which is `CollisionCylinder` on both pawns.
That makes `DefaultSceneRoot` a child of the capsule, so the same path resolves on both pawns.

UEVR (`UObjectHook.cpp` in the UEVR source) handles the path like this:

- `Acknowledged Pawn` is `GetPlayerController(0)->AcknowledgedPawn`, the pawn possessed now.
- A component step matches `<class name> <object name>`, for example
  `SceneComponent DefaultSceneRoot`.
- `update_persistent_states` resolves the path on every engine tick while UObjectHook is
  enabled. **When the path does not resolve, UEVR keeps the object it attached to last.** The
  attachment is cleared only when that object's destructor runs, which is when it is garbage
  collected. Destroying the actor does not clear it.
- The camera attachment sets only the view location, not its rotation.

The other files in that folder do not move the camera. The `*_mc_state.json` files attach
pawn components to the HMD (`hand: 2`). The `*_props.json` files set properties or hide
components. Most of their paths name components that only the station pawn has, for example
`HeadRangedCollision`, `LookPivot` and `ArmsMesh`. On the avatar those do not resolve and are
skipped.

Without the VR avatar, the path does not resolve in cyberspace. UEVR then keeps the VR body
component from the station, which sits on `PAWN_Hacker_Implant_C` below the map, and the view
goes there. That is why `apply_cyberspace_vr_settings` enables UObjectHook only when the VR
avatar exists.

## Open questions

- `AimReticle` in `_BP_VRAvatar` still has Blend Mode Masked and is one-sided, so the reticle
  is not see-through. Set Blend Mode to Transparent and Two Sided on, then cook.
- `handle_cyberspace_look_pivot` holds dead code (see Controls in VR).
- How the roll of the HMD itself should combine with the game's auto-level. Auto-level reads
  the axes of the actor, not of the view.
- Whether the native `AShockPlayerController` does anything with the avatar's rotation. It has
  0x58 bytes of state with no reflected fields. The live tests found nothing.