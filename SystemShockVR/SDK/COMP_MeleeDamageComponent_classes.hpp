#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: COMP_MeleeDamageComponent

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "Engine_classes.hpp"
#include "STRUCT_MeleeHitboxOverlapData_structs.hpp"


namespace SDK
{

// BlueprintGeneratedClass COMP_MeleeDamageComponent.COMP_MeleeDamageComponent_C
// 0x00A0 (0x0150 - 0x00B0)
class UCOMP_MeleeDamageComponent_C final : public UActorComponent
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x00B0(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	bool                                          DamagePlayerOnly;                                  // 0x00B8(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_B9[0x7];                                       // 0x00B9(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	FMulticastInlineDelegateProperty_             OnHitboxBeginOverlap;                              // 0x00C0(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, BlueprintAssignable, BlueprintCallable)
	FMulticastInlineDelegateProperty_             OnHitboxEndOverlap;                                // 0x00D0(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, BlueprintAssignable, BlueprintCallable)
	bool                                          DebugDrawColliders;                                // 0x00E0(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_E1[0x3];                                       // 0x00E1(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class FName                                   CollisionProfileName;                              // 0x00E4(0x0008)(Edit, BlueprintVisible, BlueprintReadOnly, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_EC[0x4];                                       // 0x00EC(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	TMap<class FName, float>                      TagDamageScales;                                   // 0x00F0(0x0050)(Edit, BlueprintVisible, BlueprintReadOnly, DisableEditOnInstance)
	TArray<struct FSTRUCT_MeleeHitboxOverlapData> HitboxOverlaps;                                    // 0x0140(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance, SaveGame, ContainsInstancedReference)

public:
	void OnHitboxBeginOverlap__DelegateSignature(class AActor* OverlapActor, class UPrimitiveComponent* OverlapComponent, class FName HitboxTag, float DamageScale, class UBoxComponent* HitboxComponent);
	void OnHitboxEndOverlap__DelegateSignature(class AActor* OverlapActor, class FName HitboxTag);
	void ExecuteUbergraph_COMP_MeleeDamageComponent(int32 EntryPoint);
	void ReceiveTick(float DeltaSeconds);
	void ReceiveBeginPlay();
	void InitializeHitboxes();
	void EnableHitboxesByTag(class FName HitboxTag);
	void GetPrioritizedHitboxesByTag(class FName HitboxesTag, TArray<class UBoxComponent*>* Result);
	void DisableHitboxesByTag(class FName HitboxTag);
	bool CompareHitboxComponentDamage(const class UObject* ObjectA, const class UObject* ObjectB);
	void HasAnyHitboxOverlaps(bool* Result);
	void GetHitboxOverlapIndexByTag(class FName Tag, int32* Index_0);
	void DisableAllHitboxes();
	void UpdateHitboxOverlaps(float DeltaTime);
	void HandleHitboxOverlap(class UBoxComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComponent, class FName HitboxTag, bool DuringUpdate);
	void GetCurrentHitboxDirection(class UBoxComponent* HitboxComponent, struct FVector* Vector);
	void GetHitboxDamageScale(class UBoxComponent* HitboxComponent, float* Result);
	bool ShouldSaveComponent(struct FStreamingSaveGameComponentParams* Params_0);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"COMP_MeleeDamageComponent_C">();
	}
	static class UCOMP_MeleeDamageComponent_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UCOMP_MeleeDamageComponent_C>();
	}
};
static_assert(alignof(UCOMP_MeleeDamageComponent_C) == 0x000008, "Wrong alignment on UCOMP_MeleeDamageComponent_C");
static_assert(sizeof(UCOMP_MeleeDamageComponent_C) == 0x000150, "Wrong size on UCOMP_MeleeDamageComponent_C");
static_assert(offsetof(UCOMP_MeleeDamageComponent_C, UberGraphFrame) == 0x0000B0, "Member 'UCOMP_MeleeDamageComponent_C::UberGraphFrame' has a wrong offset!");
static_assert(offsetof(UCOMP_MeleeDamageComponent_C, DamagePlayerOnly) == 0x0000B8, "Member 'UCOMP_MeleeDamageComponent_C::DamagePlayerOnly' has a wrong offset!");
static_assert(offsetof(UCOMP_MeleeDamageComponent_C, OnHitboxBeginOverlap) == 0x0000C0, "Member 'UCOMP_MeleeDamageComponent_C::OnHitboxBeginOverlap' has a wrong offset!");
static_assert(offsetof(UCOMP_MeleeDamageComponent_C, OnHitboxEndOverlap) == 0x0000D0, "Member 'UCOMP_MeleeDamageComponent_C::OnHitboxEndOverlap' has a wrong offset!");
static_assert(offsetof(UCOMP_MeleeDamageComponent_C, DebugDrawColliders) == 0x0000E0, "Member 'UCOMP_MeleeDamageComponent_C::DebugDrawColliders' has a wrong offset!");
static_assert(offsetof(UCOMP_MeleeDamageComponent_C, CollisionProfileName) == 0x0000E4, "Member 'UCOMP_MeleeDamageComponent_C::CollisionProfileName' has a wrong offset!");
static_assert(offsetof(UCOMP_MeleeDamageComponent_C, TagDamageScales) == 0x0000F0, "Member 'UCOMP_MeleeDamageComponent_C::TagDamageScales' has a wrong offset!");
static_assert(offsetof(UCOMP_MeleeDamageComponent_C, HitboxOverlaps) == 0x000140, "Member 'UCOMP_MeleeDamageComponent_C::HitboxOverlaps' has a wrong offset!");

}

