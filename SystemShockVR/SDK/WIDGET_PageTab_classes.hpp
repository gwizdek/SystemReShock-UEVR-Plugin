#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: WIDGET_PageTab

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "UMG_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass WIDGET_PageTab.WIDGET_PageTab_C
// 0x00A8 (0x0308 - 0x0260)
class UWIDGET_PageTab_C final : public UUserWidget
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0260(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UWidgetAnimation*                       TransitionDeselect;                                // 0x0268(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UWidgetAnimation*                       TransitionLeave;                                   // 0x0270(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UWidgetAnimation*                       TransitionSelect;                                  // 0x0278(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UWidgetAnimation*                       TransitionEnter;                                   // 0x0280(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UGridMeshWidget*                        MESH_Button;                                       // 0x0288(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UGridMeshWidget*                        MESH_HitArea;                                      // 0x0290(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UTextMeshWidget*                        TEXT_Label;                                        // 0x0298(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UWIDGET_UnreadMediaDot_C*               WIDGET_UnreadMediaDot;                             // 0x02A0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class FText                                   Text;                                              // 0x02A8(0x0018)(Edit, BlueprintVisible)
	FMulticastInlineDelegateProperty_             OnMouseClick;                                      // 0x02C0(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, BlueprintAssignable, BlueprintCallable)
	FMulticastInlineDelegateProperty_             OnMouseOver;                                       // 0x02D0(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, BlueprintAssignable, BlueprintCallable)
	FMulticastInlineDelegateProperty_             OnMouseOut;                                        // 0x02E0(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, BlueprintAssignable, BlueprintCallable)
	bool                                          bIsSelected;                                       // 0x02F0(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_2F1[0x7];                                      // 0x02F1(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UClass*                                 RequiredHardware;                                  // 0x02F8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UInventoryBag_C*                        HardwareBag;                                       // 0x0300(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void OnMouseClick__DelegateSignature();
	void OnMouseOver__DelegateSignature();
	void OnMouseOut__DelegateSignature();
	void ExecuteUbergraph_WIDGET_PageTab(int32 EntryPoint);
	void Construct();
	void EVENT_OnMouseEnter(const struct FGeometry& MyGeometry, const struct FPointerEvent& MouseEvent);
	void EVENT_OnMouseLeave(const struct FPointerEvent& MouseEvent);
	struct FEventReply EVENT_OnMouseButtonDown(const struct FGeometry& MyGeometry, const struct FPointerEvent& MouseEvent);
	void SetSelected(bool bShouldSelect);
	void UpdateTabColor();
	void InitializeTab();
	void EVENT_OnHardwareBagChanged(int32 SlotIndex);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"WIDGET_PageTab_C">();
	}
	static class UWIDGET_PageTab_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UWIDGET_PageTab_C>();
	}
};
static_assert(alignof(UWIDGET_PageTab_C) == 0x000008, "Wrong alignment on UWIDGET_PageTab_C");
static_assert(sizeof(UWIDGET_PageTab_C) == 0x000308, "Wrong size on UWIDGET_PageTab_C");
static_assert(offsetof(UWIDGET_PageTab_C, UberGraphFrame) == 0x000260, "Member 'UWIDGET_PageTab_C::UberGraphFrame' has a wrong offset!");
static_assert(offsetof(UWIDGET_PageTab_C, TransitionDeselect) == 0x000268, "Member 'UWIDGET_PageTab_C::TransitionDeselect' has a wrong offset!");
static_assert(offsetof(UWIDGET_PageTab_C, TransitionLeave) == 0x000270, "Member 'UWIDGET_PageTab_C::TransitionLeave' has a wrong offset!");
static_assert(offsetof(UWIDGET_PageTab_C, TransitionSelect) == 0x000278, "Member 'UWIDGET_PageTab_C::TransitionSelect' has a wrong offset!");
static_assert(offsetof(UWIDGET_PageTab_C, TransitionEnter) == 0x000280, "Member 'UWIDGET_PageTab_C::TransitionEnter' has a wrong offset!");
static_assert(offsetof(UWIDGET_PageTab_C, MESH_Button) == 0x000288, "Member 'UWIDGET_PageTab_C::MESH_Button' has a wrong offset!");
static_assert(offsetof(UWIDGET_PageTab_C, MESH_HitArea) == 0x000290, "Member 'UWIDGET_PageTab_C::MESH_HitArea' has a wrong offset!");
static_assert(offsetof(UWIDGET_PageTab_C, TEXT_Label) == 0x000298, "Member 'UWIDGET_PageTab_C::TEXT_Label' has a wrong offset!");
static_assert(offsetof(UWIDGET_PageTab_C, WIDGET_UnreadMediaDot) == 0x0002A0, "Member 'UWIDGET_PageTab_C::WIDGET_UnreadMediaDot' has a wrong offset!");
static_assert(offsetof(UWIDGET_PageTab_C, Text) == 0x0002A8, "Member 'UWIDGET_PageTab_C::Text' has a wrong offset!");
static_assert(offsetof(UWIDGET_PageTab_C, OnMouseClick) == 0x0002C0, "Member 'UWIDGET_PageTab_C::OnMouseClick' has a wrong offset!");
static_assert(offsetof(UWIDGET_PageTab_C, OnMouseOver) == 0x0002D0, "Member 'UWIDGET_PageTab_C::OnMouseOver' has a wrong offset!");
static_assert(offsetof(UWIDGET_PageTab_C, OnMouseOut) == 0x0002E0, "Member 'UWIDGET_PageTab_C::OnMouseOut' has a wrong offset!");
static_assert(offsetof(UWIDGET_PageTab_C, bIsSelected) == 0x0002F0, "Member 'UWIDGET_PageTab_C::bIsSelected' has a wrong offset!");
static_assert(offsetof(UWIDGET_PageTab_C, RequiredHardware) == 0x0002F8, "Member 'UWIDGET_PageTab_C::RequiredHardware' has a wrong offset!");
static_assert(offsetof(UWIDGET_PageTab_C, HardwareBag) == 0x000300, "Member 'UWIDGET_PageTab_C::HardwareBag' has a wrong offset!");

}

