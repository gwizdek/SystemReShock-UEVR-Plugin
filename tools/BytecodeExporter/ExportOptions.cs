using UAssetAPI.UnrealTypes;

namespace BytecodeExporter;

/// <summary>Command line options for one export run.</summary>
public sealed record ExportOptions(
    string AssetPath,
    string OutputDirectory,
    EngineVersion EngineVersion,
    string? MappingsPath)
{
    public const string Usage =
        "Usage: BytecodeExporter <asset.uasset> [--out <dir>] [--engine <4.27>] [--mappings <file.usmap>]\n" +
        "\n" +
        "Writes the Blueprint bytecode, variables and components of one .uasset as pretty JSON.\n" +
        "By default the files go to a folder named like the asset, next to the asset.";

    public static ExportOptions? Parse(string[] args)
    {
        if (args.Length == 0) return null;
        string assetPath = Path.GetFullPath(args[0]);
        string? outDir = null;
        string engine = "4.27";
        string? mappings = null;

        for (int i = 1; i < args.Length; i++)
        {
            string value = i + 1 < args.Length ? args[i + 1] : "";
            switch (args[i])
            {
                case "--out": outDir = value; i++; break;
                case "--engine": engine = value; i++; break;
                case "--mappings": mappings = value; i++; break;
                default: throw new ArgumentException($"Unknown argument: {args[i]}");
            }
        }

        outDir ??= DefaultOutputDirectory(assetPath);
        return new ExportOptions(assetPath, Path.GetFullPath(outDir), ParseEngine(engine), mappings);
    }

    private static string DefaultOutputDirectory(string assetPath)
    {
        string dir = Path.GetDirectoryName(assetPath) ?? ".";
        return Path.Combine(dir, Path.GetFileNameWithoutExtension(assetPath));
    }

    private static EngineVersion ParseEngine(string text)
    {
        string name = "VER_UE" + text.Replace('.', '_');
        if (Enum.TryParse(name, out EngineVersion version)) return version;
        throw new ArgumentException($"Unknown engine version '{text}'. Use a form like 4.27 or 5.3.");
    }
}
