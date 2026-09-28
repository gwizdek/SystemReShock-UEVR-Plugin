#include "BridgeClassWriter.h"

#include "BridgeContext.h"
#include "BridgeHeaderBuilder.h"
#include "BridgeNaming.h"
#include "UObject/Class.h"
#include "UObject/UnrealType.h"

FBridgeClassWriter::FBridgeClassWriter(const FBridgeContext& InContext)
    : Context(InContext)
{
}

FString FBridgeClassWriter::Write(const UClass* Class) const
{
    FBridgeHeaderBuilder Header(Context, Class);
    const TSet<FString> Reserved = ReservedNames(Class);

    TArray<FString> WarmProps;
    TArray<FString> WarmFuncs;
    FString Body;
    Body += ClassHead(Class, Header);
    Body += StaticMembers(Class);
    Body += Properties(Class, Header, Reserved, WarmProps);
    Body += Functions(Class, Header, WarmFuncs);
    Body += Warmup(WarmProps, WarmFuncs);
    Body += TEXT("};\n");

    return Header.Build(BridgeNaming::ObjectSearchPath(Class), Body);
}

FString FBridgeClassWriter::ClassHead(const UClass* Class, FBridgeHeaderBuilder& Header) const
{
    const UClass* Parent = Class->GetSuperClass();
    Header.AddDep({ Parent, true });

    const TCHAR* Final = HasGeneratedSubclass(Class) ? TEXT("") : TEXT(" final");
    return FString::Printf(TEXT("// %s\nclass %s%s : public %s\n{\npublic:\n"),
        *BridgeNaming::ObjectSearchPath(Class), *BridgeNaming::ClassCppName(Class), Final,
        *BridgeNaming::ClassCppName(Parent));
}

FString FBridgeClassWriter::StaticMembers(const UClass* Class) const
{
    const FString Name = BridgeNaming::ClassCppName(Class);
    FString Out;
    Out += FString::Printf(TEXT("\tstatic constexpr const wchar_t* BridgeClassPath = L\"%s\";\n\n"),
        *BridgeNaming::ObjectSearchPath(Class));
    Out += TEXT("\tstatic bridge::ClassRef& BridgeClassRef()\n\t{\n");
    Out += TEXT("\t\tstatic bridge::ClassRef Ref{ BridgeClassPath };\n\t\treturn Ref;\n\t}\n");
    Out += TEXT("\tstatic uevr::API::UClass* BridgeClass() { return BridgeClassRef().require(); }\n");
    Out += TEXT("\tstatic class UClass* StaticClass() { return reinterpret_cast<class UClass*>(BridgeClass()); }\n");
    Out += FString::Printf(TEXT("\tstatic %s* GetDefaultObj() { return reinterpret_cast<%s*>(BridgeClass()->get_class_default_object()); }\n\n"),
        *Name, *Name);
    return Out;
}

FString FBridgeClassWriter::Properties(const UClass* Class, FBridgeHeaderBuilder& Header, const TSet<FString>& Reserved, TArray<FString>& WarmProps) const
{
    FString Out;
    for (TFieldIterator<FProperty> It(Class, EFieldIteratorFlags::ExcludeSuper); It; ++It)
    {
        if (SkipProperty(*It))
        {
            continue;
        }
        TArray<FBridgeDep> Deps;
        const FBridgeType Type = Context.Mapper.Map(*It, Deps);
        if (!Type.bSupported)
        {
            Out += FString::Printf(TEXT("\t// skipped %s: %s\n"), *It->GetName(), *Type.Reason);
            continue;
        }
        Header.AddDeps(Deps);
        FString Name = BridgeNaming::Sanitize(It->GetAuthoredName());
        if (Reserved.Contains(Name))
        {
            Name += TEXT("_");
        }
        Out += PropertyAccessor(*It, Type, Name);
        WarmProps.Add(TEXT("BridgeProp_") + Name);
    }
    return Out.IsEmpty() ? Out : Out + TEXT("\n");
}

