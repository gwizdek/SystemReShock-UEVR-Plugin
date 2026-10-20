#pragma once

#include "BridgeSDK/_WIDGET_OptionsMenu_VR_classes.hpp"

// Keeps the rows of the VR options page and their stores in step. A row is its own store
// while the page is open: SavedValue changes only when the player presses Apply. Each row is
// bound to a SettingStore (an ini section or UEVR's settings), and its SettingName is the key
// in that store. See "Settings sync" in documentation/vr-options-menu.md.
class VROptionsSync final
{
public:
    // Store values into the rows, then refreshes the list's Apply and Reset state. Called after
    // the install and each time the page opens, so values changed elsewhere (UEVR's overlay)
    // show up.
    static void push(SDK::U_WIDGET_OptionsMenu_VR_C* page);
    // Takes the last-seen values from the rows without changing them. Used for a page that an
    // earlier plugin instance installed.
    static void adopt(SDK::U_WIDGET_OptionsMenu_VR_C* page);
    // Puts every slider whose handle is off its row's Step back on the nearest step. The game's
    // slider does not snap a mouse drag. Called every tick while the page is open.
    static void snap_sliders(SDK::U_WIDGET_OptionsMenu_VR_C* page);
    // Writes every row whose SavedValue changed since the last call into its store and saves
    // the stores that changed. True when something was written.
    static bool pull(SDK::U_WIDGET_OptionsMenu_VR_C* page);
};
