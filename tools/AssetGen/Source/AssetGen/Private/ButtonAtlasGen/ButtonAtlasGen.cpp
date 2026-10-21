#include "ButtonAtlasGen.h"

#include "AssetGen/AssetGenAsset.h"
#include "AssetGen/AssetGenContext.h"
#include "AssetGen/AssetGenMaterial.h"
#include "AssetGenLog.h"
#include "Engine/Texture2D.h"
#include "Materials/Material.h"
#include "Materials/MaterialExpressionTextureSampleParameter2D.h"
#include "Materials/MaterialInstanceConstant.h"

// The texture and the material instance are the mod's own assets (chunk 10); the plugin loads
// them by these paths. The stand-in for the game's button material is at the game's path,
// chunk 0, never shipped.
namespace ButtonAtlasGenPaths
{
constexpr const TCHAR* Root = TEXT("/Game/Mods/UI/ControllerButtons");
constexpr const TCHAR* Texture = TEXT("T_VRButtonLayout");
constexpr const TCHAR* Instance = TEXT("MI_VRButtonLayout");
// Relative to the generator plugin's folder. Drawn by draw_vr_button_icons.py there.
constexpr const TCHAR* Source = TEXT("Resources/ButtonAtlas/T_VRButtonLayout.png");
constexpr const TCHAR* PlatformButtonMaterial = TEXT("/Game/Art/UI/Icons/ControllerButtons/MAT_PlatformButton");
} // namespace ButtonAtlasGenPaths

namespace
{
using namespace AssetGenMaterial;

// The parameters of the game's MAT_PlatformButton that the instance overrides. The game's
// widget sets ButtonTextureSheet and ButtonIndex on a dynamic instance itself; ColCount and
// RowCount come from the material it was given, so the instance carries the atlas grid.
const FName SheetParameter(TEXT("ButtonTextureSheet"));
const FName ColCountParameter(TEXT("ColCount"));
const FName RowCountParameter(TEXT("RowCount"));

// The grid of T_VRButtonLayout.png; draw_vr_button_icons.py lists the cells.
constexpr float AtlasColumns = 4.0f;
constexpr float AtlasRows = 7.0f;

UTexture2D* MakeAtlasTexture(const FAssetGenContext& Context)
{
    const FString Path = FString(ButtonAtlasGenPaths::Root) / ButtonAtlasGenPaths::Texture;
    if (AssetGenAsset::Exists(Path) && !Context.bOverwrite) return AssetGenAsset::LoadExisting<UTexture2D>(Path);
    return MakeTexture(Path, ButtonAtlasGenPaths::Source, { AssetGen::ModChunk });
}

// A stand-in for the game's material at the game's path, with the three parameters the
// instance overrides, so the instance can be made and cooked. Chunk 0, so it is never
// shipped: in the game the instance's parent reference resolves to the game's own material,
// which reads the same parameter names.
UMaterial* MakePlatformButtonStandIn(const FAssetGenContext& Context, UTexture2D* Texture)
{
    const FString Path = ButtonAtlasGenPaths::PlatformButtonMaterial;
    if (AssetGenAsset::Exists(Path) && !Context.bOverwrite) return AssetGenAsset::LoadExisting<UMaterial>(Path);

    UMaterial* Material = NewUiMaterial(Path);
    auto* Sheet = SampleParameter(Material, SheetParameter, Texture, -600, 0);
    Scalar(Material, ColCountParameter, 4.0f, -600, 300);
    Scalar(Material, RowCountParameter, 4.0f, -600, 450);
    Material->EmissiveColor.Connect(OutRGB, Sheet);
    Material->Opacity.Connect(OutA, Sheet);
    return Save(Material, {}) ? Material : nullptr;
}

UMaterialInstanceConstant* MakeAtlasInstance(const FAssetGenContext& Context, UMaterial* Parent, UTexture2D* Texture)
{
    const FString Path = FString(ButtonAtlasGenPaths::Root) / ButtonAtlasGenPaths::Instance;
    if (AssetGenAsset::Exists(Path) && !Context.bOverwrite) return AssetGenAsset::LoadExisting<UMaterialInstanceConstant>(Path);

    UPackage* Package = AssetGenAsset::NewPackage(Path);
    AssetGenAsset::Evict(Package, AssetGenAsset::NameOf(Path));
    auto* Instance = NewObject<UMaterialInstanceConstant>(Package, *AssetGenAsset::NameOf(Path), RF_Public | RF_Standalone);
    Instance->SetParentEditorOnly(Parent);
    Instance->SetTextureParameterValueEditorOnly(FMaterialParameterInfo(SheetParameter), Texture);
    Instance->SetScalarParameterValueEditorOnly(FMaterialParameterInfo(ColCountParameter), AtlasColumns);
    Instance->SetScalarParameterValueEditorOnly(FMaterialParameterInfo(RowCountParameter), AtlasRows);
    Instance->PreEditChange(nullptr);
    Instance->PostEditChange();
    return AssetGenAsset::Save(Instance, { AssetGen::ModChunk }) ? Instance : nullptr;
}
} // namespace

bool ButtonAtlasGen::Generate(const FAssetGenContext& Context)
{
    UTexture2D* Texture = MakeAtlasTexture(Context);
    UMaterial* StandIn = Texture != nullptr ? MakePlatformButtonStandIn(Context, Texture) : nullptr;
    return StandIn != nullptr && MakeAtlasInstance(Context, StandIn, Texture) != nullptr;
}
