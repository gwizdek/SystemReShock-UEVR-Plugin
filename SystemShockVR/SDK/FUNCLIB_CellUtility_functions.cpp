#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: FUNCLIB_CellUtility

#include "Basic.hpp"

#include "FUNCLIB_CellUtility_classes.hpp"
#include "FUNCLIB_CellUtility_parameters.hpp"


namespace SDK
{

// Function FUNCLIB_CellUtility.FUNCLIB_CellUtility_C.GetReverseCardinal
// (Static, Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// ENUM_CardinalDirection                  Input                                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class UObject*                          __WorldContext                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// ENUM_CardinalDirection                  Output                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UFUNCLIB_CellUtility_C::GetReverseCardinal(ENUM_CardinalDirection Input, class UObject* __WorldContext, ENUM_CardinalDirection* Output)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = StaticClass()->GetFunction("FUNCLIB_CellUtility_C", "GetReverseCardinal");

	Params::FUNCLIB_CellUtility_C_GetReverseCardinal Parms{};

	Parms.Input = Input;
	Parms.__WorldContext = __WorldContext;

	GetDefaultObj()->ProcessEvent(Func, &Parms);

	if (Output != nullptr)
		*Output = Parms.Output;
}


// Function FUNCLIB_CellUtility.FUNCLIB_CellUtility_C.GetNeighborCell
// (Static, Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// struct FIntPoint                        SourceCell                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// ENUM_CardinalDirection                  Direction                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class UObject*                          __WorldContext                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FIntPoint                        NeighborCell                                           (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UFUNCLIB_CellUtility_C::GetNeighborCell(const struct FIntPoint& SourceCell, ENUM_CardinalDirection Direction, class UObject* __WorldContext, struct FIntPoint* NeighborCell)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = StaticClass()->GetFunction("FUNCLIB_CellUtility_C", "GetNeighborCell");

	Params::FUNCLIB_CellUtility_C_GetNeighborCell Parms{};

	Parms.SourceCell = std::move(SourceCell);
	Parms.Direction = Direction;
	Parms.__WorldContext = __WorldContext;

	GetDefaultObj()->ProcessEvent(Func, &Parms);

	if (NeighborCell != nullptr)
		*NeighborCell = std::move(Parms.NeighborCell);
}


// Function FUNCLIB_CellUtility.FUNCLIB_CellUtility_C.GetCardinalDirectionFromVector
// (Static, Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// struct FVector                          InputVector                                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class UObject*                          __WorldContext                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// ENUM_CardinalDirection                  Direction                                              (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UFUNCLIB_CellUtility_C::GetCardinalDirectionFromVector(const struct FVector& InputVector, class UObject* __WorldContext, ENUM_CardinalDirection* Direction)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = StaticClass()->GetFunction("FUNCLIB_CellUtility_C", "GetCardinalDirectionFromVector");

	Params::FUNCLIB_CellUtility_C_GetCardinalDirectionFromVector Parms{};

	Parms.InputVector = std::move(InputVector);
	Parms.__WorldContext = __WorldContext;

	GetDefaultObj()->ProcessEvent(Func, &Parms);

	if (Direction != nullptr)
		*Direction = Parms.Direction;
}


// Function FUNCLIB_CellUtility.FUNCLIB_CellUtility_C.GetDescendingCostInsertionIndex
// (Static, Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// TArray<struct FSTRUCT_CellCostNode>     DescendingCostNodes                                    (BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
// float                                   Cost                                                   (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class UObject*                          __WorldContext                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// int32                                   InsertionIndex                                         (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UFUNCLIB_CellUtility_C::GetDescendingCostInsertionIndex(TArray<struct FSTRUCT_CellCostNode>& DescendingCostNodes, float Cost, class UObject* __WorldContext, int32* InsertionIndex)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = StaticClass()->GetFunction("FUNCLIB_CellUtility_C", "GetDescendingCostInsertionIndex");

	Params::FUNCLIB_CellUtility_C_GetDescendingCostInsertionIndex Parms{};

	Parms.DescendingCostNodes = std::move(DescendingCostNodes);
	Parms.Cost = Cost;
	Parms.__WorldContext = __WorldContext;

	GetDefaultObj()->ProcessEvent(Func, &Parms);

	DescendingCostNodes = std::move(Parms.DescendingCostNodes);

	if (InsertionIndex != nullptr)
		*InsertionIndex = Parms.InsertionIndex;
}


