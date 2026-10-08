using Newtonsoft.Json.Linq;
using UAssetAPI;
using UAssetAPI.ExportTypes;

namespace BytecodeExporter;

/// <summary>Writes enums.json: every enum in the package with its entries, values and display names.</summary>
public static class EnumExporter
{
    public static int Export(UAsset asset, string outputDirectory)
    {
        var enums = asset.Exports.OfType<EnumExport>().ToList();
        if (enums.Count == 0) return 0;
        JsonFile.Write(Path.Combine(outputDirectory, "enums.json"), new JArray(enums.Select(e => Describe(asset, e))));
        return enums.Count;
    }

    private static JObject Describe(UAsset asset, EnumExport e) => new()
    {
        ["Name"] = e.ObjectName.ToString(),
        ["CppForm"] = e.Enum.CppForm.ToString(),
        ["Names"] = new JArray(e.Enum.Names.Select(n => new JObject { ["Name"] = n.Item1.ToString(), ["Value"] = n.Item2 })),
        ["Properties"] = new JArray((e.Data ?? []).Select(p => JsonFile.FromAssetObject(asset, p))),
    };
}
