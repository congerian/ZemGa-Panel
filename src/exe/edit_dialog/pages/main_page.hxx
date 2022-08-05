#pragma once

#include "data_model/requests/land_edit.hxx"

#include <QtWidgets>

namespace ZG::Panel::EditDialogInner
{

class MainPage : public QWidget
{
    Q_OBJECT

public:
    MainPage ( QWidget * parent = nullptr );
    MainPage ( Land data, QWidget *parent = nullptr );
    void extractData ( LandEditRequest & data );

private:
    QLineEdit * idLineEdit;
    QLineEdit * nameLineEdit;
    QLineEdit * descriptionLineEdit;
    QLineEdit * reglamentLineEdit;
    QLineEdit * kadastrLineEdit;
    QLineEdit * usageLineEdit;
    QLineEdit * squareLineEdit;
    QLineEdit * typeLineEdit;
    QLineEdit * priceLineEdit;
    QLineEdit * districtLineEdit;
    QLineEdit * addressLineEdit;
    QLineEdit * locationXLineEdit;
    QLineEdit * locationYLineEdit;

};



}