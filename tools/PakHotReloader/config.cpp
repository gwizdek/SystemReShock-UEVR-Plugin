#include <windows.h>

#include <fstream>
#include <sstream>

#include "uevr/API.hpp"
#include "mINI/ini.h"
#include "config.hpp"

using namespace uevr;

namespace pak_hot_reload {
namespace {

constexpr const char* kDefaultIni =
    "; PakHotReloader settings. Edit, then reload the PakHotReloader plugin in the UEVR overlay.\n"
    "\n"
    "[paks]\n"
    "; Pak files to copy and mount when the hotkey is pressed. Separate several files with ';'.\n"
    "; Later files are mounted above earlier ones.\n"
    "files = D:\\Unreal Engine\\Projects\\SystemReShock-UE4-Project\\WindowsNoEditor\\SystemShock\\Content\\Paks\\pakchunk10-WindowsNoEditor.pak\n"
    "\n"
    "[hotkey]\n"
    "; Virtual-key code in hex. 0x78 = F9, 0x79 = F10, 0x7A = F11.\n"
    "key = 0x78\n"
    "\n"
    "[load]\n"
    "; What to do after mounting: none, quick (QuickLoad), auto (AutoLoad), manual (ManualLoad with save_name).\n"
    "mode = none\n"
    "save_name =\n"
    "\n"
    "[diagnostics]\n"
    "; Files as the engine names them, separated by ';'. Each is checked before and after a mount.\n"
    "; Include one base-game file as a control. Leave empty to skip.\n"
    "probe_files = ../../../SystemShock/Content/Mods/VRBody/_BP_VRBody.uasset;../../../SystemShock/Content/Mods/VRBody/_BP_VRBody.uexp;../../../SystemShock/Content/Blueprints/Game/GI_SinglePlayer.uasset\n"
    "; Packages under this prefix that are still in memory are listed before and after the\n"
    "; garbage collection that runs ahead of the mount, together with live instances of their\n"
    "; classes. A loaded package is not read from the new pak. Leave empty to skip.\n"
    "loaded_prefix = /Game/Mods/\n";

constexpr const char* kDefaultProbeFiles =
    "../../../SystemShock/Content/Mods/VRBody/_BP_VRBody.uasset;"
    "../../../SystemShock/Content/Mods/VRBody/_BP_VRBody.uexp;"
    "../../../SystemShock/Content/Blueprints/Game/GI_SinglePlayer.uasset";
constexpr const char* kDefaultLoadedPrefix = "/Game/Mods/";

// Value of `key` in `section`, or `fallback` when the file does not have it.
std::string value_or(mINI::INIStructure& ini, const char* section, const char* key, const char* fallback) {
    if (ini.has(section) && ini[section].has(key)) return ini[section][key];
    return fallback;
}

bool write_default(const std::filesystem::path& file) {
    std::ofstream out(file);
    out << kDefaultIni;
    return static_cast<bool>(out);
}

std::string trim(const std::string& s) {
    const auto first = s.find_first_not_of(" \t\r\n");
    if (first == std::string::npos) return {};
    const auto last = s.find_last_not_of(" \t\r\n");
    return s.substr(first, last - first + 1);
}

std::vector<std::filesystem::path> split_paths(const std::string& list) {
    std::vector<std::filesystem::path> paths;
    std::stringstream stream(list);
    std::string item;
    while (std::getline(stream, item, ';')) {
        const auto trimmed = trim(item);
        if (!trimmed.empty()) paths.emplace_back(trimmed);
    }
    return paths;
}

LoadMode parse_mode(const std::string& value) {
    const auto mode = trim(value);
    if (mode == "quick") return LoadMode::Quick;
    if (mode == "auto") return LoadMode::Auto;
    if (mode == "manual") return LoadMode::Manual;
    return LoadMode::None;
}

int parse_key(const std::string& value) {
    try {
        return std::stoi(trim(value), nullptr, 0);
    } catch (...) {
        API::get()->log_warn("[config][parse_key] bad key \"%s\", using F9", value.c_str());
        return VK_F9;
    }
}

std::wstring widen(const std::string& narrow) {
    if (narrow.empty()) return {};
    const int size = MultiByteToWideChar(CP_ACP, 0, narrow.c_str(), -1, nullptr, 0);
    std::wstring wide(static_cast<size_t>(size), L'\0');
    MultiByteToWideChar(CP_ACP, 0, narrow.c_str(), -1, wide.data(), size);
    wide.resize(static_cast<size_t>(size) - 1);
    return wide;
}

} // namespace

std::optional<Config> load_config(const std::filesystem::path& file) {
    if (!std::filesystem::exists(file)) {
        const bool written = write_default(file);
        API::get()->log_warn("[config][load_config] %s default settings file %ls", written ? "wrote" : "could not write", file.c_str());
    }
    mINI::INIFile ini_file(file.string());
    mINI::INIStructure ini;
    if (!ini_file.read(ini)) {
        API::get()->log_error("[config][load_config] cannot read %ls", file.c_str());
        return std::nullopt;
    }
    Config config;
    config.paks = split_paths(ini["paks"]["files"]);
    config.hotkey = parse_key(ini["hotkey"]["key"]);
    config.load_mode = parse_mode(ini["load"]["mode"]);
    config.save_name = widen(trim(ini["load"]["save_name"]));
    // Older ini files have no [diagnostics] section; use the defaults then. An empty value switches a check off.
    for (const auto& probe : split_paths(value_or(ini, "diagnostics", "probe_files", kDefaultProbeFiles))) {
        config.probe_files.push_back(probe.wstring());
    }
    config.loaded_prefix = widen(trim(value_or(ini, "diagnostics", "loaded_prefix", kDefaultLoadedPrefix)));
    return config;
}

const char* load_mode_name(LoadMode mode) {
    switch (mode) {
    case LoadMode::Quick: return "quick";
    case LoadMode::Auto: return "auto";
    case LoadMode::Manual: return "manual";
    default: return "none";
    }
}

} // namespace pak_hot_reload
