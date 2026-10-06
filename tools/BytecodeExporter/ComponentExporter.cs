using Newtonsoft.Json.Linq;
using UAssetAPI;
using UAssetAPI.ExportTypes;
using UAssetAPI.PropertyTypes.Objects;

namespace BytecodeExporter;

/// <summary>Writes components.json: the construction script tree and every component template.</summary>
public static class ComponentExporter
{
    public static int Export(UAsset asset, string outputDirectory)
    {
        var scsNodes = asset.Exports.OfType<NormalExport>()
            .Where(e => e.GetExportClassType().ToString() == "SCS_Node").ToList();
        var inScs = new HashSet<int>();
        var tree = new JArray(RootNodes(asset, scsNodes).Select(n => DescribeNode(asset, n, inScs)));

        var others = asset.Exports.Select((e, i) => (export: e, index: i + 1))
            .Where(x => x.export is NormalExport n && !inScs.Contains(x.index) && LooksLikeComponent(asset, n))
            .Select(x => DescribeTemplate(asset, (NormalExport)x.export))
            .ToList();

        JsonFile.Write(Path.Combine(outputDirectory, "components.json"), new JObject
        {
            ["SimpleConstructionScript"] = tree,
            ["OtherComponents"] = new JArray(others),
        });
        return inScs.Count + others.Count;
    }

    private static IEnumerable<NormalExport> RootNodes(UAsset asset, List<NormalExport> scsNodes)
    {
        var scs = asset.Exports.OfType<NormalExport>()
            .FirstOrDefault(e => e.GetExportClassType().ToString() == "SimpleConstructionScript");
        var roots = PropertyReader.ObjectArray(asset, scs, "RootNodes").ToList();
        return roots.Count > 0 ? roots : scsNodes;
    }

    private static JObject DescribeNode(UAsset asset, NormalExport node, HashSet<int> inScs)
    {
        var json = new JObject
        {
            ["Node"] = node.ObjectName.ToString(),
            ["VariableName"] = PropertyReader.NameValue(node, "InternalVariableName"),
            ["ComponentClass"] = PropertyReader.ObjectName(asset, node, "ComponentClass"),
            ["AttachToName"] = PropertyReader.NameValue(node, "AttachToName"),
            ["ParentComponentOrVariableName"] = PropertyReader.NameValue(node, "ParentComponentOrVariableName"),
        };
        var template = PropertyReader.ObjectExport(asset, node, "ComponentTemplate");
        if (template is not null)
        {
            inScs.Add(asset.Exports.IndexOf(template) + 1);
            json["Template"] = DescribeTemplate(asset, template);
        }
        var children = PropertyReader.ObjectArray(asset, node, "ChildNodes");
        json["ChildNodes"] = new JArray(children.Select(c => DescribeNode(asset, c, inScs)));
        return json;
    }

    private static JObject DescribeTemplate(UAsset asset, NormalExport export) => new()
    {
        ["Name"] = export.ObjectName.ToString(),
        ["Class"] = PackageIndexNames.FullName(asset, export.ClassIndex),
        ["Outer"] = PackageIndexNames.Name(asset, export.OuterIndex),
        ["Properties"] = new JArray((export.Data ?? []).Select(p => JsonFile.FromAssetObject(asset, p))),
    };

    private static bool LooksLikeComponent(UAsset asset, NormalExport export)
    {
        string name = export.ObjectName.ToString();
        string type = export.GetExportClassType().ToString();
        if (name.EndsWith("_GEN_VARIABLE") || name.StartsWith("NODE_Add")) return true;
        if (type.EndsWith("Component")) return true;
        return export.OuterIndex.IsExport() && IsDefaultObject(asset, export.OuterIndex.ToExport(asset));
    }

    private static bool IsDefaultObject(UAsset asset, Export export) =>
        asset.Exports.OfType<ClassExport>()
            .Any(c => c.ClassDefaultObject.IsExport() && c.ClassDefaultObject.ToExport(asset) == export);
}
