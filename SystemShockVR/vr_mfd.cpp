//#include <windows.h>
//#include "imgui/imgui.h"

#include "uevr/API.hpp"

#include "SDK/SystemReShock_classes.hpp"
#include "SDK/PAWN_Hacker_Implant_classes.hpp"
#include "SDK/PAWN_Hacker_Simple_classes.hpp"

#include "SDK/WIDGET_SimpleHUD_classes.hpp"
#include "SDK/WIDGET_CrosshairCursor_classes.hpp"
#include "SDK/WIDGET_Minimap_classes.hpp"

#include "SDK/_BP_DebugWidgetComponent_classes.hpp"
#include "SDK/_BP_MFDMaskComponent_classes.hpp"
#include "SDK/_BP_VRBody_classes.hpp"

#include "vr_mfd.hpp"
#include "vr_plugin_shared.hpp"
#include "plugin_utils.hpp"

extern SDK::A_BP_VRBody_C* g_vr_body;

using namespace uevr;
using namespace SDK;

// -------------------------------------------------------------------------------------
// MFD
// -------------------------------------------------------------------------------------

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

void VRMFD::show_mfd() {
    try {
        // move MFD panel a little up
        //VRBody::align_mfd_panel(m_neural_hud);

        //API::get()->log_warn("[plugin][show_mfd] MFD Mask Show");
        g_vr_body->MFDMaskComponent->SetCollisionResponseToChannel(
            WIDGET_INTERACTION_TRACE_CHANNEL, SDK::ECollisionResponse::ECR_Block
        );

        //g_vr_body->DebugWidgetComponent->SetCollisionResponseToChannel(
        //    WIDGET_INTERACTION_TRACE_CHANNEL, SDK::ECollisionResponse::ECR_Block
        //);
        //UWIDGET_PlayerHUD_C* neural_hud{ nullptr };
        //pawn->GetNeuralHUD(&neural_hud);
        //g_vr_body->DebugWidgetComponent->WidgetClass = UWIDGET_PlayerHUD_C::StaticClass();
        //g_vr_body->DebugWidgetComponent->SetWidget(neural_hud);

        //SDK::FLinearColor color{ 0.5f, 0.5f, 0.5f, 0.1f };
        //g_vr_body->DebugWidgetComponent->SetTintColorAndOpacity(color);
        //g_vr_body->DebugWidgetComponent->SetRelativeScale3D({ 0.03f, 0.03f, 0.03f });

        g_vr_body->MFDMaskComponent->Show(1.0f, VRMFD::m_mfd_depth);
        g_vr_body->AttachLaserPointer(E_ENUM_VRHand::NewEnumerator1, false);

        if (!g_vr_body->IsWeaponHolstered()) {
            // use holster weapon button: holster weapon
            SDK::FKey h_key_name{
                .KeyName = SDK::UKismetStringLibrary::Conv_StringToName(L"H")
            };
            g_vr_body->HackerPawn->InpActEvt_Real_ToggleEquip_K2Node_InputActionEvent_24(h_key_name);
        }
    }
    catch (...) {
        API::get()->log_error("[plugin][show_mfd] Exception");
    }
}

void VRMFD::hide_mfd() {
    try {
        if (g_vr_body == nullptr) {
            API::get()->log_error("[plugin][hide_mfd] Invalid vr_body");
            return;
        }

        g_vr_body->MFDMaskComponent->SetCollisionResponseToChannel(
            WIDGET_INTERACTION_TRACE_CHANNEL, SDK::ECollisionResponse::ECR_Ignore
        );
        g_vr_body->MFDMaskComponent->Hide();
        

        if (g_vr_body->IsWeaponHolstered()) {
            // use holster weapon button: show weapon
            SDK::FKey h_key_name{
                .KeyName = SDK::UKismetStringLibrary::Conv_StringToName(L"H")
            };
            g_vr_body->HackerPawn->InpActEvt_Real_ToggleEquip_K2Node_InputActionEvent_24(h_key_name);
        }
    }
    catch (...) {
        API::get()->log_error("[plugin][hide_mfd] Exception");
    }
}

void VRMFD::set_crosshair_cursor_scale(UWIDGET_PlayerHUD_C* neural_hud, float* scale) {
    if (neural_hud != nullptr && neural_hud->WIDGET_CrosshairCursor != nullptr) {
        neural_hud->WIDGET_CrosshairCursor->MESH_CrosshairCursor->SetRenderScale({ *scale, *scale });
    }
}


bool VRMFD::calculate_uevr_ui_params(const UEVR_VRData* vr, SDK::UWorld* world, char* ui_distance, char* ui_size) {
    try {
        float world_scale = PluginUtils::uevr_param_to_float(vr, "VR_WorldScale");

        int32 m_viewport_size_x{ 1920 }, m_viewport_size_y{ 1080 };
        // prepare correct ui distance and size
        SDK::APlayerController* ctrl = SDK::UGameplayStatics::GetPlayerController(world, 0);
        ctrl->GetViewportSize(&m_viewport_size_x, &m_viewport_size_y);

        int ret_ui_distance = snprintf(ui_distance, sizeof ui_distance, "%f", (1.f / world_scale) * ((VRMFD::m_mfd_depth / 100.f)));
        int ret_ui_size = snprintf(ui_size, sizeof ui_size, "%f", (float)((1.f / world_scale) * (m_viewport_size_y / 1000.f)));
        if (ret_ui_distance < 0 || ret_ui_size < 0) {
            API::get()->log_error("[plugin][calculate_corrected_ui_distance_size] Error calculating distance / size");
            return false;
        }
        return true;
    }
    catch (...) {
        API::get()->log_error("[plugin][show_mfd] Exception");
    }
    return false;
}