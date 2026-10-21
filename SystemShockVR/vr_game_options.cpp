#include "vr_game_options.hpp"

#include <string>

#include "uevr/API.hpp"
#include "SDK/SAVE_Settings_classes.hpp"
#include "plugin_utils.hpp"

using namespace uevr;

namespace {

constexpr const wchar_t* kSettingsClass =
    L"BlueprintGeneratedClass /Game/Blueprints/UI/HUD/Widgets/Settings/SAVE_Settings.SAVE_Settings_C";

// The option widgets that show the settings this class changes.
constexpr const wchar_t* kOptionWidgetClasses[] = {
    L"WidgetBlueprintGeneratedClass /Game/Blueprints/UI/MainMenu/OptionsScreen/OptionsCategories/Accessibility-Interface/OPTION_Interface_Headbob.OPTION_Interface_Headbob_C",
    L"WidgetBlueprintGeneratedClass /Game/Blueprints/UI/MainMenu/OptionsScreen/OptionsCategories/Accessibility-Interface/OPTION_Interface_HotbarStyle.OPTION_Interface_HotbarStyle_C",
    L"WidgetBlueprintGeneratedClass /Game/Blueprints/UI/MainMenu/OptionsScreen/OptionsCategories/Accessibility-Interface/OPTION_Interface_HUDCurvature.OPTION_Interface_HUDCurvature_C",
    L"WidgetBlueprintGeneratedClass /Game/Blueprints/UI/MainMenu/OptionsScreen/OptionsCategories/Controls/OPTION_Controls_CrouchToggle.OPTION_Controls_CrouchToggle_C",
    L"WidgetBlueprintGeneratedClass /Game/Blueprints/UI/MainMenu/OptionsScreen/OptionsCategories/Controls/OPTION_Controls_FocusAimToggle.OPTION_Controls_FocusAimToggle_C",
    L"WidgetBlueprintGeneratedClass /Game/Blueprints/UI/MainMenu/OptionsScreen/OptionsCategories/Gameplay/OPTION_Gameplay_FocusOnPuzzles.OPTION_Gameplay_FocusOnPuzzles_C",
    L"WidgetBlueprintGeneratedClass /Game/Blueprints/UI/MainMenu/OptionsScreen/OptionsCategories/Gameplay/OPTION_Gameplay_BatteryReload.OPTION_Gameplay_BatteryReload_C",
    L"WidgetBlueprintGeneratedClass /Game/Blueprints/UI/MainMenu/OptionsScreen/OptionsCategories/Display/OPTION_Display_MotionBlur.OPTION_Display_MotionBlur_C",
    L"WidgetBlueprintGeneratedClass /Game/Blueprints/UI/MainMenu/OptionsScreen/OptionsCategories/Display/OPTION_Display_VSync.OPTION_Display_VSync_C",
    L"WidgetBlueprintGeneratedClass /Game/Blueprints/UI/MainMenu/OptionsScreen/OptionsCategories/Display/OPTION_Display_FieldOfView.OPTION_Display_FieldOfView_C",
};

constexpr float kFieldOfView = 120.f;

// Live widgets belong to the game instance under /Engine/Transient; the templates inside widget
// Blueprint classes are instances too and must stay as they are.
bool is_live_widget(API::UObject* widget) {
    return widget->get_full_name().find(L" /Engine/Transient.") != std::wstring::npos;
}

} // anonymous namespace

void VRGameOptions::apply() {
    SDK::USAVE_Settings_C* settings = find_settings();
    if (settings == nullptr) return;
    apply_interface(settings);
    apply_controls_and_gameplay(settings);
    apply_display(settings);
    const int refreshed = refresh_option_widgets();
    API::get()->log_warn("[vr_game_options][apply] Applied VR specific game options, refreshed %d option widgets", refreshed);
}

SDK::USAVE_Settings_C* VRGameOptions::find_settings() {
    auto* settings_class = API::get()->find_uobject<API::UClass>(kSettingsClass);
    if (settings_class == nullptr) {
        API::get()->log_error("[vr_game_options][find_settings] SAVE_Settings class not loaded");
        return nullptr;
    }
    auto* settings = settings_class->get_first_object_matching<SDK::USAVE_Settings_C>();
    if (settings == nullptr || !PluginUtils::is_a<SDK::USAVE_Settings_C>(settings)) {
        API::get()->log_error("[vr_game_options][find_settings] No SAVE_Settings object");
        return nullptr;
    }
    return settings;
}

void VRGameOptions::apply_interface(SDK::USAVE_Settings_C* settings) {
    // Accessibility: Headbob Amount: OFF
    settings->SetHeadbobAmount(SDK::ENUM_OffReducedNormal::NewEnumerator0);
    settings->ApplyHeadbobAmount(SDK::ENUM_OffReducedNormal::NewEnumerator0);

    // Accessibility: Hotbar Style: NORMAL
    settings->SetHotbarStyle(SDK::ENUM_HotbarStyle::NewEnumerator0);
    settings->ApplyHotbarStyle(SDK::ENUM_HotbarStyle::NewEnumerator0);

    // Accessibility: HUD Curve Amount: 0.0
    // This is important for the HotbarSlots to be properly placed on the MFD after creating VR HUD
    settings->SetHUDCurvature(0.0f);
    settings->ApplyHUDCurvature(0.0f);
}

void VRGameOptions::apply_controls_and_gameplay(SDK::USAVE_Settings_C* settings) {
    // Controls: Toggle Crouch: ON
    settings->SetCrouchToggle(true);
    settings->ApplyCrouchToggle(true);

    // Controls: Toggle Aim Down Sights: OFF
    settings->SetFocusAimToggle(false);
    settings->ApplyFocusAimToggle(false);

    // Gameplay: Focus Camera On Puzzles: OFF
    settings->SetFocusOnPuzzles(false);
    settings->ApplyFocusOnPuzzles(false);

    // Gameplay: Reload Can Use Batteries: OFF
    settings->SetReloadCanUseBatteries(false);
    settings->ApplyReloadCanUseBatteries(false);
}

void VRGameOptions::apply_display(SDK::USAVE_Settings_C* settings) {
    // Display: Motion Blur: OFF
    settings->SetEnableMotionBlur(false);
    settings->ApplyEnableMotionBlur(false);

    // Display: V-Sync: OFF
    settings->SetEnableVSync(false);
    settings->ApplyEnableVSync(false);

    // Display: FOV (real/cyberspace)
    settings->SetFOV(kFieldOfView, true);
    settings->ApplyFOV(kFieldOfView, true);
    settings->SetFOV(kFieldOfView, false);
    settings->ApplyFOV(kFieldOfView, false);
}

// Makes every existing option widget of those classes read its setting again. UpdateVisuals is
// called by name, so each option's own override runs, not the empty one of OPTION_Base. A class
// that is not loaded has no widgets; its lists read the new values when they are built.
int VRGameOptions::refresh_option_widgets() {
    int refreshed = 0;
    for (const wchar_t* path : kOptionWidgetClasses) {
        auto* option_class = API::get()->find_uobject<API::UClass>(path);
        if (option_class == nullptr) continue;
        for (API::UObject* option : option_class->get_objects_matching()) {
            if (!is_live_widget(option)) continue;
            option->call_function(L"UpdateVisuals", nullptr);
            ++refreshed;
        }
    }
    return refreshed;
}
