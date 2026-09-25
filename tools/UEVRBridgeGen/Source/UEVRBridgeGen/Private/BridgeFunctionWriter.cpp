#include "BridgeFunctionWriter.h"

#include "BridgeContext.h"
#include "BridgeHeaderBuilder.h"
#include "BridgeNaming.h"
#include "UObject/Class.h"
#include "UObject/UnrealType.h"

namespace
{
    const TCHAR* const FuncVar = TEXT("BridgeFunc");
    const TCHAR* const CallVar = TEXT("BridgeCall");
    const TCHAR* const TargetVar = TEXT("BridgeTarget");
    const TCHAR* const ResultVar = TEXT("BridgeResult");

    FString LocalSafe(const FString& Name)
    {
        const bool bClash = Name == FuncVar || Name == CallVar || Name == TargetVar || Name == ResultVar;
        return bClash ? Name + TEXT("_") : Name;
    }
}

FBridgeFunctionWriter::FBridgeFunctionWriter(const FBridgeContext& InContext, FBridgeHeaderBuilder& InHeader)
    : Context(InContext)
    , Header(InHeader)
{
}

FString FBridgeFunctionWriter::Write(const UFunction* Function, EBridgeCallMode Mode) const
{
    TArray<FParam> Params;
    FString Reason;
    if (!CollectParams(Function, Params, Reason))
    {
        return FString::Printf(TEXT("\t// skipped %s: %s\n"), *Function->GetName(), *Reason);
    }

    const FParam* Return = Params.FindByPredicate([](const FParam& P) { return P.bReturn; });

    FString Out;
    Out += FString::Printf(TEXT("\t// Function %s%s\n"), *Function->GetName(), *FlagsComment(Function));
    Out += TEXT("\t") + Signature(Function, Params, Mode) + TEXT("\n\t{\n");
    Out += FString::Printf(TEXT("\t\tstatic bridge::Func %s{ L\"%s\", { %s } };\n"),
        FuncVar, *Function->GetName(), *ParamNameList(Params));
    Out += FString::Printf(TEXT("\t\tbridge::Call %s(%s, %s);\n"), CallVar, FuncVar, *Target(Mode));
    for (const FParam& Param : Params)
    {
        if (!Param.bReturn)
        {
            Out += SetLine(Param);
        }
    }
    Out += FString::Printf(TEXT("\t\t%s.invoke();\n"), CallVar);
    for (const FParam& Param : Params)
    {
        if (Param.bOut && !Param.bReturn)
        {
            Out += OutLine(Param);
        }
    }
    if (Return != nullptr)
    {
        Out += ReturnLine(*Return);
    }
    Out += TEXT("\t}\n\n");
    return Out;
}

bool FBridgeFunctionWriter::CollectParams(const UFunction* Function, TArray<FParam>& Params, FString& Reason) const
{
    TArray<FBridgeDep> Deps;
    for (TFieldIterator<FProperty> It(Function); It; ++It)
    {
        if (!It->HasAnyPropertyFlags(CPF_Parm))
        {
            continue;
        }
        FParam Param;
        Param.Property = *It;
        Param.Type = Context.Mapper.Map(*It, Deps);
        if (!Param.Type.bSupported)
        {
            Reason = It->GetName() + TEXT(" has unsupported type (") + Param.Type.Reason + TEXT(")");
            return false;
        }
        Param.bReturn = It->HasAnyPropertyFlags(CPF_ReturnParm);
        Param.bOut = It->HasAnyPropertyFlags(CPF_OutParm) && !Param.bReturn;
        Param.Name = LocalSafe(BridgeNaming::Sanitize(It->GetName()));
        Param.Index = Params.Num();
        Params.Add(Param);
    }
    Header.AddDeps(Deps);
    return true;
}

FString FBridgeFunctionWriter::Signature(const UFunction* Function, const TArray<FParam>& Params, EBridgeCallMode Mode) const
{
    TArray<FString> Decls;
    if (Mode == EBridgeCallMode::Interface)
    {
        Decls.Add(FString::Printf(TEXT("uevr::API::UObject* %s"), TargetVar));
    }
    const FParam* Return = nullptr;
    for (const FParam& Param : Params)
    {
        if (Param.bReturn)
        {
            Return = &Param;
            continue;
        }
        Decls.Add(ParamDecl(Param));
    }
    const TCHAR* Prefix = Mode == EBridgeCallMode::Member ? TEXT("") : TEXT("static ");
    return FString::Printf(TEXT("%s%s %s(%s)"), Prefix, *ReturnType(Return),
        *BridgeNaming::Sanitize(Function->GetName()), *FString::Join(Decls, TEXT(", ")));
}

FString FBridgeFunctionWriter::ParamDecl(const FParam& Param) const
{
    if (Param.bOut)
    {
        return Param.Type.Cpp + TEXT("* ") + Param.Name;
    }
    if (Param.Type.bPassByRef)
    {
        return TEXT("const ") + Param.Type.Cpp + TEXT("& ") + Param.Name;
    }
    return Param.Type.Cpp + TEXT(" ") + Param.Name;
}

