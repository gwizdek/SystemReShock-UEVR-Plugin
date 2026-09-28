using System.IO;
using SystemReShockInstaller.Models;

namespace SystemReShockInstaller.Services;

/// <summary>Decides at startup whether to show the launcher, offer an update, or run the wizard.</summary>
public sealed class InstallStateResolver
{
    private readonly ISettingsStore _store;
    private readonly InstallVerifier _verifier;
    private readonly string _appDataRoot;
    private readonly string _version;

    public InstallStateResolver(ISettingsStore store, InstallVerifier verifier, string appDataRoot, string version)
    {
        _store = store;
        _verifier = verifier;
        _appDataRoot = appDataRoot;
        _version = version;
    }

    public string SettingsPath => Path.Combine(_appDataRoot, ModPaths.SettingsDirName, ModPaths.SettingsFileName);

    public InstallState Resolve()
    {
        var settings = _store.Load(SettingsPath);
        if (settings == null)
            return InstallState.NotInstalled();
        var plan = new InstallPlan(settings.UevrPath ?? string.Empty, settings.GamePath ?? string.Empty, _appDataRoot, StoreOf(settings));
        if (PathValidator.ValidateUevrFolder(settings.UevrPath) != null || PathValidator.ValidateGameFolder(settings.GamePath) != null)
            return InstallState.NotInstalled("The UEVR or game folder saved last time no longer exists.", plan, settings);
        return Classify(plan, settings, _verifier.Verify(plan));
    }

    private InstallState Classify(InstallPlan plan, InstallerSettings settings, InstallIssue? issue)
    {
        if (issue?.IsMissing == true)
            return InstallState.NotInstalled(issue.Message, plan, settings);
        if (settings.InstalledVersion != _version)
            return InstallState.VersionDiffers(plan, settings, VersionText(settings.InstalledVersion));
        if (issue != null)
            return InstallState.FilesChanged(plan, settings, issue.Message);
        return InstallState.Installed(plan, settings);
    }

    /// <summary>Settings written before the store key existed are resolved from the folder, without rewriting the file.</summary>
    private static GameStore StoreOf(InstallerSettings settings) =>
        GameStores.Parse(settings.Store) ?? GameStoreDetector.Detect(settings.GamePath);

    private string VersionText(string? installed) =>
        "Mod v" + (installed ?? "unknown") + " is installed. This setup contains v" + _version + ".";
}
