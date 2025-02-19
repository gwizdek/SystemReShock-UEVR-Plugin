#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: LocalBehaviorComponent

#include "Basic.hpp"

#include "ENUM_LocalBehaviorType_structs.hpp"
#include "Engine_classes.hpp"
#include "ENUM_LBC_DirectionBehavior_structs.hpp"


namespace SDK
{

// BlueprintGeneratedClass LocalBehaviorComponent.LocalBehaviorComponent_C
// 0x0040 (0x0240 - 0x0200)
#pragma pack(push, 0x1)
class alignas(0x10) ULocalBehaviorComponent_C : public USceneComponent
{
public:
	uint8                                         Pad_1F8[0x8];                                      // 0x01F8(0x0008)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         WaitTime;                                          // 0x0200(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         AcceptanceRadius;                                  // 0x0204(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TSoftObjectPtr<class UBehaviorTree>           LocalBehavior;                                     // 0x0208(0x0028)(Edit, BlueprintVisible, HasGetValueTypeHash)
	ENUM_LocalBehaviorType                        LocalBehaviorType;                                 // 0x0230(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ENUM_LBC_DirectionBehavior                    FaceDirectionType;                                 // 0x0231(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_232[0x2];                                      // 0x0232(0x0002)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         LastArrivedTimestamp;                              // 0x0234(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, SaveGame, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void HasValidBehavior(bool* Result);
	void HasFinishedWaiting(bool* Result);
	void UpdateArrivedTimestamp(bool Reset);
	void Zero_None();
	void One_Wait();
	bool ShouldSaveComponent(struct FStreamingSaveGameComponentParams* Params_0);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"LocalBehaviorComponent_C">();
	}
	static class ULocalBehaviorComponent_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<ULocalBehaviorComponent_C>();
	}
};
#pragma pack(pop)
static_assert(alignof(ULocalBehaviorComponent_C) == 0x000010, "Wrong alignment on ULocalBehaviorComponent_C");
static_assert(sizeof(ULocalBehaviorComponent_C) == 0x000240, "Wrong size on ULocalBehaviorComponent_C");
static_assert(offsetof(ULocalBehaviorComponent_C, WaitTime) == 0x000200, "Member 'ULocalBehaviorComponent_C::WaitTime' has a wrong offset!");
static_assert(offsetof(ULocalBehaviorComponent_C, AcceptanceRadius) == 0x000204, "Member 'ULocalBehaviorComponent_C::AcceptanceRadius' has a wrong offset!");
static_assert(offsetof(ULocalBehaviorComponent_C, LocalBehavior) == 0x000208, "Member 'ULocalBehaviorComponent_C::LocalBehavior' has a wrong offset!");
static_assert(offsetof(ULocalBehaviorComponent_C, LocalBehaviorType) == 0x000230, "Member 'ULocalBehaviorComponent_C::LocalBehaviorType' has a wrong offset!");
static_assert(offsetof(ULocalBehaviorComponent_C, FaceDirectionType) == 0x000231, "Member 'ULocalBehaviorComponent_C::FaceDirectionType' has a wrong offset!");
static_assert(offsetof(ULocalBehaviorComponent_C, LastArrivedTimestamp) == 0x000234, "Member 'ULocalBehaviorComponent_C::LastArrivedTimestamp' has a wrong offset!");

}

