using System.Collections.Generic;
using System.IO;
using SystemReShockInstaller.Models;

namespace SystemReShockInstaller.Services;

/// <summary>Deletes the mod paks from the game's Content\Paks folder. Other files there are never touched.</summary>
public sealed class PakRemoveStep : IInstallStep
{
    private readonly IModBundle _bundle;

    public PakRemoveStep(IModBundle bundle) => _bundle = bundle;

    public string Title => "Delete the mod pak files";

    public IEnumerable<string> Describe(InstallPlan plan)
    {
        yield return "Target: " + plan.PaksTargetDir;
        foreach (var pak in _bundle.PakEntries)
            yield return "Delete " + pak.FileName;
    }

    public void Execute(InstallPlan plan)
    {
        foreach (var pak in _bundle.PakEntries)
            FileCopier.DeleteIfExists(Path.Combine(plan.PaksTargetDir, pak.FileName));
    }
}
