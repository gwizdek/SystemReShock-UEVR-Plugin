using Newtonsoft.Json.Linq;
using UAssetAPI;
using UAssetAPI.ExportTypes;
using UAssetAPI.UnrealTypes;

namespace BytecodeExporter;

/// <summary>Writes class.json: the generated class header and an index of every export in the package.</summary>
public static class ClassSummaryExporter
{
    public static void Export(UAsset asset, string outputDirectory)
    {
        var json = new JObject
        {
            ["Asset"] = Path.GetFileName(asset.FilePath),
            ["EngineVersion"] = asset.GetEngineVersion().ToString(),
            ["Classes"] = new JArray(asset.Exports.OfType<ClassExport>().Select(c => DescribeClass(asset, c))),
            ["Exports"] = new JArray(asset.Exports.Select((e, i) => DescribeExport(asset, e, i + 1))),
        };
        JsonFile.Write(Path.Combine(outputDirectory, "class.json"), json);
    }

    private static JObject DescribeClass(UAsset asset, ClassExport c) => new()
    {
        ["Name"] = c.ObjectName.ToString(),
        ["SuperStruct"] = PackageIndexNames.FullName(asset, c.SuperStruct),
        ["ClassFlags"] = c.ClassFlags.ToString(),
        ["ClassWithin"] = PackageIndexNames.FullName(asset, c.ClassWithin),
        ["ClassConfigName"] = c.ClassConfigName.ToString(),
        ["ClassDefaultObject"] = PackageIndexNames.Name(asset, c.ClassDefaultObject),
        ["Interfaces"] = new JArray(c.Interfaces.Select(i => PackageIndexNames.FullName(asset, new FPackageIndex(i.Class)))),
        ["Functions"] = new JArray(c.FuncMap.Select(f => f.Key.ToString())),
        ["Children"] = new JArray(c.Children.Select(ch => PackageIndexNames.Name(asset, ch))),
    };

    private static JObject DescribeExport(UAsset asset, Export e, int index) => new()
    {
        ["Index"] = index,
        ["Name"] = e.ObjectName.ToString(),
        ["Class"] = PackageIndexNames.FullName(asset, e.ClassIndex),
        ["Outer"] = PackageIndexNames.Name(asset, e.OuterIndex),
        ["Kind"] = e.GetType().Name,
    };
}
