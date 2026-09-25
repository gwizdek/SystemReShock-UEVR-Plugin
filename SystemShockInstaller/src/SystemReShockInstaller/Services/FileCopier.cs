using System.IO;
using SystemReShockInstaller.Models;

namespace SystemReShockInstaller.Services;

internal static class FileCopier
{
    public static void ExtractTo(BundleEntry entry, string targetPath)
    {
        Directory.CreateDirectory(Path.GetDirectoryName(targetPath)!);
        using var source = entry.Open();
        using var target = new FileStream(targetPath, FileMode.Create, FileAccess.Write, FileShare.None);
        source.CopyTo(target);
    }

    public static void DeleteIfExists(string path)
    {
        if (File.Exists(path))
        {
            File.SetAttributes(path, FileAttributes.Normal);
            File.Delete(path);
        }
    }
}
