#pragma once

#include <string>

// The mod's settings file, system_reshock_vr_config.ini in the UEVR profile folder. The values
// the VR options page manages live in [general], [movement] and [cyberspace], keyed by the row's
// SettingName. The menu recenter keys in [general] have no row; they are set in the file only.
// The file is read once on first use. save() writes the changed values back and keeps
// everything else in the file as it is.
class VRSettings final
{
public:
    static constexpr const char* kGeneral = "general";
    static constexpr const char* kMovement = "movement";
    static constexpr const char* kCyberspace = "cyberspace";

    static bool has(const std::string& section, const std::string& key);
    static std::string get(const std::string& section, const std::string& key, const std::string& fallback);
    static int get_int(const std::string& section, const std::string& key, int fallback);
    static float get_float(const std::string& section, const std::string& key, float fallback);
    static bool get_bool(const std::string& section, const std::string& key, bool fallback);

    // Changes the value in memory only. save() writes the file.
    static void set(const std::string& section, const std::string& key, const std::string& value);
    static bool save();

    // The values the plugin acts on, with their limits applied.
    static int look_sensitivity();      // [movement] 1..10, default 5
    static float player_height();       // [general] 165..185 cm, default 175
    static bool auto_ads();             // [general] default on
    static float menu_recenter_angle();    // [general] 5..90 degrees, default 25
    static float menu_recenter_delay();    // [general] 0..10 seconds, default 2.5
    static float menu_recenter_duration(); // [general] 0..5 seconds, default 0.1
    static bool pitch_snap_turn();      // [cyberspace] default on
    static float pitch_deadzone();      // [cyberspace] 0..1, default 0.75
    static float pitch_snap_duration(); // [cyberspace] 0..1 seconds, default 0.7
    static int crosshair_scale();       // [cyberspace] 50..150 percent, default 100
};
