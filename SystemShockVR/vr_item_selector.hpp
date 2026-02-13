#pragma once

#include "SDK/WIDGET_PlayerHUD_classes.hpp"
#include "SDK/_BP_ItemSelector_classes.hpp"

#include "memo_structs.hpp"

class VRItemSelector
{
private:
    static inline MemoProperty<SDK::UWidgetComponent*> m_highlighted_widget_component{ nullptr, nullptr };

public:
    static void initialize(SDK::UWIDGET_PlayerHUD_C* neural_hud);
    static void set_visibility(bool visible);
    static void set_hotbar_slot_visibility(int slot, bool visible);
    static void set_current_quick_slot();
    static void activate_current_quick_slot();
    static void unselect_all_hotbar_slots(SDK::UWIDGET_PlayerHUD_C* neural_hud);

    VRItemSelector() = delete;
};
