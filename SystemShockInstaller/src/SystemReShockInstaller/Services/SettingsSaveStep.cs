using System;
using System.Collections.Generic;
using SystemReShockInstaller.Models;

namespace SystemReShockInstaller.Services;

/// <summary>Records the chosen paths for the future launcher app.</summary>
public sealed class SettingsSaveStep : IInstallStep
{
    private readonly ISettingsStore _store;
    private readonly string _version;

    public SettingsSaveStep(ISettingsStore store, string version)
    {
        _store = store;
        _version = version;
    }

    public string Title => "Save installer settings";

    public IEnumerable<string> Describe(InstallPlan plan)
    {
        yield return "Target: " + plan.SettingsPath;
        yield return "Remember the UEVR folder and the game folder";
    }

    public void Execute(InstallPlan plan)
    {
        _store.Save(plan.SettingsPath, new InstallerSettings
        {
            UevrPath = plan.UevrPath,
            GamePath = plan.GamePath,
            InstalledVersion = _version,
            InstalledAt = DateTimeOffset.Now.ToString("yyyy-MM-dd'T'HH:mm:sszzz"),
        });
    }
}
