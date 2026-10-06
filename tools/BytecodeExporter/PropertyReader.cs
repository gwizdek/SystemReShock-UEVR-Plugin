using UAssetAPI;
using UAssetAPI.ExportTypes;
using UAssetAPI.PropertyTypes.Objects;

namespace BytecodeExporter;

/// <summary>Reads typed values out of a NormalExport's property list.</summary>
public static class PropertyReader
{
    public static string? NameValue(NormalExport export, string property) =>
        (Find(export, property) as NamePropertyData)?.Value.ToString();

    public static string? ObjectName(UAsset asset, NormalExport export, string property)
    {
        var index = (Find(export, property) as ObjectPropertyData)?.Value;
        return index is null ? null : PackageIndexNames.FullName(asset, index);
    }

    public static NormalExport? ObjectExport(UAsset asset, NormalExport export, string property)
    {
        var index = (Find(export, property) as ObjectPropertyData)?.Value;
        return index is not null && index.IsExport() ? index.ToExport(asset) as NormalExport : null;
    }

    public static IEnumerable<NormalExport> ObjectArray(UAsset asset, NormalExport? export, string property)
    {
        if (export is null) yield break;
        var array = Find(export, property) as ArrayPropertyData;
        if (array?.Value is null) yield break;
        foreach (var item in array.Value.OfType<ObjectPropertyData>())
            if (item.Value.IsExport() && item.Value.ToExport(asset) is NormalExport n) yield return n;
    }

    private static PropertyData? Find(NormalExport export, string property) =>
        export.Data?.FirstOrDefault(p => p.Name.ToString() == property);
}