FString FBridgeClassWriter::PropertyAccessor(const FProperty* Property, const FBridgeType& Type, const FString& Name) const
{
    // The bridge::Prop lives in its own static accessor so BridgeWarmup can resolve it
    // without touching an object.
    FString Out = FString::Printf(TEXT("\tstatic bridge::Prop& BridgeProp_%s() { static bridge::Prop Ref{ L\"%s\" }; return Ref; }\n"),
        *Name, *Property->GetName());
    const FBoolProperty* Bool = CastField<FBoolProperty>(Property);
    if (Bool != nullptr && !Bool->IsNativeBool())
    {
        // Bit-packed bool: no address to hand out, so read and write go through the property.
        Out += FString::Printf(
            TEXT("\tbool %s() { return BridgeProp_%s().get_bool(this, BridgeClass()); }\n")
            TEXT("\tvoid %s(bool Value) { BridgeProp_%s().set_bool(this, BridgeClass(), Value); }\n"),
            *Name, *Name, *Name, *Name);
        return Out;
    }
    Out += FString::Printf(TEXT("\t%s& %s() { return BridgeProp_%s().ref<%s>(this, BridgeClass()); }\n"),
        *Type.Cpp, *Name, *Name, *Type.Cpp);
    return Out;
}

FString FBridgeClassWriter::Functions(const UClass* Class, FBridgeHeaderBuilder& Header, TArray<FString>& WarmFuncs) const
{
    const FBridgeFunctionWriter Writer(Context, Header);
    FString Out;
    for (TFieldIterator<UFunction> It(Class, EFieldIteratorFlags::ExcludeSuper); It; ++It)
    {
        if (SkipFunction(*It))
        {
            continue;
        }
        Out += Writer.Write(*It, CallModeFor(Class, *It), WarmFuncs);
    }
    return Out;
}

FString FBridgeClassWriter::Warmup(const TArray<FString>& WarmProps, const TArray<FString>& WarmFuncs) const
{
    FString Out;
    Out += TEXT("\t// Resolves the class and every property and function above, so no first use pays\n");
    Out += TEXT("\t// the lookup mid-game. Returns false when the class is not loaded yet or a name did\n");
    Out += TEXT("\t// not resolve; whatever is missing resolves on first use as usual.\n");
    Out += TEXT("\tstatic bool BridgeWarmup()\n\t{\n");
    Out += TEXT("\t\tuevr::API::UClass* Cls = BridgeClassRef().get();\n");
    Out += TEXT("\t\tif (Cls == nullptr) { bridge::warm_skipped(BridgeClassPath); return false; }\n");
    Out += TEXT("\t\tbool Ok = true;\n");
    for (const TArray<FString>* List : { &WarmProps, &WarmFuncs })
    {
        if (List->Num() == 0)
        {
            continue;
        }
        Out += TEXT("\t\tOk &= bridge::warm(Cls, {\n");
        for (const FString& Name : *List)
        {
            Out += FString::Printf(TEXT("\t\t\t&%s(),\n"), *Name);
        }
        Out += TEXT("\t\t});\n");
    }
    Out += TEXT("\t\treturn Ok;\n\t}\n");
    return Out;
}

bool FBridgeClassWriter::HasGeneratedSubclass(const UClass* Class) const
{
    for (const UClass* Other : Context.Classes)
    {
        if (Other != Class && Other->IsChildOf(Class))
        {
            return true;
        }
    }
    return false;
}

bool FBridgeClassWriter::SkipProperty(const FProperty* Property)
{
    // The ubergraph frame pointer is compiler bookkeeping, not a Blueprint variable.
    const FStructProperty* Struct = CastField<FStructProperty>(Property);
    return Struct != nullptr && Struct->Struct != nullptr
        && Struct->Struct->GetFName() == TEXT("PointerToUberGraphFrame");
}

bool FBridgeClassWriter::SkipFunction(const UFunction* Function)
{
    // Delegate signatures are types, not callables. The ubergraph entry point is internal.
    return Function->HasAnyFunctionFlags(FUNC_Delegate)
        || Function->GetName().StartsWith(TEXT("ExecuteUbergraph"));
}

EBridgeCallMode FBridgeClassWriter::CallModeFor(const UClass* Class, const UFunction* Function)
{
    if (Class->HasAnyClassFlags(CLASS_Interface))
    {
        return EBridgeCallMode::Interface;
    }
    return Function->HasAnyFunctionFlags(FUNC_Static) ? EBridgeCallMode::Static : EBridgeCallMode::Member;
}

TSet<FString> FBridgeClassWriter::ReservedNames(const UClass* Class)
{
    TSet<FString> Names = { TEXT("StaticClass"), TEXT("GetDefaultObj"), TEXT("BridgeClass"), TEXT("BridgeClassPath"),
        TEXT("BridgeClassRef"), TEXT("BridgeWarmup") };
    for (TFieldIterator<UFunction> It(Class, EFieldIteratorFlags::ExcludeSuper); It; ++It)
    {
        Names.Add(BridgeNaming::Sanitize(It->GetName()));
    }
    return Names;
}
