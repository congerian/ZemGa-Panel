#include <vector>
#include <iostream>
#include <exception>

#include "./client_table_model.hxx"
#include "application/application.hxx"

namespace ZG::Panel {

ClientTableModel::ClientTableModel (QObject * parent) : QAbstractTableModel (parent) {tryFetchData();}

int ClientTableModel::rowCount(const QModelIndex &) const
{
    return contacts.count();
}

int ClientTableModel::columnCount(const QModelIndex &) const
{
    return 6;
}

int ClientTableModel::rowCount() const
{
    return contacts.count();
}

int ClientTableModel::columnCount() const
{
    return 6;
}

QVariant ClientTableModel::data(const QModelIndex &index, int role) const
{
    
    const Contact & contact = contacts[index.row()];
    const Contact::Client client = contact.client;

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
                return QString::number(client.id);
            case 1: 
                return QString::fromStdString(client.landId);
            case 2: 
                return QString::fromStdString(client.message);
            case 3: 
                return QString::fromStdString(client.phoneNumber);
            case 4: 
                return QString::fromStdString(client.name);
            case 5: 
                return QString::fromStdString(client.requestTime);
            default: 
                return {};
        };
    }

    if (role == SortRole)
    {
        switch (index.column()) 
        {
            case 0: 
                return (long long) client.id;
            case 1: 
                return QString::fromStdString(client.landId).toLongLong();
            case 2: 
                return QString::fromStdString(client.message);
            case 3: 
                return QString::fromStdString(client.phoneNumber);
            case 4: 
                return QString::fromStdString(client.name);
            case 5: 
                return QString::fromStdString(client.requestTime);
            default: 
                return {};
        };
    }
    return {};
    
}

QVariant ClientTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation != Qt::Horizontal || role != Qt::DisplayRole) return {};
    switch (section) 
    {
        case 0:  return tr("Id");
        case 1:  return tr("Land id");
        case 2:  return tr("Message");
        case 3:  return tr("Phone number");
        case 4:  return tr("Name");
        case 5:  return tr("Request time");
        default: return {};
    }
    return {};
}

void ClientTableModel::tryFetchData ()
{
    
    emit layoutAboutToBeChanged();
    QModelIndex topLeft = index(0, 0);
    QModelIndex bottomRight = index(rowCount() - 1, columnCount() - 1);
    this->contacts.clear();
    emit dataChanged(topLeft, bottomRight);
    emit layoutChanged();
    ((Application *)Application::instance())->getRequester()->adminContacts(this, dataFetched);
    
}

void ClientTableModel::dataFetched (QNetworkReply * reply)
{
    
    if (reply->error()) {
        qDebug() << reply->errorString();
        exit(5);
    }

    QString answer = QString::fromUtf8(reply->readAll());

    qDebug() << answer;

    nlohmann::json json = nlohmann::json::parse(answer.toStdString());

    std::vector <Contact> contactVec;
    contactVec = json.at("clients").get<std::vector <Contact> >();

    emit layoutAboutToBeChanged();
    this -> contacts.clear();
    contacts.reserve(contactVec.size());
    std::copy(contactVec.begin(), contactVec.end(), std::back_inserter(contacts));
    
    QModelIndex topLeft = index(0, 0);
    QModelIndex bottomRight = index(rowCount() - 1, columnCount() - 1);


    emit dataChanged(topLeft, bottomRight);
    emit layoutChanged();
    
} 

}