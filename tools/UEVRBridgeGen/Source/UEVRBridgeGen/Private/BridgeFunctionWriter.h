#pragma once

#include "CoreMinimal.h"

#include "BridgeTypeMapper.h"

class FBridgeHeaderBuilder;
class FProperty;
class UFunction;
struct FBridgeContext;

enum class EBridgeCallMode
{
    // Called on the wrapped object: bridge::as_uobject(this).
    Member,
    // Static Blueprint function library call, dispatched on the class default object.
    Static,
    // Interface function, dispatched on an explicit target object.
    Interface,
};

// Emits one inline C++ method that calls a Blueprint UFunction through the bridge.
class FBridgeFunctionWriter
{
public:
    FBridgeFunctionWriter(const FBridgeContext& InContext, FBridgeHeaderBuilder& InHeader);

    // Appends the name of the emitted bridge::Func accessor to WarmFuncs when the
    // function can be warmed up against its own class (not for interface calls).
    FString Write(const UFunction* Function, EBridgeCallMode Mode, TArray<FString>& WarmFuncs) const;

private:
    struct FParam
    {
        const FProperty* Property = nullptr;
        FBridgeType Type;
        FString Name;
        bool bReturn = false;
        bool bOut = false;
        int32 Index = 0;
    };

    bool CollectParams(const UFunction* Function, TArray<FParam>& Params, FString& Reason) const;
    FString Signature(const UFunction* Function, const TArray<FParam>& Params, EBridgeCallMode Mode) const;
    FString ParamDecl(const FParam& Param) const;
    FString ReturnType(const FParam* Return) const;
    FString ParamNameList(const TArray<FParam>& Params) const;
    FString SetLine(const FParam& Param) const;
    FString OutLine(const FParam& Param) const;
    FString ReturnLine(const FParam& Param) const;
    FString Target(EBridgeCallMode Mode) const;
    FString FlagsComment(const UFunction* Function) const;

    const FBridgeContext& Context;
    FBridgeHeaderBuilder& Header;
};
