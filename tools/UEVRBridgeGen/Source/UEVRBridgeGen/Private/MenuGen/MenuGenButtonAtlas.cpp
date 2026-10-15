#include "MenuGenButtonAtlas.h"

#include "BridgeGenLog.h"
#include "Engine/Texture2D.h"
#include "Materials/Material.h"
#include "Materials/MaterialExpressionTextureSampleParameter2D.h"
#include "Materials/MaterialInstanceConstant.h"
#include "MenuGenAsset.h"
#include "MenuGenMaterial.h"
#include "MenuGenStore.h"

namespace
{
using namespace MenuGenMaterial;

// The parameters of the game's MAT_PlatformButton that the instance overrides. The game's
// widget sets ButtonTextureSheet and ButtonIndex on a dynamic instance itself; ColCount and
// RowCount come from the material it was given, so the instance carries the atlas grid.
const FName SheetParameter(TEXT("ButtonTextureSheet"));
const FName ColCountParameter(TEXT("ColCount"));
const FName RowCountParameter(TEXT("RowCount"));

// The grid of T_VRButtonLayout.png; draw_vr_button_icons.py lists the cells.
constexpr float AtlasColumns = 4.0f;
constexpr float AtlasRows = 7.0f;

UTexture2D* MakeAtlasTexture(const FMenuGenOptions& Options)
{
    const FString Path = FString(MenuGenPaths::ButtonAtlasRoot) / MenuGenPaths::ButtonAtlasTexture;
    if (MenuGenAsset::Exists(Path) && !Options.bOverwrite) return MenuGenAsset::LoadExisting<UTexture2D>(Path);
    return MakeTexture(Path, MenuGenPaths::ButtonAtlasSource, { MenuGenPaths::ModChunk });
}

// A stand-in for the game's material at the game's path, with the three parameters the
// instance overrides, so the instance can be made and cooked. Chunk 0, so it is never
// shipped: in the game the instance's parent reference resolves to the game's own material,
// which reads the same parameter names.
UMaterial* MakePlatformButtonStandIn(const FMenuGenOptions& Options, UTexture2D* Texture)
{
    const FString Path = MenuGenPaths::PlatformButtonMaterial;
    if (MenuGenAsset::Exists(Path) && !Options.bOverwrite) return MenuGenAsset::LoadExisting<UMaterial>(Path);

    UMaterial* Material = NewUiMaterial(Path);
    auto* Sheet = SampleParameter(Material, SheetParameter, Texture, -600, 0);
    Scalar(Material, ColCountParameter, 4.0f, -600, 300);
    Scalar(Material, RowCountParameter, 4.0f, -600, 450);
    Material->EmissiveColor.Connect(OutRGB, Sheet);
    Material->Opacity.Connect(OutA, Sheet);
    return Save(Material, {}) ? Material : nullptr;
}

UMaterialInstanceConstant* MakeAtlasInstance(const FMenuGenOptions& Options, UMaterial* Parent, UTexture2D* Texture)
{
    const FString Path = FString(MenuGenPaths::ButtonAtlasRoot) / MenuGenPaths::ButtonAtlasInstance;
    if (MenuGenAsset::Exists(Path) && !Options.bOverwrite) return MenuGenAsset::LoadExisting<UMaterialInstanceConstant>(Path);

    UPackage* Package = MenuGenAsset::NewPackage(Path);
    MenuGenAsset::Evict(Package, MenuGenAsset::NameOf(Path));
    auto* Instance = NewObject<UMaterialInstanceConstant>(Package, *MenuGenAsset::NameOf(Path), RF_Public | RF_Standalone);
    Instance->SetParentEditorOnly(Parent);
    Instance->SetTextureParameterValueEditorOnly(FMaterialParameterInfo(SheetParameter), Texture);
    Instance->SetScalarParameterValueEditorOnly(FMaterialParameterInfo(ColCountParameter), AtlasColumns);
    Instance->SetScalarParameterValueEditorOnly(FMaterialParameterInfo(RowCountParameter), AtlasRows);
    Instance->PreEditChange(nullptr);
    Instance->PostEditChange();
    return MenuGenAsset::Save(Instance, { MenuGenPaths::ModChunk }) ? Instance : nullptr;
}
} // namespace

bool MenuGenButtonAtlas::Generate(FMenuGenStore& Store, const FMenuGenOptions& Options)
{
    UTexture2D* Texture = MakeAtlasTexture(Options);
    UMaterial* StandIn = Texture != nullptr ? MakePlatformButtonStandIn(Options, Texture) : nullptr;
    UMaterialInstanceConstant* Instance = StandIn != nullptr ? MakeAtlasInstance(Options, StandIn, Texture) : nullptr;
    Store.ButtonAtlasInstance = Instance;
    return Instance != nullptr;
}
