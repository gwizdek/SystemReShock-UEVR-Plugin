#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: WIDGET_SubDetails_Consumable

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "UMG_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass WIDGET_SubDetails_Consumable.WIDGET_SubDetails_Consumable_C
// 0x0020 (0x0280 - 0x0260)
class UWIDGET_SubDetails_Consumable_C final : public UUserWidget
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0260(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UTextMeshWidget*                        TEXT_Duration;                                     // 0x0268(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UTextMeshWidget*                        TEXT_Effect;                                       // 0x0270(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UTextMeshWidget*                        TEXT_SideEffect;                                   // 0x0278(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_WIDGET_SubDetails_Consumable(int32 EntryPoint);
	void OnHideItemDetails();
	void OnShowItemDetails();
	void GetAmmoDetails(bool* ShowAmmo, int32* CountInClip, int32* CountInInventory);
	void InitializeItemDetails(class UITEM_Base_C* Item, class UWIDGET_InventoryDetails_C* InventoryDetails, bool* Result);
	void ShowExtendedDetails(bool* Show);
	void ShowBars(bool* Show);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"WIDGET_SubDetails_Consumable_C">();
	}
	static class UWIDGET_SubDetails_Consumable_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UWIDGET_SubDetails_Consumable_C>();
	}
};
static_assert(alignof(UWIDGET_SubDetails_Consumable_C) == 0x000008, "Wrong alignment on UWIDGET_SubDetails_Consumable_C");
static_assert(sizeof(UWIDGET_SubDetails_Consumable_C) == 0x000280, "Wrong size on UWIDGET_SubDetails_Consumable_C");
static_assert(offsetof(UWIDGET_SubDetails_Consumable_C, UberGraphFrame) == 0x000260, "Member 'UWIDGET_SubDetails_Consumable_C::UberGraphFrame' has a wrong offset!");
static_assert(offsetof(UWIDGET_SubDetails_Consumable_C, TEXT_Duration) == 0x000268, "Member 'UWIDGET_SubDetails_Consumable_C::TEXT_Duration' has a wrong offset!");
static_assert(offsetof(UWIDGET_SubDetails_Consumable_C, TEXT_Effect) == 0x000270, "Member 'UWIDGET_SubDetails_Consumable_C::TEXT_Effect' has a wrong offset!");
static_assert(offsetof(UWIDGET_SubDetails_Consumable_C, TEXT_SideEffect) == 0x000278, "Member 'UWIDGET_SubDetails_Consumable_C::TEXT_SideEffect' has a wrong offset!");

}

