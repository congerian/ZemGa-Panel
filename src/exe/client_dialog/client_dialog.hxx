#pragma once

#include <QtWidgets>

#include "./client_table/client_table_model.hxx"
#include "./client_table/client_table_widget.hxx"

#include "util.hxx"

namespace ZG::Panel{

class ClientDialog : public QMainWindow
{
    Q_OBJECT

protected:
    
private:
    ClientTableWidget * tableWidget;

    QAction * updateAction;

public:
    ClientDialog(QWidget *parent = nullptr, Qt::WindowFlags flags = ::defaultWindowFlags);

public slots:
    void update ();

};



}