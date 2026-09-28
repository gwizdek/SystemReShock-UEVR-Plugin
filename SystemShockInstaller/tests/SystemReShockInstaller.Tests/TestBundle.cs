using System.Collections.Generic;
using System.IO;
using System.IO.Compression;
using System.Text;
using SystemReShockInstaller.Services;

namespace SystemReShockInstaller.Tests;

/// <summary>Builds an in-memory zip shaped like mod_files/ so tests never depend on the real bundle.</summary>
internal static class TestBundle
{
    public static readonly IReadOnlyDictionary<string, string> DefaultFiles = new Dictionary<string, string>
    {
        ["config.txt"] = "VR_WorldScale=0.950000",
        ["ProfileMeta.json"] = "{}",
        ["plugins/SystemReShockVR.dll"] = "dll-bytes",
        ["uobjecthook/camera_state.json"] = "{\"x\":1}",
        ["paks/SystemShockVRModCore_P.pak"] = "core-v2",
        ["paks/SystemShockVRModAddon_P.pak"] = "addon-v2",
    };

    public static ModBundle Create() => Create(DefaultFiles);

    public static ModBundle Create(IReadOnlyDictionary<string, string> files)
    {
        var buffer = new MemoryStream();
        using (var zip = new ZipArchive(buffer, ZipArchiveMode.Create, leaveOpen: true))
        {
            foreach (var pair in files)
            {
                using var entry = zip.CreateEntry(pair.Key).Open();
                var bytes = Encoding.UTF8.GetBytes(pair.Value);
                entry.Write(bytes, 0, bytes.Length);
            }
        }
        buffer.Position = 0;
        return new ModBundle(buffer);
    }
}

/// <summary>A temp folder with a non-ASCII name, deleted on dispose.</summary>
internal sealed class TempDir : System.IDisposable
{
    public TempDir()
    {
        Path = System.IO.Path.Combine(System.IO.Path.GetTempPath(), "SysReShock – Zażółć gęślą jaźń " + System.Guid.NewGuid().ToString("N"));
        Directory.CreateDirectory(Path);
    }

    public string Path { get; }

    public string File(string relative) => System.IO.Path.Combine(Path, relative);

    public void Dispose()
    {
        if (Directory.Exists(Path))
            Directory.Delete(Path, recursive: true);
    }
}
