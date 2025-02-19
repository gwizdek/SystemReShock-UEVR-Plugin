#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: WIDGET_ButtonLegend_Button

#include "Basic.hpp"

#include "CoreUObject_structs.hpp"
#include "SlateCore_structs.hpp"
#include "UMG_structs.hpp"


namespace SDK::Params
{

// Function WIDGET_ButtonLegend_Button.WIDGET_ButtonLegend_Button_C.OnClicked__DelegateSignature
// 0x00A8 (0x00A8 - 0x0000)
struct WIDGET_ButtonLegend_Button_C_OnClicked__DelegateSignature final
{
public:
	struct FGeometry                              Geometry;                                          // 0x0000(0x0038)(BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData, NoDestructor)
	struct FPointerEvent                          InputEvent;                                        // 0x0038(0x0070)(BlueprintVisible, BlueprintReadOnly, Parm)
};
static_assert(alignof(WIDGET_ButtonLegend_Button_C_OnClicked__DelegateSignature) == 0x000008, "Wrong alignment on WIDGET_ButtonLegend_Button_C_OnClicked__DelegateSignature");
static_assert(sizeof(WIDGET_ButtonLegend_Button_C_OnClicked__DelegateSignature) == 0x0000A8, "Wrong size on WIDGET_ButtonLegend_Button_C_OnClicked__DelegateSignature");
static_assert(offsetof(WIDGET_ButtonLegend_Button_C_OnClicked__DelegateSignature, Geometry) == 0x000000, "Member 'WIDGET_ButtonLegend_Button_C_OnClicked__DelegateSignature::Geometry' has a wrong offset!");
static_assert(offsetof(WIDGET_ButtonLegend_Button_C_OnClicked__DelegateSignature, InputEvent) == 0x000038, "Member 'WIDGET_ButtonLegend_Button_C_OnClicked__DelegateSignature::InputEvent' has a wrong offset!");

// Function WIDGET_ButtonLegend_Button.WIDGET_ButtonLegend_Button_C.ExecuteUbergraph_WIDGET_ButtonLegend_Button
// 0x0024 (0x0024 - 0x0000)
struct WIDGET_ButtonLegend_Button_C_ExecuteUbergraph_WIDGET_ButtonLegend_Button final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TDelegate<void()>                             K2Node_CreateDelegate_OutputDelegate;              // 0x0004(0x0010)(ZeroConstructor, NoDestructor)
	bool                                          Temp_bool_Variable;                                // 0x0014(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          K2Node_Event_IsDesignTime;                         // 0x0015(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_16[0x2];                                       // 0x0016(0x0002)(Fixing Size After Last Property [ Dumper-7 ])
	struct FColor                                 CallFunc_GetMeshUIColor_Color;                     // 0x0018(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FColor                                 K2Node_MakeStruct_Color;                           // 0x001C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FColor                                 K2Node_Select_Default;                             // 0x0020(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(WIDGET_ButtonLegend_Button_C_ExecuteUbergraph_WIDGET_ButtonLegend_Button) == 0x000004, "Wrong alignment on WIDGET_ButtonLegend_Button_C_ExecuteUbergraph_WIDGET_ButtonLegend_Button");
static_assert(sizeof(WIDGET_ButtonLegend_Button_C_ExecuteUbergraph_WIDGET_ButtonLegend_Button) == 0x000024, "Wrong size on WIDGET_ButtonLegend_Button_C_ExecuteUbergraph_WIDGET_ButtonLegend_Button");
static_assert(offsetof(WIDGET_ButtonLegend_Button_C_ExecuteUbergraph_WIDGET_ButtonLegend_Button, EntryPoint) == 0x000000, "Member 'WIDGET_ButtonLegend_Button_C_ExecuteUbergraph_WIDGET_ButtonLegend_Button::EntryPoint' has a wrong offset!");
static_assert(offsetof(WIDGET_ButtonLegend_Button_C_ExecuteUbergraph_WIDGET_ButtonLegend_Button, K2Node_CreateDelegate_OutputDelegate) == 0x000004, "Member 'WIDGET_ButtonLegend_Button_C_ExecuteUbergraph_WIDGET_ButtonLegend_Button::K2Node_CreateDelegate_OutputDelegate' has a wrong offset!");
static_assert(offsetof(WIDGET_ButtonLegend_Button_C_ExecuteUbergraph_WIDGET_ButtonLegend_Button, Temp_bool_Variable) == 0x000014, "Member 'WIDGET_ButtonLegend_Button_C_ExecuteUbergraph_WIDGET_ButtonLegend_Button::Temp_bool_Variable' has a wrong offset!");
static_assert(offsetof(WIDGET_ButtonLegend_Button_C_ExecuteUbergraph_WIDGET_ButtonLegend_Button, K2Node_Event_IsDesignTime) == 0x000015, "Member 'WIDGET_ButtonLegend_Button_C_ExecuteUbergraph_WIDGET_ButtonLegend_Button::K2Node_Event_IsDesignTime' has a wrong offset!");
static_assert(offsetof(WIDGET_ButtonLegend_Button_C_ExecuteUbergraph_WIDGET_ButtonLegend_Button, CallFunc_GetMeshUIColor_Color) == 0x000018, "Member 'WIDGET_ButtonLegend_Button_C_ExecuteUbergraph_WIDGET_ButtonLegend_Button::CallFunc_GetMeshUIColor_Color' has a wrong offset!");
static_assert(offsetof(WIDGET_ButtonLegend_Button_C_ExecuteUbergraph_WIDGET_ButtonLegend_Button, K2Node_MakeStruct_Color) == 0x00001C, "Member 'WIDGET_ButtonLegend_Button_C_ExecuteUbergraph_WIDGET_ButtonLegend_Button::K2Node_MakeStruct_Color' has a wrong offset!");
static_assert(offsetof(WIDGET_ButtonLegend_Button_C_ExecuteUbergraph_WIDGET_ButtonLegend_Button, K2Node_Select_Default) == 0x000020, "Member 'WIDGET_ButtonLegend_Button_C_ExecuteUbergraph_WIDGET_ButtonLegend_Button::K2Node_Select_Default' has a wrong offset!");

// Function WIDGET_ButtonLegend_Button.WIDGET_ButtonLegend_Button_C.PreConstruct
// 0x0001 (0x0001 - 0x0000)
struct WIDGET_ButtonLegend_Button_C_PreConstruct final
{
public:
	bool                                          IsDesignTime;                                      // 0x0000(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(WIDGET_ButtonLegend_Button_C_PreConstruct) == 0x000001, "Wrong alignment on WIDGET_ButtonLegend_Button_C_PreConstruct");
static_assert(sizeof(WIDGET_ButtonLegend_Button_C_PreConstruct) == 0x000001, "Wrong size on WIDGET_ButtonLegend_Button_C_PreConstruct");
static_assert(offsetof(WIDGET_ButtonLegend_Button_C_PreConstruct, IsDesignTime) == 0x000000, "Member 'WIDGET_ButtonLegend_Button_C_PreConstruct::IsDesignTime' has a wrong offset!");

// Function WIDGET_ButtonLegend_Button.WIDGET_ButtonLegend_Button_C.UpdateKeyWidget
// 0x0001 (0x0001 - 0x0000)
struct WIDGET_ButtonLegend_Button_C_UpdateKeyWidget final
{
public:
	bool                                          CallFunc_IsEmpty_ReturnValue;                      // 0x0000(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(WIDGET_ButtonLegend_Button_C_UpdateKeyWidget) == 0x000001, "Wrong alignment on WIDGET_ButtonLegend_Button_C_UpdateKeyWidget");
static_assert(sizeof(WIDGET_ButtonLegend_Button_C_UpdateKeyWidget) == 0x000001, "Wrong size on WIDGET_ButtonLegend_Button_C_UpdateKeyWidget");
static_assert(offsetof(WIDGET_ButtonLegend_Button_C_UpdateKeyWidget, CallFunc_IsEmpty_ReturnValue) == 0x000000, "Member 'WIDGET_ButtonLegend_Button_C_UpdateKeyWidget::CallFunc_IsEmpty_ReturnValue' has a wrong offset!");

// Function WIDGET_ButtonLegend_Button.WIDGET_ButtonLegend_Button_C.HandleMouseEnter
// 0x0008 (0x0008 - 0x0000)
struct WIDGET_ButtonLegend_Button_C_HandleMouseEnter final
{
public:
	class UMaterialInstanceDynamic*               CallFunc_ConvertToDynamicMaterialInstance_ReturnValue; // 0x0000(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(WIDGET_ButtonLegend_Button_C_HandleMouseEnter) == 0x000008, "Wrong alignment on WIDGET_ButtonLegend_Button_C_HandleMouseEnter");
static_assert(sizeof(WIDGET_ButtonLegend_Button_C_HandleMouseEnter) == 0x000008, "Wrong size on WIDGET_ButtonLegend_Button_C_HandleMouseEnter");
static_assert(offsetof(WIDGET_ButtonLegend_Button_C_HandleMouseEnter, CallFunc_ConvertToDynamicMaterialInstance_ReturnValue) == 0x000000, "Member 'WIDGET_ButtonLegend_Button_C_HandleMouseEnter::CallFunc_ConvertToDynamicMaterialInstance_ReturnValue' has a wrong offset!");

// Function WIDGET_ButtonLegend_Button.WIDGET_ButtonLegend_Button_C.EVENT_OnMouseEnter
// 0x00A8 (0x00A8 - 0x0000)
struct WIDGET_ButtonLegend_Button_C_EVENT_OnMouseEnter final
{
public:
	struct FGeometry                              MyGeometry;                                        // 0x0000(0x0038)(ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm, IsPlainOldData, NoDestructor)
	struct FPointerEvent                          MouseEvent;                                        // 0x0038(0x0070)(ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
};
static_assert(alignof(WIDGET_ButtonLegend_Button_C_EVENT_OnMouseEnter) == 0x000008, "Wrong alignment on WIDGET_ButtonLegend_Button_C_EVENT_OnMouseEnter");
static_assert(sizeof(WIDGET_ButtonLegend_Button_C_EVENT_OnMouseEnter) == 0x0000A8, "Wrong size on WIDGET_ButtonLegend_Button_C_EVENT_OnMouseEnter");
static_assert(offsetof(WIDGET_ButtonLegend_Button_C_EVENT_OnMouseEnter, MyGeometry) == 0x000000, "Member 'WIDGET_ButtonLegend_Button_C_EVENT_OnMouseEnter::MyGeometry' has a wrong offset!");
static_assert(offsetof(WIDGET_ButtonLegend_Button_C_EVENT_OnMouseEnter, MouseEvent) == 0x000038, "Member 'WIDGET_ButtonLegend_Button_C_EVENT_OnMouseEnter::MouseEvent' has a wrong offset!");

// Function WIDGET_ButtonLegend_Button.WIDGET_ButtonLegend_Button_C.EVENT_OnMouseLeave
// 0x0070 (0x0070 - 0x0000)
struct WIDGET_ButtonLegend_Button_C_EVENT_OnMouseLeave final
{
public:
	struct FPointerEvent                          MouseEvent;                                        // 0x0000(0x0070)(ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
};
static_assert(alignof(WIDGET_ButtonLegend_Button_C_EVENT_OnMouseLeave) == 0x000008, "Wrong alignment on WIDGET_ButtonLegend_Button_C_EVENT_OnMouseLeave");
static_assert(sizeof(WIDGET_ButtonLegend_Button_C_EVENT_OnMouseLeave) == 0x000070, "Wrong size on WIDGET_ButtonLegend_Button_C_EVENT_OnMouseLeave");
static_assert(offsetof(WIDGET_ButtonLegend_Button_C_EVENT_OnMouseLeave, MouseEvent) == 0x000000, "Member 'WIDGET_ButtonLegend_Button_C_EVENT_OnMouseLeave::MouseEvent' has a wrong offset!");

// Function WIDGET_ButtonLegend_Button.WIDGET_ButtonLegend_Button_C.EVENT_OnMouseButtonDown
// 0x0218 (0x0218 - 0x0000)
struct WIDGET_ButtonLegend_Button_C_EVENT_OnMouseButtonDown final
{
public:
	struct FGeometry                              MyGeometry;                                        // 0x0000(0x0038)(BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData, NoDestructor)
	struct FPointerEvent                          MouseEvent;                                        // 0x0038(0x0070)(ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
	struct FEventReply                            ReturnValue;                                       // 0x00A8(0x00B8)(Parm, OutParm, ReturnParm)
	struct FEventReply                            CallFunc_Handled_ReturnValue;                      // 0x0160(0x00B8)()
};
static_assert(alignof(WIDGET_ButtonLegend_Button_C_EVENT_OnMouseButtonDown) == 0x000008, "Wrong alignment on WIDGET_ButtonLegend_Button_C_EVENT_OnMouseButtonDown");
static_assert(sizeof(WIDGET_ButtonLegend_Button_C_EVENT_OnMouseButtonDown) == 0x000218, "Wrong size on WIDGET_ButtonLegend_Button_C_EVENT_OnMouseButtonDown");
static_assert(offsetof(WIDGET_ButtonLegend_Button_C_EVENT_OnMouseButtonDown, MyGeometry) == 0x000000, "Member 'WIDGET_ButtonLegend_Button_C_EVENT_OnMouseButtonDown::MyGeometry' has a wrong offset!");
static_assert(offsetof(WIDGET_ButtonLegend_Button_C_EVENT_OnMouseButtonDown, MouseEvent) == 0x000038, "Member 'WIDGET_ButtonLegend_Button_C_EVENT_OnMouseButtonDown::MouseEvent' has a wrong offset!");
static_assert(offsetof(WIDGET_ButtonLegend_Button_C_EVENT_OnMouseButtonDown, ReturnValue) == 0x0000A8, "Member 'WIDGET_ButtonLegend_Button_C_EVENT_OnMouseButtonDown::ReturnValue' has a wrong offset!");
static_assert(offsetof(WIDGET_ButtonLegend_Button_C_EVENT_OnMouseButtonDown, CallFunc_Handled_ReturnValue) == 0x000160, "Member 'WIDGET_ButtonLegend_Button_C_EVENT_OnMouseButtonDown::CallFunc_Handled_ReturnValue' has a wrong offset!");

// Function WIDGET_ButtonLegend_Button.WIDGET_ButtonLegend_Button_C.HandleMouseLeave
// 0x0008 (0x0008 - 0x0000)
struct WIDGET_ButtonLegend_Button_C_HandleMouseLeave final
{
public:
	class UMaterialInstanceDynamic*               CallFunc_ConvertToDynamicMaterialInstance_ReturnValue; // 0x0000(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(WIDGET_ButtonLegend_Button_C_HandleMouseLeave) == 0x000008, "Wrong alignment on WIDGET_ButtonLegend_Button_C_HandleMouseLeave");
static_assert(sizeof(WIDGET_ButtonLegend_Button_C_HandleMouseLeave) == 0x000008, "Wrong size on WIDGET_ButtonLegend_Button_C_HandleMouseLeave");
static_assert(offsetof(WIDGET_ButtonLegend_Button_C_HandleMouseLeave, CallFunc_ConvertToDynamicMaterialInstance_ReturnValue) == 0x000000, "Member 'WIDGET_ButtonLegend_Button_C_HandleMouseLeave::CallFunc_ConvertToDynamicMaterialInstance_ReturnValue' has a wrong offset!");

// Function WIDGET_ButtonLegend_Button.WIDGET_ButtonLegend_Button_C.ToggleInteractivity
// 0x0002 (0x0002 - 0x0000)
struct WIDGET_ButtonLegend_Button_C_ToggleInteractivity final
{
public:
	bool                                          IsInteractive;                                     // 0x0000(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_Not_PreBool_ReturnValue;                  // 0x0001(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(WIDGET_ButtonLegend_Button_C_ToggleInteractivity) == 0x000001, "Wrong alignment on WIDGET_ButtonLegend_Button_C_ToggleInteractivity");
static_assert(sizeof(WIDGET_ButtonLegend_Button_C_ToggleInteractivity) == 0x000002, "Wrong size on WIDGET_ButtonLegend_Button_C_ToggleInteractivity");
static_assert(offsetof(WIDGET_ButtonLegend_Button_C_ToggleInteractivity, IsInteractive) == 0x000000, "Member 'WIDGET_ButtonLegend_Button_C_ToggleInteractivity::IsInteractive' has a wrong offset!");
static_assert(offsetof(WIDGET_ButtonLegend_Button_C_ToggleInteractivity, CallFunc_Not_PreBool_ReturnValue) == 0x000001, "Member 'WIDGET_ButtonLegend_Button_C_ToggleInteractivity::CallFunc_Not_PreBool_ReturnValue' has a wrong offset!");

// Function WIDGET_ButtonLegend_Button.WIDGET_ButtonLegend_Button_C.SetButtonActionText
// 0x0018 (0x0018 - 0x0000)
struct WIDGET_ButtonLegend_Button_C_SetButtonActionText final
{
public:
	class FText                                   NewText;                                           // 0x0000(0x0018)(BlueprintVisible, BlueprintReadOnly, Parm)
};
static_assert(alignof(WIDGET_ButtonLegend_Button_C_SetButtonActionText) == 0x000008, "Wrong alignment on WIDGET_ButtonLegend_Button_C_SetButtonActionText");
static_assert(sizeof(WIDGET_ButtonLegend_Button_C_SetButtonActionText) == 0x000018, "Wrong size on WIDGET_ButtonLegend_Button_C_SetButtonActionText");
static_assert(offsetof(WIDGET_ButtonLegend_Button_C_SetButtonActionText, NewText) == 0x000000, "Member 'WIDGET_ButtonLegend_Button_C_SetButtonActionText::NewText' has a wrong offset!");

// Function WIDGET_ButtonLegend_Button.WIDGET_ButtonLegend_Button_C.UpdateTextDistanceFromIcon
// 0x0030 (0x0030 - 0x0000)
struct WIDGET_ButtonLegend_Button_C_UpdateTextDistanceFromIcon final
{
public:
	float                                         KeyWidgetSize;                                     // 0x0000(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_Add_FloatFloat_ReturnValue;               // 0x0004(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UCanvasPanelSlot*                       CallFunc_SlotAsCanvasSlot_ReturnValue;             // 0x0008(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector2D                              CallFunc_MakeVector2D_ReturnValue;                 // 0x0010(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UCanvasPanelSlot*                       CallFunc_SlotAsCanvasSlot_ReturnValue_1;           // 0x0018(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector2D                              CallFunc_GetSize_ReturnValue;                      // 0x0020(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_BreakVector2D_X;                          // 0x0028(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_BreakVector2D_Y;                          // 0x002C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(WIDGET_ButtonLegend_Button_C_UpdateTextDistanceFromIcon) == 0x000008, "Wrong alignment on WIDGET_ButtonLegend_Button_C_UpdateTextDistanceFromIcon");
static_assert(sizeof(WIDGET_ButtonLegend_Button_C_UpdateTextDistanceFromIcon) == 0x000030, "Wrong size on WIDGET_ButtonLegend_Button_C_UpdateTextDistanceFromIcon");
static_assert(offsetof(WIDGET_ButtonLegend_Button_C_UpdateTextDistanceFromIcon, KeyWidgetSize) == 0x000000, "Member 'WIDGET_ButtonLegend_Button_C_UpdateTextDistanceFromIcon::KeyWidgetSize' has a wrong offset!");
static_assert(offsetof(WIDGET_ButtonLegend_Button_C_UpdateTextDistanceFromIcon, CallFunc_Add_FloatFloat_ReturnValue) == 0x000004, "Member 'WIDGET_ButtonLegend_Button_C_UpdateTextDistanceFromIcon::CallFunc_Add_FloatFloat_ReturnValue' has a wrong offset!");
static_assert(offsetof(WIDGET_ButtonLegend_Button_C_UpdateTextDistanceFromIcon, CallFunc_SlotAsCanvasSlot_ReturnValue) == 0x000008, "Member 'WIDGET_ButtonLegend_Button_C_UpdateTextDistanceFromIcon::CallFunc_SlotAsCanvasSlot_ReturnValue' has a wrong offset!");
static_assert(offsetof(WIDGET_ButtonLegend_Button_C_UpdateTextDistanceFromIcon, CallFunc_MakeVector2D_ReturnValue) == 0x000010, "Member 'WIDGET_ButtonLegend_Button_C_UpdateTextDistanceFromIcon::CallFunc_MakeVector2D_ReturnValue' has a wrong offset!");
static_assert(offsetof(WIDGET_ButtonLegend_Button_C_UpdateTextDistanceFromIcon, CallFunc_SlotAsCanvasSlot_ReturnValue_1) == 0x000018, "Member 'WIDGET_ButtonLegend_Button_C_UpdateTextDistanceFromIcon::CallFunc_SlotAsCanvasSlot_ReturnValue_1' has a wrong offset!");
static_assert(offsetof(WIDGET_ButtonLegend_Button_C_UpdateTextDistanceFromIcon, CallFunc_GetSize_ReturnValue) == 0x000020, "Member 'WIDGET_ButtonLegend_Button_C_UpdateTextDistanceFromIcon::CallFunc_GetSize_ReturnValue' has a wrong offset!");
static_assert(offsetof(WIDGET_ButtonLegend_Button_C_UpdateTextDistanceFromIcon, CallFunc_BreakVector2D_X) == 0x000028, "Member 'WIDGET_ButtonLegend_Button_C_UpdateTextDistanceFromIcon::CallFunc_BreakVector2D_X' has a wrong offset!");
static_assert(offsetof(WIDGET_ButtonLegend_Button_C_UpdateTextDistanceFromIcon, CallFunc_BreakVector2D_Y) == 0x00002C, "Member 'WIDGET_ButtonLegend_Button_C_UpdateTextDistanceFromIcon::CallFunc_BreakVector2D_Y' has a wrong offset!");

// Function WIDGET_ButtonLegend_Button.WIDGET_ButtonLegend_Button_C.UpdateMaterials
// 0x0010 (0x0010 - 0x0000)
struct WIDGET_ButtonLegend_Button_C_UpdateMaterials final
{
public:
	class UMaterialInstanceDynamic*               CallFunc_ConvertToDynamicMaterialInstance_ReturnValue; // 0x0000(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_SelectFloat_ReturnValue;                  // 0x0008(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(WIDGET_ButtonLegend_Button_C_UpdateMaterials) == 0x000008, "Wrong alignment on WIDGET_ButtonLegend_Button_C_UpdateMaterials");
static_assert(sizeof(WIDGET_ButtonLegend_Button_C_UpdateMaterials) == 0x000010, "Wrong size on WIDGET_ButtonLegend_Button_C_UpdateMaterials");
static_assert(offsetof(WIDGET_ButtonLegend_Button_C_UpdateMaterials, CallFunc_ConvertToDynamicMaterialInstance_ReturnValue) == 0x000000, "Member 'WIDGET_ButtonLegend_Button_C_UpdateMaterials::CallFunc_ConvertToDynamicMaterialInstance_ReturnValue' has a wrong offset!");
static_assert(offsetof(WIDGET_ButtonLegend_Button_C_UpdateMaterials, CallFunc_SelectFloat_ReturnValue) == 0x000008, "Member 'WIDGET_ButtonLegend_Button_C_UpdateMaterials::CallFunc_SelectFloat_ReturnValue' has a wrong offset!");

}

