#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: FUNCLIB_Corpse

#include "Basic.hpp"

#include "Enum_CorpseOutfits_structs.hpp"
#include "Engine_classes.hpp"
#include "BodyType_structs.hpp"
#include "ENUM_HumanCorpseLimbType_structs.hpp"
#include "Enum_CauseOfDeath_structs.hpp"


namespace SDK
{

// BlueprintGeneratedClass FUNCLIB_Corpse.FUNCLIB_Corpse_C
// 0x0000 (0x0028 - 0x0028)
class UFUNCLIB_Corpse_C final : public UBlueprintFunctionLibrary
{
public:
	static void UpdateHumanCorpseSkinMaterial(class UMeshComponent* MeshComponent, EBodyType BodyType, Enum_CauseOfDeath CauseOfDeath, float SkinPigmentScalar, class UObject* __WorldContext, class UMaterialInstanceDynamic** ResultMaterial);
	static void UpdateHumanCorpseSkinPigment(class UMaterialInstanceDynamic* SkinMaterial, class UCurveLinearColor* SkinToneCurve, float SkinPigmentScalar, class UObject* __WorldContext);
	static void UpdateHumanCorpseOutfit(class USkeletalMeshComponent* MeshComponent, EBodyType BodyType, Enum_CorpseOutfits OutfitType, bool UpdateMesh, class UObject* __WorldContext);
	static void GetHumanCorpseMesh(EBodyType BodyType, Enum_CorpseOutfits OutfitType, class UObject* __WorldContext, class USkeletalMesh** Result);
	static void UpdateHumanCorpseOutfitOffsets(class UMaterialInstanceDynamic* SkinMaterial, const struct FVector& DetailOffsetA, const struct FVector& DetailOffsetB, class UObject* __WorldContext);
	static void UpdateHumanCorpseBloodParams(class UMaterialInstanceDynamic* SkinMaterial, float BloodAmountA, float BloodAmountB, float BloodContrast, class UObject* __WorldContext);
	static void GetHumanCorpseLimbMesh(ENUM_HumanCorpseLimbType LimbType, EBodyType BodyType, Enum_CorpseOutfits OutfitType, class UObject* __WorldContext, class USkeletalMesh** Mesh);
	static void GetRandomHumanCorpseOutfit(class UObject* __WorldContext, Enum_CorpseOutfits* Result);
	static void GetRandomHumanCorpseBodyType(class UObject* __WorldContext, EBodyType* Result);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"FUNCLIB_Corpse_C">();
	}
	static class UFUNCLIB_Corpse_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UFUNCLIB_Corpse_C>();
	}
};
static_assert(alignof(UFUNCLIB_Corpse_C) == 0x000008, "Wrong alignment on UFUNCLIB_Corpse_C");
static_assert(sizeof(UFUNCLIB_Corpse_C) == 0x000028, "Wrong size on UFUNCLIB_Corpse_C");

}

