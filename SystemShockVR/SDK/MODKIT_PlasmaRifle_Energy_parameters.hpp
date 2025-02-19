#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: MODKIT_PlasmaRifle_Energy

#include "Basic.hpp"

#include "STRUCT_WeaponMode_structs.hpp"


namespace SDK::Params
{

// Function MODKIT_PlasmaRifle_Energy.MODKIT_PlasmaRifle_Energy_C.TryApplyWeaponModifications
// 0x0010 (0x0010 - 0x0000)
struct MODKIT_PlasmaRifle_Energy_C_TryApplyWeaponModifications final
{
public:
	class UITEM_WeaponBase_C*                     Weapon;                                            // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          DuringInitialization;                              // 0x0008(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          Result;                                            // 0x0009(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_TryApplyWeaponModifications_Result;       // 0x000A(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(MODKIT_PlasmaRifle_Energy_C_TryApplyWeaponModifications) == 0x000008, "Wrong alignment on MODKIT_PlasmaRifle_Energy_C_TryApplyWeaponModifications");
static_assert(sizeof(MODKIT_PlasmaRifle_Energy_C_TryApplyWeaponModifications) == 0x000010, "Wrong size on MODKIT_PlasmaRifle_Energy_C_TryApplyWeaponModifications");
static_assert(offsetof(MODKIT_PlasmaRifle_Energy_C_TryApplyWeaponModifications, Weapon) == 0x000000, "Member 'MODKIT_PlasmaRifle_Energy_C_TryApplyWeaponModifications::Weapon' has a wrong offset!");
static_assert(offsetof(MODKIT_PlasmaRifle_Energy_C_TryApplyWeaponModifications, DuringInitialization) == 0x000008, "Member 'MODKIT_PlasmaRifle_Energy_C_TryApplyWeaponModifications::DuringInitialization' has a wrong offset!");
static_assert(offsetof(MODKIT_PlasmaRifle_Energy_C_TryApplyWeaponModifications, Result) == 0x000009, "Member 'MODKIT_PlasmaRifle_Energy_C_TryApplyWeaponModifications::Result' has a wrong offset!");
static_assert(offsetof(MODKIT_PlasmaRifle_Energy_C_TryApplyWeaponModifications, CallFunc_TryApplyWeaponModifications_Result) == 0x00000A, "Member 'MODKIT_PlasmaRifle_Energy_C_TryApplyWeaponModifications::CallFunc_TryApplyWeaponModifications_Result' has a wrong offset!");

// Function MODKIT_PlasmaRifle_Energy.MODKIT_PlasmaRifle_Energy_C.GetModifiedWeaponMode
// 0x0308 (0x0308 - 0x0000)
struct MODKIT_PlasmaRifle_Energy_C_GetModifiedWeaponMode final
{
public:
	struct FSTRUCT_WeaponMode                     WeaponMode;                                        // 0x0000(0x0100)(BlueprintVisible, BlueprintReadOnly, Parm, HasGetValueTypeHash)
	struct FSTRUCT_WeaponMode                     ResultMode;                                        // 0x0100(0x0100)(Parm, OutParm, HasGetValueTypeHash)
	float                                         CallFunc_Multiply_IntFloat_ReturnValue;            // 0x0200(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_Round_ReturnValue;                        // 0x0204(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FSTRUCT_WeaponMode                     K2Node_SetFieldsInStruct_StructOut;                // 0x0208(0x0100)(HasGetValueTypeHash)
};
static_assert(alignof(MODKIT_PlasmaRifle_Energy_C_GetModifiedWeaponMode) == 0x000008, "Wrong alignment on MODKIT_PlasmaRifle_Energy_C_GetModifiedWeaponMode");
static_assert(sizeof(MODKIT_PlasmaRifle_Energy_C_GetModifiedWeaponMode) == 0x000308, "Wrong size on MODKIT_PlasmaRifle_Energy_C_GetModifiedWeaponMode");
static_assert(offsetof(MODKIT_PlasmaRifle_Energy_C_GetModifiedWeaponMode, WeaponMode) == 0x000000, "Member 'MODKIT_PlasmaRifle_Energy_C_GetModifiedWeaponMode::WeaponMode' has a wrong offset!");
static_assert(offsetof(MODKIT_PlasmaRifle_Energy_C_GetModifiedWeaponMode, ResultMode) == 0x000100, "Member 'MODKIT_PlasmaRifle_Energy_C_GetModifiedWeaponMode::ResultMode' has a wrong offset!");
static_assert(offsetof(MODKIT_PlasmaRifle_Energy_C_GetModifiedWeaponMode, CallFunc_Multiply_IntFloat_ReturnValue) == 0x000200, "Member 'MODKIT_PlasmaRifle_Energy_C_GetModifiedWeaponMode::CallFunc_Multiply_IntFloat_ReturnValue' has a wrong offset!");
static_assert(offsetof(MODKIT_PlasmaRifle_Energy_C_GetModifiedWeaponMode, CallFunc_Round_ReturnValue) == 0x000204, "Member 'MODKIT_PlasmaRifle_Energy_C_GetModifiedWeaponMode::CallFunc_Round_ReturnValue' has a wrong offset!");
static_assert(offsetof(MODKIT_PlasmaRifle_Energy_C_GetModifiedWeaponMode, K2Node_SetFieldsInStruct_StructOut) == 0x000208, "Member 'MODKIT_PlasmaRifle_Energy_C_GetModifiedWeaponMode::K2Node_SetFieldsInStruct_StructOut' has a wrong offset!");

}

