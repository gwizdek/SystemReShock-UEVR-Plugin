using System.IO;
using System.Linq;
using SystemReShockInstaller.Models;
using SystemReShockInstaller.Services;
using Xunit;

namespace SystemReShockInstaller.Tests;

public class PathTests
{
    [Fact]
    public void Plan_resolves_all_targets_from_game_and_appdata()
    {
        var plan = new InstallPlan(@"C:\uevr", @"D:\Steam\steamapps\common\System Shock Remake", @"C:\Users\ż\AppData\Roaming", GameStore.Steam);

        Assert.Equal(@"C:\Users\ż\AppData\Roaming\UnrealVRMod\SystemReShock-Win64-Shipping", plan.ProfileTargetDir);
        Assert.Equal(@"D:\Steam\steamapps\common\System Shock Remake\SystemShock\Content\Paks", plan.PaksTargetDir);
        Assert.Equal(@"C:\Users\ż\AppData\Roaming\SystemReShockVR\settings.json", plan.SettingsPath);
    }

    [Fact]
    public void Validator_accepts_folders_with_expected_files()
    {
        using var dir = new TempDir();
        File.WriteAllText(dir.File(ModPaths.UevrInjectorExe), "");
        Directory.CreateDirectory(Path.GetDirectoryName(dir.File(ModPaths.GameExeRelative))!);
        File.WriteAllText(dir.File(ModPaths.GameExeRelative), "");

        Assert.Null(PathValidator.ValidateUevrFolder(dir.Path));
        Assert.Null(PathValidator.ValidateGameFolder(dir.Path));
    }

    [Fact]
    public void Validator_reports_empty_missing_and_wrong_folders()
    {
        using var dir = new TempDir();

        Assert.Equal("Please choose a folder.", PathValidator.ValidateUevrFolder(""));
        Assert.Equal("This folder does not exist.", PathValidator.ValidateGameFolder(dir.File("nope")));
        Assert.Contains(ModPaths.UevrInjectorExe, PathValidator.ValidateUevrFolder(dir.Path));
        Assert.Contains("SystemReShock-Win64-Shipping.exe", PathValidator.ValidateGameFolder(dir.Path));
    }

    [Fact]
    public void Steam_library_paths_are_parsed_and_unescaped()
    {
        const string vdf = "\"libraryfolders\"\n{\n\t\"0\"\n\t{\n\t\t\"path\"\t\t\"C:\\\\Program Files (x86)\\\\Steam\"\n\t}\n\t\"1\"\n\t{\n\t\t\"path\"\t\t\"D:\\\\Gry – Steam\"\n\t\t\"label\"\t\t\"\"\n\t}\n}\n";

        var paths = SteamLocator.ParseLibraryPaths(vdf).ToList();

        Assert.Equal(new[] { @"C:\Program Files (x86)\Steam", @"D:\Gry – Steam" }, paths);
        Assert.Equal(@"D:\Gry – Steam\steamapps\common\System Shock Remake", SteamLocator.GameFolderIn(paths[1]));
    }
}
