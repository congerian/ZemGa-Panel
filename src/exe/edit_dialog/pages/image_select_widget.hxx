#pragma once

#include "data_model/land/land.hxx"

#include <QtWidgets>

namespace ZG::Panel
{

class ImageSelectWidget : public QWidget
{
    Q_OBJECT

public:
    ImageSelectWidget ( QWidget * parent = nullptr );
    ImageSelectWidget ( Land::URLField field, QWidget * parent = nullptr );
    Land::DataField getDataField ();

private:
    QLineEdit * imageNameLineEdit;
    QLineEdit * imageExtensionLineEdit;
    QLineEdit * imageDataLineEdit;
    QLineEdit * imageDescriptionLineEdit;

    QLabel * imageLabel;
signals:
    void deleteButtonClicked ();
    void upArrowButtonClicked ();
    void downArrowButtonClicked ();
};

}