#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: INTERF_ANIM_character

#include "Basic.hpp"

#include "CoreUObject_classes.hpp"
#include "ENUM_Emotions_structs.hpp"
#include "ENUM_DeathBlowType_structs.hpp"


namespace SDK
{

// BlueprintGeneratedClass INTERF_ANIM_character.INTERF_ANIM_Character_C
// 0x0000 (0x0028 - 0x0028)
class IINTERF_ANIM_Character_C final : public IInterface
{
public:
	void SetLookAtLocation(const struct FVector& Location, bool* Result);
	void SetLookAtAlpha(float Alpha, bool* Result);
	void SetMovementParameters(const struct FVector& Velocity, const struct FRotator& Rotation, const struct FRotator& DesiredRotation, bool* Result);
	void SetIsAlive(bool IsAlive, bool* Result);
	void ReceiveImpact(const struct FVector& Impulse, const struct FVector& ImpactLocation, const struct FVector& ImpactNormal, class FName BoneName, const class FString& DamageType, float DamageAmount, float FlinchTime, bool* Result);
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
		return StaticBPGeneratedClassImpl<"INTERF_ANIM_Character_C">();
	}
	static class IINTERF_ANIM_Character_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<IINTERF_ANIM_Character_C>();
	}
};
static_assert(alignof(IINTERF_ANIM_Character_C) == 0x000008, "Wrong alignment on IINTERF_ANIM_Character_C");
static_assert(sizeof(IINTERF_ANIM_Character_C) == 0x000028, "Wrong size on IINTERF_ANIM_Character_C");

}

