#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: CharacterUtility

#include "Basic.hpp"

#include "Engine_classes.hpp"
#include "ENUM_Axis_structs.hpp"


namespace SDK
{

// BlueprintGeneratedClass CharacterUtility.CharacterUtility_C
// 0x0000 (0x0028 - 0x0028)
class UCharacterUtility_C final : public UBlueprintFunctionLibrary
{
public:
	static void GetDistanceToMoveLocation(class APAWN_Enemy_C* EnemyPawn, class UObject* __WorldContext, float* Distance);
	static void IsCharacterLookingAt(class FName HeadSocketName, class USkeletalMeshComponent* CharacterMesh, const struct FVector& TargetLocation, ENUM_Axis ForwardAxis, bool ForwardIsNegative, float AcceptableAngle, class UObject* __WorldContext, bool* IsLookingAt);
	static void GetScaledRoundedHealthValue(int32 BaseHealth, int32 ScalePercentage, int32 RoundTo, class UObject* __WorldContext, int32* Result);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"CharacterUtility_C">();
	}
	static class UCharacterUtility_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UCharacterUtility_C>();
	}
};
static_assert(alignof(UCharacterUtility_C) == 0x000008, "Wrong alignment on UCharacterUtility_C");
static_assert(sizeof(UCharacterUtility_C) == 0x000028, "Wrong size on UCharacterUtility_C");

}

