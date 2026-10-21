#include "roomscale_sweep_setting.hpp"

#include <filesystem>
#include <fstream>
#include <string>

#include "uevr/API.hpp"

using namespace uevr;

namespace {

constexpr const char* kSweepKey = "VR_RoomscaleMovementSweep";
constexpr const wchar_t* kSavedFileName = L"cyberspace_saved_sweep.txt";

std::filesystem::path saved_file() {
    return API::get()->get_persistent_dir(kSavedFileName);
}

std::string read_current_value() {
    char value[32]{};
    API::get()->param()->vr->get_mod_value(kSweepKey, value, sizeof(value));
    return value;
}

} // namespace

void RoomscaleSweepSetting::disable_for_cyberspace() {
    try {
        const auto path = saved_file();
        if (!std::filesystem::exists(path)) {
            const std::string current = read_current_value();
            std::ofstream(path, std::ios::trunc) << current;
            API::get()->log_warn("[roomscale_sweep_setting][disable_for_cyberspace] Saved sweep %s", current.c_str());
        }
        API::get()->param()->vr->set_mod_value(kSweepKey, "false");
        API::get()->log_warn("[roomscale_sweep_setting][disable_for_cyberspace] Sweep off in cyberspace");
    }
    catch (...) {
        API::get()->log_error("[roomscale_sweep_setting][disable_for_cyberspace] Exception");
    }
}

void RoomscaleSweepSetting::restore() {
    try {
        const auto path = saved_file();
        if (!std::filesystem::exists(path)) {
            return;
        }
        std::string saved{};
        std::ifstream(path) >> saved;
        if (saved == "true" || saved == "false") {
            API::get()->param()->vr->set_mod_value(kSweepKey, saved.c_str());
            API::get()->log_warn("[roomscale_sweep_setting][restore] Sweep restored to %s", saved.c_str());
        }
        else {
            API::get()->log_error("[roomscale_sweep_setting][restore] Saved value '%s' is not true or false, sweep left as it is", saved.c_str());
        }
        std::filesystem::remove(path);
    }
    catch (...) {
        API::get()->log_error("[roomscale_sweep_setting][restore] Exception");
    }
}
