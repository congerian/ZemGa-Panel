#include "./photos_page.hxx"

namespace ZG::Panel::EditDialogInner 
{

PhotosPage::PhotosPage (QWidget * parent)
    :   QWidget (parent)
{
    QVBoxLayout * helperLayout = new QVBoxLayout ();
    QWidget     * helperWidget = new QWidget ();
    
    layout = new QVBoxLayout ();

    this            -> setLayout ( helperLayout );
    helperWidget    -> setLayout ( layout );


    QPushButton * addButton = new QPushButton ( tr("Add image") );

    helperLayout -> setContentsMargins ( 0, 0, 0, 0 );
    helperLayout -> addWidget ( helperWidget, 1 );
    helperLayout -> addWidget ( addButton, 0 );

    connect ( addButton, &QPushButton::clicked, this, &addImageSelectWidget);
}

void PhotosPage::addImageSelectWidget () 
{
    ImageSelectWidget * widget = new ImageSelectWidget ();

    connect ( widget, ImageSelectWidget::deleteButtonClicked,       this, &deleteSendingWidget          );
    connect ( widget, ImageSelectWidget::upArrowButtonClicked,      this, &moveUpwardsSendingWidget     );
    connect ( widget, ImageSelectWidget::downArrowButtonClicked,    this, &moveDownwardsSendingWidget   );

    widgets.append ( widget );
    layout -> addWidget ( widget );
}

void PhotosPage::deleteSendingWidget () 
{
    ImageSelectWidget * widget = (ImageSelectWidget *) sender ();
    if (!widget) return;

    widgets.removeOne (widget);
    layout -> removeWidget (widget);
    widget -> deleteLater ();
}

void PhotosPage::moveUpwardsSendingWidget () 
{
    ImageSelectWidget * widget = (ImageSelectWidget *) sender ();
    if ( !widget ) return;

    size_t index = layout -> indexOf ( widget );
    if ( index == 0 ) return;

    layout -> removeWidget ( widget );
    layout -> insertWidget ( index - 1, widget );
}

void PhotosPage::moveDownwardsSendingWidget () 
{
    ImageSelectWidget * widget = (ImageSelectWidget *) sender ();
    if ( !widget ) return;

    size_t index = layout -> indexOf ( widget );
    if ( index == layout -> count() - 1 ) return;

    layout -> removeWidget ( widget );
    layout -> insertWidget ( index + 1, widget );
}

PhotosPage::PhotosPage 
( 
    Land data, 
    QWidget * parent
) : PhotosPage ( parent )
{
    
    for ( Land::URLField field : data.fields.photos )
    {
        addFileSelectWidget ( field );   
    }
}

void PhotosPage::extractData ( LandEditRequest & data ) 
{
    for ( ImageSelectWidget * widget : widgets )
    {
        data.docs.push_back ( widget -> getDataField() );
    }
}

void PhotosPage::addFileSelectWidget ( Land::URLField field ) 
{
    ImageSelectWidget * widget = new ImageSelectWidget ( field );

    connect ( widget, ImageSelectWidget::deleteButtonClicked,       this, &deleteSendingWidget          );
    connect ( widget, ImageSelectWidget::upArrowButtonClicked,      this, &moveUpwardsSendingWidget     );
    connect ( widget, ImageSelectWidget::downArrowButtonClicked,    this, &moveDownwardsSendingWidget   );

    widgets.append ( widget );
    layout -> addWidget ( widget );
}

}