#include "AssetGenTint.h"

#include "AssetGenAsset.h"
#include "Materials/MaterialParameterCollection.h"

namespace
{
const TCHAR* TintCollectionPath = TEXT("/Game/Blueprints/UI/Tinting/MPC_UserTintParameters");

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
} // namespace

UMaterialParameterCollection* AssetGenTint::MakeCollection(bool bOverwrite)
{
    const FString Path = TintCollectionPath;
    if (AssetGenAsset::Exists(Path) && !bOverwrite) return AssetGenAsset::LoadExisting<UMaterialParameterCollection>(Path);

    UPackage* Package = AssetGenAsset::NewPackage(Path);
    AssetGenAsset::Evict(Package, AssetGenAsset::NameOf(Path));
    auto* Collection = NewObject<UMaterialParameterCollection>(Package, *AssetGenAsset::NameOf(Path), RF_Public | RF_Standalone);
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
    return AssetGenAsset::Save(Collection, {}) ? Collection : nullptr;
}
