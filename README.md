# SystemReShock UEVR Plugin v2.0

> [!WARNING]
> The profile doesn't work with the demo version from Steam and full game from GOG (GOG support will be added after the mod gets stable)

> [!WARNING]
> Mod installation requires extra step - copying PAK files from profile's `\paks` folder into the game's `Steam\steamapps\common\System Shock Remake\SystemShock\Content\Paks` folder.
  
Omg, it's been a lot of work to get to this point. Enjoy!  
Watch the tutorial video to see what this mod has to offer [**YouTube**](https://youtu.be/Gke3bmS2L-U?si=RVIDS3npQqPzgr2q)  
<img width="534" height="298" alt="image" src="https://github.com/user-attachments/assets/82a33495-01d4-45ee-a61c-de95002c0628" />  

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
9) Optional (recommended) - Tick `Autoplay Media Logs` in Gameplay Options

> [!NOTE]
> If you have an NVIDIA GPU, use DLSS Swapper to use newer, transformer model capable version. Set profile J or K (sharpest and not as heavy as L / M)

> [!WARNING]
> Save the game to new slots often (many things can go wrong)

## Gestures

| Gesture | How To |
|---------|-------------|
| Calibrate VR view | Press **Left Thumb** while holding the left motion controller close to your left ear |
| Use Item Selector | Assign a consumable item or weapon to a hotbar slot via the MFD. Press and hold **Right Thumb**, select an item, and release the button |
| Toggle flashlight | Press **Left Grip** while holding the left motion controller close to your left ear |
| Put an item into backpack | Release **Left Grip** or **Right Grip** while holding a pickable item over your shoulder (works if there's enough space in the inventory) |
| Toggle MFD | Place your right motion controller over your inner left wrist and press **Right Grip** |
| Holster weapon | Press **Right Grip** over your shoulder |
| Take out holstered weapon | Press **Right Grip** over your shoulder, then move your hand forward |
| Unlock doors | Press and hold **Left Grip** over the Access Card (located on your waist) to hold it. Swipe the card close to yellow door scanners to unlock them (provided you picked up the correct Access Card earlier). |
| Pull levers | Grip a lever with your left hand using the **Left Grip** button, then move your hand |
| Use consumable item | Equip a consumable item via the item selector, then use a pointing hand pose and touch the consumable with your finger |
| Toggle Hacker Hardware | Use a pointing hand pose and touch one of the Hardware Icons attached to your right forearm (hardware needs to be installed first) |
| Use Power Station | Hold your left hand close to the Power Station |

> [!NOTE]
> If you're having problems with interactions, you can use laser pointer and press game's interaction button (B by default).  
> Laser pointer is active when you're holding a ranged weapon or you can activate it with **Right Trigger** if your hand is empty

## Controls
### General
| Button | Description |
|--------|-------------|
| A | Jump |
| B | Interact (when the Laser Pointer's dot is green) / Reload weapon |
| X | Crouch / Exit menus and interactions |
| Y | Switch weapon mode |
| Right Trigger | Fire weapon / Throw grenade / Enable laser pointer (empty hand) |
| Right Thumb (hold / release) | Select hotbar item |
| Right Grip | Pick up highlighted item / Pointing pose |
| Left Trigger | Aim (useful for handling automatic weapons) |
| Left Grip | Pick up highlighted item / Loot corpse / Pointing pose |
| Left Thumb (hold) | Run |
| Left Thumb (press and hold 1s while holding the left motion controller close to your left ear) | Enter the VR Menu to adjust player height (the setting can't be stored yet). Press again to exit the menu. |
| MENU — left hamburger button | Open game menu |
| MENU — left hamburger button (hold 1s) | Toggle MFD (this binding depends on the VR runtime used and can differ). It can conflict with the Virtual Desktop binding (rebind in VR). Use the MFD gesture instead. |

### MFD
| Button | Description |
|--------|-------------|
| **Right Trigger** | Select |
| **Right Grip** | Open MFD context menu |
| **Left Grip** | Take all loot (when looting enemies/bodies/containers) |
| **X** | Exit / Back |
| **Left Trigger (hold)** | Show item description |

### Cyberspace
| Button | Description |
|--------|-------------|
| **A** | Ascend |
| **X** | Descend |
| **Y** | Recall |
| **B** | Decoy |
| **Right Grip** | Ascend |
| **Left Grip** | Descend |
| **Right Stick Up** | Ascend |
| **Right Stick Down** | Descend |
| **Right Trigger** | Pulser |
| **Left Trigger** | I.C.E. Drill |

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
* It's hard to open the X + shaped glass doors using hands - hold grip button and touch the corner outside of circular button area or point the laser at it and use interact button.  
<img width="308" height="298" alt="image" src="https://github.com/user-attachments/assets/9c9e2d65-d847-4f3f-b292-175cc5bbfed1" />


### Widescreen monitors
* Misaligned cursor and laser pointer on MFD - Happens when resolution was changed, reinitialize runtime and reload a save game.
* My MFD is to wide - You can try to change the game resolution to match 16:9 aspect ratio, set `Window Mode` in game options to `Windowed Fullscreen`, then press Alt+Enter so it no longer takes the whole screen. Lastly, reload a save game.

## Credits
Many thanks to praydog, creator of UEVR, members of the modding community and content creators for covering this mod.
