using Newtonsoft.Json.Linq;
using UAssetAPI.FieldTypes;
using UAssetAPI.Kismet;
using UAssetAPI.UnrealTypes;

namespace BytecodeExporter;

/// <summary>Describes an FProperty (a variable, parameter or local) as JSON.</summary>
public static class PropertyDescriber
{
    public static JObject Describe(FProperty property)
    {
        var json = new JObject
        {
            ["Name"] = property.Name.ToString(),
            ["Type"] = property.SerializedType.ToString(),
            ["PinType"] = PinType(property),
            ["PropertyFlags"] = property.PropertyFlags.ToString(),
            ["ArrayDim"] = property.ArrayDim.ToString(),
        };
        AddReplication(json, property);
        return json;
    }

    public static bool IsParameter(FProperty property) =>
        property.PropertyFlags.HasFlag(EPropertyFlags.CPF_Parm);

    private static JToken PinType(FProperty property)
    {
        try
        {
            var pin = KismetSerializer.ConvertPropertyToPinType(property);
            return KismetSerializer.SerializeGraphPinType(pin);
        }
        catch (Exception e)
        {
            return new JObject { ["Error"] = e.Message };
        }
    }

    private static void AddReplication(JObject json, FProperty property)
    {
        if (property.RepNotifyFunc.ToString() is { Length: > 0 } repNotify && repNotify != "None")
            json["RepNotifyFunc"] = repNotify;
        if (property.BlueprintReplicationCondition != ELifetimeCondition.COND_None)
            json["ReplicationCondition"] = property.BlueprintReplicationCondition.ToString();
    }
}
