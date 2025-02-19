#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: WIDGET_OptionsMenu_DisplayList

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "WIDGET_MenuListBase_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass WIDGET_OptionsMenu_DisplayList.WIDGET_OptionsMenu_DisplayList_C
// 0x0078 (0x0340 - 0x02C8)
class UWIDGET_OptionsMenu_DisplayList_C final : public UWIDGET_MenuListBase_C
{
public:
	uint8                                         Pad_2C2[0x6];                                      // 0x02C2(0x0006)(Fixing Size After Last Property [ Dumper-7 ])
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x02C8(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UOPTION_Display_Brightness_C*           OPTION_Display_CyberspaceBrightness;               // 0x02D0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UOPTION_Display_FieldOfView_C*          OPTION_Display_CyberspaceFieldOfView;              // 0x02D8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UOPTION_Display_EnableHDR_C*            OPTION_Display_EnableHDR;                          // 0x02E0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UOPTION_Display_MotionBlur_C*           OPTION_Display_MotionBlurStrength;                 // 0x02E8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UOPTION_Display_Brightness_C*           OPTION_Display_RealspaceBrightness;                // 0x02F0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UOPTION_Display_FieldOfView_C*          OPTION_Display_RealspaceFieldOfView;               // 0x02F8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UOPTION_Display_Resolution_C*           OPTION_Display_Resolution;                         // 0x0300(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UOPTION_Display_ResolutionScaling_C*    OPTION_Display_ResolutionScaling;                  // 0x0308(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UOPTION_Display_VSync_C*                OPTION_Display_VSync;                              // 0x0310(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UOPTION_Display_WindowMode_C*           OPTION_Display_WindowMode;                         // 0x0318(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UScrollBox*                             SCROLLBOX_OptionsMenuList;                         // 0x0320(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UWIDGET_ListCategoryHeader_C*           WIDGET_ListCategoryHeader_Cyberspace;              // 0x0328(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UWIDGET_ListCategoryHeader_C*           WIDGET_ListCategoryHeader_General;                 // 0x0330(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UWIDGET_ListCategoryHeader_C*           WIDGET_ListCategoryHeader_Realspace;               // 0x0338(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_WIDGET_OptionsMenu_DisplayList(int32 EntryPoint);
	void BndEvt__WIDGET_OptionsMenu_DisplayList_OPTION_Display_WindowMode_K2Node_ComponentBoundEvent_0_OnWindowModeChanged__DelegateSignature();
	void InitializeItemArray(TArray<class UWIDGET_MenuListItemBase_C*>* MenuListItems);
	void InitializeList(class UWIDGET_MenuBase_C* ParentScreen);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"WIDGET_OptionsMenu_DisplayList_C">();
	}
	static class UWIDGET_OptionsMenu_DisplayList_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UWIDGET_OptionsMenu_DisplayList_C>();
	}
};
static_assert(alignof(UWIDGET_OptionsMenu_DisplayList_C) == 0x000008, "Wrong alignment on UWIDGET_OptionsMenu_DisplayList_C");
static_assert(sizeof(UWIDGET_OptionsMenu_DisplayList_C) == 0x000340, "Wrong size on UWIDGET_OptionsMenu_DisplayList_C");
static_assert(offsetof(UWIDGET_OptionsMenu_DisplayList_C, UberGraphFrame) == 0x0002C8, "Member 'UWIDGET_OptionsMenu_DisplayList_C::UberGraphFrame' has a wrong offset!");
static_assert(offsetof(UWIDGET_OptionsMenu_DisplayList_C, OPTION_Display_CyberspaceBrightness) == 0x0002D0, "Member 'UWIDGET_OptionsMenu_DisplayList_C::OPTION_Display_CyberspaceBrightness' has a wrong offset!");
static_assert(offsetof(UWIDGET_OptionsMenu_DisplayList_C, OPTION_Display_CyberspaceFieldOfView) == 0x0002D8, "Member 'UWIDGET_OptionsMenu_DisplayList_C::OPTION_Display_CyberspaceFieldOfView' has a wrong offset!");
static_assert(offsetof(UWIDGET_OptionsMenu_DisplayList_C, OPTION_Display_EnableHDR) == 0x0002E0, "Member 'UWIDGET_OptionsMenu_DisplayList_C::OPTION_Display_EnableHDR' has a wrong offset!");
static_assert(offsetof(UWIDGET_OptionsMenu_DisplayList_C, OPTION_Display_MotionBlurStrength) == 0x0002E8, "Member 'UWIDGET_OptionsMenu_DisplayList_C::OPTION_Display_MotionBlurStrength' has a wrong offset!");
static_assert(offsetof(UWIDGET_OptionsMenu_DisplayList_C, OPTION_Display_RealspaceBrightness) == 0x0002F0, "Member 'UWIDGET_OptionsMenu_DisplayList_C::OPTION_Display_RealspaceBrightness' has a wrong offset!");
static_assert(offsetof(UWIDGET_OptionsMenu_DisplayList_C, OPTION_Display_RealspaceFieldOfView) == 0x0002F8, "Member 'UWIDGET_OptionsMenu_DisplayList_C::OPTION_Display_RealspaceFieldOfView' has a wrong offset!");
static_assert(offsetof(UWIDGET_OptionsMenu_DisplayList_C, OPTION_Display_Resolution) == 0x000300, "Member 'UWIDGET_OptionsMenu_DisplayList_C::OPTION_Display_Resolution' has a wrong offset!");
static_assert(offsetof(UWIDGET_OptionsMenu_DisplayList_C, OPTION_Display_ResolutionScaling) == 0x000308, "Member 'UWIDGET_OptionsMenu_DisplayList_C::OPTION_Display_ResolutionScaling' has a wrong offset!");
static_assert(offsetof(UWIDGET_OptionsMenu_DisplayList_C, OPTION_Display_VSync) == 0x000310, "Member 'UWIDGET_OptionsMenu_DisplayList_C::OPTION_Display_VSync' has a wrong offset!");
static_assert(offsetof(UWIDGET_OptionsMenu_DisplayList_C, OPTION_Display_WindowMode) == 0x000318, "Member 'UWIDGET_OptionsMenu_DisplayList_C::OPTION_Display_WindowMode' has a wrong offset!");
static_assert(offsetof(UWIDGET_OptionsMenu_DisplayList_C, SCROLLBOX_OptionsMenuList) == 0x000320, "Member 'UWIDGET_OptionsMenu_DisplayList_C::SCROLLBOX_OptionsMenuList' has a wrong offset!");
static_assert(offsetof(UWIDGET_OptionsMenu_DisplayList_C, WIDGET_ListCategoryHeader_Cyberspace) == 0x000328, "Member 'UWIDGET_OptionsMenu_DisplayList_C::WIDGET_ListCategoryHeader_Cyberspace' has a wrong offset!");
static_assert(offsetof(UWIDGET_OptionsMenu_DisplayList_C, WIDGET_ListCategoryHeader_General) == 0x000330, "Member 'UWIDGET_OptionsMenu_DisplayList_C::WIDGET_ListCategoryHeader_General' has a wrong offset!");
static_assert(offsetof(UWIDGET_OptionsMenu_DisplayList_C, WIDGET_ListCategoryHeader_Realspace) == 0x000338, "Member 'UWIDGET_OptionsMenu_DisplayList_C::WIDGET_ListCategoryHeader_Realspace' has a wrong offset!");

}

