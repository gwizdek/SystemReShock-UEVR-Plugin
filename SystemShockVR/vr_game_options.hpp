#pragma once

namespace SDK
{
class USAVE_Settings_C;
}

// Sets the game's own options that VR needs, for example headbob off, toggle crouch on, HUD
// curvature 0 and a 120 degree FOV.
//
// The options live in one SAVE_Settings object, which GI_SinglePlayer::LoadShockSettings loads
// once and keeps. Each option is written with its Set function and applied with its Apply
// function. The options screen shows a copy: an option widget reads its setting only when its
// options list is built (WIDGET_MenuListBase::InitializeList -> OPTION_Base::InitializeMenuListItem
// -> UpdateVisuals). So after the change every existing option widget of those settings is told
// to read its setting again; otherwise a list built earlier would show the old value, and
// pressing Apply on its page would write that old value back.
class VRGameOptions final
{
public:
    // Applies the options and refreshes the option widgets. Called on a level or pawn change.
    static void apply();
    // The game's live SAVE_Settings object, or nullptr when it is not loaded. Logs an error
    // then.
    static SDK::USAVE_Settings_C* find_settings();

private:
    static void apply_interface(SDK::USAVE_Settings_C* settings);
    static void apply_controls_and_gameplay(SDK::USAVE_Settings_C* settings);
    static void apply_display(SDK::USAVE_Settings_C* settings);
    static int refresh_option_widgets();
};
