using System.Collections.Generic;
using System.IO;
using SystemReShockInstaller.Models;

namespace SystemReShockInstaller.Services;

/// <summary>Replaces the mod paks in the game's Content\Paks folder. Other files there are never touched.</summary>
public sealed class PakInstallStep : IInstallStep
{
    private readonly IModBundle _bundle;

    public PakInstallStep(IModBundle bundle) => _bundle = bundle;

    public string Title => "Copy mod pak files into the game folder";

    public IEnumerable<string> Describe(InstallPlan plan)
    {
        yield return "Target: " + plan.PaksTargetDir;
        foreach (var pak in _bundle.PakEntries)
            yield return "Replace " + pak.FileName;
    }

    public void Execute(InstallPlan plan)
    {
        Directory.CreateDirectory(plan.PaksTargetDir);
        foreach (var pak in _bundle.PakEntries)
        {
            var target = Path.Combine(plan.PaksTargetDir, pak.FileName);
            FileCopier.DeleteIfExists(target);
            FileCopier.ExtractTo(pak, target);
        }
    }
}
