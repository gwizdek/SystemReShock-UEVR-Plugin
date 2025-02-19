#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: WIDGET_SimplifiedHotbar

#include "Basic.hpp"

#include "ENUM_SimplifiedHotbarState_structs.hpp"
#include "UMG_classes.hpp"
#include "ENUM_HotbarStyle_structs.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass WIDGET_SimplifiedHotbar.WIDGET_SimplifiedHotbar_C
// 0x0050 (0x02B0 - 0x0260)
class UWIDGET_SimplifiedHotbar_C final : public UUserWidget
{
public:
	class UGridMeshWidget*                        GridMeshWidget_0;                                  // 0x0260(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UCanvasPanel*                           PANEL_SimplifiedHotbar;                            // 0x0268(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UWIDGET_SimplifiedHotbarCategoryModal_C* WIDGET_SimplifiedItemModal_Consumables;            // 0x0270(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UWIDGET_SimplifiedHotbarCategoryModal_C* WIDGET_SimplifiedItemModal_Explosives;             // 0x0278(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UWIDGET_SimplifiedHotbarCategoryModal_C* WIDGET_SimplifiedItemModal_Weapons;                // 0x0280(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	TArray<class UWIDGET_SimplifiedHotbarSlot_C*> SimplifiedHotbarSlots;                             // 0x0288(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance, ContainsInstancedReference)
	ENUM_SimplifiedHotbarState                    SimplifiedHotbarState;                             // 0x0298(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_299[0x7];                                      // 0x0299(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UWIDGET_PlayerHUD_C*                    PlayerHUD;                                         // 0x02A0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          HasJustOpenedModal;                                // 0x02A8(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)

public:
	void ToggleSimplifiedHotbarCategory(ENUM_SimplifiedHotbarState NewHotbarState);
	void GetHotbarSlots();
	void InitializeSimplifiedHotbar(class UWIDGET_PlayerHUD_C* Player_HUD);
	void CloseSimplifiedHotbarModal();
	void Select_Simplifed_Hotbar_Slot(int32 HotbarSlotIndex, class UCOMP_Hotbar_C* COMP_Hotbar);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"WIDGET_SimplifiedHotbar_C">();
	}
	static class UWIDGET_SimplifiedHotbar_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UWIDGET_SimplifiedHotbar_C>();
	}
};
static_assert(alignof(UWIDGET_SimplifiedHotbar_C) == 0x000008, "Wrong alignment on UWIDGET_SimplifiedHotbar_C");
static_assert(sizeof(UWIDGET_SimplifiedHotbar_C) == 0x0002B0, "Wrong size on UWIDGET_SimplifiedHotbar_C");
static_assert(offsetof(UWIDGET_SimplifiedHotbar_C, GridMeshWidget_0) == 0x000260, "Member 'UWIDGET_SimplifiedHotbar_C::GridMeshWidget_0' has a wrong offset!");
static_assert(offsetof(UWIDGET_SimplifiedHotbar_C, PANEL_SimplifiedHotbar) == 0x000268, "Member 'UWIDGET_SimplifiedHotbar_C::PANEL_SimplifiedHotbar' has a wrong offset!");
static_assert(offsetof(UWIDGET_SimplifiedHotbar_C, WIDGET_SimplifiedItemModal_Consumables) == 0x000270, "Member 'UWIDGET_SimplifiedHotbar_C::WIDGET_SimplifiedItemModal_Consumables' has a wrong offset!");
static_assert(offsetof(UWIDGET_SimplifiedHotbar_C, WIDGET_SimplifiedItemModal_Explosives) == 0x000278, "Member 'UWIDGET_SimplifiedHotbar_C::WIDGET_SimplifiedItemModal_Explosives' has a wrong offset!");
static_assert(offsetof(UWIDGET_SimplifiedHotbar_C, WIDGET_SimplifiedItemModal_Weapons) == 0x000280, "Member 'UWIDGET_SimplifiedHotbar_C::WIDGET_SimplifiedItemModal_Weapons' has a wrong offset!");
static_assert(offsetof(UWIDGET_SimplifiedHotbar_C, SimplifiedHotbarSlots) == 0x000288, "Member 'UWIDGET_SimplifiedHotbar_C::SimplifiedHotbarSlots' has a wrong offset!");
static_assert(offsetof(UWIDGET_SimplifiedHotbar_C, SimplifiedHotbarState) == 0x000298, "Member 'UWIDGET_SimplifiedHotbar_C::SimplifiedHotbarState' has a wrong offset!");
static_assert(offsetof(UWIDGET_SimplifiedHotbar_C, PlayerHUD) == 0x0002A0, "Member 'UWIDGET_SimplifiedHotbar_C::PlayerHUD' has a wrong offset!");
static_assert(offsetof(UWIDGET_SimplifiedHotbar_C, HasJustOpenedModal) == 0x0002A8, "Member 'UWIDGET_SimplifiedHotbar_C::HasJustOpenedModal' has a wrong offset!");

}

