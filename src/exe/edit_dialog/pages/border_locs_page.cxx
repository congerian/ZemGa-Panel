#include "./border_locs_page.hxx"

namespace ZG::Panel::EditDialogInner 
{

BorderLocsPage::BorderLocsPage (QWidget * parent)
    :   QWidget (parent)
{
    QVBoxLayout * helperLayout = new QVBoxLayout ();
    QWidget     * helperWidget = new QWidget ();
    
    layout = new QVBoxLayout ();

    this            -> setLayout ( helperLayout );
    helperWidget    -> setLayout ( layout );


    QPushButton * addButton = new QPushButton ( tr("Add location") );

    helperLayout -> setContentsMargins ( 0, 0, 0, 0 );
    helperLayout -> addWidget ( helperWidget, 1 );
    helperLayout -> addWidget ( addButton, 0 );

    connect ( addButton, &QPushButton::clicked, this, qOverload<>(&addLocationWidget));
}

BorderLocsPage::BorderLocsPage 
( 
    Land data, 
    QWidget *parent 
) :  BorderLocsPage ( parent )
{
    for (Land::Location loc : data.fields.borderLocs) 
    {
        addLocationWidget ( loc );
    }
}

void BorderLocsPage::extractData ( LandEditRequest & data ) 
{
    for ( LocationWidget * widget : widgets )
    {
        data.borderLocs.push_back ( widget -> getLocation() );
    }
}

void BorderLocsPage::addLocationWidget () 
{
    LocationWidget * widget = new LocationWidget ();

    connect ( widget, LocationWidget::deleteButtonClicked,       this, &deleteSendingWidget          );
    connect ( widget, LocationWidget::upArrowButtonClicked,      this, &moveUpwardsSendingWidget     );
    connect ( widget, LocationWidget::downArrowButtonClicked,    this, &moveDownwardsSendingWidget   );

    widgets.append ( widget );
    layout -> addWidget ( widget );
}

void BorderLocsPage::addLocationWidget ( Land::Location location ) 
{
    LocationWidget * widget = new LocationWidget ( location );

    connect ( widget, LocationWidget::deleteButtonClicked,       this, &deleteSendingWidget          );
    connect ( widget, LocationWidget::upArrowButtonClicked,      this, &moveUpwardsSendingWidget     );
    connect ( widget, LocationWidget::downArrowButtonClicked,    this, &moveDownwardsSendingWidget   );

    widgets.append ( widget );
    layout -> addWidget ( widget );
}

void BorderLocsPage::deleteSendingWidget () 
{
    LocationWidget * widget = (LocationWidget *) sender ();
    if (!widget) return;

    widgets.removeOne (widget);
    layout -> removeWidget (widget);
    widget -> deleteLater ();
}

void BorderLocsPage::moveUpwardsSendingWidget () 
{
    LocationWidget * widget = (LocationWidget *) sender ();
    if ( !widget ) return;

    size_t index = layout -> indexOf ( widget );
    if ( index == 0 ) return;

    layout -> removeWidget ( widget );
    layout -> insertWidget ( index - 1, widget );
}

void BorderLocsPage::moveDownwardsSendingWidget () 
{
    LocationWidget * widget = (LocationWidget *) sender ();
    if ( !widget ) return;

    size_t index = layout -> indexOf ( widget );
    if ( index == layout -> count() - 1 ) return;

    layout -> removeWidget ( widget );
    layout -> insertWidget ( index + 1, widget );
}

}