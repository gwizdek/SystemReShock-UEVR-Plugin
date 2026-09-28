using System;
using System.IO;

namespace SystemReShockInstaller.Models;

/// <summary>One file inside the embedded mod bundle.</summary>
public sealed class BundleEntry
{
    public BundleEntry(string relativePath, Func<Stream> open)
    {
        RelativePath = relativePath.Replace('/', '\\');
        Open = open;
    }

    /// <summary>Path relative to the bundle root, using backslashes.</summary>
    public string RelativePath { get; }
    public Func<Stream> Open { get; }

    public string FileName => Path.GetFileName(RelativePath);

    public bool IsPak => IsUnder(ModPaths.BundlePaksFolder);

    public bool IsPlugin => IsUnder(ModPaths.BundlePluginsFolder);

    /// <summary>UEVR never rewrites paks or plugins, so their content can be checked byte for byte.</summary>
    public bool HasStableContent => IsPak || IsPlugin;

    private bool IsUnder(string folder) =>
        RelativePath.StartsWith(folder + "\\", StringComparison.OrdinalIgnoreCase);
}
