#include "CyberHudGen.h"

#include "AssetGen/AssetGenAsset.h"
#include "AssetGen/AssetGenContext.h"
#include "AssetGen/AssetGenMaterial.h"
#include "AssetGenLog.h"
#include "Engine/Texture2D.h"
#include "Materials/Material.h"
#include "Materials/MaterialExpressionAdd.h"
#include "Materials/MaterialExpressionAppendVector.h"
#include "Materials/MaterialExpressionClamp.h"
#include "Materials/MaterialExpressionCollectionParameter.h"
#include "Materials/MaterialExpressionComponentMask.h"
#include "Materials/MaterialExpressionConstant.h"
#include "Materials/MaterialExpressionConstant2Vector.h"
#include "Materials/MaterialExpressionDivide.h"
#include "Materials/MaterialExpressionFloor.h"
#include "Materials/MaterialExpressionFmod.h"
#include "Materials/MaterialExpressionFrac.h"
#include "Materials/MaterialExpressionMax.h"
#include "Materials/MaterialExpressionMin.h"
#include "Materials/MaterialExpressionOneMinus.h"
#include "Materials/MaterialExpressionSaturate.h"
#include "Materials/MaterialExpressionScalarParameter.h"
#include "Materials/MaterialExpressionTextureCoordinate.h"
#include "Materials/MaterialExpressionTextureSample.h"
#include "Materials/MaterialParameterCollection.h"

// The game's own asset paths of the four additive materials the Core pak replaces, and of
// their textures.
namespace CyberHudGenPaths
{
constexpr const TCHAR* GuiRoot = TEXT("/Game/Art/Cyberspace/GUI");
constexpr const TCHAR* ArchiveRoot = TEXT("/Game/Art/Cyberspace/GUI/zz_Archive");
constexpr const TCHAR* PanelTexture = TEXT("T_ConnectionIntegrityWindow");
constexpr const TCHAR* PanelMaterial = TEXT("MAT_ConnectionIntegrityPanel");
constexpr const TCHAR* HealthTexture = TEXT("T_ConnectionIntegrityHealth");
constexpr const TCHAR* HealthMaterial = TEXT("MAT_ConnectionIntegrityHealth");
constexpr const TCHAR* SecureTexture = TEXT("T_ConnectionStatusSecure");
constexpr const TCHAR* SecureMaterial = TEXT("MAT_ConnectionStatusSecure");
constexpr const TCHAR* ThreatTexture = TEXT("T_ConnectionStatusThreat");
constexpr const TCHAR* ThreatMaterial = TEXT("MAT_ConnectionStatusThreat");
// The game's textures as PNGs, relative to the generator plugin's folder. Written by
// export-cooked-texture.ps1 from the cooked assets.
constexpr const TCHAR* PanelSource = TEXT("Resources/CyberHud/T_ConnectionIntegrityWindow.png");
constexpr const TCHAR* HealthSource = TEXT("Resources/CyberHud/T_ConnectionIntegrityHealth.png");
constexpr const TCHAR* SecureSource = TEXT("Resources/CyberHud/T_ConnectionStatusSecure.png");
constexpr const TCHAR* ThreatSource = TEXT("Resources/CyberHud/T_ConnectionStatusThreat.png");
// Cyberspace HUD textures replaced at the game's paths in chunk 10, so the Core pak overrides
// them while the game's materials stay. The flight reticle keeps only its top triangle
// (make_flight_reticle.py); the drill lock-on's arcs and chevrons keep only a thin outline
// rim (make_ice_drill_reticle.py).
constexpr const TCHAR* ReticleTexture = TEXT("T_CyberspaceFlightReticle");
constexpr const TCHAR* ReticleSource = TEXT("Resources/CyberHud/T_CyberspaceFlightReticle.png");
constexpr const TCHAR* LockOnBracketTexture = TEXT("T_ICEDrillReticle_LockOnBracket");
constexpr const TCHAR* LockOnBracketSource = TEXT("Resources/CyberHud/T_ICEDrillReticle_LockOnBracket.png");
constexpr const TCHAR* LockOnPointerTexture = TEXT("T_ICEDrillReticle_LockOnPointer");
constexpr const TCHAR* LockOnPointerSource = TEXT("Resources/CyberHud/T_ICEDrillReticle_LockOnPointer.png");
} // namespace CyberHudGenPaths

