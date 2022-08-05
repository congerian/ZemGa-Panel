#include "./docs_page.hxx"
#include "application/application.hxx"

namespace ZG::Panel::EditDialogInner 
{

DocsPage::DocsPage (QWidget * parent)
    :   QWidget (parent)
{
    QVBoxLayout * helperLayout = new QVBoxLayout ();
    QWidget     * helperWidget = new QWidget ();
    
    layout = new QVBoxLayout ();

    this            -> setLayout ( helperLayout );
    helperWidget    -> setLayout ( layout );


    QPushButton * addButton = new QPushButton ( tr("Add file") );

    helperLayout -> setContentsMargins ( 0, 0, 0, 0 );
    helperLayout -> addWidget ( helperWidget, 1 );
    helperLayout -> addWidget ( addButton, 0 );

    connect ( addButton, &QPushButton::clicked, this, qOverload<>(&addFileSelectWidget) );
}

DocsPage::DocsPage 
( 
    Land data, 
    QWidget * parent
) : DocsPage ( parent )
{
    
    for ( Land::URLField field : data.fields.docURLs )
    {
        addFileSelectWidget ( field );   
    }
}

void DocsPage::extractData ( LandEditRequest & data ) 
{
    for ( FileSelectWidget * widget : widgets )
    {
        data.docs.push_back ( widget -> getDataField() );
    }
}

void DocsPage::addFileSelectWidget () 
{
    FileSelectWidget * widget = new FileSelectWidget ();

    connect ( widget, FileSelectWidget::deleteButtonClicked,       this, &deleteSendingWidget          );
    connect ( widget, FileSelectWidget::upArrowButtonClicked,      this, &moveUpwardsSendingWidget     );
    connect ( widget, FileSelectWidget::downArrowButtonClicked,    this, &moveDownwardsSendingWidget   );

    widgets.append ( widget );
    layout -> addWidget ( widget );
}

void DocsPage::addFileSelectWidget ( Land::URLField field ) 
{
    FileSelectWidget * widget = new FileSelectWidget ( field );

    connect ( widget, FileSelectWidget::deleteButtonClicked,       this, &deleteSendingWidget          );
    connect ( widget, FileSelectWidget::upArrowButtonClicked,      this, &moveUpwardsSendingWidget     );
    connect ( widget, FileSelectWidget::downArrowButtonClicked,    this, &moveDownwardsSendingWidget   );

    widgets.append ( widget );
    layout -> addWidget ( widget );
}

void DocsPage::deleteSendingWidget () 
{
    FileSelectWidget * widget = (FileSelectWidget *) sender ();
    if (!widget) return;

    widgets.removeOne (widget);
    layout -> removeWidget (widget);
    widget -> deleteLater ();
}

void DocsPage::moveUpwardsSendingWidget () 
{
    FileSelectWidget * widget = (FileSelectWidget *) sender ();
    if ( !widget ) return;

    size_t index = layout -> indexOf ( widget );
    if ( index == 0 ) return;

    layout -> removeWidget ( widget );
    layout -> insertWidget ( index - 1, widget );
}

void DocsPage::moveDownwardsSendingWidget () 
{
    FileSelectWidget * widget = (FileSelectWidget *) sender ();
    if ( !widget ) return;

    size_t index = layout -> indexOf ( widget );
    if ( index == layout -> count() - 1 ) return;

    layout -> removeWidget ( widget );
    layout -> insertWidget ( index + 1, widget );
}

}