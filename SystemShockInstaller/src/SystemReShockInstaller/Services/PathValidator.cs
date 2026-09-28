using System.IO;
using SystemReShockInstaller.Models;

namespace SystemReShockInstaller.Services;

/// <summary>Returns null when a folder is acceptable, otherwise the message to show under the field.</summary>
public static class PathValidator
{
    public static string? ValidateUevrFolder(string? path) =>
        ValidateFolder(path) ?? RequireFile(path!, ModPaths.UevrInjectorExe);

    public static string? ValidateGameFolder(string? path) =>
        ValidateFolder(path) ?? RequireFile(path!, ModPaths.GameExeRelative);

    public static bool IsGameFolder(string? path) => ValidateGameFolder(path) == null;

    private static string? ValidateFolder(string? path)
    {
        if (string.IsNullOrWhiteSpace(path))
            return "Please choose a folder.";
        return Directory.Exists(path) ? null : "This folder does not exist.";
    }

    private static string? RequireFile(string folder, string relativeFile) =>
        File.Exists(Path.Combine(folder, relativeFile))
            ? null
            : "This folder does not contain " + relativeFile + ".";
}
