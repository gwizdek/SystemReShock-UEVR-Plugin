#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: INTERF_Anim_Crate

#include "Basic.hpp"


namespace SDK::Params
{

// Function INTERF_Anim_Crate.INTERF_Anim_Crate_C.SetAngle
// 0x0008 (0x0008 - 0x0000)
struct INTERF_Anim_Crate_C_SetAngle final
{
public:
	float                                         NewAngle;                                          // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Result;                                            // 0x0004(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(INTERF_Anim_Crate_C_SetAngle) == 0x000004, "Wrong alignment on INTERF_Anim_Crate_C_SetAngle");
static_assert(sizeof(INTERF_Anim_Crate_C_SetAngle) == 0x000008, "Wrong size on INTERF_Anim_Crate_C_SetAngle");
static_assert(offsetof(INTERF_Anim_Crate_C_SetAngle, NewAngle) == 0x000000, "Member 'INTERF_Anim_Crate_C_SetAngle::NewAngle' has a wrong offset!");
static_assert(offsetof(INTERF_Anim_Crate_C_SetAngle, Result) == 0x000004, "Member 'INTERF_Anim_Crate_C_SetAngle::Result' has a wrong offset!");

// Function INTERF_Anim_Crate.INTERF_Anim_Crate_C.SetPhase
// 0x0008 (0x0008 - 0x0000)
struct INTERF_Anim_Crate_C_SetPhase final
{
public:
	float                                         NewPhase;                                          // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Result;                                            // 0x0004(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(INTERF_Anim_Crate_C_SetPhase) == 0x000004, "Wrong alignment on INTERF_Anim_Crate_C_SetPhase");
static_assert(sizeof(INTERF_Anim_Crate_C_SetPhase) == 0x000008, "Wrong size on INTERF_Anim_Crate_C_SetPhase");
static_assert(offsetof(INTERF_Anim_Crate_C_SetPhase, NewPhase) == 0x000000, "Member 'INTERF_Anim_Crate_C_SetPhase::NewPhase' has a wrong offset!");
static_assert(offsetof(INTERF_Anim_Crate_C_SetPhase, Result) == 0x000004, "Member 'INTERF_Anim_Crate_C_SetPhase::Result' has a wrong offset!");

}

