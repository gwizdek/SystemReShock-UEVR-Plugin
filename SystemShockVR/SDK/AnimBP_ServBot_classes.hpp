#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: AnimBP_ServBot

#include "Basic.hpp"

#include "AnimGraphRuntime_structs.hpp"
#include "Engine_structs.hpp"
#include "Engine_classes.hpp"
#include "CoreUObject_structs.hpp"
#include "ENUM_Emotions_structs.hpp"
#include "ENUM_DeathBlowType_structs.hpp"


namespace SDK
{

// AnimBlueprintGeneratedClass AnimBP_ServBot.AnimBP_ServBot_C
// 0x04F0 (0x07B0 - 0x02C0)
class UAnimBP_ServBot_C final : public UAnimInstance
{
public:
	uint8                                         Pad_2B8[0x8];                                      // 0x02B8(0x0008)(Fixing Size After Last Property [ Dumper-7 ])
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x02C0(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	struct FAnimNode_Root                         AnimGraphNode_Root;                                // 0x02C8(0x0030)()
	struct FAnimNode_BlendSpacePlayer             AnimGraphNode_BlendSpacePlayer;                    // 0x02F8(0x00E8)()
	struct FAnimNode_BlendListByBool              AnimGraphNode_BlendListByBool_2;                   // 0x03E0(0x00A0)()
	struct FAnimNode_BlendListByBool              AnimGraphNode_BlendListByBool_1;                   // 0x0480(0x00A0)()
	struct FAnimNode_SequencePlayer               AnimGraphNode_SequencePlayer_1;                    // 0x0520(0x0080)()
	struct FAnimNode_Slot                         AnimGraphNode_Slot;                                // 0x05A0(0x0048)()
	struct FAnimNode_PoseSnapshot                 AnimGraphNode_PoseSnapshot;                        // 0x05E8(0x0090)()
	struct FAnimNode_BlendListByBool              AnimGraphNode_BlendListByBool;                     // 0x0678(0x00A0)()
	struct FAnimNode_SequencePlayer               AnimGraphNode_SequencePlayer;                      // 0x0718(0x0080)()
	struct FVector2D                              RelativeMoveVelocity;                              // 0x0798(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          IsAlive;                                           // 0x07A0(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	bool                                          IsMoving;                                          // 0x07A1(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	bool                                          UseStunnedSequence;                                // 0x07A2(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                         Pad_7A3[0x5];                                      // 0x07A3(0x0005)(Fixing Size After Last Property [ Dumper-7 ])
	class UAnimSequenceBase*                      StunnedAnimSequence;                               // 0x07A8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_AnimBP_ServBot(int32 EntryPoint);
	void AnimGraph(struct FPoseLink* AnimGraph_0);
	void ReceiveImpact(const struct FVector& Impulse, const struct FVector& ImpactLocation, const struct FVector& ImpactNormal, class FName BoneName, const class FString& DamageType, float DamageAmount, float FlinchTime, bool* Result);
	void SetIsAlive(bool IsAlive_0, bool* Result);
	void SetMovementParameters(const struct FVector& Velocity, const struct FRotator& Rotation, const struct FRotator& DesiredRotation, bool* Result);
	void SetLookAtAlpha(float Alpha, bool* Result);
	void SetLookAtLocation(const struct FVector& Location, bool* Result);
	void ReceiveDeathBlow(ENUM_DeathBlowType BodyPart, bool* Result);
	void SetStandingTurn(float SignedAngleToTarget, bool IsStanding, bool* Result);
	void SetCatatonic(bool State, bool* Result);
	void SetStance(ENUM_Emotions Stance, bool* Result);
	void GetStance(ENUM_Emotions* Stance);
	void GetRotation(struct FRotator* AnimRotationPerSecond, float* AnimRotationAlpha);
	void SetRelativeAimAngleOffset(float YawOffset, float PitchOffset, float Alpha, bool* Result);
	void SetIdleOverrideSequence(class UAnimSequenceBase* IdleOverride, bool* Result);
	void GetIdleOverrideSequence(class UAnimSequenceBase** IdleOverride);
	void SetAimTarget(class UOBJ_EnemyTarget_C* Target, bool* Result);
	void GetAimTarget(class UOBJ_EnemyTarget_C** Target);
	void SetTravelMode(bool TravelModeOn, bool* Result);
	void SetSprintEnabled(bool SprintEnabled, bool* Result);
	void SetStunnedSequence(class UAnimSequence* StunnedSequence, bool* Result);
	void IsStunned(bool* Result);
	void SetVoiceAmplitude(float VoiceAmplitude, bool* Result);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"AnimBP_ServBot_C">();
	}
	static class UAnimBP_ServBot_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UAnimBP_ServBot_C>();
	}
};
static_assert(alignof(UAnimBP_ServBot_C) == 0x000010, "Wrong alignment on UAnimBP_ServBot_C");
static_assert(sizeof(UAnimBP_ServBot_C) == 0x0007B0, "Wrong size on UAnimBP_ServBot_C");
static_assert(offsetof(UAnimBP_ServBot_C, UberGraphFrame) == 0x0002C0, "Member 'UAnimBP_ServBot_C::UberGraphFrame' has a wrong offset!");
static_assert(offsetof(UAnimBP_ServBot_C, AnimGraphNode_Root) == 0x0002C8, "Member 'UAnimBP_ServBot_C::AnimGraphNode_Root' has a wrong offset!");
static_assert(offsetof(UAnimBP_ServBot_C, AnimGraphNode_BlendSpacePlayer) == 0x0002F8, "Member 'UAnimBP_ServBot_C::AnimGraphNode_BlendSpacePlayer' has a wrong offset!");
static_assert(offsetof(UAnimBP_ServBot_C, AnimGraphNode_BlendListByBool_2) == 0x0003E0, "Member 'UAnimBP_ServBot_C::AnimGraphNode_BlendListByBool_2' has a wrong offset!");
static_assert(offsetof(UAnimBP_ServBot_C, AnimGraphNode_BlendListByBool_1) == 0x000480, "Member 'UAnimBP_ServBot_C::AnimGraphNode_BlendListByBool_1' has a wrong offset!");
static_assert(offsetof(UAnimBP_ServBot_C, AnimGraphNode_SequencePlayer_1) == 0x000520, "Member 'UAnimBP_ServBot_C::AnimGraphNode_SequencePlayer_1' has a wrong offset!");
static_assert(offsetof(UAnimBP_ServBot_C, AnimGraphNode_Slot) == 0x0005A0, "Member 'UAnimBP_ServBot_C::AnimGraphNode_Slot' has a wrong offset!");
static_assert(offsetof(UAnimBP_ServBot_C, AnimGraphNode_PoseSnapshot) == 0x0005E8, "Member 'UAnimBP_ServBot_C::AnimGraphNode_PoseSnapshot' has a wrong offset!");
static_assert(offsetof(UAnimBP_ServBot_C, AnimGraphNode_BlendListByBool) == 0x000678, "Member 'UAnimBP_ServBot_C::AnimGraphNode_BlendListByBool' has a wrong offset!");
static_assert(offsetof(UAnimBP_ServBot_C, AnimGraphNode_SequencePlayer) == 0x000718, "Member 'UAnimBP_ServBot_C::AnimGraphNode_SequencePlayer' has a wrong offset!");
static_assert(offsetof(UAnimBP_ServBot_C, RelativeMoveVelocity) == 0x000798, "Member 'UAnimBP_ServBot_C::RelativeMoveVelocity' has a wrong offset!");
static_assert(offsetof(UAnimBP_ServBot_C, IsAlive) == 0x0007A0, "Member 'UAnimBP_ServBot_C::IsAlive' has a wrong offset!");
static_assert(offsetof(UAnimBP_ServBot_C, IsMoving) == 0x0007A1, "Member 'UAnimBP_ServBot_C::IsMoving' has a wrong offset!");
static_assert(offsetof(UAnimBP_ServBot_C, UseStunnedSequence) == 0x0007A2, "Member 'UAnimBP_ServBot_C::UseStunnedSequence' has a wrong offset!");
static_assert(offsetof(UAnimBP_ServBot_C, StunnedAnimSequence) == 0x0007A8, "Member 'UAnimBP_ServBot_C::StunnedAnimSequence' has a wrong offset!");

}

