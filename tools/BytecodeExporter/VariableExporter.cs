using Newtonsoft.Json.Linq;
using UAssetAPI;
using UAssetAPI.ExportTypes;

namespace BytecodeExporter;

/// <summary>Writes variables.json: every class variable with its type and default value.</summary>
public static class VariableExporter
{
    public static int Export(UAsset asset, string outputDirectory)
    {
        var classExport = asset.Exports.OfType<ClassExport>().FirstOrDefault();
        if (classExport is null) return 0;

        var defaults = DefaultObject(asset, classExport);
        var variables = new JArray();
        foreach (var property in classExport.LoadedProperties ?? [])
        {
            var json = PropertyDescriber.Describe(property);
            json["DefaultValue"] = DefaultValue(asset, defaults, property.Name.ToString());
            variables.Add(json);
        }

        JsonFile.Write(Path.Combine(outputDirectory, "variables.json"), new JObject
        {
            ["Class"] = classExport.ObjectName.ToString(),
            ["DefaultObject"] = defaults?.ObjectName.ToString(),
            ["Variables"] = variables,
        });
        return variables.Count;
    }

    private static NormalExport? DefaultObject(UAsset asset, ClassExport classExport)
    {
        if (!classExport.ClassDefaultObject.IsExport()) return null;
        return classExport.ClassDefaultObject.ToExport(asset) as NormalExport;
    }

    private static JToken DefaultValue(UAsset asset, NormalExport? defaults, string name)
    {
        var data = defaults?.Data?.Where(p => p.Name.ToString() == name).ToList();
        if (data is null || data.Count == 0) return JValue.CreateNull();
        if (data.Count == 1) return JsonFile.FromAssetObject(asset, data[0]);
        return new JArray(data.Select(p => JsonFile.FromAssetObject(asset, p)));
    }
}
