#pragma once

#include "SDK/PAWN_Hacker_Implant_classes.hpp"
#include "SDK/WIDGET_PlayerHUD_classes.hpp"
#include "SDK/_BP_ItemSelector_classes.hpp"
#include "SDK/_BP_VRBody_classes.hpp"

#include "memo_structs.hpp"

using namespace SDK;

class VRItemSelector
{
private:
    static inline A_BP_ItemSelector_C* m_item_selector{ nullptr };

public:
    VRItemSelector() = default;
    virtual ~VRItemSelector() {};

    static inline MemoProperty<SDK::UWidgetComponent*> m_highlighted_widget_component{ nullptr, nullptr };

    static void initialize(APAWN_Hacker_Implant_C* pawn, A_BP_VRBody_C* vr_body, UWIDGET_PlayerHUD_C* neural_hud);
    static void set_visibility(A_BP_VRBody_C* vr_body, bool visible);
    //// getters
    static void set_hotbar_slot_visibility(int slot, bool visible);
    static void set_current_quick_slot(A_BP_VRBody_C* vr_body);
    static void activate_current_quick_slot(APAWN_Hacker_Implant_C* pawn);
    static void unselect_all_hotbar_slots(UWIDGET_PlayerHUD_C* neural_hud);
};
