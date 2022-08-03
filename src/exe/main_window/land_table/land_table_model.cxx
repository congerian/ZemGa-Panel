#include "./land_table_model.hxx"

namespace ZG::Panel {

LandTableModel::LandTableModel (QObject * parent) : QAbstractTableModel (parent) {}

int LandTableModel::rowCount(const QModelIndex &) const
{
    return lands.count();
}

int LandTableModel::columnCount(const QModelIndex &) const
{
    return 11;
}

QVariant LandTableModel::data(const QModelIndex &index, int role) const
{
    if (role != Qt::DisplayRole && role != Qt::EditRole) return QVariant();

    const Land & land = lands[index.row()];
    const Land::LandFields fields = land.getFields();

    switch (index.column()) 
    {
        case 0: 
            return QString::number(fields.getId());
        default: 
            return {};
    };
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


}