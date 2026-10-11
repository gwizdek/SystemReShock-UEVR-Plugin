#include "vr_setting_store.hpp"

#include <cstdio>

#include "uevr/API.hpp"
#include "vr_settings.hpp"

using namespace uevr;

namespace {

// "5" for a whole number, "0.2" otherwise: what a person expects to read in a config file,
// and what UEVR's integer settings accept.
std::string format_number(float value) {
    char text[32]{};
    snprintf(text, sizeof(text), "%g", value);
    return text;
}

} // anonymous namespace

// -------------------------------------------------------------------------------------
// IniSectionStore
// -------------------------------------------------------------------------------------

std::optional<float> IniSectionStore::get_float(const std::string& key) const {
    if (!VRSettings::has(m_section, key)) return std::nullopt;
    return VRSettings::get_float(m_section, key, 0.f);
}

std::optional<bool> IniSectionStore::get_bool(const std::string& key) const {
    if (!VRSettings::has(m_section, key)) return std::nullopt;
    return VRSettings::get_bool(m_section, key, false);
}

void IniSectionStore::set_float(const std::string& key, float value) {
    VRSettings::set(m_section, key, format_number(value));
    m_changed = true;
}

void IniSectionStore::set_bool(const std::string& key, bool value) {
    VRSettings::set(m_section, key, value ? "1" : "0");
    m_changed = true;
}

void IniSectionStore::save_if_changed() {
    if (!m_changed) return;
    m_changed = false;
    if (VRSettings::save()) {
        API::get()->log_warn("[vr_setting_store][IniSectionStore::save_if_changed] [%s] saved", m_section);
    }
}

// -------------------------------------------------------------------------------------
// UevrSettingStore
// -------------------------------------------------------------------------------------
// UEVR returns every value as text: "50", "0.203000", "true". An unknown key returns "".
// Values are written as text through the raw function: the API.hpp template set_mod_value
// does not compile for strings.

namespace {

void set_uevr_value(const std::string& key, const std::string& value) {
    API::get()->param()->vr->set_mod_value(key.c_str(), value.c_str());
}

} // anonymous namespace

std::optional<float> UevrSettingStore::get_float(const std::string& key) const {
    const std::string text = API::VR::get_mod_value<std::string>(key);
    if (text.empty()) return std::nullopt;
    try {
        return std::stof(text);
    }
    catch (...) {
        API::get()->log_error("[vr_setting_store][UevrSettingStore::get_float] %s is not a number: %s", key.c_str(), text.c_str());
        return std::nullopt;
    }
}

std::optional<bool> UevrSettingStore::get_bool(const std::string& key) const {
    const std::string text = API::VR::get_mod_value<std::string>(key);
    if (text.empty()) return std::nullopt;
    return text == "true";
}

void UevrSettingStore::set_float(const std::string& key, float value) {
    set_uevr_value(key, format_number(value));
    m_changed = true;
}

void UevrSettingStore::set_bool(const std::string& key, bool value) {
    set_uevr_value(key, value ? "true" : "false");
    m_changed = true;
}

void UevrSettingStore::save_if_changed() {
    if (!m_changed) return;
    m_changed = false;
    API::VR::save_config();
    API::get()->log_warn("[vr_setting_store][UevrSettingStore::save_if_changed] UEVR config saved");
}
