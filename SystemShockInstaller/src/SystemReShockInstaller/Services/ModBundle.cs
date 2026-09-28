using System;
using System.Collections.Generic;
using System.IO;
using System.IO.Compression;
using System.Linq;
using System.Reflection;
using SystemReShockInstaller.Models;

namespace SystemReShockInstaller.Services;

/// <summary>Reads the zip embedded at build time from mod_files/.</summary>
public sealed class ModBundle : IModBundle, IDisposable
{
    private const string ResourceName = "mod_files.zip";
    private readonly ZipArchive _archive;

    public ModBundle(Stream zipStream)
    {
        _archive = new ZipArchive(zipStream, ZipArchiveMode.Read);
        var entries = _archive.Entries
            .Where(e => !string.IsNullOrEmpty(e.Name))
            .Select(e => new BundleEntry(e.FullName, e.Open))
            .ToList();
        PakEntries = entries.Where(e => e.IsPak).ToList();
        ProfileEntries = entries.Where(e => !e.IsPak).ToList();
    }

    public IReadOnlyList<BundleEntry> ProfileEntries { get; }
    public IReadOnlyList<BundleEntry> PakEntries { get; }

    public static ModBundle FromEmbeddedResource()
    {
        var stream = Assembly.GetExecutingAssembly().GetManifestResourceStream(ResourceName)
            ?? throw new InvalidOperationException("Embedded resource " + ResourceName + " is missing.");
        return new ModBundle(stream);
    }

    public void Dispose() => _archive.Dispose();
}
