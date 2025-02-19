#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: DEC_HasSeenPlayerRecently

#include "Basic.hpp"

#include "AIModule_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass DEC_HasSeenPlayerRecently.DEC_HasSeenPlayerRecently_C
// 0x0008 (0x00A8 - 0x00A0)
class UDEC_HasSeenPlayerRecently_C final : public UBTDecorator_BlueprintBase
{
public:
	float                                         TimeThreshold;                                     // 0x00A0(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	bool PerformConditionCheckAI(class AAIController* OwnerController, class APawn* ControlledPawn);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"DEC_HasSeenPlayerRecently_C">();
	}
	static class UDEC_HasSeenPlayerRecently_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UDEC_HasSeenPlayerRecently_C>();
	}
};
static_assert(alignof(UDEC_HasSeenPlayerRecently_C) == 0x000008, "Wrong alignment on UDEC_HasSeenPlayerRecently_C");
static_assert(sizeof(UDEC_HasSeenPlayerRecently_C) == 0x0000A8, "Wrong size on UDEC_HasSeenPlayerRecently_C");
static_assert(offsetof(UDEC_HasSeenPlayerRecently_C, TimeThreshold) == 0x0000A0, "Member 'UDEC_HasSeenPlayerRecently_C::TimeThreshold' has a wrong offset!");

}

