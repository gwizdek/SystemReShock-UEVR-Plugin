#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: WIDGET_ScalableButton

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "UMG_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass WIDGET_ScalableButton.WIDGET_ScalableButton_C
// 0x0068 (0x02C8 - 0x0260)
class UWIDGET_ScalableButton_C final : public UUserWidget
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0260(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UWidgetAnimation*                       ANIM_OnMouseDown;                                  // 0x0268(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UWidgetAnimation*                       ANIM_OnMouseActivate;                              // 0x0270(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UWidgetAnimation*                       ANIM_OnMouseEnter;                                 // 0x0278(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UGridMeshWidget*                        MESH_Background;                                   // 0x0280(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UTextMeshWidget*                        TEXT_Caption;                                      // 0x0288(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	float                                         FontSize;                                          // 0x0290(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, ExposeOnSpawn, HasGetValueTypeHash)
	uint8                                         Pad_294[0x4];                                      // 0x0294(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class FText                                   Caption;                                           // 0x0298(0x0018)(Edit, BlueprintVisible, ExposeOnSpawn)
	FMulticastInlineDelegateProperty_             OnMouseButtonActivated;                            // 0x02B0(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, BlueprintAssignable, BlueprintCallable)
	bool                                          IsButtonEnabled;                                   // 0x02C0(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, ExposeOnSpawn)
	bool                                          ActivateOnMouseUp;                                 // 0x02C1(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, ExposeOnSpawn)
	bool                                          PlayActivateAnimation;                             // 0x02C2(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, ExposeOnSpawn)
	bool                                          IsActivating;                                      // 0x02C3(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	bool                                          IsMouseOver;                                       // 0x02C4(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)

public:
	void OnMouseButtonActivated__DelegateSignature(const struct FGeometry& MyGeometry, const struct FPointerEvent& MouseEvent);
	void ExecuteUbergraph_WIDGET_ScalableButton(int32 EntryPoint);
	void PreConstruct(bool IsDesignTime);
	struct FEventReply EVENT_OnMouseButtonDown(const struct FGeometry& MyGeometry, const struct FPointerEvent& MouseEvent);
	struct FEventReply EVENT_OnMouseButtonUp(const struct FGeometry& MyGeometry, const struct FPointerEvent& MouseEvent);
	void EVENT_OnMouseEnter(const struct FGeometry& MyGeometry, const struct FPointerEvent& MouseEvent);
	void EVENT_OnMouseLeave(const struct FPointerEvent& MouseEvent);
	void SetButtonEnabled(bool Enabled);
	void ResetButton();
	void EVENT_OnActivationFinished();
	void OnEnabledStateChanged();
	void SetCaption(const class FText& Caption_0);
	void GetButtonEnabled(bool* IsEnabled);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"WIDGET_ScalableButton_C">();
	}
	static class UWIDGET_ScalableButton_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UWIDGET_ScalableButton_C>();
	}
};
static_assert(alignof(UWIDGET_ScalableButton_C) == 0x000008, "Wrong alignment on UWIDGET_ScalableButton_C");
static_assert(sizeof(UWIDGET_ScalableButton_C) == 0x0002C8, "Wrong size on UWIDGET_ScalableButton_C");
static_assert(offsetof(UWIDGET_ScalableButton_C, UberGraphFrame) == 0x000260, "Member 'UWIDGET_ScalableButton_C::UberGraphFrame' has a wrong offset!");
static_assert(offsetof(UWIDGET_ScalableButton_C, ANIM_OnMouseDown) == 0x000268, "Member 'UWIDGET_ScalableButton_C::ANIM_OnMouseDown' has a wrong offset!");
static_assert(offsetof(UWIDGET_ScalableButton_C, ANIM_OnMouseActivate) == 0x000270, "Member 'UWIDGET_ScalableButton_C::ANIM_OnMouseActivate' has a wrong offset!");
static_assert(offsetof(UWIDGET_ScalableButton_C, ANIM_OnMouseEnter) == 0x000278, "Member 'UWIDGET_ScalableButton_C::ANIM_OnMouseEnter' has a wrong offset!");
static_assert(offsetof(UWIDGET_ScalableButton_C, MESH_Background) == 0x000280, "Member 'UWIDGET_ScalableButton_C::MESH_Background' has a wrong offset!");
static_assert(offsetof(UWIDGET_ScalableButton_C, TEXT_Caption) == 0x000288, "Member 'UWIDGET_ScalableButton_C::TEXT_Caption' has a wrong offset!");
static_assert(offsetof(UWIDGET_ScalableButton_C, FontSize) == 0x000290, "Member 'UWIDGET_ScalableButton_C::FontSize' has a wrong offset!");
static_assert(offsetof(UWIDGET_ScalableButton_C, Caption) == 0x000298, "Member 'UWIDGET_ScalableButton_C::Caption' has a wrong offset!");
static_assert(offsetof(UWIDGET_ScalableButton_C, OnMouseButtonActivated) == 0x0002B0, "Member 'UWIDGET_ScalableButton_C::OnMouseButtonActivated' has a wrong offset!");
static_assert(offsetof(UWIDGET_ScalableButton_C, IsButtonEnabled) == 0x0002C0, "Member 'UWIDGET_ScalableButton_C::IsButtonEnabled' has a wrong offset!");
static_assert(offsetof(UWIDGET_ScalableButton_C, ActivateOnMouseUp) == 0x0002C1, "Member 'UWIDGET_ScalableButton_C::ActivateOnMouseUp' has a wrong offset!");
static_assert(offsetof(UWIDGET_ScalableButton_C, PlayActivateAnimation) == 0x0002C2, "Member 'UWIDGET_ScalableButton_C::PlayActivateAnimation' has a wrong offset!");
static_assert(offsetof(UWIDGET_ScalableButton_C, IsActivating) == 0x0002C3, "Member 'UWIDGET_ScalableButton_C::IsActivating' has a wrong offset!");
static_assert(offsetof(UWIDGET_ScalableButton_C, IsMouseOver) == 0x0002C4, "Member 'UWIDGET_ScalableButton_C::IsMouseOver' has a wrong offset!");

}

