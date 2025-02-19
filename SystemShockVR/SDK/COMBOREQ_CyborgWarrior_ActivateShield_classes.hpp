#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: COMBOREQ_CyborgWarrior_ActivateShield

#include "Basic.hpp"

#include "COMBOREQ_Base_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass COMBOREQ_CyborgWarrior_ActivateShield.COMBOREQ_CyborgWarrior_ActivateShield_C
// 0x0000 (0x0028 - 0x0028)
class UCOMBOREQ_CyborgWarrior_ActivateShield_C final : public UCOMBOREQ_Base_C
{
public:
	void CanStartCombo(class APAWN_Enemy_C* EnemyPawn, int32 ComboIndex, bool* Result);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"COMBOREQ_CyborgWarrior_ActivateShield_C">();
	}
	static class UCOMBOREQ_CyborgWarrior_ActivateShield_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UCOMBOREQ_CyborgWarrior_ActivateShield_C>();
	}
};
static_assert(alignof(UCOMBOREQ_CyborgWarrior_ActivateShield_C) == 0x000008, "Wrong alignment on UCOMBOREQ_CyborgWarrior_ActivateShield_C");
static_assert(sizeof(UCOMBOREQ_CyborgWarrior_ActivateShield_C) == 0x000028, "Wrong size on UCOMBOREQ_CyborgWarrior_ActivateShield_C");

}

