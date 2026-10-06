#include <cstdint>

#include "uevr/API.hpp"
#include "save_loader.hpp"

using namespace uevr;

namespace pak_hot_reload {
namespace {

// Memory layout of an FString parameter: TArray<TCHAR> with data, count and capacity.
struct FStringParam {
    const wchar_t* data;
    int32_t num;
    int32_t max;
};

struct UserIndexParams {
    int32_t user_index;
};

struct ManualLoadParams {
    FStringParam save_name;
    int32_t user_index;
};

API::UObject* game_instance() {
    auto* engine = API::get()->get_engine();
    if (engine == nullptr) return nullptr;
    auto** slot = engine->get_property_data<API::UObject*>(L"GameInstance");
    return slot != nullptr ? *slot : nullptr;
}

bool call_if_present(API::UObject* instance, std::wstring_view function, void* params) {
    if (instance->get_class()->find_function(function) == nullptr) {
        API::get()->log_error("[save_loader][call_if_present] %ls has no function %ls", instance->get_full_name().c_str(), function.data());
        return false;
    }
    instance->call_function(function, params);
    API::get()->log_warn("[save_loader][call_if_present] called %ls", function.data());
    return true;
}

bool call_manual_load(API::UObject* instance, const std::wstring& save_name) {
    if (save_name.empty()) {
        API::get()->log_error("[save_loader][call_manual_load] load mode is manual but save_name is empty");
        return false;
    }
    const auto count = static_cast<int32_t>(save_name.size() + 1);
    ManualLoadParams params{{save_name.c_str(), count, count}, 0};
    return call_if_present(instance, L"ManualLoad", &params);
}

} // namespace

bool load_save(LoadMode mode, const std::wstring& save_name) {
    if (mode == LoadMode::None) return true;
    auto* instance = game_instance();
    if (instance == nullptr) {
        API::get()->log_error("[save_loader][load_save] no GameInstance");
        return false;
    }
    UserIndexParams user{0};
    switch (mode) {
    case LoadMode::Quick: return call_if_present(instance, L"QuickLoad", &user);
    case LoadMode::Auto: return call_if_present(instance, L"AutoLoad", &user);
    case LoadMode::Manual: return call_manual_load(instance, save_name);
    default: return false;
    }
}

} // namespace pak_hot_reload
