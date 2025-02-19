#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: CH_Protoborg_AnimBP

#include "Basic.hpp"

#include "CoreUObject_structs.hpp"
#include "ENUM_Emotions_structs.hpp"
#include "ENUM_DeathBlowType_structs.hpp"
#include "Engine_structs.hpp"


namespace SDK::Params
{

// Function CH_Protoborg_AnimBP.CH_Protoborg_AnimBP_C.ExecuteUbergraph_CH_Protoborg_AnimBP
// 0x0030 (0x0030 - 0x0000)
struct CH_Protoborg_AnimBP_C_ExecuteUbergraph_CH_Protoborg_AnimBP final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_RandomFloatInRange_ReturnValue;           // 0x0004(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TDelegate<void()>                             K2Node_CreateDelegate_OutputDelegate;              // 0x0008(0x0010)(ZeroConstructor, NoDestructor)
	float                                         CallFunc_GetInstanceAssetPlayerTimeFraction_ReturnValue; // 0x0018(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_Greater_FloatFloat_ReturnValue;           // 0x001C(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_1D[0x3];                                       // 0x001D(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         CallFunc_PlaySlotAnimation_ReturnValue;            // 0x0020(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_RandomFloatInRange_ReturnValue_1;         // 0x0024(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FTimerHandle                           CallFunc_K2_SetTimerDelegate_ReturnValue;          // 0x0028(0x0008)(NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(CH_Protoborg_AnimBP_C_ExecuteUbergraph_CH_Protoborg_AnimBP) == 0x000008, "Wrong alignment on CH_Protoborg_AnimBP_C_ExecuteUbergraph_CH_Protoborg_AnimBP");
static_assert(sizeof(CH_Protoborg_AnimBP_C_ExecuteUbergraph_CH_Protoborg_AnimBP) == 0x000030, "Wrong size on CH_Protoborg_AnimBP_C_ExecuteUbergraph_CH_Protoborg_AnimBP");
static_assert(offsetof(CH_Protoborg_AnimBP_C_ExecuteUbergraph_CH_Protoborg_AnimBP, EntryPoint) == 0x000000, "Member 'CH_Protoborg_AnimBP_C_ExecuteUbergraph_CH_Protoborg_AnimBP::EntryPoint' has a wrong offset!");
static_assert(offsetof(CH_Protoborg_AnimBP_C_ExecuteUbergraph_CH_Protoborg_AnimBP, CallFunc_RandomFloatInRange_ReturnValue) == 0x000004, "Member 'CH_Protoborg_AnimBP_C_ExecuteUbergraph_CH_Protoborg_AnimBP::CallFunc_RandomFloatInRange_ReturnValue' has a wrong offset!");
static_assert(offsetof(CH_Protoborg_AnimBP_C_ExecuteUbergraph_CH_Protoborg_AnimBP, K2Node_CreateDelegate_OutputDelegate) == 0x000008, "Member 'CH_Protoborg_AnimBP_C_ExecuteUbergraph_CH_Protoborg_AnimBP::K2Node_CreateDelegate_OutputDelegate' has a wrong offset!");
static_assert(offsetof(CH_Protoborg_AnimBP_C_ExecuteUbergraph_CH_Protoborg_AnimBP, CallFunc_GetInstanceAssetPlayerTimeFraction_ReturnValue) == 0x000018, "Member 'CH_Protoborg_AnimBP_C_ExecuteUbergraph_CH_Protoborg_AnimBP::CallFunc_GetInstanceAssetPlayerTimeFraction_ReturnValue' has a wrong offset!");
static_assert(offsetof(CH_Protoborg_AnimBP_C_ExecuteUbergraph_CH_Protoborg_AnimBP, CallFunc_Greater_FloatFloat_ReturnValue) == 0x00001C, "Member 'CH_Protoborg_AnimBP_C_ExecuteUbergraph_CH_Protoborg_AnimBP::CallFunc_Greater_FloatFloat_ReturnValue' has a wrong offset!");
static_assert(offsetof(CH_Protoborg_AnimBP_C_ExecuteUbergraph_CH_Protoborg_AnimBP, CallFunc_PlaySlotAnimation_ReturnValue) == 0x000020, "Member 'CH_Protoborg_AnimBP_C_ExecuteUbergraph_CH_Protoborg_AnimBP::CallFunc_PlaySlotAnimation_ReturnValue' has a wrong offset!");
static_assert(offsetof(CH_Protoborg_AnimBP_C_ExecuteUbergraph_CH_Protoborg_AnimBP, CallFunc_RandomFloatInRange_ReturnValue_1) == 0x000024, "Member 'CH_Protoborg_AnimBP_C_ExecuteUbergraph_CH_Protoborg_AnimBP::CallFunc_RandomFloatInRange_ReturnValue_1' has a wrong offset!");
static_assert(offsetof(CH_Protoborg_AnimBP_C_ExecuteUbergraph_CH_Protoborg_AnimBP, CallFunc_K2_SetTimerDelegate_ReturnValue) == 0x000028, "Member 'CH_Protoborg_AnimBP_C_ExecuteUbergraph_CH_Protoborg_AnimBP::CallFunc_K2_SetTimerDelegate_ReturnValue' has a wrong offset!");

// Function CH_Protoborg_AnimBP.CH_Protoborg_AnimBP_C.AnimGraph
// 0x0010 (0x0010 - 0x0000)
struct CH_Protoborg_AnimBP_C_AnimGraph final
{
public:
	struct FPoseLink                              AnimGraph_0;                                       // 0x0000(0x0010)(Parm, OutParm, NoDestructor)
};
static_assert(alignof(CH_Protoborg_AnimBP_C_AnimGraph) == 0x000008, "Wrong alignment on CH_Protoborg_AnimBP_C_AnimGraph");
static_assert(sizeof(CH_Protoborg_AnimBP_C_AnimGraph) == 0x000010, "Wrong size on CH_Protoborg_AnimBP_C_AnimGraph");
static_assert(offsetof(CH_Protoborg_AnimBP_C_AnimGraph, AnimGraph_0) == 0x000000, "Member 'CH_Protoborg_AnimBP_C_AnimGraph::AnimGraph_0' has a wrong offset!");

// Function CH_Protoborg_AnimBP.CH_Protoborg_AnimBP_C.ReceiveDeathBlow
// 0x0002 (0x0002 - 0x0000)
struct CH_Protoborg_AnimBP_C_ReceiveDeathBlow final
{
public:
	ENUM_DeathBlowType                            BodyPart;                                          // 0x0000(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Result;                                            // 0x0001(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(CH_Protoborg_AnimBP_C_ReceiveDeathBlow) == 0x000001, "Wrong alignment on CH_Protoborg_AnimBP_C_ReceiveDeathBlow");
static_assert(sizeof(CH_Protoborg_AnimBP_C_ReceiveDeathBlow) == 0x000002, "Wrong size on CH_Protoborg_AnimBP_C_ReceiveDeathBlow");
static_assert(offsetof(CH_Protoborg_AnimBP_C_ReceiveDeathBlow, BodyPart) == 0x000000, "Member 'CH_Protoborg_AnimBP_C_ReceiveDeathBlow::BodyPart' has a wrong offset!");
static_assert(offsetof(CH_Protoborg_AnimBP_C_ReceiveDeathBlow, Result) == 0x000001, "Member 'CH_Protoborg_AnimBP_C_ReceiveDeathBlow::Result' has a wrong offset!");

// Function CH_Protoborg_AnimBP.CH_Protoborg_AnimBP_C.ReceiveImpact
// 0x0050 (0x0050 - 0x0000)
struct CH_Protoborg_AnimBP_C_ReceiveImpact final
{
public:
	struct FVector                                Impulse;                                           // 0x0000(0x000C)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                ImpactLocation;                                    // 0x000C(0x000C)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                ImpactNormal;                                      // 0x0018(0x000C)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FName                                   BoneName;                                          // 0x0024(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_2C[0x4];                                       // 0x002C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class FString                                 DamageType;                                        // 0x0030(0x0010)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, HasGetValueTypeHash)
	float                                         DamageAmount;                                      // 0x0040(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         FlinchTime;                                        // 0x0044(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Result;                                            // 0x0048(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(CH_Protoborg_AnimBP_C_ReceiveImpact) == 0x000008, "Wrong alignment on CH_Protoborg_AnimBP_C_ReceiveImpact");
static_assert(sizeof(CH_Protoborg_AnimBP_C_ReceiveImpact) == 0x000050, "Wrong size on CH_Protoborg_AnimBP_C_ReceiveImpact");
static_assert(offsetof(CH_Protoborg_AnimBP_C_ReceiveImpact, Impulse) == 0x000000, "Member 'CH_Protoborg_AnimBP_C_ReceiveImpact::Impulse' has a wrong offset!");
static_assert(offsetof(CH_Protoborg_AnimBP_C_ReceiveImpact, ImpactLocation) == 0x00000C, "Member 'CH_Protoborg_AnimBP_C_ReceiveImpact::ImpactLocation' has a wrong offset!");
static_assert(offsetof(CH_Protoborg_AnimBP_C_ReceiveImpact, ImpactNormal) == 0x000018, "Member 'CH_Protoborg_AnimBP_C_ReceiveImpact::ImpactNormal' has a wrong offset!");
static_assert(offsetof(CH_Protoborg_AnimBP_C_ReceiveImpact, BoneName) == 0x000024, "Member 'CH_Protoborg_AnimBP_C_ReceiveImpact::BoneName' has a wrong offset!");
static_assert(offsetof(CH_Protoborg_AnimBP_C_ReceiveImpact, DamageType) == 0x000030, "Member 'CH_Protoborg_AnimBP_C_ReceiveImpact::DamageType' has a wrong offset!");
static_assert(offsetof(CH_Protoborg_AnimBP_C_ReceiveImpact, DamageAmount) == 0x000040, "Member 'CH_Protoborg_AnimBP_C_ReceiveImpact::DamageAmount' has a wrong offset!");
static_assert(offsetof(CH_Protoborg_AnimBP_C_ReceiveImpact, FlinchTime) == 0x000044, "Member 'CH_Protoborg_AnimBP_C_ReceiveImpact::FlinchTime' has a wrong offset!");
static_assert(offsetof(CH_Protoborg_AnimBP_C_ReceiveImpact, Result) == 0x000048, "Member 'CH_Protoborg_AnimBP_C_ReceiveImpact::Result' has a wrong offset!");

// Function CH_Protoborg_AnimBP.CH_Protoborg_AnimBP_C.SetIsAlive
// 0x0002 (0x0002 - 0x0000)
struct CH_Protoborg_AnimBP_C_SetIsAlive final
{
public:
	bool                                          IsAlive_0;                                         // 0x0000(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          Result;                                            // 0x0001(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(CH_Protoborg_AnimBP_C_SetIsAlive) == 0x000001, "Wrong alignment on CH_Protoborg_AnimBP_C_SetIsAlive");
static_assert(sizeof(CH_Protoborg_AnimBP_C_SetIsAlive) == 0x000002, "Wrong size on CH_Protoborg_AnimBP_C_SetIsAlive");
static_assert(offsetof(CH_Protoborg_AnimBP_C_SetIsAlive, IsAlive_0) == 0x000000, "Member 'CH_Protoborg_AnimBP_C_SetIsAlive::IsAlive_0' has a wrong offset!");
static_assert(offsetof(CH_Protoborg_AnimBP_C_SetIsAlive, Result) == 0x000001, "Member 'CH_Protoborg_AnimBP_C_SetIsAlive::Result' has a wrong offset!");

// Function CH_Protoborg_AnimBP.CH_Protoborg_AnimBP_C.SetMovementParameters
// 0x0028 (0x0028 - 0x0000)
struct CH_Protoborg_AnimBP_C_SetMovementParameters final
{
public:
	struct FVector                                Velocity;                                          // 0x0000(0x000C)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FRotator                               Rotation;                                          // 0x000C(0x000C)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
	struct FRotator                               DesiredRotation;                                   // 0x0018(0x000C)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          Result;                                            // 0x0024(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(CH_Protoborg_AnimBP_C_SetMovementParameters) == 0x000004, "Wrong alignment on CH_Protoborg_AnimBP_C_SetMovementParameters");
static_assert(sizeof(CH_Protoborg_AnimBP_C_SetMovementParameters) == 0x000028, "Wrong size on CH_Protoborg_AnimBP_C_SetMovementParameters");
static_assert(offsetof(CH_Protoborg_AnimBP_C_SetMovementParameters, Velocity) == 0x000000, "Member 'CH_Protoborg_AnimBP_C_SetMovementParameters::Velocity' has a wrong offset!");
static_assert(offsetof(CH_Protoborg_AnimBP_C_SetMovementParameters, Rotation) == 0x00000C, "Member 'CH_Protoborg_AnimBP_C_SetMovementParameters::Rotation' has a wrong offset!");
static_assert(offsetof(CH_Protoborg_AnimBP_C_SetMovementParameters, DesiredRotation) == 0x000018, "Member 'CH_Protoborg_AnimBP_C_SetMovementParameters::DesiredRotation' has a wrong offset!");
static_assert(offsetof(CH_Protoborg_AnimBP_C_SetMovementParameters, Result) == 0x000024, "Member 'CH_Protoborg_AnimBP_C_SetMovementParameters::Result' has a wrong offset!");

// Function CH_Protoborg_AnimBP.CH_Protoborg_AnimBP_C.SetLookAtAlpha
// 0x0008 (0x0008 - 0x0000)
struct CH_Protoborg_AnimBP_C_SetLookAtAlpha final
{
public:
	float                                         Alpha;                                             // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Result;                                            // 0x0004(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(CH_Protoborg_AnimBP_C_SetLookAtAlpha) == 0x000004, "Wrong alignment on CH_Protoborg_AnimBP_C_SetLookAtAlpha");
static_assert(sizeof(CH_Protoborg_AnimBP_C_SetLookAtAlpha) == 0x000008, "Wrong size on CH_Protoborg_AnimBP_C_SetLookAtAlpha");
static_assert(offsetof(CH_Protoborg_AnimBP_C_SetLookAtAlpha, Alpha) == 0x000000, "Member 'CH_Protoborg_AnimBP_C_SetLookAtAlpha::Alpha' has a wrong offset!");
static_assert(offsetof(CH_Protoborg_AnimBP_C_SetLookAtAlpha, Result) == 0x000004, "Member 'CH_Protoborg_AnimBP_C_SetLookAtAlpha::Result' has a wrong offset!");

// Function CH_Protoborg_AnimBP.CH_Protoborg_AnimBP_C.SetLookAtLocation
// 0x0010 (0x0010 - 0x0000)
struct CH_Protoborg_AnimBP_C_SetLookAtLocation final
{
public:
	struct FVector                                Location;                                          // 0x0000(0x000C)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Result;                                            // 0x000C(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(CH_Protoborg_AnimBP_C_SetLookAtLocation) == 0x000004, "Wrong alignment on CH_Protoborg_AnimBP_C_SetLookAtLocation");
static_assert(sizeof(CH_Protoborg_AnimBP_C_SetLookAtLocation) == 0x000010, "Wrong size on CH_Protoborg_AnimBP_C_SetLookAtLocation");
static_assert(offsetof(CH_Protoborg_AnimBP_C_SetLookAtLocation, Location) == 0x000000, "Member 'CH_Protoborg_AnimBP_C_SetLookAtLocation::Location' has a wrong offset!");
static_assert(offsetof(CH_Protoborg_AnimBP_C_SetLookAtLocation, Result) == 0x00000C, "Member 'CH_Protoborg_AnimBP_C_SetLookAtLocation::Result' has a wrong offset!");

// Function CH_Protoborg_AnimBP.CH_Protoborg_AnimBP_C.SetStandingTurn
// 0x0008 (0x0008 - 0x0000)
struct CH_Protoborg_AnimBP_C_SetStandingTurn final
{
public:
	float                                         SignedAngleToTarget;                               // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          IsStanding;                                        // 0x0004(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          Result;                                            // 0x0005(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(CH_Protoborg_AnimBP_C_SetStandingTurn) == 0x000004, "Wrong alignment on CH_Protoborg_AnimBP_C_SetStandingTurn");
static_assert(sizeof(CH_Protoborg_AnimBP_C_SetStandingTurn) == 0x000008, "Wrong size on CH_Protoborg_AnimBP_C_SetStandingTurn");
static_assert(offsetof(CH_Protoborg_AnimBP_C_SetStandingTurn, SignedAngleToTarget) == 0x000000, "Member 'CH_Protoborg_AnimBP_C_SetStandingTurn::SignedAngleToTarget' has a wrong offset!");
static_assert(offsetof(CH_Protoborg_AnimBP_C_SetStandingTurn, IsStanding) == 0x000004, "Member 'CH_Protoborg_AnimBP_C_SetStandingTurn::IsStanding' has a wrong offset!");
static_assert(offsetof(CH_Protoborg_AnimBP_C_SetStandingTurn, Result) == 0x000005, "Member 'CH_Protoborg_AnimBP_C_SetStandingTurn::Result' has a wrong offset!");

// Function CH_Protoborg_AnimBP.CH_Protoborg_AnimBP_C.SetCatatonic
// 0x0002 (0x0002 - 0x0000)
struct CH_Protoborg_AnimBP_C_SetCatatonic final
{
public:
	bool                                          State;                                             // 0x0000(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          Result;                                            // 0x0001(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(CH_Protoborg_AnimBP_C_SetCatatonic) == 0x000001, "Wrong alignment on CH_Protoborg_AnimBP_C_SetCatatonic");
static_assert(sizeof(CH_Protoborg_AnimBP_C_SetCatatonic) == 0x000002, "Wrong size on CH_Protoborg_AnimBP_C_SetCatatonic");
static_assert(offsetof(CH_Protoborg_AnimBP_C_SetCatatonic, State) == 0x000000, "Member 'CH_Protoborg_AnimBP_C_SetCatatonic::State' has a wrong offset!");
static_assert(offsetof(CH_Protoborg_AnimBP_C_SetCatatonic, Result) == 0x000001, "Member 'CH_Protoborg_AnimBP_C_SetCatatonic::Result' has a wrong offset!");

// Function CH_Protoborg_AnimBP.CH_Protoborg_AnimBP_C.SetStance
// 0x0002 (0x0002 - 0x0000)
struct CH_Protoborg_AnimBP_C_SetStance final
{
public:
	ENUM_Emotions                                 Stance;                                            // 0x0000(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Result;                                            // 0x0001(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(CH_Protoborg_AnimBP_C_SetStance) == 0x000001, "Wrong alignment on CH_Protoborg_AnimBP_C_SetStance");
static_assert(sizeof(CH_Protoborg_AnimBP_C_SetStance) == 0x000002, "Wrong size on CH_Protoborg_AnimBP_C_SetStance");
static_assert(offsetof(CH_Protoborg_AnimBP_C_SetStance, Stance) == 0x000000, "Member 'CH_Protoborg_AnimBP_C_SetStance::Stance' has a wrong offset!");
static_assert(offsetof(CH_Protoborg_AnimBP_C_SetStance, Result) == 0x000001, "Member 'CH_Protoborg_AnimBP_C_SetStance::Result' has a wrong offset!");

// Function CH_Protoborg_AnimBP.CH_Protoborg_AnimBP_C.GetStance
// 0x0001 (0x0001 - 0x0000)
struct CH_Protoborg_AnimBP_C_GetStance final
{
public:
	ENUM_Emotions                                 Stance;                                            // 0x0000(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(CH_Protoborg_AnimBP_C_GetStance) == 0x000001, "Wrong alignment on CH_Protoborg_AnimBP_C_GetStance");
static_assert(sizeof(CH_Protoborg_AnimBP_C_GetStance) == 0x000001, "Wrong size on CH_Protoborg_AnimBP_C_GetStance");
static_assert(offsetof(CH_Protoborg_AnimBP_C_GetStance, Stance) == 0x000000, "Member 'CH_Protoborg_AnimBP_C_GetStance::Stance' has a wrong offset!");

// Function CH_Protoborg_AnimBP.CH_Protoborg_AnimBP_C.GetRotation
// 0x0010 (0x0010 - 0x0000)
struct CH_Protoborg_AnimBP_C_GetRotation final
{
public:
	struct FRotator                               AnimRotationPerSecond;                             // 0x0000(0x000C)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
	float                                         AnimRotationAlpha;                                 // 0x000C(0x0004)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(CH_Protoborg_AnimBP_C_GetRotation) == 0x000004, "Wrong alignment on CH_Protoborg_AnimBP_C_GetRotation");
static_assert(sizeof(CH_Protoborg_AnimBP_C_GetRotation) == 0x000010, "Wrong size on CH_Protoborg_AnimBP_C_GetRotation");
static_assert(offsetof(CH_Protoborg_AnimBP_C_GetRotation, AnimRotationPerSecond) == 0x000000, "Member 'CH_Protoborg_AnimBP_C_GetRotation::AnimRotationPerSecond' has a wrong offset!");
static_assert(offsetof(CH_Protoborg_AnimBP_C_GetRotation, AnimRotationAlpha) == 0x00000C, "Member 'CH_Protoborg_AnimBP_C_GetRotation::AnimRotationAlpha' has a wrong offset!");

// Function CH_Protoborg_AnimBP.CH_Protoborg_AnimBP_C.SetRelativeAimAngleOffset
// 0x0010 (0x0010 - 0x0000)
struct CH_Protoborg_AnimBP_C_SetRelativeAimAngleOffset final
{
public:
	float                                         YawOffset;                                         // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         PitchOffset;                                       // 0x0004(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         Alpha;                                             // 0x0008(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Result;                                            // 0x000C(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(CH_Protoborg_AnimBP_C_SetRelativeAimAngleOffset) == 0x000004, "Wrong alignment on CH_Protoborg_AnimBP_C_SetRelativeAimAngleOffset");
static_assert(sizeof(CH_Protoborg_AnimBP_C_SetRelativeAimAngleOffset) == 0x000010, "Wrong size on CH_Protoborg_AnimBP_C_SetRelativeAimAngleOffset");
static_assert(offsetof(CH_Protoborg_AnimBP_C_SetRelativeAimAngleOffset, YawOffset) == 0x000000, "Member 'CH_Protoborg_AnimBP_C_SetRelativeAimAngleOffset::YawOffset' has a wrong offset!");
static_assert(offsetof(CH_Protoborg_AnimBP_C_SetRelativeAimAngleOffset, PitchOffset) == 0x000004, "Member 'CH_Protoborg_AnimBP_C_SetRelativeAimAngleOffset::PitchOffset' has a wrong offset!");
static_assert(offsetof(CH_Protoborg_AnimBP_C_SetRelativeAimAngleOffset, Alpha) == 0x000008, "Member 'CH_Protoborg_AnimBP_C_SetRelativeAimAngleOffset::Alpha' has a wrong offset!");
static_assert(offsetof(CH_Protoborg_AnimBP_C_SetRelativeAimAngleOffset, Result) == 0x00000C, "Member 'CH_Protoborg_AnimBP_C_SetRelativeAimAngleOffset::Result' has a wrong offset!");

// Function CH_Protoborg_AnimBP.CH_Protoborg_AnimBP_C.SetIdleOverrideSequence
// 0x0010 (0x0010 - 0x0000)
struct CH_Protoborg_AnimBP_C_SetIdleOverrideSequence final
{
public:
	class UAnimSequenceBase*                      IdleOverride;                                      // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Result;                                            // 0x0008(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(CH_Protoborg_AnimBP_C_SetIdleOverrideSequence) == 0x000008, "Wrong alignment on CH_Protoborg_AnimBP_C_SetIdleOverrideSequence");
static_assert(sizeof(CH_Protoborg_AnimBP_C_SetIdleOverrideSequence) == 0x000010, "Wrong size on CH_Protoborg_AnimBP_C_SetIdleOverrideSequence");
static_assert(offsetof(CH_Protoborg_AnimBP_C_SetIdleOverrideSequence, IdleOverride) == 0x000000, "Member 'CH_Protoborg_AnimBP_C_SetIdleOverrideSequence::IdleOverride' has a wrong offset!");
static_assert(offsetof(CH_Protoborg_AnimBP_C_SetIdleOverrideSequence, Result) == 0x000008, "Member 'CH_Protoborg_AnimBP_C_SetIdleOverrideSequence::Result' has a wrong offset!");

// Function CH_Protoborg_AnimBP.CH_Protoborg_AnimBP_C.GetIdleOverrideSequence
// 0x0008 (0x0008 - 0x0000)
struct CH_Protoborg_AnimBP_C_GetIdleOverrideSequence final
{
public:
	class UAnimSequenceBase*                      IdleOverride;                                      // 0x0000(0x0008)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(CH_Protoborg_AnimBP_C_GetIdleOverrideSequence) == 0x000008, "Wrong alignment on CH_Protoborg_AnimBP_C_GetIdleOverrideSequence");
static_assert(sizeof(CH_Protoborg_AnimBP_C_GetIdleOverrideSequence) == 0x000008, "Wrong size on CH_Protoborg_AnimBP_C_GetIdleOverrideSequence");
static_assert(offsetof(CH_Protoborg_AnimBP_C_GetIdleOverrideSequence, IdleOverride) == 0x000000, "Member 'CH_Protoborg_AnimBP_C_GetIdleOverrideSequence::IdleOverride' has a wrong offset!");

// Function CH_Protoborg_AnimBP.CH_Protoborg_AnimBP_C.SetAimTarget
// 0x0010 (0x0010 - 0x0000)
struct CH_Protoborg_AnimBP_C_SetAimTarget final
{
public:
	class UOBJ_EnemyTarget_C*                     Target;                                            // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Result;                                            // 0x0008(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(CH_Protoborg_AnimBP_C_SetAimTarget) == 0x000008, "Wrong alignment on CH_Protoborg_AnimBP_C_SetAimTarget");
static_assert(sizeof(CH_Protoborg_AnimBP_C_SetAimTarget) == 0x000010, "Wrong size on CH_Protoborg_AnimBP_C_SetAimTarget");
static_assert(offsetof(CH_Protoborg_AnimBP_C_SetAimTarget, Target) == 0x000000, "Member 'CH_Protoborg_AnimBP_C_SetAimTarget::Target' has a wrong offset!");
static_assert(offsetof(CH_Protoborg_AnimBP_C_SetAimTarget, Result) == 0x000008, "Member 'CH_Protoborg_AnimBP_C_SetAimTarget::Result' has a wrong offset!");

// Function CH_Protoborg_AnimBP.CH_Protoborg_AnimBP_C.GetAimTarget
// 0x0008 (0x0008 - 0x0000)
struct CH_Protoborg_AnimBP_C_GetAimTarget final
{
public:
	class UOBJ_EnemyTarget_C*                     Target;                                            // 0x0000(0x0008)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(CH_Protoborg_AnimBP_C_GetAimTarget) == 0x000008, "Wrong alignment on CH_Protoborg_AnimBP_C_GetAimTarget");
static_assert(sizeof(CH_Protoborg_AnimBP_C_GetAimTarget) == 0x000008, "Wrong size on CH_Protoborg_AnimBP_C_GetAimTarget");
static_assert(offsetof(CH_Protoborg_AnimBP_C_GetAimTarget, Target) == 0x000000, "Member 'CH_Protoborg_AnimBP_C_GetAimTarget::Target' has a wrong offset!");

// Function CH_Protoborg_AnimBP.CH_Protoborg_AnimBP_C.SetTravelMode
// 0x0002 (0x0002 - 0x0000)
struct CH_Protoborg_AnimBP_C_SetTravelMode final
{
public:
	bool                                          TravelModeOn;                                      // 0x0000(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          Result;                                            // 0x0001(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(CH_Protoborg_AnimBP_C_SetTravelMode) == 0x000001, "Wrong alignment on CH_Protoborg_AnimBP_C_SetTravelMode");
static_assert(sizeof(CH_Protoborg_AnimBP_C_SetTravelMode) == 0x000002, "Wrong size on CH_Protoborg_AnimBP_C_SetTravelMode");
static_assert(offsetof(CH_Protoborg_AnimBP_C_SetTravelMode, TravelModeOn) == 0x000000, "Member 'CH_Protoborg_AnimBP_C_SetTravelMode::TravelModeOn' has a wrong offset!");
static_assert(offsetof(CH_Protoborg_AnimBP_C_SetTravelMode, Result) == 0x000001, "Member 'CH_Protoborg_AnimBP_C_SetTravelMode::Result' has a wrong offset!");

// Function CH_Protoborg_AnimBP.CH_Protoborg_AnimBP_C.SetSprintEnabled
// 0x0002 (0x0002 - 0x0000)
struct CH_Protoborg_AnimBP_C_SetSprintEnabled final
{
public:
	bool                                          SprintEnabled;                                     // 0x0000(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          Result;                                            // 0x0001(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(CH_Protoborg_AnimBP_C_SetSprintEnabled) == 0x000001, "Wrong alignment on CH_Protoborg_AnimBP_C_SetSprintEnabled");
static_assert(sizeof(CH_Protoborg_AnimBP_C_SetSprintEnabled) == 0x000002, "Wrong size on CH_Protoborg_AnimBP_C_SetSprintEnabled");
static_assert(offsetof(CH_Protoborg_AnimBP_C_SetSprintEnabled, SprintEnabled) == 0x000000, "Member 'CH_Protoborg_AnimBP_C_SetSprintEnabled::SprintEnabled' has a wrong offset!");
static_assert(offsetof(CH_Protoborg_AnimBP_C_SetSprintEnabled, Result) == 0x000001, "Member 'CH_Protoborg_AnimBP_C_SetSprintEnabled::Result' has a wrong offset!");

// Function CH_Protoborg_AnimBP.CH_Protoborg_AnimBP_C.SetStunnedSequence
// 0x0010 (0x0010 - 0x0000)
struct CH_Protoborg_AnimBP_C_SetStunnedSequence final
{
public:
	class UAnimSequence*                          StunnedSequence;                                   // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Result;                                            // 0x0008(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(CH_Protoborg_AnimBP_C_SetStunnedSequence) == 0x000008, "Wrong alignment on CH_Protoborg_AnimBP_C_SetStunnedSequence");
static_assert(sizeof(CH_Protoborg_AnimBP_C_SetStunnedSequence) == 0x000010, "Wrong size on CH_Protoborg_AnimBP_C_SetStunnedSequence");
static_assert(offsetof(CH_Protoborg_AnimBP_C_SetStunnedSequence, StunnedSequence) == 0x000000, "Member 'CH_Protoborg_AnimBP_C_SetStunnedSequence::StunnedSequence' has a wrong offset!");
static_assert(offsetof(CH_Protoborg_AnimBP_C_SetStunnedSequence, Result) == 0x000008, "Member 'CH_Protoborg_AnimBP_C_SetStunnedSequence::Result' has a wrong offset!");

// Function CH_Protoborg_AnimBP.CH_Protoborg_AnimBP_C.IsStunned
// 0x0001 (0x0001 - 0x0000)
struct CH_Protoborg_AnimBP_C_IsStunned final
{
public:
	bool                                          Result;                                            // 0x0000(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(CH_Protoborg_AnimBP_C_IsStunned) == 0x000001, "Wrong alignment on CH_Protoborg_AnimBP_C_IsStunned");
static_assert(sizeof(CH_Protoborg_AnimBP_C_IsStunned) == 0x000001, "Wrong size on CH_Protoborg_AnimBP_C_IsStunned");
static_assert(offsetof(CH_Protoborg_AnimBP_C_IsStunned, Result) == 0x000000, "Member 'CH_Protoborg_AnimBP_C_IsStunned::Result' has a wrong offset!");

// Function CH_Protoborg_AnimBP.CH_Protoborg_AnimBP_C.SetVoiceAmplitude
// 0x0008 (0x0008 - 0x0000)
struct CH_Protoborg_AnimBP_C_SetVoiceAmplitude final
{
public:
	float                                         VoiceAmplitude;                                    // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Result;                                            // 0x0004(0x0001)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(CH_Protoborg_AnimBP_C_SetVoiceAmplitude) == 0x000004, "Wrong alignment on CH_Protoborg_AnimBP_C_SetVoiceAmplitude");
static_assert(sizeof(CH_Protoborg_AnimBP_C_SetVoiceAmplitude) == 0x000008, "Wrong size on CH_Protoborg_AnimBP_C_SetVoiceAmplitude");
static_assert(offsetof(CH_Protoborg_AnimBP_C_SetVoiceAmplitude, VoiceAmplitude) == 0x000000, "Member 'CH_Protoborg_AnimBP_C_SetVoiceAmplitude::VoiceAmplitude' has a wrong offset!");
static_assert(offsetof(CH_Protoborg_AnimBP_C_SetVoiceAmplitude, Result) == 0x000004, "Member 'CH_Protoborg_AnimBP_C_SetVoiceAmplitude::Result' has a wrong offset!");

}

