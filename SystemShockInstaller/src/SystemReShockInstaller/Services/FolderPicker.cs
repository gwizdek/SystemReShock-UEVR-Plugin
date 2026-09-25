using System;
using System.IO;
using System.Runtime.InteropServices;
using System.Windows;
using System.Windows.Interop;
using SystemReShockInstaller.Interop;

namespace SystemReShockInstaller.Services;

/// <summary>Modern Explorer-style folder dialog (IFileOpenDialog with FOS_PICKFOLDERS). Unicode paths throughout.</summary>
public sealed class FolderPicker : IFolderPicker
{
    private const int ErrorCancelled = unchecked((int)0x800704C7);

    public string? Pick(string title, string? initialFolder)
    {
        var dialog = (IFileOpenDialog)new FileOpenDialogRCW();
        try
        {
            Configure(dialog, title, initialFolder);
            var hr = dialog.Show(OwnerHandle());
            if (hr == ErrorCancelled)
                return null;
            Marshal.ThrowExceptionForHR(hr);
            dialog.GetResult(out var item);
            item.GetDisplayName(ShellItemDisplayName.FileSystemPath, out var path);
            return path;
        }
        finally
        {
            Marshal.ReleaseComObject(dialog);
        }
    }

    private static void Configure(IFileOpenDialog dialog, string title, string? initialFolder)
    {
        dialog.SetOptions(FileOpenOptions.PickFolders | FileOpenOptions.ForceFileSystem | FileOpenOptions.PathMustExist);
        dialog.SetTitle(title);
        if (!string.IsNullOrEmpty(initialFolder) && Directory.Exists(initialFolder))
            dialog.SetFolder(ShellItem.FromPath(initialFolder!));
    }

    private static IntPtr OwnerHandle()
    {
        var window = Application.Current?.MainWindow;
        return window == null ? IntPtr.Zero : new WindowInteropHelper(window).Handle;
    }
}
