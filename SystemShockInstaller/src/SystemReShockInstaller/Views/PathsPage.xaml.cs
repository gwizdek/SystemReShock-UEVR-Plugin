using System.Diagnostics;
using System.Windows.Controls;
using System.Windows.Navigation;

namespace SystemReShockInstaller.Views;

public partial class PathsPage : UserControl
{
    public PathsPage() => InitializeComponent();

    private void OnRequestNavigate(object sender, RequestNavigateEventArgs e)
    {
        Process.Start(new ProcessStartInfo(e.Uri.AbsoluteUri) { UseShellExecute = true });
        e.Handled = true;
    }
}
