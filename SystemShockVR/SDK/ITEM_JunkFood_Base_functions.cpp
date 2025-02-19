#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: ITEM_JunkFood_Base

#include "Basic.hpp"

#include "ITEM_JunkFood_Base_classes.hpp"
#include "ITEM_JunkFood_Base_parameters.hpp"


namespace SDK
{

// Function ITEM_JunkFood_Base.ITEM_JunkFood_Base_C.ConsumeJunkFood
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// class APAWN_SystemShockCharacter_C*     Character                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UITEM_JunkFood_Base_C::ConsumeJunkFood(class APAWN_SystemShockCharacter_C* Character)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ITEM_JunkFood_Base_C", "ConsumeJunkFood");

	Params::ITEM_JunkFood_Base_C_ConsumeJunkFood Parms{};

	Parms.Character = Character;

	UObject::ProcessEvent(Func, &Parms);
}


// Function ITEM_JunkFood_Base.ITEM_JunkFood_Base_C.PlayConsumeSFX
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// class APAWN_SystemShockCharacter_C*     Character                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UITEM_JunkFood_Base_C::PlayConsumeSFX(class APAWN_SystemShockCharacter_C* Character)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ITEM_JunkFood_Base_C", "PlayConsumeSFX");

	Params::ITEM_JunkFood_Base_C_PlayConsumeSFX Parms{};

	Parms.Character = Character;

	UObject::ProcessEvent(Func, &Parms);
}


// Function ITEM_JunkFood_Base.ITEM_JunkFood_Base_C.Activate
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// class APAWN_SystemShockCharacter_C*     Character                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UITEM_JunkFood_Base_C::Activate(class APAWN_SystemShockCharacter_C* Character, bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ITEM_JunkFood_Base_C", "Activate");

	Params::ITEM_JunkFood_Base_C_Activate Parms{};

	Parms.Character = Character;

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function ITEM_JunkFood_Base.ITEM_JunkFood_Base_C.GetInventoryItemDetailsClass
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// class UClass*                           InventoryItemDetailsWidget                             (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UITEM_JunkFood_Base_C::GetInventoryItemDetailsClass(class UClass** InventoryItemDetailsWidget)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("ITEM_JunkFood_Base_C", "GetInventoryItemDetailsClass");

	Params::ITEM_JunkFood_Base_C_GetInventoryItemDetailsClass Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (InventoryItemDetailsWidget != nullptr)
		*InventoryItemDetailsWidget = Parms.InventoryItemDetailsWidget;
}

}

