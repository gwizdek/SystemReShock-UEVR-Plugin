#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PICKUP_LogicProbe

#include "Basic.hpp"

#include "PICKUP_Base_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass PICKUP_LogicProbe.PICKUP_LogicProbe_C
// 0x0008 (0x0480 - 0x0478)
class APICKUP_LogicProbe_C final : public APICKUP_Base_C
{
public:
	uint8                                         Pad_474[0x4];                                      // 0x0474(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UNiagaraComponent*                      FlashingLight;                                     // 0x0478(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"PICKUP_LogicProbe_C">();
	}
	static class APICKUP_LogicProbe_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<APICKUP_LogicProbe_C>();
	}
};
static_assert(alignof(APICKUP_LogicProbe_C) == 0x000008, "Wrong alignment on APICKUP_LogicProbe_C");
static_assert(sizeof(APICKUP_LogicProbe_C) == 0x000480, "Wrong size on APICKUP_LogicProbe_C");
static_assert(offsetof(APICKUP_LogicProbe_C, FlashingLight) == 0x000478, "Member 'APICKUP_LogicProbe_C::FlashingLight' has a wrong offset!");

}

