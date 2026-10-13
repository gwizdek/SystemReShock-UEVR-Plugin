#include "MenuGenMaterial.h"

#include "BridgeGenLog.h"
#include "Engine/Texture2D.h"
#include "IImageWrapper.h"
#include "IImageWrapperModule.h"
#include "Interfaces/IPluginManager.h"
#include "Materials/MaterialExpressionScalarParameter.h"
#include "Materials/MaterialExpressionTextureSample.h"
#include "Materials/MaterialExpressionTextureSampleParameter2D.h"
#include "Materials/MaterialExpressionVectorParameter.h"
#include "Materials/MaterialExpressionVertexColor.h"
#include "MenuGenAsset.h"
#include "Misc/FileHelper.h"
#include "Modules/ModuleManager.h"

namespace
{
// The PNG lives in the generator plugin, which the Unreal project reaches through a junction.
bool ReadPng(const TCHAR* RelativeFile, TArray<uint8>& OutBgra, int32& OutWidth, int32& OutHeight)
{
    TSharedPtr<IPlugin> Plugin = IPluginManager::Get().FindPlugin(TEXT("UEVRBridgeGen"));
    const FString File = Plugin.IsValid() ? Plugin->GetBaseDir() / RelativeFile : FString();
    TArray<uint8> Compressed;
    if (File.IsEmpty() || !FFileHelper::LoadFileToArray(Compressed, *File))
    {
        UE_LOG(LogUEVRBridgeGen, Error, TEXT("Cannot read the image %s"), *File);
        return false;
    }
    IImageWrapperModule& Images = FModuleManager::LoadModuleChecked<IImageWrapperModule>(TEXT("ImageWrapper"));
    TSharedPtr<IImageWrapper> Png = Images.CreateImageWrapper(EImageFormat::PNG);
    if (!Png.IsValid() || !Png->SetCompressed(Compressed.GetData(), Compressed.Num()) || !Png->GetRaw(ERGBFormat::BGRA, 8, OutBgra))
    {
        UE_LOG(LogUEVRBridgeGen, Error, TEXT("Cannot decode the image %s"), *File);
        return false;
    }
    OutWidth = Png->GetWidth();
    OutHeight = Png->GetHeight();
    return true;
}
} // namespace

UTexture2D* MenuGenMaterial::MakeTexture(const FString& PackagePath, const TCHAR* PngRelative, const TArray<int32>& ChunkIds)
{
    TArray<uint8> Pixels;
    int32 Width = 0;
    int32 Height = 0;
    if (!ReadPng(PngRelative, Pixels, Width, Height)) return nullptr;

    UPackage* Package = MenuGenAsset::NewPackage(PackagePath);
    MenuGenAsset::Evict(Package, MenuGenAsset::NameOf(PackagePath));
    auto* Texture = NewObject<UTexture2D>(Package, *MenuGenAsset::NameOf(PackagePath), RF_Public | RF_Standalone);
    Texture->Source.Init(Width, Height, 1, 1, TSF_BGRA8, Pixels.GetData());
    Texture->CompressionSettings = TC_EditorIcon;
    Texture->LODGroup = TEXTUREGROUP_UI;
    Texture->MipGenSettings = TMGS_NoMipmaps;
    Texture->NeverStream = true;
    Texture->PostEditChange();
    return MenuGenAsset::Save(Texture, ChunkIds) ? Texture : nullptr;
}

UMaterial* MenuGenMaterial::NewUiMaterial(const FString& PackagePath)
{
    UPackage* Package = MenuGenAsset::NewPackage(PackagePath);
    MenuGenAsset::Evict(Package, MenuGenAsset::NameOf(PackagePath));
    auto* Material = NewObject<UMaterial>(Package, *MenuGenAsset::NameOf(PackagePath), RF_Public | RF_Standalone);
    Material->MaterialDomain = MD_UI;
    Material->BlendMode = BLEND_Translucent;
    return Material;
}

bool MenuGenMaterial::Save(UMaterial* Material, const TArray<int32>& ChunkIds)
{
    Material->PreEditChange(nullptr);
    Material->PostEditChange();
    return MenuGenAsset::Save(Material, ChunkIds);
}

UMaterialExpressionMultiply* MenuGenMaterial::Multiply(UMaterial* Material, UMaterialExpression* A, int32 OutputA, UMaterialExpression* B, int32 OutputB, int32 X, int32 Y)
{
    auto* Expression = Add<UMaterialExpressionMultiply>(Material, X, Y);
    Expression->A.Connect(OutputA, A);
    Expression->B.Connect(OutputB, B);
    return Expression;
}

UMaterialExpressionMultiply* MenuGenMaterial::MultiplyConst(UMaterial* Material, UMaterialExpression* A, int32 OutputA, float ConstB, int32 X, int32 Y)
{
    auto* Expression = Add<UMaterialExpressionMultiply>(Material, X, Y);
    Expression->A.Connect(OutputA, A);
    Expression->ConstB = ConstB;
    return Expression;
}

UMaterialExpressionScalarParameter* MenuGenMaterial::Scalar(UMaterial* Material, FName Name, float Default, int32 X, int32 Y)
{
    auto* Expression = Add<UMaterialExpressionScalarParameter>(Material, X, Y);
    Expression->ParameterName = Name;
    Expression->DefaultValue = Default;
    return Expression;
}

UMaterialExpressionVectorParameter* MenuGenMaterial::Color(UMaterial* Material, FName Name, FLinearColor Default, int32 X, int32 Y)
{
    auto* Expression = Add<UMaterialExpressionVectorParameter>(Material, X, Y);
    Expression->ParameterName = Name;
    Expression->DefaultValue = Default;
    return Expression;
}

UMaterialExpressionTextureSample* MenuGenMaterial::Sample(UMaterial* Material, UTexture2D* Texture, int32 X, int32 Y)
{
    auto* Expression = Add<UMaterialExpressionTextureSample>(Material, X, Y);
    Expression->Texture = Texture;
    Expression->SamplerType = SAMPLERTYPE_Color;
    return Expression;
}

UMaterialExpressionTextureSampleParameter2D* MenuGenMaterial::SampleParameter(UMaterial* Material, FName Name, UTexture2D* Texture, int32 X, int32 Y)
{
    auto* Expression = Add<UMaterialExpressionTextureSampleParameter2D>(Material, X, Y);
    Expression->ParameterName = Name;
    Expression->Texture = Texture;
    Expression->SamplerType = SAMPLERTYPE_Color;
    return Expression;
}

UMaterialExpressionVertexColor* MenuGenMaterial::VertexColor(UMaterial* Material, int32 X, int32 Y)
{
    return Add<UMaterialExpressionVertexColor>(Material, X, Y);
}

void MenuGenMaterial::ConnectThroughVertexColor(UMaterial* Material, UMaterialExpression* Color, UMaterialExpression* Opacity, int32 OutputOpacity)
{
    UMaterialExpressionVertexColor* Vertex = VertexColor(Material, 100, 300);
    UMaterialExpressionMultiply* TintedColor = Multiply(Material, Color, 0, Vertex, OutRGB, 300, 0);
    UMaterialExpressionMultiply* TintedOpacity = Multiply(Material, Opacity, OutputOpacity, Vertex, OutA, 300, 400);
    Material->EmissiveColor.Connect(0, TintedColor);
    Material->Opacity.Connect(0, TintedOpacity);
}
