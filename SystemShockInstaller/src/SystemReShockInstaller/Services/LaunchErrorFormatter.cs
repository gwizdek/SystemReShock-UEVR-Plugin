using System;
using System.IO;

namespace SystemReShockInstaller.Services;

/// <summary>Turns launch failures into text a player can act on.</summary>
public static class LaunchErrorFormatter
{
    private const string AntivirusHint =
        " Antivirus software often blocks this step. Add an exception for this launcher and the UEVR folder, then try again.";

    public static string Format(Exception ex) => ex switch
    {
        InjectionException => "Injection failed. " + ex.Message + AntivirusHint,
        FileNotFoundException => "Launch failed. " + ex.Message,
        TimeoutException => "Launch failed. " + ex.Message,
        _ => "Launch failed. " + ex.Message,
    };
}
