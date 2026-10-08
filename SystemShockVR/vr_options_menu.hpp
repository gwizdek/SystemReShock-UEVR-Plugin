#pragma once

#include "SDK/Engine_classes.hpp"
#include "SDK/WIDGET_PlayerHUD_classes.hpp"
#include "SDK/WIDGET_OptionsScreen_classes.hpp"
#include "BridgeSDK/_WIDGET_OptionsMenu_VR_classes.hpp"

// Adds the mod's "VR" category and page to the game's Options screen. The page's own
// Blueprint does the installing (its Install function, see documentation/vr-options-menu.md).
// This class only finds the live screen, creates the page once per screen instance and gives
// the page the game's panel material, which the mod pak does not hold.
class VROptionsMenu final
{
public:
    // Game thread, once per tick. Uses the pause menu's options screen when the HUD exists,
    // else the title screen's, reached through the main menu's ghost pawn. Does nothing until
    // that screen has run its own InitializeMenu, and nothing more once the page is in.
    static void handle(SDK::UWIDGET_PlayerHUD_C* hud, SDK::APawn* pawn);
    // Forgets the installed screen. Called on level change, when the HUD is made again.
    static void reset();

private:
    static SDK::UWIDGET_OptionsScreen_C* find_screen(SDK::UWIDGET_PlayerHUD_C* hud);
    static SDK::UWIDGET_OptionsScreen_C* find_title_screen(SDK::APawn* pawn);
    static bool is_ready(SDK::UWIDGET_OptionsScreen_C* screen);
    static bool has_vr_category(SDK::UWIDGET_OptionsScreen_C* screen);
    static SDK::U_WIDGET_OptionsMenu_VR_C* create_page(SDK::UWIDGET_OptionsScreen_C* screen);
    static void apply_panel_material(SDK::U_WIDGET_OptionsMenu_VR_C* page);
    static void shift_category_list(SDK::UWIDGET_OptionsScreen_C* screen);

    static SDK::UWIDGET_OptionsScreen_C* s_installed_screen;
    static int s_failed_attempts;
};
