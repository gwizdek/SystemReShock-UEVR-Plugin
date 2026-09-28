using System;
using System.IO;

namespace SystemReShockInstaller.Services;

/// <summary>Turns file system exceptions into text a player can act on.</summary>
public static class InstallErrorFormatter
{
    private const int SharingViolation = unchecked((int)0x80070020);
    private const int LockViolation = unchecked((int)0x80070021);

    public static string Format(Exception ex) => ex switch
    {
        UnauthorizedAccessException => "Access denied. " + ex.Message
            + " Close the game and try running the installer as administrator.",
        IOException io when io.HResult == SharingViolation || io.HResult == LockViolation =>
            "A file is in use. " + io.Message + " Close the game and UEVR, then try again.",
        IOException io => "File error: " + io.Message,
        _ => "Unexpected error: " + ex.Message,
    };
}
