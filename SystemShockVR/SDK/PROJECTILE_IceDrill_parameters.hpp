#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PROJECTILE_IceDrill

#include "Basic.hpp"

#include "AttributeSystem_structs.hpp"
#include "CoreUObject_structs.hpp"


namespace SDK::Params
{

// Function PROJECTILE_IceDrill.PROJECTILE_IceDrill_C.SetLockOnActor
// 0x0008 (0x0008 - 0x0000)
struct PROJECTILE_IceDrill_C_SetLockOnActor final
{
public:
	class AActor*                                 Actor;                                             // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(PROJECTILE_IceDrill_C_SetLockOnActor) == 0x000008, "Wrong alignment on PROJECTILE_IceDrill_C_SetLockOnActor");
static_assert(sizeof(PROJECTILE_IceDrill_C_SetLockOnActor) == 0x000008, "Wrong size on PROJECTILE_IceDrill_C_SetLockOnActor");
static_assert(offsetof(PROJECTILE_IceDrill_C_SetLockOnActor, Actor) == 0x000000, "Member 'PROJECTILE_IceDrill_C_SetLockOnActor::Actor' has a wrong offset!");

// Function PROJECTILE_IceDrill.PROJECTILE_IceDrill_C.UpdateDrillRotation
// 0x0070 (0x0070 - 0x0000)
struct PROJECTILE_IceDrill_C_UpdateDrillRotation final
{
public:
	float                                         DeltaSeconds;                                      // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                LockOnDirection;                                   // 0x0004(0x000C)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CallFunc_GetActorForwardVector_ReturnValue;        // 0x0010(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FRotator                               CallFunc_Conv_VectorToRotator_ReturnValue;         // 0x001C(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_IsValid_ReturnValue;                      // 0x0028(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_29[0x3];                                       // 0x0029(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         CallFunc_MapRangeClamped_ReturnValue;              // 0x002C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FRotator                               CallFunc_K2_GetActorRotation_ReturnValue;          // 0x0030(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor)
	struct FRotator                               CallFunc_RInterpTo_Constant_ReturnValue;           // 0x003C(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor)
	struct FVector                                CallFunc_K2_GetComponentLocation_ReturnValue;      // 0x0048(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_K2_SetActorRotation_ReturnValue;          // 0x0054(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_55[0x3];                                       // 0x0055(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	struct FVector                                CallFunc_K2_GetActorLocation_ReturnValue;          // 0x0058(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CallFunc_GetDirectionUnitVector_ReturnValue;       // 0x0064(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(PROJECTILE_IceDrill_C_UpdateDrillRotation) == 0x000004, "Wrong alignment on PROJECTILE_IceDrill_C_UpdateDrillRotation");
static_assert(sizeof(PROJECTILE_IceDrill_C_UpdateDrillRotation) == 0x000070, "Wrong size on PROJECTILE_IceDrill_C_UpdateDrillRotation");
static_assert(offsetof(PROJECTILE_IceDrill_C_UpdateDrillRotation, DeltaSeconds) == 0x000000, "Member 'PROJECTILE_IceDrill_C_UpdateDrillRotation::DeltaSeconds' has a wrong offset!");
static_assert(offsetof(PROJECTILE_IceDrill_C_UpdateDrillRotation, LockOnDirection) == 0x000004, "Member 'PROJECTILE_IceDrill_C_UpdateDrillRotation::LockOnDirection' has a wrong offset!");
static_assert(offsetof(PROJECTILE_IceDrill_C_UpdateDrillRotation, CallFunc_GetActorForwardVector_ReturnValue) == 0x000010, "Member 'PROJECTILE_IceDrill_C_UpdateDrillRotation::CallFunc_GetActorForwardVector_ReturnValue' has a wrong offset!");
static_assert(offsetof(PROJECTILE_IceDrill_C_UpdateDrillRotation, CallFunc_Conv_VectorToRotator_ReturnValue) == 0x00001C, "Member 'PROJECTILE_IceDrill_C_UpdateDrillRotation::CallFunc_Conv_VectorToRotator_ReturnValue' has a wrong offset!");
static_assert(offsetof(PROJECTILE_IceDrill_C_UpdateDrillRotation, CallFunc_IsValid_ReturnValue) == 0x000028, "Member 'PROJECTILE_IceDrill_C_UpdateDrillRotation::CallFunc_IsValid_ReturnValue' has a wrong offset!");
static_assert(offsetof(PROJECTILE_IceDrill_C_UpdateDrillRotation, CallFunc_MapRangeClamped_ReturnValue) == 0x00002C, "Member 'PROJECTILE_IceDrill_C_UpdateDrillRotation::CallFunc_MapRangeClamped_ReturnValue' has a wrong offset!");
static_assert(offsetof(PROJECTILE_IceDrill_C_UpdateDrillRotation, CallFunc_K2_GetActorRotation_ReturnValue) == 0x000030, "Member 'PROJECTILE_IceDrill_C_UpdateDrillRotation::CallFunc_K2_GetActorRotation_ReturnValue' has a wrong offset!");
static_assert(offsetof(PROJECTILE_IceDrill_C_UpdateDrillRotation, CallFunc_RInterpTo_Constant_ReturnValue) == 0x00003C, "Member 'PROJECTILE_IceDrill_C_UpdateDrillRotation::CallFunc_RInterpTo_Constant_ReturnValue' has a wrong offset!");
static_assert(offsetof(PROJECTILE_IceDrill_C_UpdateDrillRotation, CallFunc_K2_GetComponentLocation_ReturnValue) == 0x000048, "Member 'PROJECTILE_IceDrill_C_UpdateDrillRotation::CallFunc_K2_GetComponentLocation_ReturnValue' has a wrong offset!");
static_assert(offsetof(PROJECTILE_IceDrill_C_UpdateDrillRotation, CallFunc_K2_SetActorRotation_ReturnValue) == 0x000054, "Member 'PROJECTILE_IceDrill_C_UpdateDrillRotation::CallFunc_K2_SetActorRotation_ReturnValue' has a wrong offset!");
static_assert(offsetof(PROJECTILE_IceDrill_C_UpdateDrillRotation, CallFunc_K2_GetActorLocation_ReturnValue) == 0x000058, "Member 'PROJECTILE_IceDrill_C_UpdateDrillRotation::CallFunc_K2_GetActorLocation_ReturnValue' has a wrong offset!");
static_assert(offsetof(PROJECTILE_IceDrill_C_UpdateDrillRotation, CallFunc_GetDirectionUnitVector_ReturnValue) == 0x000064, "Member 'PROJECTILE_IceDrill_C_UpdateDrillRotation::CallFunc_GetDirectionUnitVector_ReturnValue' has a wrong offset!");

// Function PROJECTILE_IceDrill.PROJECTILE_IceDrill_C.IncrementalPositionUpdate
// 0x0008 (0x0008 - 0x0000)
struct PROJECTILE_IceDrill_C_IncrementalPositionUpdate final
{
public:
	float                                         DeltaTime;                                         // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Result;                                            // 0x0004(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_IncrementalPositionUpdate_Result;         // 0x0005(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(PROJECTILE_IceDrill_C_IncrementalPositionUpdate) == 0x000004, "Wrong alignment on PROJECTILE_IceDrill_C_IncrementalPositionUpdate");
static_assert(sizeof(PROJECTILE_IceDrill_C_IncrementalPositionUpdate) == 0x000008, "Wrong size on PROJECTILE_IceDrill_C_IncrementalPositionUpdate");
static_assert(offsetof(PROJECTILE_IceDrill_C_IncrementalPositionUpdate, DeltaTime) == 0x000000, "Member 'PROJECTILE_IceDrill_C_IncrementalPositionUpdate::DeltaTime' has a wrong offset!");
static_assert(offsetof(PROJECTILE_IceDrill_C_IncrementalPositionUpdate, Result) == 0x000004, "Member 'PROJECTILE_IceDrill_C_IncrementalPositionUpdate::Result' has a wrong offset!");
static_assert(offsetof(PROJECTILE_IceDrill_C_IncrementalPositionUpdate, CallFunc_IncrementalPositionUpdate_Result) == 0x000005, "Member 'PROJECTILE_IceDrill_C_IncrementalPositionUpdate::CallFunc_IncrementalPositionUpdate_Result' has a wrong offset!");

// Function PROJECTILE_IceDrill.PROJECTILE_IceDrill_C.ApplyDamageMod
// 0x0088 (0x0088 - 0x0000)
struct PROJECTILE_IceDrill_C_ApplyDamageMod final
{
public:
	class UAttribManagerComponent*                AttribManager;                                     // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UOBJ_ImpactData_C*                      ImpactData;                                        // 0x0008(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         FrameHitDeltaTime;                                 // 0x0010(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_14[0x4];                                       // 0x0014(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	struct FAttribDamageInstance                  DamageInstance;                                    // 0x0018(0x0028)(Parm, OutParm)
	class UAttribMod*                             DamageMod;                                         // 0x0040(0x0008)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FAttribDamageInstance                  CallFunc_ApplyDamageMod_DamageInstance;            // 0x0048(0x0028)()
	class UAttribMod*                             CallFunc_ApplyDamageMod_DamageMod;                 // 0x0070(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UAttribInstance*                        CallFunc_GetOrCreateAttribInstance_ReturnValue;    // 0x0078(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_ExpireModsMatchingCategory_ReturnValue;   // 0x0080(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(PROJECTILE_IceDrill_C_ApplyDamageMod) == 0x000008, "Wrong alignment on PROJECTILE_IceDrill_C_ApplyDamageMod");
static_assert(sizeof(PROJECTILE_IceDrill_C_ApplyDamageMod) == 0x000088, "Wrong size on PROJECTILE_IceDrill_C_ApplyDamageMod");
static_assert(offsetof(PROJECTILE_IceDrill_C_ApplyDamageMod, AttribManager) == 0x000000, "Member 'PROJECTILE_IceDrill_C_ApplyDamageMod::AttribManager' has a wrong offset!");
static_assert(offsetof(PROJECTILE_IceDrill_C_ApplyDamageMod, ImpactData) == 0x000008, "Member 'PROJECTILE_IceDrill_C_ApplyDamageMod::ImpactData' has a wrong offset!");
static_assert(offsetof(PROJECTILE_IceDrill_C_ApplyDamageMod, FrameHitDeltaTime) == 0x000010, "Member 'PROJECTILE_IceDrill_C_ApplyDamageMod::FrameHitDeltaTime' has a wrong offset!");
static_assert(offsetof(PROJECTILE_IceDrill_C_ApplyDamageMod, DamageInstance) == 0x000018, "Member 'PROJECTILE_IceDrill_C_ApplyDamageMod::DamageInstance' has a wrong offset!");
static_assert(offsetof(PROJECTILE_IceDrill_C_ApplyDamageMod, DamageMod) == 0x000040, "Member 'PROJECTILE_IceDrill_C_ApplyDamageMod::DamageMod' has a wrong offset!");
static_assert(offsetof(PROJECTILE_IceDrill_C_ApplyDamageMod, CallFunc_ApplyDamageMod_DamageInstance) == 0x000048, "Member 'PROJECTILE_IceDrill_C_ApplyDamageMod::CallFunc_ApplyDamageMod_DamageInstance' has a wrong offset!");
static_assert(offsetof(PROJECTILE_IceDrill_C_ApplyDamageMod, CallFunc_ApplyDamageMod_DamageMod) == 0x000070, "Member 'PROJECTILE_IceDrill_C_ApplyDamageMod::CallFunc_ApplyDamageMod_DamageMod' has a wrong offset!");
static_assert(offsetof(PROJECTILE_IceDrill_C_ApplyDamageMod, CallFunc_GetOrCreateAttribInstance_ReturnValue) == 0x000078, "Member 'PROJECTILE_IceDrill_C_ApplyDamageMod::CallFunc_GetOrCreateAttribInstance_ReturnValue' has a wrong offset!");
static_assert(offsetof(PROJECTILE_IceDrill_C_ApplyDamageMod, CallFunc_ExpireModsMatchingCategory_ReturnValue) == 0x000080, "Member 'PROJECTILE_IceDrill_C_ApplyDamageMod::CallFunc_ExpireModsMatchingCategory_ReturnValue' has a wrong offset!");

// Function PROJECTILE_IceDrill.PROJECTILE_IceDrill_C.DestroyProjectile
// 0x0080 (0x0080 - 0x0000)
struct PROJECTILE_IceDrill_C_DestroyProjectile final
{
public:
	struct FVector                                ImpactNormal;                                      // 0x0000(0x000C)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_C[0x4];                                        // 0x000C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	struct FTransform                             CallFunc_GetTransform_ReturnValue;                 // 0x0010(0x0030)(ConstParm, IsPlainOldData, NoDestructor)
	struct FRotator                               CallFunc_Conv_VectorToRotator_ReturnValue;         // 0x0040(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor)
	struct FVector                                CallFunc_BreakTransform_Location;                  // 0x004C(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FRotator                               CallFunc_BreakTransform_Rotation;                  // 0x0058(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor)
	struct FVector                                CallFunc_BreakTransform_Scale;                     // 0x0064(0x000C)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UNiagaraComponent*                      CallFunc_SpawnSystemAtLocation_ReturnValue;        // 0x0070(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(PROJECTILE_IceDrill_C_DestroyProjectile) == 0x000010, "Wrong alignment on PROJECTILE_IceDrill_C_DestroyProjectile");
static_assert(sizeof(PROJECTILE_IceDrill_C_DestroyProjectile) == 0x000080, "Wrong size on PROJECTILE_IceDrill_C_DestroyProjectile");
static_assert(offsetof(PROJECTILE_IceDrill_C_DestroyProjectile, ImpactNormal) == 0x000000, "Member 'PROJECTILE_IceDrill_C_DestroyProjectile::ImpactNormal' has a wrong offset!");
static_assert(offsetof(PROJECTILE_IceDrill_C_DestroyProjectile, CallFunc_GetTransform_ReturnValue) == 0x000010, "Member 'PROJECTILE_IceDrill_C_DestroyProjectile::CallFunc_GetTransform_ReturnValue' has a wrong offset!");
static_assert(offsetof(PROJECTILE_IceDrill_C_DestroyProjectile, CallFunc_Conv_VectorToRotator_ReturnValue) == 0x000040, "Member 'PROJECTILE_IceDrill_C_DestroyProjectile::CallFunc_Conv_VectorToRotator_ReturnValue' has a wrong offset!");
static_assert(offsetof(PROJECTILE_IceDrill_C_DestroyProjectile, CallFunc_BreakTransform_Location) == 0x00004C, "Member 'PROJECTILE_IceDrill_C_DestroyProjectile::CallFunc_BreakTransform_Location' has a wrong offset!");
static_assert(offsetof(PROJECTILE_IceDrill_C_DestroyProjectile, CallFunc_BreakTransform_Rotation) == 0x000058, "Member 'PROJECTILE_IceDrill_C_DestroyProjectile::CallFunc_BreakTransform_Rotation' has a wrong offset!");
static_assert(offsetof(PROJECTILE_IceDrill_C_DestroyProjectile, CallFunc_BreakTransform_Scale) == 0x000064, "Member 'PROJECTILE_IceDrill_C_DestroyProjectile::CallFunc_BreakTransform_Scale' has a wrong offset!");
static_assert(offsetof(PROJECTILE_IceDrill_C_DestroyProjectile, CallFunc_SpawnSystemAtLocation_ReturnValue) == 0x000070, "Member 'PROJECTILE_IceDrill_C_DestroyProjectile::CallFunc_SpawnSystemAtLocation_ReturnValue' has a wrong offset!");

}

