#pragma once

// Registers input actions that name the VR controller buttons the plugin handles itself, so a
// tutorial text or button legend can show the icon of that button with a placeholder such as
// {VR_LeftGrip}.
//
// The game's placeholders name a rebindable action, for example {Real_Interact}. The legend
// widget looks the action up in the player's key bindings and draws the bound key. That is wrong
// for a button the plugin reads directly from the XInput state, because the player can rebind the
// game's action away from that button while the plugin keeps reading it.
//
// FUNCLIB_GameSettings::GetBoundKeyForCurrentUser only consults the player's bindings for names
// that start with Real_, Cyber_ or Minigame_ (after the Gamepad_ or JCMS_ prefix). Every other
// name falls back to the engine's UInputSettings action mappings, which the options menu cannot
// change. So the plugin adds one mapping per VR button there, under the plain name and under the
// gamepad and JCMS prefixes that the legend widget adds for the other controller types. The key
// is always a gamepad key, so WIDGET_ButtonLegend_Key draws a gamepad icon even while the game is
// in keyboard and mouse mode (it picks the icon style by the key's type, not by the mode).
//
// The mappings are lookup entries only; no input event is bound to them.
class VRInputActions final
{
public:
    // Called once per engine tick, on the game thread. Adds the mappings on the first call and
    // does nothing afterwards.
    static void handle();

private:
    static bool register_all();
    static bool add_mapping(const wchar_t* action_name, const wchar_t* key_name);

    static bool s_done;
};
