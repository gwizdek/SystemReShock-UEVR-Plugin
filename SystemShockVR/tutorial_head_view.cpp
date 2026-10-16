#include "tutorial_head_view.hpp"

#include <cstdint>
#include <cstring>

#include "uevr/API.hpp"
#include "SDK/Engine_classes.hpp"
#include "SDK/PAWN_Hacker_Simple_classes.hpp"
#include "BridgeSDK/_BP_VRBody_classes.hpp"
#include "plugin_utils.hpp"

using namespace uevr;

namespace {

constexpr const wchar_t* kPawnClass =
    L"BlueprintGeneratedClass /Game/Blueprints/Characters/Hacker/PAWN_Hacker_Simple.PAWN_Hacker_Simple_C";
constexpr const wchar_t* kFunctions[] = {
    L"Function /Game/Blueprints/Characters/Hacker/PAWN_Hacker_Simple.PAWN_Hacker_Simple_C.GetAngleToTutorialActor",
    L"Function /Game/Blueprints/Characters/Hacker/PAWN_Hacker_Simple.PAWN_Hacker_Simple_C.GetPitchYawToTutorialActor",
};
constexpr const wchar_t* kTransientPackage = L"Package /Engine/Transient";

// Ticks between two checks of the functions.
constexpr int kCheckTicks = 600;

// UStruct::Script, the bytecode of a Blueprint function, in UE 4.27: a TArray<uint8> at 0x60.
constexpr size_t kScriptOffset = 0x60;

struct ScriptArray
{
    uint8_t* data;
    int32_t num;
    int32_t max;
};

// Blueprint VM opcodes (EExprToken).
constexpr uint8_t EX_InstanceVariable = 0x01;
constexpr uint8_t EX_Context = 0x19;
constexpr uint8_t EX_ObjectConst = 0x20;

// "Context" opcode, then the object expression: its opcode and an 8 byte pointer.
constexpr int32_t kContextObjectSize = 1 + 1 + 8;

bool is_context_of(const uint8_t* p, uint8_t object_opcode, const void* pointer) {
    if (p[0] != EX_Context || p[1] != object_opcode) return false;
    return std::memcmp(p + 2, &pointer, sizeof(pointer)) == 0;
}

ScriptArray* script_of(const wchar_t* function_name) {
    auto* function = API::get()->find_uobject<API::UFunction>(function_name);
    if (function == nullptr) return nullptr;   // class not loaded yet
    auto* script = reinterpret_cast<ScriptArray*>(reinterpret_cast<uint8_t*>(function) + kScriptOffset);
    if (script->data == nullptr || script->num <= 0 || script->num > script->max) return nullptr;
    return script;
}

const void* player_camera_property() {
    auto* pawn_class = API::get()->find_uobject<API::UClass>(kPawnClass);
    return pawn_class != nullptr ? pawn_class->find_property(L"PlayerCamera") : nullptr;
}

// The component a patched function already points at, or nullptr. Used after a plugin swap.
SDK::USceneComponent* find_patched_proxy(const ScriptArray& script) {
    for (int32_t at = 0; at + kContextObjectSize <= script.num; ++at) {
        const uint8_t* p = script.data + at;
        if (p[0] != EX_Context || p[1] != EX_ObjectConst) continue;
        SDK::USceneComponent* proxy;
        std::memcpy(&proxy, p + 2, sizeof(proxy));
        return proxy;
    }
    return nullptr;
}

SDK::USceneComponent* create_proxy() {
    auto* outer = API::get()->find_uobject<SDK::UObject>(kTransientPackage);
    auto* proxy = static_cast<SDK::USceneComponent*>(SDK::UGameplayStatics::SpawnObject(SDK::USceneComponent::StaticClass(), outer));
    if (proxy == nullptr || !PluginUtils::add_to_root(proxy)) return nullptr;
    return proxy;
}

} // anonymous namespace

SDK::USceneComponent* TutorialHeadView::s_proxy{ nullptr };
bool TutorialHeadView::s_failed{ false };
int TutorialHeadView::s_ticks_until_check{ 1 };

void TutorialHeadView::handle(SDK::UWorld* world, SDK::A_BP_VRBody_C* vr_body) {
    if (s_failed) return;
    try {
        if (--s_ticks_until_check <= 0) {
            s_ticks_until_check = kCheckTicks;
            if (ensure_proxy()) patch_all();
        }
        if (s_proxy != nullptr) follow_view(world, vr_body);
    }
    catch (...) {
        API::get()->log_error("[tutorial_head_view][handle] Exception");
        s_failed = true;
    }
}

// Copies the HMD's world transform onto the proxy, or PlayerCamera's without a VR body.
void TutorialHeadView::follow_view(SDK::UWorld* world, SDK::A_BP_VRBody_C* vr_body) {
    SDK::USceneComponent* source = nullptr;
    if (vr_body != nullptr && SDK::UKismetSystemLibrary::IsValid(vr_body)) {
        source = vr_body->HMDComponent();
    }
    else if (world != nullptr) {
        SDK::APawn* pawn = SDK::UGameplayStatics::GetPlayerPawn(world, 0);
        if (PluginUtils::is_a<SDK::APAWN_Hacker_Simple_C>(pawn)) source = static_cast<SDK::APAWN_Hacker_Simple_C*>(pawn)->PlayerCamera;
    }
    if (source == nullptr) return;
    SDK::FHitResult hit{};
    s_proxy->K2_SetWorldLocationAndRotation(source->K2_GetComponentLocation(), source->K2_GetComponentRotation(), false, &hit, false);
}

// Finds the proxy a previous plugin left in the bytecode, or creates one.
bool TutorialHeadView::ensure_proxy() {
    if (s_proxy != nullptr) return true;
    for (const wchar_t* name : kFunctions) {
        const ScriptArray* script = script_of(name);
        if (script == nullptr) return false;   // class not loaded yet
        if (s_proxy == nullptr) s_proxy = find_patched_proxy(*script);
    }
    if (s_proxy != nullptr) return true;
    s_proxy = create_proxy();
    if (s_proxy == nullptr) {
        API::get()->log_error("[tutorial_head_view][ensure_proxy] Cannot create the view component, tutorial popups keep following the hand");
        s_failed = true;
        return false;
    }
    API::get()->log_warn("[tutorial_head_view][ensure_proxy] Created the view component");
    return true;
}

void TutorialHeadView::patch_all() {
    for (const wchar_t* name : kFunctions) {
        const int patched = patch(name);
        if (patched > 0) API::get()->log_warn("[tutorial_head_view][patch_all] %ls now reads the HMD view (%d places)", name, patched);
    }
}

// Points every PlayerCamera context of the function at the proxy; returns how many it changed.
int TutorialHeadView::patch(const wchar_t* function_name) {
    ScriptArray* script = script_of(function_name);
    const void* camera = player_camera_property();
    if (script == nullptr || camera == nullptr) return 0;
    int patched = 0;
    for (int32_t at = 0; at + kContextObjectSize <= script->num; ++at) {
        uint8_t* p = script->data + at;
        if (!is_context_of(p, EX_InstanceVariable, camera)) continue;
        p[1] = EX_ObjectConst;
        std::memcpy(p + 2, &s_proxy, sizeof(s_proxy));
        ++patched;
    }
    return patched;
}