// Function FUNCLIB_CellUtility.FUNCLIB_CellUtility_C.GetEuclideanDistanceBetweenCells
// (Static, Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// struct FSTRUCT_CellLocationData         CellDataA                                              (BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FSTRUCT_CellLocationData         CellDataB                                              (BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class UObject*                          __WorldContext                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// float                                   Distance                                               (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UFUNCLIB_CellUtility_C::GetEuclideanDistanceBetweenCells(const struct FSTRUCT_CellLocationData& CellDataA, const struct FSTRUCT_CellLocationData& CellDataB, class UObject* __WorldContext, float* Distance)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = StaticClass()->GetFunction("FUNCLIB_CellUtility_C", "GetEuclideanDistanceBetweenCells");

	Params::FUNCLIB_CellUtility_C_GetEuclideanDistanceBetweenCells Parms{};

	Parms.CellDataA = std::move(CellDataA);
	Parms.CellDataB = std::move(CellDataB);
	Parms.__WorldContext = __WorldContext;

	GetDefaultObj()->ProcessEvent(Func, &Parms);

	if (Distance != nullptr)
		*Distance = Parms.Distance;
}


// Function FUNCLIB_CellUtility.FUNCLIB_CellUtility_C.GetManhattanDistanceBetweenCells
// (Static, Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// struct FSTRUCT_CellLocationData         CellDataA                                              (BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FSTRUCT_CellLocationData         CellDataB                                              (BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class UObject*                          __WorldContext                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// float                                   Distance                                               (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UFUNCLIB_CellUtility_C::GetManhattanDistanceBetweenCells(const struct FSTRUCT_CellLocationData& CellDataA, const struct FSTRUCT_CellLocationData& CellDataB, class UObject* __WorldContext, float* Distance)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = StaticClass()->GetFunction("FUNCLIB_CellUtility_C", "GetManhattanDistanceBetweenCells");

	Params::FUNCLIB_CellUtility_C_GetManhattanDistanceBetweenCells Parms{};

	Parms.CellDataA = std::move(CellDataA);
	Parms.CellDataB = std::move(CellDataB);
	Parms.__WorldContext = __WorldContext;

	GetDefaultObj()->ProcessEvent(Func, &Parms);

	if (Distance != nullptr)
		*Distance = Parms.Distance;
}


// Function FUNCLIB_CellUtility.FUNCLIB_CellUtility_C.GetCardinalDirectionFromIntPoint
// (Static, Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// struct FIntPoint                        Target                                                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class UObject*                          __WorldContext                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// ENUM_CardinalDirection                  Direction                                              (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UFUNCLIB_CellUtility_C::GetCardinalDirectionFromIntPoint(const struct FIntPoint& Target, class UObject* __WorldContext, ENUM_CardinalDirection* Direction)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = StaticClass()->GetFunction("FUNCLIB_CellUtility_C", "GetCardinalDirectionFromIntPoint");

	Params::FUNCLIB_CellUtility_C_GetCardinalDirectionFromIntPoint Parms{};

	Parms.Target = std::move(Target);
	Parms.__WorldContext = __WorldContext;

	GetDefaultObj()->ProcessEvent(Func, &Parms);

	if (Direction != nullptr)
		*Direction = Parms.Direction;
}


// Function FUNCLIB_CellUtility.FUNCLIB_CellUtility_C.GetNeighborCells
// (Static, Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// struct FIntPoint                        Source                                                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class UObject*                          __WorldContext                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// TArray<struct FIntPoint>                Neighbors                                              (Parm, OutParm)

void UFUNCLIB_CellUtility_C::GetNeighborCells(const struct FIntPoint& Source, class UObject* __WorldContext, TArray<struct FIntPoint>* Neighbors)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = StaticClass()->GetFunction("FUNCLIB_CellUtility_C", "GetNeighborCells");

	Params::FUNCLIB_CellUtility_C_GetNeighborCells Parms{};

	Parms.Source = std::move(Source);
	Parms.__WorldContext = __WorldContext;

	GetDefaultObj()->ProcessEvent(Func, &Parms);

	if (Neighbors != nullptr)
		*Neighbors = std::move(Parms.Neighbors);
}


// Function FUNCLIB_CellUtility.FUNCLIB_CellUtility_C.GetDirectionToCell
// (Static, Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// struct FIntPoint                        Source                                                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FIntPoint                        Target                                                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class UObject*                          __WorldContext                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// ENUM_CardinalDirection                  Direction                                              (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UFUNCLIB_CellUtility_C::GetDirectionToCell(const struct FIntPoint& Source, const struct FIntPoint& Target, class UObject* __WorldContext, ENUM_CardinalDirection* Direction)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = StaticClass()->GetFunction("FUNCLIB_CellUtility_C", "GetDirectionToCell");

	Params::FUNCLIB_CellUtility_C_GetDirectionToCell Parms{};

	Parms.Source = std::move(Source);
	Parms.Target = std::move(Target);
	Parms.__WorldContext = __WorldContext;

	GetDefaultObj()->ProcessEvent(Func, &Parms);

	if (Direction != nullptr)
		*Direction = Parms.Direction;
}


