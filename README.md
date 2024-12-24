# SystemReShock UEVR Plugin

Welcome back to Citadel Station hackers...

This UEVR plugin is inspired by wonderful work of Ashok and the team (CJ117, TimBurton and Markmon), who created the original UEVR plugin ([**Link**](https://github.com/Ashok0/SystemShock-UEVR)) and it borrows some of the fixes and ideas, so many thanks to the guys.
Also, let's not forget, that it wouldn't be possible without Praydog, the author of UEVR!

Author's note: This release is a little bit rushed for the Christmas, so you may see some bugs.

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
1) Install UEVR ver 1.05 from [**HERE**](https://github.com/praydog/UEVR/releases).
2) Remove your current System Shock profile folder if exists `C:\Users\{username}\AppData\Roaming\UnrealVRMod\SystemReShock-Win64-Shipping` 
3) Download the latest release of the SystemReShock UEVR plugin from Releases page. Click "Import Config" in the UEVR UI and navigate to "SystemReShock-Win64-Shipping.zip" and click on it and accept the DLL warning.
4) Launch System Shock and inject the game with UEVR
5) Reset controller bindings in game options to defaults

## Controls
### General
* **A** - Interact / Reload
* **B** - Jump
* **X** - Crouch / Exit menus and interactions
* **Y** - Switch weapon mode
* **Right Trigger** - Fire weapon / Use item / Throw grenade
* **Right Grip (hold / release)** - Select hotbar item
* **Right Stick Button (hold / release)** - Toggle hacker hardware
* **Left Trigger** - aim (useful for handling automatic weapons)
* **Left Grip** - toggle run / walk
* **Left Stick Button** - hold to run (possibly will be remapped to something more useful)
* **MENU** - toggle MFD

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

## Plugin Options
The plugin options are accessible through a separate overlay window displayed when UEVR's overlay is visible.
It is preferred to use mouse to make the adjustments.

Important notice! Right now the options you select can't be persisted on hard drive. You have to select them each time you inject the mod.

### Fine-tune Crosshair Depth
If you feel the crosshair is to close or to far, you can adjust it here. It's specially useful when you change the world scale from default value of 1.0

### Look Sensitivity
Your character rotation speed

### Player height modifier
Some players reported that they feel the floor is much to close. You can adjust how tall you are here. You can also change UEVR world scale to something like 0.95 if you like.

### Force hide compass
This setting forces the top compass band to hide. If you really like the compass, you can untick it and toggle navigation software off/on through MFD to show it again.

### Crosshair Cursor Scale and Cursor Brackets Scale
The original game crosshair is way to big for my liking. I made it a lot smaller by default, but you can make it big again or hide it completely.
You can also make it bearly visible. You may need to adjust this setting depending on selected game video resolution. The brackets part of crosshair is hidden by default.  
Press `Apply` button after you make the changes.

## Limitations
* no physical crouching
* no physical melee

## Troubleshooting
### General
* Laser pointer on the MFD doesn't work - Check if the game window is in focus.

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
