#pragma once

#include "data_model/land/land.hxx"

#include <QtWidgets>

namespace ZG::Panel
{

class LocationWidget : public QWidget
{
    Q_OBJECT

public:
    LocationWidget ( QWidget * parent = nullptr );
    LocationWidget ( Land::Location loc, QWidget * parent = nullptr );

    Land::Location getLocation (); 

private:
    QLineEdit * yCoordLineEdit;
    QLineEdit * xCoordLineEdit;

signals:
    void deleteButtonClicked ();
    void upArrowButtonClicked ();
    void downArrowButtonClicked ();
};

}