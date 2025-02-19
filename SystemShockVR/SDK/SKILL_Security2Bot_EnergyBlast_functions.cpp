#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: SKILL_Security2Bot_EnergyBlast

#include "Basic.hpp"

#include "SKILL_Security2Bot_EnergyBlast_classes.hpp"
#include "SKILL_Security2Bot_EnergyBlast_parameters.hpp"


namespace SDK
{

// Function SKILL_Security2Bot_EnergyBlast.SKILL_Security2Bot_EnergyBlast_C.OnActivateSkill
// (Protected, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void USKILL_Security2Bot_EnergyBlast_C::OnActivateSkill(bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("SKILL_Security2Bot_EnergyBlast_C", "OnActivateSkill");

	Params::SKILL_Security2Bot_EnergyBlast_C_OnActivateSkill Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function SKILL_Security2Bot_EnergyBlast.SKILL_Security2Bot_EnergyBlast_C.OnDeactivateSkill
// (Protected, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void USKILL_Security2Bot_EnergyBlast_C::OnDeactivateSkill(bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("SKILL_Security2Bot_EnergyBlast_C", "OnDeactivateSkill");

	Params::SKILL_Security2Bot_EnergyBlast_C_OnDeactivateSkill Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}

}

