#include "MenuGenBlueprint.h"

#include "BridgeGenLog.h"
#include "Engine/Blueprint.h"
#include "Engine/BlueprintGeneratedClass.h"
#include "K2Node_FunctionEntry.h"
#include "K2Node_FunctionResult.h"
#include "Kismet2/BlueprintEditorUtils.h"
#include "Kismet2/CompilerResultsLog.h"
#include "Kismet2/KismetEditorUtilities.h"
#include "MenuGenAsset.h"
#include "WidgetBlueprint.h"
#include "Blueprint/WidgetBlueprintGeneratedClass.h"

namespace
{
// Moves an object out of its package under a unique name, so a new object can take the name.
void MoveToTransient(UObject* Object)
{
    if (Object == nullptr) return;
    Object->ClearFlags(RF_Public | RF_Standalone);
    const FName NewName = MakeUniqueObjectName(GetTransientPackage(), Object->GetClass(), Object->GetFName());
    Object->Rename(*NewName.ToString(), GetTransientPackage(), REN_DontCreateRedirectors | REN_DoNotDirty | REN_NonTransactional);
}

// With -Overwrite an old version of the asset may already be in memory, loaded as a dependency
// of something else. CreateBlueprint asserts on a name clash, so the old Blueprint and its two
// classes are moved aside first.
void EvictLoadedBlueprint(UPackage* Package, FName Name)
{
    UBlueprint* Existing = FindObject<UBlueprint>(Package, *Name.ToString());
    if (Existing == nullptr) return;
    UE_LOG(LogUEVRBridgeGen, Display, TEXT("Replacing the loaded %s"), *Existing->GetPathName());
    MoveToTransient(Existing->SkeletonGeneratedClass);
    MoveToTransient(Existing->GeneratedClass);
    MoveToTransient(Existing);
}
} // namespace

TSharedPtr<FMenuGenBlueprint> FMenuGenBlueprint::Create(const FString& PackagePath, UClass* Parent, bool bWidget)
{
    UPackage* Package = MenuGenAsset::NewPackage(PackagePath);
    const FName Name = *MenuGenAsset::NameOf(PackagePath);
    EvictLoadedBlueprint(Package, Name);
    UBlueprint* BP = bWidget
        ? FKismetEditorUtilities::CreateBlueprint(Parent, Package, Name, BPTYPE_Normal, UWidgetBlueprint::StaticClass(), UWidgetBlueprintGeneratedClass::StaticClass())
        : FKismetEditorUtilities::CreateBlueprint(Parent, Package, Name, BPTYPE_Normal, UBlueprint::StaticClass(), UBlueprintGeneratedClass::StaticClass());
    if (BP == nullptr)
    {
        UE_LOG(LogUEVRBridgeGen, Error, TEXT("Cannot create Blueprint %s with parent %s"), *PackagePath, Parent ? *Parent->GetName() : TEXT("null"));
        return nullptr;
    }
    UE_LOG(LogUEVRBridgeGen, Display, TEXT("Created %s : %s"), *PackagePath, *Parent->GetName());
    return MakeShareable(new FMenuGenBlueprint(BP));
}

TSharedPtr<FMenuGenBlueprint> FMenuGenBlueprint::Load(const FString& PackagePath)
{
    UBlueprint* BP = LoadObject<UBlueprint>(nullptr, *MenuGenAsset::ObjectPath(PackagePath));
    if (BP == nullptr || BP->GeneratedClass == nullptr)
    {
        UE_LOG(LogUEVRBridgeGen, Error, TEXT("Cannot load Blueprint %s"), *PackagePath);
        return nullptr;
    }
    UE_LOG(LogUEVRBridgeGen, Display, TEXT("Kept existing %s"), *PackagePath);
    return MakeShareable(new FMenuGenBlueprint(BP));
}

UWidgetBlueprint* FMenuGenBlueprint::Widget() const
{
    return Cast<UWidgetBlueprint>(BP);
}

UClass* FMenuGenBlueprint::Class() const
{
    return BP->GeneratedClass;
}

void FMenuGenBlueprint::AddVariable(FName Name, const FEdGraphPinType& Type, bool bInstanceEditable, const FString& Default)
{
    if (!FBlueprintEditorUtils::AddMemberVariable(BP, Name, Type, Default))
    {
        UE_LOG(LogUEVRBridgeGen, Error, TEXT("%s: cannot add variable %s"), *BP->GetName(), *Name.ToString());
        return;
    }
    if (bInstanceEditable)
    {
        FBlueprintEditorUtils::SetBlueprintOnlyEditableFlag(BP, Name, false);
    }
}

