#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: SKILL_Mantis_Melee_Long

#include "Basic.hpp"

#include "SKILL_MeleeDamage_Base_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass SKILL_Mantis_Melee_Long.SKILL_Mantis_Melee_Long_C
// 0x0000 (0x00C0 - 0x00C0)
class USKILL_Mantis_Melee_Long_C final : public USKILL_MeleeDamage_Base_C
{
public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"SKILL_Mantis_Melee_Long_C">();
	}
	static class USKILL_Mantis_Melee_Long_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<USKILL_Mantis_Melee_Long_C>();
	}
};
static_assert(alignof(USKILL_Mantis_Melee_Long_C) == 0x000008, "Wrong alignment on USKILL_Mantis_Melee_Long_C");
static_assert(sizeof(USKILL_Mantis_Melee_Long_C) == 0x0000C0, "Wrong size on USKILL_Mantis_Melee_Long_C");

}

