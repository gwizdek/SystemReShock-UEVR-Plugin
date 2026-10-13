#include "MenuGenHudIcon.h"

#include "BridgeGenLog.h"
#include "Engine/Texture2D.h"
#include "IImageWrapper.h"
#include "IImageWrapperModule.h"
#include "Interfaces/IPluginManager.h"
#include "Materials/Material.h"
#include "Materials/MaterialExpressionAdd.h"
#include "Materials/MaterialExpressionMultiply.h"
#include "Materials/MaterialExpressionScalarParameter.h"
#include "Materials/MaterialExpressionTextureSampleParameter2D.h"
#include "Materials/MaterialExpressionVectorParameter.h"
#include "Materials/MaterialExpressionVertexColor.h"
#include "MenuGenAsset.h"
#include "MenuGenStore.h"
#include "Misc/FileHelper.h"
#include "Modules/ModuleManager.h"

namespace
{
// Texture sample outputs: 0 = RGB, 1 = R, 2 = G, 3 = B, 4 = A.
constexpr int32 OutputR = 1;
constexpr int32 OutputG = 2;
constexpr int32 OutputAlpha = 4;

// The game's envelope texture: R is the crisp outline, G a soft fill with a glow around the
// envelope. The game draws it additively, which looks like a bright orange outline over a dim
// dark red fill. These defaults copy that look; the plugin can change them on a dynamic instance.
const FName IconParameter(TEXT("Icon"));
const FName OutlineColorParameter(TEXT("OutlineColor"));
const FName FillColorParameter(TEXT("FillColor"));
const FName FillOpacityParameter(TEXT("FillOpacity"));
// Linear values: 0.12 red shows as about 95 of 255 on screen. Tuned in the running game
// against the original icon.
const FLinearColor OutlineColorDefault(1.0f, 0.38f, 0.04f, 1.0f);
const FLinearColor FillColorDefault(0.12f, 0.008f, 0.0f, 1.0f);
constexpr float FillOpacityDefault = 0.35f;

// The PNG lives in the generator plugin, which the Unreal project reaches through a junction.
bool ReadPixels(const TCHAR* RelativeFile, TArray<uint8>& OutBgra, int32& OutWidth, int32& OutHeight)
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

// Same settings as the game's texture: uncompressed BGRA8, UI texture group, one mip.
UTexture2D* MakeTexture(const FMenuGenOptions& Options)
{
    const FString Path = FString(MenuGenPaths::HudIconRoot) / MenuGenPaths::HudIconTexture;
    if (MenuGenAsset::Exists(Path) && !Options.bOverwrite) return MenuGenAsset::LoadExisting<UTexture2D>(Path);

    TArray<uint8> Pixels;
    int32 Width = 0;
    int32 Height = 0;
    if (!ReadPixels(MenuGenPaths::HudIconSource, Pixels, Width, Height)) return nullptr;

    UPackage* Package = MenuGenAsset::NewPackage(Path);
    MenuGenAsset::Evict(Package, MenuGenAsset::NameOf(Path));
    auto* Texture = NewObject<UTexture2D>(Package, *MenuGenAsset::NameOf(Path), RF_Public | RF_Standalone);
    Texture->Source.Init(Width, Height, 1, 1, TSF_BGRA8, Pixels.GetData());
    Texture->CompressionSettings = TC_EditorIcon;
    Texture->LODGroup = TEXTUREGROUP_UI;
    Texture->MipGenSettings = TMGS_NoMipmaps;
    Texture->NeverStream = true;
    Texture->PostEditChange();
    return MenuGenAsset::Save(Texture, { MenuGenPaths::ModChunk }) ? Texture : nullptr;
}

template <class ExpressionType>
ExpressionType* AddExpression(UMaterial* Material, int32 X, int32 Y)
{
    auto* Expression = NewObject<ExpressionType>(Material);
    Expression->MaterialExpressionEditorX = X;
    Expression->MaterialExpressionEditorY = Y;
    Material->Expressions.Add(Expression);
    return Expression;
}

UMaterialExpressionVectorParameter* AddColorParameter(UMaterial* Material, FName Name, FLinearColor Default, int32 Y)
{
    auto* Parameter = AddExpression<UMaterialExpressionVectorParameter>(Material, -600, Y);
    Parameter->ParameterName = Name;
    Parameter->DefaultValue = Default;
    return Parameter;
}

UMaterialExpressionMultiply* AddMultiply(UMaterial* Material, UMaterialExpression* A, int32 OutputA, UMaterialExpression* B, int32 Y)
{
    auto* Multiply = AddExpression<UMaterialExpressionMultiply>(Material, -300, Y);
    Multiply->A.Connect(OutputA, A);
    Multiply->B.Connect(0, B);
    return Multiply;
}

// Emissive = (R * OutlineColor + G * FillColor) * vertex colour. Opacity = (R + G * FillOpacity)
// * vertex alpha; the renderer clamps it. The game's mesh widget passes its Color as the vertex
// colour, so the game can still tint and fade the icon. The texture is a parameter.
UMaterial* MakeMaterial(const FMenuGenOptions& Options, UTexture2D* Texture)
{
    const FString Path = FString(MenuGenPaths::HudIconRoot) / MenuGenPaths::HudIconMaterial;
    if (MenuGenAsset::Exists(Path) && !Options.bOverwrite) return MenuGenAsset::LoadExisting<UMaterial>(Path);

    UPackage* Package = MenuGenAsset::NewPackage(Path);
    MenuGenAsset::Evict(Package, MenuGenAsset::NameOf(Path));
    auto* Material = NewObject<UMaterial>(Package, *MenuGenAsset::NameOf(Path), RF_Public | RF_Standalone);
    Material->MaterialDomain = MD_UI;
    Material->BlendMode = BLEND_Translucent;

    auto* Icon = AddExpression<UMaterialExpressionTextureSampleParameter2D>(Material, -600, 0);
    Icon->ParameterName = IconParameter;
    Icon->Texture = Texture;
    Icon->SamplerType = SAMPLERTYPE_Color;

    auto* OutlineColor = AddColorParameter(Material, OutlineColorParameter, OutlineColorDefault, 300);
    auto* FillColor = AddColorParameter(Material, FillColorParameter, FillColorDefault, 450);
    auto* FillOpacity = AddExpression<UMaterialExpressionScalarParameter>(Material, -600, 600);
    FillOpacity->ParameterName = FillOpacityParameter;
    FillOpacity->DefaultValue = FillOpacityDefault;

    auto* Outline = AddMultiply(Material, Icon, OutputR, OutlineColor, 0);
    auto* Fill = AddMultiply(Material, Icon, OutputG, FillColor, 150);
    auto* Color = AddExpression<UMaterialExpressionAdd>(Material, -100, 0);
    Color->A.Connect(0, Outline);
    Color->B.Connect(0, Fill);

    auto* FillAlpha = AddMultiply(Material, Icon, OutputG, FillOpacity, 400);
    auto* Alpha = AddExpression<UMaterialExpressionAdd>(Material, -100, 400);
    Alpha->A.Connect(OutputR, Icon);
    Alpha->B.Connect(0, FillAlpha);

    auto* Vertex = AddExpression<UMaterialExpressionVertexColor>(Material, -300, 600);
    auto* TintedColor = AddExpression<UMaterialExpressionMultiply>(Material, 100, 0);
    TintedColor->A.Connect(0, Color);
    TintedColor->B.Connect(0, Vertex);
    auto* TintedAlpha = AddExpression<UMaterialExpressionMultiply>(Material, 100, 400);
    TintedAlpha->A.Connect(0, Alpha);
    TintedAlpha->B.Connect(OutputAlpha, Vertex);

    Material->EmissiveColor.Connect(0, TintedColor);
    Material->Opacity.Connect(0, TintedAlpha);
    Material->PreEditChange(nullptr);
    Material->PostEditChange();
    return MenuGenAsset::Save(Material, { MenuGenPaths::ModChunk }) ? Material : nullptr;
}
} // namespace

bool MenuGenHudIcon::Generate(FMenuGenStore& Store, const FMenuGenOptions& Options)
{
    UTexture2D* Texture = MakeTexture(Options);
    UMaterial* Material = Texture != nullptr ? MakeMaterial(Options, Texture) : nullptr;
    Store.HudIconMaterial = Material;
    return Material != nullptr;
}
