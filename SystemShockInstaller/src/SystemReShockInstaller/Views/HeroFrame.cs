using System.Windows;
using System.Windows.Controls;

namespace SystemReShockInstaller.Views;

/// <summary>
/// Page frame with the Shodan artwork on the left, page content on the right, and a bottom bar
/// carrying the UEVR logo plus the page's buttons. Its template lives in Theme.xaml.
/// </summary>
public sealed class HeroFrame : ContentControl
{
    public static readonly DependencyProperty ButtonBarProperty =
        DependencyProperty.Register(nameof(ButtonBar), typeof(object), typeof(HeroFrame));

    public object? ButtonBar
    {
        get => GetValue(ButtonBarProperty);
        set => SetValue(ButtonBarProperty, value);
    }
}
