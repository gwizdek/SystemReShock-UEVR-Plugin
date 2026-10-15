#include "tutorial_messages.hpp"

#include <algorithm>
#include <cctype>

#include "framework.h"
#include "uevr/API.hpp"
#include "SDK/Engine_classes.hpp"
#include "SDK/STRUCT_TutorialData_structs.hpp"
#include "SDK/SystemReShock_classes.hpp"
#include "SDK/UMG_classes.hpp"
#include "SDK/WIDGET_PlayerHUD_classes.hpp"
#include "SDK/WIDGET_TutorialMessage_classes.hpp"
#include "mINI/ini.h"
#include "plugin_utils.hpp"

using namespace uevr;

namespace {

constexpr const wchar_t* kIniFileName = L"tutorial_messages.ini";
constexpr const char* kSection = "tutorials";
constexpr const char* kPopupSection = "popup";

// The frame mesh of the popup is larger than the text box: 576 x 160 around a 500 x 75 box.
constexpr float kFrameExtraWidth = 76.0f;
constexpr float kFrameExtraHeight = 85.0f;
constexpr const wchar_t* kTableName = L"DataTable /Game/Blueprints/Interactables/Triggers/DT_Tutorials.DT_Tutorials";
constexpr const wchar_t* kTablePath = L"/Game/Blueprints/Interactables/Triggers/DT_Tutorials.DT_Tutorials";

// Ticks between two checks that the loaded table is still the patched one.
constexpr int kCheckTicks = 600;

std::string to_lower(std::string text) {
    std::transform(text.begin(), text.end(), text.begin(), [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
    return text;
}

// An ini value is one line, so a line break in a text is written as the two characters \n.
std::string unescape_line_breaks(std::string text) {
    for (size_t at = text.find("\\n"); at != std::string::npos; at = text.find("\\n", at + 1)) {
        text.replace(at, 2, "\n");
    }
    return text;
}

} // anonymous namespace

std::unordered_map<std::string, std::string> TutorialMessages::s_texts;
bool TutorialMessages::s_ini_read{ false };
float TutorialMessages::s_popup_width{ 0.0f };
float TutorialMessages::s_popup_height{ 0.0f };
float TutorialMessages::s_popup_font_size{ 0.0f };
SDK::UDataTable* TutorialMessages::s_patched_table{ nullptr };
int TutorialMessages::s_ticks_until_check{ 1 };

void TutorialMessages::handle() {
    if (--s_ticks_until_check > 0) return;
    s_ticks_until_check = kCheckTicks;
    try {
        if (!s_ini_read && !read_ini()) return;
        if (s_texts.empty()) return;
        SDK::UDataTable* table = find_table();
        if (table == nullptr || table == s_patched_table) return;
        apply(table);
    }
    catch (...) {
        API::get()->log_error("[tutorial_messages][handle] Exception");
    }
}

// Reads the [tutorials] section once. A missing file is not an error: the game's texts stay.
bool TutorialMessages::read_ini() {
    s_ini_read = true;
    const std::string path = API::get()->get_persistent_dir(kIniFileName).string();
    mINI::INIFile file(path);
    mINI::INIStructure ini;
    if (!file.read(ini)) {
        API::get()->log_warn("[tutorial_messages][read_ini] %s not found or unreadable; the game's texts stay", path.c_str());
        return false;
    }
    if (ini.has(kPopupSection)) {
        s_popup_width = static_cast<float>(std::atof(ini.get(kPopupSection).get("width").c_str()));
        s_popup_height = static_cast<float>(std::atof(ini.get(kPopupSection).get("height").c_str()));
        s_popup_font_size = static_cast<float>(std::atof(ini.get(kPopupSection).get("font_size").c_str()));
    }
    if (!ini.has(kSection)) {
        API::get()->log_warn("[tutorial_messages][read_ini] %s has no [%s] section", path.c_str(), kSection);
        return false;
    }
    for (const auto& [key, value] : ini.get(kSection)) {
        s_texts[to_lower(key)] = unescape_line_breaks(value);
    }
    API::get()->log_warn("[tutorial_messages][read_ini] %zu texts read from %s", s_texts.size(), path.c_str());
    return true;
}

// The loaded table, or loads it. Loading it from the plugin makes it the one object every
// later reader gets, and rooting it keeps it that way.
SDK::UDataTable* TutorialMessages::find_table() {
    auto* table = API::get()->find_uobject<SDK::UDataTable>(kTableName);
    if (table != nullptr) return table;
    const SDK::FSoftObjectPath path = SDK::UKismetSystemLibrary::MakeSoftObjectPath(kTablePath);
    const auto soft_ref = SDK::UKismetSystemLibrary::Conv_SoftObjPathToSoftObjRef(path);
    table = static_cast<SDK::UDataTable*>(SDK::UKismetSystemLibrary::LoadAsset_Blocking(soft_ref));
    if (table == nullptr) {
        API::get()->log_error("[tutorial_messages][find_table] Cannot load %ls", kTablePath);
    }
    return table;
}

// Writes the ini text into every row the ini names. The row struct holds one FText; the new
// FText comes from the engine's string conversion, so it carries the text as its source string
// and the popup widget finds the button placeholders in it as in the game's own texts.
void TutorialMessages::apply(SDK::UDataTable* table) {
    PluginUtils::add_to_root(table);
    int replaced = 0;
    const int32_t count = table->RowMap.NumAllocated();
    for (int32_t i = 0; i < count; ++i) {
        if (!table->RowMap.IsValidIndex(i)) continue;
        auto& pair = table->RowMap[i];
        const auto found = s_texts.find(to_lower(pair.Key().GetRawString()));
        if (found == s_texts.end() || pair.Value() == nullptr) continue;
        auto* row = reinterpret_cast<SDK::FSTRUCT_TutorialData*>(pair.Value());
        row->DisplayMessage_2_FCA74516419B252E9A99769C9B6DBA76 =
            SDK::UKismetTextLibrary::Conv_StringToText(SDK::FString(to_wide(found->second).c_str()));
        ++replaced;
    }
    s_patched_table = table;
    API::get()->log_warn("[tutorial_messages][apply] Replaced %d of %d tutorial texts (%zu in the ini)", replaced, table->RowMap.Num(), s_texts.size());
}

void TutorialMessages::apply_popup_size(SDK::UWIDGET_PlayerHUD_C* neural_hud) {
    try {
        if (!s_ini_read) read_ini();
        if (neural_hud == nullptr) return;
        SDK::UWIDGET_TutorialMessage_C* popup = neural_hud->WIDGET_TutorialMessage;
        if (popup == nullptr) return;
        if (s_popup_width > 0.0f && s_popup_height > 0.0f) {
            SDK::UCanvasPanelSlot* box = canvas_slot_of(popup);
            SDK::UCanvasPanelSlot* frame = canvas_slot_of(popup->MESH_Background);
            if (box == nullptr || frame == nullptr) {
                API::get()->log_error("[tutorial_messages][apply_popup_size] The popup or its frame has no canvas slot");
                return;
            }
            box->SetSize(SDK::FVector2D{ s_popup_width, s_popup_height });
            frame->SetSize(SDK::FVector2D{ s_popup_width + kFrameExtraWidth, s_popup_height + kFrameExtraHeight });
        }
        if (s_popup_font_size > 0.0f && popup->TEXT_TutorialMessage != nullptr) {
            popup->TEXT_TutorialMessage->SetFontSize(s_popup_font_size);
        }
        API::get()->log_warn("[tutorial_messages][apply_popup_size] Popup box %g x %g, font size %g", s_popup_width, s_popup_height, s_popup_font_size);
    }
    catch (...) {
        API::get()->log_error("[tutorial_messages][apply_popup_size] Exception");
    }
}

SDK::UCanvasPanelSlot* TutorialMessages::canvas_slot_of(SDK::UWidget* widget) {
    if (widget == nullptr || widget->Slot == nullptr || !widget->Slot->IsA(SDK::UCanvasPanelSlot::StaticClass())) return nullptr;
    return static_cast<SDK::UCanvasPanelSlot*>(widget->Slot);
}

std::wstring TutorialMessages::to_wide(const std::string& utf8) {
    if (utf8.empty()) return {};
    const int length = MultiByteToWideChar(CP_UTF8, 0, utf8.data(), static_cast<int>(utf8.size()), nullptr, 0);
    std::wstring wide(static_cast<size_t>(length), L'\0');
    MultiByteToWideChar(CP_UTF8, 0, utf8.data(), static_cast<int>(utf8.size()), wide.data(), length);
    return wide;
}
