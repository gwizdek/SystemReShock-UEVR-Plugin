using System.IO;
using SystemReShockInstaller.Models;
using SystemReShockInstaller.Services;
using Xunit;

namespace SystemReShockInstaller.Tests;

public class SettingsStoreTests
{
    [Fact]
    public void Round_trips_unicode_paths()
    {
        using var dir = new TempDir();
        var path = dir.File(@"SystemReShockVR\settings.json");
        var store = new SettingsStore();
        var settings = new InstallerSettings
        {
            UevrPath = @"D:\Gry\UEVR – wersja nocna",
            GamePath = @"D:\Steam\steamapps\common\System Shock Remake",
            InstalledVersion = "2.0-beta.2",
            InstalledAt = "2026-09-18T23:10:00+02:00",
        };

        store.Save(path, settings);
        var loaded = store.Load(path);

        Assert.NotNull(loaded);
        Assert.Equal(settings.UevrPath, loaded!.UevrPath);
        Assert.Equal(settings.GamePath, loaded.GamePath);
        Assert.Equal(settings.InstalledVersion, loaded.InstalledVersion);
        Assert.Equal(settings.InstalledAt, loaded.InstalledAt);
    }

    [Fact]
    public void Round_trips_launcher_fields_and_tolerates_their_absence()
    {
        using var dir = new TempDir();
        var store = new SettingsStore();
        var withLauncherFields = dir.File("new.json");
        var installerOnly = dir.File("old.json");
        File.WriteAllText(installerOnly, "{\"uevrPath\":\"x\",\"gamePath\":\"y\",\"installedVersion\":\"1\",\"installedAt\":\"t\"}");

        store.Save(withLauncherFields, new InstallerSettings { UevrPath = "x", GamePath = "y", Runtime = "openvr", InjectDelaySeconds = 20 });
        var loadedNew = store.Load(withLauncherFields)!;
        var loadedOld = store.Load(installerOnly)!;

        Assert.Equal("openvr", loadedNew.Runtime);
        Assert.Equal(20, loadedNew.InjectDelaySeconds);
        Assert.Null(loadedOld.Runtime);
        Assert.Null(loadedOld.InjectDelaySeconds);
    }

    [Fact]
    public void Writes_camel_case_keys_without_bom()
    {
        using var dir = new TempDir();
        var path = dir.File("settings.json");

        new SettingsStore().Save(path, new InstallerSettings { UevrPath = "x", GamePath = "y" });
        var bytes = File.ReadAllBytes(path);
        var text = File.ReadAllText(path);

        Assert.NotEqual(0xEF, bytes[0]);
        Assert.Contains("\"uevrPath\"", text);
        Assert.Contains("\"gamePath\"", text);
    }

    [Fact]
    public void Load_returns_null_for_missing_or_corrupt_file()
    {
        using var dir = new TempDir();
        var store = new SettingsStore();
        var corrupt = dir.File("bad.json");
        File.WriteAllText(corrupt, "{ not json");

        Assert.Null(store.Load(dir.File("missing.json")));
        Assert.Null(store.Load(corrupt));
    }

    [Fact]
    public void Save_step_records_plan_paths_and_version()
    {
        using var dir = new TempDir();
        var plan = new InstallPlan(@"C:\uevr", @"C:\game", dir.Path);
        var store = new SettingsStore();

        new SettingsSaveStep(store, "2.0-beta.2").Execute(plan);
        var loaded = store.Load(plan.SettingsPath);

        Assert.Equal(@"C:\uevr", loaded!.UevrPath);
        Assert.Equal(@"C:\game", loaded.GamePath);
        Assert.Equal("2.0-beta.2", loaded.InstalledVersion);
        Assert.Matches(@"^\d{4}-\d{2}-\d{2}T\d{2}:\d{2}:\d{2}[+-]\d{2}:\d{2}$", loaded.InstalledAt);
    }
}
