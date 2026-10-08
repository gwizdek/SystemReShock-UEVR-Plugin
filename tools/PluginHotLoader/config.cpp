#include <windows.h>

#include <fstream>
#include <string>

#include "uevr/API.hpp"
#include "mINI/ini.h"
#include "config.hpp"

using namespace uevr;

namespace plugin_hot_load {
namespace {

constexpr const char* kDefaultIniHead =
    "; PluginHotLoader settings. Edit, then reload the PluginHotLoader plugin in the UEVR overlay.\n"
    "\n"
    "[plugin]\n"
    "; The plugin DLL to load and watch. The loader loads a copy, so this file is never locked\n"
    "; and can be overwritten while the game runs. The loader swaps to the new file by itself.\n"
    "file = ";

constexpr const char* kDefaultIniTail =
    "\n"
    "\n"
    "[watch]\n"
    "; How often the file is checked, in milliseconds.\n"
    "poll_ms = 500\n"
    "; How long a new write time must stay unchanged before the swap, in milliseconds.\n"
    "settle_ms = 1000\n";

std::string narrow(const std::wstring& wide) {
    std::string out;
    out.reserve(wide.size());
    for (const wchar_t c : wide) out.push_back(c < 128 ? static_cast<char>(c) : '?');
    return out;
}

std::string trim(const std::string& s) {
    const auto first = s.find_first_not_of(" \t\r\n");
    if (first == std::string::npos) return {};
    const auto last = s.find_last_not_of(" \t\r\n");
    return s.substr(first, last - first + 1);
}

int int_or(const std::string& value, int fallback, const char* key) {
    try {
        return std::stoi(trim(value));
    } catch (...) {
        API::get()->log_warn("[config][int_or] bad %s \"%s\", using %d", key, value.c_str(), fallback);
        return fallback;
    }
}

bool write_default(const std::filesystem::path& file, const std::filesystem::path& default_plugin_file) {
    std::ofstream out(file);
    out << kDefaultIniHead << default_plugin_file.string() << kDefaultIniTail;
    return static_cast<bool>(out);
}

} // namespace

std::optional<Config> load_config(const std::filesystem::path& file, const std::filesystem::path& default_plugin_file) {
    if (!std::filesystem::exists(file)) {
        const bool written = write_default(file, default_plugin_file);
        API::get()->log_warn("[config][load_config] %s default settings file %s", written ? "wrote" : "could not write", narrow(file.wstring()).c_str());
    }
    mINI::INIFile ini_file(file.string());
    mINI::INIStructure ini;
    if (!ini_file.read(ini)) {
        API::get()->log_error("[config][load_config] cannot read %s", narrow(file.wstring()).c_str());
        return std::nullopt;
    }
    Config config;
    const std::string plugin_file = trim(ini["plugin"]["file"]);
    config.plugin_file = plugin_file.empty() ? default_plugin_file : std::filesystem::path(plugin_file);
    config.poll_ms = int_or(ini["watch"]["poll_ms"], config.poll_ms, "poll_ms");
    config.settle_ms = int_or(ini["watch"]["settle_ms"], config.settle_ms, "settle_ms");
    return config;
}

} // namespace plugin_hot_load
