#include "MenuGenIcon.h"

#include "BridgeGenLog.h"
#include "Engine/Texture2D.h"
#include "IImageWrapper.h"
#include "IImageWrapperModule.h"
#include "Interfaces/IPluginManager.h"
#include "Materials/Material.h"
#include "Materials/MaterialExpressionCollectionParameter.h"
#include "Materials/MaterialExpressionTextureSample.h"
#include "Materials/MaterialParameterCollection.h"
#include "MenuGenAsset.h"
#include "MenuGenStore.h"
#include "Misc/FileHelper.h"
#include "Modules/ModuleManager.h"

namespace
{
// The game's MPC_UserTintParameters, read from the cooked asset. A material that reads a
// collection compiles against its parameter order and records its StateId; in the game the
// reference resolves to the real collection, and the material finds the live tint only when
// both match. So the dummy copies the StateId, every parameter in order, and their Ids.
// Do not open the dummy in the editor and change it: that makes a new StateId.
const FGuid TintStateId(0x750932EF, 0x4B39B594, 0x79E34ABC, 0xB8B9BBF6);

struct FTintParameter
{
    const TCHAR* Name;
    FLinearColor Default;
    FGuid Id;
};

const FTintParameter TintParameters[] = {
    { TEXT("UIBackgroundTint0"), FLinearColor(0.0000f, 0.7011f, 1.0000f, 1.0000f), FGuid(0x81CFE507, 0x4FB85889, 0xC3F20680, 0xEB36422E) },
    { TEXT("UIBackgroundTint1"), FLinearColor(0.1470f, 1.0000f, 0.2195f, 1.0000f), FGuid(0x9A5520CB, 0x416092FC, 0x07E13286, 0x2D6B804E) },
    { TEXT("UIHighlightTint0"), FLinearColor(1.0000f, 0.1683f, 0.0000f, 1.0000f), FGuid(0x58A1D0E7, 0x40A85A2A, 0x46CE3FAC, 0x5B4E1234) },
    { TEXT("UIHighlightTint1"), FLinearColor(0.9765f, 0.8549f, 0.0314f, 1.0000f), FGuid(0xC02E51A2, 0x4D7670F6, 0x4325B882, 0xC327C475) },
    { TEXT("UIMapIconEnemy"), FLinearColor(0.9417f, 0.0000f, 0.0000f, 1.0000f), FGuid(0xF54E3DAF, 0x41DE2657, 0xBF0E398A, 0xBDCA4BC3) },
    { TEXT("UIMapIconSecurity"), FLinearColor(1.0000f, 0.1507f, 0.0000f, 1.0000f), FGuid(0x8CA863C1, 0x4C4FE9D0, 0xD67480B0, 0x092C2238) },
    { TEXT("UIMapIconHealingUtility"), FLinearColor(0.1470f, 1.0000f, 0.2195f, 1.0000f), FGuid(0xC64E8D20, 0x457D846F, 0x2A3C9E95, 0x99089D87) },
    { TEXT("UIMapIconPowerUtility"), FLinearColor(0.0000f, 0.7011f, 1.0000f, 1.0000f), FGuid(0x7969ADF7, 0x433BA07D, 0x193F4887, 0x3DC11C4F) },
    { TEXT("UIMapIconElevator"), FLinearColor(0.0000f, 0.1760f, 1.0000f, 1.0000f), FGuid(0x72A57357, 0x4B717D49, 0xD820AAA8, 0x481A6577) },
    { TEXT("UIMapIconItem"), FLinearColor(0.1470f, 1.0000f, 0.2195f, 1.0000f), FGuid(0xB10EB4BC, 0x48D8116E, 0x2E4945BB, 0x17412F44) },
    { TEXT("UIMapIconStoryItem"), FLinearColor(0.4300f, 1.0000f, 0.4784f, 1.0000f), FGuid(0x6CCBE588, 0x442F8D52, 0x2D1EAF97, 0x6BCA9E12) },
    { TEXT("UIMapIconQuestMarker"), FLinearColor(0.9823f, 0.8550f, 0.0307f, 1.0000f), FGuid(0xB01E265F, 0x49523A36, 0xA5DDED93, 0x62EBA43D) },
    { TEXT("UIMapIconUserMarkerA"), FLinearColor(1.0000f, 0.1683f, 0.0000f, 1.0000f), FGuid(0xC15DE5EE, 0x4548D724, 0xEE3A6FA8, 0xA6800BB9) },
    { TEXT("UIMapIconUserMarkerB"), FLinearColor(0.0000f, 0.0000f, 0.0000f, 0.0000f), FGuid(0xF86462AB, 0x4B688302, 0xBDD9CDB3, 0x0A9D9698) },
    { TEXT("UIMapIconUserMarkerC"), FLinearColor(0.0000f, 0.0000f, 0.0000f, 0.0000f), FGuid(0x26E5EE7D, 0x4088D03E, 0x7B0F5EAD, 0x9871BB67) },
    { TEXT("UIMapIconUserMarkerD"), FLinearColor(0.0000f, 0.0000f, 0.0000f, 0.0000f), FGuid(0x9CEE0C59, 0x4DC2F829, 0x5031CA9F, 0x8096DA23) },
    { TEXT("UIMapIconPuzzle"), FLinearColor(0.3887f, 0.1470f, 1.0000f, 1.0000f), FGuid(0xC5FCE64E, 0x45352454, 0x038427B6, 0x0811D615) },
    { TEXT("UIMapIconCyberspace"), FLinearColor(1.0000f, 0.1470f, 0.8436f, 1.0000f), FGuid(0x80D69B8C, 0x4BB2DE78, 0xEE1DFE8E, 0xF264F563) },
    { TEXT("UIMapIconVendor"), FLinearColor(0.7417f, 0.7417f, 0.7417f, 1.0000f), FGuid(0xF4CE3603, 0x4F49F59C, 0x4456318C, 0x628514AC) },
};

// The game's category icons are this colour: the icon mask times the background tint.
const FName IconTint(TEXT("UIBackgroundTint1"));

template <class AssetType>
AssetType* LoadExisting(const FString& Path)
{
    AssetType* Asset = LoadObject<AssetType>(nullptr, *MenuGenAsset::ObjectPath(Path));
    if (Asset == nullptr)
    {
        UE_LOG(LogUEVRBridgeGen, Error, TEXT("Cannot load %s"), *Path);
        return nullptr;
    }
    UE_LOG(LogUEVRBridgeGen, Display, TEXT("Kept existing %s"), *Path);
    return Asset;
}

UMaterialParameterCollection* MakeTintCollection(const FMenuGenOptions& Options)
{
    const FString Path = MenuGenPaths::TintCollection;
    if (MenuGenAsset::Exists(Path) && !Options.bOverwrite) return LoadExisting<UMaterialParameterCollection>(Path);

    UPackage* Package = MenuGenAsset::NewPackage(Path);
    MenuGenAsset::Evict(Package, MenuGenAsset::NameOf(Path));
    auto* Collection = NewObject<UMaterialParameterCollection>(Package, *MenuGenAsset::NameOf(Path), RF_Public | RF_Standalone);
    // PostEditChange builds the uniform buffer layout the material compiles against, and
    // gives the collection a new StateId, which is replaced right after.
    Collection->PreEditChange(nullptr);
    for (const FTintParameter& Source : TintParameters)
    {
        FCollectionVectorParameter Parameter;
        Parameter.ParameterName = Source.Name;
        Parameter.DefaultValue = Source.Default;
        Parameter.Id = Source.Id;
        Collection->VectorParameters.Add(Parameter);
    }
    Collection->PostEditChange();
    Collection->StateId = TintStateId;
    return MenuGenAsset::Save(Collection, {}) ? Collection : nullptr;
}

// The PNG lives in the generator plugin, which the Unreal project reaches through a junction.
bool ReadIconPixels(TArray<uint8>& OutBgra, int32& OutWidth, int32& OutHeight)
{
    TSharedPtr<IPlugin> Plugin = IPluginManager::Get().FindPlugin(TEXT("UEVRBridgeGen"));
    const FString File = Plugin.IsValid() ? Plugin->GetBaseDir() / MenuGenPaths::IconSource : FString();
    TArray<uint8> Compressed;
    if (File.IsEmpty() || !FFileHelper::LoadFileToArray(Compressed, *File))
    {
        UE_LOG(LogUEVRBridgeGen, Error, TEXT("Cannot read the icon image %s"), *File);
        return false;
    }
    IImageWrapperModule& Images = FModuleManager::LoadModuleChecked<IImageWrapperModule>(TEXT("ImageWrapper"));
    TSharedPtr<IImageWrapper> Png = Images.CreateImageWrapper(EImageFormat::PNG);
    if (!Png.IsValid() || !Png->SetCompressed(Compressed.GetData(), Compressed.Num()) || !Png->GetRaw(ERGBFormat::BGRA, 8, OutBgra))
    {
        UE_LOG(LogUEVRBridgeGen, Error, TEXT("Cannot decode the icon image %s"), *File);
        return false;
    }
    OutWidth = Png->GetWidth();
    OutHeight = Png->GetHeight();
    return true;
}

// Same settings as the game's icon textures: uncompressed BGRA8, UI texture group, one mip.
UTexture2D* MakeIconTexture(const FMenuGenOptions& Options)
{
    const FString Path = Options.ModRoot / MenuGenPaths::IconTexture;
    if (MenuGenAsset::Exists(Path) && !Options.bOverwrite) return LoadExisting<UTexture2D>(Path);

    TArray<uint8> Pixels;
    int32 Width = 0;
    int32 Height = 0;
    if (!ReadIconPixels(Pixels, Width, Height)) return nullptr;

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

// A UI material like the game's MAT_OptionsIcons_*: colour = the user's background tint,
// opacity = the icon mask. The tint is read from the collection, so the icon follows the
// colour the player picks in the Interface options.
UMaterial* MakeIconMaterial(const FMenuGenOptions& Options, UTexture2D* Texture, UMaterialParameterCollection* Collection)
{
    const FString Path = Options.ModRoot / MenuGenPaths::IconMaterial;
    if (MenuGenAsset::Exists(Path) && !Options.bOverwrite) return LoadExisting<UMaterial>(Path);

    UPackage* Package = MenuGenAsset::NewPackage(Path);
    MenuGenAsset::Evict(Package, MenuGenAsset::NameOf(Path));
    auto* Material = NewObject<UMaterial>(Package, *MenuGenAsset::NameOf(Path), RF_Public | RF_Standalone);
    Material->MaterialDomain = MD_UI;
    Material->BlendMode = BLEND_Translucent;

    auto* Mask = NewObject<UMaterialExpressionTextureSample>(Material);
    Mask->Texture = Texture;
    Mask->SamplerType = SAMPLERTYPE_Color;
    Mask->MaterialExpressionEditorX = -400;
    Mask->MaterialExpressionEditorY = 200;
    Material->Expressions.Add(Mask);

    auto* Tint = NewObject<UMaterialExpressionCollectionParameter>(Material);
    Tint->Collection = Collection;
    Tint->ParameterName = IconTint;
    Tint->ParameterId = Collection->GetParameterId(IconTint);
    Tint->MaterialExpressionEditorX = -400;
    Material->Expressions.Add(Tint);

    Material->EmissiveColor.Connect(0, Tint);
    Material->Opacity.Connect(1, Mask);  // output 1 of a texture sample is its R channel
    Material->PreEditChange(nullptr);
    Material->PostEditChange();
    return MenuGenAsset::Save(Material, { MenuGenPaths::ModChunk }) ? Material : nullptr;
}
} // namespace

bool MenuGenIcon::Generate(FMenuGenStore& Store, const FMenuGenOptions& Options)
{
    UMaterialParameterCollection* Collection = MakeTintCollection(Options);
    UTexture2D* Texture = Collection != nullptr ? MakeIconTexture(Options) : nullptr;
    UMaterial* Material = Texture != nullptr ? MakeIconMaterial(Options, Texture, Collection) : nullptr;
    Store.IconMaterial = Material;
    return Material != nullptr;
}
