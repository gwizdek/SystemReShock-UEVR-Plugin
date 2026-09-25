#include "BridgeNaming.h"

#include "UObject/Class.h"
#include "UObject/Package.h"

namespace
{
    const TSet<FString>& CppKeywords()
    {
        static const TSet<FString> Keywords = {
            TEXT("alignas"), TEXT("alignof"), TEXT("and"), TEXT("asm"), TEXT("auto"), TEXT("bool"),
            TEXT("break"), TEXT("case"), TEXT("catch"), TEXT("char"), TEXT("class"), TEXT("concept"),
            TEXT("const"), TEXT("constexpr"), TEXT("continue"), TEXT("decltype"), TEXT("default"),
            TEXT("delete"), TEXT("do"), TEXT("double"), TEXT("else"), TEXT("enum"), TEXT("explicit"),
            TEXT("export"), TEXT("extern"), TEXT("false"), TEXT("float"), TEXT("for"), TEXT("friend"),
            TEXT("goto"), TEXT("if"), TEXT("inline"), TEXT("int"), TEXT("long"), TEXT("mutable"),
            TEXT("namespace"), TEXT("new"), TEXT("noexcept"), TEXT("not"), TEXT("nullptr"),
            TEXT("operator"), TEXT("or"), TEXT("private"), TEXT("protected"), TEXT("public"),
            TEXT("register"), TEXT("requires"), TEXT("return"), TEXT("short"), TEXT("signed"),
            TEXT("sizeof"), TEXT("static"), TEXT("struct"), TEXT("switch"), TEXT("template"),
            TEXT("this"), TEXT("throw"), TEXT("true"), TEXT("try"), TEXT("typedef"), TEXT("typeid"),
            TEXT("typename"), TEXT("union"), TEXT("unsigned"), TEXT("using"), TEXT("virtual"),
            TEXT("void"), TEXT("volatile"), TEXT("while"), TEXT("xor"),
        };
        return Keywords;
    }

    bool IsIdentifierChar(TCHAR C)
    {
        return FChar::IsAlnum(C) || C == TEXT('_');
    }
}

FString BridgeNaming::Sanitize(const FString& Name)
{
    FString Out;
    Out.Reserve(Name.Len() + 2);
    for (TCHAR C : Name)
    {
        Out.AppendChar(IsIdentifierChar(C) ? C : TEXT('_'));
    }
    if (Out.IsEmpty() || FChar::IsDigit(Out[0]))
    {
        Out.InsertAt(0, TEXT('_'));
    }
    if (CppKeywords().Contains(Out))
    {
        Out += TEXT("_");
    }
    return Out;
}

FString BridgeNaming::ClassCppName(const UClass* Class)
{
    // GetPrefixCPP returns "I" for interfaces, "A" for actors and "U" otherwise,
    // which is the rule Dumper-7 follows as well.
    return FString(Class->GetPrefixCPP()) + Sanitize(Class->GetName());
}

FString BridgeNaming::StructCppName(const UScriptStruct* Struct)
{
    return TEXT("F") + Sanitize(Struct->GetName());
}

FString BridgeNaming::EnumCppName(const UEnum* Enum)
{
    const FString Name = Sanitize(Enum->GetName());
    return Name.StartsWith(TEXT("E")) ? Name : TEXT("E") + Name;
}

FString BridgeNaming::PackageShortName(const UField* Field)
{
    FString PackageName = Field->GetOutermost()->GetName();
    int32 SlashIndex = INDEX_NONE;
    if (PackageName.FindLastChar(TEXT('/'), SlashIndex))
    {
        PackageName.RightChopInline(SlashIndex + 1);
    }
    return Sanitize(PackageName);
}

FString BridgeNaming::ClassesHeaderName(const UField* Field)
{
    return PackageShortName(Field) + TEXT("_classes.hpp");
}

FString BridgeNaming::StructsHeaderName(const UField* Field)
{
    return PackageShortName(Field) + TEXT("_structs.hpp");
}

FString BridgeNaming::ObjectSearchPath(const UObject* Object)
{
    return Object->GetClass()->GetName() + TEXT(" ") + Object->GetPathName();
}
