#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: PROP_Sign

#include "Basic.hpp"

#include "CoreUObject_structs.hpp"
#include "Engine_structs.hpp"
#include "Engine_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass PROP_Sign.PROP_Sign_C
// 0x0070 (0x0290 - 0x0220)
class APROP_Sign_C : public AActor
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0220(0x0008)(ZeroConstructor, Transient, DuplicateTransient)
	class UCOMP_Descriptor_C*                     COMP_Descriptor;                                   // 0x0228(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UStaticMeshComponent*                   StaticMesh;                                        // 0x0230(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class FString                                 SignText;                                          // 0x0238(0x0010)(Edit, BlueprintVisible, ZeroConstructor, HasGetValueTypeHash)
	struct FLinearColor                           TextColor;                                         // 0x0248(0x0010)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         TextSize;                                          // 0x0258(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         Width;                                             // 0x025C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         Height;                                            // 0x0260(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_264[0x4];                                      // 0x0264(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UCanvasRenderTarget2D*                  RenderTarget;                                      // 0x0268(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UCanvas*                                Canvas;                                            // 0x0270(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FDrawToRenderTargetContext             Context;                                           // 0x0278(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor)
	bool                                          IsPowered;                                         // 0x0288(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)

public:
	void ExecuteUbergraph_PROP_Sign(int32 EntryPoint);
	void ReceiveEndPlay(EEndPlayReason EndPlayReason);
	void ReceiveBeginPlay();
	void UserConstructionScript();
	void InitializeSign();
	void UpdateSign();
	void TryCleanupSign();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"PROP_Sign_C">();
	}
	static class APROP_Sign_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<APROP_Sign_C>();
	}
};
static_assert(alignof(APROP_Sign_C) == 0x000008, "Wrong alignment on APROP_Sign_C");
static_assert(sizeof(APROP_Sign_C) == 0x000290, "Wrong size on APROP_Sign_C");
static_assert(offsetof(APROP_Sign_C, UberGraphFrame) == 0x000220, "Member 'APROP_Sign_C::UberGraphFrame' has a wrong offset!");
static_assert(offsetof(APROP_Sign_C, COMP_Descriptor) == 0x000228, "Member 'APROP_Sign_C::COMP_Descriptor' has a wrong offset!");
static_assert(offsetof(APROP_Sign_C, StaticMesh) == 0x000230, "Member 'APROP_Sign_C::StaticMesh' has a wrong offset!");
static_assert(offsetof(APROP_Sign_C, SignText) == 0x000238, "Member 'APROP_Sign_C::SignText' has a wrong offset!");
static_assert(offsetof(APROP_Sign_C, TextColor) == 0x000248, "Member 'APROP_Sign_C::TextColor' has a wrong offset!");
static_assert(offsetof(APROP_Sign_C, TextSize) == 0x000258, "Member 'APROP_Sign_C::TextSize' has a wrong offset!");
static_assert(offsetof(APROP_Sign_C, Width) == 0x00025C, "Member 'APROP_Sign_C::Width' has a wrong offset!");
static_assert(offsetof(APROP_Sign_C, Height) == 0x000260, "Member 'APROP_Sign_C::Height' has a wrong offset!");
static_assert(offsetof(APROP_Sign_C, RenderTarget) == 0x000268, "Member 'APROP_Sign_C::RenderTarget' has a wrong offset!");
static_assert(offsetof(APROP_Sign_C, Canvas) == 0x000270, "Member 'APROP_Sign_C::Canvas' has a wrong offset!");
static_assert(offsetof(APROP_Sign_C, Context) == 0x000278, "Member 'APROP_Sign_C::Context' has a wrong offset!");
static_assert(offsetof(APROP_Sign_C, IsPowered) == 0x000288, "Member 'APROP_Sign_C::IsPowered' has a wrong offset!");

}

