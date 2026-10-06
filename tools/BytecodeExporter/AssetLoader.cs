using UAssetAPI;
using UAssetAPI.Kismet;
using UAssetAPI.Unversioned;

namespace BytecodeExporter;

/// <summary>Opens a .uasset with UAssetAPI and prepares the KismetSerializer for it.</summary>
public static class AssetLoader
{
    public static UAsset Load(ExportOptions options)
    {
        if (!File.Exists(options.AssetPath))
            throw new FileNotFoundException("Asset not found", options.AssetPath);

        Usmap? mappings = options.MappingsPath is null ? null : new Usmap(options.MappingsPath);
        var asset = new UAsset(options.AssetPath, options.EngineVersion, mappings);
        KismetSerializer.asset = asset;
        return asset;
    }
}
