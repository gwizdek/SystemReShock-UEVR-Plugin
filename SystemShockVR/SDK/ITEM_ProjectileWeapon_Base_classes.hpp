#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: ITEM_ProjectileWeapon_Base

#include "Basic.hpp"

#include "CoreUObject_structs.hpp"
#include "ENUM_ActionPriority_structs.hpp"
#include "Engine_structs.hpp"
#include "ITEM_WeaponBase_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass ITEM_ProjectileWeapon_Base.ITEM_ProjectileWeapon_Base_C
// 0x0200 (0x0550 - 0x0350)
class UITEM_ProjectileWeapon_Base_C : public UITEM_WeaponBase_C
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame_ITEM_ProjectileWeapon_Base_C;       // 0x0350(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	int32                                         CurrentMagazineAmmo;                               // 0x0358(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, SaveGame, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_35C[0x4];                                      // 0x035C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	TSoftObjectPtr<class UAnimMontage>            DischargeMontage;                                  // 0x0360(0x0028)(Edit, BlueprintVisible, DisableEditOnInstance, HasGetValueTypeHash)
	TSoftObjectPtr<class UAnimMontage>            DischargeDryMontage;                               // 0x0388(0x0028)(Edit, BlueprintVisible, DisableEditOnInstance, HasGetValueTypeHash)
	TSoftObjectPtr<class UAnimMontage>            DischargeFailMontage;                              // 0x03B0(0x0028)(Edit, BlueprintVisible, DisableEditOnInstance, HasGetValueTypeHash)
	TSoftObjectPtr<class UAnimMontage>            ReloadMontage;                                     // 0x03D8(0x0028)(Edit, BlueprintVisible, DisableEditOnInstance, HasGetValueTypeHash)
	TSoftObjectPtr<class UAnimMontage>            ReloadDryMontage;                                  // 0x0400(0x0028)(Edit, BlueprintVisible, DisableEditOnInstance, HasGetValueTypeHash)
	TSoftObjectPtr<class UAnimMontage>            ModeSwitchMontage;                                 // 0x0428(0x0028)(Edit, BlueprintVisible, DisableEditOnInstance, HasGetValueTypeHash)
	class UCOMP_PhysInstancedStaticMesh_C*        ShellCasingComponent;                              // 0x0450(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UStaticMesh*                            ShellMesh;                                         // 0x0458(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                ShellEjectRelativeDirection;                       // 0x0460(0x000C)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         ShellEjectSpeed;                                   // 0x046C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FString                                 ReloadAmmoMessage;                                 // 0x0470(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, HasGetValueTypeHash)
	class FString                                 EmptyAmmoMessage;                                  // 0x0480(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, HasGetValueTypeHash)
	class FString                                 EjectShellMessage;                                 // 0x0490(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, HasGetValueTypeHash)
	int32                                         SwitchToModeIndex;                                 // 0x04A0(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         ShotsFiredInBurst;                                 // 0x04A4(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         ManualQueueDuration;                               // 0x04A8(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         AutomaticQueueDuration;                            // 0x04AC(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          ShouldRefillMagazine;                              // 0x04B0(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	bool                                          HasKickback;                                       // 0x04B1(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_4B2[0x6];                                      // 0x04B2(0x0006)(Fixing Size After Last Property [ Dumper-7 ])
	struct FTimerHandle                           AutoFireTimerHandle;                               // 0x04B8(0x0008)(Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash)
	struct FTimerHandle                           AllowRefireTimerHandle;                            // 0x04C0(0x0008)(Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash)
	struct FRotator                               ProjectileOffsetRotation;                          // 0x04C8(0x000C)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                         Pad_4D4[0x4];                                      // 0x04D4(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	FMulticastInlineDelegateProperty_             OnMagazineChanged;                                 // 0x04D8(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, BlueprintAssignable, BlueprintCallable)
	class FString                                 ModeSwitchMessage;                                 // 0x04E8(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, HasGetValueTypeHash)
	class UAnimMontage*                           CachedDischargeMontage;                            // 0x04F8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UAnimMontage*                           CachedDischargeDryMontage;                         // 0x0500(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UAnimMontage*                           CachedDischargeFailMontage;                        // 0x0508(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UAnimMontage*                           CachedReloadMontage;                               // 0x0510(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UAnimMontage*                           CachedReloadDryMontage;                            // 0x0518(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UAnimMontage*                           CachedModeSwitchMontage;                           // 0x0520(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TSoftObjectPtr<class USoundCue>               ShellCasingCollisionSoundCue;                      // 0x0528(0x0028)(Edit, BlueprintVisible, DisableEditOnInstance, HasGetValueTypeHash)

