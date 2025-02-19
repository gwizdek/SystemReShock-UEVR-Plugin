#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: WIDGET_OptionsMenu_Interface

#include "Basic.hpp"

#include "WIDGET_OptionsMenu_Interface_classes.hpp"
#include "WIDGET_OptionsMenu_Interface_parameters.hpp"


namespace SDK
{

// Function WIDGET_OptionsMenu_Interface.WIDGET_OptionsMenu_Interface_C.InitializeMenu
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UWIDGET_MenuBase_C*               ParentMenuWidget                                       (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWIDGET_OptionsMenu_Interface_C::InitializeMenu(class UWIDGET_MenuBase_C* ParentMenuWidget)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_OptionsMenu_Interface_C", "InitializeMenu");

	Params::WIDGET_OptionsMenu_Interface_C_InitializeMenu Parms{};

	Parms.ParentMenuWidget = ParentMenuWidget;

	UObject::ProcessEvent(Func, &Parms);
}

}