FString FBridgeFunctionWriter::ReturnType(const FParam* Return) const
{
    if (Return == nullptr)
    {
        return TEXT("void");
    }
    if (Return->Type.bIsUserStruct)
    {
        return TEXT("bridge::Boxed<") + Return->Type.Cpp + TEXT(">");
    }
    return Return->Type.Cpp;
}

FString FBridgeFunctionWriter::ParamNameList(const TArray<FParam>& Params) const
{
    TArray<FString> Names;
    for (const FParam& Param : Params)
    {
        Names.Add(FString::Printf(TEXT("L\"%s\""), *Param.Property->GetName()));
    }
    return FString::Join(Names, TEXT(", "));
}

FString FBridgeFunctionWriter::SetLine(const FParam& Param) const
{
    const FString Value = Param.bOut ? TEXT("*") + Param.Name : Param.Name;
    const FString Data = Param.bOut ? Param.Name + TEXT("->Data") : Param.Name + TEXT(".Data");
    FString Set;
    if (Param.Type.bIsBool)
    {
        Set = FString::Printf(TEXT("%s.set_bool(%d, %s);"), CallVar, Param.Index, *Value);
    }
    else if (Param.Type.bIsUserStruct)
    {
        Set = FString::Printf(TEXT("%s.set_raw(%d, %s, %s::StaticSize());"), CallVar, Param.Index, *Data, *Param.Type.Cpp);
    }
    else
    {
        Set = FString::Printf(TEXT("%s.set<%s>(%d, %s);"), CallVar, *Param.Type.Cpp, Param.Index, *Value);
    }
    if (Param.bOut)
    {
        return FString::Printf(TEXT("\t\tif (%s != nullptr) { %s }\n"), *Param.Name, *Set);
    }
    return TEXT("\t\t") + Set + TEXT("\n");
}

FString FBridgeFunctionWriter::OutLine(const FParam& Param) const
{
    FString Get;
    if (Param.Type.bIsBool)
    {
        Get = FString::Printf(TEXT("*%s = %s.get_bool(%d);"), *Param.Name, CallVar, Param.Index);
    }
    else if (Param.Type.bIsUserStruct)
    {
        Get = FString::Printf(TEXT("%s.copy_out(%d, %s->Data, %s::StaticSize());"), CallVar, Param.Index, *Param.Name, *Param.Type.Cpp);
    }
    else
    {
        Get = FString::Printf(TEXT("*%s = %s.get<%s>(%d);"), *Param.Name, CallVar, *Param.Type.Cpp, Param.Index);
    }
    return FString::Printf(TEXT("\t\tif (%s != nullptr) { %s }\n"), *Param.Name, *Get);
}

FString FBridgeFunctionWriter::ReturnLine(const FParam& Param) const
{
    if (Param.Type.bIsBool)
    {
        return FString::Printf(TEXT("\t\treturn %s.get_bool(%d);\n"), CallVar, Param.Index);
    }
    if (Param.Type.bIsUserStruct)
    {
        return FString::Printf(
            TEXT("\t\tbridge::Boxed<%s> %s(%s::StaticSize());\n\t\t%s.copy_out(%d, %s.data(), %s.size());\n\t\treturn %s;\n"),
            *Param.Type.Cpp, ResultVar, *Param.Type.Cpp, CallVar, Param.Index, ResultVar, ResultVar, ResultVar);
    }
    return FString::Printf(TEXT("\t\treturn %s.get<%s>(%d);\n"), CallVar, *Param.Type.Cpp, Param.Index);
}

FString FBridgeFunctionWriter::Target(EBridgeCallMode Mode) const
{
    switch (Mode)
    {
    case EBridgeCallMode::Static:
        return TEXT("BridgeClass()->get_class_default_object()");
    case EBridgeCallMode::Interface:
        return TargetVar;
    default:
        return TEXT("bridge::as_uobject(this)");
    }
}

FString FBridgeFunctionWriter::FlagsComment(const UFunction* Function) const
{
    TArray<FString> Flags;
    if (Function->HasAnyFunctionFlags(FUNC_BlueprintCallable)) Flags.Add(TEXT("BlueprintCallable"));
    if (Function->HasAnyFunctionFlags(FUNC_BlueprintPure)) Flags.Add(TEXT("BlueprintPure"));
    if (Function->HasAnyFunctionFlags(FUNC_BlueprintEvent)) Flags.Add(TEXT("BlueprintEvent"));
    if (Function->HasAnyFunctionFlags(FUNC_Static)) Flags.Add(TEXT("Static"));
    return Flags.Num() > 0 ? TEXT(" (") + FString::Join(Flags, TEXT(", ")) + TEXT(")") : FString();
}
