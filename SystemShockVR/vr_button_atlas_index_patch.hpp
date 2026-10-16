#pragma once

#include <cstdint>

// Gives the pointing hand cell of the VR button atlas a gamepad key, so a button placeholder
// can show it.
//
// FUNCLIB_UserInterface::GetGamepadButtonAtlasIndex turns a gamepad key into a cell of the
// button atlas with a chain of branches, one per key:
//
//   LetBool Equal = EqualEqual_KeyKey(Key, FKey{<name>})
//   JumpIfNot Equal -> next branch
//   Let Index = <cell>
//   Let Rotation = 0.0
//   Jump -> Return
//
// Any other key falls through to "Index = -1; Rotation = 0; Jump -> Return", and no key
// reaches cell 24, the pointing hand. Behind that default the function has four branches that
// only run on the Nintendo Switch, where the face buttons swap places. The plugin copies the
// last key branch over the start of that dead code, changes its key to Gamepad_RightStick_Up
// and its cell to 24, and moves the default behind it. The rest of the dead code becomes
// EX_Nothing. Gamepad_RightStick_Up is a gamepad key that no other branch handles and that the
// game shows no legend for; vr_input_actions.cpp maps the placeholder {VR_HandPoint} to it.
//
// The patch lives in the loaded class, so it holds until the game exits, and it is checked
// again now and then in case the class was loaded anew.
class VRButtonAtlasIndexPatch final
{
public:
    // Called once per engine tick, on the game thread.
    static void handle();

private:
    static void patch();

    static int s_ticks_until_check;
};
