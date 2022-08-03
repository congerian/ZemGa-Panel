#pragma once

#include <QtWidgets>

#include "./land_table_model.hxx"

namespace ZG::Panel{

class LandTableWidget : public QWidget
{
    Q_OBJECT
protected:
private:
    QTableView * tableView;
    LandTableModel * model;
    QGridLayout * layout;
public:
    explicit LandTableWidget(QWidget *parent = nullptr);
private slots:
};



}