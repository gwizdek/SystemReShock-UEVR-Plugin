#include "vr_options_sync.hpp"

#include <algorithm>
#include <cmath>
#include <optional>
#include <string>

#include "uevr/API.hpp"
#include "SDK/WIDGET_MenuListBase_classes.hpp"
#include "BridgeSDK/_WIDGET_OptionsMenu_VRList_classes.hpp"
#include "BridgeSDK/_OPTION_VR_Slider_classes.hpp"
#include "BridgeSDK/_OPTION_VR_Toggle_classes.hpp"

#include "vr_setting_store.hpp"
#include "vr_settings.hpp"

using namespace SDK;
using namespace uevr;

namespace {

using List = U_WIDGET_OptionsMenu_VRList_C;

// One row of the page, the store that holds its value, and the SavedValue seen last.
template <class Row, class Value>
struct RowBinding
{
    Row*& (List::*row)();
    SettingStore* store;
    Value last;
};

using SliderBinding = RowBinding<U_OPTION_VR_Slider_C, float>;
using ToggleBinding = RowBinding<U_OPTION_VR_Toggle_C, bool>;

IniSectionStore s_general{ VRSettings::kGeneral };
IniSectionStore s_movement{ VRSettings::kMovement };
IniSectionStore s_cyberspace{ VRSettings::kCyberspace };
UevrSettingStore s_uevr;

SettingStore* const s_stores[] = { &s_general, &s_movement, &s_cyberspace, &s_uevr };

// Every row of the page and where its value lives. A new row needs one line here.
SliderBinding s_sliders[] = {
    { &List::OPTION_VR_PlayerHeight, &s_general, 0.f },
    { &List::OPTION_VR_LookSensitivity, &s_movement, 0.f },
    { &List::OPTION_VR_SnapTurnAngle, &s_uevr, 0.f },
    { &List::OPTION_VR_SnapTurnDeadzone, &s_uevr, 0.f },
    { &List::OPTION_VR_CyberPitchDeadzone, &s_cyberspace, 0.f },
    { &List::OPTION_VR_CyberPitchSnapDuration, &s_cyberspace, 0.f },
    { &List::OPTION_VR_CyberCrosshairScale, &s_cyberspace, 0.f },
};

ToggleBinding s_toggles[] = {
    { &List::OPTION_VR_AutoAimDownSights, &s_general, false },
    { &List::OPTION_VR_SnapTurn, &s_uevr, false },
    { &List::OPTION_VR_CyberPitchSnapTurn, &s_cyberspace, false },
};

template <class Fn>
void for_each_binding(Fn fn) {
    for (SliderBinding& binding : s_sliders) fn(binding);
    for (ToggleBinding& binding : s_toggles) fn(binding);
}

std::optional<float> read(const SettingStore& store, const std::string& key, float) { return store.get_float(key); }
std::optional<bool> read(const SettingStore& store, const std::string& key, bool) { return store.get_bool(key); }
void write(SettingStore& store, const std::string& key, float value) { store.set_float(key, value); }
void write(SettingStore& store, const std::string& key, bool value) { store.set_bool(key, value); }

// A value from outside the page, such as UEVR's deadzone 0.203, is put on the row's steps and
// range. Otherwise the row would count as changed as soon as the page opens, because the row
// compares against the slider position snapped to Step.
float fit(U_OPTION_VR_Slider_C* row, float value) {
    const float step = row->Step();
    if (step > 0.f) value = std::round(value / step) * step;
    return std::clamp(value, row->SliderValueMin, row->SliderValueMax);
}

bool fit(U_OPTION_VR_Toggle_C*, bool value) { return value; }

template <class Binding>
void push_row(List* list, Binding& binding) {
    auto* row = (list->*binding.row)();
    if (row == nullptr) return;
    const auto stored = read(*binding.store, row->SettingName().ToString(), binding.last);
    if (stored) row->SavedValue() = fit(row, *stored);
    row->UpdateVisuals();
    binding.last = row->SavedValue();
}

template <class Binding>
void adopt_row(List* list, Binding& binding) {
    auto* row = (list->*binding.row)();
    if (row != nullptr) binding.last = row->SavedValue();
}

// True when SavedValue changed since the last call. The new value is then in the store's memory.
template <class Binding>
bool pull_row(List* list, Binding& binding) {
    auto* row = (list->*binding.row)();
    if (row == nullptr) return false;
    const auto value = row->SavedValue();
    if (value == binding.last) return false;
    binding.last = value;
    write(*binding.store, row->SettingName().ToString(), value);
    return true;
}

List* list_of(U_WIDGET_OptionsMenu_VR_C* page) {
    List* list = page != nullptr ? page->_WIDGET_OptionsMenu_VRList() : nullptr;
    if (list == nullptr) API::get()->log_error("[vr_options_sync][list_of] Page has no list, settings not synced");
    return list;
}

} // anonymous namespace

void VROptionsSync::push(U_WIDGET_OptionsMenu_VR_C* page) {
    List* list = list_of(page);
    if (list == nullptr) return;
    for_each_binding([list](auto& binding) { push_row(list, binding); });
    // The page computed its Apply and Reset state from the old values when it opened.
    list->EVENT_OnOptionChanged();
    API::get()->log_warn("[vr_options_sync][push] Rows set from the stores, look sensitivity %d, player height %.0f, auto ADS %d",
        VRSettings::look_sensitivity(), VRSettings::player_height(), VRSettings::auto_ads() ? 1 : 0);
}

void VROptionsSync::adopt(U_WIDGET_OptionsMenu_VR_C* page) {
    List* list = list_of(page);
    if (list == nullptr) return;
    for_each_binding([list](auto& binding) { adopt_row(list, binding); });
}

bool VROptionsSync::pull(U_WIDGET_OptionsMenu_VR_C* page) {
    List* list = page != nullptr ? page->_WIDGET_OptionsMenu_VRList() : nullptr;
    if (list == nullptr) return false;
    bool changed = false;
    for_each_binding([list, &changed](auto& binding) { changed = pull_row(list, binding) || changed; });
    if (!changed) return false;
    // The values apply from memory even when a file could not be written.
    for (SettingStore* store : s_stores) store->save_if_changed();
    API::get()->log_warn("[vr_options_sync][pull] Settings applied, look sensitivity %d, player height %.0f, auto ADS %d",
        VRSettings::look_sensitivity(), VRSettings::player_height(), VRSettings::auto_ads() ? 1 : 0);
    return true;
}
