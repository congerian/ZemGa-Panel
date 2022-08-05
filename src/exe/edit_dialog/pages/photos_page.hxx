#pragma once

#include "image_select_widget.hxx"
#include "data_model/requests/land_edit.hxx"

#include <QtWidgets>

namespace ZG::Panel::EditDialogInner
{

class PhotosPage : public QWidget
{
    Q_OBJECT

public:
    PhotosPage ( QWidget * parent = nullptr );
    PhotosPage ( Land data, QWidget *parent = nullptr );
    void extractData ( LandEditRequest & data );

private:
    QList <ImageSelectWidget *> widgets;
    QVBoxLayout * layout;

private slots:
    void deleteSendingWidget            ();
    void moveUpwardsSendingWidget       ();
    void moveDownwardsSendingWidget     ();
    void addImageSelectWidget           ();
    void addFileSelectWidget ( Land::URLField field );
};

}