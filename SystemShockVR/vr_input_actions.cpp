#include "vr_input_actions.hpp"

#include <string>

#include "uevr/API.hpp"
#include "SDK/Engine_classes.hpp"

using namespace uevr;

namespace {

struct VRAction
{
    const wchar_t* name;
    const wchar_t* key;
};

// One entry per VR button the plugin reads itself. The key is the gamepad key UEVR sends for
// that button; it only decides which icon the legend widget draws.
constexpr VRAction kActions[] = {
    { L"VR_LeftGrip",     L"Gamepad_LeftShoulder" },
    { L"VR_RightGrip",    L"Gamepad_RightShoulder" },
    { L"VR_LeftThumb",    L"Gamepad_LeftThumbstick" },
    { L"VR_RightThumb",   L"Gamepad_RightThumbstick" },
    { L"VR_RightTrigger", L"Gamepad_RightTrigger" },
};

// The legend widget adds these to a placeholder's name for controller types 1 and 2.
constexpr const wchar_t* kPrefixes[] = { L"", L"Gamepad_", L"JCMS_" };

} // anonymous namespace

bool VRInputActions::s_done{ false };

void VRInputActions::handle() {
    if (s_done) return;
    try {
        s_done = register_all();
    }
    catch (...) {
        API::get()->log_error("[vr_input_actions][handle] Exception");
        s_done = true;
    }
}

bool VRInputActions::register_all() {
    SDK::UInputSettings* settings = SDK::UInputSettings::GetInputSettings();
    if (settings == nullptr) {
        API::get()->log_warn("[vr_input_actions][register_all] No UInputSettings yet, retrying");
        return false;
    }
    int added = 0;
    for (const VRAction& action : kActions) {
        for (const wchar_t* prefix : kPrefixes) {
            const std::wstring name = std::wstring(prefix) + action.name;
            if (add_mapping(name.c_str(), action.key)) ++added;
        }
    }
    API::get()->log_warn("[vr_input_actions][register_all] Added %d VR action mappings", added);
    return true;
}

// Adds the mapping unless a mapping with that name exists already, which is the case after the
// hot loader swapped the plugin in a running game.
bool VRInputActions::add_mapping(const wchar_t* action_name, const wchar_t* key_name) {
    SDK::UInputSettings* settings = SDK::UInputSettings::GetInputSettings();
    const SDK::FName name = SDK::UKismetStringLibrary::Conv_StringToName(action_name);

    SDK::TArray<SDK::FInputActionKeyMapping> existing;
    settings->GetActionMappingByName(name, &existing);
    if (existing.Num() > 0) return false;

    SDK::FInputActionKeyMapping mapping{};
    mapping.ActionName = name;
    mapping.Key.KeyName = SDK::UKismetStringLibrary::Conv_StringToName(key_name);
    settings->AddActionMapping(mapping, /*bForceRebuildKeymaps=*/ false);
    return true;
}
