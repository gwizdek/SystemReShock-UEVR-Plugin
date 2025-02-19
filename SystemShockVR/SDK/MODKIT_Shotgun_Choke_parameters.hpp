#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: MODKIT_Shotgun_Choke

#include "Basic.hpp"

#include "CoreUObject_structs.hpp"
#include "STRUCT_WeaponMode_structs.hpp"
#include "STRUCT_WeaponPropertyValue_structs.hpp"


namespace SDK::Params
{

// Function MODKIT_Shotgun_Choke.MODKIT_Shotgun_Choke_C.TryApplyWeaponModifications
// 0x0020 (0x0020 - 0x0000)
struct MODKIT_Shotgun_Choke_C_TryApplyWeaponModifications final
{
public:
	class UITEM_WeaponBase_C*                     Weapon;                                            // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          DuringInitialization;                              // 0x0008(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          Result;                                            // 0x0009(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_TryApplyWeaponModifications_Result;       // 0x000A(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_B[0x5];                                        // 0x000B(0x0005)(Fixing Size After Last Property [ Dumper-7 ])
	class UWEAPON_Shotgun_C*                      K2Node_DynamicCast_AsWEAPON_Shotgun;               // 0x0010(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess;                       // 0x0018(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(MODKIT_Shotgun_Choke_C_TryApplyWeaponModifications) == 0x000008, "Wrong alignment on MODKIT_Shotgun_Choke_C_TryApplyWeaponModifications");
static_assert(sizeof(MODKIT_Shotgun_Choke_C_TryApplyWeaponModifications) == 0x000020, "Wrong size on MODKIT_Shotgun_Choke_C_TryApplyWeaponModifications");
static_assert(offsetof(MODKIT_Shotgun_Choke_C_TryApplyWeaponModifications, Weapon) == 0x000000, "Member 'MODKIT_Shotgun_Choke_C_TryApplyWeaponModifications::Weapon' has a wrong offset!");
static_assert(offsetof(MODKIT_Shotgun_Choke_C_TryApplyWeaponModifications, DuringInitialization) == 0x000008, "Member 'MODKIT_Shotgun_Choke_C_TryApplyWeaponModifications::DuringInitialization' has a wrong offset!");
static_assert(offsetof(MODKIT_Shotgun_Choke_C_TryApplyWeaponModifications, Result) == 0x000009, "Member 'MODKIT_Shotgun_Choke_C_TryApplyWeaponModifications::Result' has a wrong offset!");
static_assert(offsetof(MODKIT_Shotgun_Choke_C_TryApplyWeaponModifications, CallFunc_TryApplyWeaponModifications_Result) == 0x00000A, "Member 'MODKIT_Shotgun_Choke_C_TryApplyWeaponModifications::CallFunc_TryApplyWeaponModifications_Result' has a wrong offset!");
static_assert(offsetof(MODKIT_Shotgun_Choke_C_TryApplyWeaponModifications, K2Node_DynamicCast_AsWEAPON_Shotgun) == 0x000010, "Member 'MODKIT_Shotgun_Choke_C_TryApplyWeaponModifications::K2Node_DynamicCast_AsWEAPON_Shotgun' has a wrong offset!");
static_assert(offsetof(MODKIT_Shotgun_Choke_C_TryApplyWeaponModifications, K2Node_DynamicCast_bSuccess) == 0x000018, "Member 'MODKIT_Shotgun_Choke_C_TryApplyWeaponModifications::K2Node_DynamicCast_bSuccess' has a wrong offset!");

// Function MODKIT_Shotgun_Choke.MODKIT_Shotgun_Choke_C.GetModifiedWeaponMode
// 0x0320 (0x0320 - 0x0000)
struct MODKIT_Shotgun_Choke_C_GetModifiedWeaponMode final
{
public:
	struct FSTRUCT_WeaponMode                     WeaponMode;                                        // 0x0000(0x0100)(BlueprintVisible, BlueprintReadOnly, Parm, HasGetValueTypeHash)
	struct FSTRUCT_WeaponMode                     ResultMode;                                        // 0x0100(0x0100)(Parm, OutParm, HasGetValueTypeHash)
	TArray<struct FSTRUCT_WeaponPropertyValue>    WeaponProperties;                                  // 0x0200(0x0010)(Edit, BlueprintVisible)
	int32                                         CallFunc_GetWeaponPropertyIndexByType_ArrayIndex;  // 0x0210(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_Add_IntInt_ReturnValue;                   // 0x0214(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FSTRUCT_WeaponMode                     K2Node_SetFieldsInStruct_StructOut;                // 0x0218(0x0100)(HasGetValueTypeHash)
	struct FSTRUCT_WeaponPropertyValue            K2Node_MakeStruct_STRUCT_WeaponPropertyValue;      // 0x0318(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(MODKIT_Shotgun_Choke_C_GetModifiedWeaponMode) == 0x000008, "Wrong alignment on MODKIT_Shotgun_Choke_C_GetModifiedWeaponMode");
static_assert(sizeof(MODKIT_Shotgun_Choke_C_GetModifiedWeaponMode) == 0x000320, "Wrong size on MODKIT_Shotgun_Choke_C_GetModifiedWeaponMode");
static_assert(offsetof(MODKIT_Shotgun_Choke_C_GetModifiedWeaponMode, WeaponMode) == 0x000000, "Member 'MODKIT_Shotgun_Choke_C_GetModifiedWeaponMode::WeaponMode' has a wrong offset!");
static_assert(offsetof(MODKIT_Shotgun_Choke_C_GetModifiedWeaponMode, ResultMode) == 0x000100, "Member 'MODKIT_Shotgun_Choke_C_GetModifiedWeaponMode::ResultMode' has a wrong offset!");
static_assert(offsetof(MODKIT_Shotgun_Choke_C_GetModifiedWeaponMode, WeaponProperties) == 0x000200, "Member 'MODKIT_Shotgun_Choke_C_GetModifiedWeaponMode::WeaponProperties' has a wrong offset!");
static_assert(offsetof(MODKIT_Shotgun_Choke_C_GetModifiedWeaponMode, CallFunc_GetWeaponPropertyIndexByType_ArrayIndex) == 0x000210, "Member 'MODKIT_Shotgun_Choke_C_GetModifiedWeaponMode::CallFunc_GetWeaponPropertyIndexByType_ArrayIndex' has a wrong offset!");
static_assert(offsetof(MODKIT_Shotgun_Choke_C_GetModifiedWeaponMode, CallFunc_Add_IntInt_ReturnValue) == 0x000214, "Member 'MODKIT_Shotgun_Choke_C_GetModifiedWeaponMode::CallFunc_Add_IntInt_ReturnValue' has a wrong offset!");
static_assert(offsetof(MODKIT_Shotgun_Choke_C_GetModifiedWeaponMode, K2Node_SetFieldsInStruct_StructOut) == 0x000218, "Member 'MODKIT_Shotgun_Choke_C_GetModifiedWeaponMode::K2Node_SetFieldsInStruct_StructOut' has a wrong offset!");
static_assert(offsetof(MODKIT_Shotgun_Choke_C_GetModifiedWeaponMode, K2Node_MakeStruct_STRUCT_WeaponPropertyValue) == 0x000318, "Member 'MODKIT_Shotgun_Choke_C_GetModifiedWeaponMode::K2Node_MakeStruct_STRUCT_WeaponPropertyValue' has a wrong offset!");

// Function MODKIT_Shotgun_Choke.MODKIT_Shotgun_Choke_C.HasAppearanceChange
// 0x0001 (0x0001 - 0x0000)
struct MODKIT_Shotgun_Choke_C_HasAppearanceChange final
{
public:
	bool                                          Result;                                            // 0x0000(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(MODKIT_Shotgun_Choke_C_HasAppearanceChange) == 0x000001, "Wrong alignment on MODKIT_Shotgun_Choke_C_HasAppearanceChange");
static_assert(sizeof(MODKIT_Shotgun_Choke_C_HasAppearanceChange) == 0x000001, "Wrong size on MODKIT_Shotgun_Choke_C_HasAppearanceChange");
static_assert(offsetof(MODKIT_Shotgun_Choke_C_HasAppearanceChange, Result) == 0x000000, "Member 'MODKIT_Shotgun_Choke_C_HasAppearanceChange::Result' has a wrong offset!");

// Function MODKIT_Shotgun_Choke.MODKIT_Shotgun_Choke_C.GetFirstPersonAttachment
// 0x0080 (0x0080 - 0x0000)
struct MODKIT_Shotgun_Choke_C_GetFirstPersonAttachment final
{
public:
	class UStaticMesh*                            Mesh;                                              // 0x0000(0x0008)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_8[0x8];                                        // 0x0008(0x0008)(Fixing Size After Last Property [ Dumper-7 ])
	struct FTransform                             Transform;                                         // 0x0010(0x0030)(Parm, OutParm, IsPlainOldData, NoDestructor)
	class FName                                   SocketName;                                        // 0x0040(0x0008)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_48[0x8];                                       // 0x0048(0x0008)(Fixing Size After Last Property [ Dumper-7 ])
	struct FTransform                             CallFunc_MakeTransform_ReturnValue;                // 0x0050(0x0030)(IsPlainOldData, NoDestructor)
};
static_assert(alignof(MODKIT_Shotgun_Choke_C_GetFirstPersonAttachment) == 0x000010, "Wrong alignment on MODKIT_Shotgun_Choke_C_GetFirstPersonAttachment");
static_assert(sizeof(MODKIT_Shotgun_Choke_C_GetFirstPersonAttachment) == 0x000080, "Wrong size on MODKIT_Shotgun_Choke_C_GetFirstPersonAttachment");
static_assert(offsetof(MODKIT_Shotgun_Choke_C_GetFirstPersonAttachment, Mesh) == 0x000000, "Member 'MODKIT_Shotgun_Choke_C_GetFirstPersonAttachment::Mesh' has a wrong offset!");
static_assert(offsetof(MODKIT_Shotgun_Choke_C_GetFirstPersonAttachment, Transform) == 0x000010, "Member 'MODKIT_Shotgun_Choke_C_GetFirstPersonAttachment::Transform' has a wrong offset!");
static_assert(offsetof(MODKIT_Shotgun_Choke_C_GetFirstPersonAttachment, SocketName) == 0x000040, "Member 'MODKIT_Shotgun_Choke_C_GetFirstPersonAttachment::SocketName' has a wrong offset!");
static_assert(offsetof(MODKIT_Shotgun_Choke_C_GetFirstPersonAttachment, CallFunc_MakeTransform_ReturnValue) == 0x000050, "Member 'MODKIT_Shotgun_Choke_C_GetFirstPersonAttachment::CallFunc_MakeTransform_ReturnValue' has a wrong offset!");

// Function MODKIT_Shotgun_Choke.MODKIT_Shotgun_Choke_C.TryModifyPickupAppearance
// 0x0050 (0x0050 - 0x0000)
struct MODKIT_Shotgun_Choke_C_TryModifyPickupAppearance final
{
public:
	class APICKUP_Weapon_Base_C*                  WeaponPickup;                                      // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Result;                                            // 0x0008(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_9[0x7];                                        // 0x0009(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	struct FTransform                             CallFunc_MakeTransform_ReturnValue;                // 0x0010(0x0030)(IsPlainOldData, NoDestructor)
	class APICKUP_Shotgun_C*                      K2Node_DynamicCast_AsPICKUP_Shotgun;               // 0x0040(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess;                       // 0x0048(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(MODKIT_Shotgun_Choke_C_TryModifyPickupAppearance) == 0x000010, "Wrong alignment on MODKIT_Shotgun_Choke_C_TryModifyPickupAppearance");
static_assert(sizeof(MODKIT_Shotgun_Choke_C_TryModifyPickupAppearance) == 0x000050, "Wrong size on MODKIT_Shotgun_Choke_C_TryModifyPickupAppearance");
static_assert(offsetof(MODKIT_Shotgun_Choke_C_TryModifyPickupAppearance, WeaponPickup) == 0x000000, "Member 'MODKIT_Shotgun_Choke_C_TryModifyPickupAppearance::WeaponPickup' has a wrong offset!");
static_assert(offsetof(MODKIT_Shotgun_Choke_C_TryModifyPickupAppearance, Result) == 0x000008, "Member 'MODKIT_Shotgun_Choke_C_TryModifyPickupAppearance::Result' has a wrong offset!");
static_assert(offsetof(MODKIT_Shotgun_Choke_C_TryModifyPickupAppearance, CallFunc_MakeTransform_ReturnValue) == 0x000010, "Member 'MODKIT_Shotgun_Choke_C_TryModifyPickupAppearance::CallFunc_MakeTransform_ReturnValue' has a wrong offset!");
static_assert(offsetof(MODKIT_Shotgun_Choke_C_TryModifyPickupAppearance, K2Node_DynamicCast_AsPICKUP_Shotgun) == 0x000040, "Member 'MODKIT_Shotgun_Choke_C_TryModifyPickupAppearance::K2Node_DynamicCast_AsPICKUP_Shotgun' has a wrong offset!");
static_assert(offsetof(MODKIT_Shotgun_Choke_C_TryModifyPickupAppearance, K2Node_DynamicCast_bSuccess) == 0x000048, "Member 'MODKIT_Shotgun_Choke_C_TryModifyPickupAppearance::K2Node_DynamicCast_bSuccess' has a wrong offset!");

}

