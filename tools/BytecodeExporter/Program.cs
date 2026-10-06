using BytecodeExporter;

ExportOptions? options;
try
{
    options = ExportOptions.Parse(args);
}
catch (ArgumentException e)
{
    Console.Error.WriteLine(e.Message);
    Console.Error.WriteLine(ExportOptions.Usage);
    return 2;
}
if (options is null)
{
    Console.Error.WriteLine(ExportOptions.Usage);
    return 2;
}

try
{
    var asset = AssetLoader.Load(options);
    Directory.CreateDirectory(options.OutputDirectory);
    Console.WriteLine($"Asset:  {options.AssetPath}");
    Console.WriteLine($"Output: {options.OutputDirectory}");

    int functions = FunctionExporter.Export(asset, options.OutputDirectory);
    int variables = VariableExporter.Export(asset, options.OutputDirectory);
    int components = ComponentExporter.Export(asset, options.OutputDirectory);
    ClassSummaryExporter.Export(asset, options.OutputDirectory);

    Console.WriteLine($"Wrote {functions} bytecode files, {variables} variables, {components} components.");
    return 0;
}
catch (Exception e)
{
    Console.Error.WriteLine("Export failed: " + e);
    return 1;
}
