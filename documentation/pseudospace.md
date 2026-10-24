# Pseudospace

Pseudospace is the final battle against SHODAN. The player is a Hacker again, on foot, not
the flying cyberspace avatar. The plugin detects it and gives it its own game state. Most of
the VR setup is the apartment intro's, because the pawn derives from the apartment pawn. This
page collects what is known and what is still to do.

The game facts come from the cooked Blueprints (exported with the bytecode exporter) and the
Dumper-7 SDK. The detection, the pause state, the hidden wrist widgets, the HUD layout, the
VR body's pawn and the pulser in the right hand were checked in the running game. The other
weapons, the platforms, the respawn and the pause menu were not.

## The pawn and its HUD

| What | Class | Notes |
|---|---|---|
| Pawn | `PAWN_Hacker_Pseudospace_C` (`/Game/Blueprints/Characters/Hacker/PAWN_Hacker_Pseudospace`) | Parent is `PAWN_Hacker_Simple_C`, the apartment intro pawn. The SDK has it: `SDK/PAWN_Hacker_Pseudospace_classes.hpp`. |
| HUD | `WIDGET_PseudospaceHUD_C` | Set by the pawn's `PlayerHUDClass` default. A direct child of `UUserWidget`, not of `WIDGET_SimpleHUD_C`. Has its own `WIDGET_MainMenu_InGame` (offset 0x280) and `GetMainMenuWidget`. |
| Game mode | `GM_Pseudospace` | `/Game/Blueprints/Interactables/Cyberspace/GM_Pseudospace` |

The pawn adds little to `PAWN_Hacker_Simple_C`:

- one component, `CyberspaceLocalEffects` (a Niagara effect, `AvatarLocalFX`), on
  `CollisionCylinder`;
- `IsRealspaceCharacter` returns `false`;
- `OnCharacterDied` plays a stinger and calls `EVENT_RespawnPseudoHacker` after 3 seconds;
- `TryLeaveCurrentLevel` calls `StartFadeOutSequence`, which ends the battle (see below).

Everything else, including walking, jumping, the `PlayerCamera` component, the inventory
and the weapons, comes from `PAWN_Hacker_Simple_C`. It is a first-person walking pawn like
the station pawn, so the station's VR approach is the starting point, not the cyberspace
one.

## Entering and leaving

The player enters through a cyberspace terminal. `CON_Hacker.TryOpenCyberRiftFromTerminal`
reads the terminal's level collection. When its data table is `DT_CyberspaceLevels`, the
next pawn is `CyberspacePawnClass` (`PAWN_Avatar_C`); otherwise it is
`PseudospacePawnClass` (`PAWN_Hacker_Pseudospace_C`). `FinishCyberRiftTransition` loads that
class and possesses a pawn of it, as for cyberspace.

`PAWN_Hacker_Pseudospace_C` is loaded only from then on. Before the last terminal, its class
is not in memory.

Death: `EVENT_RespawnPseudoHacker` looks for the `INTERACT_PseudoSurfboardPlatform` in the
current streaming level whose surf started last, and respawns the player on the platform
connected to it. What happens depends on the difficulty of type 3
(`GI_SinglePlayer.GetDifficultyByType(3)`): with value 0 the player always respawns there;
with 1, once per platform; with 2, never. When there is no platform, or no respawn is
allowed, it calls `GI_SinglePlayer.OpenPersistentMapByType(4)`, which loads the level again.

Leaving: `StartFadeOutSequence` gives the pawn 1000 armor, holds it in place for 5 seconds,
sets the music, and calls `CON_Hacker.TryOpenCyberRiftFromPseudospace` with the
`Outro_Bridge_Cinematic` sequence. That rift goes from the `ShodanArena` level collection to
`Outro` (both in `DT_StreamingLevels`).

## Assets that belong to it

- Interactables: `INTERACT_PseudoPlatformBase`, `INTERACT_PseudoSpawnPlatform`,
  `INTERACT_PseudoSurfboardPlatform`, `INTERACT_PseudoTurretPlatform`, `PseudoSurfboard`,
  `PseudoTurret` (`/Game/Blueprints/Interactables/CyberspaceArena/`).
- Weapons: `WEAPON_PseudoPulser`, `WEAPON_PseudoNova`, `WEAPON_PseudoDiscLauncher`, their
  pickups and projectiles.
- HUD parts: `WIDGET_PseudospaceHUD`, `WIDGET_PseudoHealth`.
- Level pieces: `BP_PseudoLoudspeaker`, `BP_PseudoWaveFloor`
  (`/Game/Cyberspace/FinalDomain/`), the sequences `LS_PseudoSpaceSurfEntrance` and
  `LS_PseudoSpace_EntranceSpawn`.
- Enums: `ENUM_PseudoShodanState`, `ENUM_PseudoTurretState`.

## What the plugin does in pseudospace

### Detection

`prepare_game_state` (`plugin.cpp`) tests the pawn in this order: Hacker Implant, player
ghost, cyberspace avatar, pseudospace, Hacker Simple. The pseudospace test must come before
the Hacker Simple test, because the pseudospace pawn is also a Hacker Simple.

The pawn is matched by the name of its class, with
`PluginUtils::is_class_named(pawn, "PAWN_Hacker_Pseudospace_C")`. Do not use
`is_a<APAWN_Hacker_Pseudospace_C>` or `StaticClass()` for it. The class is not loaded for
most of the game, and Dumper-7's `StaticClass()` searches the whole object array (about
200 ms) on every call until it finds the class. Once found, it keeps the pointer, which goes
stale when the class unloads.

