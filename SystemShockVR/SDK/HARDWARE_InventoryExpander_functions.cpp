#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: HARDWARE_InventoryExpander

#include "Basic.hpp"

#include "HARDWARE_InventoryExpander_classes.hpp"
#include "HARDWARE_InventoryExpander_parameters.hpp"


namespace SDK
{

// Function HARDWARE_InventoryExpander.HARDWARE_InventoryExpander_C.ExecuteUbergraph_HARDWARE_InventoryExpander
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UHARDWARE_InventoryExpander_C::ExecuteUbergraph_HARDWARE_InventoryExpander(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("HARDWARE_InventoryExpander_C", "ExecuteUbergraph_HARDWARE_InventoryExpander");

	Params::HARDWARE_InventoryExpander_C_ExecuteUbergraph_HARDWARE_InventoryExpander Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function HARDWARE_InventoryExpander.HARDWARE_InventoryExpander_C.OnAddedToInventory
// (Public, BlueprintCallable, BlueprintEvent)

void UHARDWARE_InventoryExpander_C::OnAddedToInventory()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("HARDWARE_InventoryExpander_C", "OnAddedToInventory");

	UObject::ProcessEvent(Func, nullptr);
}


// Function HARDWARE_InventoryExpander.HARDWARE_InventoryExpander_C.ExpandMainInventory
// (Protected, BlueprintCallable, BlueprintEvent)

void UHARDWARE_InventoryExpander_C::ExpandMainInventory()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("HARDWARE_InventoryExpander_C", "ExpandMainInventory");

	UObject::ProcessEvent(Func, nullptr);
}


// Function HARDWARE_InventoryExpander.HARDWARE_InventoryExpander_C.OnUpgradedItem
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UITEM_UpgradeBase_C*              PreviousItem                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UHARDWARE_InventoryExpander_C::OnUpgradedItem(class UITEM_UpgradeBase_C* PreviousItem, bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("HARDWARE_InventoryExpander_C", "OnUpgradedItem");

	Params::HARDWARE_InventoryExpander_C_OnUpgradedItem Parms{};

	Parms.PreviousItem = PreviousItem;

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}

}

