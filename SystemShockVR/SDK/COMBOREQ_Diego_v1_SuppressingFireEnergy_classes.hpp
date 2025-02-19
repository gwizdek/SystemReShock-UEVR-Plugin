#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: COMBOREQ_Diego_v1_SuppressingFireEnergy

#include "Basic.hpp"

#include "COMBOREQ_LineOfSightCheck_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass COMBOREQ_Diego_v1_SuppressingFireEnergy.COMBOREQ_Diego_v1_SuppressingFireEnergy_C
// 0x0008 (0x0030 - 0x0028)
class UCOMBOREQ_Diego_v1_SuppressingFireEnergy_C final : public UCOMBOREQ_LineOfSightCheck_C
{
public:
	float                                         SuppressingFireEnergy;                             // 0x0028(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void CanStartCombo(class APAWN_Enemy_C* EnemyPawn, int32 ComboIndex, bool* Result);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"COMBOREQ_Diego_v1_SuppressingFireEnergy_C">();
	}
	static class UCOMBOREQ_Diego_v1_SuppressingFireEnergy_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UCOMBOREQ_Diego_v1_SuppressingFireEnergy_C>();
	}
};
static_assert(alignof(UCOMBOREQ_Diego_v1_SuppressingFireEnergy_C) == 0x000008, "Wrong alignment on UCOMBOREQ_Diego_v1_SuppressingFireEnergy_C");
static_assert(sizeof(UCOMBOREQ_Diego_v1_SuppressingFireEnergy_C) == 0x000030, "Wrong size on UCOMBOREQ_Diego_v1_SuppressingFireEnergy_C");
static_assert(offsetof(UCOMBOREQ_Diego_v1_SuppressingFireEnergy_C, SuppressingFireEnergy) == 0x000028, "Member 'UCOMBOREQ_Diego_v1_SuppressingFireEnergy_C::SuppressingFireEnergy' has a wrong offset!");

}

