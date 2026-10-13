#include "MenuGenHudIcon.h"

#include "BridgeGenLog.h"
#include "Engine/Texture2D.h"
#include "Materials/Material.h"
#include "Materials/MaterialExpressionAdd.h"
#include "Materials/MaterialExpressionScalarParameter.h"
#include "Materials/MaterialExpressionTextureSampleParameter2D.h"
#include "Materials/MaterialExpressionVectorParameter.h"
#include "MenuGenAsset.h"
#include "MenuGenMaterial.h"
#include "MenuGenStore.h"

namespace
{
using namespace MenuGenMaterial;

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

UTexture2D* MakeEnvelopeTexture(const FMenuGenOptions& Options)
{
    const FString Path = FString(MenuGenPaths::HudIconRoot) / MenuGenPaths::HudIconTexture;
    if (MenuGenAsset::Exists(Path) && !Options.bOverwrite) return MenuGenAsset::LoadExisting<UTexture2D>(Path);
    return MakeTexture(Path, MenuGenPaths::HudIconSource, { MenuGenPaths::ModChunk });
}

// Emissive = (R * OutlineColor + G * FillColor) * vertex colour. Opacity = (R + G * FillOpacity)
// * vertex alpha; the renderer clamps it. The texture is a parameter.
UMaterial* MakeEnvelopeMaterial(const FMenuGenOptions& Options, UTexture2D* Texture)
{
    const FString Path = FString(MenuGenPaths::HudIconRoot) / MenuGenPaths::HudIconMaterial;
    if (MenuGenAsset::Exists(Path) && !Options.bOverwrite) return MenuGenAsset::LoadExisting<UMaterial>(Path);

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
    return Save(Material, { MenuGenPaths::ModChunk }) ? Material : nullptr;
}
} // namespace

bool MenuGenHudIcon::Generate(FMenuGenStore& Store, const FMenuGenOptions& Options)
{
    UTexture2D* Texture = MakeEnvelopeTexture(Options);
    UMaterial* Material = Texture != nullptr ? MakeEnvelopeMaterial(Options, Texture) : nullptr;
    Store.HudIconMaterial = Material;
    return Material != nullptr;
}
