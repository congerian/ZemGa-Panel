#pragma once

#include "./file_select_widget.hxx"
#include "data_model/requests/land_edit.hxx"

#include <QtWidgets>

namespace ZG::Panel::EditDialogInner
{

class DocsPage : public QWidget
{
    Q_OBJECT

public:
    DocsPage ( QWidget * parent = nullptr );
    DocsPage ( Land data, QWidget *parent = nullptr );
    void extractData ( LandEditRequest & data );

private:
    QList <FileSelectWidget *> widgets;
    QVBoxLayout * layout;

private slots:
    void deleteSendingWidget            ();
    void moveUpwardsSendingWidget       ();
    void moveDownwardsSendingWidget     ();
    void addFileSelectWidget            ();
    void addFileSelectWidget ( Land::URLField field );
};

}