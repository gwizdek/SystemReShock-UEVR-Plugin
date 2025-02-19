#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PROJECTILE_Cyberspace_Base

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "BulletProjectile_Base_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass PROJECTILE_Cyberspace_Base.PROJECTILE_Cyberspace_Base_C
// 0x0078 (0x0398 - 0x0320)
class APROJECTILE_Cyberspace_Base_C : public ABulletProjectile_Base_C
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame_PROJECTILE_Cyberspace_Base_C;       // 0x0320(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UAudioComponent*                        Audio_Loop;                                        // 0x0328(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class USphereComponent*                       Sphere;                                            // 0x0330(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	float                                         ProjectileSpeedMax;                                // 0x0338(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, ExposeOnSpawn, HasGetValueTypeHash)
	float                                         InitialProjectileSpeed;                            // 0x033C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, ExposeOnSpawn, HasGetValueTypeHash)
	float                                         Acceleration;                                      // 0x0340(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         AccelerationTime;                                  // 0x0344(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TSet<class AActor*>                           IgnoreActorCollisionSet;                           // 0x0348(0x0050)(Edit, BlueprintVisible, DisableEditOnTemplate, DisableEditOnInstance)

public:
	void ExecuteUbergraph_PROJECTILE_Cyberspace_Base(int32 EntryPoint);
	void ReceiveBeginPlay();
	void ReceiveTick(float DeltaSeconds);
	void UpdateProjectileAcceleration(float DeltaTime);
	void DestroyProjectile(const struct FVector& ImpactNormal);
	void OverlapProjectile(class APROJECTILE_Cyberspace_Base_C* OtherProjectile, const struct FVector& OtherProjectileForward);
	void GetRicochetDirection(const struct FVector& SourceForward, const struct FVector& OtherForward, struct FVector* RicochetDirection);
	void TryBulletCollision(const struct FHitResult& Hit, float FrameHitDeltaTime, bool* Result);
	void CanAttribManagerBeDamaged(class UAttribManagerComponent* AttribManager, bool* Result);
	void GetIgnoreCollisionActors(TArray<class AActor*>* Result);
	void CleanupBulletProjectile();
	void TryCreateSoundDetectionEvent(const struct FVector& ImpactLocation);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"PROJECTILE_Cyberspace_Base_C">();
	}
	static class APROJECTILE_Cyberspace_Base_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<APROJECTILE_Cyberspace_Base_C>();
	}
};
static_assert(alignof(APROJECTILE_Cyberspace_Base_C) == 0x000008, "Wrong alignment on APROJECTILE_Cyberspace_Base_C");
static_assert(sizeof(APROJECTILE_Cyberspace_Base_C) == 0x000398, "Wrong size on APROJECTILE_Cyberspace_Base_C");
static_assert(offsetof(APROJECTILE_Cyberspace_Base_C, UberGraphFrame_PROJECTILE_Cyberspace_Base_C) == 0x000320, "Member 'APROJECTILE_Cyberspace_Base_C::UberGraphFrame_PROJECTILE_Cyberspace_Base_C' has a wrong offset!");
static_assert(offsetof(APROJECTILE_Cyberspace_Base_C, Audio_Loop) == 0x000328, "Member 'APROJECTILE_Cyberspace_Base_C::Audio_Loop' has a wrong offset!");
static_assert(offsetof(APROJECTILE_Cyberspace_Base_C, Sphere) == 0x000330, "Member 'APROJECTILE_Cyberspace_Base_C::Sphere' has a wrong offset!");
static_assert(offsetof(APROJECTILE_Cyberspace_Base_C, ProjectileSpeedMax) == 0x000338, "Member 'APROJECTILE_Cyberspace_Base_C::ProjectileSpeedMax' has a wrong offset!");
static_assert(offsetof(APROJECTILE_Cyberspace_Base_C, InitialProjectileSpeed) == 0x00033C, "Member 'APROJECTILE_Cyberspace_Base_C::InitialProjectileSpeed' has a wrong offset!");
static_assert(offsetof(APROJECTILE_Cyberspace_Base_C, Acceleration) == 0x000340, "Member 'APROJECTILE_Cyberspace_Base_C::Acceleration' has a wrong offset!");
static_assert(offsetof(APROJECTILE_Cyberspace_Base_C, AccelerationTime) == 0x000344, "Member 'APROJECTILE_Cyberspace_Base_C::AccelerationTime' has a wrong offset!");
static_assert(offsetof(APROJECTILE_Cyberspace_Base_C, IgnoreActorCollisionSet) == 0x000348, "Member 'APROJECTILE_Cyberspace_Base_C::IgnoreActorCollisionSet' has a wrong offset!");

}

