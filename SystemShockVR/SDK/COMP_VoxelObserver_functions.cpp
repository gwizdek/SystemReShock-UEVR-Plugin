#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: COMP_VoxelObserver

#include "Basic.hpp"

#include "COMP_VoxelObserver_classes.hpp"
#include "COMP_VoxelObserver_parameters.hpp"


namespace SDK
{

// Function COMP_VoxelObserver.COMP_VoxelObserver_C.GetVoxelLevelManager
// (Event, Protected, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UVoxelLevelManager*               ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

class UVoxelLevelManager* UCOMP_VoxelObserver_C::GetVoxelLevelManager()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("COMP_VoxelObserver_C", "GetVoxelLevelManager");

	Params::COMP_VoxelObserver_C_GetVoxelLevelManager Parms{};

	UObject::ProcessEvent(Func, &Parms);

	return Parms.ReturnValue;
}

}

