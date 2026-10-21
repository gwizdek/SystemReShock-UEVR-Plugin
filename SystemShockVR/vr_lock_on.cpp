#include "vr_lock_on.hpp"

#include "uevr/API.hpp"
#include "SDK/Engine_classes.hpp"
#include "SDK/UMG_classes.hpp"
#include "SDK/PAWN_Avatar_classes.hpp"
#include "SDK/WIDGET_CyberspaceHUD_classes.hpp"
#include "SDK/WIDGET_IceDrillLockOn_classes.hpp"
#include "BridgeSDK/_BP_VRAvatar_classes.hpp"

using namespace SDK;
using namespace uevr;

namespace {

// The lock-on's size in the HUD, in pixels; the component draws it at that size.
constexpr float kDrawSize = 512.f;
// The lock-on's scale relative to the reticle's. At 1 it would be 6.4 times the reticle, as in
// the HUD, which is far too big in VR.
constexpr float kScaleToReticle = 0.2f;
// Translucent without depth test, so walls never cut into the lock-on. It is several times the
// reticle's size, so the masked, depth-tested material of the reticle would clip it on any
// wall that is not hit straight on.
constexpr const wchar_t* kNoDepthMaterial =
    L"/Game/Mods/VRBody/Materials/Widget3DPassThrough_Translucent_NoDepth.Widget3DPassThrough_Translucent_NoDepth";

bool is_alive(void* object) {
    return object != nullptr && API::UObjectHook::exists(reinterpret_cast<API::UObject*>(object));
}

UMaterialInterface* load_material(const wchar_t* object_path) {
    const FSoftObjectPath path = UKismetSystemLibrary::MakeSoftObjectPath(object_path);
    return static_cast<UMaterialInterface*>(
        UKismetSystemLibrary::LoadAsset_Blocking(UKismetSystemLibrary::Conv_SoftObjPathToSoftObjRef(path))
    );
}

} // namespace

UWidgetComponent* VRLockOn::s_component{ nullptr };
UUserWidget* VRLockOn::s_widget{ nullptr };
UWIDGET_CyberspaceHUD_C* VRLockOn::s_hud{ nullptr };

void VRLockOn::attach(A_BP_VRAvatar_C* vr_avatar, APAWN_Avatar_C* pawn) {
    try {
        restore();
        auto* hud = static_cast<UWIDGET_CyberspaceHUD_C*>(pawn->CyberspaceUI);
        if (!is_alive(hud) || hud->WIDGET_IceDrillLockOn == nullptr) {
            API::get()->log_error("[vr_lock_on][attach] No cyberspace HUD or lock-on widget");
            return;
        }
        UWidgetComponent* component = create_component(vr_avatar);
        if (component == nullptr) {
            return;
        }
        UUserWidget* lock_on = hud->WIDGET_IceDrillLockOn;
        lock_on->RemoveFromParent();
        component->SetWidget(lock_on);
        s_component = component;
        s_widget = lock_on;
        s_hud = hud;
        API::get()->log_warn("[vr_lock_on][attach] Drill lock-on moved into the world");
    }
    catch (...) {
        API::get()->log_error("[vr_lock_on][attach] Exception");
    }
}

UWidgetComponent* VRLockOn::create_component(A_BP_VRAvatar_C* vr_avatar) {
    FTransform identity{};
    identity.Rotation = { 0.f, 0.f, 0.f, 1.f };
    identity.Scale3D = { 1.f, 1.f, 1.f };
    auto* component = static_cast<UWidgetComponent*>(
        vr_avatar->AddComponentByClass(UWidgetComponent::StaticClass(), true, identity, false)
    );
    if (component == nullptr) {
        API::get()->log_error("[vr_lock_on][create_component] Could not add the widget component");
        return nullptr;
    }
    component->K2_AttachToComponent(
        vr_avatar->DefaultSceneRoot(),
        UKismetStringLibrary::Conv_StringToName(L"None"),
        EAttachmentRule::KeepWorld,
        EAttachmentRule::KeepWorld,
        EAttachmentRule::KeepWorld,
        true
    );
    component->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    component->SetDrawSize({ kDrawSize, kDrawSize });
    // The widget's animations run in its tick; keep them running when nothing is drawn.
    component->SetTickWhenOffscreen(true);
    component->BlendMode = EWidgetBlendMode::Transparent;
    if (UMaterialInterface* material = load_material(kNoDepthMaterial)) {
        component->SetMaterial(0, material);
    }
    else {
        API::get()->log_error("[vr_lock_on][create_component] %ls not loaded", kNoDepthMaterial);
    }
    // Rebuilds the render proxy, so the blend mode above is used.
    component->SetTwoSided(true);
    return component;
}

void VRLockOn::place(const FVector& location, const FRotator& rotation, float scale) {
    if (!is_alive(s_component)) {
        return;
    }
    FHitResult unused{};
    s_component->K2_SetWorldLocationAndRotation(location, rotation, false, &unused, false);
    const float lock_on_scale = scale * kScaleToReticle;
    s_component->SetWorldScale3D({ lock_on_scale, lock_on_scale, lock_on_scale });
}

// The HUD's layout of the lock-on: 512 x 512 at the screen centre.
void VRLockOn::restore() {
    try {
        if (is_alive(s_component)) {
            s_component->SetWidget(nullptr);
        }
        if (is_alive(s_widget) && is_alive(s_hud) && s_hud->WidgetTree != nullptr) {
            UWidget* root = s_hud->WidgetTree->RootWidget;
            if (root != nullptr && root->IsA(UCanvasPanel::StaticClass())) {
                UCanvasPanelSlot* slot = static_cast<UCanvasPanel*>(root)->AddChildToCanvas(s_widget);
                if (slot != nullptr) {
                    slot->SetAnchors(FAnchors{ { 0.5f, 0.5f }, { 0.5f, 0.5f } });
                    slot->SetAlignment(FVector2D{ 0.5f, 0.5f });
                    slot->SetPosition(FVector2D{ 0.f, 0.f });
                    slot->SetSize(FVector2D{ kDrawSize, kDrawSize });
                }
                API::get()->log_warn("[vr_lock_on][restore] Drill lock-on back in the HUD");
            }
        }
    }
    catch (...) {
        API::get()->log_error("[vr_lock_on][restore] Exception");
    }
    s_component = nullptr;
    s_widget = nullptr;
    s_hud = nullptr;
}
