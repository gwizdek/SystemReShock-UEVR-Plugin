#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: WIDGET_Biometer

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "UMG_structs.hpp"
#include "UMG_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass WIDGET_Biometer.WIDGET_Biometer_C
// 0x0050 (0x02B0 - 0x0260)
class UWIDGET_Biometer_C final : public UUserWidget
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0260(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UGridMeshWidget*                        MESH_BiometerFrame;                                // 0x0268(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UTimeSeriesTraceWidget*                 MESH_TraceLines;                                   // 0x0270(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UCanvasPanel*                           PANEL_Biometer;                                    // 0x0278(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UWIDGET_PlayerHUD_C*                    PlayerHUD;                                         // 0x0280(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UInventoryBag_C*                        HardwareBag;                                       // 0x0288(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UHARDWARE_Bioscan_Base_C*               HardwareItem;                                      // 0x0290(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          MouseOver;                                         // 0x0298(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	bool                                          WasMagLocked;                                      // 0x0299(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                         Pad_29A[0x2];                                      // 0x029A(0x0002)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         FadeInStartTimestamp;                              // 0x029C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         NextToolTipUpdateProgress;                         // 0x02A0(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_2A4[0x4];                                      // 0x02A4(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	struct FTimerHandle                           RevealWidgetTimerHandle;                           // 0x02A8(0x0008)(Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_WIDGET_Biometer(int32 EntryPoint);
	void Tick(const struct FGeometry& MyGeometry, float InDeltaTime);
	void InitializeBiometer(class UWIDGET_PlayerHUD_C* HUD);
	void ShowBiometer(bool Visible);
	void EVENT_OnHardwareBagChanged(int32 SlotIndex);
	void UpdateBiometer(float DeltaTime);
	void SetHardwareItem(class UHARDWARE_Bioscan_Base_C* Item);
	void EVENT_OnHardwareStateChanged(bool Activated, bool MagLocked);
	void EVENT_OnMouseOverTraceLines(const struct FGeometry& MyGeometry, const struct FPointerEvent& MouseEvent);
	void EVENT_OnMouseLeaveTraceLines(const struct FPointerEvent& MouseEvent);
	void GetHeartRate(int32* Result);
	void GetEnergyUsage(int32* Result);
	void GetChiFrequency(float* Result);
	void GetToolTipText(class FText* ToolTip);
	void OnMouseExit(bool* Result);
	void OnMouseOver(bool* Result);
	void GetMeshWidget(class UGridMeshWidget** Result);
	void EnableFlickerEffect(bool* Result);
	void DisableFlickerEffect(bool* Result);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"WIDGET_Biometer_C">();
	}
	static class UWIDGET_Biometer_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UWIDGET_Biometer_C>();
	}
};
static_assert(alignof(UWIDGET_Biometer_C) == 0x000008, "Wrong alignment on UWIDGET_Biometer_C");
static_assert(sizeof(UWIDGET_Biometer_C) == 0x0002B0, "Wrong size on UWIDGET_Biometer_C");
static_assert(offsetof(UWIDGET_Biometer_C, UberGraphFrame) == 0x000260, "Member 'UWIDGET_Biometer_C::UberGraphFrame' has a wrong offset!");
static_assert(offsetof(UWIDGET_Biometer_C, MESH_BiometerFrame) == 0x000268, "Member 'UWIDGET_Biometer_C::MESH_BiometerFrame' has a wrong offset!");
static_assert(offsetof(UWIDGET_Biometer_C, MESH_TraceLines) == 0x000270, "Member 'UWIDGET_Biometer_C::MESH_TraceLines' has a wrong offset!");
static_assert(offsetof(UWIDGET_Biometer_C, PANEL_Biometer) == 0x000278, "Member 'UWIDGET_Biometer_C::PANEL_Biometer' has a wrong offset!");
static_assert(offsetof(UWIDGET_Biometer_C, PlayerHUD) == 0x000280, "Member 'UWIDGET_Biometer_C::PlayerHUD' has a wrong offset!");
static_assert(offsetof(UWIDGET_Biometer_C, HardwareBag) == 0x000288, "Member 'UWIDGET_Biometer_C::HardwareBag' has a wrong offset!");
static_assert(offsetof(UWIDGET_Biometer_C, HardwareItem) == 0x000290, "Member 'UWIDGET_Biometer_C::HardwareItem' has a wrong offset!");
static_assert(offsetof(UWIDGET_Biometer_C, MouseOver) == 0x000298, "Member 'UWIDGET_Biometer_C::MouseOver' has a wrong offset!");
static_assert(offsetof(UWIDGET_Biometer_C, WasMagLocked) == 0x000299, "Member 'UWIDGET_Biometer_C::WasMagLocked' has a wrong offset!");
static_assert(offsetof(UWIDGET_Biometer_C, FadeInStartTimestamp) == 0x00029C, "Member 'UWIDGET_Biometer_C::FadeInStartTimestamp' has a wrong offset!");
static_assert(offsetof(UWIDGET_Biometer_C, NextToolTipUpdateProgress) == 0x0002A0, "Member 'UWIDGET_Biometer_C::NextToolTipUpdateProgress' has a wrong offset!");
static_assert(offsetof(UWIDGET_Biometer_C, RevealWidgetTimerHandle) == 0x0002A8, "Member 'UWIDGET_Biometer_C::RevealWidgetTimerHandle' has a wrong offset!");

}

