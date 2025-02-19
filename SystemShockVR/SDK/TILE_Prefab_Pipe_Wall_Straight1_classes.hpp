#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: TILE_Prefab_Pipe_Wall_Straight1

#include "Basic.hpp"

#include "TILE_Prefab_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass TILE_Prefab_Pipe_Wall_Straight1.TILE_Prefab_Pipe_Wall_Straight1_C
// 0x0010 (0x0240 - 0x0230)
class ATILE_Prefab_Pipe_Wall_Straight1_C final : public ATILE_Prefab_C
{
public:
	class UPointLightComponent*                   PointLight1;                                       // 0x0230(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UPointLightComponent*                   PointLight;                                        // 0x0238(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"TILE_Prefab_Pipe_Wall_Straight1_C">();
	}
	static class ATILE_Prefab_Pipe_Wall_Straight1_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<ATILE_Prefab_Pipe_Wall_Straight1_C>();
	}
};
static_assert(alignof(ATILE_Prefab_Pipe_Wall_Straight1_C) == 0x000008, "Wrong alignment on ATILE_Prefab_Pipe_Wall_Straight1_C");
static_assert(sizeof(ATILE_Prefab_Pipe_Wall_Straight1_C) == 0x000240, "Wrong size on ATILE_Prefab_Pipe_Wall_Straight1_C");
static_assert(offsetof(ATILE_Prefab_Pipe_Wall_Straight1_C, PointLight1) == 0x000230, "Member 'ATILE_Prefab_Pipe_Wall_Straight1_C::PointLight1' has a wrong offset!");
static_assert(offsetof(ATILE_Prefab_Pipe_Wall_Straight1_C, PointLight) == 0x000238, "Member 'ATILE_Prefab_Pipe_Wall_Straight1_C::PointLight' has a wrong offset!");

}

