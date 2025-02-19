#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: HARDWARE_SystemAnalyzer

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "ITEM_HardwareBase_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass HARDWARE_SystemAnalyzer.HARDWARE_SystemAnalyzer_C
// 0x0008 (0x0288 - 0x0280)
class UHARDWARE_SystemAnalyzer_C final : public UITEM_HardwareBase_C
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame_HARDWARE_SystemAnalyzer_C;          // 0x0280(0x0008)(ZeroConstructor, Transient, DuplicateTransient)

public:
	void ExecuteUbergraph_HARDWARE_SystemAnalyzer(int32 EntryPoint);
	void OnQuestNotification(class FName QuestName, const class FText& NotificationText, float NotificationDelay);
	void ListenForQuestNotifications();
	void OnAddedToInventory();
	void OnBeginPlay();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"HARDWARE_SystemAnalyzer_C">();
	}
	static class UHARDWARE_SystemAnalyzer_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UHARDWARE_SystemAnalyzer_C>();
	}
};
static_assert(alignof(UHARDWARE_SystemAnalyzer_C) == 0x000008, "Wrong alignment on UHARDWARE_SystemAnalyzer_C");
static_assert(sizeof(UHARDWARE_SystemAnalyzer_C) == 0x000288, "Wrong size on UHARDWARE_SystemAnalyzer_C");
static_assert(offsetof(UHARDWARE_SystemAnalyzer_C, UberGraphFrame_HARDWARE_SystemAnalyzer_C) == 0x000280, "Member 'UHARDWARE_SystemAnalyzer_C::UberGraphFrame_HARDWARE_SystemAnalyzer_C' has a wrong offset!");

}

