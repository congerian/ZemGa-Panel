#include "./preview_page.hxx"
#include "application/application.hxx"
#include "util.hxx"

namespace ZG::Panel::EditDialogInner 
{

PreviewPage::PreviewPage (QWidget * parent)
    :   QWidget (parent)
{
    QGridLayout * layout = new QGridLayout (this);

    previewFileNameLineEdit         = new QLineEdit ();
    previewFileExtensionLineEdit    = new QLineEdit ();
    previewFileDataLineEdit         = new QLineEdit ();
    previewFileDescriptionLineEdit  = new QLineEdit ();

    QLabel * previewFileNameLabel           = new QLabel ( tr("Preview file name") );
    QLabel * previewFileExtensionLabel      = new QLabel ( tr("Preview file extension") );
    QLabel * previewFileDataLabel           = new QLabel ( tr("Preview file data") );
    QLabel * previewFileDescriptionLabel    = new QLabel ( tr("Preview file description") );

    previewImageLabel = new QLabel ( );

    //previewFileNameLineEdit         -> setReadOnly ( true );
    previewFileExtensionLineEdit    -> setReadOnly ( true );
    previewFileDataLineEdit         -> setReadOnly ( true );

    QPushButton * selectPreviewButton = new QPushButton ( tr("Select image") );
    
    layout -> addWidget ( previewFileNameLabel,         0, 0 );
    layout -> addWidget ( previewFileExtensionLabel,    1, 0 );
    layout -> addWidget ( previewFileDataLabel,         2, 0 );
    layout -> addWidget ( previewFileDescriptionLabel,  3, 0 );

    layout -> addWidget ( previewFileNameLineEdit,          0, 1 );
    layout -> addWidget ( previewFileExtensionLineEdit,     1, 1 );
    layout -> addWidget ( previewFileDataLineEdit,          2, 1 );
    layout -> addWidget ( previewFileDescriptionLineEdit,   3, 1 );

    layout -> addWidget ( previewImageLabel,      4, 0, 1, 2, Qt::AlignCenter);
    
    layout -> addItem ( 
        new QSpacerItem ( 0, 0, QSizePolicy::Ignored, QSizePolicy::MinimumExpanding), 5, 0
    );

    layout -> addWidget ( selectPreviewButton, 6, 1 );

    layout -> setColumnStretch ( 1, 1 );
    layout -> setHorizontalSpacing ( 20 );
    
    connect 
    ( 
        selectPreviewButton, 
        QPushButton::clicked,
        this,
        [this] () 
        {
            QString fileName = QFileDialog::getOpenFileName 
            (
                this, 
                tr("Open File"),
                QStringLiteral(""),
                tr("Images (*.png *.xpm *.jpg)")
            );

            if (!fileName.isNull()) 
            {
                QFileInfo fileInfo ( fileName );
                QString extension = fileInfo.completeSuffix ();
                QString fileShortName  = fileInfo.completeBaseName ();
                QImage  image ( fileName );
                QString byteData = fileToBase64 ( fileName );

                previewImageLabel -> setPixmap ( QPixmap::fromImage ( image.scaled (200, 200, Qt::KeepAspectRatio) ) );

                previewFileNameLineEdit         -> setText ( fileShortName );
                previewFileExtensionLineEdit    -> setText ( extension );
                previewFileDataLineEdit         -> setText ( byteData );
            }
        } 
    );
}

PreviewPage::PreviewPage 
(
    Land data,
    QWidget * parent
) : PreviewPage (parent)
{
    QUrl url ( QString::fromStdString ( data.fields.previewURL.URL ) );
    QFileInfo fileInfo ( url.fileName() );
    QString extension = fileInfo.completeSuffix ();
    QString fileShortName  = fileInfo.completeBaseName ();
    QString byteData;

    QEventLoop loop;
    ((Application *) Application::instance())->getRequester()->downloadFile
    (
        QString::fromStdString ( data.fields.previewURL.URL ),
        this,
        [&loop, &byteData] ( QNetworkReply * reply ) 
        {
            loop.quit();
            byteData = QString( reply -> readAll().toBase64());
            //qDebug() << byteData;
        } 
    );
    loop.exec();

    QByteArray byteArray = QByteArray::fromBase64 ( byteData.toUtf8() );

    QImage image = QImage::fromData ( byteArray, extension.toUtf8().data());

    previewImageLabel -> setPixmap ( QPixmap::fromImage ( image.scaled (200, 200, Qt::KeepAspectRatio) ) );

    previewFileNameLineEdit         -> setText ( fileShortName );
    previewFileExtensionLineEdit    -> setText ( extension );
    previewFileDataLineEdit         -> setText ( byteData );
    previewFileDescriptionLineEdit  -> setText ( QString::fromStdString ( data.fields.previewURL.description ) );
}

void PreviewPage::extractData ( LandEditRequest & data )
{
    data.preview.name           = previewFileNameLineEdit           -> text().toStdString(); 
    data.preview.extension      = previewFileExtensionLineEdit      -> text().toStdString(); 
    data.preview.description    = previewFileDescriptionLineEdit    -> text().toStdString(); 
    data.preview.data           =  previewFileDataLineEdit          -> text().toStdString(); 
}

}