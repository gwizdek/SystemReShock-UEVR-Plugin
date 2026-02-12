#include "uevr/API.hpp"

#include "SDK/WIDGET_HotbarSlot_classes.hpp"

#include "vr_item_selector.hpp"
#include "vr_plugin_shared.hpp"

using namespace uevr;
using namespace SDK;

void VRItemSelector::initialize(APAWN_Hacker_Implant_C* pawn, A_BP_VRBody_C* vr_body, UWIDGET_PlayerHUD_C* neural_hud) {
    try {
        API::get()->log_warn("[item_selector][initialize] Initialize HotbarSlots");
        if (vr_body == nullptr) {
            API::get()->log_error("[item_selector][initialize] vr_body nullptr");
            return;
        }
        
        // get prepared in UE Editor hotbar slot array 
        auto hotbar_slots = vr_body->ItemSelectorRight->HotbarSlots;

        // canvas panel slots 
        std::array<SDK::UCanvasPanelSlot*, 10> canvas_panel_slots{};

        for (int i = 0; i < 10; i++) {
            canvas_panel_slots[i] = (SDK::UCanvasPanelSlot*)neural_hud->HotbarSlots[i]->Slot;
            canvas_panel_slots[i]->SetAlignment({ 0.5f, 0.5f });
            canvas_panel_slots[i]->SetAnchors(SDK::FAnchors{ {0.5f, 0.5f}, {0.5f, 0.5f} });

            hotbar_slots[i]->SetWidget(neural_hud->HotbarSlots[i]);
            hotbar_slots[i]->SetDrawSize({ 100.0f, 104.0f });
    
            // setup selector's collision channels
            hotbar_slots[i]->SetCollisionResponseToAllChannels(SDK::ECollisionResponse::ECR_Ignore);
            hotbar_slots[i]->SetCollisionResponseToChannel(
                WIDGET_INTERACTION_TRACE_CHANNEL, SDK::ECollisionResponse::ECR_Block
            );

            // ?
            canvas_panel_slots[i]->SetAlignment({ 0.5f, 1.f });
            canvas_panel_slots[i]->SetAnchors(SDK::FAnchors{ {0.5f, 1.f}, {0.5f, 1.f} });

            auto material = API::get()->find_uobject<SDK::UMaterialInstanceConstant>(
                L"MaterialInstanceConstant /Engine/EngineMaterials/Widget3DPassThrough_Translucent.Widget3DPassThrough_Translucent"
                //L"MaterialInstanceConstant /Engine/EngineMaterials/Widget3DPassThrough_Opaque.Widget3DPassThrough_Opaque"
            );
            SDK::FLinearColor color{ 0.1f, 0.1f, 0.1f, 1.0f };
            hotbar_slots[i]->SetMaterial(0, material);
            hotbar_slots[i]->SetTintColorAndOpacity(color);

            neural_hud->HotbarSlots[i]->UpdateHotbarSlot();

            VRItemSelector::m_item_selector = vr_body->ItemSelectorRight;

            set_visibility(vr_body, false);
        }

        API::get()->log_warn("[item_selector][initialize] Initialized HotbarSlots");
    }
    catch (...) {
        API::get()->log_error("[vrbody][initialize] Exception");
    }
}

void VRItemSelector::set_hotbar_slot_visibility(int slot, bool visible) {
    m_item_selector->HotbarSlots[slot]->SetVisibility(visible, true);
    m_item_selector->HotbarSlots[slot]->SetHiddenInGame(!visible, true);
}

// highlights selected item
void VRItemSelector::set_current_quick_slot(A_BP_VRBody_C* vr_body) {
    //API::get()->log_warn("[vrbody][highlight_quick_slot] Begin");
    VRItemSelector::m_highlighted_widget_component.set_value(vr_body->WidgetInteractionRight->GetHoveredWidgetComponent());

    if (VRItemSelector::m_highlighted_widget_component.has_changed()) {
        // highlight current selected slot
        if (VRItemSelector::m_highlighted_widget_component.value != nullptr) {
            auto widget = VRItemSelector::m_highlighted_widget_component.value->GetWidget();
            if (widget != nullptr && widget->IsA(SDK::UWIDGET_HotbarSlot_C::StaticClass())) {
                static_cast<SDK::UWIDGET_HotbarSlot_C*>(widget)->SetIsCurrentQuickSlot(true);
            }
        }

        // remove highlight from previous slot
        if (VRItemSelector::m_highlighted_widget_component.prev_value != nullptr) {
            auto prev_widget = VRItemSelector::m_highlighted_widget_component.prev_value->GetWidget();
            if (prev_widget != nullptr && prev_widget->IsA(SDK::UWIDGET_HotbarSlot_C::StaticClass())) {
                static_cast<SDK::UWIDGET_HotbarSlot_C*>(prev_widget)->SetIsCurrentQuickSlot(false);
            }
        }
    }
    //API::get()->log_warn("[vrbody][highlight_quick_slot] End");
}

// change active hotbar slot
void VRItemSelector::activate_current_quick_slot(APAWN_Hacker_Implant_C* pawn) {
    if (VRItemSelector::m_highlighted_widget_component.value != nullptr) {
        auto widget = VRItemSelector::m_highlighted_widget_component.value->GetWidget();
        if (widget != nullptr && widget->IsA(SDK::UWIDGET_HotbarSlot_C::StaticClass())) {
            SDK::int32 slot_index;
            static_cast<SDK::UWIDGET_HotbarSlot_C*>(widget)->GetSlotIndex(&slot_index);

            pawn->ReceiveInputForHotbarSlotByIndex(
                slot_index + 1, true
            );
        }
    }
    else {
        SDK::FKey h_key_name{
            .KeyName = SDK::UKismetStringLibrary::Conv_StringToName(L"H")
        };

        // holster weapon
        pawn->InpActEvt_Real_ToggleEquip_K2Node_InputActionEvent_24(h_key_name);
    }
}

void VRItemSelector::set_visibility(A_BP_VRBody_C* vr_body, bool visible) {
    for (int i = 0; i < 10; i++) {
        if (vr_body->ItemSelectorRight->HotbarSlots[i] != nullptr) {
            vr_body->ItemSelectorRight->HotbarSlots[i]->SetVisibility(visible, true);
            vr_body->ItemSelectorRight->HotbarSlots[i]->SetHiddenInGame(!visible, true);
        }
    }
}

void VRItemSelector::unselect_all_hotbar_slots(UWIDGET_PlayerHUD_C* neural_hud) {
    try {
        for (int i = 0; i < 10; i++) {
            neural_hud->HotbarSlots[i]->SetIsCurrentQuickSlot(false);
        }
    }
    catch (...) {
        API::get()->log_error("[vrbody][unselect_all_hotbar_slots] Exception");
    }
}
