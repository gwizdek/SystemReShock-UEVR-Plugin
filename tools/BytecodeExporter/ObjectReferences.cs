using Newtonsoft.Json.Linq;
using UAssetAPI;
using UAssetAPI.UnrealTypes;

namespace BytecodeExporter;

/// <summary>Adds an "Object" name next to every object reference that UAssetAPI wrote as a bare package index.</summary>
public static class ObjectReferences
{
    public static JToken Annotate(UAsset asset, JToken token)
    {
        if (token is not JContainer container) return token;
        foreach (var obj in container.DescendantsAndSelf().OfType<JObject>().ToList())
        {
            if (!IsObjectProperty(obj) || obj["Value"] is not JValue { Type: JTokenType.Integer } value) continue;
            obj["Object"] = PackageIndexNames.FullName(asset, new FPackageIndex((int)value));
        }
        return token;
    }

    private static bool IsObjectProperty(JObject obj) =>
        obj["$type"]?.ToString().StartsWith("UAssetAPI.PropertyTypes.Objects.ObjectPropertyData") == true;
}
