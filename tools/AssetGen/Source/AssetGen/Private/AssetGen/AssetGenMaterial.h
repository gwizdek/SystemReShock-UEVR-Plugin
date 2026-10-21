#pragma once

#include "CoreMinimal.h"
#include "Materials/Material.h"
#include "Materials/MaterialExpressionMultiply.h"

class UMaterialExpressionScalarParameter;
class UMaterialExpressionTextureSample;
class UMaterialExpressionTextureSampleParameter2D;
class UMaterialExpressionVectorParameter;
class UMaterialExpressionVertexColor;
class UTexture2D;

// Helpers for the generated UI materials and their textures. A UI material here is
// translucent and writes alpha, because UEVR composites the game's flat HUD onto its UI
// quad by alpha, and the game's additive HUD materials write none.
namespace AssetGenMaterial
{
// Outputs of a texture sample.
constexpr int32 OutRGB = 0;
constexpr int32 OutR = 1;
constexpr int32 OutG = 2;
constexpr int32 OutB = 3;
constexpr int32 OutA = 4;

// A PNG from the generator plugin's folder as a texture asset with the game's HUD texture
// settings: uncompressed BGRA8, UI texture group, one mip. Chunk ids as AssetGenAsset::Save.
UTexture2D* MakeTexture(const FString& PackagePath, const TCHAR* PngRelative, const TArray<int32>& ChunkIds);

// A new, empty UI-domain translucent material in a new package. Add expressions, then Save.
UMaterial* NewUiMaterial(const FString& PackagePath);

// Compiles the material and saves its package with the chunk ids.
bool Save(UMaterial* Material, const TArray<int32>& ChunkIds);

template <class ExpressionType>
ExpressionType* Add(UMaterial* Material, int32 X, int32 Y)
{
    auto* Expression = NewObject<ExpressionType>(Material);
    Expression->MaterialExpressionEditorX = X;
    Expression->MaterialExpressionEditorY = Y;
    Material->Expressions.Add(Expression);
    return Expression;
}

UMaterialExpressionMultiply* Multiply(UMaterial* Material, UMaterialExpression* A, int32 OutputA, UMaterialExpression* B, int32 OutputB, int32 X, int32 Y);
UMaterialExpressionMultiply* MultiplyConst(UMaterial* Material, UMaterialExpression* A, int32 OutputA, float ConstB, int32 X, int32 Y);
UMaterialExpressionScalarParameter* Scalar(UMaterial* Material, FName Name, float Default, int32 X, int32 Y);
UMaterialExpressionVectorParameter* Color(UMaterial* Material, FName Name, FLinearColor Default, int32 X, int32 Y);
UMaterialExpressionTextureSample* Sample(UMaterial* Material, UTexture2D* Texture, int32 X, int32 Y);
UMaterialExpressionTextureSampleParameter2D* SampleParameter(UMaterial* Material, FName Name, UTexture2D* Texture, int32 X, int32 Y);
UMaterialExpressionVertexColor* VertexColor(UMaterial* Material, int32 X, int32 Y);

// Connects colour and opacity, each multiplied by the vertex colour (RGB) and vertex alpha.
// The game's mesh widgets pass their Color as the vertex colour, so the game keeps its
// tints and fades.
void ConnectThroughVertexColor(UMaterial* Material, UMaterialExpression* Color, UMaterialExpression* Opacity, int32 OutputOpacity);
} // namespace AssetGenMaterial
