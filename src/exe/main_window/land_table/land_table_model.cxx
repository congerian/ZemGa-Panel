#include <vector>
#include <iostream>
#include <exception>

#include "./land_table_model.hxx"
#include "application/application.hxx"

namespace ZG::Panel {

LandTableModel::LandTableModel (QObject * parent) : QAbstractTableModel (parent) {tryFetchData();}

int LandTableModel::rowCount(const QModelIndex &) const
{
    return lands.count();
}

int LandTableModel::columnCount(const QModelIndex &) const
{
    return 11;
}

int LandTableModel::rowCount() const
{
    return lands.count();
}

int LandTableModel::columnCount() const
{
    return 11;
}

QVariant LandTableModel::data(const QModelIndex &index, int role) const
{

    const Land & land = lands[index.row()];
    const Land::LandFields fields = land.fields;

    if (role == Qt::BackgroundRole){
        if (index.row() % 2) 
        {
            QColor color = QColor(255, 255, 255);
            return QVariant (QBrush (color));    
        }
        QColor color = QColor(0, 0, 0, 20);
        return QVariant (QBrush (color));
    }

    if (role == Qt::DisplayRole) 
    {
        switch (index.column()) 
        {
            case 0: 
                return QString::number(fields.id);
            case 1: 
                return QString::fromStdString(fields.name);
            case 2: 
                return QString::fromStdString(fields.description);
            case 3: 
                return QString::fromStdString(fields.reglament);
            case 4: 
                return QString::fromStdString(fields.kadastr);
            case 5: 
                return QString::fromStdString(fields.usage);
            case 6: 
                return QString::fromStdString(fields.type);
            case 7: 
                return QString::fromStdString(fields.district);
            case 8: 
                return QString::fromStdString(fields.address);
            case 9: 
                return QString::number(fields.square);
            case 10: 
                return QString::number(fields.price);
            default: 
                return {};
        };
    }

    if (role == SortRole)
    {
        switch (index.column()) 
        {
            case 0: 
                return (long long) fields.id;
            case 1: 
                return QString::fromStdString(fields.name);
            case 2: 
                return QString::fromStdString(fields.description);
            case 3: 
                return QString::fromStdString(fields.reglament);
            case 4: 
                return QString::fromStdString(fields.kadastr);
            case 5: 
                return QString::fromStdString(fields.usage);
            case 6: 
                return QString::fromStdString(fields.type);
            case 7: 
                return QString::fromStdString(fields.district);
            case 8: 
                return QString::fromStdString(fields.address);
            case 9: 
                return (long long) fields.square;
            case 10: 
                return (long long) fields.price;
            default: 
                return {};
        };
    }

    return {};
    
}

QVariant LandTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation != Qt::Horizontal || role != Qt::DisplayRole) return {};
    switch (section) 
    {
        case 0:  return tr("Id");
        case 1:  return tr("Name");
        case 2:  return tr("Description");
        case 3:  return tr("Reglament");
        case 4:  return tr("Kadastr");
        case 5:  return tr("Usage");
        case 6:  return tr("Type");
        case 7:  return tr("District");
        case 8:  return tr("Address");
        case 9:  return tr("Square");
        case 10: return tr("Price");
        default: return {};
    }
}

void LandTableModel::tryFetchData ()
{
    emit layoutAboutToBeChanged();
    QModelIndex topLeft = index(0, 0);
    QModelIndex bottomRight = index(rowCount() - 1, columnCount() - 1);
    this->lands.clear();
    emit dataChanged(topLeft, bottomRight);
    emit layoutChanged();
    ((Application *)Application::instance())->getRequester()->clientGetLandAll(this, dataFetched);
}

void LandTableModel::dataFetched (QNetworkReply * reply)
{
    if (reply->error()) {
        qDebug() << reply->errorString();
        exit(5);
    }

    QString answer = QString::fromUtf8(reply->readAll());
    nlohmann::json json = nlohmann::json::parse(answer.toStdString());


    std::vector<Land> landsVec;
    landsVec = json.at("lands").get<std::vector<Land>>();

    emit layoutAboutToBeChanged();
    this->lands.clear();
    lands.reserve(landsVec.size());
    std::copy(landsVec.begin(), landsVec.end(), std::back_inserter(lands));
    
    QModelIndex topLeft = index(0, 0);
    QModelIndex bottomRight = index(rowCount() - 1, columnCount() - 1);


    emit dataChanged(topLeft, bottomRight);
    emit layoutChanged();
} 

long LandTableModel::getLandId (int row){
    return (lands[row].fields.id);
}

Land LandTableModel::getLand (int id){
    return (lands[id]);
}

}