#pragma once

#include "data_model/land/land.hxx"

#include <QtWidgets>

namespace ZG::Panel
{

class FileSelectWidget : public QWidget
{
    Q_OBJECT

public:
    FileSelectWidget ( QWidget * parent = nullptr );
    FileSelectWidget ( Land::URLField field, QWidget * parent = nullptr );
    Land::DataField getDataField ();
private:
    QLineEdit * fileNameLineEdit;
    QLineEdit * fileExtensionLineEdit;
    QLineEdit * fileDataLineEdit;
    QLineEdit * fileDescriptionLineEdit;

signals:
    void deleteButtonClicked ();
    void upArrowButtonClicked ();
    void downArrowButtonClicked ();
};

}