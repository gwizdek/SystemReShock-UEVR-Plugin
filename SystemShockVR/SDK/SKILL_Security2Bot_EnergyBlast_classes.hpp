#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: SKILL_Security2Bot_EnergyBlast

#include "Basic.hpp"

#include "Skill_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass SKILL_Security2Bot_EnergyBlast.SKILL_Security2Bot_EnergyBlast_C
// 0x0010 (0x00A0 - 0x0090)
class USKILL_Security2Bot_EnergyBlast_C : public USkill_C
{
public:
	class FName                                   EnergyBlastSocket;                                 // 0x0090(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         BeamRange;                                         // 0x0098(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void OnActivateSkill(bool* Result);
	void OnDeactivateSkill(bool* Result);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"SKILL_Security2Bot_EnergyBlast_C">();
	}
	static class USKILL_Security2Bot_EnergyBlast_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<USKILL_Security2Bot_EnergyBlast_C>();
	}
};
static_assert(alignof(USKILL_Security2Bot_EnergyBlast_C) == 0x000008, "Wrong alignment on USKILL_Security2Bot_EnergyBlast_C");
static_assert(sizeof(USKILL_Security2Bot_EnergyBlast_C) == 0x0000A0, "Wrong size on USKILL_Security2Bot_EnergyBlast_C");
static_assert(offsetof(USKILL_Security2Bot_EnergyBlast_C, EnergyBlastSocket) == 0x000090, "Member 'USKILL_Security2Bot_EnergyBlast_C::EnergyBlastSocket' has a wrong offset!");
static_assert(offsetof(USKILL_Security2Bot_EnergyBlast_C, BeamRange) == 0x000098, "Member 'USKILL_Security2Bot_EnergyBlast_C::BeamRange' has a wrong offset!");

}

