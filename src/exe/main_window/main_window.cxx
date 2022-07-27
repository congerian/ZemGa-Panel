#include "./main_window.hxx"

namespace {
    Qt::WindowFlags defaultWindowFlags = Qt::WindowFlags() 
        | Qt::MSWindowsFixedSizeDialogHint
//        | Qt::X11BypassWindowManagerHint
//        | Qt::FramelessWindowHint
//        | Qt::NoDropShadowWindowHint
//        | Qt::WindowTitleHint
//        | Qt::WindowSystemMenuHint
//        | Qt::WindowMinimizeButtonHint
//        | Qt::WindowMaximizeButtonHint
//        | Qt::WindowCloseButtonHint
//        | Qt::WindowContextHelpButtonHint
//        | Qt::WindowShadeButtonHint
//        | Qt::WindowStaysOnTopHint
//        | Qt::WindowStaysOnBottomHint
//        | Qt::CustomizeWindowHint
;

}

namespace ZG::Panel{
    MainWindow::MainWindow(QWidget *parent)                         
        : MainWindow::MainWindow(parent, ::defaultWindowFlags) {}
    MainWindow::MainWindow(QWidget *parent, Qt::WindowFlags flags)  
        : QMainWindow(parent, flags){}
    MainWindow::MainWindow(Qt::WindowFlags flags) 
        : MainWindow::MainWindow(nullptr, flags) {}
    MainWindow::MainWindow() 
        : MainWindow::MainWindow(nullptr, ::defaultWindowFlags){}
}
