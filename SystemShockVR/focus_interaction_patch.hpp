#pragma once

#include <cstdint>

// Makes ShouldFocusOnInteract always return false, so keypads, vending machines and puzzles
// never lock the camera onto the device.
//
// INTERACT_Focusable_Base::ShouldFocusOnInteract returns IsUsingGamepad() OR the "focus on
// puzzles" setting, and INTERACT_Keypad and PUZZLE_Base override it. The functions are only
// called from other Blueprint functions, which UEVR's UFunction hook does not see, so the
// plugin patches their bytecode instead: the first instruction becomes a jump to a
// "Result = false" that is followed by a return. INTERACT_Keypad and PUZZLE_Base end with such
// an epilogue; INTERACT_Focusable_Base has it as the branch for "already channeling" and ends
// with "Result = IsUsingGamepad OR setting" instead. The patch lives in the loaded class, so
// it holds until the game exits, and it is checked again now and then in case the class was
// loaded anew.
//
// Without this patch the plugin had to keep the game in keyboard and mouse mode
// (SetIsUsingGamepad(false) on every tick), which made every button legend show keyboard keys.
class FocusInteractionPatch final
{
public:
    // Called once per engine tick, on the game thread. Patches the functions once they are
    // loaded and checks them again every few seconds.
    static void handle();

private:
    static void patch_all();
    static bool patch(const wchar_t* function_name);

    static int s_ticks_until_check;
};
