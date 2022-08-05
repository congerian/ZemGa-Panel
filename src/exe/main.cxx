#include <QApplication>
#include <QPushButton>
#include <QTranslator>

#include <windows.h>

#include <iostream>

#include "application/application.hxx"
#include "main_window/main_window.hxx"

int main(int argc, char *argv[])
{

    QTranslator * translator = new QTranslator();
    translator -> load (":/i18n/translation.qm");
    ZG::Panel::Application app (argc, argv);
    app.installTranslator ( translator );

    ZG::Panel::MainWindow * mainWindow = new ZG::Panel::MainWindow();
    app.mainWindow = mainWindow;
    mainWindow->show();

    int code = app.exec();

    return code;
}