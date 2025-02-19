#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: INTERF_ANIM_EnergyWeapon

#include "Basic.hpp"


namespace SDK::Params
{

// Function INTERF_ANIM_EnergyWeapon.INTERF_ANIM_EnergyWeapon_C.SetChargeMode
// 0x0008 (0x0008 - 0x0000)
struct INTERF_ANIM_EnergyWeapon_C_SetChargeMode final
{
public:
	int32                                         ModeIndex;                                         // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Result;                                            // 0x0004(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(INTERF_ANIM_EnergyWeapon_C_SetChargeMode) == 0x000004, "Wrong alignment on INTERF_ANIM_EnergyWeapon_C_SetChargeMode");
static_assert(sizeof(INTERF_ANIM_EnergyWeapon_C_SetChargeMode) == 0x000008, "Wrong size on INTERF_ANIM_EnergyWeapon_C_SetChargeMode");
static_assert(offsetof(INTERF_ANIM_EnergyWeapon_C_SetChargeMode, ModeIndex) == 0x000000, "Member 'INTERF_ANIM_EnergyWeapon_C_SetChargeMode::ModeIndex' has a wrong offset!");
static_assert(offsetof(INTERF_ANIM_EnergyWeapon_C_SetChargeMode, Result) == 0x000004, "Member 'INTERF_ANIM_EnergyWeapon_C_SetChargeMode::Result' has a wrong offset!");

// Function INTERF_ANIM_EnergyWeapon.INTERF_ANIM_EnergyWeapon_C.SetChargeValue
// 0x0008 (0x0008 - 0x0000)
struct INTERF_ANIM_EnergyWeapon_C_SetChargeValue final
{
public:
	float                                         NormalisedChargeValue;                             // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Result;                                            // 0x0004(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(INTERF_ANIM_EnergyWeapon_C_SetChargeValue) == 0x000004, "Wrong alignment on INTERF_ANIM_EnergyWeapon_C_SetChargeValue");
static_assert(sizeof(INTERF_ANIM_EnergyWeapon_C_SetChargeValue) == 0x000008, "Wrong size on INTERF_ANIM_EnergyWeapon_C_SetChargeValue");
static_assert(offsetof(INTERF_ANIM_EnergyWeapon_C_SetChargeValue, NormalisedChargeValue) == 0x000000, "Member 'INTERF_ANIM_EnergyWeapon_C_SetChargeValue::NormalisedChargeValue' has a wrong offset!");
static_assert(offsetof(INTERF_ANIM_EnergyWeapon_C_SetChargeValue, Result) == 0x000004, "Member 'INTERF_ANIM_EnergyWeapon_C_SetChargeValue::Result' has a wrong offset!");

// Function INTERF_ANIM_EnergyWeapon.INTERF_ANIM_EnergyWeapon_C.SetTimeSinceFired
// 0x0008 (0x0008 - 0x0000)
struct INTERF_ANIM_EnergyWeapon_C_SetTimeSinceFired final
{
public:
	float                                         TimeSinceFired;                                    // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Result;                                            // 0x0004(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(INTERF_ANIM_EnergyWeapon_C_SetTimeSinceFired) == 0x000004, "Wrong alignment on INTERF_ANIM_EnergyWeapon_C_SetTimeSinceFired");
static_assert(sizeof(INTERF_ANIM_EnergyWeapon_C_SetTimeSinceFired) == 0x000008, "Wrong size on INTERF_ANIM_EnergyWeapon_C_SetTimeSinceFired");
static_assert(offsetof(INTERF_ANIM_EnergyWeapon_C_SetTimeSinceFired, TimeSinceFired) == 0x000000, "Member 'INTERF_ANIM_EnergyWeapon_C_SetTimeSinceFired::TimeSinceFired' has a wrong offset!");
static_assert(offsetof(INTERF_ANIM_EnergyWeapon_C_SetTimeSinceFired, Result) == 0x000004, "Member 'INTERF_ANIM_EnergyWeapon_C_SetTimeSinceFired::Result' has a wrong offset!");

// Function INTERF_ANIM_EnergyWeapon.INTERF_ANIM_EnergyWeapon_C.SetHeatPercentage
// 0x0008 (0x0008 - 0x0000)
struct INTERF_ANIM_EnergyWeapon_C_SetHeatPercentage final
{
public:
	float                                         HeatPercentage;                                    // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Result;                                            // 0x0004(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(INTERF_ANIM_EnergyWeapon_C_SetHeatPercentage) == 0x000004, "Wrong alignment on INTERF_ANIM_EnergyWeapon_C_SetHeatPercentage");
static_assert(sizeof(INTERF_ANIM_EnergyWeapon_C_SetHeatPercentage) == 0x000008, "Wrong size on INTERF_ANIM_EnergyWeapon_C_SetHeatPercentage");
static_assert(offsetof(INTERF_ANIM_EnergyWeapon_C_SetHeatPercentage, HeatPercentage) == 0x000000, "Member 'INTERF_ANIM_EnergyWeapon_C_SetHeatPercentage::HeatPercentage' has a wrong offset!");
static_assert(offsetof(INTERF_ANIM_EnergyWeapon_C_SetHeatPercentage, Result) == 0x000004, "Member 'INTERF_ANIM_EnergyWeapon_C_SetHeatPercentage::Result' has a wrong offset!");

}

