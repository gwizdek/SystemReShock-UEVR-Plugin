#pragma once

#include "CoreMinimal.h"
#include "EdGraph/EdGraph.h"

class UK2Node_AddDelegate;
class UK2Node_CallFunction;
class UK2Node_CallParentFunction;
class UK2Node_CreateDelegate;
class UK2Node_DynamicCast;
class UK2Node_FunctionEntry;
class UK2Node_FunctionResult;
class UK2Node_IfThenElse;
class UK2Node_MakeArray;
class UK2Node_Self;
class UK2Node_VariableGet;
class UK2Node_VariableSet;

// Builds the nodes of one function graph and links their pins. Node positions only matter
// for a person opening the graph, so nodes are laid out left to right in creation order.
class FMenuGenGraph
{
public:
    explicit FMenuGenGraph(UEdGraph* InGraph);

    UK2Node_FunctionEntry* Entry() const;
    UK2Node_FunctionResult* Result() const;
    // The node to chain new exec nodes after: the parent call that an override graph starts with,
    // or the entry itself.
    UEdGraphNode* Start() const;

    // Calls a function. A function of the Blueprint's own class chain gets no target pin.
    UK2Node_CallFunction* Call(UClass* Owner, FName Function);
    UK2Node_CallParentFunction* CallParent(FName Function);
    // Reads or writes a variable. Owner null means a variable of this Blueprint.
    UK2Node_VariableGet* Get(FName Variable, UClass* Owner = nullptr);
    UK2Node_VariableSet* Set(FName Variable, UClass* Owner = nullptr);
    UK2Node_DynamicCast* Cast(UClass* To, bool bPure);
    UK2Node_IfThenElse* Branch();
    UK2Node_Self* Self();
    // A "Create Event" node pointing at a function of this Blueprint.
    UK2Node_CreateDelegate* Delegate(FName Function);
    // A "Bind Event" node for a dispatcher. Owner null means a dispatcher of this Blueprint's class chain.
    UK2Node_AddDelegate* Bind(FName Dispatcher, UClass* Owner = nullptr);
    UK2Node_MakeArray* MakeArray(int32 Count);

    bool Link(UEdGraphPin* From, UEdGraphPin* To);
    bool Link(UEdGraphNode* From, FName FromPin, UEdGraphNode* To, FName ToPin);
    // Links the exec output "then" of From to the exec input of To.
    bool Then(UEdGraphNode* From, UEdGraphNode* To);

    static UEdGraphPin* Pin(UEdGraphNode* Node, FName Name, EEdGraphPinDirection Direction = EGPD_MAX);
    static UEdGraphPin* ReturnPin(UEdGraphNode* Node);
    static UEdGraphPin* SelfPin(UEdGraphNode* Node);
    bool SetDefault(UEdGraphNode* Node, FName PinName, const FString& Value);
    bool SetDefaultText(UEdGraphNode* Node, FName PinName, const FText& Value);
    bool SetDefaultObject(UEdGraphNode* Node, FName PinName, UObject* Value);

private:
    template <class NodeType>
    NodeType* Make(TFunctionRef<void(NodeType*)> Setup);

    UClass* OwnClass() const;
    const UEdGraphSchema_K2* Schema() const;

    UEdGraph* Graph;
    int32 NextX = 400;
};
