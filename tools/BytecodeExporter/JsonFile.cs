using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
using UAssetAPI;

namespace BytecodeExporter;

/// <summary>Writes JSON tokens to disk as pretty, indented text.</summary>
public static class JsonFile
{
    public static void Write(string path, JToken content)
    {
        Directory.CreateDirectory(Path.GetDirectoryName(path)!);
        File.WriteAllText(path, content.ToString(Formatting.Indented));
    }

    /// <summary>Serializes any UAssetAPI object with the asset's own JSON converters.</summary>
    public static JToken FromAssetObject(UAsset asset, object? value)
    {
        if (value is null) return JValue.CreateNull();
        return ObjectReferences.Annotate(asset, JToken.Parse(asset.SerializeJsonObject(value, false)));
    }

    /// <summary>Turns a name into something that is safe to use as a file name.</summary>
    public static string SafeFileName(string name)
    {
        var invalid = Path.GetInvalidFileNameChars();
        return string.Concat(name.Select(c => invalid.Contains(c) ? '_' : c));
    }
}
