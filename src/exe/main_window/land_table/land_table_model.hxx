#pragma once

#include <QtWidgets>
#include <QNetworkReply>

#include "data_model/land/land.hxx"

namespace ZG::Panel {

class LandTableModel : public QAbstractTableModel {
    Q_OBJECT

public:

    enum Role {
        SortRole = Qt::UserRole
    };

    LandTableModel (QObject * parent = nullptr);
    int rowCount (const QModelIndex &) const override;
    int columnCount (const QModelIndex &) const override;
    int rowCount () const;
    int columnCount () const;
    QVariant data (const QModelIndex &index, int role) const override;
    QVariant headerData (int section, Qt::Orientation orientation, int role) const override;
    void tryFetchData ();

private:

    QList <Land> lands;

public slots:

    void dataFetched(QNetworkReply * reply);

signals:

};

}