#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: DEBUG_MapMove

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "WIDGET_DebugListItem_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass DEBUG_MapMove.DEBUG_MapMove_C
// 0x0010 (0x0370 - 0x0360)
class UDEBUG_MapMove_C final : public UWIDGET_DebugListItem_C
{
public:
	uint8                                         Pad_35A[0x6];                                      // 0x035A(0x0006)(Fixing Size After Last Property [ Dumper-7 ])
	struct FDataTableRowHandle                    TargetLevel;                                       // 0x0360(0x0010)(Edit, BlueprintVisible, NoDestructor)

public:
	void TriggerDebugFunction(bool* Handled);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"DEBUG_MapMove_C">();
	}
	static class UDEBUG_MapMove_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UDEBUG_MapMove_C>();
	}
};
static_assert(alignof(UDEBUG_MapMove_C) == 0x000008, "Wrong alignment on UDEBUG_MapMove_C");
static_assert(sizeof(UDEBUG_MapMove_C) == 0x000370, "Wrong size on UDEBUG_MapMove_C");
static_assert(offsetof(UDEBUG_MapMove_C, TargetLevel) == 0x000360, "Member 'UDEBUG_MapMove_C::TargetLevel' has a wrong offset!");

}

