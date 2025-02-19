#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: COMP_DismembermentManager

#include "Basic.hpp"

#include "ENUM_LimbStrength_structs.hpp"
#include "Engine_structs.hpp"
#include "Engine_classes.hpp"
#include "PhysicsCore_structs.hpp"


namespace SDK
{

// BlueprintGeneratedClass COMP_DismembermentManager.COMP_DismembermentManager_C
// 0x0230 (0x02E0 - 0x00B0)
class UCOMP_DismembermentManager_C final : public UActorComponent
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x00B0(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UClass*                                 DismembermentLimbClass;                            // 0x00B8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UDataTable*                             DismembermentDataTable;                            // 0x00C0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, SaveGame, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UDataTable*                             DynaDamageDataTable;                               // 0x00C8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, SaveGame, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         LowHideMask;                                       // 0x00D0(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, SaveGame, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         HighHideMask;                                      // 0x00D4(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, SaveGame, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TMap<class FName, class ULimbDamageAccumulator_C*> LimbDamageAccumulators;                            // 0x00D8(0x0050)(Edit, BlueprintVisible, DisableEditOnInstance)
	TMap<class FName, class ULimbDamageAccumulator_C*> DynaDamageAccumulators;                            // 0x0128(0x0050)(Edit, BlueprintVisible, DisableEditOnInstance)
	TArray<int32>                                 LimbHits;                                          // 0x0178(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance)
	TArray<int32>                                 DynaDamageHits;                                    // 0x0188(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance)
	int32                                         RemovedLimbBits;                                   // 0x0198(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, SaveGame, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         DestroyedDynaDamageBits;                           // 0x019C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, SaveGame, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UDataTable*                             DismembermentImpactTable;                          // 0x01A0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FName                                   LimbRowName;                                       // 0x01A8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, SaveGame, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TArray<class FName>                           OrderedLimbList;                                   // 0x01B0(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance)
	TMap<class FName, class FName>                BoneLimbMap;                                       // 0x01C0(0x0050)(Edit, BlueprintVisible, DisableEditOnInstance)
	bool                                          PendingDestroyLimbActor;                           // 0x0210(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                         Pad_211[0x7];                                      // 0x0211(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	TMap<class FName, class USkeletalMesh*>       CachedLimbMeshesToSpawn;                           // 0x0218(0x0050)(Edit, BlueprintVisible, DisableEditOnInstance)
	bool                                          DrawDynaDamageSphere;                              // 0x0268(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_269[0x7];                                      // 0x0269(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	TMap<class FName, float>                      DebugDynaDamages;                                  // 0x0270(0x0050)(Edit, BlueprintVisible, DisableEditOnInstance)
	FMulticastInlineDelegateProperty_             OnLimbDismembered;                                 // 0x02C0(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, BlueprintAssignable, BlueprintCallable)
	FMulticastInlineDelegateProperty_             OnDynaDamage;                                      // 0x02D0(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, BlueprintAssignable, BlueprintCallable)

public:
	void OnLimbDismembered__DelegateSignature(class FName LimbName, const struct FSTRUCT_DismemberableLimb& LimbData, class ADismembermentLimb_Base_C* LimbActor, bool OnBeginPlay);
	void OnDynaDamage__DelegateSignature(class FName DynaElementName, bool OnBeginPlay);
	void ExecuteUbergraph_COMP_DismembermentManager(int32 EntryPoint);
	void ReceiveTick(float DeltaSeconds);
	void StreamDismemberableLimbMesh(class FName LimbName, const struct FSTRUCT_DismemberableLimb& LimbData);
	void OnLoaded_3E0AC6B84CCA7F17E04CA4AA481994B7(class UObject* Loaded);
	void InitializeDismembermentManager();
	void InitializeDismemberedLimb(int32 LowHideMask_0, int32 HighHideMask_0, class UDataTable* DismembermentData, class UDataTable* DynaDamageData, class FName LimbRowName_0, int32 MissingLimbBits, int32 ActivatedDynaDamageBits, TArray<struct FVector4>& BloodData);
	void ReceiveDamage(class UOBJ_ImpactData_C* Impact, const struct FAttribDamageInstance& Damage, bool* LegDismembered, bool* LimbDismembered);
	void DealDamageToDismemberLimbs(class UOBJ_ImpactData_C* Impact, const struct FAttribDamageInstance& Damage, bool* LegDismembered, bool* LimbDismembered);
	void TryDismemberLimbManually(class FName LimbName, const struct FVector& ImpactPoint, const struct FVector& LinearImpulse, bool* Success);
	void ForceDismemberLimb(class FName LimbToDismember, class UOBJ_ImpactData_C* Impact, const struct FAttribDamageInstance& Damage, bool DestroyLimb_0, bool* LegDismembered);
	void SpawnDismemberedLimb(class FName Limb, class UOBJ_ImpactData_C* ImpactData, class ADismembermentLimb_Base_C** NewLimb);
	void DestroyLimb(class FName Limb, const struct FAttribDamageInstance& DamageInstance, class UOBJ_ImpactData_C* ImpactData);
	void GetLimbMesh(class USkeletalMeshComponent** Mesh);
	void RemoveLimb(class FName LimbName);
	void GetLimbDamageAccumulator(class FName Limb, class ULimbDamageAccumulator_C** Accumulator);
	void GetLimbName(class FName* Limb);
	void IsLimbAttached(class FName Limb, bool* Result);
	void SetHideIndices(TArray<int32>& HideIndices, bool HideState);
	void UpdateMaterialParameters();
	void HideInitialIDs();
	void IsOwnerAlive(bool* IsAlive);
	void DealDamageToDynaElements(class UOBJ_ImpactData_C* Impact, const struct FAttribDamageInstance& Damage, bool* PseudoLimbsDestroyed);
	void SpawnDynaDamageEffects(class FName DynaDamage);
	void DisableChildBoneCollision(class FName ParentBone, bool IsCleanBreak);
	void GetLimbByBone(class FName BoneName, class FName* Limb);
	void GetLimbByIndex(int32 Index_0, class FName* LimbName);
	void UpdateDestroyedDynaDamageBits(class FName ParentBoneName);
	void GetDynaDamageAccumumlator(class FName DynaDamageElement, class ULimbDamageAccumulator_C** Accumulator);
	void GetLimbRowName(const struct FSTRUCT_DismemberableLimb& Limb, class FName* RowName);
	void GetLimbData(class FName Limb, struct FSTRUCT_DismemberableLimb* LimbData);
	void GetLimbIndex(class FName LimbName, int32* Index_0);
	void TryApplyInstantDynaDamage(class FName DynaDamageElement, bool SpawnEffects, bool* Result);
	void GetDynaData(class FName DynaElement, struct FSTRUCT_DynaDamageElement* DynaData);
	void GetDynaIndex(class FName DynaElement, int32* Index_0);
	void HasAnyDismemberedLimbs(bool* Result);
	void HasAnyDynamicDamage(bool* Result);
	void HasAttachedChildLimb(bool* Result);
	void HasUnactivatedDynaDamage(bool* Result);
	void IsDynaElementUnactivated(class FName DynaElement, bool* Result);
	void GetChildLimbBits(class FName ParentLimb, bool IncludeSelf, int32* ChildBits);
	void GetChildLimbs(class FName ParentLimb, bool IncludeSelf, bool IncludeDescendants, TArray<class FName>* ChildLimbs);
	void GetChildDynaElements(class FName ParentElement, TArray<class FName>* ChildElements);
	void GetDynaDamageBonusFromBoneName(class FName BoneName, float* BonusPercent);
	void GetOrderedLimbList(TArray<class FName>* Limbs);
	void GetDynaDamageByBone(class FName Bone, TArray<class FName>* DynaDamageElements);
	void GetDynaDamageBone(class FName DynaDamage, class FName* Bone);
	void GetLimbStrengthSettings(ENUM_LimbStrength Strength, int32* StackArmor, int32* StackCount);
	void GetDynaDamageByIndex(int32 Index_0, class FName* DynaName);
	void SetOwnerLimbRemoved(class FName Limb, const struct FSTRUCT_DismemberableLimb& LimbData, class ADismembermentLimb_Base_C* LimbActor, bool Initialization);
	void SetOwnerDynaDestroyed(class FName DynaElement, bool Initialization);
	void ComputeSlicingDamage(const struct FAttribDamageInstance& DamageInstance, float* Result);
	void ShouldDestroyLimbActor(bool* Result);
	void DoesLimbDestroyActor(class FName Limb, bool* Result);
	void SpawnDismemberLimbEffects(class FName LimbName, class ADismembermentLimb_Base_C* NewLimb);
	void GetParentLimb(class FName ChildLimb, class FName* ParentLimb);
	void GetLimbBoneNames(class FName Limb, TArray<class FName>* LimbBoneNames);
	void GetDecalSampler(class USkinnedDecalSampler** SkinnedDecalSampler);
	void StreamDismemberableLimbAssets(class FName LimbName, const struct FSTRUCT_DismemberableLimb& LimbData);
	void SpawnEffect(const struct FSTRUCT_LimbSpawnEffect& EffectParams, class USceneComponent* ParentComponent, class FName BoneName);
	void SpawnEffectAttached(const struct FSTRUCT_LimbSpawnEffect& EffectParams, class FName BoneName);
	void SpawnEffectImmediately(class UNiagaraSystem* NiagaraSystem, class USceneComponent* ParentComponent, class FName BoneName, const struct FTransform& LocalTransform, class UNiagaraComponent** ParticleSystem);
	void DrawDebugSpheres();
	void TransferAttachedLimbEffects(class ADismembermentLimb_Base_C* New_Limb, class FName BoneName);
	void TransferDecals(class ADismembermentLimb_Base_C* NewLimb, bool* Result);
	void PlayDismemberImpactSound(class UOBJ_ImpactData_C* ImpactData, class FName BoneName);
	bool ShouldSaveComponent(struct FStreamingSaveGameComponentParams* Params_0);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"COMP_DismembermentManager_C">();
	}
	static class UCOMP_DismembermentManager_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UCOMP_DismembermentManager_C>();
	}
};
static_assert(alignof(UCOMP_DismembermentManager_C) == 0x000008, "Wrong alignment on UCOMP_DismembermentManager_C");
static_assert(sizeof(UCOMP_DismembermentManager_C) == 0x0002E0, "Wrong size on UCOMP_DismembermentManager_C");
static_assert(offsetof(UCOMP_DismembermentManager_C, UberGraphFrame) == 0x0000B0, "Member 'UCOMP_DismembermentManager_C::UberGraphFrame' has a wrong offset!");
static_assert(offsetof(UCOMP_DismembermentManager_C, DismembermentLimbClass) == 0x0000B8, "Member 'UCOMP_DismembermentManager_C::DismembermentLimbClass' has a wrong offset!");
static_assert(offsetof(UCOMP_DismembermentManager_C, DismembermentDataTable) == 0x0000C0, "Member 'UCOMP_DismembermentManager_C::DismembermentDataTable' has a wrong offset!");
static_assert(offsetof(UCOMP_DismembermentManager_C, DynaDamageDataTable) == 0x0000C8, "Member 'UCOMP_DismembermentManager_C::DynaDamageDataTable' has a wrong offset!");
static_assert(offsetof(UCOMP_DismembermentManager_C, LowHideMask) == 0x0000D0, "Member 'UCOMP_DismembermentManager_C::LowHideMask' has a wrong offset!");
static_assert(offsetof(UCOMP_DismembermentManager_C, HighHideMask) == 0x0000D4, "Member 'UCOMP_DismembermentManager_C::HighHideMask' has a wrong offset!");
static_assert(offsetof(UCOMP_DismembermentManager_C, LimbDamageAccumulators) == 0x0000D8, "Member 'UCOMP_DismembermentManager_C::LimbDamageAccumulators' has a wrong offset!");
static_assert(offsetof(UCOMP_DismembermentManager_C, DynaDamageAccumulators) == 0x000128, "Member 'UCOMP_DismembermentManager_C::DynaDamageAccumulators' has a wrong offset!");
static_assert(offsetof(UCOMP_DismembermentManager_C, LimbHits) == 0x000178, "Member 'UCOMP_DismembermentManager_C::LimbHits' has a wrong offset!");
static_assert(offsetof(UCOMP_DismembermentManager_C, DynaDamageHits) == 0x000188, "Member 'UCOMP_DismembermentManager_C::DynaDamageHits' has a wrong offset!");
static_assert(offsetof(UCOMP_DismembermentManager_C, RemovedLimbBits) == 0x000198, "Member 'UCOMP_DismembermentManager_C::RemovedLimbBits' has a wrong offset!");
static_assert(offsetof(UCOMP_DismembermentManager_C, DestroyedDynaDamageBits) == 0x00019C, "Member 'UCOMP_DismembermentManager_C::DestroyedDynaDamageBits' has a wrong offset!");
static_assert(offsetof(UCOMP_DismembermentManager_C, DismembermentImpactTable) == 0x0001A0, "Member 'UCOMP_DismembermentManager_C::DismembermentImpactTable' has a wrong offset!");
static_assert(offsetof(UCOMP_DismembermentManager_C, LimbRowName) == 0x0001A8, "Member 'UCOMP_DismembermentManager_C::LimbRowName' has a wrong offset!");
static_assert(offsetof(UCOMP_DismembermentManager_C, OrderedLimbList) == 0x0001B0, "Member 'UCOMP_DismembermentManager_C::OrderedLimbList' has a wrong offset!");
static_assert(offsetof(UCOMP_DismembermentManager_C, BoneLimbMap) == 0x0001C0, "Member 'UCOMP_DismembermentManager_C::BoneLimbMap' has a wrong offset!");
static_assert(offsetof(UCOMP_DismembermentManager_C, PendingDestroyLimbActor) == 0x000210, "Member 'UCOMP_DismembermentManager_C::PendingDestroyLimbActor' has a wrong offset!");
static_assert(offsetof(UCOMP_DismembermentManager_C, CachedLimbMeshesToSpawn) == 0x000218, "Member 'UCOMP_DismembermentManager_C::CachedLimbMeshesToSpawn' has a wrong offset!");
static_assert(offsetof(UCOMP_DismembermentManager_C, DrawDynaDamageSphere) == 0x000268, "Member 'UCOMP_DismembermentManager_C::DrawDynaDamageSphere' has a wrong offset!");
static_assert(offsetof(UCOMP_DismembermentManager_C, DebugDynaDamages) == 0x000270, "Member 'UCOMP_DismembermentManager_C::DebugDynaDamages' has a wrong offset!");
static_assert(offsetof(UCOMP_DismembermentManager_C, OnLimbDismembered) == 0x0002C0, "Member 'UCOMP_DismembermentManager_C::OnLimbDismembered' has a wrong offset!");
static_assert(offsetof(UCOMP_DismembermentManager_C, OnDynaDamage) == 0x0002D0, "Member 'UCOMP_DismembermentManager_C::OnDynaDamage' has a wrong offset!");

}

