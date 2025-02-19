#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: DEC_HasPatrolNode

#include "Basic.hpp"

#include "AIModule_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass DEC_HasPatrolNode.DEC_HasPatrolNode_C
// 0x0008 (0x00A8 - 0x00A0)
class UDEC_HasPatrolNode_C final : public UBTDecorator_BlueprintBase
{
public:
	bool                                          IsEndOfRoute;                                      // 0x00A0(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)

public:
	bool PerformConditionCheckAI(class AAIController* OwnerController, class APawn* ControlledPawn);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"DEC_HasPatrolNode_C">();
	}
	static class UDEC_HasPatrolNode_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UDEC_HasPatrolNode_C>();
	}
};
static_assert(alignof(UDEC_HasPatrolNode_C) == 0x000008, "Wrong alignment on UDEC_HasPatrolNode_C");
static_assert(sizeof(UDEC_HasPatrolNode_C) == 0x0000A8, "Wrong size on UDEC_HasPatrolNode_C");
static_assert(offsetof(UDEC_HasPatrolNode_C, IsEndOfRoute) == 0x0000A0, "Member 'UDEC_HasPatrolNode_C::IsEndOfRoute' has a wrong offset!");

}

