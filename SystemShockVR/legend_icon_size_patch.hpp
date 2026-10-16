#pragma once

// Sets the size of gamepad button icons, as the icon_size key of the [popup] section in
// tutorial_messages.ini says.
//
// WIDGET_ButtonLegend_Key draws one key of a button placeholder, in tutorial popups and in
// every other button legend. Two literals in its bytecode decide how big a key is:
//
//   UpdateLegend         Let Temp_float_Variable    = FloatConst 30.0      (mouse button)
//                        Let Temp_float_Variable_1  = FloatConst 38.0      (gamepad key)
//   TryUpdateLegendSize  Let Temp_struct_Variable   = Vector2D{64, 64}     (picture)
//                        Let Temp_struct_Variable_1 = Vector2D{128, 128}   (picture with key text)
//
// The 38 is PanelSize, the space the key takes in the text around it. The 64 is the canvas
// slot of MESH_KeyBackground, the picture itself; the picture does not follow PanelSize. The
// plugin finds both pairs of statements in the loaded functions and writes icon_size over the
// 38.0 and 64 * icon_size / 38 over the 64.0, so space and picture grow together. All VR
// button icons are gamepad keys, so they all get the new size; keyboard keys keep theirs, and
// a mouse button keeps its space but gets the larger picture. A legend key created before the
// patch keeps its size until it updates again. The patch lives in the loaded class, so it
// holds until the game exits, and it is checked again now and then in case the class was
// loaded anew.
class LegendIconSizePatch final
{
public:
    // Called once per engine tick, on the game thread. Does nothing when the ini sets no size.
    static void handle();

private:
    static void read_ini();
    static void patch_panel_size();
    static void patch_picture_size();

    static bool s_ini_read;
    static float s_icon_size;
    static int s_ticks_until_check;
};
