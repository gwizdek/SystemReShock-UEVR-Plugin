#include "MenuGenIcon.h"

#include "AssetGen/AssetGenAsset.h"
#include "AssetGenLog.h"
#include "Engine/Texture2D.h"
#include "IImageWrapper.h"
#include "IImageWrapperModule.h"
#include "Interfaces/IPluginManager.h"
#include "Materials/Material.h"
#include "Materials/MaterialExpressionCollectionParameter.h"
#include "Materials/MaterialExpressionTextureSample.h"
#include "Materials/MaterialParameterCollection.h"
#include "MenuGenStore.h"
#include "Misc/FileHelper.h"
#include "Modules/ModuleManager.h"

namespace
{
// The game's category icons are this colour: the icon mask times the background tint.
const FName IconTint(TEXT("UIBackgroundTint1"));

// The PNG lives in the generator plugin, which the Unreal project reaches through a junction.
bool ReadIconPixels(TArray<uint8>& OutBgra, int32& OutWidth, int32& OutHeight)
{
    TSharedPtr<IPlugin> Plugin = IPluginManager::Get().FindPlugin(TEXT("AssetGen"));
    const FString File = Plugin.IsValid() ? Plugin->GetBaseDir() / MenuGenPaths::IconSource : FString();
    TArray<uint8> Compressed;
    if (File.IsEmpty() || !FFileHelper::LoadFileToArray(Compressed, *File))
    {
        UE_LOG(LogAssetGen, Error, TEXT("Cannot read the icon image %s"), *File);
        return false;
    }
    IImageWrapperModule& Images = FModuleManager::LoadModuleChecked<IImageWrapperModule>(TEXT("ImageWrapper"));
    TSharedPtr<IImageWrapper> Png = Images.CreateImageWrapper(EImageFormat::PNG);
    if (!Png.IsValid() || !Png->SetCompressed(Compressed.GetData(), Compressed.Num()) || !Png->GetRaw(ERGBFormat::BGRA, 8, OutBgra))
    {
        UE_LOG(LogAssetGen, Error, TEXT("Cannot decode the icon image %s"), *File);
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
    if (AssetGenAsset::Exists(Path) && !Options.bOverwrite) return AssetGenAsset::LoadExisting<UTexture2D>(Path);

    TArray<uint8> Pixels;
    int32 Width = 0;
    int32 Height = 0;
    if (!ReadIconPixels(Pixels, Width, Height)) return nullptr;

    UPackage* Package = AssetGenAsset::NewPackage(Path);
    AssetGenAsset::Evict(Package, AssetGenAsset::NameOf(Path));
    auto* Texture = NewObject<UTexture2D>(Package, *AssetGenAsset::NameOf(Path), RF_Public | RF_Standalone);
    Texture->Source.Init(Width, Height, 1, 1, TSF_BGRA8, Pixels.GetData());
    Texture->CompressionSettings = TC_EditorIcon;
    Texture->LODGroup = TEXTUREGROUP_UI;
    Texture->MipGenSettings = TMGS_NoMipmaps;
    Texture->NeverStream = true;
    Texture->PostEditChange();
    return AssetGenAsset::Save(Texture, { AssetGen::ModChunk }) ? Texture : nullptr;
}

// A UI material like the game's MAT_OptionsIcons_*: colour = the user's background tint,
// opacity = the icon mask. The tint is read from the collection, so the icon follows the
// colour the player picks in the Interface options.
UMaterial* MakeIconMaterial(const FMenuGenOptions& Options, UTexture2D* Texture, UMaterialParameterCollection* Collection)
{
    const FString Path = Options.ModRoot / MenuGenPaths::IconMaterial;
    if (AssetGenAsset::Exists(Path) && !Options.bOverwrite) return AssetGenAsset::LoadExisting<UMaterial>(Path);

    UPackage* Package = AssetGenAsset::NewPackage(Path);
    AssetGenAsset::Evict(Package, AssetGenAsset::NameOf(Path));
    auto* Material = NewObject<UMaterial>(Package, *AssetGenAsset::NameOf(Path), RF_Public | RF_Standalone);
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
    return AssetGenAsset::Save(Material, { AssetGen::ModChunk }) ? Material : nullptr;
}
} // namespace

bool MenuGenIcon::Generate(FMenuGenStore& Store, const FMenuGenOptions& Options)
{
    if (Store.TintCollection == nullptr)
    {
        UE_LOG(LogAssetGen, Error, TEXT("The tint collection must be generated first"));
        return false;
    }
    UTexture2D* Texture = MakeIconTexture(Options);
    UMaterial* Material = Texture != nullptr ? MakeIconMaterial(Options, Texture, Store.TintCollection) : nullptr;
    Store.IconMaterial = Material;
    return Material != nullptr;
}
