#pragma once

#include <QtWidgets>

namespace ZG::Panel{

class LandTableWidget : public QWidget
{
    Q_OBJECT
protected:
private:
    QTableWidget * table;
    QGridLayout * layout;
public:
    explicit LandTableWidget(QWidget *parent = nullptr);
private slots:
};



}