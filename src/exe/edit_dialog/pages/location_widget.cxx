#include "./location_widget.hxx"
#include "util.hxx"

namespace ZG::Panel 
{

LocationWidget::LocationWidget 
(
    QWidget * parent 
) : QWidget ( parent )   
{
    QVBoxLayout * helperLayout = new QVBoxLayout ( this );
    QGroupBox * groupBox = new QGroupBox ( this );

    helperLayout -> setSpacing ( 0 );
    helperLayout -> setContentsMargins ( 0, 0, 0, 0 );

    helperLayout->addWidget ( groupBox, 1 );

    QGridLayout * layout = new QGridLayout ( groupBox );
    groupBox -> setLayout ( layout ); 

    yCoordLineEdit  = new QLineEdit ();
    xCoordLineEdit  = new QLineEdit ();

    QLabel * xCoordLabel  = new QLabel ( tr("Latitude") );
    QLabel * yCoordLabel       = new QLabel ( tr("Longitude") );

    QPushButton * deleteButton          = new QPushButton ( tr("Delete") );
    QPushButton * upArrowButton         = new QPushButton ( tr("Up") );
    QPushButton * downArrowButton       = new QPushButton ( tr("Down") );

    deleteButton        -> setMinimumWidth (80);
    upArrowButton       -> setMinimumWidth (45);
    downArrowButton     -> setMinimumWidth (45);
    
    layout -> addWidget ( xCoordLabel,  0, 0, 1, 2);
    layout -> addWidget ( yCoordLabel,  1, 0, 1, 2);

    layout -> addWidget ( xCoordLineEdit, 0, 2, 1, 2);
    layout -> addWidget ( yCoordLineEdit, 1, 2, 1, 2);

    layout -> addWidget ( upArrowButton,   3, 1 );
    layout -> addWidget ( downArrowButton, 3, 2 );
    layout -> addWidget ( deleteButton,    3, 3 );

    layout -> addItem ( 
        new QSpacerItem ( 0, 0, QSizePolicy::Ignored, QSizePolicy::MinimumExpanding), 2, 0
    );

    layout -> setColumnStretch ( 3, 1 );

    layout -> setRowStretch    ( 2, 1 );
    layout -> setHorizontalSpacing ( 20 );

    connect ( deleteButton,     &QPushButton::clicked, this, &deleteButtonClicked       );
    connect ( upArrowButton,    &QPushButton::clicked, this, &upArrowButtonClicked      );
    connect ( downArrowButton,  &QPushButton::clicked, this, &downArrowButtonClicked    );
}

LocationWidget::LocationWidget 
(
    Land::Location land,
    QWidget * parent 
) : LocationWidget ( parent )
{
    xCoordLineEdit -> setText ( QString::number ( land.lat ) );
    yCoordLineEdit -> setText ( QString::number ( land.lon ) );
}

Land::Location LocationWidget::getLocation () 
{
    return Land::Location 
    ( 
        xCoordLineEdit -> text().toDouble(), 
        yCoordLineEdit -> text().toDouble()
    );
}

}