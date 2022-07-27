#pragma once

#include <QMainWindow>

namespace ZG::Panel{

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent, Qt::WindowFlags flags);
    MainWindow(QWidget *parent);
    MainWindow(Qt::WindowFlags flags);
    MainWindow();
private slots:
};



}