public:
	void OnMagazineChanged__DelegateSignature();
	void ExecuteUbergraph_ITEM_ProjectileWeapon_Base(int32 EntryPoint);
	void StreamWeaponMontages();
	void OnLoaded_9046651747D724C56C1F3FB472BA2644(class UObject* Loaded);
	void OnLoaded_5DAA8C1E43E8A4939EEF1C91476CA4D4(class UObject* Loaded);
	void OnLoaded_2842429F4E6B3880E4FBCCB35F2E69FA(class UObject* Loaded);
	void OnLoaded_690C388B40163C7491D441BA893CD6FC(class UObject* Loaded);
	void OnLoaded_36493C924805267668187694115D493B(class UObject* Loaded);
	void OnLoaded_3960340748179C183102AEBC17F001F3(class UObject* Loaded);
	void ForceActivateWithPriority(ENUM_ActionPriority Priority, float QueueDuration);
	void ConsumeAmmo();
	void GetAdditionalMods(TArray<struct FAttribModApplyData>* Result);
	void HasAmmoInMagazineOrChamber(bool* Result);
	void GetAmmoInMagazineAndChamber(int32* Ammo);
	void CanEmptyAmmoInMagazineOrChamber(bool* Result);
	void HasLowAmmoInMagazineAndChamber(bool* Result);
	void GetAmmoInMagazine(int32* Ammo);
	void GetAmmoInChamber(int32* Ammo);
	void GetSpreadHalfAngle(float* Result);
	void ComputeSpreadDirection(const struct FVector& BarrelDirection, struct FVector* SpreadDirection);
	void QueueReloading();
	void OnDischargeMontageStarted();
	void IsTryingToRefillMagazine(bool* Result);
	void IsPlayingReloadMontage(bool* Result);
	void CanRefillMagazine(bool* Result);
	void HasSpareAmmo(bool* Result);
	void ShouldAutoReload(bool* Result);
	void SetListenToInventory(bool State);
	void SetListenToActionManager(bool State);
	void SetManualQueueDuration(float NewDuration);
	void TryEmptyMagazine();
	void OnMagazineEmptied();
	void OnMagazineRefilled();
	void SetupMaterial();
	void ReceiveAnimationMessage(const class FString& Message, bool* Result);
	void OnAutoReloadStateChanged(bool State);
	void MarkShouldRefillMagazine(bool State);
	void ForceAddAmmoToMagazine(int32 Ammo);
	void ForceSetAmmoInMagazine(int32 Ammo);
	void RefillMagazine();
	void UpdateMaterial(bool Glitch);
	void EjectShell();
	void MoveAmmoToInventory();
	void MoveAmmoFromChamberToMagazine();
	void EnableDamage(bool* Result);
	void FireProjectile(class AActor** FiredProjectile, struct FVector* Direction);
	void SetCurrentMode(int32 Mode, bool* Result);
	void EVENT_OnTryAutomaticRefire();
	void FireProjectileInDirection(const struct FVector& BarrelLocation, const struct FVector& ProjectileDirection, class AActor** FiredProjectile, struct FVector* Direction);
	void InitializeProjectileDamageSettings(class ABulletProjectile_Base_C* BulletProjectileActor);
	void PlayDischargeEffects();
	void GetProjectileClass(class UClass** Result);
	void GetDischargeMontage(class UAnimMontage** DischargeAnimation);
	void EVENT_OnAllowRefire();
	void QueueModeSwitchWithDuration(float Duration);
	void QueueModeSwitch();
	void GetWeaponModeDisplayName(int32 ModeIndex, bool ShortName, class FText* Result);
	void EVENT_OnDischargeStarted();
	void EVENT_OnTryReloadWhenActionFinished(class UCharacterAction_C* Action);
	void EVENT_OnTryReloadWhenAmmoBagChanged(int32 SlotIndex_0);
	void OnWeaponBecameActivatable(class APAWN_SystemShockCharacter_C* Character, bool ShowImmediately);
	void GetDesiredModeSwitchIndex(int32* Result);
	void TrySwitchToDesiredModeImmediately(bool* Result);
	void TryCreateShellCasingComponent();
	void TryDestroyShellCasingComponent();
	void TryBeginReloading(bool* Result);
	void OnBecomeUnactivatable(bool* Result);
	void Activate(class APAWN_SystemShockCharacter_C* Character, bool* Result);
	void Deactivate(bool* Result);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"ITEM_ProjectileWeapon_Base_C">();
	}
	static class UITEM_ProjectileWeapon_Base_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UITEM_ProjectileWeapon_Base_C>();
	}
};
static_assert(alignof(UITEM_ProjectileWeapon_Base_C) == 0x000008, "Wrong alignment on UITEM_ProjectileWeapon_Base_C");
static_assert(sizeof(UITEM_ProjectileWeapon_Base_C) == 0x000550, "Wrong size on UITEM_ProjectileWeapon_Base_C");
static_assert(offsetof(UITEM_ProjectileWeapon_Base_C, UberGraphFrame_ITEM_ProjectileWeapon_Base_C) == 0x000350, "Member 'UITEM_ProjectileWeapon_Base_C::UberGraphFrame_ITEM_ProjectileWeapon_Base_C' has a wrong offset!");
static_assert(offsetof(UITEM_ProjectileWeapon_Base_C, CurrentMagazineAmmo) == 0x000358, "Member 'UITEM_ProjectileWeapon_Base_C::CurrentMagazineAmmo' has a wrong offset!");
static_assert(offsetof(UITEM_ProjectileWeapon_Base_C, DischargeMontage) == 0x000360, "Member 'UITEM_ProjectileWeapon_Base_C::DischargeMontage' has a wrong offset!");
static_assert(offsetof(UITEM_ProjectileWeapon_Base_C, DischargeDryMontage) == 0x000388, "Member 'UITEM_ProjectileWeapon_Base_C::DischargeDryMontage' has a wrong offset!");
static_assert(offsetof(UITEM_ProjectileWeapon_Base_C, DischargeFailMontage) == 0x0003B0, "Member 'UITEM_ProjectileWeapon_Base_C::DischargeFailMontage' has a wrong offset!");
static_assert(offsetof(UITEM_ProjectileWeapon_Base_C, ReloadMontage) == 0x0003D8, "Member 'UITEM_ProjectileWeapon_Base_C::ReloadMontage' has a wrong offset!");
static_assert(offsetof(UITEM_ProjectileWeapon_Base_C, ReloadDryMontage) == 0x000400, "Member 'UITEM_ProjectileWeapon_Base_C::ReloadDryMontage' has a wrong offset!");
static_assert(offsetof(UITEM_ProjectileWeapon_Base_C, ModeSwitchMontage) == 0x000428, "Member 'UITEM_ProjectileWeapon_Base_C::ModeSwitchMontage' has a wrong offset!");
static_assert(offsetof(UITEM_ProjectileWeapon_Base_C, ShellCasingComponent) == 0x000450, "Member 'UITEM_ProjectileWeapon_Base_C::ShellCasingComponent' has a wrong offset!");
static_assert(offsetof(UITEM_ProjectileWeapon_Base_C, ShellMesh) == 0x000458, "Member 'UITEM_ProjectileWeapon_Base_C::ShellMesh' has a wrong offset!");
static_assert(offsetof(UITEM_ProjectileWeapon_Base_C, ShellEjectRelativeDirection) == 0x000460, "Member 'UITEM_ProjectileWeapon_Base_C::ShellEjectRelativeDirection' has a wrong offset!");
static_assert(offsetof(UITEM_ProjectileWeapon_Base_C, ShellEjectSpeed) == 0x00046C, "Member 'UITEM_ProjectileWeapon_Base_C::ShellEjectSpeed' has a wrong offset!");
static_assert(offsetof(UITEM_ProjectileWeapon_Base_C, ReloadAmmoMessage) == 0x000470, "Member 'UITEM_ProjectileWeapon_Base_C::ReloadAmmoMessage' has a wrong offset!");
static_assert(offsetof(UITEM_ProjectileWeapon_Base_C, EmptyAmmoMessage) == 0x000480, "Member 'UITEM_ProjectileWeapon_Base_C::EmptyAmmoMessage' has a wrong offset!");
static_assert(offsetof(UITEM_ProjectileWeapon_Base_C, EjectShellMessage) == 0x000490, "Member 'UITEM_ProjectileWeapon_Base_C::EjectShellMessage' has a wrong offset!");
static_assert(offsetof(UITEM_ProjectileWeapon_Base_C, SwitchToModeIndex) == 0x0004A0, "Member 'UITEM_ProjectileWeapon_Base_C::SwitchToModeIndex' has a wrong offset!");
static_assert(offsetof(UITEM_ProjectileWeapon_Base_C, ShotsFiredInBurst) == 0x0004A4, "Member 'UITEM_ProjectileWeapon_Base_C::ShotsFiredInBurst' has a wrong offset!");
static_assert(offsetof(UITEM_ProjectileWeapon_Base_C, ManualQueueDuration) == 0x0004A8, "Member 'UITEM_ProjectileWeapon_Base_C::ManualQueueDuration' has a wrong offset!");
static_assert(offsetof(UITEM_ProjectileWeapon_Base_C, AutomaticQueueDuration) == 0x0004AC, "Member 'UITEM_ProjectileWeapon_Base_C::AutomaticQueueDuration' has a wrong offset!");
static_assert(offsetof(UITEM_ProjectileWeapon_Base_C, ShouldRefillMagazine) == 0x0004B0, "Member 'UITEM_ProjectileWeapon_Base_C::ShouldRefillMagazine' has a wrong offset!");
static_assert(offsetof(UITEM_ProjectileWeapon_Base_C, HasKickback) == 0x0004B1, "Member 'UITEM_ProjectileWeapon_Base_C::HasKickback' has a wrong offset!");
static_assert(offsetof(UITEM_ProjectileWeapon_Base_C, AutoFireTimerHandle) == 0x0004B8, "Member 'UITEM_ProjectileWeapon_Base_C::AutoFireTimerHandle' has a wrong offset!");
static_assert(offsetof(UITEM_ProjectileWeapon_Base_C, AllowRefireTimerHandle) == 0x0004C0, "Member 'UITEM_ProjectileWeapon_Base_C::AllowRefireTimerHandle' has a wrong offset!");
static_assert(offsetof(UITEM_ProjectileWeapon_Base_C, ProjectileOffsetRotation) == 0x0004C8, "Member 'UITEM_ProjectileWeapon_Base_C::ProjectileOffsetRotation' has a wrong offset!");
static_assert(offsetof(UITEM_ProjectileWeapon_Base_C, OnMagazineChanged) == 0x0004D8, "Member 'UITEM_ProjectileWeapon_Base_C::OnMagazineChanged' has a wrong offset!");
static_assert(offsetof(UITEM_ProjectileWeapon_Base_C, ModeSwitchMessage) == 0x0004E8, "Member 'UITEM_ProjectileWeapon_Base_C::ModeSwitchMessage' has a wrong offset!");
static_assert(offsetof(UITEM_ProjectileWeapon_Base_C, CachedDischargeMontage) == 0x0004F8, "Member 'UITEM_ProjectileWeapon_Base_C::CachedDischargeMontage' has a wrong offset!");
static_assert(offsetof(UITEM_ProjectileWeapon_Base_C, CachedDischargeDryMontage) == 0x000500, "Member 'UITEM_ProjectileWeapon_Base_C::CachedDischargeDryMontage' has a wrong offset!");
static_assert(offsetof(UITEM_ProjectileWeapon_Base_C, CachedDischargeFailMontage) == 0x000508, "Member 'UITEM_ProjectileWeapon_Base_C::CachedDischargeFailMontage' has a wrong offset!");
static_assert(offsetof(UITEM_ProjectileWeapon_Base_C, CachedReloadMontage) == 0x000510, "Member 'UITEM_ProjectileWeapon_Base_C::CachedReloadMontage' has a wrong offset!");
static_assert(offsetof(UITEM_ProjectileWeapon_Base_C, CachedReloadDryMontage) == 0x000518, "Member 'UITEM_ProjectileWeapon_Base_C::CachedReloadDryMontage' has a wrong offset!");
static_assert(offsetof(UITEM_ProjectileWeapon_Base_C, CachedModeSwitchMontage) == 0x000520, "Member 'UITEM_ProjectileWeapon_Base_C::CachedModeSwitchMontage' has a wrong offset!");
static_assert(offsetof(UITEM_ProjectileWeapon_Base_C, ShellCasingCollisionSoundCue) == 0x000528, "Member 'UITEM_ProjectileWeapon_Base_C::ShellCasingCollisionSoundCue' has a wrong offset!");

}

