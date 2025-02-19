#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: WIDGET_OptionsMenu_GameplayList

#include "Basic.hpp"

#include "WIDGET_OptionsMenu_GameplayList_classes.hpp"
#include "WIDGET_OptionsMenu_GameplayList_parameters.hpp"


namespace SDK
{

// Function WIDGET_OptionsMenu_GameplayList.WIDGET_OptionsMenu_GameplayList_C.InitializeItemArray
// (Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// TArray<class UWIDGET_MenuListItemBase_C*>MenuListItems                                          (Parm, OutParm, ContainsInstancedReference)

void UWIDGET_OptionsMenu_GameplayList_C::InitializeItemArray(TArray<class UWIDGET_MenuListItemBase_C*>* MenuListItems)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_OptionsMenu_GameplayList_C", "InitializeItemArray");

	Params::WIDGET_OptionsMenu_GameplayList_C_InitializeItemArray Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (MenuListItems != nullptr)
		*MenuListItems = std::move(Parms.MenuListItems);
}


// Function WIDGET_OptionsMenu_GameplayList.WIDGET_OptionsMenu_GameplayList_C.InitializeList
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UWIDGET_MenuBase_C*               ParentScreen                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWIDGET_OptionsMenu_GameplayList_C::InitializeList(class UWIDGET_MenuBase_C* ParentScreen)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_OptionsMenu_GameplayList_C", "InitializeList");

	Params::WIDGET_OptionsMenu_GameplayList_C_InitializeList Parms{};

	Parms.ParentScreen = ParentScreen;

	UObject::ProcessEvent(Func, &Parms);
}

}

