#pragma once

#include <string>
#include <unordered_map>

namespace SDK
{
class UCanvasPanelSlot;
class UDataTable;
class UWidget;
class UWIDGET_PlayerHUD_C;
}

// Replaces the game's tutorial popup texts with the VR texts of tutorial_messages.ini in the
// UEVR profile folder.
//
// Every popup text is a row of the data table DT_Tutorials, one FText DisplayMessage per row;
// PAWN_Hacker_Simple::GetTutorialMessage reads the row when a popup is shown. The plugin loads
// the table, roots it so it stays the one object every reader gets, and writes the ini text
// into each row named in the [tutorials] section. Rows missing from the ini keep the game's
// text. The ini is read once; the table is patched once and checked again every few seconds,
// so a plugin swap by the hot loader patches it again.
class TutorialMessages final
{
public:
    // Called once per engine tick, on the game thread.
    static void handle();

    // Sizes the popup on the HUD as the [popup] section of the ini says: width and height of
    // the text box in screen units (the game's box is 500 x 75; the frame around it follows)
    // and font_size (the game's is 20). Called when the plugin sets up the HUD; a value of 0
    // or a missing section keeps the game's value.
    static void apply_popup_size(SDK::UWIDGET_PlayerHUD_C* neural_hud);

private:
    static bool read_ini();
    static SDK::UCanvasPanelSlot* canvas_slot_of(SDK::UWidget* widget);
    static SDK::UDataTable* find_table();
    static void apply(SDK::UDataTable* table);
    static std::wstring to_wide(const std::string& utf8);

    // Row name in lower case -> text, as mINI lower-cases keys.
    static std::unordered_map<std::string, std::string> s_texts;
    static bool s_ini_read;
    static float s_popup_width;
    static float s_popup_height;
    static float s_popup_font_size;
    static SDK::UDataTable* s_patched_table;
    static int s_ticks_until_check;
};
