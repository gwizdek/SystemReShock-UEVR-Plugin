#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: WIDGET_SaveLoadMenu

#include "Basic.hpp"

#include "WIDGET_SaveLoadMenu_classes.hpp"
#include "WIDGET_SaveLoadMenu_parameters.hpp"


namespace SDK
{

// Function WIDGET_SaveLoadMenu.WIDGET_SaveLoadMenu_C.ExecuteUbergraph_WIDGET_SaveLoadMenu
// (Final, UbergraphFunction, HasDefaults)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWIDGET_SaveLoadMenu_C::ExecuteUbergraph_WIDGET_SaveLoadMenu(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_SaveLoadMenu_C", "ExecuteUbergraph_WIDGET_SaveLoadMenu");

	Params::WIDGET_SaveLoadMenu_C_ExecuteUbergraph_WIDGET_SaveLoadMenu Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_SaveLoadMenu.WIDGET_SaveLoadMenu_C.BndEvt__WIDGET_SaveLoadMenu_WIDGET_ButtonLegend_Button_3_K2Node_ComponentBoundEvent_3_OnClicked__DelegateSignature
// (BlueprintEvent)
// Parameters:
// struct FGeometry                        Geometry                                               (BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData, NoDestructor)
// struct FPointerEvent                    InputEvent                                             (BlueprintVisible, BlueprintReadOnly, Parm)

void UWIDGET_SaveLoadMenu_C::BndEvt__WIDGET_SaveLoadMenu_WIDGET_ButtonLegend_Button_3_K2Node_ComponentBoundEvent_3_OnClicked__DelegateSignature(const struct FGeometry& Geometry, const struct FPointerEvent& InputEvent)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_SaveLoadMenu_C", "BndEvt__WIDGET_SaveLoadMenu_WIDGET_ButtonLegend_Button_3_K2Node_ComponentBoundEvent_3_OnClicked__DelegateSignature");

	Params::WIDGET_SaveLoadMenu_C_BndEvt__WIDGET_SaveLoadMenu_WIDGET_ButtonLegend_Button_3_K2Node_ComponentBoundEvent_3_OnClicked__DelegateSignature Parms{};

	Parms.Geometry = std::move(Geometry);
	Parms.InputEvent = std::move(InputEvent);

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_SaveLoadMenu.WIDGET_SaveLoadMenu_C.BndEvt__WIDGET_SaveLoadMenu_WIDGET_ButtonLegend_Button_K2Node_ComponentBoundEvent_0_OnClicked__DelegateSignature
// (BlueprintEvent)
// Parameters:
// struct FGeometry                        Geometry                                               (BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData, NoDestructor)
// struct FPointerEvent                    InputEvent                                             (BlueprintVisible, BlueprintReadOnly, Parm)

void UWIDGET_SaveLoadMenu_C::BndEvt__WIDGET_SaveLoadMenu_WIDGET_ButtonLegend_Button_K2Node_ComponentBoundEvent_0_OnClicked__DelegateSignature(const struct FGeometry& Geometry, const struct FPointerEvent& InputEvent)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_SaveLoadMenu_C", "BndEvt__WIDGET_SaveLoadMenu_WIDGET_ButtonLegend_Button_K2Node_ComponentBoundEvent_0_OnClicked__DelegateSignature");

	Params::WIDGET_SaveLoadMenu_C_BndEvt__WIDGET_SaveLoadMenu_WIDGET_ButtonLegend_Button_K2Node_ComponentBoundEvent_0_OnClicked__DelegateSignature Parms{};

	Parms.Geometry = std::move(Geometry);
	Parms.InputEvent = std::move(InputEvent);

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_SaveLoadMenu.WIDGET_SaveLoadMenu_C.SetSaveLoadMenuVisibility
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    NewVisibility                                          (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
// ENUM_SaveLoad                           Mode_0                                                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// int32                                   UserIndex_0                                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWIDGET_SaveLoadMenu_C::SetSaveLoadMenuVisibility(bool NewVisibility, ENUM_SaveLoad Mode_0, int32 UserIndex_0)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_SaveLoadMenu_C", "SetSaveLoadMenuVisibility");

	Params::WIDGET_SaveLoadMenu_C_SetSaveLoadMenuVisibility Parms{};

	Parms.NewVisibility = NewVisibility;
	Parms.Mode_0 = Mode_0;
	Parms.UserIndex_0 = UserIndex_0;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_SaveLoadMenu.WIDGET_SaveLoadMenu_C.RefreshSaveRows
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)

void UWIDGET_SaveLoadMenu_C::RefreshSaveRows()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_SaveLoadMenu_C", "RefreshSaveRows");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WIDGET_SaveLoadMenu.WIDGET_SaveLoadMenu_C.CreateNewSave
// (Public, BlueprintCallable, BlueprintEvent)

void UWIDGET_SaveLoadMenu_C::CreateNewSave()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_SaveLoadMenu_C", "CreateNewSave");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WIDGET_SaveLoadMenu.WIDGET_SaveLoadMenu_C.SetMainMenu
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UWidget*                          MainMenu_0                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWIDGET_SaveLoadMenu_C::SetMainMenu(class UWidget* MainMenu_0)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_SaveLoadMenu_C", "SetMainMenu");

