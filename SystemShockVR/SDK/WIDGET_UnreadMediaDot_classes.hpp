#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: WIDGET_UnreadMediaDot

#include "Basic.hpp"

#include "UMG_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass WIDGET_UnreadMediaDot.WIDGET_UnreadMediaDot_C
// 0x0008 (0x0268 - 0x0260)
class UWIDGET_UnreadMediaDot_C final : public UUserWidget
{
public:
	class UGridMeshWidget*                        GridMeshWidget_0;                                  // 0x0260(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"WIDGET_UnreadMediaDot_C">();
	}
	static class UWIDGET_UnreadMediaDot_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UWIDGET_UnreadMediaDot_C>();
	}
};
static_assert(alignof(UWIDGET_UnreadMediaDot_C) == 0x000008, "Wrong alignment on UWIDGET_UnreadMediaDot_C");
static_assert(sizeof(UWIDGET_UnreadMediaDot_C) == 0x000268, "Wrong size on UWIDGET_UnreadMediaDot_C");
static_assert(offsetof(UWIDGET_UnreadMediaDot_C, GridMeshWidget_0) == 0x000260, "Member 'UWIDGET_UnreadMediaDot_C::GridMeshWidget_0' has a wrong offset!");

}

