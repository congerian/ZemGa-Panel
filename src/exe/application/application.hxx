#pragma once

#include <QApplication>

#include "../requester/requester.hxx"

namespace ZG::Panel{

class Application : public QApplication
{
    Q_OBJECT
private:
    Requester requester;
public:
    Application(int argc, char *argv[]);
signals:
private slots:
};

}



