using System.IO;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Json;
using System.Text;
using SystemReShockInstaller.Models;

namespace SystemReShockInstaller.Services;

/// <summary>JSON file read and written with the built-in DataContractJsonSerializer, UTF-8 without BOM.</summary>
public sealed class SettingsStore : ISettingsStore
{
    private static readonly DataContractJsonSerializer Serializer = new(typeof(InstallerSettings));

    public InstallerSettings? Load(string path)
    {
        if (!File.Exists(path))
            return null;
        try
        {
            using var stream = File.OpenRead(path);
            return Serializer.ReadObject(stream) as InstallerSettings;
        }
        catch (SerializationException)
        {
            return null;
        }
    }

    public void Save(string path, InstallerSettings settings)
    {
        Directory.CreateDirectory(Path.GetDirectoryName(path)!);
        using var stream = new FileStream(path, FileMode.Create, FileAccess.Write, FileShare.None);
        using var writer = JsonReaderWriterFactory.CreateJsonWriter(stream, new UTF8Encoding(false), ownsStream: false, indent: true);
        Serializer.WriteObject(writer, settings);
        writer.Flush();
    }
}
