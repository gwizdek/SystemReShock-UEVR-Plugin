using UAssetAPI;
using UAssetAPI.UnrealTypes;

namespace BytecodeExporter;

/// <summary>Resolves FPackageIndex values to readable names.</summary>
public static class PackageIndexNames
{
    public static string? Name(UAsset asset, FPackageIndex index)
    {
        if (index.IsNull()) return null;
        if (index.IsImport()) return index.ToImport(asset).ObjectName.ToString();
        return index.ToExport(asset).ObjectName.ToString();
    }

    /// <summary>Full path for imports (package + object), plain name for exports.</summary>
    public static string? FullName(UAsset asset, FPackageIndex index)
    {
        if (index.IsNull()) return null;
        if (!index.IsImport()) return index.ToExport(asset).ObjectName.ToString();

        var import = index.ToImport(asset);
        string? outer = FullName(asset, import.OuterIndex);
        string name = import.ObjectName.ToString();
        return outer is null ? name : outer + "." + name;
    }
}
