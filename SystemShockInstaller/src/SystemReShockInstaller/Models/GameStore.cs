using System;
using System.Collections.Generic;

namespace SystemReShockInstaller.Models;

public enum GameStore
{
    Steam,
    GOG,
    /// <summary>A copied or moved install without a store marker. Started from its exe, like GOG.</summary>
    Other,
}

/// <summary>Maps each store to its settings key and to the words the pages use for it.</summary>
public static class GameStores
{
    private static readonly Dictionary<GameStore, (string Key, string Label, string LaunchVia)> Table = new()
    {
        [GameStore.Steam] = ("steam", "Steam version", "through Steam"),
        [GameStore.GOG] = ("gog", "GOG version", "from the game folder"),
        [GameStore.Other] = ("other", "Not a Steam or GOG install", "from the game folder"),
    };

    public static string Key(GameStore store) => Table[store].Key;

    public static string Label(GameStore store) => Table[store].Label;

    /// <summary>Completes "Starting System Shock Remake ...".</summary>
    public static string LaunchVia(GameStore store) => Table[store].LaunchVia;

    /// <summary>One sentence for the launcher: which version this is and how it is started.</summary>
    public static string Describe(GameStore store) =>
        Label(store) + ". The game is started " + LaunchVia(store) + ".";

    public static bool StartsThroughSteam(GameStore store) => store == GameStore.Steam;

    /// <summary>Null when the key is missing or unknown, so the caller can detect the store from the folder.</summary>
    public static GameStore? Parse(string? key)
    {
        foreach (var pair in Table)
        {
            if (string.Equals(pair.Value.Key, key, StringComparison.OrdinalIgnoreCase))
                return pair.Key;
        }
        return null;
    }
}
