using SystemReShockInstaller.Models;

namespace SystemReShockInstaller.Services;

/// <summary>Auto-detects where each store installed the game. Null when that store has no install.</summary>
public static class GameLocators
{
    public static string? Locate(GameStore store) => store switch
    {
        GameStore.Steam => SteamLocator.FindGameFolder(),
        GameStore.GOG => GogLocator.FindGameFolder(),
        _ => null,
    };
}
