#include "uevr/API.hpp"
#include "SDK/Engine_classes.hpp"
#include "SDK/SlateCore_structs.hpp"
#include "SDK/UMG_classes.hpp"
#include "SDK/WIDGET_MainMenu_InGame_classes.hpp"
#include "SDK/WIDGET_OptionsCategoryMenuList_classes.hpp"
#include "SDK/WIDGET_OptionsMenu_Gameplay_classes.hpp"
#include "SDK/PAWN_PlayerGhost_classes.hpp"
#include "SDK/WIDGET_PreGameScreen_classes.hpp"
#include "SDK/WIDGET_SplashScreen_Title_classes.hpp"

#include "plugin_utils.hpp"
#include "vr_options_menu.hpp"
#include "vr_options_sync.hpp"

using namespace SDK;
using namespace uevr;

namespace {

constexpr const wchar_t* kPageClassPath = L"/Game/Mods/UI/Options/_WIDGET_OptionsMenu_VR._WIDGET_OptionsMenu_VR_C";
constexpr const wchar_t* kPanelMaterialPath = L"Material /Game/Art/UI/HUD/MainMenu/SubMenuGeneric/MAT_SubMenu_ListPanel.MAT_SubMenu_ListPanel";
constexpr int kGameCategoryCount = 6;
// The game sized the category list for six items of 100 units plus 8 units of padding. The
// seventh item would be cut off at the bottom, so the whole list is moved up by this many
// units into the empty space under the header.
constexpr float kCategoryListShift = 110.f;
// After this many failed installs on one screen the plugin stops trying, so a broken pak
// does not fill the log every tick.
constexpr int kMaxFailedAttempts = 3;

// Logs a line once per plugin load. Diagnostics for the title screen path, which has no
// other output until the page is installed.
#define PLUGIN_WARN_ONCE(...) { static bool logged_ = false; if (!logged_) { logged_ = true; API::get()->log_warn(__VA_ARGS__); } }

} // namespace

UWIDGET_OptionsScreen_C* VROptionsMenu::s_installed_screen{ nullptr };
U_WIDGET_OptionsMenu_VR_C* VROptionsMenu::s_page{ nullptr };
int VROptionsMenu::s_failed_attempts{ 0 };
bool VROptionsMenu::s_page_open{ false };
bool VROptionsMenu::s_settings_changed{ false };

