#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: SKILL_Security2Bot_GatlingShoot

#include "Basic.hpp"

#include "CoreUObject_structs.hpp"


namespace SDK::Params
{

// Function SKILL_Security2Bot_GatlingShoot.SKILL_Security2Bot_GatlingShoot_C.CanUseSkill
// 0x0001 (0x0001 - 0x0000)
struct SKILL_Security2Bot_GatlingShoot_C_CanUseSkill final
{
public:
	bool                                          Result;                                            // 0x0000(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(SKILL_Security2Bot_GatlingShoot_C_CanUseSkill) == 0x000001, "Wrong alignment on SKILL_Security2Bot_GatlingShoot_C_CanUseSkill");
static_assert(sizeof(SKILL_Security2Bot_GatlingShoot_C_CanUseSkill) == 0x000001, "Wrong size on SKILL_Security2Bot_GatlingShoot_C_CanUseSkill");
static_assert(offsetof(SKILL_Security2Bot_GatlingShoot_C_CanUseSkill, Result) == 0x000000, "Member 'SKILL_Security2Bot_GatlingShoot_C_CanUseSkill::Result' has a wrong offset!");

// Function SKILL_Security2Bot_GatlingShoot.SKILL_Security2Bot_GatlingShoot_C.SpawnBullet
// 0x0070 (0x0070 - 0x0000)
struct SKILL_Security2Bot_GatlingShoot_C_SpawnBullet final
{
public:
	class FName                                   SocketName;                                        // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                Location;                                          // 0x0008(0x000C)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                Direction;                                         // 0x0014(0x000C)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class ABulletProjectile_Base_C*               Result;                                            // 0x0020(0x0008)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         SequenceLength;                                    // 0x0028(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         ScaledDamage;                                      // 0x002C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class APAWN_Enemy_C*                          CallFunc_GetSkillPawn_SkillPawn;                   // 0x0030(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class APAWN_Security2Bot_C*                   K2Node_DynamicCast_AsPAWN_Security_2Bot;           // 0x0038(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess;                       // 0x0040(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_41[0x7];                                       // 0x0041(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class ABulletProjectile_Base_C*               CallFunc_SpawnBulletWithWeightedRandomDamage_Result; // 0x0048(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UAnimMontage*                           CallFunc_GetMontage_Result;                        // 0x0050(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class APAWN_Enemy_C*                          CallFunc_GetSkillPawn_SkillPawn_1;                 // 0x0058(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_GetScaledEnemyDamage_DamageValue;         // 0x0060(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_Conv_IntToFloat_ReturnValue;              // 0x0064(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_Multiply_FloatFloat_ReturnValue;          // 0x0068(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(SKILL_Security2Bot_GatlingShoot_C_SpawnBullet) == 0x000008, "Wrong alignment on SKILL_Security2Bot_GatlingShoot_C_SpawnBullet");
static_assert(sizeof(SKILL_Security2Bot_GatlingShoot_C_SpawnBullet) == 0x000070, "Wrong size on SKILL_Security2Bot_GatlingShoot_C_SpawnBullet");
static_assert(offsetof(SKILL_Security2Bot_GatlingShoot_C_SpawnBullet, SocketName) == 0x000000, "Member 'SKILL_Security2Bot_GatlingShoot_C_SpawnBullet::SocketName' has a wrong offset!");
static_assert(offsetof(SKILL_Security2Bot_GatlingShoot_C_SpawnBullet, Location) == 0x000008, "Member 'SKILL_Security2Bot_GatlingShoot_C_SpawnBullet::Location' has a wrong offset!");
static_assert(offsetof(SKILL_Security2Bot_GatlingShoot_C_SpawnBullet, Direction) == 0x000014, "Member 'SKILL_Security2Bot_GatlingShoot_C_SpawnBullet::Direction' has a wrong offset!");
static_assert(offsetof(SKILL_Security2Bot_GatlingShoot_C_SpawnBullet, Result) == 0x000020, "Member 'SKILL_Security2Bot_GatlingShoot_C_SpawnBullet::Result' has a wrong offset!");
static_assert(offsetof(SKILL_Security2Bot_GatlingShoot_C_SpawnBullet, SequenceLength) == 0x000028, "Member 'SKILL_Security2Bot_GatlingShoot_C_SpawnBullet::SequenceLength' has a wrong offset!");
static_assert(offsetof(SKILL_Security2Bot_GatlingShoot_C_SpawnBullet, ScaledDamage) == 0x00002C, "Member 'SKILL_Security2Bot_GatlingShoot_C_SpawnBullet::ScaledDamage' has a wrong offset!");
static_assert(offsetof(SKILL_Security2Bot_GatlingShoot_C_SpawnBullet, CallFunc_GetSkillPawn_SkillPawn) == 0x000030, "Member 'SKILL_Security2Bot_GatlingShoot_C_SpawnBullet::CallFunc_GetSkillPawn_SkillPawn' has a wrong offset!");
static_assert(offsetof(SKILL_Security2Bot_GatlingShoot_C_SpawnBullet, K2Node_DynamicCast_AsPAWN_Security_2Bot) == 0x000038, "Member 'SKILL_Security2Bot_GatlingShoot_C_SpawnBullet::K2Node_DynamicCast_AsPAWN_Security_2Bot' has a wrong offset!");
static_assert(offsetof(SKILL_Security2Bot_GatlingShoot_C_SpawnBullet, K2Node_DynamicCast_bSuccess) == 0x000040, "Member 'SKILL_Security2Bot_GatlingShoot_C_SpawnBullet::K2Node_DynamicCast_bSuccess' has a wrong offset!");
static_assert(offsetof(SKILL_Security2Bot_GatlingShoot_C_SpawnBullet, CallFunc_SpawnBulletWithWeightedRandomDamage_Result) == 0x000048, "Member 'SKILL_Security2Bot_GatlingShoot_C_SpawnBullet::CallFunc_SpawnBulletWithWeightedRandomDamage_Result' has a wrong offset!");
static_assert(offsetof(SKILL_Security2Bot_GatlingShoot_C_SpawnBullet, CallFunc_GetMontage_Result) == 0x000050, "Member 'SKILL_Security2Bot_GatlingShoot_C_SpawnBullet::CallFunc_GetMontage_Result' has a wrong offset!");
static_assert(offsetof(SKILL_Security2Bot_GatlingShoot_C_SpawnBullet, CallFunc_GetSkillPawn_SkillPawn_1) == 0x000058, "Member 'SKILL_Security2Bot_GatlingShoot_C_SpawnBullet::CallFunc_GetSkillPawn_SkillPawn_1' has a wrong offset!");
static_assert(offsetof(SKILL_Security2Bot_GatlingShoot_C_SpawnBullet, CallFunc_GetScaledEnemyDamage_DamageValue) == 0x000060, "Member 'SKILL_Security2Bot_GatlingShoot_C_SpawnBullet::CallFunc_GetScaledEnemyDamage_DamageValue' has a wrong offset!");
static_assert(offsetof(SKILL_Security2Bot_GatlingShoot_C_SpawnBullet, CallFunc_Conv_IntToFloat_ReturnValue) == 0x000064, "Member 'SKILL_Security2Bot_GatlingShoot_C_SpawnBullet::CallFunc_Conv_IntToFloat_ReturnValue' has a wrong offset!");
static_assert(offsetof(SKILL_Security2Bot_GatlingShoot_C_SpawnBullet, CallFunc_Multiply_FloatFloat_ReturnValue) == 0x000068, "Member 'SKILL_Security2Bot_GatlingShoot_C_SpawnBullet::CallFunc_Multiply_FloatFloat_ReturnValue' has a wrong offset!");

}

