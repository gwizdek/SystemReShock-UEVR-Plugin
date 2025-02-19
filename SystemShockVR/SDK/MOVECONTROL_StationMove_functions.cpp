#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: MOVECONTROL_StationMove

#include "Basic.hpp"

#include "MOVECONTROL_StationMove_classes.hpp"
#include "MOVECONTROL_StationMove_parameters.hpp"


namespace SDK
{

// Function MOVECONTROL_StationMove.MOVECONTROL_StationMove_C.InitializeMoveControl
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// class APAWN_Hacker_Simple_C*            Player_0                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// float                                   GameTime                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FSTRUCT_MoveControlParams        InitialControlParams                                   (BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UMOVECONTROL_StationMove_C::InitializeMoveControl(class APAWN_Hacker_Simple_C* Player_0, float GameTime, const struct FSTRUCT_MoveControlParams& InitialControlParams, bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("MOVECONTROL_StationMove_C", "InitializeMoveControl");

	Params::MOVECONTROL_StationMove_C_InitializeMoveControl Parms{};

	Parms.Player_0 = Player_0;
	Parms.GameTime = GameTime;
	Parms.InitialControlParams = std::move(InitialControlParams);

	UObject::ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function MOVECONTROL_StationMove.MOVECONTROL_StationMove_C.UpdateMoveControl
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FVector2D                        MoveInput                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FVector2D                        LookInput                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FSTRUCT_MoveControlParams        ControlParams                                          (BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// TArray<float>                           ActionInputValues                                      (BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
// float                                   MoveInputScale                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// float                                   Delta_Time                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    ShouldExpire                                           (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UMOVECONTROL_StationMove_C::UpdateMoveControl(const struct FVector2D& MoveInput, const struct FVector2D& LookInput, const struct FSTRUCT_MoveControlParams& ControlParams, TArray<float>& ActionInputValues, float MoveInputScale, float Delta_Time, bool* ShouldExpire)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("MOVECONTROL_StationMove_C", "UpdateMoveControl");

	Params::MOVECONTROL_StationMove_C_UpdateMoveControl Parms{};

	Parms.MoveInput = std::move(MoveInput);
	Parms.LookInput = std::move(LookInput);
	Parms.ControlParams = std::move(ControlParams);
	Parms.ActionInputValues = std::move(ActionInputValues);
	Parms.MoveInputScale = MoveInputScale;
	Parms.Delta_Time = Delta_Time;

	UObject::ProcessEvent(Func, &Parms);

	ActionInputValues = std::move(Parms.ActionInputValues);

	if (ShouldExpire != nullptr)
		*ShouldExpire = Parms.ShouldExpire;
}


// Function MOVECONTROL_StationMove.MOVECONTROL_StationMove_C.ExpireStationMovement
// (Public, BlueprintCallable, BlueprintEvent)

void UMOVECONTROL_StationMove_C::ExpireStationMovement()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("MOVECONTROL_StationMove_C", "ExpireStationMovement");

	UObject::ProcessEvent(Func, nullptr);
}


// Function MOVECONTROL_StationMove.MOVECONTROL_StationMove_C.ExpireMoveControl
// (Public, BlueprintCallable, BlueprintEvent)

void UMOVECONTROL_StationMove_C::ExpireMoveControl()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("MOVECONTROL_StationMove_C", "ExpireMoveControl");

	UObject::ProcessEvent(Func, nullptr);
}

}

