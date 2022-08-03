#pragma once

#include <QtWidgets>

#include "data_model/land/land.hxx"

namespace ZG::Panel {

class LandTableModel : public QAbstractTableModel {
    Q_OBJECT

public:

    LandTableModel(QObject * parent = nullptr);
    int rowCount(const QModelIndex &) const override;
    int columnCount(const QModelIndex &) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

private:
    QList <Land> lands;

};

}