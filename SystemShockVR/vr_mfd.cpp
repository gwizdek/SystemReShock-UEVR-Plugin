#include <windows.h>

#include "uevr/API.hpp"
#include "imgui/imgui.h"

#include "SDK/SystemReShock_classes.hpp"
#include "SDK/PAWN_Hacker_Implant_classes.hpp"
#include "SDK/PAWN_Hacker_Simple_classes.hpp"
#include "SDK/WIDGET_PlayerHUD_classes.hpp"
#include "SDK/WIDGET_SimpleHUD_classes.hpp"
#include "SDK/WIDGET_CrosshairCursor_classes.hpp"
#include "SDK/_BP_MFDMaskComponent_classes.hpp"

#include "vr_mfd.hpp"
#include "vr_plugin_shared.hpp"

using namespace uevr;
using namespace SDK;

// -------------------------------------------------------------------------------------
// MFD
// -------------------------------------------------------------------------------------

void VRMFD::initialize(A_BP_VRBody_C* vr_body) {
    //auto material = API::get()->find_uobject<SDK::UMaterialInstanceConstant>(
    //    L"MaterialInstanceConstant /Engine/EngineMaterials/Widget3DPassThrough_Translucent.Widget3DPassThrough_Translucent"
    //    //L"MaterialInstanceConstant /Engine/EngineMaterials/Widget3DPassThrough_Opaque.Widget3DPassThrough_Opaque"
    //);
    //vr_body->MFDMaskComponent->SetMaterial(0, material);

    //SDK::FLinearColor color{ 0.4f, 0.4f, 0.4f, 0.2f };
    //vr_body->MFDMaskComponent->SetTintColorAndOpacity(color);
    vr_body->MFDMaskComponent->SetCollisionResponseToChannel(
        WIDGET_INTERACTION_TRACE_CHANNEL, SDK::ECollisionResponse::ECR_Ignore
    );
}


// moves MFD panel 10% up
void VRMFD::align_mfd_panel(UWIDGET_PlayerHUD_C* neural_hud) {
    if (!SDK::UKismetSystemLibrary::IsValid(neural_hud->Panel_MultiFunctionDisplay)) {
        API::get()->log_error("[vr_mfd][align_mfd_panel] Invalid Panel_MultiFunctionDisplay");
        return;
    }
    auto slot = (SDK::UCanvasPanelSlot*)neural_hud->Panel_MultiFunctionDisplay->Slot;
    slot->SetAlignment({ 0.5f, 1.0f });
    slot->SetAnchors(SDK::FAnchors{ {0.5f, 0.9f}, {0.5f, 0.9f} });
}

void VRMFD::show(A_BP_VRBody_C* vr_body) {
    vr_body->MFDMaskComponent->Show(1.0f, VRMFD::m_mfd_depth);
}

void VRMFD::hide(A_BP_VRBody_C* vr_body) {
    vr_body->MFDMaskComponent->Hide();
}

void VRMFD::set_crosshair_cursor_scale(UWIDGET_PlayerHUD_C* neural_hud, float* scale) {
    if (neural_hud != nullptr && neural_hud->WIDGET_CrosshairCursor != nullptr) {
        neural_hud->WIDGET_CrosshairCursor->MESH_CrosshairCursor->SetRenderScale({ *scale, *scale });
    }
}


