#pragma once

#include <QtWidgets>

#include "./land_table_model.hxx"

namespace ZG::Panel{

class LandTableWidget : public QWidget
{
    Q_OBJECT
protected:
private:
    QTableView * _tableView;
    LandTableModel * _model;
    QGridLayout * _layout;
public:
    explicit LandTableWidget(QWidget *parent = nullptr);
    QTableView * tableView();
    LandTableModel * model();
private slots:
};



}