using System.Collections.Generic;
using System.IO;
using SystemReShockInstaller.Models;

namespace SystemReShockInstaller.Services;

/// <summary>Wipes the UEVR profile folder and extracts the bundled profile into it.</summary>
public sealed class ProfileInstallStep : IInstallStep
{
    private readonly IModBundle _bundle;

    public ProfileInstallStep(IModBundle bundle) => _bundle = bundle;

    public string Title => "Install the UEVR profile";

    public IEnumerable<string> Describe(InstallPlan plan)
    {
        yield return "Target: " + plan.ProfileTargetDir;
        yield return "Delete the existing profile folder, if any";
        yield return "Copy " + _bundle.ProfileEntries.Count + " profile files";
    }

    public void Execute(InstallPlan plan)
    {
        DeleteDirectory(plan.ProfileTargetDir);
        Directory.CreateDirectory(plan.ProfileTargetDir);
        foreach (var entry in _bundle.ProfileEntries)
            FileCopier.ExtractTo(entry, Path.Combine(plan.ProfileTargetDir, entry.RelativePath));
    }

    private static void DeleteDirectory(string dir)
    {
        if (!Directory.Exists(dir))
            return;
        foreach (var file in Directory.EnumerateFiles(dir, "*", SearchOption.AllDirectories))
            File.SetAttributes(file, FileAttributes.Normal);
        Directory.Delete(dir, recursive: true);
    }
}
