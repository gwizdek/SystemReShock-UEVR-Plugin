#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BP_ClothesPile

#include "Basic.hpp"

#include "Engine_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass BP_ClothesPile.BP_ClothesPile_C
// 0x0010 (0x0230 - 0x0220)
class ABP_ClothesPile_C final : public AActor
{
public:
	class UCOMP_Descriptor_C*                     COMP_Descriptor;                                   // 0x0220(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UStaticMeshComponent*                   StaticMesh;                                        // 0x0228(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"BP_ClothesPile_C">();
	}
	static class ABP_ClothesPile_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<ABP_ClothesPile_C>();
	}
};
static_assert(alignof(ABP_ClothesPile_C) == 0x000008, "Wrong alignment on ABP_ClothesPile_C");
static_assert(sizeof(ABP_ClothesPile_C) == 0x000230, "Wrong size on ABP_ClothesPile_C");
static_assert(offsetof(ABP_ClothesPile_C, COMP_Descriptor) == 0x000220, "Member 'ABP_ClothesPile_C::COMP_Descriptor' has a wrong offset!");
static_assert(offsetof(ABP_ClothesPile_C, StaticMesh) == 0x000228, "Member 'ABP_ClothesPile_C::StaticMesh' has a wrong offset!");

}

