#include "MenuGenGraph.h"

#include "AssetGenLog.h"
#include "EdGraphSchema_K2.h"
#include "Engine/Blueprint.h"
#include "K2Node_AddDelegate.h"
#include "K2Node_CallFunction.h"
#include "K2Node_CallParentFunction.h"
#include "K2Node_CreateDelegate.h"
#include "K2Node_DynamicCast.h"
#include "K2Node_FunctionEntry.h"
#include "K2Node_FunctionResult.h"
#include "K2Node_IfThenElse.h"
#include "K2Node_MakeArray.h"
#include "K2Node_Self.h"
#include "K2Node_VariableGet.h"
#include "K2Node_VariableSet.h"
#include "Kismet2/BlueprintEditorUtils.h"

FMenuGenGraph::FMenuGenGraph(UEdGraph* InGraph) : Graph(InGraph)
{
}

UK2Node_FunctionEntry* FMenuGenGraph::Entry() const
{
    TArray<UK2Node_FunctionEntry*> Nodes;
    Graph->GetNodesOfClass<UK2Node_FunctionEntry>(Nodes);
    return Nodes.Num() > 0 ? Nodes[0] : nullptr;
}

UK2Node_FunctionResult* FMenuGenGraph::Result() const
{
    TArray<UK2Node_FunctionResult*> Nodes;
    Graph->GetNodesOfClass<UK2Node_FunctionResult>(Nodes);
    return Nodes.Num() > 0 ? Nodes[0] : nullptr;
}

UEdGraphNode* FMenuGenGraph::Start() const
{
    UEdGraphPin* Then = Entry()->FindPin(UEdGraphSchema_K2::PN_Then, EGPD_Output);
    if (Then != nullptr && Then->LinkedTo.Num() > 0 && !Then->LinkedTo[0]->GetOwningNode()->IsA<UK2Node_FunctionResult>())
    {
        return Then->LinkedTo[0]->GetOwningNode();
    }
    return Entry();
}

template <class NodeType>
NodeType* FMenuGenGraph::Make(TFunctionRef<void(NodeType*)> Setup)
{
    FGraphNodeCreator<NodeType> Creator(*Graph);
    NodeType* Node = Creator.CreateNode(false);
    Setup(Node);
    Node->NodePosX = NextX;
    NextX += 320;
    Creator.Finalize();
    return Node;
}

UK2Node_CallFunction* FMenuGenGraph::Call(UClass* Owner, FName Function)
{
    UFunction* Target = Owner->FindFunctionByName(Function);
    if (Target == nullptr)
    {
        UE_LOG(LogAssetGen, Error, TEXT("%s: no function %s on %s"), *Graph->GetName(), *Function.ToString(), *Owner->GetName());
        return nullptr;
    }
    return Make<UK2Node_CallFunction>([Target](UK2Node_CallFunction* Node) { Node->SetFromFunction(Target); });
}

UK2Node_CallParentFunction* FMenuGenGraph::CallParent(FName Function)
{
    UFunction* Target = OwnClass()->GetSuperClass()->FindFunctionByName(Function);
    if (Target == nullptr)
    {
        UE_LOG(LogAssetGen, Error, TEXT("%s: parent has no function %s"), *Graph->GetName(), *Function.ToString());
        return nullptr;
    }
    return Make<UK2Node_CallParentFunction>([Target](UK2Node_CallParentFunction* Node) { Node->SetFromFunction(Target); });
}

UK2Node_VariableGet* FMenuGenGraph::Get(FName Variable, UClass* Owner)
{
    return Make<UK2Node_VariableGet>([&](UK2Node_VariableGet* Node)
    {
        if (Owner == nullptr) Node->VariableReference.SetSelfMember(Variable);
        else Node->VariableReference.SetExternalMember(Variable, Owner);
    });
}

UK2Node_VariableSet* FMenuGenGraph::Set(FName Variable, UClass* Owner)
{
    return Make<UK2Node_VariableSet>([&](UK2Node_VariableSet* Node)
    {
        if (Owner == nullptr) Node->VariableReference.SetSelfMember(Variable);
        else Node->VariableReference.SetExternalMember(Variable, Owner);
    });
}

UK2Node_DynamicCast* FMenuGenGraph::Cast(UClass* To, bool bPure)
{
    UK2Node_DynamicCast* Node = Make<UK2Node_DynamicCast>([To](UK2Node_DynamicCast* Cast) { Cast->TargetType = To; });
    Node->SetPurity(bPure);
    return Node;
}

UK2Node_IfThenElse* FMenuGenGraph::Branch()
{
    return Make<UK2Node_IfThenElse>([](UK2Node_IfThenElse*) {});
}

UK2Node_Self* FMenuGenGraph::Self()
{
    return Make<UK2Node_Self>([](UK2Node_Self*) {});
}