A match sets `PAWN_PSEUDOSPACE`. The game state is `GAME_STATE_PAUSE_MENU` while the pause
menu is open, otherwise `GAME_STATE_PSEUDOSPACE`. The pause state comes from the HUD's own
`WIDGET_MainMenu_InGame` field (offset 0x280 in `UWIDGET_PseudospaceHUD_C`).
`UWIDGET_SimpleHUD_C::GetMainMenuWidget` must not be called on this HUD: Dumper-7 looks the
function up in the object's own class chain, finds nothing, and `ProcessEvent` with a null
function is an access violation. The apartment's laptop lookup does not run either. The
laptop class is not loaded in pseudospace, so a failed `find_uobject` would cost about
200 ms every tick.

### VR setup

- `handle_game_state_change` has a `GAME_STATE_PSEUDOSPACE` case with the apartment's VR
  settings.
- Controller input goes through the apartment branch of `handle_xinput`.
- `handle_level_change` runs its Hacker Simple branch: it spawns the VR body
  (`VRBody::initialize_vr_body`) and sets up the laser dot, the crouch animations, the hand
  item collisions and the player height.
- For every pawn that is not a Hacker Implant, `initialize_vr_body` hides the wrist widgets
  and the hardware panel (`VRBody::hide_neural_hud_widgets`). They show the neural HUD's
  widgets, which only the station pawn has. Without this, each would show a standalone
  minimap or media display. The game's own connection integrity
  (`WIDGET_PseudoHealth`) is the only HUD part left.
- `CyberspaceHudLayout::handle_pseudospace` moves connection integrity from the top right
  corner to the top centre, as in cyberspace. It runs every tick and applies the layout once
  per HUD, because the HUD can appear after the pawn.
- The same function hides the HUD's centre dot (`IMG_CursorDot`); the laser dot shows where
  the hand points. It checks the dot every tick, because the HUD's own `SetCursorVisibility`
  shows it again, for example after a menu.
- The periodic modules that only skip cyberspace (`FocusInteractionPatch`,
  `TutorialMessages`, `TutorialPopupDuration`, `TutorialHeadView`) run too.

### The VR body in pseudospace

The unpossessed station pawn stays in the level during pseudospace. `_BP_VRBody` must
therefore find its pawn with `GetPlayerPawn(0)`, in `BeginPlay` and in
`InitializeAnimations`. `GetActorOfClass(PAWN_Hacker_Simple_C)` returns the station pawn
there, and the VR body would then copy that pawn's animation and bind to its inventory.

For a pseudospace pawn, `BeginPlay`:

- calls `_BP_LaserDot.SetPseudospaceParams`, which sets the laser dot's power, size and
  distance for pseudospace. The plugin does not set the dot's `Power` or `Size`
  (`initialize_laser_dot`);
- binds `CustomEvent_WeaponChanged`, `CustomEvent_WeaponDrawn` and
  `CustomEvent_WeaponHolstered` to the pawn's `COMP_HackerInventory` and keeps that inventory
  in `BoundHackerInventory`. `EndPlay` unbinds the three events from it.

Weapons reach the hand through these events. A pickup pedestal (`BP_CYBER_PickupPedestal`)
calls `COMP_HackerInventory.GrantItem` from its overlap event. The weapon's `SetEquipped`
calls `SetCurrentEquippedWeapon`, which broadcasts `OnEquippedWeaponChanged`. When the
weapon is drawn, `OnWeaponDrawStarted` broadcasts `OnWeaponDrawn`, and the VR body's
`CustomEvent_WeaponDrawn` calls `ChangeEquippedWeapon`. That attaches the pawn's
`WeaponMesh` to the right hand. The pulser's anim Blueprint, `AnimBP_Cybergun`, implements
`_BI_VRWeapon`, which gives the socket and the offset.

`PICKUP_Base.OnPickedUp` cannot be used for this: in the whole game only
`INTERACT_ModkitStation` binds to it.

## The earlier plugin

`SystemShockVR/old_dllmain.cpp` is the plugin before the current `plugin.cpp`. It is not in
the project file and is not compiled. It handled pseudospace. It is useful as a record of
what was tried:

- it found the pawn by the start of its full name, `PAWN_Hacker_Pseudospace`;
- it set all three `bUseControllerRotation*` flags of the pawn to `false`;
- it set UEVR aim method 2 (right controller), snap turn on, decoupled pitch on, roomscale
  movement on and `VR_DecoupledPitchUIAdjust` on, and recentered the view;
- it opened the pause menu through the pawn's `InpActEvt_Locked_Escape_K2Node_InputActionEvent_118`.

None of it has been checked against the current plugin or the current game version.

## Work to do

1. Check the pause menu in pseudospace. Its game state case enables UObjectHook and
   decoupled pitch.
2. Check the Nova and the disc launcher in the hand, and the surfboards and turret
   platforms with the hand interaction. Check whether the apartment input (triggers attach
   the laser pointer when the hand is empty) gets in the way of firing.
3. Decide which periodic modules run there. `FocusInteractionPatch` matters only if a
   pseudospace interactable derives from `INTERACT_Focusable_Base` or is a keypad or
   puzzle. The tutorial modules matter only if pseudospace shows tutorial popups.
4. Check the respawn (`OnRespawnHacker`) and the reload by `OpenPersistentMapByType(4)`:
   both may need the VR body set up again.

A save just before the last terminal is the quickest way to test all of this.
