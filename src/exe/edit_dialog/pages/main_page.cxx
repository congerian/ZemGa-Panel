#include "./main_page.hxx"

namespace ZG::Panel::EditDialogInner 
{

MainPage::MainPage (QWidget * parent)
    :   QWidget (parent)
{
    QGridLayout * layout = new QGridLayout (this);
    this -> setLayout ( layout );

    QLabel * idLabel            = new QLabel ( tr("Id") );
    QLabel * nameLabel          = new QLabel ( tr("Name") );
    QLabel * descriptionLabel   = new QLabel ( tr("Description") );
    QLabel * reglamentLabel     = new QLabel ( tr("Reglament") );
    QLabel * kadastrLabel       = new QLabel ( tr("Kadastr") );
    QLabel * usageLabel         = new QLabel ( tr("Usage") );
    QLabel * squareLabel        = new QLabel ( tr("Square") );
    QLabel * typeLabel          = new QLabel ( tr("Type") );
    QLabel * priceLabel         = new QLabel ( tr("Price") );
    QLabel * districtLabel      = new QLabel ( tr("District") );
    QLabel * addressLabel       = new QLabel ( tr("Address") );
    QLabel * locationXLabel     = new QLabel ( tr("LocationX") );
    QLabel * locationYLabel     = new QLabel ( tr("LocationY") );


    idLineEdit          = new QLineEdit ();
    nameLineEdit        = new QLineEdit ();
    descriptionLineEdit = new QLineEdit ();
    reglamentLineEdit   = new QLineEdit ();
    kadastrLineEdit     = new QLineEdit ();
    usageLineEdit       = new QLineEdit ();
    squareLineEdit      = new QLineEdit ();
    typeLineEdit        = new QLineEdit ();
    priceLineEdit       = new QLineEdit ();
    districtLineEdit    = new QLineEdit ();
    addressLineEdit     = new QLineEdit ();
    locationXLineEdit   = new QLineEdit ();
    locationYLineEdit   = new QLineEdit ();

    layout -> addWidget ( idLabel,          0,  0 );
    layout -> addWidget ( nameLabel,        1,  0 );
    layout -> addWidget ( descriptionLabel, 2,  0 );
    layout -> addWidget ( reglamentLabel,   3,  0 );
    layout -> addWidget ( kadastrLabel,     4,  0 );
    layout -> addWidget ( usageLabel,       5,  0 );
    layout -> addWidget ( squareLabel,      6,  0 );
    layout -> addWidget ( typeLabel,        7,  0 );
    layout -> addWidget ( priceLabel,       8,  0 );
    layout -> addWidget ( districtLabel,    9,  0 );
    layout -> addWidget ( addressLabel,     10, 0 );
    layout -> addWidget ( locationXLabel,   11, 0 );
    layout -> addWidget ( locationYLabel,   12, 0 );

    layout -> addWidget ( idLineEdit,          0,  1 );
    layout -> addWidget ( nameLineEdit,        1,  1 );
    layout -> addWidget ( descriptionLineEdit, 2,  1 );
    layout -> addWidget ( reglamentLineEdit,   3,  1 );
    layout -> addWidget ( kadastrLineEdit,     4,  1 );
    layout -> addWidget ( usageLineEdit,       5,  1 );
    layout -> addWidget ( squareLineEdit,      6,  1 );
    layout -> addWidget ( typeLineEdit,        7,  1 );
    layout -> addWidget ( priceLineEdit,       8,  1 );
    layout -> addWidget ( districtLineEdit,    9,  1 );
    layout -> addWidget ( addressLineEdit,     10, 1 );
    layout -> addWidget ( locationXLineEdit,   11, 1 );
    layout -> addWidget ( locationYLineEdit,   12, 1 );

    layout -> addItem ( 
        new QSpacerItem ( 0, 0, QSizePolicy::Ignored, QSizePolicy::MinimumExpanding), 13, 0
    );

    layout -> setHorizontalSpacing ( 20 );
    layout -> setColumnStretch ( 1, 1 );

    idLineEdit -> setReadOnly ( true );
}

MainPage::MainPage 
( 
    Land data, 
    QWidget * parent
) : MainPage ( parent )
{
    idLineEdit          -> setText ( QString::number        ( data.fields.id ) );
    nameLineEdit        -> setText ( QString::fromStdString ( data.fields.name ) );
    descriptionLineEdit -> setText ( QString::fromStdString ( data.fields.description ) );
    reglamentLineEdit   -> setText ( QString::fromStdString ( data.fields.reglament ) );
    kadastrLineEdit     -> setText ( QString::fromStdString ( data.fields.kadastr ) );
    usageLineEdit       -> setText ( QString::fromStdString ( data.fields.usage ) );
    squareLineEdit      -> setText ( QString::number        ( data.fields.square ) );
    typeLineEdit        -> setText ( QString::fromStdString ( data.fields.type ) );
    priceLineEdit       -> setText ( QString::number        ( data.fields.price ) );
    districtLineEdit    -> setText ( QString::fromStdString ( data.fields.district ) );
    addressLineEdit     -> setText ( QString::fromStdString ( data.fields.address ) );
    locationXLineEdit   -> setText ( QString::number        ( data.fields.location.lat ) );
    locationYLineEdit   -> setText ( QString::number        ( data.fields.location.lon ) );
}

void MainPage::extractData ( LandEditRequest & data )
{
    data.id             = idLineEdit            -> text().toLong();
    data.name           = nameLineEdit          -> text().toStdString();
    data.description    = descriptionLineEdit   -> text().toStdString();
    data.reglament      = reglamentLineEdit     -> text().toStdString();
    data.kadastr        = kadastrLineEdit       -> text().toStdString();
    data.usage          = usageLineEdit         -> text().toStdString();
    data.square         = squareLineEdit        -> text().toDouble();
    data.type           = typeLineEdit          -> text().toStdString();
    data.price          = priceLineEdit         -> text().toDouble();
    data.district       = districtLineEdit      -> text().toStdString();
    data.address        = addressLineEdit       -> text().toStdString();
    data.location.lat   = locationXLineEdit     -> text().toDouble();
    data.location.lon   = locationYLineEdit     -> text().toDouble();
}

}