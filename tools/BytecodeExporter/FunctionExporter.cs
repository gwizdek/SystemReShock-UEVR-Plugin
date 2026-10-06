using Newtonsoft.Json.Linq;
using UAssetAPI;
using UAssetAPI.ExportTypes;
using UAssetAPI.Kismet;

namespace BytecodeExporter;

/// <summary>Writes one .bytecode file per export that carries Blueprint script.</summary>
public static class FunctionExporter
{
    public static int Export(UAsset asset, string outputDirectory)
    {
        int count = 0;
        foreach (var export in asset.Exports.OfType<StructExport>())
        {
            if (export.ScriptBytecode is null || export.ScriptBytecode.Length == 0) continue;
            string file = Path.Combine(outputDirectory, JsonFile.SafeFileName(export.ObjectName.ToString()) + ".bytecode");
            JsonFile.Write(file, Describe(asset, export));
            count++;
        }
        return count;
    }

    private static JObject Describe(UAsset asset, StructExport export)
    {
        var json = new JObject
        {
            ["Name"] = export.ObjectName.ToString(),
            ["Outer"] = PackageIndexNames.Name(asset, export.OuterIndex),
            ["SuperStruct"] = PackageIndexNames.FullName(asset, export.SuperStruct),
        };
        if (export is FunctionExport function)
            json["FunctionFlags"] = function.FunctionFlags.ToString();

        var properties = export.LoadedProperties ?? [];
        json["Parameters"] = new JArray(properties.Where(PropertyDescriber.IsParameter).Select(PropertyDescriber.Describe));
        json["Locals"] = new JArray(properties.Where(p => !PropertyDescriber.IsParameter(p)).Select(PropertyDescriber.Describe));
        json["Script"] = Script(export);
        return json;
    }

    private static JToken Script(StructExport export)
    {
        try
        {
            return KismetSerializer.SerializeScript(export.ScriptBytecode);
        }
        catch (Exception e)
        {
            Console.Error.WriteLine($"  {export.ObjectName}: bytecode could not be serialized: {e.Message}");
            return new JObject { ["Error"] = e.ToString() };
        }
    }
}
