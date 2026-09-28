using System.Collections.Generic;
using SystemReShockInstaller.Models;

namespace SystemReShockInstaller.Services;

/// <summary>Deletes the whole UEVR profile folder, including the plugin DLL and the settings UEVR wrote into it.</summary>
public sealed class ProfileRemoveStep : IInstallStep
{
    public string Title => "Delete the UEVR profile";

    public IEnumerable<string> Describe(InstallPlan plan)
    {
        yield return "Delete the folder " + plan.ProfileTargetDir;
    }

    public void Execute(InstallPlan plan) => FileCopier.DeleteDirectory(plan.ProfileTargetDir);
}
