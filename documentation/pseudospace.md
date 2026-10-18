# Pseudospace

Pseudospace is the final battle against SHODAN. The player is a Hacker again, on foot, not
the flying cyberspace avatar. The plugin has no pseudospace support: it does not detect it,
and treats it as the apartment intro. This page collects what is known, for the work that
adds that support.

Nothing on this page has been tested in the headset. The game facts come from the cooked
Blueprints (exported with the bytecode exporter) and the Dumper-7 SDK. The plugin facts come
from reading the code.

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

## What the plugin does in pseudospace today

`prepare_game_state` (`plugin.cpp`) tests the pawn in this order: Hacker Implant, the
cyberspace avatar, then `is_a<APAWN_Hacker_Simple_C>`. The pseudospace pawn is a Hacker
Simple, so that test matches. The code after it, written for the apartment intro, then runs:

- the pawn state becomes `PAWN_HACKERSIMPLE`;
- `try_set_intro_laptop_pointer` looks for the apartment's laptop;
- the pause menu check casts `PlayerHUDWidget` to `UWIDGET_SimpleHUD_C` and calls its
  `GetMainMenuWidget`. The HUD is a `WIDGET_PseudospaceHUD_C`, which is not a Simple HUD.
  The Simple HUD's function reads `WIDGET_MainMenu_InGame` at offset 0x278, but in the
  pseudospace HUD that field is at 0x280. The result is a wrong pointer, and reading
  `IsMainMenuEnabled` through it may crash or report a wrong pause state;
- `ChannelingInteractable` selects `GAME_STATE_INTERACTABLE`, otherwise the state is
  `GAME_STATE_APPARTMENT`.

So the game state handler applies the apartment's VR settings, and `handle_level_change` runs
its Hacker Simple branch: it spawns the VR body (`VRBody::initialize_vr_body`) and sets up
the laser dot, the crouch animations, the hand item collisions and the player height. The
periodic modules that only skip cyberspace (`FocusInteractionPatch`, `TutorialMessages`,
`TutorialPopupDuration`, `TutorialHeadView`) run too.

`GAME_STATE_PSEUDOSPACE` and `PAWN_PSEUDOSPACE` exist in `vr_plugin_shared.hpp`, but
nothing sets them, and `handle_game_state_change` has no case for them. A TODO in
`prepare_game_state` says to detect the pawn by name, because its class is not loaded
before the last terminal and `StaticClass()` of a class that is not loaded searches the
whole object array. `PluginUtils::is_a<T>` now remembers the answer per object class, so
that cost is paid once per new pawn class, not every tick.

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

1. Detect the pawn before the Hacker Simple test in `prepare_game_state`, with
   `PluginUtils::is_a<APAWN_Hacker_Pseudospace_C>`, and set `PAWN_PSEUDOSPACE` and
   `GAME_STATE_PSEUDOSPACE`.
2. Read the pause state from `UWIDGET_PseudospaceHUD_C::GetMainMenuWidget` and set
   `GAME_STATE_PAUSE_MENU` there. Check what the pause menu case does in pseudospace; it
   enables UObjectHook and decoupled pitch.
3. Decide the VR setup: whether the station's VR body, hands, laser dot and weapon handling
   work on this pawn, or a reduced set is needed. Then add a `GAME_STATE_PSEUDOSPACE` case
   to `handle_game_state_change`, and a pseudospace branch to `handle_level_change`.
4. Check the pseudospace weapons with the VR weapon code, and the surfboards and turret
   platforms with the hand interaction.
5. Decide which periodic modules run there. `FocusInteractionPatch` matters only if a
   pseudospace interactable derives from `INTERACT_Focusable_Base` or is a keypad or
   puzzle. The tutorial modules matter only if pseudospace shows tutorial popups.
6. Check the respawn (`OnRespawnHacker`) and the reload by `OpenPersistentMapByType(4)`:
   both may need the VR body set up again.

A save just before the last terminal is the quickest way to test all of this.
