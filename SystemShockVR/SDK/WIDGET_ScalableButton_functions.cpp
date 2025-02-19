#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: WIDGET_ScalableButton

#include "Basic.hpp"

#include "WIDGET_ScalableButton_classes.hpp"
#include "WIDGET_ScalableButton_parameters.hpp"


namespace SDK
{

// Function WIDGET_ScalableButton.WIDGET_ScalableButton_C.OnMouseButtonActivated__DelegateSignature
// (Public, Delegate, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FGeometry                        MyGeometry                                             (BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData, NoDestructor)
// struct FPointerEvent                    MouseEvent                                             (BlueprintVisible, BlueprintReadOnly, Parm)

void UWIDGET_ScalableButton_C::OnMouseButtonActivated__DelegateSignature(const struct FGeometry& MyGeometry, const struct FPointerEvent& MouseEvent)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_ScalableButton_C", "OnMouseButtonActivated__DelegateSignature");

	Params::WIDGET_ScalableButton_C_OnMouseButtonActivated__DelegateSignature Parms{};

	Parms.MyGeometry = std::move(MyGeometry);
	Parms.MouseEvent = std::move(MouseEvent);

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_ScalableButton.WIDGET_ScalableButton_C.ExecuteUbergraph_WIDGET_ScalableButton
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWIDGET_ScalableButton_C::ExecuteUbergraph_WIDGET_ScalableButton(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_ScalableButton_C", "ExecuteUbergraph_WIDGET_ScalableButton");

	Params::WIDGET_ScalableButton_C_ExecuteUbergraph_WIDGET_ScalableButton Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_ScalableButton.WIDGET_ScalableButton_C.PreConstruct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)
// Parameters:
// bool                                    IsDesignTime                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWIDGET_ScalableButton_C::PreConstruct(bool IsDesignTime)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_ScalableButton_C", "PreConstruct");

	Params::WIDGET_ScalableButton_C_PreConstruct Parms{};

	Parms.IsDesignTime = IsDesignTime;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_ScalableButton.WIDGET_ScalableButton_C.EVENT_OnMouseButtonDown
// (Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FGeometry                        MyGeometry                                             (BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData, NoDestructor)
// struct FPointerEvent                    MouseEvent                                             (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
// struct FEventReply                      ReturnValue                                            (Parm, OutParm, ReturnParm)

struct FEventReply UWIDGET_ScalableButton_C::EVENT_OnMouseButtonDown(const struct FGeometry& MyGeometry, const struct FPointerEvent& MouseEvent)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_ScalableButton_C", "EVENT_OnMouseButtonDown");

	Params::WIDGET_ScalableButton_C_EVENT_OnMouseButtonDown Parms{};

	Parms.MyGeometry = std::move(MyGeometry);
	Parms.MouseEvent = std::move(MouseEvent);

	UObject::ProcessEvent(Func, &Parms);

	return Parms.ReturnValue;
}


// Function WIDGET_ScalableButton.WIDGET_ScalableButton_C.EVENT_OnMouseButtonUp
// (Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FGeometry                        MyGeometry                                             (BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData, NoDestructor)
// struct FPointerEvent                    MouseEvent                                             (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
// struct FEventReply                      ReturnValue                                            (Parm, OutParm, ReturnParm)

struct FEventReply UWIDGET_ScalableButton_C::EVENT_OnMouseButtonUp(const struct FGeometry& MyGeometry, const struct FPointerEvent& MouseEvent)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_ScalableButton_C", "EVENT_OnMouseButtonUp");

	Params::WIDGET_ScalableButton_C_EVENT_OnMouseButtonUp Parms{};

	Parms.MyGeometry = std::move(MyGeometry);
	Parms.MouseEvent = std::move(MouseEvent);

	UObject::ProcessEvent(Func, &Parms);

	return Parms.ReturnValue;
}


// Function WIDGET_ScalableButton.WIDGET_ScalableButton_C.EVENT_OnMouseEnter
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FGeometry                        MyGeometry                                             (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm, IsPlainOldData, NoDestructor)
// struct FPointerEvent                    MouseEvent                                             (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)

void UWIDGET_ScalableButton_C::EVENT_OnMouseEnter(const struct FGeometry& MyGeometry, const struct FPointerEvent& MouseEvent)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_ScalableButton_C", "EVENT_OnMouseEnter");

	Params::WIDGET_ScalableButton_C_EVENT_OnMouseEnter Parms{};

	Parms.MyGeometry = std::move(MyGeometry);
	Parms.MouseEvent = std::move(MouseEvent);

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_ScalableButton.WIDGET_ScalableButton_C.EVENT_OnMouseLeave
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FPointerEvent                    MouseEvent                                             (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)

void UWIDGET_ScalableButton_C::EVENT_OnMouseLeave(const struct FPointerEvent& MouseEvent)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_ScalableButton_C", "EVENT_OnMouseLeave");

	Params::WIDGET_ScalableButton_C_EVENT_OnMouseLeave Parms{};

	Parms.MouseEvent = std::move(MouseEvent);

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_ScalableButton.WIDGET_ScalableButton_C.SetButtonEnabled
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Enabled                                                (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWIDGET_ScalableButton_C::SetButtonEnabled(bool Enabled)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_ScalableButton_C", "SetButtonEnabled");

	Params::WIDGET_ScalableButton_C_SetButtonEnabled Parms{};

	Parms.Enabled = Enabled;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_ScalableButton.WIDGET_ScalableButton_C.ResetButton
// (Public, BlueprintCallable, BlueprintEvent)

void UWIDGET_ScalableButton_C::ResetButton()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_ScalableButton_C", "ResetButton");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WIDGET_ScalableButton.WIDGET_ScalableButton_C.EVENT_OnActivationFinished
// (Public, BlueprintCallable, BlueprintEvent)

void UWIDGET_ScalableButton_C::EVENT_OnActivationFinished()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_ScalableButton_C", "EVENT_OnActivationFinished");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WIDGET_ScalableButton.WIDGET_ScalableButton_C.OnEnabledStateChanged
// (Public, BlueprintCallable, BlueprintEvent)

void UWIDGET_ScalableButton_C::OnEnabledStateChanged()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_ScalableButton_C", "OnEnabledStateChanged");

	UObject::ProcessEvent(Func, nullptr);
}


// Function WIDGET_ScalableButton.WIDGET_ScalableButton_C.SetCaption
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// class FText                             Caption_0                                              (BlueprintVisible, BlueprintReadOnly, Parm)

void UWIDGET_ScalableButton_C::SetCaption(const class FText& Caption_0)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_ScalableButton_C", "SetCaption");

	Params::WIDGET_ScalableButton_C_SetCaption Parms{};

	Parms.Caption_0 = std::move(Caption_0);

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_ScalableButton.WIDGET_ScalableButton_C.GetButtonEnabled
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// bool                                    IsEnabled                                              (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWIDGET_ScalableButton_C::GetButtonEnabled(bool* IsEnabled)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_ScalableButton_C", "GetButtonEnabled");

	Params::WIDGET_ScalableButton_C_GetButtonEnabled Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (IsEnabled != nullptr)
		*IsEnabled = Parms.IsEnabled;
}

}

