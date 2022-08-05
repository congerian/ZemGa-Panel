#include "./image_select_widget.hxx"
#include "application/application.hxx"
#include "util.hxx"

namespace ZG::Panel 
{

ImageSelectWidget::ImageSelectWidget 
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

    imageNameLineEdit         = new QLineEdit ();
    imageExtensionLineEdit    = new QLineEdit ();
    imageDataLineEdit         = new QLineEdit ();
    imageDescriptionLineEdit      = new QLineEdit ();

    QLabel * imageNameLabel         = new QLabel ( tr("Image name") );
    QLabel * imageExtensionLabel    = new QLabel ( tr("Image extension") );
    QLabel * imageDataLabel         = new QLabel ( tr("Image data") );
    QLabel * imageDescriptionLabel  = new QLabel ( tr("Image description") );

    imageLabel = new QLabel ( );

    imageExtensionLineEdit    -> setReadOnly ( true );
    imageDataLineEdit         -> setReadOnly ( true );

    QPushButton * selectPreviewButton   = new QPushButton ( tr("Select image") );
    QPushButton * deleteButton          = new QPushButton ( tr("Delete") );
    QPushButton * upArrowButton         = new QPushButton ( tr("Up") );
    QPushButton * downArrowButton       = new QPushButton ( tr("Down") );

    selectPreviewButton -> setMinimumWidth (80);
    deleteButton        -> setMinimumWidth (80);
    upArrowButton       -> setMinimumWidth (45);
    downArrowButton     -> setMinimumWidth (45);
    
    layout -> addWidget ( imageNameLabel,         0, 0, 1, 2);
    layout -> addWidget ( imageExtensionLabel,    1, 0, 1, 2);
    layout -> addWidget ( imageDataLabel,         2, 0, 1, 2);
    layout -> addWidget ( imageDescriptionLabel,  3, 0, 1, 2);

    layout -> addWidget ( imageNameLineEdit,        0, 2, 1, 2);
    layout -> addWidget ( imageExtensionLineEdit,   1, 2, 1, 2);
    layout -> addWidget ( imageDataLineEdit,        2, 2, 1, 2);
    layout -> addWidget ( imageDescriptionLineEdit, 3, 2, 1, 2);

    layout -> addWidget ( imageLabel,      4, 1, 1, 2, Qt::AlignCenter);
    
    layout -> addItem ( 
        new QSpacerItem ( 0, 0, QSizePolicy::Ignored, QSizePolicy::MinimumExpanding), 5, 0
    );

    layout -> addWidget ( deleteButton,         6, 0 );
    layout -> addWidget ( upArrowButton,        6, 1 );
    layout -> addWidget ( downArrowButton,      6, 2 );
    layout -> addWidget ( selectPreviewButton,  6, 3 );

    layout -> setColumnStretch ( 1, 1 );
    layout -> setColumnStretch ( 2, 1 );

    layout -> setRowStretch    ( 5, 1 );
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
                QString byteData = fileToBase64 ( fileName );
                
                QImage  image ( fileName );

                imageLabel -> setPixmap ( QPixmap::fromImage ( image.scaled (200, 200, Qt::KeepAspectRatio) ) );

                imageNameLineEdit         -> setText ( fileShortName );
                imageExtensionLineEdit    -> setText ( extension );
                imageDataLineEdit         -> setText ( byteData );
            }
        } 
    );

    connect ( deleteButton,     &QPushButton::clicked, this, &deleteButtonClicked       );
    connect ( upArrowButton,    &QPushButton::clicked, this, &upArrowButtonClicked      );
    connect ( downArrowButton,  &QPushButton::clicked, this, &downArrowButtonClicked    );
}

ImageSelectWidget::ImageSelectWidget 
(
    Land::URLField field,
    QWidget * parent 
) : ImageSelectWidget ( parent )   
{
    QUrl url ( QString::fromStdString ( field.URL ) );
    QFileInfo fileInfo ( url.fileName() );
    QString extension = fileInfo.completeSuffix ();
    QString fileShortName  = fileInfo.completeBaseName ();
    QString byteData;

    QEventLoop loop;
    ((Application *) Application::instance())->getRequester()->downloadFile
    (
        QString::fromStdString ( field.URL ),
        this,
        [&loop, &byteData] ( QNetworkReply * reply ) 
        {
            loop.quit();
            byteData = QString( reply -> readAll().toBase64());
        } 
    );
    loop.exec();

    QByteArray byteArray = QByteArray::fromBase64 ( byteData.toUtf8() );

    QImage image = QImage::fromData ( byteArray, extension.toUtf8().data());

    imageLabel -> setPixmap ( QPixmap::fromImage ( image.scaled (200, 200, Qt::KeepAspectRatio) ) );

    imageNameLineEdit         -> setText ( fileShortName );
    imageExtensionLineEdit    -> setText ( extension );
    imageDataLineEdit         -> setText ( byteData );
    imageDescriptionLineEdit  -> setText ( QString::fromStdString ( field.description ) );
}

Land::DataField ImageSelectWidget::getDataField ()
{
    return Land::DataField 
    (
        imageNameLineEdit        -> text().toStdString(),
        imageExtensionLineEdit   -> text().toStdString(),
        imageDataLineEdit        -> text().toStdString(),
        imageDescriptionLineEdit -> text().toStdString()
    );
}

}