// Function FUNCLIB_CellUtility.FUNCLIB_CellUtility_C.GetVectorFromCardinalDirection
// (Static, Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// ENUM_CardinalDirection                  Direction                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class UObject*                          __WorldContext                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FVector                          Vector                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UFUNCLIB_CellUtility_C::GetVectorFromCardinalDirection(ENUM_CardinalDirection Direction, class UObject* __WorldContext, struct FVector* Vector)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = StaticClass()->GetFunction("FUNCLIB_CellUtility_C", "GetVectorFromCardinalDirection");

	Params::FUNCLIB_CellUtility_C_GetVectorFromCardinalDirection Parms{};

	Parms.Direction = Direction;
	Parms.__WorldContext = __WorldContext;

	GetDefaultObj()->ProcessEvent(Func, &Parms);

	if (Vector != nullptr)
		*Vector = std::move(Parms.Vector);
}


// Function FUNCLIB_CellUtility.FUNCLIB_CellUtility_C.GetIntPointFromCardinalDirection
// (Static, Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// ENUM_CardinalDirection                  Direction                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class UObject*                          __WorldContext                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FIntPoint                        Point                                                  (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UFUNCLIB_CellUtility_C::GetIntPointFromCardinalDirection(ENUM_CardinalDirection Direction, class UObject* __WorldContext, struct FIntPoint* Point)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = StaticClass()->GetFunction("FUNCLIB_CellUtility_C", "GetIntPointFromCardinalDirection");

	Params::FUNCLIB_CellUtility_C_GetIntPointFromCardinalDirection Parms{};

	Parms.Direction = Direction;
	Parms.__WorldContext = __WorldContext;

	GetDefaultObj()->ProcessEvent(Func, &Parms);

	if (Point != nullptr)
		*Point = std::move(Parms.Point);
}


// Function FUNCLIB_CellUtility.FUNCLIB_CellUtility_C.GetCellTangentVector
// (Static, Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// struct FVector                          Vector                                                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class UObject*                          __WorldContext                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FVector                          Tanget                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UFUNCLIB_CellUtility_C::GetCellTangentVector(const struct FVector& Vector, class UObject* __WorldContext, struct FVector* Tanget)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = StaticClass()->GetFunction("FUNCLIB_CellUtility_C", "GetCellTangentVector");

	Params::FUNCLIB_CellUtility_C_GetCellTangentVector Parms{};

	Parms.Vector = std::move(Vector);
	Parms.__WorldContext = __WorldContext;

	GetDefaultObj()->ProcessEvent(Func, &Parms);

	if (Tanget != nullptr)
		*Tanget = std::move(Parms.Tanget);
}


// Function FUNCLIB_CellUtility.FUNCLIB_CellUtility_C.GetCellWorldDirection
// (Static, Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// struct FVector                          Direction                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class UObject*                          __WorldContext                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FVector                          WorldDirection                                         (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UFUNCLIB_CellUtility_C::GetCellWorldDirection(const struct FVector& Direction, class UObject* __WorldContext, struct FVector* WorldDirection)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = StaticClass()->GetFunction("FUNCLIB_CellUtility_C", "GetCellWorldDirection");

	Params::FUNCLIB_CellUtility_C_GetCellWorldDirection Parms{};

	Parms.Direction = std::move(Direction);
	Parms.__WorldContext = __WorldContext;

	GetDefaultObj()->ProcessEvent(Func, &Parms);

	if (WorldDirection != nullptr)
		*WorldDirection = std::move(Parms.WorldDirection);
}


// Function FUNCLIB_CellUtility.FUNCLIB_CellUtility_C.GetWorldToCellDirection
// (Static, Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// struct FVector                          WorldDirection                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class UObject*                          __WorldContext                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FVector                          CellDirection                                          (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UFUNCLIB_CellUtility_C::GetWorldToCellDirection(const struct FVector& WorldDirection, class UObject* __WorldContext, struct FVector* CellDirection)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = StaticClass()->GetFunction("FUNCLIB_CellUtility_C", "GetWorldToCellDirection");

	Params::FUNCLIB_CellUtility_C_GetWorldToCellDirection Parms{};

	Parms.WorldDirection = std::move(WorldDirection);
	Parms.__WorldContext = __WorldContext;

	GetDefaultObj()->ProcessEvent(Func, &Parms);

	if (CellDirection != nullptr)
		*CellDirection = std::move(Parms.CellDirection);
}


