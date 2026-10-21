#pragma once

#include "CoreMinimal.h"
#include "MenuGenTypes.h"

class UBlueprint;
class UEdGraph;
class UWidgetBlueprint;

// One Blueprint being generated: creation, members, compile and save.
class FMenuGenBlueprint
{
public:
    // Creates an empty Blueprint asset in a new package. bWidget selects a Widget Blueprint.
    static TSharedPtr<FMenuGenBlueprint> Create(const FString& PackagePath, UClass* Parent, bool bWidget);

    // Wraps a Blueprint that already exists on disk.
    static TSharedPtr<FMenuGenBlueprint> Load(const FString& PackagePath);

    UBlueprint* Blueprint() const { return BP; }
    UWidgetBlueprint* Widget() const;
    UClass* Class() const;

    void AddVariable(FName Name, const FEdGraphPinType& Type, bool bInstanceEditable = false, const FString& Default = FString());
    void AddDispatcher(FName Name, const TArray<FMenuGenParam>& Params);
    UEdGraph* AddFunction(FName Name, const TArray<FMenuGenParam>& Inputs, const TArray<FMenuGenParam>& Outputs, bool bPure);
    // Adds a function graph that overrides a function of the parent class.
    UEdGraph* AddOverride(FName ParentFunction);

    bool Compile(const TCHAR* Stage);
    bool Save(const TArray<int32>& ChunkIds);

private:
    explicit FMenuGenBlueprint(UBlueprint* InBP) : BP(InBP) {}

    UEdGraph* NewGraph(FName Name) const;
    static void AddParams(class UK2Node_EditablePinBase* Node, const TArray<FMenuGenParam>& Params, EEdGraphPinDirection Direction);
    static class UK2Node_FunctionEntry* EntryOf(UEdGraph* Graph);

    UBlueprint* BP = nullptr;
};
