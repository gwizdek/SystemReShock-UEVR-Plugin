#pragma once

#include <cstdint>

namespace SDK
{
class UClass;
class UObject;
class UTexture;
class UMaterialInterface;
}

// Gives the game's button legend widget the VR controller button atlas, so tutorial popups
// and button legends draw VR controller buttons instead of Xbox buttons.
//
// WIDGET_ButtonLegend_Key draws a gamepad key with MAT_PlatformButton on its mesh, the atlas
// as the material's ButtonTextureSheet and the cell index from
// FUNCLIB_UserInterface::GetGamepadButtonAtlasIndex. The material and the atlas come from two
// variables of the widget, PlatformButtonMaterial and GamepadLayoutAtlas, which the widget
// loads from the game's assets only while they are unset. So the plugin sets both on the
// class default object, and every legend key made after that starts with the VR assets.
// Legend keys that exist already, including the templates inside the widget trees of loaded
// packages, get the two variables set directly; live ones redraw through UpdateMapping.
//
// The assets come from the Core pak: T_VRButtonLayout, a 4 x 7 atlas whose cells 0 to 15
// follow the game's index function, and MI_VRButtonLayout, an instance of the game's material
// that sets the atlas and RowCount = 7. The game's own keyboard key cap is such an instance
// too, so the widget's SetMaterial takes it. The draw function of the widget is Blueprint
// internal and cannot be hooked, which is why the variables are patched instead.
class VRButtonAtlas final
{
public:
    // Called once per engine tick, on the game thread. Applies the atlas once the assets and
    // the widget class are available, and checks every few seconds that it is still applied.
    static void handle();

private:
    static bool load_assets();
    static SDK::UObject* load_object(const wchar_t* object_path);
    static SDK::UClass* find_widget_class();
    static bool is_applied(SDK::UClass* widget_class);
    static void apply(SDK::UClass* widget_class);
    static void apply_to_object(SDK::UObject* object, bool refresh);

    static SDK::UTexture* s_atlas;
    static SDK::UMaterialInterface* s_material;
    static bool s_load_failed_logged;
    static int s_ticks_until_check;
};
