#pragma once

#include <QApplication>

namespace ZG::Panel{


class Application : public QApplication
{
    Q_OBJECT
public:
    Application(int argc, char *argv[]);
private slots:
};

}



