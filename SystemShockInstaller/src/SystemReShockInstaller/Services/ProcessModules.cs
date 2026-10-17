using System;
using System.ComponentModel;
using System.Diagnostics;
using System.Linq;

namespace SystemReShockInstaller.Services;

/// <summary>Reads which DLLs another process has loaded.</summary>
public static class ProcessModules
{
    /// <summary>
    /// True when the process has loaded one of the named DLLs. False when its modules cannot be
    /// read, for example while it starts or exits, or when it runs as administrator.
    /// </summary>
    public static bool HasAny(Process process, params string[] moduleNames)
    {
        try
        {
            foreach (ProcessModule module in process.Modules)
            {
                if (moduleNames.Any(name => string.Equals(name, module.ModuleName, StringComparison.OrdinalIgnoreCase)))
                    return true;
            }
            return false;
        }
        catch (Exception ex) when (ex is Win32Exception || ex is InvalidOperationException)
        {
            return false;
        }
    }
}
