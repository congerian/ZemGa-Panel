#include "./edit_dialog.hxx"
#include "application/application.hxx"

namespace ZG::Panel
{

EditDialog::EditDialog (QWidget * parent) 
    :   QDialog (parent)
{
    resize (500, 600);

    QGridLayout * verticalLayout    = new QGridLayout ( this );
    QToolBox    * toolbox           = new QToolBox ();
    QPushButton * applyButton       = new QPushButton ( tr("Create") );

    verticalLayout -> addWidget ( toolbox );
    verticalLayout -> addWidget ( applyButton );

    setWindowTitle ( tr("Creating new land") );

    mainPage       = new MainPage        ();
    borderLocsPage = new BorderLocsPage  ();
    docsPage       = new DocsPage        ();
    photosPage     = new PhotosPage      ();
    previewPage    = new PreviewPage     ();

    toolbox -> addItem ( mainPage,          tr("Main page")       );
    toolbox -> addItem ( previewPage,       tr("Preview page")    );
    toolbox -> addItem ( docsPage,          tr("Docs page")       );
    toolbox -> addItem ( photosPage,        tr("Photos page")     );
    toolbox -> addItem ( borderLocsPage,    tr("BorderLocs page") );

    connect 
    ( 
        applyButton, 
        &QPushButton::clicked, 
        this,
        [this] () 
        {
            LandEditRequest request = extractData ();
            ( ( Application * ) Application::instance() ) -> getRequester() -> adminAdd 
            ( 
                request,
                this,
                [] ( QNetworkReply * reply ) 
                {   
                    qDebug() << QString::fromUtf8(reply->readAll());
                    ( ( Application * ) Application::instance() ) -> mainWindow -> update();
                }
            );
        } 
    );
}

EditDialog::EditDialog 
(
    Land data,
    QWidget * parent
) : QDialog (parent)
{
    resize (500, 600);

    QGridLayout * verticalLayout    = new QGridLayout ( this );
    QToolBox    * toolbox           = new QToolBox ();

    QPushButton * applyButton       = new QPushButton ( tr("Update") );

    verticalLayout -> addWidget ( toolbox );
    verticalLayout -> addWidget ( applyButton );

    setWindowTitle ( tr("Updating land: %1").arg ( data.fields.id ) );

    mainPage       = new MainPage        ( data );
    borderLocsPage = new BorderLocsPage  ( data );
    docsPage       = new DocsPage        ( data );
    photosPage     = new PhotosPage      ( data );
    previewPage    = new PreviewPage     ( data );

    toolbox -> addItem ( mainPage,          tr("Main page")       );
    toolbox -> addItem ( previewPage,       tr("Preview page")    );
    toolbox -> addItem ( docsPage,          tr("Docs page")       );
    toolbox -> addItem ( photosPage,        tr("Photos page")     );
    toolbox -> addItem ( borderLocsPage,    tr("BorderLocs page") );

    connect 
    ( 
        applyButton, 
        &QPushButton::clicked, 
        this,
        [this] () 
        {
            LandEditRequest request = extractData ();
            ( ( Application * ) Application::instance() ) -> getRequester() -> adminUpdate 
            ( 
                request,
                this,
                [] ( QNetworkReply * reply ) 
                {
                    qDebug() << QString::fromUtf8(reply->readAll());
                    ( ( Application * ) Application::instance() ) -> mainWindow -> update();
                }
            );
        } 
    );
}

LandEditRequest EditDialog::extractData ()
{
    LandEditRequest request;
    borderLocsPage  -> extractData( request );
    docsPage        -> extractData( request );
    mainPage        -> extractData( request );
    photosPage      -> extractData( request );
    previewPage     -> extractData( request );

    return request;
}

}