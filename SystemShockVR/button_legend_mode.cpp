#include "button_legend_mode.hpp"

#include "uevr/API.hpp"
#include "SDK/Engine_classes.hpp"
#include "SDK/CON_Hacker_classes.hpp"
#include "SDK/ENUM_ControllerType_structs.hpp"
#include "SDK/WIDGET_ButtonLegend_Key_classes.hpp"
#include "SDK/WIDGET_ButtonLegend_KeyComposite_classes.hpp"
#include "plugin_utils.hpp"

using namespace uevr;

namespace {

constexpr const wchar_t* kComposite = L"Function /Game/Blueprints/UI/HUD/Widgets/ButtonLegend/WIDGET_ButtonLegend_KeyComposite.WIDGET_ButtonLegend_KeyComposite_C.";
constexpr const wchar_t* kKey = L"Function /Game/Blueprints/UI/HUD/Widgets/ButtonLegend/WIDGET_ButtonLegend_Key.WIDGET_ButtonLegend_Key_C.";

// The functions during which the widgets read CON_Hacker.ActiveControllerType. Only functions
// the engine enters through ProcessEvent can be hooked: GetDecoratorSizeFromPayload is called
// by the text mesh, Construct and PreConstruct by the widget system. The initialize functions
// that do the actual read run from Construct through an internal Blueprint call, which the
// hook does not see, so the events are hooked instead.
const std::wstring kHookedFunctions[] = {
    std::wstring(kComposite) + L"GetDecoratorSizeFromPayload",
    std::wstring(kComposite) + L"Construct",
    std::wstring(kComposite) + L"PreConstruct",
    std::wstring(kKey) + L"GetDecoratorSizeFromPayload",
    std::wstring(kKey) + L"Construct",
    std::wstring(kKey) + L"PreConstruct",
};

// Ticks between two attempts to find the functions. The classes load with the HUD.
constexpr int kRetryTicks = 120;

// How many hook calls are written to the log after the plugin starts.
constexpr int kLoggedCalls = 12;

constexpr uint8_t kGamepad = static_cast<uint8_t>(SDK::ENUM_ControllerType::NewEnumerator1);

} // anonymous namespace

SDK::UWorld* ButtonLegendMode::s_world{ nullptr };
bool ButtonLegendMode::s_installed{ false };
int ButtonLegendMode::s_ticks_until_retry{ 0 };
int ButtonLegendMode::s_depth{ 0 };
uint8_t ButtonLegendMode::s_saved_type{ 0 };

void ButtonLegendMode::handle(SDK::UWorld* world) {
    s_world = world;
    if (s_installed || world == nullptr) return;
    if (--s_ticks_until_retry > 0) return;
    s_ticks_until_retry = kRetryTicks;
    try_install();
}

void ButtonLegendMode::try_install() {
    try {
        for (const auto& name : kHookedFunctions) {
            if (API::get()->find_uobject<API::UFunction>(name) == nullptr) return;   // not loaded yet
        }
        for (const auto& name : kHookedFunctions) {
            if (!install_hook(name.c_str())) return;
        }
        s_installed = true;
        API::get()->log_warn("[button_legend_mode][try_install] Hooked the key widgets; text decorators now read gamepad mode");
    }
    catch (...) {
        API::get()->log_error("[button_legend_mode][try_install] Exception");
    }
}

bool ButtonLegendMode::install_hook(const wchar_t* function_name) {
    auto* function = API::get()->find_uobject<API::UFunction>(function_name);
    if (function == nullptr) {
        API::get()->log_error("[button_legend_mode][install_hook] %ls not found", function_name);
        return false;
    }
    const bool ok = function->hook_ptr(
        reinterpret_cast<API::UFunction::UEVR_UFunction_CPPPreNative>(&on_pre),
        reinterpret_cast<API::UFunction::UEVR_UFunction_CPPPostNative>(&on_post));
    if (!ok) {
        API::get()->log_error("[button_legend_mode][install_hook] hook_ptr failed for %ls", function_name);
    }
    return ok;
}

bool ButtonLegendMode::on_pre(void* function, void* obj, void*, void*) {
    try {
        const bool decorator = is_text_decorator(obj);
        auto* hacker = controller(obj);
        log_call("on_pre", function, obj, decorator, hacker);
        if (!decorator || hacker == nullptr) return true;
        if (s_depth == 0) {
            s_saved_type = static_cast<uint8_t>(hacker->ActiveControllerType);
            hacker->ActiveControllerType = static_cast<SDK::ENUM_ControllerType>(kGamepad);
        }
        ++s_depth;
    }
    catch (...) {
        API::get()->log_error("[button_legend_mode][on_pre] Exception");
    }
    return true;
}

// Logs the first calls of the hooks, so the log shows whether they run and what they see.
void ButtonLegendMode::log_call(const char* where, void* function, void* obj, bool decorator, const void* hacker) {
    static int logged = 0;
    if (logged >= kLoggedCalls) return;
    ++logged;
    auto* fn = static_cast<API::UFunction*>(function);
    auto* object = static_cast<API::UObject*>(obj);
    const std::wstring fn_name = fn != nullptr ? fn->get_fname()->to_string() : L"?";
    const std::wstring obj_name = object != nullptr ? object->get_full_name() : L"?";
    const int type = hacker != nullptr ? static_cast<int>(static_cast<const SDK::ACON_Hacker_C*>(hacker)->ActiveControllerType) : -1;
    API::get()->log_warn("[button_legend_mode][%s] %ls on %ls decorator=%d controller=%p type=%d depth=%d",
        where, fn_name.c_str(), obj_name.c_str(), decorator ? 1 : 0, hacker, type, s_depth);
}

bool ButtonLegendMode::on_post(void* function, void* obj, void*, void*) {
    try {
        if (!is_text_decorator(obj) || s_depth == 0) return true;
        if (--s_depth > 0) return true;
        auto* hacker = controller(obj);
        log_call("on_post", function, obj, true, hacker);
        if (hacker != nullptr) {
            hacker->ActiveControllerType = static_cast<SDK::ENUM_ControllerType>(s_saved_type);
        }
    }
    catch (...) {
        API::get()->log_error("[button_legend_mode][on_post] Exception");
    }
    return true;
}

// A key widget that a TextMeshWidget created: a composite or key widget whose outer is the
// game instance, or a key widget inside such a composite. Menu legends keep their key widgets
// in a widget tree, so they are left alone.
bool ButtonLegendMode::is_text_decorator(const void* widget) {
    const auto* object = static_cast<const SDK::UObject*>(widget);
    for (int i = 0; object != nullptr && i < 4; ++i, object = object->Outer) {
        const bool is_key_widget = PluginUtils::is_a<SDK::UWIDGET_ButtonLegend_KeyComposite_C>(object)
            || PluginUtils::is_a<SDK::UWIDGET_ButtonLegend_Key_C>(object);
        if (is_key_widget && PluginUtils::is_a<SDK::UGameInstance>(object->Outer)) return true;
    }
    return false;
}

SDK::ACON_Hacker_C* ButtonLegendMode::controller(void* widget) {
    // The same lookup the widget makes: GetPlayerController with itself as world context.
    SDK::UObject* context = widget != nullptr ? static_cast<SDK::UObject*>(widget) : s_world;
    if (context == nullptr) return nullptr;
    SDK::APlayerController* player = SDK::UGameplayStatics::GetPlayerController(context, 0);
    if (!PluginUtils::is_a<SDK::ACON_Hacker_C>(player)) return nullptr;
    return static_cast<SDK::ACON_Hacker_C*>(player);
}
