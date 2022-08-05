#pragma once

#include "./location_widget.hxx"
#include "data_model/requests/land_edit.hxx"

#include <QtWidgets>

namespace ZG::Panel::EditDialogInner
{

class BorderLocsPage : public QWidget
{
    Q_OBJECT

public:
    BorderLocsPage ( QWidget * parent = nullptr );
    BorderLocsPage ( Land data, QWidget *parent = nullptr );
    void extractData ( LandEditRequest & data );

private:
    QList <LocationWidget *> widgets;
    QVBoxLayout * layout;

private slots:
    void deleteSendingWidget            ();
    void moveUpwardsSendingWidget       ();
    void moveDownwardsSendingWidget     ();
    void addLocationWidget              ();

    void addLocationWidget              ( Land::Location );
};

}