#include "HudIconGen.h"

#include "AssetGen/AssetGenAsset.h"
#include "AssetGen/AssetGenContext.h"
#include "AssetGen/AssetGenMaterial.h"
#include "AssetGenLog.h"
#include "Engine/Texture2D.h"
#include "Materials/Material.h"
#include "Materials/MaterialExpressionAdd.h"
#include "Materials/MaterialExpressionScalarParameter.h"
#include "Materials/MaterialExpressionTextureSampleParameter2D.h"
#include "Materials/MaterialExpressionVectorParameter.h"

// The game's own asset paths: the mod pak mounts above the game's, so its copies replace the
// game's material and texture, and the game's HUD widget draws the icon with them. Nothing in
// the plugin loads them.
namespace HudIconGenPaths
{
constexpr const TCHAR* Root = TEXT("/Game/Art/UI/HUD/Media");
constexpr const TCHAR* Texture = TEXT("T_MediaIcon_UnreadMessages");
constexpr const TCHAR* Material = TEXT("MAT_MediaIcon_UnreadMessages");
// The game's envelope texture as a PNG, relative to the generator plugin's folder. Written by
// make_media_icon.ps1 next to it from the cooked T_MediaIcon_UnreadMessages, with the glow
// outside the envelope reduced.
constexpr const TCHAR* Source = TEXT("Resources/HudIcon/T_MediaIcon_UnreadMessages_VR.png");
} // namespace HudIconGenPaths

namespace
{
using namespace AssetGenMaterial;

// The game's envelope texture: R is the crisp outline, G a soft fill with a glow around the
// envelope. The game draws it additively, which looks like a bright orange outline over a dim
// dark red fill. These defaults copy that look; the plugin can change them on a dynamic instance.
// Linear values: 0.12 red shows as about 95 of 255 on screen. Tuned in the running game
// against the original icon.
const FName IconParameter(TEXT("Icon"));
const FName OutlineColorParameter(TEXT("OutlineColor"));
const FName FillColorParameter(TEXT("FillColor"));
const FName FillOpacityParameter(TEXT("FillOpacity"));
const FLinearColor OutlineColorDefault(1.0f, 0.38f, 0.04f, 1.0f);
const FLinearColor FillColorDefault(0.12f, 0.008f, 0.0f, 1.0f);
constexpr float FillOpacityDefault = 0.35f;

UTexture2D* MakeEnvelopeTexture(const FAssetGenContext& Context)
{
    const FString Path = FString(HudIconGenPaths::Root) / HudIconGenPaths::Texture;
    if (AssetGenAsset::Exists(Path) && !Context.bOverwrite) return AssetGenAsset::LoadExisting<UTexture2D>(Path);
    return MakeTexture(Path, HudIconGenPaths::Source, { AssetGen::ModChunk });
}

// Emissive = (R * OutlineColor + G * FillColor) * vertex colour. Opacity = (R + G * FillOpacity)
// * vertex alpha; the renderer clamps it. The texture is a parameter.
UMaterial* MakeEnvelopeMaterial(const FAssetGenContext& Context, UTexture2D* Texture)
{
    const FString Path = FString(HudIconGenPaths::Root) / HudIconGenPaths::Material;
    if (AssetGenAsset::Exists(Path) && !Context.bOverwrite) return AssetGenAsset::LoadExisting<UMaterial>(Path);

    UMaterial* Material = NewUiMaterial(Path);
    auto* Icon = SampleParameter(Material, IconParameter, Texture, -600, 0);
    auto* OutlineColor = Color(Material, OutlineColorParameter, OutlineColorDefault, -600, 300);
    auto* FillColor = Color(Material, FillColorParameter, FillColorDefault, -600, 450);
    auto* FillOpacity = Scalar(Material, FillOpacityParameter, FillOpacityDefault, -600, 600);

    auto* Outline = Multiply(Material, Icon, OutR, OutlineColor, 0, -300, 0);
    auto* Fill = Multiply(Material, Icon, OutG, FillColor, 0, -300, 150);
    auto* IconColor = Add<UMaterialExpressionAdd>(Material, -100, 0);
    IconColor->A.Connect(0, Outline);
    IconColor->B.Connect(0, Fill);

    auto* FillAlpha = Multiply(Material, Icon, OutG, FillOpacity, 0, -300, 400);
    auto* Alpha = Add<UMaterialExpressionAdd>(Material, -100, 400);
    Alpha->A.Connect(OutR, Icon);
    Alpha->B.Connect(0, FillAlpha);

    ConnectThroughVertexColor(Material, IconColor, Alpha, 0);
    return Save(Material, { AssetGen::ModChunk }) ? Material : nullptr;
}
} // namespace

bool HudIconGen::Generate(const FAssetGenContext& Context)
{
    UTexture2D* Texture = MakeEnvelopeTexture(Context);
    return Texture != nullptr && MakeEnvelopeMaterial(Context, Texture) != nullptr;
}
