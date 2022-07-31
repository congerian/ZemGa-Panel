#include <QApplication>

#include <windows.h>

#include <iostream>

#include "application/application.hxx"
#include "main_window/main_window.hxx"

int main(int argc, char *argv[])
{
    ZG::Panel::Application app(argc, argv);

    ZG::Panel::MainWindow mainWindow;

    mainWindow.resize(500, 500);

    mainWindow.show();
    return app.exec();
}
