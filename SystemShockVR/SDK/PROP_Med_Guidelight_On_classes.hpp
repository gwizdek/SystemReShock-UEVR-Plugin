#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PROP_Med_Guidelight_On

#include "Basic.hpp"

#include "Engine_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass PROP_Med_Guidelight_On.PROP_Med_Guidelight_On_C
// 0x0018 (0x0238 - 0x0220)
class APROP_Med_Guidelight_On_C final : public AActor
{
public:
	class UCOMP_Descriptor_C*                     COMP_Descriptor;                                   // 0x0220(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UPointLightComponent*                   PointLight;                                        // 0x0228(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UStaticMeshComponent*                   StaticMesh;                                        // 0x0230(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"PROP_Med_Guidelight_On_C">();
	}
	static class APROP_Med_Guidelight_On_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<APROP_Med_Guidelight_On_C>();
	}
};
static_assert(alignof(APROP_Med_Guidelight_On_C) == 0x000008, "Wrong alignment on APROP_Med_Guidelight_On_C");
static_assert(sizeof(APROP_Med_Guidelight_On_C) == 0x000238, "Wrong size on APROP_Med_Guidelight_On_C");
static_assert(offsetof(APROP_Med_Guidelight_On_C, COMP_Descriptor) == 0x000220, "Member 'APROP_Med_Guidelight_On_C::COMP_Descriptor' has a wrong offset!");
static_assert(offsetof(APROP_Med_Guidelight_On_C, PointLight) == 0x000228, "Member 'APROP_Med_Guidelight_On_C::PointLight' has a wrong offset!");
static_assert(offsetof(APROP_Med_Guidelight_On_C, StaticMesh) == 0x000230, "Member 'APROP_Med_Guidelight_On_C::StaticMesh' has a wrong offset!");

}