namespace
{
using namespace AssetGenMaterial;

// Parameter names the widget's Blueprint sets on dynamic instances of these materials
// (WIDGET_ConnectionIntegrity, function "Set Integrity Value").
const FName HealthRatioParameter(TEXT("HealthRatio"));
const FName HealthGoodParameter(TEXT("HealthGood"));
const FName HealthCriticalParameter(TEXT("HealthCritical"));
const FName PanelOpacityParameter(TEXT("PanelOpacity"));
// The game's panel is the player's background tint, like the menu icons.
const FName PanelTint(TEXT("UIBackgroundTint1"));

// The health bar texture is a flipbook: 21 frames in 2 columns and 11 rows (the last slot is
// empty), left to right and top to bottom. Frame n has n dark segments, so frame 0 is the full
// bar and frame 20 the empty one.
constexpr float FlipbookColumns = 2.0f;
constexpr float FlipbookRows = 11.0f;
constexpr float FlipbookLastFrame = 20.0f;
const FName PanelFillOpacityParameter(TEXT("FillOpacity"));

struct FCyberAsset
{
    const TCHAR* Texture;
    const TCHAR* TextureSource;
    const TCHAR* Material;
};

const FCyberAsset Panel{ CyberHudGenPaths::PanelTexture, CyberHudGenPaths::PanelSource, CyberHudGenPaths::PanelMaterial };
const FCyberAsset Health{ CyberHudGenPaths::HealthTexture, CyberHudGenPaths::HealthSource, CyberHudGenPaths::HealthMaterial };
const FCyberAsset Secure{ CyberHudGenPaths::SecureTexture, CyberHudGenPaths::SecureSource, CyberHudGenPaths::SecureMaterial };
const FCyberAsset Threat{ CyberHudGenPaths::ThreatTexture, CyberHudGenPaths::ThreatSource, CyberHudGenPaths::ThreatMaterial };

// The texture is a stand-in in chunk 0: never shipped, only there so the material can refer
// to the game's path.
UTexture2D* MakeStandInTexture(const FAssetGenContext& Context, const TCHAR* Root, const FCyberAsset& Asset)
{
    const FString Path = FString(Root) / Asset.Texture;
    if (AssetGenAsset::Exists(Path) && !Context.bOverwrite) return AssetGenAsset::LoadExisting<UTexture2D>(Path);
    return MakeTexture(Path, Asset.TextureSource, {});
}

// Textures shipped at the game's paths: the game's materials stay and sample these instead.
// The flight reticle's holds only the ring's top triangle, the "up" marker the plugin turns
// to world up. The drill lock-on's arcs and chevrons keep only a thin rim of their outline
// band (B), which looked like a thick outline in VR.
struct FReplacedTexture
{
    const TCHAR* Texture;
    const TCHAR* Source;
};

const FReplacedTexture ReplacedTextures[] = {
    { CyberHudGenPaths::ReticleTexture, CyberHudGenPaths::ReticleSource },
    { CyberHudGenPaths::LockOnBracketTexture, CyberHudGenPaths::LockOnBracketSource },
    { CyberHudGenPaths::LockOnPointerTexture, CyberHudGenPaths::LockOnPointerSource },
};

bool MakeReplacedTextures(const FAssetGenContext& Context)
{
    for (const FReplacedTexture& Replaced : ReplacedTextures)
    {
        const FString Path = FString(CyberHudGenPaths::GuiRoot) / Replaced.Texture;
        if (AssetGenAsset::Exists(Path) && !Context.bOverwrite) continue;
        if (MakeTexture(Path, Replaced.Source, { AssetGen::ModChunk }) == nullptr) return false;
    }
    return true;
}

// Returns the existing material when it is kept, or a new empty one to fill. bNew tells which.
UMaterial* BeginMaterial(const FAssetGenContext& Context, const TCHAR* Root, const FCyberAsset& Asset, bool& bNew)
{
    const FString Path = FString(Root) / Asset.Material;
    bNew = !(AssetGenAsset::Exists(Path) && !Context.bOverwrite);
    return bNew ? NewUiMaterial(Path) : AssetGenAsset::LoadExisting<UMaterial>(Path);
}

// The panel texture: G is the fill gradient (bright left, dark right), R and B are the two
// edge lines, A the shape. Colour = tint * (R + G + B). Opacity = (lines + fill * FillOpacity)
// * A * PanelOpacity: the lines stay solid, the fill is see-through and fades out to the
// right as it does with the game's additive draw, and the label on top of it stays readable.
UMaterial* MakePanelMaterial(const FAssetGenContext& Context, UTexture2D* Texture, UMaterialParameterCollection* Collection)
{
    bool bNew = false;
    UMaterial* Material = BeginMaterial(Context, CyberHudGenPaths::GuiRoot, Panel, bNew);
    if (Material == nullptr || !bNew) return Material;

    auto* Window = Sample(Material, Texture, -800, 0);
    auto* EdgeAndFill = Add<UMaterialExpressionAdd>(Material, -600, 0);
    EdgeAndFill->A.Connect(OutR, Window);
    EdgeAndFill->B.Connect(OutG, Window);
    auto* Lines = Add<UMaterialExpressionAdd>(Material, -450, 0);
    Lines->A.Connect(0, EdgeAndFill);
    Lines->B.Connect(OutB, Window);
    auto* Shape = Add<UMaterialExpressionSaturate>(Material, -300, 0);
    Shape->Input.Connect(0, Lines);

    auto* Tint = Add<UMaterialExpressionCollectionParameter>(Material, -600, 200);
    Tint->Collection = Collection;
    Tint->ParameterName = PanelTint;
    Tint->ParameterId = Collection->GetParameterId(PanelTint);
    // The collection gives a float4; the vertex colour it is multiplied with later is a float3.
    auto* TintRgb = Add<UMaterialExpressionComponentMask>(Material, -450, 200);
    TintRgb->Input.Connect(0, Tint);
    TintRgb->R = true;
    TintRgb->G = true;
    TintRgb->B = true;
    auto* PanelColor = Multiply(Material, TintRgb, 0, Shape, 0, -100, 0);

    auto* EdgeLines = Add<UMaterialExpressionAdd>(Material, -600, 400);
    EdgeLines->A.Connect(OutR, Window);
    EdgeLines->B.Connect(OutB, Window);
    auto* FillOpacity = Scalar(Material, PanelFillOpacityParameter, 0.35f, -750, 550);
    auto* DimFill = Multiply(Material, Window, OutG, FillOpacity, 0, -600, 550);
    auto* Coverage = Add<UMaterialExpressionAdd>(Material, -450, 450);
    Coverage->A.Connect(0, EdgeLines);
    Coverage->B.Connect(0, DimFill);
    auto* PanelOpacity = Scalar(Material, PanelOpacityParameter, 0.9f, -450, 650);
    auto* ShapeAlpha = Multiply(Material, Window, OutA, Coverage, 0, -300, 450);
    auto* Alpha = Multiply(Material, ShapeAlpha, 0, PanelOpacity, 0, -100, 450);

    ConnectThroughVertexColor(Material, PanelColor, Alpha, 0);
    return Save(Material, { AssetGen::ModChunk }) ? Material : nullptr;
}

// UVs of the flipbook frame for the health ratio: frame = round((1 - ratio) * 20), at most 20,
// column = frame mod 2, row = floor(frame / 2), uv = (frac(uv) + (column, row)) / (2, 11).
// frac, because the game's mesh widget passes V outside 0..1 (it runs from -1 to 0); texture
// wrapping hides that for a plain sample but not for a frame offset.
UMaterialExpression* MakeFlipbookUVs(UMaterial* Material, UMaterialExpression* Ratio)
{
    auto* Clamped = Add<UMaterialExpressionClamp>(Material, -1400, 200);
    Clamped->Input.Connect(0, Ratio);
    auto* Phase = Add<UMaterialExpressionOneMinus>(Material, -1250, 200);
    Phase->Input.Connect(0, Clamped);
    auto* Scaled = MultiplyConst(Material, Phase, 0, FlipbookLastFrame, -1100, 200);
    auto* Rounded = Add<UMaterialExpressionAdd>(Material, -1000, 200);
    Rounded->A.Connect(0, Scaled);
    Rounded->ConstB = 0.5f;
    auto* Last = Add<UMaterialExpressionMin>(Material, -950, 200);
    Last->A.Connect(0, Rounded);
    Last->ConstB = FlipbookLastFrame;
    auto* Frame = Add<UMaterialExpressionFloor>(Material, -800, 200);
    Frame->Input.Connect(0, Last);

    auto* Columns = Add<UMaterialExpressionConstant>(Material, -800, 350);
    Columns->R = FlipbookColumns;
    auto* Column = Add<UMaterialExpressionFmod>(Material, -650, 200);
    Column->A.Connect(0, Frame);
    Column->B.Connect(0, Columns);
    auto* RowFraction = Add<UMaterialExpressionDivide>(Material, -650, 300);
    RowFraction->A.Connect(0, Frame);
    RowFraction->ConstB = FlipbookColumns;
    auto* Row = Add<UMaterialExpressionFloor>(Material, -500, 300);
    Row->Input.Connect(0, RowFraction);
    auto* Offset = Add<UMaterialExpressionAppendVector>(Material, -350, 250);
    Offset->A.Connect(0, Column);
    Offset->B.Connect(0, Row);

    auto* Coordinates = Add<UMaterialExpressionTextureCoordinate>(Material, -500, 100);
    auto* Wrapped = Add<UMaterialExpressionFrac>(Material, -350, 100);
    Wrapped->Input.Connect(0, Coordinates);
    auto* Shifted = Add<UMaterialExpressionAdd>(Material, -200, 150);
    Shifted->A.Connect(0, Wrapped);
    Shifted->B.Connect(0, Offset);
    auto* Grid = Add<UMaterialExpressionConstant2Vector>(Material, -200, 300);
    Grid->R = FlipbookColumns;
    Grid->G = FlipbookRows;
    auto* UVs = Add<UMaterialExpressionDivide>(Material, -50, 200);
    UVs->A.Connect(0, Shifted);
    UVs->B.Connect(0, Grid);
    return UVs;
}

// The health bar: the flipbook frame picked by HealthRatio, drawn as it is in the texture.
// The texture's alpha is 1 everywhere, so the opacity is the brightest channel: black stays
// see-through, dark segments show dimly, lit ones fully, as with the game's additive draw.
UMaterial* MakeHealthMaterial(const FAssetGenContext& Context, UTexture2D* Texture)
{
    bool bNew = false;
    UMaterial* Material = BeginMaterial(Context, CyberHudGenPaths::GuiRoot, Health, bNew);
    if (Material == nullptr || !bNew) return Material;

    auto* Ratio = Scalar(Material, HealthRatioParameter, 1.0f, -1600, 200);
    UMaterialExpression* UVs = MakeFlipbookUVs(Material, Ratio);
    auto* Bar = Sample(Material, Texture, 100, 100);
    Bar->Coordinates.Connect(0, UVs);
    auto* RedOrGreen = Add<UMaterialExpressionMax>(Material, 300, 300);
    RedOrGreen->A.Connect(OutR, Bar);
    RedOrGreen->B.Connect(OutG, Bar);
    auto* Brightest = Add<UMaterialExpressionMax>(Material, 450, 300);
    Brightest->A.Connect(0, RedOrGreen);
    Brightest->B.Connect(OutB, Bar);
    ConnectThroughVertexColor(Material, Bar, Brightest, 0);
    return Save(Material, { AssetGen::ModChunk }) ? Material : nullptr;
}

// A status tag: the texture as it is, shown when its switch parameter is 1 and hidden at 0.
UMaterial* MakeTagMaterial(const FAssetGenContext& Context, const FCyberAsset& Asset, UTexture2D* Texture, FName Switch)
{
    bool bNew = false;
    UMaterial* Material = BeginMaterial(Context, CyberHudGenPaths::ArchiveRoot, Asset, bNew);
    if (Material == nullptr || !bNew) return Material;

    auto* Tag = Sample(Material, Texture, -600, 0);
    auto* Shown = Scalar(Material, Switch, 0.0f, -600, 300);
    auto* Alpha = Multiply(Material, Tag, OutA, Shown, 0, -300, 300);
    ConnectThroughVertexColor(Material, Tag, Alpha, 0);
    return Save(Material, { AssetGen::ModChunk }) ? Material : nullptr;
}
} // namespace

