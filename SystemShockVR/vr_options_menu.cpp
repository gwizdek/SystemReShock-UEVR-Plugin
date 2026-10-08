#include "uevr/API.hpp"
#include "SDK/Engine_classes.hpp"
#include "SDK/UMG_classes.hpp"
#include "SDK/WIDGET_MainMenu_InGame_classes.hpp"
#include "SDK/WIDGET_OptionsCategoryMenuList_classes.hpp"

#include "plugin_utils.hpp"
#include "vr_options_menu.hpp"

using namespace SDK;
using namespace uevr;

namespace {

constexpr const wchar_t* kPageClassPath = L"/Game/Mods/UI/Options/_WIDGET_OptionsMenu_VR._WIDGET_OptionsMenu_VR_C";
constexpr const wchar_t* kPanelMaterialPath = L"Material /Game/Art/UI/HUD/MainMenu/SubMenuGeneric/MAT_SubMenu_ListPanel.MAT_SubMenu_ListPanel";
constexpr int kGameCategoryCount = 6;
// After this many failed installs on one screen the plugin stops trying, so a broken pak
// does not fill the log every tick.
constexpr int kMaxFailedAttempts = 3;

} // namespace

UWIDGET_OptionsScreen_C* VROptionsMenu::s_installed_screen{ nullptr };
int VROptionsMenu::s_failed_attempts{ 0 };

void VROptionsMenu::handle(UWIDGET_PlayerHUD_C* hud) {
    try {
        UWIDGET_OptionsScreen_C* screen = find_screen(hud);
        if (screen == nullptr || screen == s_installed_screen || !is_ready(screen)) return;
        if (has_vr_category(screen)) {
            // The page survived a plugin reload, or another instance installed it.
            s_installed_screen = screen;
            return;
        }
        if (s_failed_attempts >= kMaxFailedAttempts) return;

        API::get()->log_warn("[vr_options_menu][handle] Installing the VR options page into %s", screen->GetName().c_str());
        U_WIDGET_OptionsMenu_VR_C* page = create_page(screen);
        if (page == nullptr) {
            ++s_failed_attempts;
            return;
        }
        page->Install(screen);
        apply_panel_material(page);
        s_installed_screen = screen;
        s_failed_attempts = 0;
        API::get()->log_warn("[vr_options_menu][handle] VR options page installed, categories: %d",
            screen->WIDGET_OptionsCategoryMenuList->MenuListItemArray.Num());
    }
    catch (...) {
        ++s_failed_attempts;
        API::get()->log_error("[vr_options_menu][handle] Exception (attempt %d)", s_failed_attempts);
    }
}

void VROptionsMenu::reset() {
    s_installed_screen = nullptr;
    s_failed_attempts = 0;
}

UWIDGET_OptionsScreen_C* VROptionsMenu::find_screen(UWIDGET_PlayerHUD_C* hud) {
    if (!UKismetSystemLibrary::IsValid(hud)) return nullptr;
    UWIDGET_MainMenu_InGame_C* menu = hud->WIDGET_MainMenu_InGame;
    if (!UKismetSystemLibrary::IsValid(menu)) return nullptr;
    UWIDGET_OptionsScreen_C* screen = menu->WIDGET_OptionsScreen;
    return UKismetSystemLibrary::IsValid(screen) ? screen : nullptr;
}

// The screen's OnInitialized fills the category list. Until then the installer would
// re-number an empty list.
bool VROptionsMenu::is_ready(UWIDGET_OptionsScreen_C* screen) {
    UWIDGET_OptionsCategoryMenuList_C* list = screen->WIDGET_OptionsCategoryMenuList;
    return list != nullptr && list->MenuListItemArray.Num() >= kGameCategoryCount;
}

bool VROptionsMenu::has_vr_category(UWIDGET_OptionsScreen_C* screen) {
    UVerticalBox* box = screen->WIDGET_OptionsCategoryMenuList->VBOX_OptionCategoryWidgetList;
    return box != nullptr && box->GetChildrenCount() > kGameCategoryCount;
}

// Nothing in the game imports the page class, so it is loaded here, as the VR body's class is.
U_WIDGET_OptionsMenu_VR_C* VROptionsMenu::create_page(UWIDGET_OptionsScreen_C* screen) {
    UClass* page_class = PluginUtils::load_class_for_bridge(kPageClassPath, U_WIDGET_OptionsMenu_VR_C::BridgeClassRef());
    if (page_class == nullptr) {
        API::get()->log_error("[vr_options_menu][create_page] Page class not loaded. Is the Core pak mounted?");
        return nullptr;
    }
    UUserWidget* widget = UWidgetBlueprintLibrary::Create(screen, page_class, nullptr);
    if (widget == nullptr || !widget->IsA(page_class)) {
        API::get()->log_error("[vr_options_menu][create_page] Create returned no page widget");
        return nullptr;
    }
    return static_cast<U_WIDGET_OptionsMenu_VR_C*>(widget);
}

// The game's option pages share one background material. The mod page references no game
// art, so the material is looked up in the running game and set on the page's image.
void VROptionsMenu::apply_panel_material(U_WIDGET_OptionsMenu_VR_C* page) {
    auto* material = API::get()->find_uobject<UMaterialInterface>(kPanelMaterialPath);
    UImage* background = page->IMAGE_PanelBackground();
    if (material == nullptr || background == nullptr) {
        API::get()->log_warn("[vr_options_menu][apply_panel_material] Panel material or image not found, page stays without background");
        return;
    }
    background->SetBrushFromMaterial(material);
}