void VROptionsMenu::handle(UWIDGET_PlayerHUD_C* hud, APawn* pawn) {
    try {
        // The pawn decides which menu exists. The HUD pointer alone cannot: the plugin keeps it
        // across level changes, and a freed widget can still pass IsValid.
        const bool at_title = UKismetSystemLibrary::IsValid(pawn) && PluginUtils::is_a<APAWN_PlayerGhost_C>(pawn);
        if (at_title) PLUGIN_WARN_ONCE("[vr_options_menu][handle] Ghost pawn, looking for the title screen");
        UWIDGET_OptionsScreen_C* screen = at_title ? find_title_screen(pawn) : find_screen(hud);
        if (screen == nullptr || !is_ready(screen)) return;
        // Covers the install and the per-tick sync: a pak and plugin that do not match would
        // otherwise throw, and log, every tick.
        if (s_failed_attempts >= kMaxFailedAttempts) return;
        if (screen == s_installed_screen) {
            // The screen was reached through live pointers this tick, so its page is alive too.
            watch_page(screen);
            return;
        }
        if (has_vr_category(screen)) {
            adopt_page(screen);
            return;
        }

        API::get()->log_warn("[vr_options_menu][handle] Installing the VR options page into %s", screen->GetName().c_str());
        U_WIDGET_OptionsMenu_VR_C* page = create_page(screen);
        if (page == nullptr) {
            ++s_failed_attempts;
            return;
        }
        page->Install(screen);
        // The visible steps come first, so a failing settings sync cannot hide the category.
        apply_panel_material(page);
        shift_category_list(screen);
        VROptionsSync::push(page);
        s_installed_screen = screen;
        s_page = page;
        s_page_open = false;
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
    s_page = nullptr;
    s_page_open = false;
    s_failed_attempts = 0;
}

UWIDGET_OptionsScreen_C* VROptionsMenu::find_screen(UWIDGET_PlayerHUD_C* hud) {
    if (!UKismetSystemLibrary::IsValid(hud)) return nullptr;
    UWIDGET_MainMenu_InGame_C* menu = hud->WIDGET_MainMenu_InGame;
    if (!UKismetSystemLibrary::IsValid(menu)) return nullptr;
    UWIDGET_OptionsScreen_C* screen = menu->WIDGET_OptionsScreen;
    return UKismetSystemLibrary::IsValid(screen) ? screen : nullptr;
}

// Without a HUD the game is at the title screen. The main menu's pawn is a PAWN_PlayerGhost
// that holds the pre-game screen, which holds the title screen with its own options screen.
UWIDGET_OptionsScreen_C* VROptionsMenu::find_title_screen(APawn* pawn) {
    UWIDGET_PreGameScreen_C* pre_game = static_cast<APAWN_PlayerGhost_C*>(pawn)->PreGameScreenWidget;
    if (!UKismetSystemLibrary::IsValid(pre_game)) {
        PLUGIN_WARN_ONCE("[vr_options_menu][find_title_screen] Ghost pawn has no pre-game screen yet");
        return nullptr;
    }
    UWIDGET_SplashScreen_Title_C* title = pre_game->WIDGET_SplashScreen_Title;
    if (!UKismetSystemLibrary::IsValid(title)) {
        PLUGIN_WARN_ONCE("[vr_options_menu][find_title_screen] Pre-game screen has no title screen yet");
        return nullptr;
    }
    UWIDGET_OptionsScreen_C* screen = title->WIDGET_OptionsScreen;
    if (!UKismetSystemLibrary::IsValid(screen)) {
        PLUGIN_WARN_ONCE("[vr_options_menu][find_title_screen] %s has no options screen yet", title->GetName().c_str());
        return nullptr;
    }
    return screen;
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

// The box of category items fills its canvas from the top. A negative top offset makes the box
// start higher while its bottom stays put, so every item moves up by the same amount. The list
// widget's own slot is left alone: ANIM_OpenOptionsSubscreen animates that one.
void VROptionsMenu::shift_category_list(UWIDGET_OptionsScreen_C* screen) {
    UVerticalBox* box = screen->WIDGET_OptionsCategoryMenuList->VBOX_OptionCategoryWidgetList;
    if (box == nullptr || box->Slot == nullptr || !box->Slot->IsA(UCanvasPanelSlot::StaticClass())) {
        API::get()->log_warn("[vr_options_menu][shift_category_list] Category box has no canvas slot, list not moved");
        return;
    }
    auto* slot = static_cast<UCanvasPanelSlot*>(box->Slot);
    FMargin offsets = slot->LayoutData.Offsets;
    offsets.Top = -kCategoryListShift;
    slot->SetOffsets(offsets);
    API::get()->log_warn("[vr_options_menu][shift_category_list] Category list moved up by %.0f units", kCategoryListShift);
}

// The page sits in the screen's grid next to the game's pages. Used when an earlier plugin
// instance installed the page and this one holds no pointer to it.
U_WIDGET_OptionsMenu_VR_C* VROptionsMenu::find_page(UWIDGET_OptionsScreen_C* screen) {
    auto* page_class = reinterpret_cast<UClass*>(U_WIDGET_OptionsMenu_VR_C::BridgeClassRef().get());
    UWidget* gameplay = screen->WIDGET_OptionsMenu_Gameplay;
    UPanelWidget* scale_box = gameplay != nullptr ? gameplay->GetParent() : nullptr;
    UPanelWidget* grid = scale_box != nullptr ? scale_box->GetParent() : nullptr;
    if (page_class == nullptr || grid == nullptr) return nullptr;
    for (int i = 0; i < grid->GetChildrenCount(); ++i) {
        UWidget* child = grid->GetChildAt(i);
        if (child != nullptr && child->IsA(page_class)) return static_cast<U_WIDGET_OptionsMenu_VR_C*>(child);
    }
    return nullptr;
}

// The page survived a plugin reload, or another instance installed it. Its rows already hold
// the right values, so only the last-seen values are taken from them; nothing is pushed. The
// material and the list shift are applied again: both are idempotent, and an install that
// failed half way may have skipped them.
void VROptionsMenu::adopt_page(UWIDGET_OptionsScreen_C* screen) {
    s_installed_screen = screen;
    s_page = find_page(screen);
    if (s_page == nullptr) {
        API::get()->log_warn("[vr_options_menu][adopt_page] VR category present but no page found, settings not synced");
        return;
    }
    apply_panel_material(s_page);
    shift_category_list(screen);
    s_page_open = is_page_open(screen);
    VROptionsSync::adopt(s_page);
    s_failed_attempts = 0;
    API::get()->log_warn("[vr_options_menu][adopt_page] Adopted the installed page");
}

// Each time the player opens the VR page its rows are read again from their stores, so a
// value changed in UEVR's overlay shows up. Every tick a SavedValue that changed, which is an
// Apply, goes into its store.
void VROptionsMenu::watch_page(UWIDGET_OptionsScreen_C* screen) {
    if (s_page == nullptr) return;
    const bool open = is_page_open(screen);
    if (open && !s_page_open) VROptionsSync::push(s_page);
    s_page_open = open;
    if (VROptionsSync::pull(s_page)) s_settings_changed = true;
}

bool VROptionsMenu::is_page_open(UWIDGET_OptionsScreen_C* screen) {
    return s_page != nullptr && static_cast<UObject*>(screen->OpenedSubMenu) == static_cast<UObject*>(s_page);
}

bool VROptionsMenu::consume_settings_change() {
    const bool changed = s_settings_changed;
    s_settings_changed = false;
    return changed;
}
