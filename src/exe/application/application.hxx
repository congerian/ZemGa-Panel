#pragma once

#include <QApplication>

#include "main_window/main_window.hxx"
#include "requester/panel_requester.hxx"

namespace ZG::Panel{

class Application : public QApplication
{
    Q_OBJECT

private:

    PanelRequester * requester;

public:

    Application(int argc, char *argv[]);
    MainWindow * mainWindow;
    
    PanelRequester * getRequester();

    ~Application();

signals:

private slots:

};

}



