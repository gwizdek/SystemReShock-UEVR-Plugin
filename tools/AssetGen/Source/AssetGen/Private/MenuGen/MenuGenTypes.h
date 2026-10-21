#pragma once

#include "CoreMinimal.h"
#include "EdGraph/EdGraphPin.h"
#include "EdGraphSchema_K2.h"

// A function or dispatcher parameter of a generated Blueprint.
struct FMenuGenParam
{
    FName Name;
    FEdGraphPinType Type;
};

// Pin types used by the generated variables, parameters and dispatchers.
namespace MenuGenPins
{
inline FEdGraphPinType Simple(FName Category)
{
    FEdGraphPinType Type;
    Type.PinCategory = Category;
    return Type;
}

inline FEdGraphPinType Bool() { return Simple(UEdGraphSchema_K2::PC_Boolean); }
inline FEdGraphPinType Int() { return Simple(UEdGraphSchema_K2::PC_Int); }
inline FEdGraphPinType Float() { return Simple(UEdGraphSchema_K2::PC_Float); }
inline FEdGraphPinType Name() { return Simple(UEdGraphSchema_K2::PC_Name); }
inline FEdGraphPinType Text() { return Simple(UEdGraphSchema_K2::PC_Text); }
inline FEdGraphPinType Delegate() { return Simple(UEdGraphSchema_K2::PC_MCDelegate); }

inline FEdGraphPinType Object(UClass* Class)
{
    FEdGraphPinType Type = Simple(UEdGraphSchema_K2::PC_Object);
    Type.PinSubCategoryObject = Class;
    return Type;
}

inline FEdGraphPinType Byte(UEnum* Enum)
{
    FEdGraphPinType Type = Simple(UEdGraphSchema_K2::PC_Byte);
    Type.PinSubCategoryObject = Enum;
    return Type;
}

inline FEdGraphPinType Array(FEdGraphPinType Inner)
{
    Inner.ContainerType = EPinContainerType::Array;
    return Inner;
}
} // namespace MenuGenPins
