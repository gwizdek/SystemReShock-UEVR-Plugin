#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: WEAPON_RailGun

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "ITEM_ProjectileWeapon_Base_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass WEAPON_RailGun.WEAPON_RailGun_C
// 0x0250 (0x07A0 - 0x0550)
class UWEAPON_RailGun_C final : public UITEM_ProjectileWeapon_Base_C
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame_WEAPON_RailGun_C;                   // 0x0550(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	float                                         DefaultRechargeDuration;                           // 0x0558(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         ManualRechargeDuration;                            // 0x055C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         LastRechargeRatio;                                 // 0x0560(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, SaveGame, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         LastRechargeTimestamp;                             // 0x0564(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, SaveGame, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         LastFiredTimestamp;                                // 0x0568(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         LastChargeDamageBonus;                             // 0x056C(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, SaveGame, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          IsManuallyRecharging;                              // 0x056D(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, SaveGame, IsPlainOldData, NoDestructor)
	uint8                                         Pad_56E[0x2];                                      // 0x056E(0x0002)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         MinRechargeEnergyCost;                             // 0x0570(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         MaxRechargeEnergyCost;                             // 0x0574(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         MaxRechargeDamageBonus;                            // 0x0578(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_57C[0x4];                                      // 0x057C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	struct FTimerHandle                           RechargeTimerHandle;                               // 0x0580(0x0008)(Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash)
	TSoftObjectPtr<class UAnimMontage>            RechargeStartMontage;                              // 0x0588(0x0028)(Edit, BlueprintVisible, DisableEditOnInstance, HasGetValueTypeHash)
	class UNiagaraSystem*                         CachedRechargeFX;                                  // 0x05B0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class USoundCue*                              CachedAutoRechargeStartCue;                        // 0x05B8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class USoundCue*                              CachedEjectDebrisCue;                              // 0x05C0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class USoundCue*                              CachedRechargeSingleRailStartCue;                  // 0x05C8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class USoundCue*                              CachedRechargeSingleRailStopCue;                   // 0x05D0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class USoundCue*                              CachedAutoRechargeEndCue;                          // 0x05D8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class USoundCue*                              CachedManualRechargeStartCue;                      // 0x05E0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class USoundCue*                              CachedManualRechargeLoopCue;                       // 0x05E8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UAnimMontage*                           CachedRechargeStartMontage;                        // 0x05F0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FString                                 RechargeAnimMessage;                               // 0x05F8(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, HasGetValueTypeHash)
	TSoftObjectPtr<class UAnimMontage>            RechargeStopMontage;                               // 0x0608(0x0028)(Edit, BlueprintVisible, DisableEditOnInstance, HasGetValueTypeHash)
	class UAnimSequence*                          RechargeLoopSequence;                              // 0x0630(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UAnimMontage*                           CachedRechargeStopMontage;                         // 0x0638(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FString                                 RechargeEndAnimMessage;                            // 0x0640(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, HasGetValueTypeHash)
	TSoftObjectPtr<class UNiagaraSystem>          NiagaraFX;                                         // 0x0650(0x0028)(Edit, BlueprintVisible, DisableEditOnInstance, HasGetValueTypeHash)
	class UNiagaraComponent*                      RechargeEffectsComponent;                          // 0x0678(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TSoftObjectPtr<class USoundCue>               AutoRechargeStartCue;                              // 0x0680(0x0028)(Edit, BlueprintVisible, DisableEditOnInstance, HasGetValueTypeHash)
	TSoftObjectPtr<class USoundCue>               EjectDebrisCue;                                    // 0x06A8(0x0028)(Edit, BlueprintVisible, DisableEditOnInstance, HasGetValueTypeHash)
	TSoftObjectPtr<class USoundCue>               RechargeSingleRailStartCue;                        // 0x06D0(0x0028)(Edit, BlueprintVisible, DisableEditOnInstance, HasGetValueTypeHash)
	TSoftObjectPtr<class USoundCue>               RechargeSingleRailStopCue;                         // 0x06F8(0x0028)(Edit, BlueprintVisible, DisableEditOnInstance, HasGetValueTypeHash)
	TSoftObjectPtr<class USoundCue>               AutoRechargeEndCue;                                // 0x0720(0x0028)(Edit, BlueprintVisible, DisableEditOnInstance, HasGetValueTypeHash)
	TSoftObjectPtr<class USoundCue>               ManualRechargeStartCue;                            // 0x0748(0x0028)(Edit, BlueprintVisible, DisableEditOnInstance, HasGetValueTypeHash)
	TSoftObjectPtr<class USoundCue>               ManualRechargeLoopCue;                             // 0x0770(0x0028)(Edit, BlueprintVisible, DisableEditOnInstance, HasGetValueTypeHash)
	class UAudioComponent*                        RechargeLoopAudioComponent;                        // 0x0798(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_WEAPON_RailGun(int32 EntryPoint);
	void StreamWeaponAssets();
	void StreamWeaponMontages();
	void OnLoaded_5720FE574376ACD59DD48CAE01523587(class UObject* Loaded);
	void OnLoaded_8743A92249565054FE40349F7DA41F6B(class UObject* Loaded);
	void OnLoaded_E9FE140D4F405DCA7BCD9497199571BA(class UObject* Loaded);
	void OnLoaded_4A73B99447DF07AACEF2F6A768C4B39A(class UObject* Loaded);
	void OnLoaded_01A2328B4439EFE397747EA95F5CF048(class UObject* Loaded);
	void OnLoaded_9AA6C2524D1EB4CCC75E44A27E6C9798(class UObject* Loaded);
	void OnLoaded_C6FD450A44CCB16F84FB0B9A936A06CB(class UObject* Loaded);
	void OnLoaded_93B8DF1F43B0049ED402B9B57C3A1446(class UObject* Loaded);
	void OnLoaded_D7391D554DCE817853AC78A6A6BFBB87(class UObject* Loaded);
	void OnLoaded_A4273C444AFB5C6132FEDD80D1E89B1C(class UObject* Loaded);
	void HasAmmoInMagazineOrChamber(bool* Result);
	void GetProjectileClass(class UClass** Result);
	void FireProjectile(class AActor** FiredProjectile, struct FVector* Direction);
	void EjectShell();
	void HasFullyRecharged(bool* Result);
	void OnWeaponBecameActivatable(class APAWN_SystemShockCharacter_C* Character, bool ShowImmediately);
	void GetRechargeRatio(float* Result);
	void GetCurrentRechargeRate(float* Result);
	void GetCurrentRechargeDuration(float* Result);
	void GetElapsedTimeSinceFired(float* Result);
	void GetRechargeRatioRemaining(float* Result);
	void GetElapsedTimeUntilFullyRecharged(float* Result);
	void GetCurrentChargeDamageBonus(int32* DamageBonus);
	void ForceStartRechargeTimer();
	void TryStartRechargeTimer();
	void TryStopRechargeTimer();
	void TryStartManualRecharge(bool* Result);
	void TryStopManualRecharge(bool PlayStopMontage, bool* Result);
	void ModifyRechargeDurations(float DefaultDuration, float ManualDuration);
	void UpdateLastRechargeRatio();
	void UpdateRechargeFX(bool Destroy, float RechargeRatio, bool ManualRecharge);
	void OnRechargeManually();
	void OnUpdateRecharge(bool DuringTick);
	void Deactivate(bool* Result);
	void OnBecomeUnactivatable(bool* Result);
	void CycleCurrentMode(bool Previous, bool* Result);
	void ReceiveAnimationMessage(const class FString& Message, bool* Result);
	void CanActivate(class APAWN_SystemShockCharacter_C* Character, bool* Result);
	void GetWeaponMode(int32 Index_0, struct FSTRUCT_WeaponMode* Mode);
	void OnRailgunFired();
	void PlayRailgunSoundCue(class USoundCue* SoundCue, class UAudioComponent** AudioComponent);
	void EVENT_OnUpdateRecharge();
	void ShouldAutoReload(bool* Result);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"WEAPON_RailGun_C">();
	}
	static class UWEAPON_RailGun_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UWEAPON_RailGun_C>();
	}
};
static_assert(alignof(UWEAPON_RailGun_C) == 0x000008, "Wrong alignment on UWEAPON_RailGun_C");
static_assert(sizeof(UWEAPON_RailGun_C) == 0x0007A0, "Wrong size on UWEAPON_RailGun_C");
static_assert(offsetof(UWEAPON_RailGun_C, UberGraphFrame_WEAPON_RailGun_C) == 0x000550, "Member 'UWEAPON_RailGun_C::UberGraphFrame_WEAPON_RailGun_C' has a wrong offset!");
static_assert(offsetof(UWEAPON_RailGun_C, DefaultRechargeDuration) == 0x000558, "Member 'UWEAPON_RailGun_C::DefaultRechargeDuration' has a wrong offset!");
static_assert(offsetof(UWEAPON_RailGun_C, ManualRechargeDuration) == 0x00055C, "Member 'UWEAPON_RailGun_C::ManualRechargeDuration' has a wrong offset!");
static_assert(offsetof(UWEAPON_RailGun_C, LastRechargeRatio) == 0x000560, "Member 'UWEAPON_RailGun_C::LastRechargeRatio' has a wrong offset!");
static_assert(offsetof(UWEAPON_RailGun_C, LastRechargeTimestamp) == 0x000564, "Member 'UWEAPON_RailGun_C::LastRechargeTimestamp' has a wrong offset!");
static_assert(offsetof(UWEAPON_RailGun_C, LastFiredTimestamp) == 0x000568, "Member 'UWEAPON_RailGun_C::LastFiredTimestamp' has a wrong offset!");
static_assert(offsetof(UWEAPON_RailGun_C, LastChargeDamageBonus) == 0x00056C, "Member 'UWEAPON_RailGun_C::LastChargeDamageBonus' has a wrong offset!");
static_assert(offsetof(UWEAPON_RailGun_C, IsManuallyRecharging) == 0x00056D, "Member 'UWEAPON_RailGun_C::IsManuallyRecharging' has a wrong offset!");
static_assert(offsetof(UWEAPON_RailGun_C, MinRechargeEnergyCost) == 0x000570, "Member 'UWEAPON_RailGun_C::MinRechargeEnergyCost' has a wrong offset!");
static_assert(offsetof(UWEAPON_RailGun_C, MaxRechargeEnergyCost) == 0x000574, "Member 'UWEAPON_RailGun_C::MaxRechargeEnergyCost' has a wrong offset!");
static_assert(offsetof(UWEAPON_RailGun_C, MaxRechargeDamageBonus) == 0x000578, "Member 'UWEAPON_RailGun_C::MaxRechargeDamageBonus' has a wrong offset!");
static_assert(offsetof(UWEAPON_RailGun_C, RechargeTimerHandle) == 0x000580, "Member 'UWEAPON_RailGun_C::RechargeTimerHandle' has a wrong offset!");
static_assert(offsetof(UWEAPON_RailGun_C, RechargeStartMontage) == 0x000588, "Member 'UWEAPON_RailGun_C::RechargeStartMontage' has a wrong offset!");
static_assert(offsetof(UWEAPON_RailGun_C, CachedRechargeFX) == 0x0005B0, "Member 'UWEAPON_RailGun_C::CachedRechargeFX' has a wrong offset!");
static_assert(offsetof(UWEAPON_RailGun_C, CachedAutoRechargeStartCue) == 0x0005B8, "Member 'UWEAPON_RailGun_C::CachedAutoRechargeStartCue' has a wrong offset!");
static_assert(offsetof(UWEAPON_RailGun_C, CachedEjectDebrisCue) == 0x0005C0, "Member 'UWEAPON_RailGun_C::CachedEjectDebrisCue' has a wrong offset!");
static_assert(offsetof(UWEAPON_RailGun_C, CachedRechargeSingleRailStartCue) == 0x0005C8, "Member 'UWEAPON_RailGun_C::CachedRechargeSingleRailStartCue' has a wrong offset!");
static_assert(offsetof(UWEAPON_RailGun_C, CachedRechargeSingleRailStopCue) == 0x0005D0, "Member 'UWEAPON_RailGun_C::CachedRechargeSingleRailStopCue' has a wrong offset!");
static_assert(offsetof(UWEAPON_RailGun_C, CachedAutoRechargeEndCue) == 0x0005D8, "Member 'UWEAPON_RailGun_C::CachedAutoRechargeEndCue' has a wrong offset!");
static_assert(offsetof(UWEAPON_RailGun_C, CachedManualRechargeStartCue) == 0x0005E0, "Member 'UWEAPON_RailGun_C::CachedManualRechargeStartCue' has a wrong offset!");
static_assert(offsetof(UWEAPON_RailGun_C, CachedManualRechargeLoopCue) == 0x0005E8, "Member 'UWEAPON_RailGun_C::CachedManualRechargeLoopCue' has a wrong offset!");
static_assert(offsetof(UWEAPON_RailGun_C, CachedRechargeStartMontage) == 0x0005F0, "Member 'UWEAPON_RailGun_C::CachedRechargeStartMontage' has a wrong offset!");
static_assert(offsetof(UWEAPON_RailGun_C, RechargeAnimMessage) == 0x0005F8, "Member 'UWEAPON_RailGun_C::RechargeAnimMessage' has a wrong offset!");
static_assert(offsetof(UWEAPON_RailGun_C, RechargeStopMontage) == 0x000608, "Member 'UWEAPON_RailGun_C::RechargeStopMontage' has a wrong offset!");
static_assert(offsetof(UWEAPON_RailGun_C, RechargeLoopSequence) == 0x000630, "Member 'UWEAPON_RailGun_C::RechargeLoopSequence' has a wrong offset!");
static_assert(offsetof(UWEAPON_RailGun_C, CachedRechargeStopMontage) == 0x000638, "Member 'UWEAPON_RailGun_C::CachedRechargeStopMontage' has a wrong offset!");
static_assert(offsetof(UWEAPON_RailGun_C, RechargeEndAnimMessage) == 0x000640, "Member 'UWEAPON_RailGun_C::RechargeEndAnimMessage' has a wrong offset!");
static_assert(offsetof(UWEAPON_RailGun_C, NiagaraFX) == 0x000650, "Member 'UWEAPON_RailGun_C::NiagaraFX' has a wrong offset!");
static_assert(offsetof(UWEAPON_RailGun_C, RechargeEffectsComponent) == 0x000678, "Member 'UWEAPON_RailGun_C::RechargeEffectsComponent' has a wrong offset!");
static_assert(offsetof(UWEAPON_RailGun_C, AutoRechargeStartCue) == 0x000680, "Member 'UWEAPON_RailGun_C::AutoRechargeStartCue' has a wrong offset!");
static_assert(offsetof(UWEAPON_RailGun_C, EjectDebrisCue) == 0x0006A8, "Member 'UWEAPON_RailGun_C::EjectDebrisCue' has a wrong offset!");
static_assert(offsetof(UWEAPON_RailGun_C, RechargeSingleRailStartCue) == 0x0006D0, "Member 'UWEAPON_RailGun_C::RechargeSingleRailStartCue' has a wrong offset!");
static_assert(offsetof(UWEAPON_RailGun_C, RechargeSingleRailStopCue) == 0x0006F8, "Member 'UWEAPON_RailGun_C::RechargeSingleRailStopCue' has a wrong offset!");
static_assert(offsetof(UWEAPON_RailGun_C, AutoRechargeEndCue) == 0x000720, "Member 'UWEAPON_RailGun_C::AutoRechargeEndCue' has a wrong offset!");
static_assert(offsetof(UWEAPON_RailGun_C, ManualRechargeStartCue) == 0x000748, "Member 'UWEAPON_RailGun_C::ManualRechargeStartCue' has a wrong offset!");
static_assert(offsetof(UWEAPON_RailGun_C, ManualRechargeLoopCue) == 0x000770, "Member 'UWEAPON_RailGun_C::ManualRechargeLoopCue' has a wrong offset!");
static_assert(offsetof(UWEAPON_RailGun_C, RechargeLoopAudioComponent) == 0x000798, "Member 'UWEAPON_RailGun_C::RechargeLoopAudioComponent' has a wrong offset!");

}

