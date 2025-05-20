# SystemReShock UEVR Plugin

> [!WARNING]
> The profile doesn't work with the Demo version of the game available on Steam
  
> [!NOTE]
> The profile is now also available through Unreal Easy Injector https://uevrdeluxe.org

> [!NOTE]
> Optional mod files available:
> * Markmon's Index Knuckles support
> * Ashok's character arms and physical melee gesture mods

### Welcome back to Citadel Station hackers...

This UEVR plugin is inspired by wonderful work of Ashok and the team (CJ117, TimBurton and Markmon), who created the original UEVR plugin ([**Link**](https://github.com/Ashok0/SystemShock-UEVR)) and it borrows some of the fixes and ideas, so many thanks to the guys.  

Of course, let's not forget, that it wouldn't be possible without Praydog, the author of UEVR!

## Features
* 6DOF
* working crosshair (guns, puzzles, vending machines)
* emulated crosshair depth
* minimalistic HUD
* minimap and health bars attached to right hand
* hotbar item selector - HL:A style
* hacker hardware toggler
* emulated MFD laser pointer 
* plugin options accessible through overlay
* refined controller mappings
* two aiming modes for cyberspace

## Installation
1) Install UEVR ver 1.05 from [**HERE**](https://github.com/praydog/UEVR/releases). (Works also with Nightly builds)
2) Remove your current System Shock profile folder if exists `C:\Users\{username}\AppData\Roaming\UnrealVRMod\SystemReShock-Win64-Shipping` 
3) Download the latest release of the SystemReShock UEVR plugin from Releases page. Click "Import Config" in the UEVR UI and navigate to "SystemReShock-Win64-Shipping.zip" and click on it and accept the DLL warning.
4) Add optional mod files (Index controllers support, Player Arms mod, Melee Gesture mod) - described below
5) Launch System Shock and inject the game with UEVR
6) Reset controller bindings in game options to defaults

## Controls
### General
* **A** - Interact / Reload
* **B** - Jump
* **X** - Crouch / Exit menus and interactions
* **Y** - Switch weapon mode
* **Right Trigger** - Fire weapon / Use item / Throw grenade
* **Right Grip (hold / release)** - Select hotbar item
* **Right Stick Button (hold / release)** - Toggle hacker hardware
* **Left Trigger** - Aim (useful for handling automatic weapons) / Use Target Identifier
* **Left Grip** - Toggle run / walk *(configurable in plugin options)*
* **Left Stick Button** - Hold to run (possibly will be remapped to something more useful)
* **MENU BUTTON** (hold 1s) - Toggle MFD  
* **MENU BUTTON** (short press) - Open game menu  

### MFD
* **A** - Select
* **B** - Take all loot / Sort inventory
* **X** - Exit / Back
* **Y** - Open MFD contex menu
* **Right Trigger (hold 1s)** - Vaporize junk
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
* **Right Stick Button** - Change aiming mode

The Cyberspace part of System Shock is tricky to get right in VR, especially on different HMDs. The plugin currently supports two control implementations. The first one is suited for Meta Quest HMDs (tested by Ashok), the second one works on WMR headsets like my G2. We are limited in our testing to these HMDs and can't garantee compatibility with other headsets.  
You can choose which implementation you want to use by accessing plugin options overlay and selecting `HMD`. Default value is `Meta Quest`. Both implementations support 2 aiming modes toggable via **Right Stick Button**.

## Plugin Options
Plugin options are accessible through a separate overlay window displayed when UEVR's overlay is visible.
It is preferred to use mouse to make the adjustments.  

Options are stored in your UEVR profile folder in `system_reshock_vr_config.ini` file. This file is created automatically first fime you inject the profile.  
To save options press `Save Configuration` button.

