#pragma once

#include <QtWidgets>

#include "./client_table_model.hxx"

namespace ZG::Panel{

class ClientTableWidget : public QWidget
{
    Q_OBJECT
protected:
private:
    QTableView * _tableView;
    ClientTableModel * _model;
    QGridLayout * _layout;
public:
    explicit ClientTableWidget(QWidget *parent = nullptr);
    QTableView * tableView();
    ClientTableModel * model();
private slots:
};



}