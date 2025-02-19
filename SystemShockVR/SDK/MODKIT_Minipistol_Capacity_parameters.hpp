#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: MODKIT_Minipistol_Capacity

#include "Basic.hpp"

#include "STRUCT_WeaponMode_structs.hpp"
#include "STRUCT_WeaponPropertyValue_structs.hpp"


namespace SDK::Params
{

// Function MODKIT_Minipistol_Capacity.MODKIT_Minipistol_Capacity_C.TryApplyWeaponModifications
// 0x0010 (0x0010 - 0x0000)
struct MODKIT_Minipistol_Capacity_C_TryApplyWeaponModifications final
{
public:
	class UITEM_WeaponBase_C*                     Weapon;                                            // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          DuringInitialization;                              // 0x0008(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          Result;                                            // 0x0009(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_TryApplyWeaponModifications_Result;       // 0x000A(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(MODKIT_Minipistol_Capacity_C_TryApplyWeaponModifications) == 0x000008, "Wrong alignment on MODKIT_Minipistol_Capacity_C_TryApplyWeaponModifications");
static_assert(sizeof(MODKIT_Minipistol_Capacity_C_TryApplyWeaponModifications) == 0x000010, "Wrong size on MODKIT_Minipistol_Capacity_C_TryApplyWeaponModifications");
static_assert(offsetof(MODKIT_Minipistol_Capacity_C_TryApplyWeaponModifications, Weapon) == 0x000000, "Member 'MODKIT_Minipistol_Capacity_C_TryApplyWeaponModifications::Weapon' has a wrong offset!");
static_assert(offsetof(MODKIT_Minipistol_Capacity_C_TryApplyWeaponModifications, DuringInitialization) == 0x000008, "Member 'MODKIT_Minipistol_Capacity_C_TryApplyWeaponModifications::DuringInitialization' has a wrong offset!");
static_assert(offsetof(MODKIT_Minipistol_Capacity_C_TryApplyWeaponModifications, Result) == 0x000009, "Member 'MODKIT_Minipistol_Capacity_C_TryApplyWeaponModifications::Result' has a wrong offset!");
static_assert(offsetof(MODKIT_Minipistol_Capacity_C_TryApplyWeaponModifications, CallFunc_TryApplyWeaponModifications_Result) == 0x00000A, "Member 'MODKIT_Minipistol_Capacity_C_TryApplyWeaponModifications::CallFunc_TryApplyWeaponModifications_Result' has a wrong offset!");

// Function MODKIT_Minipistol_Capacity.MODKIT_Minipistol_Capacity_C.GetModifiedWeaponMode
// 0x0320 (0x0320 - 0x0000)
struct MODKIT_Minipistol_Capacity_C_GetModifiedWeaponMode final
{
public:
	struct FSTRUCT_WeaponMode                     WeaponMode;                                        // 0x0000(0x0100)(BlueprintVisible, BlueprintReadOnly, Parm, HasGetValueTypeHash)
	struct FSTRUCT_WeaponMode                     ResultMode;                                        // 0x0100(0x0100)(Parm, OutParm, HasGetValueTypeHash)
	TArray<struct FSTRUCT_WeaponPropertyValue>    WeaponProperties;                                  // 0x0200(0x0010)(Edit, BlueprintVisible)
	int32                                         CallFunc_GetWeaponPropertyIndexByType_ArrayIndex;  // 0x0210(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_214[0x4];                                      // 0x0214(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	struct FSTRUCT_WeaponMode                     K2Node_SetFieldsInStruct_StructOut;                // 0x0218(0x0100)(HasGetValueTypeHash)
	struct FSTRUCT_WeaponPropertyValue            K2Node_MakeStruct_STRUCT_WeaponPropertyValue;      // 0x0318(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(MODKIT_Minipistol_Capacity_C_GetModifiedWeaponMode) == 0x000008, "Wrong alignment on MODKIT_Minipistol_Capacity_C_GetModifiedWeaponMode");
static_assert(sizeof(MODKIT_Minipistol_Capacity_C_GetModifiedWeaponMode) == 0x000320, "Wrong size on MODKIT_Minipistol_Capacity_C_GetModifiedWeaponMode");
static_assert(offsetof(MODKIT_Minipistol_Capacity_C_GetModifiedWeaponMode, WeaponMode) == 0x000000, "Member 'MODKIT_Minipistol_Capacity_C_GetModifiedWeaponMode::WeaponMode' has a wrong offset!");
static_assert(offsetof(MODKIT_Minipistol_Capacity_C_GetModifiedWeaponMode, ResultMode) == 0x000100, "Member 'MODKIT_Minipistol_Capacity_C_GetModifiedWeaponMode::ResultMode' has a wrong offset!");
static_assert(offsetof(MODKIT_Minipistol_Capacity_C_GetModifiedWeaponMode, WeaponProperties) == 0x000200, "Member 'MODKIT_Minipistol_Capacity_C_GetModifiedWeaponMode::WeaponProperties' has a wrong offset!");
static_assert(offsetof(MODKIT_Minipistol_Capacity_C_GetModifiedWeaponMode, CallFunc_GetWeaponPropertyIndexByType_ArrayIndex) == 0x000210, "Member 'MODKIT_Minipistol_Capacity_C_GetModifiedWeaponMode::CallFunc_GetWeaponPropertyIndexByType_ArrayIndex' has a wrong offset!");
static_assert(offsetof(MODKIT_Minipistol_Capacity_C_GetModifiedWeaponMode, K2Node_SetFieldsInStruct_StructOut) == 0x000218, "Member 'MODKIT_Minipistol_Capacity_C_GetModifiedWeaponMode::K2Node_SetFieldsInStruct_StructOut' has a wrong offset!");
static_assert(offsetof(MODKIT_Minipistol_Capacity_C_GetModifiedWeaponMode, K2Node_MakeStruct_STRUCT_WeaponPropertyValue) == 0x000318, "Member 'MODKIT_Minipistol_Capacity_C_GetModifiedWeaponMode::K2Node_MakeStruct_STRUCT_WeaponPropertyValue' has a wrong offset!");

}

