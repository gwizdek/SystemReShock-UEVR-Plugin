#include "vr_settings.hpp"

#include <algorithm>
#include <cmath>
#include <filesystem>

#include "uevr/API.hpp"
#include "mINI/ini.h"

using namespace uevr;

namespace {

constexpr const wchar_t* kFileName = L"system_reshock_vr_config.ini";

struct Store
{
    std::string path;
    mINI::INIStructure ini;
};

// Keys that plugin versions before the [movement] section kept in [general].
struct MovedKey
{
    const char* key;
    const char* section;
};

constexpr MovedKey kMovedKeys[] = {
    { "vr_look_sensitivity", VRSettings::kMovement },
};

// Moves each old [general] key into its section. The old value is kept only when the section
// has no value of its own. The old key is removed either way. Returns true when a key moved.
bool move_old_keys(mINI::INIStructure& ini)
{
    bool moved_any = false;
    for (const MovedKey& moved : kMovedKeys) {
        if (!ini.has(VRSettings::kGeneral) || !ini.get(VRSettings::kGeneral).has(moved.key)) continue;
        const std::string value = ini.get(VRSettings::kGeneral).get(moved.key);
        if (!ini.has(moved.section) || !ini.get(moved.section).has(moved.key)) ini[moved.section][moved.key] = value;
        ini[VRSettings::kGeneral].remove(moved.key);
        API::get()->log_warn("[vr_settings][move_old_keys] [general] %s moved to [%s]", moved.key, moved.section);
        moved_any = true;
    }
    return moved_any;
}

// Keys with no row on the VR options page. Nothing else writes them, so they are added with
// their default when missing, to be found and changed in the file.
struct FileOnlyKey
{
    const char* section;
    const char* key;
    const char* value;
};

constexpr FileOnlyKey kFileOnlyKeys[] = {
    { VRSettings::kGeneral, "menu_recenter_angle", "25" },
    { VRSettings::kGeneral, "menu_recenter_delay", "2.5" },
    { VRSettings::kGeneral, "menu_recenter_duration", "0.1" },
};

// Returns true when a key was added.
bool add_file_only_keys(mINI::INIStructure& ini)
{
    bool added_any = false;
    for (const FileOnlyKey& entry : kFileOnlyKeys) {
        if (ini.has(entry.section) && ini.get(entry.section).has(entry.key)) continue;
        ini[entry.section][entry.key] = entry.value;
        API::get()->log_warn("[vr_settings][add_file_only_keys] [%s] %s = %s added", entry.section, entry.key, entry.value);
        added_any = true;
    }
    return added_any;
}

Store& store()
{
    static Store value = [] {
        Store s;
        s.path = API::get()->get_persistent_dir(kFileName).string();
        mINI::INIFile file(s.path);
        if (!file.read(s.ini)) {
            API::get()->log_warn("[vr_settings][store] %s not found or unreadable, defaults apply until the first save", s.path.c_str());
            return s;
        }
        const bool moved = move_old_keys(s.ini);
        const bool added = add_file_only_keys(s.ini);
        if ((moved || added) && !file.write(s.ini, true)) {
            API::get()->log_error("[vr_settings][store] cannot write %s after moving or adding keys", s.path.c_str());
        }
        return s;
    }();
    return value;
}

} // anonymous namespace

bool VRSettings::has(const std::string& section, const std::string& key)
{
    const mINI::INIStructure& ini = store().ini;
    return ini.has(section) && ini.get(section).has(key);
}

std::string VRSettings::get(const std::string& section, const std::string& key, const std::string& fallback)
{
    return has(section, key) ? store().ini.get(section).get(key) : fallback;
}

int VRSettings::get_int(const std::string& section, const std::string& key, int fallback)
{
    try {
        return has(section, key) ? std::stoi(get(section, key, "")) : fallback;
    }
    catch (...) {
        API::get()->log_error("[vr_settings][get_int] [%s] %s is not a number, using %d", section.c_str(), key.c_str(), fallback);
        return fallback;
    }
}

float VRSettings::get_float(const std::string& section, const std::string& key, float fallback)
{
    try {
        return has(section, key) ? std::stof(get(section, key, "")) : fallback;
    }
    catch (...) {
        API::get()->log_error("[vr_settings][get_float] [%s] %s is not a number, using %g", section.c_str(), key.c_str(), fallback);
        return fallback;
    }
}

bool VRSettings::get_bool(const std::string& section, const std::string& key, bool fallback)
{
    if (!has(section, key)) return fallback;
    const std::string value = get(section, key, "");
    return value == "1" || value == "true";
}

void VRSettings::set(const std::string& section, const std::string& key, const std::string& value)
{
    store().ini[section][key] = value;
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
    return std::clamp(get_int(kMovement, "vr_look_sensitivity", 5), 1, 10);
}

float VRSettings::player_height()
{
    return std::clamp(get_float(kGeneral, "player_height", 175.f), 165.f, 185.f);
}

bool VRSettings::auto_ads()
{
    return get_bool(kGeneral, "auto_ads", true);
}

float VRSettings::menu_recenter_angle()
{
    return std::clamp(get_float(kGeneral, "menu_recenter_angle", 25.f), 5.f, 90.f);
}

float VRSettings::menu_recenter_delay()
{
    return std::clamp(get_float(kGeneral, "menu_recenter_delay", 2.5f), 0.f, 10.f);
}

float VRSettings::menu_recenter_duration()
{
    return std::clamp(get_float(kGeneral, "menu_recenter_duration", 0.1f), 0.f, 5.f);
}

bool VRSettings::pitch_snap_turn()
{
    return get_bool(kCyberspace, "pitch_snap_turn", true);
}

float VRSettings::pitch_deadzone()
{
    return std::clamp(get_float(kCyberspace, "pitch_deadzone", 0.75f), 0.f, 1.f);
}

float VRSettings::pitch_snap_duration()
{
    return std::clamp(get_float(kCyberspace, "pitch_snap_duration", 0.7f), 0.f, 1.f);
}

// The slider row writes a float, so the value is read as one and rounded.
int VRSettings::crosshair_scale()
{
    return std::clamp(static_cast<int>(std::lround(get_float(kCyberspace, "crosshair_scale", 100.f))), 50, 150);
}
