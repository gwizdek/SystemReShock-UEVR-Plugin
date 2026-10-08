#include <string>

#include "uevr/API.hpp"
#include "inner_plugin.hpp"

using namespace uevr;

namespace plugin_hot_load {
namespace {

constexpr const wchar_t* kStagingSuffix = L".dll";

bool ends_with(const std::wstring& text, const std::wstring& suffix) {
    return text.size() >= suffix.size() && text.compare(text.size() - suffix.size(), suffix.size(), suffix) == 0;
}

} // namespace

InnerPlugin::InnerPlugin(std::filesystem::path source, std::filesystem::path staging_dir)
    : m_source(std::move(source)), m_staging_dir(std::move(staging_dir)) {}

// The name ends in "_s<pid>_<start seconds>_<n>.dll", unique per session and per load.
std::filesystem::path InnerPlugin::next_staging_path() {
    static const auto session = std::to_wstring(GetCurrentProcessId()) + L"_" + std::to_wstring(GetTickCount64() / 1000);
    ++m_load_count;
    return m_staging_dir / (m_source.stem().wstring() + L"_s" + session + L"_" + std::to_wstring(m_load_count) + kStagingSuffix);
}

bool InnerPlugin::stage_copy(std::filesystem::path& copy) {
    std::error_code ec;
    if (!std::filesystem::is_regular_file(m_source, ec)) {
        API::get()->log_error("[inner_plugin][stage_copy] plugin file not found: %ls", m_source.c_str());
        return false;
    }
    std::filesystem::create_directories(m_staging_dir, ec);
    copy = next_staging_path();
    if (!std::filesystem::copy_file(m_source, copy, std::filesystem::copy_options::overwrite_existing, ec)) {
        API::get()->log_error("[inner_plugin][stage_copy] copy to %ls failed: %s", copy.c_str(), ec.message().c_str());
        return false;
    }
    return true;
}

bool InnerPlugin::load(const UEVR_PluginInitializeParam* param) {
    if (m_module != nullptr) {
        API::get()->log_error("[inner_plugin][load] already loaded, unload first");
        return false;
    }
    std::filesystem::path copy;
    if (!stage_copy(copy)) return false;

    HMODULE module = LoadLibraryW(copy.c_str());
    if (module == nullptr) {
        API::get()->log_error("[inner_plugin][load] LoadLibrary failed for %ls, error %lu", copy.c_str(), GetLastError());
        return false;
    }
    // The module stays recorded on failure too, so the caller can unload it after it has
    // emptied the callback slots. Freeing it here would race the forwarders.
    m_module = module;
    m_loaded_copy = copy;
    if (!check_version(module, param->version) || !initialize(module, param)) {
        return false;
    }
    API::get()->log_warn("[inner_plugin][load] loaded %ls as %ls", m_source.c_str(), copy.filename().c_str());
    return true;
}

bool InnerPlugin::check_version(HMODULE module, const UEVR_PluginVersion* host) const {
    const auto fn = reinterpret_cast<UEVR_PluginRequiredVersionFn>(GetProcAddress(module, "uevr_plugin_required_version"));
    if (fn == nullptr) {
        API::get()->log_error("[inner_plugin][check_version] no uevr_plugin_required_version export");
        return false;
    }
    UEVR_PluginVersion required{};
    fn(&required);
    API::get()->log_warn("[inner_plugin][check_version] plugin requires %d.%d.%d, UEVR is %d.%d.%d",
        required.major, required.minor, required.patch, host->major, host->minor, host->patch);
    if (required.major != host->major) {
        API::get()->log_error("[inner_plugin][check_version] different major version");
        return false;
    }
    if (required.minor > host->minor) {
        API::get()->log_error("[inner_plugin][check_version] newer minor version required");
        return false;
    }
    if (required.patch > host->patch) {
        API::get()->log_warn("[inner_plugin][check_version] newer patch version desired");
    }
    return true;
}

bool InnerPlugin::initialize(HMODULE module, const UEVR_PluginInitializeParam* param) const {
    const auto fn = reinterpret_cast<UEVR_PluginInitializeFn>(GetProcAddress(module, "uevr_plugin_initialize"));
    if (fn == nullptr) {
        API::get()->log_error("[inner_plugin][initialize] no uevr_plugin_initialize export");
        return false;
    }
    try {
        if (!fn(param)) {
            API::get()->log_error("[inner_plugin][initialize] uevr_plugin_initialize returned false");
            return false;
        }
    } catch (const std::exception& e) {
        API::get()->log_error("[inner_plugin][initialize] exception in uevr_plugin_initialize: %s", e.what());
        return false;
    } catch (...) {
        API::get()->log_error("[inner_plugin][initialize] exception in uevr_plugin_initialize (not a C++ exception, likely an access violation)");
        return false;
    }
    return true;
}

// FreeLibrary runs the plugin's static destructors. A plugin whose initialize failed half
// way may crash there; the exception is caught and the module is then left mapped.
void InnerPlugin::unload() {
    if (m_module == nullptr) return;
    const auto name = m_loaded_copy.filename().wstring();
    bool freed = false;
    try {
        freed = FreeLibrary(m_module) != FALSE;
    } catch (...) {
        API::get()->log_error("[inner_plugin][unload] exception while freeing %ls, module left mapped", name.c_str());
    }
    m_module = nullptr;
    std::error_code ec;
    if (freed) std::filesystem::remove(m_loaded_copy, ec);
    API::get()->log_warn("[inner_plugin][unload] %s %ls%s", freed ? "unloaded" : "did not free", name.c_str(), (!freed || ec) ? " (copy left on disk)" : "");
    m_loaded_copy.clear();
}

void InnerPlugin::clear_staging_dir() {
    std::error_code ec;
    if (!std::filesystem::is_directory(m_staging_dir, ec)) return;
    int removed = 0;
    for (const auto& entry : std::filesystem::directory_iterator(m_staging_dir, ec)) {
        if (!entry.is_regular_file(ec) || !ends_with(entry.path().filename().wstring(), kStagingSuffix)) continue;
        if (std::filesystem::remove(entry.path(), ec)) ++removed;
    }
    API::get()->log_warn("[inner_plugin][clear_staging_dir] removed %d old copies from %ls", removed, m_staging_dir.c_str());
}

} // namespace plugin_hot_load
