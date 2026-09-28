using System.Runtime.Serialization;

namespace SystemReShockInstaller.Models;

/// <summary>Shared by the installer and the launcher. Field names are the JSON wire contract.</summary>
[DataContract]
public sealed class InstallerSettings
{
    [DataMember(Name = "uevrPath", Order = 0)]
    public string? UevrPath { get; set; }

    [DataMember(Name = "gamePath", Order = 1)]
    public string? GamePath { get; set; }

    [DataMember(Name = "installedVersion", Order = 2)]
    public string? InstalledVersion { get; set; }

    /// <summary>ISO 8601 local time with offset, for example 2026-09-18T23:10:00+02:00.</summary>
    [DataMember(Name = "installedAt", Order = 3)]
    public string? InstalledAt { get; set; }

    /// <summary>"openxr" or "openvr". Missing means OpenXR.</summary>
    [DataMember(Name = "runtime", Order = 4, EmitDefaultValue = false)]
    public string? Runtime { get; set; }

    /// <summary>Seconds between the game window appearing and injection. Missing means the default.</summary>
    [DataMember(Name = "injectDelaySeconds", Order = 5, EmitDefaultValue = false)]
    public int? InjectDelaySeconds { get; set; }

    /// <summary>"steam", "gog" or "other". Missing means: detect it from the game folder.</summary>
    [DataMember(Name = "store", Order = 6, EmitDefaultValue = false)]
    public string? Store { get; set; }
}
