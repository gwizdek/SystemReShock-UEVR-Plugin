#include <windows.h>

#include "uevr/API.hpp"

#include "SDK/SystemReShock_classes.hpp"
#include "SDK/PAWN_Hacker_Implant_classes.hpp"
#include "SDK/PAWN_Hacker_Simple_classes.hpp"
#include "SDK/CON_Hacker_classes.hpp"

#include "SDK/WIDGET_SimpleHUD_classes.hpp"
#include "SDK/WIDGET_CrosshairCursor_classes.hpp"
#include "SDK/WIDGET_Minimap_classes.hpp"

#include "BridgeSDK/_BP_DebugWidgetComponent_classes.hpp"
#include "BridgeSDK/_BP_MFDMaskComponent_classes.hpp"
#include "BridgeSDK/_BP_VRBody_classes.hpp"
#include "BridgeSDK/_BP_HandInteractionComponent_classes.hpp"
#include "BridgeSDK/_BP_LaserDot_classes.hpp"
#include "BridgeSDK/_BP_HackerHardware_classes.hpp"

#include "vr_mfd.hpp"
#include "vr_plugin_shared.hpp"
#include "plugin_utils.hpp"

extern SDK::A_BP_VRBody_C* g_vr_body;

using namespace uevr;
using namespace SDK;

// -------------------------------------------------------------------------------------
// MFD
// -------------------------------------------------------------------------------------

// Called from on_post_calculate_stereo_view_offset, where UEVR has already added the HMD to
// the view rotation.
void VRMFD::save_view_rotation(const UEVR_Rotatorf* rotation) {
    if (rotation == nullptr) return;
    m_view_rotation = SDK::FRotator{ rotation->pitch, rotation->yaw, rotation->roll };
    m_has_view_rotation = true;
}

// Turns the MFD and the UEVR UI layer to where the player looks, without moving the view.
// UEVR draws the UI layer in front of the control rotation: yaw from the control rotation,
// pitch from it too while VR_DecoupledPitchUIAdjust is on. MFDMaskComponent::Show takes the
// yaw from the pawn, which follows the control rotation, and the pitch from HMDComponent.
// So the control rotation is set to the head, and recenter_view() moves UEVR's rotation
// offset by the same yaw, which keeps the view where it is. With decoupled pitch the control
// pitch does not reach the view. This is what UEVR's head aim (aim method 1) does each tick.
void VRMFD::face_head(SDK::APawn* pawn, const UEVR_VRData* vr) {
    try {
        if (!m_has_view_rotation || pawn == nullptr || pawn->Controller == nullptr) {
            API::get()->log_warn("[vr_mfd][face_head] No view rotation or controller yet, MFD keeps the control rotation");
            return;
        }
        pawn->Controller->SetControlRotation(SDK::FRotator{ m_view_rotation.Pitch, m_view_rotation.Yaw, 0.f });
        vr->recenter_view();
        API::get()->log_warn("[vr_mfd][face_head] Control rotation set to the head: pitch=%.1f yaw=%.1f",
            m_view_rotation.Pitch, m_view_rotation.Yaw);
    }
    catch (...) {
        API::get()->log_error("[vr_mfd][face_head] Exception");
    }
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

void VRMFD::show_mfd() {
    try {
        if (g_vr_body == nullptr) {
            API::get()->log_error("[plugin][show_mfd] Invalid vr_body");
            return;
        }
        if (!g_vr_body->IsWeaponHolstered()) {
            // use holster weapon button: holster weapon
            SDK::FKey h_key_name{
                .KeyName = SDK::UKismetStringLibrary::Conv_StringToName(L"H")
            };
            g_vr_body->HackerPawn()->InpActEvt_Real_ToggleEquip_K2Node_InputActionEvent_64(h_key_name);
            VRMFD::m_had_equipped_weapon = true;
        }
        else {
            VRMFD::m_had_equipped_weapon = false;
        }

        g_vr_body->HandInteractionRight()->AttachLaserPointer(true, 0.f);
        g_vr_body->LaserDot()->SetLaserVisibility(false, true, 0.f);
        g_vr_body->EnableRangedInteractions(false);

        g_vr_body->MFDMaskComponent()->SetCollisionResponseToChannel(
            WIDGET_INTERACTION_TRACE_CHANNEL, SDK::ECollisionResponse::ECR_Block
        );
        g_vr_body->MFDMaskComponent()->Show(1.0f, VRMFD::m_mfd_depth);
    }
    catch (...) {
        API::get()->log_error("[plugin][show_mfd] Exception");
    }
}

void VRMFD::hide_mfd(SDK::ACON_Hacker_C* ctrl) {
    try {
        if (g_vr_body == nullptr) {
            API::get()->log_error("[plugin][hide_mfd] Invalid vr_body");
            return;
        }

        g_vr_body->MFDMaskComponent()->SetCollisionResponseToChannel(
            WIDGET_INTERACTION_TRACE_CHANNEL, SDK::ECollisionResponse::ECR_Ignore
        );
        g_vr_body->MFDMaskComponent()->Hide();
        //g_vr_body->LaserDot()->SetLaserVisibility(false, false, 0.f);
        //g_vr_body->EnableRangedInteractions(false);


        if (g_vr_body->IsWeaponHolstered() && VRMFD::m_had_equipped_weapon) {
            // use holster weapon button: show weapon
            SDK::FKey h_key_name{
                .KeyName = SDK::UKismetStringLibrary::Conv_StringToName(L"H")
            };
            g_vr_body->HackerPawn()->InpActEvt_Real_ToggleEquip_K2Node_InputActionEvent_64(h_key_name);
        }

        g_vr_body->HackerHardware()->SetWidgetVisibility(true);

        // The MFD handler presses mouse buttons for the trigger and the right shoulder. When
        // the MFD closes while one is held, the handler no longer runs and its release is never
        // sent: Windows then keeps the button down, the pointer stays captured and hidden, and
        // the late click puts the game back into keyboard and mouse mode. Release both here.
        PluginUtils::send_mouse(VK_LBUTTON, true);
        PluginUtils::send_mouse(VK_RBUTTON, true);
        if (ctrl != nullptr) {
            ctrl->SetIsUsingGamepad(true);
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