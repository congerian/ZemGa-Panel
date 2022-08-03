#include <vector>
#include <iostream>


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
    const Land::LandFields fields = land.getFields();

    if (role == Qt::DisplayRole || role == Qt::EditRole) 
    {
        switch (index.column()) 
        {
            case 0: 
                return QString::number(fields.getId());
            case 1: 
                return QString::fromStdString(fields.getName());
            case 2: 
                return QString::fromStdString(fields.getDescription());
            case 3: 
                return QString::fromStdString(fields.getReglament());
            case 4: 
                return QString::fromStdString(fields.getKadastr());
            case 5: 
                return QString::fromStdString(fields.getUsage());
            case 6: 
                return QString::fromStdString(fields.getType());
            case 7: 
                return QString::fromStdString(fields.getDistrict());
            case 8: 
                return QString::fromStdString(fields.getAddress());
            case 9: 
                return QString::number(fields.getSquare());
            case 10: 
                return QString::number(fields.getPrice());
            default: 
                return {};
        };
    }

    if (role == SortRole)
    {
        switch (index.column()) 
        {
            case 0: 
                return (long long) fields.getId();
            case 1: 
                return QString::fromStdString(fields.getName());
            case 2: 
                return QString::fromStdString(fields.getDescription());
            case 3: 
                return QString::fromStdString(fields.getReglament());
            case 4: 
                return QString::fromStdString(fields.getKadastr());
            case 5: 
                return QString::fromStdString(fields.getUsage());
            case 6: 
                return QString::fromStdString(fields.getType());
            case 7: 
                return QString::fromStdString(fields.getDistrict());
            case 8: 
                return QString::fromStdString(fields.getAddress());
            case 9: 
                return (long long) fields.getSquare();
            case 10: 
                return (long long) fields.getPrice();
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
    ((Application *)Application::instance())->getRequester()->clientGetLandAll(this, dataFetched);
}

void LandTableModel::dataFetched (QNetworkReply * reply)
{
    if (reply->error()) {
        qDebug() << reply->errorString();
        return;
    }

    QString answer = QString::fromUtf8(reply->readAll());
    nlohmann::json json = nlohmann::json::parse(answer.toStdString());
    
    qDebug() << QString::fromStdString(json.dump());

    std::vector<Land> landsVec = json.at("lands").get<std::vector<Land>>();

    this->lands.clear();
    lands.reserve(landsVec.size());
    std::copy(landsVec.begin(), landsVec.end(), std::back_inserter(lands));
    
    QModelIndex topLeft = index(0, 0);
    QModelIndex bottomRight = index(rowCount() - 1, columnCount() - 1);

    emit dataChanged(topLeft, bottomRight);
    emit layoutChanged();
} 

}