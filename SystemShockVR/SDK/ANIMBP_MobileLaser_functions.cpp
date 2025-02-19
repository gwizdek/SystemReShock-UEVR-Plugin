#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: ANIMBP_MobileLaser

#include "Basic.hpp"

#include "ANIMBP_MobileLaser_classes.hpp"
#include "ANIMBP_MobileLaser_parameters.hpp"


namespace SDK
{

// Function ANIMBP_MobileLaser.ANIMBP_MobileLaser_C.ExecuteUbergraph_ANIMBP_MobileLaser
// (Final, UbergraphFunction, HasDefaults)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UANIMBP_MobileLaser_C::ExecuteUbergraph_ANIMBP_MobileLaser(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ANIMBP_MobileLaser_C", "ExecuteUbergraph_ANIMBP_MobileLaser");

	Params::ANIMBP_MobileLaser_C_ExecuteUbergraph_ANIMBP_MobileLaser Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function ANIMBP_MobileLaser.ANIMBP_MobileLaser_C.GetReferences
// (BlueprintCallable, BlueprintEvent)

void UANIMBP_MobileLaser_C::GetReferences()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ANIMBP_MobileLaser_C", "GetReferences");

	UObject::ProcessEvent(Func, nullptr);
}


// Function ANIMBP_MobileLaser.ANIMBP_MobileLaser_C.BlueprintUpdateAnimation
// (Event, Public, BlueprintEvent)
// Parameters:
// float                                   DeltaTimeX                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UANIMBP_MobileLaser_C::BlueprintUpdateAnimation(float DeltaTimeX)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ANIMBP_MobileLaser_C", "BlueprintUpdateAnimation");

	Params::ANIMBP_MobileLaser_C_BlueprintUpdateAnimation Parms{};

	Parms.DeltaTimeX = DeltaTimeX;

	UObject::ProcessEvent(Func, &Parms);
}


// Function ANIMBP_MobileLaser.ANIMBP_MobileLaser_C.UpdateLeanParameters
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// int32                                   IterationCount                                         (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// float                                   LinearSpeed                                            (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// float                                   AngularSpeed                                           (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UANIMBP_MobileLaser_C::UpdateLeanParameters(int32* IterationCount, float* LinearSpeed, float* AngularSpeed)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ANIMBP_MobileLaser_C", "UpdateLeanParameters");

	Params::ANIMBP_MobileLaser_C_UpdateLeanParameters Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (IterationCount != nullptr)
		*IterationCount = Parms.IterationCount;

	if (LinearSpeed != nullptr)
		*LinearSpeed = Parms.LinearSpeed;

	if (AngularSpeed != nullptr)
		*AngularSpeed = Parms.AngularSpeed;
}


// Function ANIMBP_MobileLaser.ANIMBP_MobileLaser_C.UpdateAimSettings
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// float                                   DeltaTime                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UANIMBP_MobileLaser_C::UpdateAimSettings(float DeltaTime)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ANIMBP_MobileLaser_C", "UpdateAimSettings");

	Params::ANIMBP_MobileLaser_C_UpdateAimSettings Parms{};

	Parms.DeltaTime = DeltaTime;

	UObject::ProcessEvent(Func, &Parms);
}


// Function ANIMBP_MobileLaser.ANIMBP_MobileLaser_C.UpdateLaserSpin
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// float                                   DeltaTime                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UANIMBP_MobileLaser_C::UpdateLaserSpin(float DeltaTime)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ANIMBP_MobileLaser_C", "UpdateLaserSpin");

	Params::ANIMBP_MobileLaser_C_UpdateLaserSpin Parms{};

	Parms.DeltaTime = DeltaTime;

	UObject::ProcessEvent(Func, &Parms);
}