bool CyberHudGen::Generate(const FAssetGenContext& Context)
{
    if (Context.TintCollection == nullptr)
    {
        UE_LOG(LogAssetGen, Error, TEXT("The tint collection must be generated first"));
        return false;
    }
    UTexture2D* PanelTexture = MakeStandInTexture(Context, CyberHudGenPaths::GuiRoot, Panel);
    UTexture2D* HealthTexture = MakeStandInTexture(Context, CyberHudGenPaths::GuiRoot, Health);
    UTexture2D* SecureTexture = MakeStandInTexture(Context, CyberHudGenPaths::ArchiveRoot, Secure);
    UTexture2D* ThreatTexture = MakeStandInTexture(Context, CyberHudGenPaths::ArchiveRoot, Threat);
    if (PanelTexture == nullptr || HealthTexture == nullptr || SecureTexture == nullptr || ThreatTexture == nullptr) return false;

    const bool bOk =
        MakePanelMaterial(Context, PanelTexture, Context.TintCollection) != nullptr &&
        MakeHealthMaterial(Context, HealthTexture) != nullptr &&
        MakeTagMaterial(Context, Secure, SecureTexture, HealthGoodParameter) != nullptr &&
        MakeTagMaterial(Context, Threat, ThreatTexture, HealthCriticalParameter) != nullptr &&
        MakeReplacedTextures(Context);
    return bOk;
}
