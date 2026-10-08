using Newtonsoft.Json.Linq;
using UAssetAPI;
using UAssetAPI.ExportTypes;

namespace BytecodeExporter;

/// <summary>Writes widgets.json: the widget tree of a UMG widget Blueprint, its animations and delegate bindings.</summary>
public static class WidgetTreeExporter
{
    private static readonly HashSet<string> WidgetLinks = ["Slot", "Slots"];
    private static readonly HashSet<string> SlotLinks = ["Parent", "Content"];

    public static int Export(UAsset asset, string outputDirectory)
    {
        var tree = ExportsOfClass(asset, "WidgetTree").FirstOrDefault();
        if (tree is null) return 0;

        var visited = new List<string>();
        var root = PropertyReader.ObjectExport(asset, tree, "RootWidget");
        var json = new JObject
        {
            ["RootWidget"] = root is null ? JValue.CreateNull() : DescribeWidget(asset, root, visited),
            ["Animations"] = new JArray(ExportsOfClass(asset, "WidgetAnimation").Select(a => DescribeAnimation(asset, a))),
            ["DelegateBindings"] = new JArray(ExportsOfClass(asset, "ComponentDelegateBinding").Select(b => Properties(asset, b, []))),
        };
        JsonFile.Write(Path.Combine(outputDirectory, "widgets.json"), json);
        return visited.Count;
    }

    private static JObject DescribeWidget(UAsset asset, NormalExport widget, List<string> visited)
    {
        visited.Add(widget.ObjectName.ToString());
        var json = new JObject
        {
            ["Name"] = widget.ObjectName.ToString(),
            ["Class"] = PackageIndexNames.FullName(asset, widget.ClassIndex),
        };
        var slot = PropertyReader.ObjectExport(asset, widget, "Slot");
        if (slot is not null) json["Slot"] = DescribeSlot(asset, slot);
        json["Properties"] = Properties(asset, widget, WidgetLinks);
        json["Children"] = new JArray(Children(asset, widget).Select(c => DescribeWidget(asset, c, visited)));
        return json;
    }

    private static JObject DescribeSlot(UAsset asset, NormalExport slot) => new()
    {
        ["Class"] = PackageIndexNames.FullName(asset, slot.ClassIndex),
        ["Properties"] = Properties(asset, slot, SlotLinks),
    };

    /// <summary>Child widgets in slot order. Every panel, including content widgets such as Border and Button, lists its slots in Slots.</summary>
    private static IEnumerable<NormalExport> Children(UAsset asset, NormalExport panel)
    {
        foreach (var slot in PropertyReader.ObjectArray(asset, panel, "Slots"))
        {
            var content = PropertyReader.ObjectExport(asset, slot, "Content");
            if (content is not null) yield return content;
        }
    }

    private static JObject DescribeAnimation(UAsset asset, NormalExport animation)
    {
        var scene = PropertyReader.ObjectExport(asset, animation, "MovieScene");
        return new JObject
        {
            ["Name"] = animation.ObjectName.ToString(),
            ["Properties"] = Properties(asset, animation, ["MovieScene"]),
            ["MovieScene"] = scene is null ? JValue.CreateNull() : Properties(asset, scene, []),
            ["Tracks"] = scene is null ? new JArray() : new JArray(OwnedBy(asset, scene).Select(t => DescribeTrack(asset, t))),
        };
    }

    private static JObject DescribeTrack(UAsset asset, NormalExport track) => new()
    {
        ["Name"] = track.ObjectName.ToString(),
        ["Class"] = PackageIndexNames.FullName(asset, track.ClassIndex),
        ["Properties"] = Properties(asset, track, []),
        ["Sections"] = new JArray(OwnedBy(asset, track).Select(s => new JObject
        {
            ["Name"] = s.ObjectName.ToString(),
            ["Class"] = PackageIndexNames.FullName(asset, s.ClassIndex),
            ["Properties"] = Properties(asset, s, []),
        })),
    };

    private static JArray Properties(UAsset asset, NormalExport export, HashSet<string> skip) =>
        new((export.Data ?? []).Where(p => !skip.Contains(p.Name.ToString())).Select(p => JsonFile.FromAssetObject(asset, p)));

    private static IEnumerable<NormalExport> ExportsOfClass(UAsset asset, string className) =>
        asset.Exports.OfType<NormalExport>().Where(e => e.GetExportClassType().ToString() == className);

    private static IEnumerable<NormalExport> OwnedBy(UAsset asset, NormalExport outer) =>
        asset.Exports.OfType<NormalExport>().Where(e => e.OuterIndex.IsExport() && e.OuterIndex.ToExport(asset) == outer);
}