// Function ANIMBP_MobileLaser.ANIMBP_MobileLaser_C.GetTargetLocalAimDirection
// (Protected, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// struct FVector                          TargetLocalDirection                                   (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UANIMBP_MobileLaser_C::GetTargetLocalAimDirection(struct FVector* TargetLocalDirection)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ANIMBP_MobileLaser_C", "GetTargetLocalAimDirection");

	Params::ANIMBP_MobileLaser_C_GetTargetLocalAimDirection Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (TargetLocalDirection != nullptr)
		*TargetLocalDirection = std::move(Parms.TargetLocalDirection);
}


// Function ANIMBP_MobileLaser.ANIMBP_MobileLaser_C.GetCurrentLocalAimDirection
// (Protected, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// struct FVector                          TargetLocalDirection                                   (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UANIMBP_MobileLaser_C::GetCurrentLocalAimDirection(struct FVector* TargetLocalDirection)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ANIMBP_MobileLaser_C", "GetCurrentLocalAimDirection");

	Params::ANIMBP_MobileLaser_C_GetCurrentLocalAimDirection Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (TargetLocalDirection != nullptr)
		*TargetLocalDirection = std::move(Parms.TargetLocalDirection);
}


// Function ANIMBP_MobileLaser.ANIMBP_MobileLaser_C.WorldDirectionToLocalDirection
// (Private, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// struct FVector                          WorldDirection                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FVector                          LocalDirection                                         (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UANIMBP_MobileLaser_C::WorldDirectionToLocalDirection(const struct FVector& WorldDirection, struct FVector* LocalDirection)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ANIMBP_MobileLaser_C", "WorldDirectionToLocalDirection");

	Params::ANIMBP_MobileLaser_C_WorldDirectionToLocalDirection Parms{};

	Parms.WorldDirection = std::move(WorldDirection);

	UObject::ProcessEvent(Func, &Parms);

	if (LocalDirection != nullptr)
		*LocalDirection = std::move(Parms.LocalDirection);
}


// Function ANIMBP_MobileLaser.ANIMBP_MobileLaser_C.LocalDirectionToWorldDirection
// (Private, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// struct FVector                          WorldDirection                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FVector                          LocalDirection                                         (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UANIMBP_MobileLaser_C::LocalDirectionToWorldDirection(const struct FVector& WorldDirection, struct FVector* LocalDirection)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ANIMBP_MobileLaser_C", "LocalDirectionToWorldDirection");

	Params::ANIMBP_MobileLaser_C_LocalDirectionToWorldDirection Parms{};

	Parms.WorldDirection = std::move(WorldDirection);

	UObject::ProcessEvent(Func, &Parms);

	if (LocalDirection != nullptr)
		*LocalDirection = std::move(Parms.LocalDirection);
}


// Function ANIMBP_MobileLaser.ANIMBP_MobileLaser_C.HorizontalVerticalToLocalRotator
// (Private, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// struct FVector2D                        HorizontalVertical                                     (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FRotator                         LocalRotator                                           (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UANIMBP_MobileLaser_C::HorizontalVerticalToLocalRotator(const struct FVector2D& HorizontalVertical, struct FRotator* LocalRotator)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ANIMBP_MobileLaser_C", "HorizontalVerticalToLocalRotator");

	Params::ANIMBP_MobileLaser_C_HorizontalVerticalToLocalRotator Parms{};

	Parms.HorizontalVertical = std::move(HorizontalVertical);

	UObject::ProcessEvent(Func, &Parms);

	if (LocalRotator != nullptr)
		*LocalRotator = std::move(Parms.LocalRotator);
}


// Function ANIMBP_MobileLaser.ANIMBP_MobileLaser_C.LocalRotatorToHorizontalVertical
// (Private, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// struct FRotator                         LocalRotator                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
// struct FVector2D                        HorizontalVertical                                     (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UANIMBP_MobileLaser_C::LocalRotatorToHorizontalVertical(const struct FRotator& LocalRotator, struct FVector2D* HorizontalVertical)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ANIMBP_MobileLaser_C", "LocalRotatorToHorizontalVertical");

	Params::ANIMBP_MobileLaser_C_LocalRotatorToHorizontalVertical Parms{};

	Parms.LocalRotator = std::move(LocalRotator);

	UObject::ProcessEvent(Func, &Parms);

	if (HorizontalVertical != nullptr)
		*HorizontalVertical = std::move(Parms.HorizontalVertical);
}


