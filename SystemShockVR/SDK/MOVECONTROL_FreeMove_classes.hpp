#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: MOVECONTROL_FreeMove

#include "Basic.hpp"

#include "MOVECONTROL_Base_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass MOVECONTROL_FreeMove.MOVECONTROL_FreeMove_C
// 0x0000 (0x0098 - 0x0098)
class UMOVECONTROL_FreeMove_C final : public UMOVECONTROL_Base_C
{
public:
	void UpdateMoveControl(const struct FVector2D& MoveInput, const struct FVector2D& LookInput, const struct FSTRUCT_MoveControlParams& ControlParams, TArray<float>& ActionInputValues, float MoveInputScale, float Delta_Time, bool* ShouldExpire);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"MOVECONTROL_FreeMove_C">();
	}
	static class UMOVECONTROL_FreeMove_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UMOVECONTROL_FreeMove_C>();
	}
};
static_assert(alignof(UMOVECONTROL_FreeMove_C) == 0x000008, "Wrong alignment on UMOVECONTROL_FreeMove_C");
static_assert(sizeof(UMOVECONTROL_FreeMove_C) == 0x000098, "Wrong size on UMOVECONTROL_FreeMove_C");

}