UK2Node_CreateDelegate* FMenuGenGraph::Delegate(FName Function)
{
    UK2Node_CreateDelegate* Node = Make<UK2Node_CreateDelegate>([](UK2Node_CreateDelegate*) {});
    Node->SetFunction(Function);
    return Node;
}

UK2Node_AddDelegate* FMenuGenGraph::Bind(FName Dispatcher, UClass* Owner)
{
    UClass* Scope = Owner != nullptr ? Owner : OwnClass();
    FMulticastDelegateProperty* Property = FindFProperty<FMulticastDelegateProperty>(Scope, Dispatcher);
    if (Property == nullptr)
    {
        UE_LOG(LogAssetGen, Error, TEXT("%s: no dispatcher %s on %s"), *Graph->GetName(), *Dispatcher.ToString(), *Scope->GetName());
        return nullptr;
    }
    const bool bSelf = Owner == nullptr;
    return Make<UK2Node_AddDelegate>([&](UK2Node_AddDelegate* Node) { Node->SetFromProperty(Property, bSelf, Property->GetOwnerClass()); });
}

UK2Node_MakeArray* FMenuGenGraph::MakeArray(int32 Count)
{
    UK2Node_MakeArray* Node = Make<UK2Node_MakeArray>([](UK2Node_MakeArray*) {});
    for (int32 i = 1; i < Count; ++i)
    {
        Node->AddInputPin();
    }
    return Node;
}

bool FMenuGenGraph::Link(UEdGraphPin* From, UEdGraphPin* To)
{
    if (From == nullptr || To == nullptr)
    {
        UE_LOG(LogAssetGen, Error, TEXT("%s: link with a missing pin"), *Graph->GetName());
        return false;
    }
    if (!Schema()->TryCreateConnection(From, To))
    {
        UE_LOG(LogAssetGen, Error, TEXT("%s: cannot link %s.%s to %s.%s"), *Graph->GetName(),
            *From->GetOwningNode()->GetName(), *From->PinName.ToString(), *To->GetOwningNode()->GetName(), *To->PinName.ToString());
        return false;
    }
    return true;
}

bool FMenuGenGraph::Link(UEdGraphNode* From, FName FromPin, UEdGraphNode* To, FName ToPin)
{
    if (From == nullptr || To == nullptr)
    {
        UE_LOG(LogAssetGen, Error, TEXT("%s: link with a missing node"), *Graph->GetName());
        return false;
    }
    return Link(Pin(From, FromPin, EGPD_Output), Pin(To, ToPin, EGPD_Input));
}

bool FMenuGenGraph::Then(UEdGraphNode* From, UEdGraphNode* To)
{
    return Link(From, UEdGraphSchema_K2::PN_Then, To, UEdGraphSchema_K2::PN_Execute);
}

UEdGraphPin* FMenuGenGraph::Pin(UEdGraphNode* Node, FName Name, EEdGraphPinDirection Direction)
{
    UEdGraphPin* Found = Node != nullptr ? Node->FindPin(Name, Direction) : nullptr;
    if (Found == nullptr)
    {
        UE_LOG(LogAssetGen, Error, TEXT("Node %s has no pin %s"), Node ? *Node->GetName() : TEXT("null"), *Name.ToString());
    }
    return Found;
}

UEdGraphPin* FMenuGenGraph::ReturnPin(UEdGraphNode* Node)
{
    return Pin(Node, UEdGraphSchema_K2::PN_ReturnValue, EGPD_Output);
}

UEdGraphPin* FMenuGenGraph::SelfPin(UEdGraphNode* Node)
{
    return Pin(Node, UEdGraphSchema_K2::PN_Self, EGPD_Input);
}

bool FMenuGenGraph::SetDefault(UEdGraphNode* Node, FName PinName, const FString& Value)
{
    UEdGraphPin* Target = Pin(Node, PinName, EGPD_Input);
    if (Target == nullptr) return false;
    Schema()->TrySetDefaultValue(*Target, Value);
    return true;
}

bool FMenuGenGraph::SetDefaultText(UEdGraphNode* Node, FName PinName, const FText& Value)
{
    UEdGraphPin* Target = Pin(Node, PinName, EGPD_Input);
    if (Target == nullptr) return false;
    Schema()->TrySetDefaultText(*Target, Value);
    return true;
}

bool FMenuGenGraph::SetDefaultObject(UEdGraphNode* Node, FName PinName, UObject* Value)
{
    UEdGraphPin* Target = Pin(Node, PinName, EGPD_Input);
    if (Target == nullptr) return false;
    Schema()->TrySetDefaultObject(*Target, Value);
    return true;
}

UClass* FMenuGenGraph::OwnClass() const
{
    return FBlueprintEditorUtils::FindBlueprintForGraphChecked(Graph)->GeneratedClass;
}

const UEdGraphSchema_K2* FMenuGenGraph::Schema() const
{
    return GetDefault<UEdGraphSchema_K2>();
}
