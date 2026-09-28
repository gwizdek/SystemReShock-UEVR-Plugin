using System.IO;
using SystemReShockInstaller.Models;
using SystemReShockInstaller.Services;
using Xunit;

namespace SystemReShockInstaller.Tests;

public class GameStoreTests
{
    [Theory]
    [InlineData(null, null)]
    [InlineData("", null)]
    [InlineData("garbage", null)]
    [InlineData("steam", GameStore.Steam)]
    [InlineData("GOG", GameStore.GOG)]
    [InlineData("other", GameStore.Other)]
    public void Parses_settings_key_and_reports_unknown_as_null(string? key, GameStore? expected)
    {
        Assert.Equal(expected, GameStores.Parse(key));
    }

    [Fact]
    public void Keys_round_trip()
    {
        Assert.Equal(GameStore.GOG, GameStores.Parse(GameStores.Key(GameStore.GOG)));
        Assert.Equal(GameStore.Other, GameStores.Parse(GameStores.Key(GameStore.Other)));
    }

    [Fact]
    public void Only_steam_starts_through_steam()
    {
        Assert.True(GameStores.StartsThroughSteam(GameStore.Steam));
        Assert.False(GameStores.StartsThroughSteam(GameStore.GOG));
        Assert.False(GameStores.StartsThroughSteam(GameStore.Other));
    }

    [Fact]
    public void Gog_marker_file_means_gog()
    {
        using var dir = new TempDir();
        File.WriteAllText(dir.File("goggame-1439637285.info"), "{}");

        Assert.Equal(GameStore.GOG, GameStoreDetector.Detect(dir.Path));
    }

    [Theory]
    [InlineData(@"D:\Steam\steamapps\common\System Shock Remake")]
    [InlineData(@"d:/steam/STEAMAPPS/Common/System Shock Remake")]
    public void Steam_library_path_means_steam(string folder)
    {
        Assert.Equal(GameStore.Steam, GameStoreDetector.Detect(folder));
    }

    [Fact]
    public void Plain_folder_or_empty_path_means_other()
    {
        using var dir = new TempDir();

        Assert.Equal(GameStore.Other, GameStoreDetector.Detect(dir.Path));
        Assert.Equal(GameStore.Other, GameStoreDetector.Detect(""));
        Assert.Equal(GameStore.Other, GameStoreDetector.Detect(null));
    }
}
