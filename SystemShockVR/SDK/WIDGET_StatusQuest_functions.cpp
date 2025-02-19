#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: WIDGET_StatusQuest

#include "Basic.hpp"

#include "WIDGET_StatusQuest_classes.hpp"
#include "WIDGET_StatusQuest_parameters.hpp"


namespace SDK
{

// Function WIDGET_StatusQuest.WIDGET_StatusQuest_C.ExecuteUbergraph_WIDGET_StatusQuest
// (Final, UbergraphFunction)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWIDGET_StatusQuest_C::ExecuteUbergraph_WIDGET_StatusQuest(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_StatusQuest_C", "ExecuteUbergraph_WIDGET_StatusQuest");

	Params::WIDGET_StatusQuest_C_ExecuteUbergraph_WIDGET_StatusQuest Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_StatusQuest.WIDGET_StatusQuest_C.PreConstruct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)
// Parameters:
// bool                                    IsDesignTime                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UWIDGET_StatusQuest_C::PreConstruct(bool IsDesignTime)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_StatusQuest_C", "PreConstruct");

	Params::WIDGET_StatusQuest_C_PreConstruct Parms{};

	Parms.IsDesignTime = IsDesignTime;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_StatusQuest.WIDGET_StatusQuest_C.InitializeStatusQuest
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UWIDGET_Status_C*                 Status                                                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UWIDGET_StatusQuest_C::InitializeStatusQuest(class UWIDGET_Status_C* Status)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_StatusQuest_C", "InitializeStatusQuest");

	Params::WIDGET_StatusQuest_C_InitializeStatusQuest Parms{};

	Parms.Status = Status;

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_StatusQuest.WIDGET_StatusQuest_C.SetStatusQuest
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// class FText                             QuestValue                                             (BlueprintVisible, BlueprintReadOnly, Parm)

void UWIDGET_StatusQuest_C::SetStatusQuest(const class FText& QuestValue)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_StatusQuest_C", "SetStatusQuest");

	Params::WIDGET_StatusQuest_C_SetStatusQuest Parms{};

	Parms.QuestValue = std::move(QuestValue);

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_StatusQuest.WIDGET_StatusQuest_C.EVENT_OnMouseEnter
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FGeometry                        MyGeometry                                             (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm, IsPlainOldData, NoDestructor)
// struct FPointerEvent                    MouseEvent                                             (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)

void UWIDGET_StatusQuest_C::EVENT_OnMouseEnter(const struct FGeometry& MyGeometry, const struct FPointerEvent& MouseEvent)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_StatusQuest_C", "EVENT_OnMouseEnter");

	Params::WIDGET_StatusQuest_C_EVENT_OnMouseEnter Parms{};

	Parms.MyGeometry = std::move(MyGeometry);
	Parms.MouseEvent = std::move(MouseEvent);

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_StatusQuest.WIDGET_StatusQuest_C.EVENT_OnMouseLeave
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FPointerEvent                    MouseEvent                                             (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)

void UWIDGET_StatusQuest_C::EVENT_OnMouseLeave(const struct FPointerEvent& MouseEvent)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_StatusQuest_C", "EVENT_OnMouseLeave");

	Params::WIDGET_StatusQuest_C_EVENT_OnMouseLeave Parms{};

	Parms.MouseEvent = std::move(MouseEvent);

	UObject::ProcessEvent(Func, &Parms);
}


// Function WIDGET_StatusQuest.WIDGET_StatusQuest_C.EVENT_OnMouseButtonDown
// (Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FGeometry                        MyGeometry                                             (BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData, NoDestructor)
// struct FPointerEvent                    MouseEvent                                             (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
// struct FEventReply                      ReturnValue                                            (Parm, OutParm, ReturnParm)

struct FEventReply UWIDGET_StatusQuest_C::EVENT_OnMouseButtonDown(const struct FGeometry& MyGeometry, const struct FPointerEvent& MouseEvent)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_StatusQuest_C", "EVENT_OnMouseButtonDown");

	Params::WIDGET_StatusQuest_C_EVENT_OnMouseButtonDown Parms{};

	Parms.MyGeometry = std::move(MyGeometry);
	Parms.MouseEvent = std::move(MouseEvent);

	UObject::ProcessEvent(Func, &Parms);

	return Parms.ReturnValue;
}


// Function WIDGET_StatusQuest.WIDGET_StatusQuest_C.EVENT_OnMouseMove
// (Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FGeometry                        MyGeometry                                             (BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData, NoDestructor)
// struct FPointerEvent                    MouseEvent                                             (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
// struct FEventReply                      ReturnValue                                            (Parm, OutParm, ReturnParm)

struct FEventReply UWIDGET_StatusQuest_C::EVENT_OnMouseMove(const struct FGeometry& MyGeometry, const struct FPointerEvent& MouseEvent)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_StatusQuest_C", "EVENT_OnMouseMove");

	Params::WIDGET_StatusQuest_C_EVENT_OnMouseMove Parms{};

	Parms.MyGeometry = std::move(MyGeometry);
	Parms.MouseEvent = std::move(MouseEvent);

	UObject::ProcessEvent(Func, &Parms);

	return Parms.ReturnValue;
}


// Function WIDGET_StatusQuest.WIDGET_StatusQuest_C.GetToolTipText
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// class FText                             ToolTip                                                (Parm, OutParm)

void UWIDGET_StatusQuest_C::GetToolTipText(class FText* ToolTip)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("WIDGET_StatusQuest_C", "GetToolTipText");

	Params::WIDGET_StatusQuest_C_GetToolTipText Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (ToolTip != nullptr)
		*ToolTip = std::move(Parms.ToolTip);
}

}