// Function FUNCLIB_CellUtility.FUNCLIB_CellUtility_C.ExtractStraightLinePath
// (Static, Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FIntPoint                        SourceCell                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// TArray<struct FIntPoint>                PathToModify                                           (BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
// class UObject*                          __WorldContext                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// ENUM_CardinalDirection                  Direction                                              (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UFUNCLIB_CellUtility_C::ExtractStraightLinePath(const struct FIntPoint& SourceCell, TArray<struct FIntPoint>& PathToModify, class UObject* __WorldContext, ENUM_CardinalDirection* Direction)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = StaticClass()->GetFunction("FUNCLIB_CellUtility_C", "ExtractStraightLinePath");

	Params::FUNCLIB_CellUtility_C_ExtractStraightLinePath Parms{};

	Parms.SourceCell = std::move(SourceCell);
	Parms.PathToModify = std::move(PathToModify);
	Parms.__WorldContext = __WorldContext;

	GetDefaultObj()->ProcessEvent(Func, &Parms);

	PathToModify = std::move(Parms.PathToModify);

	if (Direction != nullptr)
		*Direction = Parms.Direction;
}


// Function FUNCLIB_CellUtility.FUNCLIB_CellUtility_C.IsAlignedToMoveToCell
// (Static, Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// struct FSTRUCT_CellLocationData         SourceCellData                                         (BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FIntPoint                        TargetCell                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class UObject*                          __WorldContext                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UFUNCLIB_CellUtility_C::IsAlignedToMoveToCell(const struct FSTRUCT_CellLocationData& SourceCellData, const struct FIntPoint& TargetCell, class UObject* __WorldContext, bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = StaticClass()->GetFunction("FUNCLIB_CellUtility_C", "IsAlignedToMoveToCell");

	Params::FUNCLIB_CellUtility_C_IsAlignedToMoveToCell Parms{};

	Parms.SourceCellData = std::move(SourceCellData);
	Parms.TargetCell = std::move(TargetCell);
	Parms.__WorldContext = __WorldContext;

	GetDefaultObj()->ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}


// Function FUNCLIB_CellUtility.FUNCLIB_CellUtility_C.GetPathTravelDistance
// (Static, Public, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// struct FSTRUCT_CellLocationData         SourceCellData                                         (BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// TArray<struct FIntPoint>                Path                                                   (BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
// class UObject*                          __WorldContext                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// float                                   Distance                                               (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UFUNCLIB_CellUtility_C::GetPathTravelDistance(const struct FSTRUCT_CellLocationData& SourceCellData, TArray<struct FIntPoint>& Path, class UObject* __WorldContext, float* Distance)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = StaticClass()->GetFunction("FUNCLIB_CellUtility_C", "GetPathTravelDistance");

	Params::FUNCLIB_CellUtility_C_GetPathTravelDistance Parms{};

	Parms.SourceCellData = std::move(SourceCellData);
	Parms.Path = std::move(Path);
	Parms.__WorldContext = __WorldContext;

	GetDefaultObj()->ProcessEvent(Func, &Parms);

	Path = std::move(Parms.Path);

	if (Distance != nullptr)
		*Distance = Parms.Distance;
}


// Function FUNCLIB_CellUtility.FUNCLIB_CellUtility_C.GetVectorFromCellLocationData
// (Static, Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// struct FSTRUCT_CellLocationData         CellLocation                                           (BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class UObject*                          __WorldContext                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FVector2D                        Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UFUNCLIB_CellUtility_C::GetVectorFromCellLocationData(const struct FSTRUCT_CellLocationData& CellLocation, class UObject* __WorldContext, struct FVector2D* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = StaticClass()->GetFunction("FUNCLIB_CellUtility_C", "GetVectorFromCellLocationData");

	Params::FUNCLIB_CellUtility_C_GetVectorFromCellLocationData Parms{};

	Parms.CellLocation = std::move(CellLocation);
	Parms.__WorldContext = __WorldContext;

	GetDefaultObj()->ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = std::move(Parms.Result);
}


// Function FUNCLIB_CellUtility.FUNCLIB_CellUtility_C.IsIntPointContainedInBounds
// (Static, Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// struct FIntPoint                        Point                                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FIntPoint                        BoundsMin                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FIntPoint                        BoundsMax                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    InclusiveMax                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
// class UObject*                          __WorldContext                                         (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    Result                                                 (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UFUNCLIB_CellUtility_C::IsIntPointContainedInBounds(const struct FIntPoint& Point, const struct FIntPoint& BoundsMin, const struct FIntPoint& BoundsMax, bool InclusiveMax, class UObject* __WorldContext, bool* Result)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = StaticClass()->GetFunction("FUNCLIB_CellUtility_C", "IsIntPointContainedInBounds");

	Params::FUNCLIB_CellUtility_C_IsIntPointContainedInBounds Parms{};

	Parms.Point = std::move(Point);
	Parms.BoundsMin = std::move(BoundsMin);
	Parms.BoundsMax = std::move(BoundsMax);
	Parms.InclusiveMax = InclusiveMax;
	Parms.__WorldContext = __WorldContext;

	GetDefaultObj()->ProcessEvent(Func, &Parms);

	if (Result != nullptr)
		*Result = Parms.Result;
}

}

