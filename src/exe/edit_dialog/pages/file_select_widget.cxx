#include "./file_select_widget.hxx"
#include "application/application.hxx"
#include "util.hxx"

namespace ZG::Panel 
{

FileSelectWidget::FileSelectWidget 
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

    fileNameLineEdit         = new QLineEdit ();
    fileExtensionLineEdit    = new QLineEdit ();
    fileDataLineEdit         = new QLineEdit ();
    fileDescriptionLineEdit  = new QLineEdit ();

    QLabel * fileNameLabel        = new QLabel ( tr("File name") );
    QLabel * fileExtensionLabel   = new QLabel ( tr("File extension") );
    QLabel * fileDataLabel        = new QLabel ( tr("File data") );
    QLabel * fileDescriptionLabel = new QLabel ( tr("File description") );

    fileNameLineEdit         -> setReadOnly ( true );
    fileExtensionLineEdit    -> setReadOnly ( true );
    fileDataLineEdit         -> setReadOnly ( true );

    QPushButton * selectPreviewButton   = new QPushButton ( tr("Select file") );
    QPushButton * deleteButton          = new QPushButton ( tr("Delete") );
    QPushButton * upArrowButton         = new QPushButton ( tr("Up") );
    QPushButton * downArrowButton       = new QPushButton ( tr("Down") );

    selectPreviewButton -> setMinimumWidth (80);
    deleteButton        -> setMinimumWidth (80);
    upArrowButton       -> setMinimumWidth (45);
    downArrowButton     -> setMinimumWidth (45);
    
    layout -> addWidget ( fileNameLabel,            0, 0, 1, 2);
    layout -> addWidget ( fileExtensionLabel,       1, 0, 1, 2);
    layout -> addWidget ( fileDataLabel,            2, 0, 1, 2);
    layout -> addWidget ( fileDescriptionLabel,     3, 0, 1, 2);

    layout -> addWidget ( fileNameLineEdit,         0, 2, 1, 2);
    layout -> addWidget ( fileExtensionLineEdit,    1, 2, 1, 2);
    layout -> addWidget ( fileDataLineEdit,         2, 2, 1, 2);
    layout -> addWidget ( fileDescriptionLineEdit,  3, 2, 1, 2);

    layout -> addItem ( 
        new QSpacerItem ( 0, 0, QSizePolicy::Ignored, QSizePolicy::MinimumExpanding), 4, 0
    );

    layout -> addWidget ( deleteButton,         5, 0 );
    layout -> addWidget ( upArrowButton,        5, 1 );
    layout -> addWidget ( downArrowButton,      5, 2 );
    layout -> addWidget ( selectPreviewButton,  5, 3 );

    layout -> setColumnStretch ( 1, 1 );
    layout -> setColumnStretch ( 2, 1 );

    layout -> setRowStretch    ( 4, 1 );
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
                tr("Files (*.*)")
            );

            if (!fileName.isNull()) 
            {
                QFileInfo fileInfo ( fileName );
                QString extension = fileInfo.completeSuffix ();
                QString fileShortName  = fileInfo.completeBaseName ();
                QImage  image ( fileName );
                QString byteData = fileToBase64 ( fileName );

                fileNameLineEdit         -> setText ( fileShortName );
                fileExtensionLineEdit    -> setText ( extension );
                fileDataLineEdit         -> setText ( byteData );
            }
        } 
    );

    connect ( deleteButton,     &QPushButton::clicked, this, &deleteButtonClicked       );
    connect ( upArrowButton,    &QPushButton::clicked, this, &upArrowButtonClicked      );
    connect ( downArrowButton,  &QPushButton::clicked, this, &downArrowButtonClicked    );
}

FileSelectWidget::FileSelectWidget 
(
    Land::URLField field,
    QWidget * parent 
) : FileSelectWidget ( parent )   
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

    fileNameLineEdit         -> setText ( fileShortName );
    fileExtensionLineEdit    -> setText ( extension );
    fileDataLineEdit         -> setText ( byteData );
    fileDescriptionLineEdit  -> setText ( QString::fromStdString ( field.description ) );
}

Land::DataField FileSelectWidget::getDataField ()
{
    return Land::DataField 
    (
        fileNameLineEdit        -> text().toStdString(),
        fileExtensionLineEdit   -> text().toStdString(),
        fileDataLineEdit        -> text().toStdString(),
        fileDescriptionLineEdit -> text().toStdString()
    );
}

}