#include "vr_button_atlas.hpp"

#include "uevr/API.hpp"
#include "SDK/Engine_classes.hpp"
#include "SDK/WIDGET_ButtonLegend_Key_classes.hpp"
#include "plugin_utils.hpp"

using namespace uevr;

namespace {

constexpr const wchar_t* kAtlasPath = L"/Game/Mods/UI/ControllerButtons/T_VRButtonLayout.T_VRButtonLayout";
constexpr const wchar_t* kMaterialPath = L"/Game/Mods/UI/ControllerButtons/MI_VRButtonLayout.MI_VRButtonLayout";
constexpr const wchar_t* kWidgetClassPath = L"/Game/Blueprints/UI/HUD/Widgets/ButtonLegend/WIDGET_ButtonLegend_Key.WIDGET_ButtonLegend_Key_C";
constexpr const wchar_t* kWidgetClassName = L"WidgetBlueprintGeneratedClass /Game/Blueprints/UI/HUD/Widgets/ButtonLegend/WIDGET_ButtonLegend_Key.WIDGET_ButtonLegend_Key_C";

// Ticks between two checks that the class default object still holds the VR assets.
constexpr int kCheckTicks = 600;

// EObjectFlags::RF_ArchetypeObject in UE 4.27: a template inside a loaded widget tree.
constexpr uint32_t kArchetypeFlag = 0x20;

} // anonymous namespace

SDK::UTexture* VRButtonAtlas::s_atlas{ nullptr };
SDK::UMaterialInterface* VRButtonAtlas::s_material{ nullptr };
bool VRButtonAtlas::s_load_failed_logged{ false };
int VRButtonAtlas::s_ticks_until_check{ 1 };

void VRButtonAtlas::handle() {
    if (--s_ticks_until_check > 0) return;
    s_ticks_until_check = kCheckTicks;
    try {
        if (s_atlas == nullptr && !load_assets()) return;
        SDK::UClass* widget_class = find_widget_class();
        if (widget_class == nullptr || is_applied(widget_class)) return;
        apply(widget_class);
    }
    catch (...) {
        API::get()->log_error("[vr_button_atlas][handle] Exception");
    }
}

// Loads the atlas and the material instance from the Core pak and roots them, so the garbage
// collector keeps them while only the plugin and the patched widgets point to them.
bool VRButtonAtlas::load_assets() {
    auto* atlas = static_cast<SDK::UTexture*>(load_object(kAtlasPath));
    auto* material = static_cast<SDK::UMaterialInterface*>(load_object(kMaterialPath));
    if (atlas == nullptr || material == nullptr) {
        if (!s_load_failed_logged) {
            API::get()->log_warn("[vr_button_atlas][load_assets] Atlas assets not found; is the Core pak deployed? Retrying");
            s_load_failed_logged = true;
        }
        return false;
    }
    PluginUtils::add_to_root(atlas);
    PluginUtils::add_to_root(material);
    s_atlas = atlas;
    s_material = material;
    API::get()->log_warn("[vr_button_atlas][load_assets] Loaded the VR button atlas and its material instance");
    return true;
}

SDK::UObject* VRButtonAtlas::load_object(const wchar_t* object_path) {
    const SDK::FSoftObjectPath path = SDK::UKismetSystemLibrary::MakeSoftObjectPath(object_path);
    const auto soft_ref = SDK::UKismetSystemLibrary::Conv_SoftObjPathToSoftObjRef(path);
    return SDK::UKismetSystemLibrary::LoadAsset_Blocking(soft_ref);
}

// The loaded widget class, or loads it. Loading it early means the class default object is
// patched before any menu or popup package brings in templates of it.
SDK::UClass* VRButtonAtlas::find_widget_class() {
    auto* widget_class = API::get()->find_uobject<SDK::UClass>(kWidgetClassName);
    if (widget_class != nullptr) return widget_class;
    return PluginUtils::load_class(kWidgetClassPath);
}

bool VRButtonAtlas::is_applied(SDK::UClass* widget_class) {
    auto* cdo = static_cast<SDK::UWIDGET_ButtonLegend_Key_C*>(widget_class->DefaultObject);
    return cdo != nullptr && cdo->GamepadLayoutAtlas == s_atlas
        && cdo->PlatformButtonMaterial == reinterpret_cast<SDK::UMaterial*>(s_material);
}

// Sets the two variables on the class default object and on every object of the class that
// exists already: default objects and templates of subclasses, templates in loaded widget
// trees, and live widgets, which redraw.
void VRButtonAtlas::apply(SDK::UClass* widget_class) {
    int templates = 0;
    int live = 0;
    const int32_t count = SDK::UObject::GObjects->Num();
    for (int32_t i = 0; i < count; ++i) {
        SDK::UObject* object = SDK::UObject::GObjects->GetByIndex(i);
        if (object == nullptr || !object->IsA(widget_class)) continue;
        const bool is_template = object->IsDefaultObject()
            || (static_cast<uint32_t>(object->Flags) & kArchetypeFlag) != 0;
        apply_to_object(object, !is_template);
        is_template ? ++templates : ++live;
    }
    API::get()->log_warn("[vr_button_atlas][apply] VR button atlas set on %d templates and %d live legend keys", templates, live);
}

void VRButtonAtlas::apply_to_object(SDK::UObject* object, bool refresh) {
    auto* widget = static_cast<SDK::UWIDGET_ButtonLegend_Key_C*>(object);
    widget->GamepadLayoutAtlas = s_atlas;
    // The variable is typed UMaterial in the Blueprint, but the widget only passes it to
    // SetMaterial, which takes any material interface; the game's keyboard key cap is an
    // instance too.
    widget->PlatformButtonMaterial = reinterpret_cast<SDK::UMaterial*>(s_material);
    if (refresh) widget->UpdateMapping();
}
