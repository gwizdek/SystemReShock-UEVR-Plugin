using System.Windows;
using System.Windows.Input;

namespace SystemReShockInstaller.Views;

public partial class StyledDialog : Window
{
    /// <summary>
    /// With a cancel text the dialog asks a question: Enter and Esc both pick the cancel button,
    /// so a stray key press never confirms. Without one it is a notice with a single button.
    /// </summary>
    public StyledDialog(string title, string message, string confirmText, string? cancelText)
    {
        InitializeComponent();
        Title = title;
        TitleText.Text = title.ToUpperInvariant();
        MessageText.Text = message;
        ConfirmButton.Content = confirmText;
        if (cancelText == null)
        {
            CancelButton.Visibility = Visibility.Collapsed;
            CancelButton.IsCancel = false;
            ConfirmButton.IsDefault = true;
            ConfirmButton.IsCancel = true;
        }
        else
        {
            CancelButton.Content = cancelText;
            CancelButton.IsDefault = true;
        }
    }

    private void OnConfirm(object sender, RoutedEventArgs e) => DialogResult = true;

    private void OnCancel(object sender, RoutedEventArgs e) => DialogResult = false;

    private void OnHeaderMouseDown(object sender, MouseButtonEventArgs e)
    {
        if (e.ButtonState == MouseButtonState.Pressed)
            DragMove();
    }
}
