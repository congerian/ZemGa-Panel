#include <QApplication>
#include <QPushButton>

#include <windows.h>

#include <iostream>

#include "application/application.hxx"
#include "main_window/main_window.hxx"

int main(int argc, char *argv[])
{
    ZG::Panel::Application * app = new ZG::Panel::Application(argc, argv);
    app->mainWindow->show();
    int code = app->exec();
    delete app;
    return code;
}