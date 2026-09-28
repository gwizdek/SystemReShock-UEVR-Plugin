using System.IO;
using SystemReShockInstaller.Models;
using SystemReShockInstaller.Services;
using Xunit;

namespace SystemReShockInstaller.Tests;

public class InstallStateResolverTests
{
    private const string Version = "2.0-beta.2";

    [Fact]
    public void No_settings_means_not_installed()
    {
        using var root = new TempDir();
        using var bundle = TestBundle.Create();

        var state = Resolver(root, bundle).Resolve();

        Assert.Equal(InstallStatus.NotInstalled, state.Status);
        Assert.False(state.IsLaunchable);
    }

    [Fact]
    public void Matching_files_and_version_means_installed()
    {
        using var root = new TempDir();
        using var bundle = TestBundle.Create();
        FullInstall(root, bundle, Version);

        var state = Resolver(root, bundle).Resolve();

        Assert.Equal(InstallStatus.Installed, state.Status);
        Assert.True(state.IsLaunchable);
        Assert.Equal(root.File("game"), state.Plan!.GamePath);
    }

    [Fact]
    public void Different_version_offers_update_but_stays_launchable()
    {
        using var root = new TempDir();
        using var bundle = TestBundle.Create();
        FullInstall(root, bundle, "2.0-beta.1");

        var state = Resolver(root, bundle).Resolve();

        Assert.Equal(InstallStatus.VersionDiffers, state.Status);
        Assert.True(state.IsLaunchable);
        Assert.Contains("v2.0-beta.1", state.Reason);
        Assert.Contains("v2.0-beta.2", state.Reason);
    }

    [Fact]
    public void Changed_plugin_with_same_version_means_files_changed()
    {
        using var root = new TempDir();
        using var bundle = TestBundle.Create();
        var plan = FullInstall(root, bundle, Version);
        File.WriteAllText(Path.Combine(plan.ProfileTargetDir, @"plugins\SystemReShockVR.dll"), "tampered");

        var state = Resolver(root, bundle).Resolve();

        Assert.Equal(InstallStatus.FilesChanged, state.Status);
        Assert.False(state.IsLaunchable);
    }

    [Fact]
    public void Missing_pak_means_not_installed_even_with_old_version()
    {
        using var root = new TempDir();
        using var bundle = TestBundle.Create();
        var plan = FullInstall(root, bundle, "1.0");
        File.Delete(Path.Combine(plan.PaksTargetDir, "SystemShockVRModAddon_P.pak"));

        var state = Resolver(root, bundle).Resolve();

        Assert.Equal(InstallStatus.NotInstalled, state.Status);
        Assert.Contains("SystemShockVRModAddon_P.pak", state.Reason);
    }

    [Fact]
    public void Vanished_game_folder_means_not_installed()
    {
        using var root = new TempDir();
        using var bundle = TestBundle.Create();
        FullInstall(root, bundle, Version);
        Directory.Delete(root.File("game"), recursive: true);

        var state = Resolver(root, bundle).Resolve();

        Assert.Equal(InstallStatus.NotInstalled, state.Status);
    }

    [Fact]
    public void Saved_store_key_is_used_as_is()
    {
        using var root = new TempDir();
        using var bundle = TestBundle.Create();
        var plan = FullInstall(root, bundle, Version);
        RewriteStore(plan, "gog");

        var state = Resolver(root, bundle).Resolve();

        Assert.Equal(GameStore.GOG, state.Plan!.Store);
    }

    [Fact]
    public void Missing_store_key_is_detected_from_the_game_folder()
    {
        using var root = new TempDir();
        using var bundle = TestBundle.Create();
        var plan = FullInstall(root, bundle, Version);
        RewriteStore(plan, null);
        File.WriteAllText(Path.Combine(plan.GamePath, "goggame-1439637285.info"), "{}");

        var state = Resolver(root, bundle).Resolve();

        Assert.Equal(GameStore.GOG, state.Plan!.Store);
    }

    private static void RewriteStore(InstallPlan plan, string? store)
    {
        var settingsStore = new SettingsStore();
        var settings = settingsStore.Load(plan.SettingsPath)!;
        settings.Store = store;
        settingsStore.Save(plan.SettingsPath, settings);
    }

    private static InstallStateResolver Resolver(TempDir root, IModBundle bundle) =>
        new(new SettingsStore(), new InstallVerifier(bundle), root.File("appdata"), Version);

    private static InstallPlan FullInstall(TempDir root, IModBundle bundle, string installedVersion)
    {
        CreateMarkerFiles(root);
        var plan = InstallVerifierTests.Install(root, bundle);
        new SettingsSaveStep(new SettingsStore(), installedVersion).Execute(plan);
        return plan;
    }

    private static void CreateMarkerFiles(TempDir root)
    {
        var uevr = root.File("uevr");
        var gameExe = Path.Combine(root.File("game"), ModPaths.GameExeRelative);
        Directory.CreateDirectory(uevr);
        Directory.CreateDirectory(Path.GetDirectoryName(gameExe)!);
        File.WriteAllText(Path.Combine(uevr, ModPaths.UevrInjectorExe), "");
        File.WriteAllText(gameExe, "");
    }
}