	Params::WIDGET_SaveLoadMenu_C_SetMainMenu Parms{};

	Parms.MainMenu_0 = MainMenu_0;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_SaveLoadMenu.WIDGET_SaveLoadMenu_C.TriggerNavUp
// (Private, BlueprintCallable, BlueprintEvent)

void UWIDGET_SaveLoadMenu_C::TriggerNavUp()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_SaveLoadMenu_C", "TriggerNavUp");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WIDGET_SaveLoadMenu.WIDGET_SaveLoadMenu_C.TriggerNavDown
// (Private, BlueprintCallable, BlueprintEvent)

void UWIDGET_SaveLoadMenu_C::TriggerNavDown()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_SaveLoadMenu_C", "TriggerNavDown");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WIDGET_SaveLoadMenu.WIDGET_SaveLoadMenu_C.TriggerNavAccept
// (Private, BlueprintCallable, BlueprintEvent)

void UWIDGET_SaveLoadMenu_C::TriggerNavAccept()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_SaveLoadMenu_C", "TriggerNavAccept");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WIDGET_SaveLoadMenu.WIDGET_SaveLoadMenu_C.TriggerNavBack
// (Private, BlueprintCallable, BlueprintEvent)

void UWIDGET_SaveLoadMenu_C::TriggerNavBack()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_SaveLoadMenu_C", "TriggerNavBack");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WIDGET_SaveLoadMenu.WIDGET_SaveLoadMenu_C.TriggerNavAlt1
// (Private, BlueprintCallable, BlueprintEvent)

void UWIDGET_SaveLoadMenu_C::TriggerNavAlt1()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_SaveLoadMenu_C", "TriggerNavAlt1");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WIDGET_SaveLoadMenu.WIDGET_SaveLoadMenu_C.TriggerNavAlt2
// (Private, BlueprintCallable, BlueprintEvent)

void UWIDGET_SaveLoadMenu_C::TriggerNavAlt2()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_SaveLoadMenu_C", "TriggerNavAlt2");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WIDGET_SaveLoadMenu.WIDGET_SaveLoadMenu_C.SetSelectedItem
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// int32                                   Index_0                                                (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWIDGET_SaveLoadMenu_C::SetSelectedItem(int32 Index_0)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_SaveLoadMenu_C", "SetSelectedItem");

	Params::WIDGET_SaveLoadMenu_C_SetSelectedItem Parms{};

	Parms.Index_0 = Index_0;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_SaveLoadMenu.WIDGET_SaveLoadMenu_C.EVENT_OnGameSessionSaved
// (Private, BlueprintCallable, BlueprintEvent)
// Parameters:
// class FString                           SaveName                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, HasGetValueTypeHash)
// int32                                   UserIndex_0                                            (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    bSuccess                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWIDGET_SaveLoadMenu_C::EVENT_OnGameSessionSaved(const class FString& SaveName, const int32 UserIndex_0, bool bSuccess)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_SaveLoadMenu_C", "EVENT_OnGameSessionSaved");

	Params::WIDGET_SaveLoadMenu_C_EVENT_OnGameSessionSaved Parms{};

	Parms.SaveName = std::move(SaveName);
	Parms.UserIndex_0 = UserIndex_0;
	Parms.bSuccess = bSuccess;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_SaveLoadMenu.WIDGET_SaveLoadMenu_C.InvokeNavManager
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// ENUM_MenuNavigationInput                InputType                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    InputState                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWIDGET_SaveLoadMenu_C::InvokeNavManager(ENUM_MenuNavigationInput InputType, bool InputState)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_SaveLoadMenu_C", "InvokeNavManager");

	Params::WIDGET_SaveLoadMenu_C_InvokeNavManager Parms{};

	Parms.InputType = InputType;
	Parms.InputState = InputState;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_SaveLoadMenu.WIDGET_SaveLoadMenu_C.GetMenuLabel
// (Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// class FText                             Page                                                   (Parm, OutParm)

void UWIDGET_SaveLoadMenu_C::GetMenuLabel(class FText* Page)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_SaveLoadMenu_C", "GetMenuLabel");

	Params::WIDGET_SaveLoadMenu_C_GetMenuLabel Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Page != nullptr)
		*Page = std::move(Parms.Page);
}

}

