#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BulletProjectile_Diego_v1_PlasmaRifle_EnergyBolt

#include "Basic.hpp"

#include "BulletProjectile_Diego_v1_PlasmaRifle_EnergyBolt_classes.hpp"
#include "BulletProjectile_Diego_v1_PlasmaRifle_EnergyBolt_parameters.hpp"


namespace SDK
{

// Function BulletProjectile_Diego_v1_PlasmaRifle_EnergyBolt.BulletProjectile_Diego_v1_PlasmaRifle_EnergyBolt_C.ExecuteUbergraph_BulletProjectile_Diego_v1_PlasmaRifle_EnergyBolt
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void ABulletProjectile_Diego_v1_PlasmaRifle_EnergyBolt_C::ExecuteUbergraph_BulletProjectile_Diego_v1_PlasmaRifle_EnergyBolt(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BulletProjectile_Diego_v1_PlasmaRifle_EnergyBolt_C", "ExecuteUbergraph_BulletProjectile_Diego_v1_PlasmaRifle_EnergyBolt");

	Params::BulletProjectile_Diego_v1_PlasmaRifle_EnergyBolt_C_ExecuteUbergraph_BulletProjectile_Diego_v1_PlasmaRifle_EnergyBolt Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function BulletProjectile_Diego_v1_PlasmaRifle_EnergyBolt.BulletProjectile_Diego_v1_PlasmaRifle_EnergyBolt_C.ReceiveBeginPlay
// (Event, Protected, BlueprintEvent)

void ABulletProjectile_Diego_v1_PlasmaRifle_EnergyBolt_C::ReceiveBeginPlay()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BulletProjectile_Diego_v1_PlasmaRifle_EnergyBolt_C", "ReceiveBeginPlay");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BulletProjectile_Diego_v1_PlasmaRifle_EnergyBolt.BulletProjectile_Diego_v1_PlasmaRifle_EnergyBolt_C.TryBulletCollision
// (Protected, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FHitResult                       Hit                                                    (BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData, NoDestructor, ContainsInstancedReference)
// float                                   FrameHitDeltaTime                                      (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void ABulletProjectile_Diego_v1_PlasmaRifle_EnergyBolt_C::TryBulletCollision(const struct FHitResult& Hit, float FrameHitDeltaTime, bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BulletProjectile_Diego_v1_PlasmaRifle_EnergyBolt_C", "TryBulletCollision");

	Params::BulletProjectile_Diego_v1_PlasmaRifle_EnergyBolt_C_TryBulletCollision Parms{};

	Parms.Hit = std::move(Hit);
	Parms.FrameHitDeltaTime = FrameHitDeltaTime;

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}

}