// Function ANIMBP_MobileLaser.ANIMBP_MobileLaser_C.AnimGraph
// (HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FPoseLink                        AnimGraph_0                                            (Parm, OutParm, NoDestructor)

void UANIMBP_MobileLaser_C::AnimGraph(struct FPoseLink* AnimGraph_0)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ANIMBP_MobileLaser_C", "AnimGraph");

	Params::ANIMBP_MobileLaser_C_AnimGraph Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (AnimGraph_0 != nullptr)
		*AnimGraph_0 = std::move(Parms.AnimGraph_0);
}


// Function ANIMBP_MobileLaser.ANIMBP_MobileLaser_C.SetSprintEnabled
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    SprintEnabled                                          (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UANIMBP_MobileLaser_C::SetSprintEnabled(bool SprintEnabled, bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ANIMBP_MobileLaser_C", "SetSprintEnabled");

	Params::ANIMBP_MobileLaser_C_SetSprintEnabled Parms{};

	Parms.SprintEnabled = SprintEnabled;

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function ANIMBP_MobileLaser.ANIMBP_MobileLaser_C.SetTravelMode
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    TravelModeOn                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UANIMBP_MobileLaser_C::SetTravelMode(bool TravelModeOn, bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ANIMBP_MobileLaser_C", "SetTravelMode");

	Params::ANIMBP_MobileLaser_C_SetTravelMode Parms{};

	Parms.TravelModeOn = TravelModeOn;

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function ANIMBP_MobileLaser.ANIMBP_MobileLaser_C.SetAimTarget
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UOBJ_EnemyTarget_C*               Target                                                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UANIMBP_MobileLaser_C::SetAimTarget(class UOBJ_EnemyTarget_C* Target, bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ANIMBP_MobileLaser_C", "SetAimTarget");

	Params::ANIMBP_MobileLaser_C_SetAimTarget Parms{};

	Parms.Target = Target;

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function ANIMBP_MobileLaser.ANIMBP_MobileLaser_C.GetIdleOverrideSequence
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UAnimSequenceBase*                IdleOverride                                           (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UANIMBP_MobileLaser_C::GetIdleOverrideSequence(class UAnimSequenceBase** IdleOverride)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ANIMBP_MobileLaser_C", "GetIdleOverrideSequence");

	Params::ANIMBP_MobileLaser_C_GetIdleOverrideSequence Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (IdleOverride != nullptr)
		*IdleOverride = Parms.IdleOverride;
}


// Function ANIMBP_MobileLaser.ANIMBP_MobileLaser_C.SetIdleOverrideSequence
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UAnimSequenceBase*                IdleOverride                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UANIMBP_MobileLaser_C::SetIdleOverrideSequence(class UAnimSequenceBase* IdleOverride, bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ANIMBP_MobileLaser_C", "SetIdleOverrideSequence");

	Params::ANIMBP_MobileLaser_C_SetIdleOverrideSequence Parms{};

	Parms.IdleOverride = IdleOverride;

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function ANIMBP_MobileLaser.ANIMBP_MobileLaser_C.SetRelativeAimAngleOffset
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// float                                   YawOffset                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// float                                   PitchOffset                                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// float                                   Alpha                                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UANIMBP_MobileLaser_C::SetRelativeAimAngleOffset(float YawOffset, float PitchOffset, float Alpha, bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ANIMBP_MobileLaser_C", "SetRelativeAimAngleOffset");

	Params::ANIMBP_MobileLaser_C_SetRelativeAimAngleOffset Parms{};

	Parms.YawOffset = YawOffset;
	Parms.PitchOffset = PitchOffset;
	Parms.Alpha = Alpha;

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function ANIMBP_MobileLaser.ANIMBP_MobileLaser_C.GetRotation
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FRotator                         AnimRotationPerSecond                                  (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)
// float                                   AnimRotationAlpha                                      (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UANIMBP_MobileLaser_C::GetRotation(struct FRotator* AnimRotationPerSecond, float* AnimRotationAlpha)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ANIMBP_MobileLaser_C", "GetRotation");

	Params::ANIMBP_MobileLaser_C_GetRotation Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (AnimRotationPerSecond != nullptr)
		*AnimRotationPerSecond = std::move(Parms.AnimRotationPerSecond);

	if (AnimRotationAlpha != nullptr)
		*AnimRotationAlpha = Parms.AnimRotationAlpha;
}


// Function ANIMBP_MobileLaser.ANIMBP_MobileLaser_C.GetStance
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// ENUM_Emotions                           Stance                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UANIMBP_MobileLaser_C::GetStance(ENUM_Emotions* Stance)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ANIMBP_MobileLaser_C", "GetStance");

	Params::ANIMBP_MobileLaser_C_GetStance Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Stance != nullptr)
		*Stance = Parms.Stance;
}


// Function ANIMBP_MobileLaser.ANIMBP_MobileLaser_C.SetStance
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// ENUM_Emotions                           Stance                                                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UANIMBP_MobileLaser_C::SetStance(ENUM_Emotions Stance, bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ANIMBP_MobileLaser_C", "SetStance");

	Params::ANIMBP_MobileLaser_C_SetStance Parms{};

	Parms.Stance = Stance;

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function ANIMBP_MobileLaser.ANIMBP_MobileLaser_C.SetCatatonic
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    State                                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UANIMBP_MobileLaser_C::SetCatatonic(bool State, bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ANIMBP_MobileLaser_C", "SetCatatonic");

	Params::ANIMBP_MobileLaser_C_SetCatatonic Parms{};

	Parms.State = State;

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function ANIMBP_MobileLaser.ANIMBP_MobileLaser_C.SetStandingTurn
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// float                                   SignedAngleToTarget                                    (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    IsStanding                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UANIMBP_MobileLaser_C::SetStandingTurn(float SignedAngleToTarget, bool IsStanding, bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ANIMBP_MobileLaser_C", "SetStandingTurn");

	Params::ANIMBP_MobileLaser_C_SetStandingTurn Parms{};

	Parms.SignedAngleToTarget = SignedAngleToTarget;
	Parms.IsStanding = IsStanding;

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function ANIMBP_MobileLaser.ANIMBP_MobileLaser_C.ReceiveDeathBlow
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// ENUM_DeathBlowType                      BodyPart                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UANIMBP_MobileLaser_C::ReceiveDeathBlow(ENUM_DeathBlowType BodyPart, bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ANIMBP_MobileLaser_C", "ReceiveDeathBlow");

	Params::ANIMBP_MobileLaser_C_ReceiveDeathBlow Parms{};

	Parms.BodyPart = BodyPart;

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function ANIMBP_MobileLaser.ANIMBP_MobileLaser_C.ReceiveImpact
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FVector                          Impulse                                                (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FVector                          ImpactLocation                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FVector                          ImpactNormal                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class FName                             BoneName                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class FString                           DamageType                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, HasGetValueTypeHash)
// float                                   DamageAmount                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// float                                   FlinchTime                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UANIMBP_MobileLaser_C::ReceiveImpact(const struct FVector& Impulse, const struct FVector& ImpactLocation, const struct FVector& ImpactNormal, class FName BoneName, const class FString& DamageType, float DamageAmount, float FlinchTime, bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ANIMBP_MobileLaser_C", "ReceiveImpact");

	Params::ANIMBP_MobileLaser_C_ReceiveImpact Parms{};

	Parms.Impulse = std::move(Impulse);
	Parms.ImpactLocation = std::move(ImpactLocation);
	Parms.ImpactNormal = std::move(ImpactNormal);
	Parms.BoneName = BoneName;
	Parms.DamageType = std::move(DamageType);
	Parms.DamageAmount = DamageAmount;
	Parms.FlinchTime = FlinchTime;

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function ANIMBP_MobileLaser.ANIMBP_MobileLaser_C.SetIsAlive
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    IsAlive_0                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UANIMBP_MobileLaser_C::SetIsAlive(bool IsAlive_0, bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ANIMBP_MobileLaser_C", "SetIsAlive");

	Params::ANIMBP_MobileLaser_C_SetIsAlive Parms{};

	Parms.IsAlive_0 = IsAlive_0;

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function ANIMBP_MobileLaser.ANIMBP_MobileLaser_C.SetMovementParameters
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FVector                          Velocity                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FRotator                         Rotation_0                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
// struct FRotator                         DesiredRotation                                        (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UANIMBP_MobileLaser_C::SetMovementParameters(const struct FVector& Velocity, const struct FRotator& Rotation_0, const struct FRotator& DesiredRotation, bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ANIMBP_MobileLaser_C", "SetMovementParameters");

	Params::ANIMBP_MobileLaser_C_SetMovementParameters Parms{};

	Parms.Velocity = std::move(Velocity);
	Parms.Rotation_0 = std::move(Rotation_0);
	Parms.DesiredRotation = std::move(DesiredRotation);

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function ANIMBP_MobileLaser.ANIMBP_MobileLaser_C.SetLookAtAlpha
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// float                                   Alpha                                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UANIMBP_MobileLaser_C::SetLookAtAlpha(float Alpha, bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ANIMBP_MobileLaser_C", "SetLookAtAlpha");

	Params::ANIMBP_MobileLaser_C_SetLookAtAlpha Parms{};

	Parms.Alpha = Alpha;

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function ANIMBP_MobileLaser.ANIMBP_MobileLaser_C.SetLookAtLocation
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FVector                          Location                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UANIMBP_MobileLaser_C::SetLookAtLocation(const struct FVector& Location, bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ANIMBP_MobileLaser_C", "SetLookAtLocation");

	Params::ANIMBP_MobileLaser_C_SetLookAtLocation Parms{};

	Parms.Location = std::move(Location);

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function ANIMBP_MobileLaser.ANIMBP_MobileLaser_C.GetAimTarget
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UOBJ_EnemyTarget_C*               Target                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UANIMBP_MobileLaser_C::GetAimTarget(class UOBJ_EnemyTarget_C** Target)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ANIMBP_MobileLaser_C", "GetAimTarget");

	Params::ANIMBP_MobileLaser_C_GetAimTarget Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Target != nullptr)
		*Target = Parms.Target;
}


// Function ANIMBP_MobileLaser.ANIMBP_MobileLaser_C.SetStunnedSequence
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UAnimSequence*                    StunnedSequence                                        (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UANIMBP_MobileLaser_C::SetStunnedSequence(class UAnimSequence* StunnedSequence, bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ANIMBP_MobileLaser_C", "SetStunnedSequence");

	Params::ANIMBP_MobileLaser_C_SetStunnedSequence Parms{};

	Parms.StunnedSequence = StunnedSequence;

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function ANIMBP_MobileLaser.ANIMBP_MobileLaser_C.IsStunned
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UANIMBP_MobileLaser_C::IsStunned(bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ANIMBP_MobileLaser_C", "IsStunned");

	Params::ANIMBP_MobileLaser_C_IsStunned Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function ANIMBP_MobileLaser.ANIMBP_MobileLaser_C.SetVoiceAmplitude
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// float                                   VoiceAmplitude                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UANIMBP_MobileLaser_C::SetVoiceAmplitude(float VoiceAmplitude, bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ANIMBP_MobileLaser_C", "SetVoiceAmplitude");

	Params::ANIMBP_MobileLaser_C_SetVoiceAmplitude Parms{};

	Parms.VoiceAmplitude = VoiceAmplitude;

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}

}

