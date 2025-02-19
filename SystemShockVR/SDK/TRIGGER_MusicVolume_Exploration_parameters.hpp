#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: TRIGGER_MusicVolume_Exploration

#include "Basic.hpp"


namespace SDK::Params
{

// Function TRIGGER_MusicVolume_Exploration.TRIGGER_MusicVolume_Exploration_C.OnEnterVolume
// 0x0018 (0x0018 - 0x0000)
struct TRIGGER_MusicVolume_Exploration_C_OnEnterVolume final
{
public:
	class UGI_SinglePlayer_C*                     GameInstance;                                      // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UGI_SinglePlayer_C*                     OutGameInstance;                                   // 0x0008(0x0008)(Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UGI_SinglePlayer_C*                     CallFunc_OnEnterVolume_OutGameInstance;            // 0x0010(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(TRIGGER_MusicVolume_Exploration_C_OnEnterVolume) == 0x000008, "Wrong alignment on TRIGGER_MusicVolume_Exploration_C_OnEnterVolume");
static_assert(sizeof(TRIGGER_MusicVolume_Exploration_C_OnEnterVolume) == 0x000018, "Wrong size on TRIGGER_MusicVolume_Exploration_C_OnEnterVolume");
static_assert(offsetof(TRIGGER_MusicVolume_Exploration_C_OnEnterVolume, GameInstance) == 0x000000, "Member 'TRIGGER_MusicVolume_Exploration_C_OnEnterVolume::GameInstance' has a wrong offset!");
static_assert(offsetof(TRIGGER_MusicVolume_Exploration_C_OnEnterVolume, OutGameInstance) == 0x000008, "Member 'TRIGGER_MusicVolume_Exploration_C_OnEnterVolume::OutGameInstance' has a wrong offset!");
static_assert(offsetof(TRIGGER_MusicVolume_Exploration_C_OnEnterVolume, CallFunc_OnEnterVolume_OutGameInstance) == 0x000010, "Member 'TRIGGER_MusicVolume_Exploration_C_OnEnterVolume::CallFunc_OnEnterVolume_OutGameInstance' has a wrong offset!");

}

