# SystemReShock UEVR Plugin v2.0

> [!WARNING]
> The profile doesn't work with the demo version from Steam and full game from GOG (GOG support will be added after the mod gets stable)

> [!WARNING]
> Mod installation requires extra step - copying PAK files from profile's `\paks` folder into the game's `Steam\steamapps\common\System Shock Remake\SystemShock\Content\Paks` folder.
  
Omg, this was a lot of work to get to this point. Enjoy!  
You can leave me a tip here: https://ko-fi.com/gwizdek

## Features
* 6DOF FBIK. Full roomscale VR.
* Physical interactions
* HL:A style item selector
* Automatic Aim Pose - aim the weapon, your walking speed will decrease but accuracy incease.
* Many more... (I will list them later)

## Installation
1) Install latest UEVR Nightly [**HERE**](https://github.com/praydog/UEVR-nightly/releases).
2) Remove your current System Shock profile folder if exists `C:\Users\{username}\AppData\Roaming\UnrealVRMod\SystemReShock-Win64-Shipping` 
3) Download the 2.0-beta.1 release of the SystemReShock UEVR plugin from Releases page.
4) Click "Import Config" in the UEVR Frontend App and select downloaded "SystemReShock-Win64-Shipping.zip". Accept the DLL warning.
5) Copy PAK files from `C:\Users\{username}\AppData\Roaming\UnrealVRMod\SystemReShock-Win64-Shipping\paks` folder into the game's `Steam\steamapps\common\System Shock Remake\SystemShock\Content\Paks` folder.
6) Add optional mod files (Index controllers support, Red Tint Remover) - described below
7) Launch System Shock and inject UEVR at MAIN MENU (this will allow the mod to set game options for VR play)
8) Reset controller bindings in game options to defaults

> [!WARNING]
> Save the game to new slots often (many things can go wrong)

## Gestures
* Press **Left Thumb** while holding left motion controller close to left ear - calibrate VR view
* Press **Left Grip** while holding left motion controller close to left ear - toggle flashlight
* Release **Left Grip** or **Right Grip** while holding pickable item over the shoulder to put it into the inventory (if there's enough space)
* Place your right motion controller over your inner left wrist and press **Right Grip** - toggle MFD
* Press **Right Grip** over your shoulder - holster weapon
* Press **Right Grip** over your shoulder, then move the hand forward - take out holstered weapon
* Press and hold **Left Grip** over the Access Card (located on your waist) to hold it. Swipe the card close to Yellow door scanners to unlock them (provided you picked up a correct Access Card earlier).
* Press and hold **Left Grip** over a lever, then move your hand to use lever
* Use pointing hand pose and touch consumable held in the other hand to use it
* Use pointing hand pose and touch one of Hardware Icons (attached to right forearm) to toggle selected hardware (it must be installed first)

## Controls
### General
* **A** - Jump
* **B** - Interact (when Laser Pointer's Dot is green) / Reload Weapon
* **X** - Crouch / Exit menus and interactions
* **Y** - Switch weapon mode
* **Right Trigger** - Fire weapon / Throw grenade / Enable laser pointer (empty hand)
* **Right Thumb (hold / release)** - Select hotbar item
* **Right Grip** - Pickup highlighted item / Pointing pose
* **Left Trigger** - Aim (useful for handling automatic weapons)
* **Left Grip** - Pickup highlighted item / Loot corpse / Pointing pose
* **Left Thumb (hold)** - Run
* **Left Thumb (press and hold 1s while holding left motion controller close to left ear)** - Enter VR Menu - adjust player height (the setting can't be stored yet). Press again to exit menu.
* **MENU - left hamburger button** - Open game menu
* **MENU - left hamburger button** (hold 1s) - Toggle MFD (this binding depends on VR runtime used and can differ). It can conflict with Virtual Desktop binding (rebind in VR). Use the MFD gesture instead.

### MFD
* **Right Trigger** - Select
* **Right Grip** - Open MFD contex menu
* **Left Grip** - Take all loot (when looting enemies/bodies/containers)
* **X** - Exit / Back
* **Left Trigger (hold)** - Show item description

### Cyberspace
* **A** - Ascend
* **X** - Descend
* **Y** - Recall
* **B** - Decoy
* **Right Grip** - Ascend
* **Left Grip** - Descend
* **Right Stick Up** - Ascend
* **Right Stick Down** - Descend
* **Right Trigger** - Pulser
* **Left Trigger** - I.C.E. Drill

## Limitations
* Mods that modify crosshair, hotbar slots, MFD and other game logic can have negative impact on the plugin and can cause it to break.

## Suggested Mods
* Remove red tint:  https://www.nexusmods.com/systemshock2023/mods/33
* Markmon's support mod for Index Knuckles

## Troubleshooting
* My view starts shaking and loosing sync between eyes - This happens to me after level change, player death, or going to Main Menu. Open UEVR overlay and toggle Native Stereo Fix off and on
* Laser pointer on the MFD doesn't work - Check if the game window is in focus.
* Misaligned cursor and laser pointer on MFD - Happens when resolution was changed, reinitialize runtime and reload a save game.
* My MFD is to wide - You can try to change the game resolution to match 16:9 aspect ratio, set `Window Mode` in game options to `Windowed Fullscreen`, then press Alt+Enter so it no longer takes the whole screen. Lastly, reload a save game.

## Known Bugs
* Final Shodan boss battle not working yet
* Wake-up from cryosleep animation not aligned (other animations like climbing ladders are buggy too)
* Right hand doesn't snap to levers correctly
* Red laser can point to the right in MFD when Mini Pistol was equipped
* You can steal from cabinets by physically grabbing items
* Proximity Mine can stick to you and blow up when trying to throw it (sorry)
* Using wire connectors in wire puzzle can be tricky/too sensitive (helper: use right hand)
* You can stand up and see through the level geometry when traversing low tunnels
* You can stick your gun through a door and shoot enemies on the other side
* Some of the two handed weapon poses are not aligned
* Missing parts or reload animations for Railgun(cooldown), Plasma Rifle (plasma core ammo)
* Sparq weapon - mode dial is not pointing at correct energy power setting (the lights work ok though)

### Widescreen monitors
* Misaligned cursor and laser pointer on MFD - Happens when resolution was changed, reinitialize runtime and reload a save game.
* My MFD is to wide - You can try to change the game resolution to match 16:9 aspect ratio, set `Window Mode` in game options to `Windowed Fullscreen`, then press Alt+Enter so it no longer takes the whole screen. Lastly, reload a save game.

## Credits
Many thanks to praydog, creator of UEVR, members of the modding community and content creators for covering this mod.
