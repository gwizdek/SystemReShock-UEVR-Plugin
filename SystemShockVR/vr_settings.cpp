#include "vr_settings.hpp"

#include <algorithm>
#include <filesystem>

#include "uevr/API.hpp"
#include "mINI/ini.h"

using namespace uevr;

namespace {

constexpr const wchar_t* kFileName = L"system_reshock_vr_config.ini";
constexpr const char* kSection = "general";

struct Store
{
    std::string path;
    mINI::INIStructure ini;
};

Store& store()
{
    static Store value = [] {
        Store s;
        s.path = API::get()->get_persistent_dir(kFileName).string();
        mINI::INIFile file(s.path);
        if (!file.read(s.ini)) {
            API::get()->log_warn("[vr_settings][store] %s not found or unreadable, defaults apply until the first save", s.path.c_str());
        }
        return s;
    }();
    return value;
}

} // anonymous namespace

bool VRSettings::has(const std::string& key)
{
    const mINI::INIStructure& ini = store().ini;
    return ini.has(kSection) && ini.get(kSection).has(key);
}

std::string VRSettings::get(const std::string& key, const std::string& fallback)
{
    return has(key) ? store().ini.get(kSection).get(key) : fallback;
}

int VRSettings::get_int(const std::string& key, int fallback)
{
    try {
        return has(key) ? std::stoi(get(key, "")) : fallback;
    }
    catch (...) {
        API::get()->log_error("[vr_settings][get_int] [%s] %s is not a number, using %d", kSection, key.c_str(), fallback);
        return fallback;
    }
}

float VRSettings::get_float(const std::string& key, float fallback)
{
    try {
        return has(key) ? std::stof(get(key, "")) : fallback;
    }
    catch (...) {
        API::get()->log_error("[vr_settings][get_float] [%s] %s is not a number, using %g", kSection, key.c_str(), fallback);
        return fallback;
    }
}

bool VRSettings::get_bool(const std::string& key, bool fallback)
{
    if (!has(key)) return fallback;
    const std::string value = get(key, "");
    return value == "1" || value == "true";
}

void VRSettings::set(const std::string& key, const std::string& value)
{
    store().ini[kSection][key] = value;
}

// write() keeps the file's other sections, keys, comments and order; a missing file is created.
bool VRSettings::save()
{
    Store& s = store();
    mINI::INIFile file(s.path);
    if (!file.write(s.ini, true)) {
        API::get()->log_error("[vr_settings][save] cannot write %s", s.path.c_str());
        return false;
    }
    return true;
}

int VRSettings::look_sensitivity()
{
    return std::clamp(get_int("vr_look_sensitivity", 5), 1, 10);
}

float VRSettings::player_height()
{
    return std::clamp(get_float("player_height", 175.f), 165.f, 185.f);
}
