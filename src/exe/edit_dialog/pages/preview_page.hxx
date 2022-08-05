#pragma once

#include "./image_select_widget.hxx"
#include "data_model/requests/land_edit.hxx"

#include <QtWidgets>

namespace ZG::Panel::EditDialogInner
{

class PreviewPage : public QWidget
{
    Q_OBJECT

public:
    PreviewPage ( QWidget * parent = nullptr );
    PreviewPage ( Land data, QWidget *parent = nullptr );
    void extractData ( LandEditRequest & data );

private:
    QLineEdit * previewFileNameLineEdit;
    QLineEdit * previewFileExtensionLineEdit;
    QLineEdit * previewFileDataLineEdit;
    QLineEdit * previewFileDescriptionLineEdit;

    QLabel * previewImageLabel;

};

}