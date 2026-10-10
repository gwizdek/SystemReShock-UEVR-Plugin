#pragma once

#include <string>

// The mod's settings file, system_reshock_vr_config.ini in the UEVR profile folder. The values
// the VR options page manages live in [general], keyed by the row's SettingName. The file is
// read once on first use. save() writes the changed values back and keeps everything else in
// the file as it is.
class VRSettings final
{
public:
    static bool has(const std::string& key);
    static std::string get(const std::string& key, const std::string& fallback);
    static int get_int(const std::string& key, int fallback);
    static float get_float(const std::string& key, float fallback);
    static bool get_bool(const std::string& key, bool fallback);

    // Changes the value in memory only. save() writes the file.
    static void set(const std::string& key, const std::string& value);
    static bool save();

    // The values the plugin acts on, with their limits applied.
    static int look_sensitivity();   // 1..10, default 5
    static float player_height();    // 165..185 cm, default 175
};
