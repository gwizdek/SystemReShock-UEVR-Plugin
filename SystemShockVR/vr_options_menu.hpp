#pragma once

#include "SDK/Engine_classes.hpp"
#include "SDK/WIDGET_PlayerHUD_classes.hpp"
#include "SDK/WIDGET_OptionsScreen_classes.hpp"
#include "BridgeSDK/_WIDGET_OptionsMenu_VR_classes.hpp"

// Adds the mod's "VR" category and page to the game's Options screen. The page's own
// Blueprint does the installing (its Install function, see documentation/vr-options-menu.md).
// This class finds the live screen, creates the page once per screen instance, gives the
// page the game's panel material, which the mod pak does not hold, and has VROptionsSync keep
// the rows and their stores in step: store values go into the rows after the install and each
// time the page opens, and a row's SavedValue, which changes only on Apply, goes back.
class VROptionsMenu final
{
public:
    // Game thread, once per tick. Uses the pause menu's options screen when the HUD exists,
    // else the title screen's, reached through the main menu's ghost pawn. Does nothing until
    // that screen has run its own InitializeMenu. Once the page is in, it only watches the rows.
    static void handle(SDK::UWIDGET_PlayerHUD_C* hud, SDK::APawn* pawn);
    // Forgets the installed screen and page. Called on level change, when the HUD is made again.
    static void reset();
    // True once after the player pressed Apply and the settings were saved. The caller then
    // applies the values to the game, for example VRBody::apply_custom_vr_game_options.
    static bool consume_settings_change();

private:
    static SDK::UWIDGET_OptionsScreen_C* find_screen(SDK::UWIDGET_PlayerHUD_C* hud);
    static SDK::UWIDGET_OptionsScreen_C* find_title_screen(SDK::APawn* pawn);
    static bool is_ready(SDK::UWIDGET_OptionsScreen_C* screen);
    static bool has_vr_category(SDK::UWIDGET_OptionsScreen_C* screen);
    static SDK::U_WIDGET_OptionsMenu_VR_C* create_page(SDK::UWIDGET_OptionsScreen_C* screen);
    static SDK::U_WIDGET_OptionsMenu_VR_C* find_page(SDK::UWIDGET_OptionsScreen_C* screen);
    static void apply_panel_material(SDK::U_WIDGET_OptionsMenu_VR_C* page);
    static void shift_category_list(SDK::UWIDGET_OptionsScreen_C* screen);
    static void adopt_page(SDK::UWIDGET_OptionsScreen_C* screen);
    static void watch_page(SDK::UWIDGET_OptionsScreen_C* screen);
    static bool is_page_open(SDK::UWIDGET_OptionsScreen_C* screen);

    static SDK::UWIDGET_OptionsScreen_C* s_installed_screen;
    static SDK::U_WIDGET_OptionsMenu_VR_C* s_page;
    static int s_failed_attempts;
    static bool s_page_open;
    static bool s_settings_changed;
};