![mod_options](https://github.com/user-attachments/assets/72eda989-a461-42a8-acf2-2b152eb65606)  

### Look Sensitivity
Your character rotation speed

### Player height modifier
Some players reported that they feel the floor is much to close. You can adjust how tall you are here. You can also change UEVR world scale to something like 0.95 if you like.

### Force hide compass
This setting forces the top compass band to hide. If you really like the compass, you can untick it and toggle navigation software off/on through MFD to show it again.

### Toggle run with Left Grip
Option to disable walk/run toggle binded to Left Grip. You can still run by pressing and holding **Left Stick Button**

### HMD
Select control implementation for Cyberspace

### Crosshair Depth
If you feel the crosshair is to close or to far, you can adjust it here. It's specially useful when you change the world scale from default value of 1.0

### Crosshair Cursor Scale and Cursor Brackets Scale
The original game crosshair is way to big for my liking. I made it a lot smaller by default, but you can make it big again or hide it completely.
You can also make it bearly visible. You may need to adjust this setting depending on selected game video resolution. The brackets part of crosshair is hidden by default.  

### TargetID Reticle Scale
When you upgrade your Target Identifier software, an additional reticle will be shown marking target's weak spot. You can control the size of this reticle using this option.  

![target_reticle](https://github.com/user-attachments/assets/d10ff372-dccb-4e78-86c2-3a64d86d1571)  

Press `Apply Crosshair Options` button after you make the changes.

## Optional Mods by Ashok
There are two additional files prepared by Ashok (included in the v1.2.0 release). You can choose to add them if you want to further enhance your gameplay.   
### Player character's arms mod
This `pak` mod makes player arms disappear. To install it, download `SystemShock-VRFixes_p.pak` file and place it inside `\Steam\steamapps\common\System Shock Remake\SystemShock\Content\Paks` folder.  
![hands_mod_resized](https://github.com/user-attachments/assets/d72b8c90-38f2-4f52-bfe1-e1139c68053f)  

### Physical Melee mod
This is a `lua` script that brings back physical melee (swing gesture) from the original Ashok's mod. To install it, download `SSR_PhysicalMelee.lua` file and place it into `C:\Users\{username}\AppData\Roaming\UnrealVRMod\SystemReShock-Win64-Shipping\scripts` folder.  

## Limitations
* no physical crouching

## Compatibility
Mods that modify crosshair, hotbar slots, inventory and mfd can have negative impact on the plugin.

## Troubleshooting
### General
* I can't see the crosshair!  
  The crosshair scaling may look different depending on your monitor resolution. This can lead to a crosshair being too big or too small/invisible.
  To change the scale, use your normal mouse and monitor to access mod options menu, and change `Crosshair Cursor Scale` setting. Press `Apply Crosshair Options` button to see the changes and finally `Save Configuration` button to store them.
* (Quest 2/3) My character changes weapons/items on it's own - Do you rest your thumb on the thumbrest area (dpad shifting button) of the controller? You can disable this feature in the UEVR overlay.
* Laser pointer on the MFD doesn't work - Check if the game window is in focus.
* (Valve Index): [**this**](https://github.com/mark-mon/uevr-index-controls/releases) tool by markmon will allow use of Knuckles controllers  

### Widescreen monitors
* Misaligned cursor and laser pointer on MFD - Happens when resolution was changed, reinitialize runtime and reload a save game.
* My MFD is to wide - You can try to change the game resolution to match 16:9 aspect ratio, set `Window Mode` in game options to `Windowed Fullscreen`, then press Alt+Enter so it no longer takes the whole screen. Lastly, reload a save game.

## Known Bugs
* Intro laptop animation not behaving correctly
* Wake up from cryosleep animation not aligned
* Game button prompts are not correct
* The crosshair is not pointing exactly where I think it should when close to walls / objects - it's a side effect of emulating the crosshair instead of actually computing its correct position.

## Disclaimer
This plugin was developed on HP Reverb G2 using OpenXR API. Some testing was performed by me on G2 and by Ashok on Q2 / Q3 (Thank you!). It's a limited set of HMDs, so you may bump into bugs, depending on your setup!
