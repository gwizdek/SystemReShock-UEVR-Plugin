#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: WIDGET_SubMenu_Breadcrumb

#include "Basic.hpp"

#include "UMG_structs.hpp"
#include "UMG_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass WIDGET_SubMenu_Breadcrumb.WIDGET_SubMenu_Breadcrumb_C
// 0x0018 (0x0278 - 0x0260)
class UWIDGET_SubMenu_Breadcrumb_C final : public UUserWidget
{
public:
	class UWidgetAnimation*                       BreadcrumbEnable;                                  // 0x0260(0x0008)(BlueprintVisible, BlueprintReadOnly, ZeroConstructor, Transient, IsPlainOldData, RepSkip, NoDestructor, HasGetValueTypeHash)
	class UCanvasPanel*                           PANEL_Breadcrumb;                                  // 0x0268(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UTextBlock*                             TEXT_BreadcrumbLabel;                              // 0x0270(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)

public:
	void EnableBreadcrumb(const class FText& Breadcrumb);
	void ChangeBreadcrumb(const class FText& Breadcrumb);
	void DisableBreadcrumb();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"WIDGET_SubMenu_Breadcrumb_C">();
	}
	static class UWIDGET_SubMenu_Breadcrumb_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UWIDGET_SubMenu_Breadcrumb_C>();
	}
};
static_assert(alignof(UWIDGET_SubMenu_Breadcrumb_C) == 0x000008, "Wrong alignment on UWIDGET_SubMenu_Breadcrumb_C");
static_assert(sizeof(UWIDGET_SubMenu_Breadcrumb_C) == 0x000278, "Wrong size on UWIDGET_SubMenu_Breadcrumb_C");
static_assert(offsetof(UWIDGET_SubMenu_Breadcrumb_C, BreadcrumbEnable) == 0x000260, "Member 'UWIDGET_SubMenu_Breadcrumb_C::BreadcrumbEnable' has a wrong offset!");
static_assert(offsetof(UWIDGET_SubMenu_Breadcrumb_C, PANEL_Breadcrumb) == 0x000268, "Member 'UWIDGET_SubMenu_Breadcrumb_C::PANEL_Breadcrumb' has a wrong offset!");
static_assert(offsetof(UWIDGET_SubMenu_Breadcrumb_C, TEXT_BreadcrumbLabel) == 0x000270, "Member 'UWIDGET_SubMenu_Breadcrumb_C::TEXT_BreadcrumbLabel' has a wrong offset!");

}

