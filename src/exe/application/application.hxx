#pragma once

#include <QApplication>

#include "../requester/requester.hxx"
#include "../main_window/main_window.hxx"

namespace ZG::Panel{

class Application : public QApplication
{
    Q_OBJECT
private:
    Requester requester;
public:
    Application(int argc, char *argv[]);
    MainWindow * mainWindow;
    
    ~Application();
signals:
private slots:
};

}



