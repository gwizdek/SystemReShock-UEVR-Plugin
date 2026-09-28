using System.Collections.Generic;
using System.IO;
using System.Linq;
using SystemReShockInstaller.Models;

namespace SystemReShockInstaller.Services;

/// <summary>Deletes settings.json so the next start is a clean first run. Removes its folder too when nothing else is in it.</summary>
public sealed class SettingsRemoveStep : IInstallStep
{
    public string Title => "Delete the installer settings";

    public IEnumerable<string> Describe(InstallPlan plan)
    {
        yield return "Delete " + plan.SettingsPath;
    }

    public void Execute(InstallPlan plan)
    {
        FileCopier.DeleteIfExists(plan.SettingsPath);
        var folder = Path.GetDirectoryName(plan.SettingsPath)!;
        if (Directory.Exists(folder) && !Directory.EnumerateFileSystemEntries(folder).Any())
            Directory.Delete(folder);
    }
}