// Mirrors FBlueprintEditor::OnAddNewDelegate: a multicast delegate variable plus a signature graph.
void FMenuGenBlueprint::AddDispatcher(FName Name, const TArray<FMenuGenParam>& Params)
{
    if (!FBlueprintEditorUtils::AddMemberVariable(BP, Name, MenuGenPins::Delegate()))
    {
        UE_LOG(LogUEVRBridgeGen, Error, TEXT("%s: cannot add dispatcher %s"), *BP->GetName(), *Name.ToString());
        return;
    }
    UEdGraph* Graph = NewGraph(Name);
    Graph->bEditable = false;
    const UEdGraphSchema_K2* Schema = GetDefault<UEdGraphSchema_K2>();
    Schema->CreateDefaultNodesForGraph(*Graph);
    Schema->CreateFunctionGraphTerminators(*Graph, static_cast<UClass*>(nullptr));
    Schema->AddExtraFunctionFlags(Graph, FUNC_BlueprintCallable | FUNC_BlueprintEvent | FUNC_Public);
    Schema->MarkFunctionEntryAsEditable(Graph, true);
    BP->DelegateSignatureGraphs.Add(Graph);
    AddParams(EntryOf(Graph), Params, EGPD_Output);
    FBlueprintEditorUtils::MarkBlueprintAsStructurallyModified(BP);
}

UEdGraph* FMenuGenBlueprint::AddFunction(FName Name, const TArray<FMenuGenParam>& Inputs, const TArray<FMenuGenParam>& Outputs, bool bPure)
{
    UEdGraph* Graph = NewGraph(Name);
    FBlueprintEditorUtils::AddFunctionGraph<UClass>(BP, Graph, true, nullptr);
    UK2Node_FunctionEntry* Entry = EntryOf(Graph);
    AddParams(Entry, Inputs, EGPD_Output);
    if (Outputs.Num() > 0)
    {
        AddParams(FBlueprintEditorUtils::FindOrCreateFunctionResultNode(Entry), Outputs, EGPD_Input);
    }
    if (bPure)
    {
        Entry->AddExtraFlags(FUNC_BlueprintPure);
    }
    return Graph;
}

UEdGraph* FMenuGenBlueprint::AddOverride(FName ParentFunction)
{
    UFunction* Function = BP->ParentClass->FindFunctionByName(ParentFunction);
    if (Function == nullptr)
    {
        UE_LOG(LogUEVRBridgeGen, Error, TEXT("%s: parent has no function %s"), *BP->GetName(), *ParentFunction.ToString());
        return nullptr;
    }
    // The UClass overload makes an override: the entry points at the parent's function and a
    // call to the parent implementation is placed after it (see FMenuGenGraph::Start).
    UEdGraph* Graph = NewGraph(ParentFunction);
    FBlueprintEditorUtils::AddFunctionGraph<UClass>(BP, Graph, false, Function->GetOwnerClass());
    return Graph;
}

bool FMenuGenBlueprint::Compile(const TCHAR* Stage)
{
    FCompilerResultsLog Results;
    FKismetEditorUtilities::CompileBlueprint(BP, EBlueprintCompileOptions::SkipGarbageCollection, &Results);
    for (const TSharedRef<FTokenizedMessage>& Message : Results.Messages)
    {
        if (Message->GetSeverity() == EMessageSeverity::Error)
        {
            UE_LOG(LogUEVRBridgeGen, Error, TEXT("%s (%s): %s"), *BP->GetName(), Stage, *Message->ToText().ToString());
        }
    }
    const bool bOk = Results.NumErrors == 0 && BP->Status != BS_Error;
    UE_LOG(LogUEVRBridgeGen, Display, TEXT("Compiled %s (%s): %s"), *BP->GetName(), Stage, bOk ? TEXT("ok") : TEXT("FAILED"));
    return bOk;
}

bool FMenuGenBlueprint::Save(const TArray<int32>& ChunkIds)
{
    return MenuGenAsset::Save(BP, ChunkIds);
}

UEdGraph* FMenuGenBlueprint::NewGraph(FName Name) const
{
    return FBlueprintEditorUtils::CreateNewGraph(BP, Name, UEdGraph::StaticClass(), UEdGraphSchema_K2::StaticClass());
}

void FMenuGenBlueprint::AddParams(UK2Node_EditablePinBase* Node, const TArray<FMenuGenParam>& Params, EEdGraphPinDirection Direction)
{
    if (Node == nullptr)
    {
        return;
    }
    for (const FMenuGenParam& Param : Params)
    {
        Node->CreateUserDefinedPin(Param.Name, Param.Type, Direction, false);
    }
}

UK2Node_FunctionEntry* FMenuGenBlueprint::EntryOf(UEdGraph* Graph)
{
    TArray<UK2Node_FunctionEntry*> Entries;
    Graph->GetNodesOfClass<UK2Node_FunctionEntry>(Entries);
    return Entries.Num() > 0 ? Entries[0] : nullptr;
}
