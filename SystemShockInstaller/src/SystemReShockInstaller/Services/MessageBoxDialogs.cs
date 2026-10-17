using System.Windows;

namespace SystemReShockInstaller.Services;

/// <summary>
/// Standard Windows message boxes, owned by the main window when there is one. The app uses them
/// only for the notice that another copy is already running; every other question and notice is
/// a StyledDialog.
/// </summary>
public sealed class MessageBoxDialogs : IDialogs
{
    public bool Confirm(string title, string message) =>
        Show(title, message, MessageBoxButton.YesNo, MessageBoxImage.Warning) == MessageBoxResult.Yes;

    public void Warn(string title, string message) =>
        Show(title, message, MessageBoxButton.OK, MessageBoxImage.Information);

    private static MessageBoxResult Show(string title, string message, MessageBoxButton buttons, MessageBoxImage image)
    {
        var owner = Application.Current?.MainWindow;
        return owner == null
            ? MessageBox.Show(message, title, buttons, image)
            : MessageBox.Show(owner, message, title, buttons, image);
    }
}
