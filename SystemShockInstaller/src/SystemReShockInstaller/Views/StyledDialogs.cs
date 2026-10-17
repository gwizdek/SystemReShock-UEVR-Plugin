using System.Windows;
using SystemReShockInstaller.Services;

namespace SystemReShockInstaller.Views;

/// <summary>Questions and notices in the installer's own style, centred on the main window.</summary>
public sealed class StyledDialogs : IDialogs
{
    public bool Confirm(string title, string message) => Show(title, message, "Yes", "No");

    public void Warn(string title, string message) => Show(title, message, "OK", null);

    private static bool Show(string title, string message, string confirmText, string? cancelText)
    {
        var dialog = new StyledDialog(title, message, confirmText, cancelText);
        var owner = Application.Current?.MainWindow;
        if (owner != null && owner.IsVisible)
            dialog.Owner = owner;
        else
            dialog.WindowStartupLocation = WindowStartupLocation.CenterScreen;
        return dialog.ShowDialog() == true;
    }
}
