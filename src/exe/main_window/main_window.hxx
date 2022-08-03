#pragma once

#include <QtWidgets>

#include "./land_table/land_table_widget.hxx"

namespace {
    Qt::WindowFlags defaultWindowFlags = Qt::WindowFlags() 
//        | Qt::MSWindowsFixedSizeDialogHint
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

class MainWindow : public QMainWindow
{
    Q_OBJECT
protected:
    
private:
    LandTableWidget * tableView;
public:
    MainWindow(QWidget *parent = nullptr, Qt::WindowFlags flags = ::defaultWindowFlags);
private slots:
    void update();
    
};



}