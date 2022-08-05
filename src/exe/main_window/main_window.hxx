#pragma once

#include "./land_table/land_table_widget.hxx"
#include "util.hxx"

#include <QtWidgets>

namespace ZG::Panel{

class MainWindow : public QMainWindow
{
    Q_OBJECT
protected:
    
private:
    LandTableWidget * tableWidget;

    QAction * updateAction;
    QAction * newAction;
    QAction * editAction;
    QAction * deleteAction;
    QAction * contactsAction;

    int selectedRow;

public:
    MainWindow(QWidget *parent = nullptr, Qt::WindowFlags flags = ::defaultWindowFlags);

public slots:
    void update ();
private slots:
    void createLand ();
    void editLand ();
    void deleteLand ();
    void showContacts ();
    void tableSelectionChanged (const QItemSelection &, const QItemSelection &);

};



}