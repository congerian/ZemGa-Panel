#include "./main_window.hxx"

#include "application/application.hxx"
#include "edit_dialog/edit_dialog.hxx"
#include "client_dialog/client_dialog.hxx"

#include <QtWidgets>

namespace ZG::Panel{

    MainWindow::MainWindow (QWidget *parent, Qt::WindowFlags flags)  
        : QMainWindow (parent, flags)
        {
            
            resize (800, 600);

            setWindowTitle (QString::fromUtf8 ("Admin panel - Zemga"));
            setWindowIcon (QIcon (":/exe_res/icon.png"));
            
            QToolBar * toolBar = addToolBar (tr("Actions"));

            updateAction = new QAction ( tr("&Update"), this);
            updateAction->setShortcuts (QKeySequence::Refresh);
            updateAction->setStatusTip ( tr("Update loaded lands"));
            connect (updateAction, &QAction::triggered, this, &MainWindow::update);
            toolBar->addAction (updateAction);

            newAction = new QAction ( tr("&New"), this);
            newAction->setShortcuts (QKeySequence::New);
            newAction->setStatusTip ( tr("Create new land"));
            connect (newAction, &QAction::triggered, this, &MainWindow::createLand);
            toolBar->addAction (newAction);

            editAction = new QAction ( tr("&Edit"), this);
            editAction->setStatusTip ( tr("Edit existing land"));
            connect (editAction, &QAction::triggered, this, &MainWindow::editLand);
            toolBar->addAction (editAction);
            editAction->setEnabled (false);

            deleteAction = new QAction ( tr("&Delete"), this);
            deleteAction->setStatusTip ( tr("Delete existing land"));
            connect (deleteAction, &QAction::triggered, this, &MainWindow::deleteLand);
            toolBar->addAction (deleteAction);
            deleteAction->setEnabled (false);

            contactsAction = new QAction ( tr("&Show contacts"), this);
            contactsAction->setStatusTip ( tr("Show contacts"));
            connect (contactsAction, &QAction::triggered, this, &MainWindow::showContacts);
            toolBar->addAction (contactsAction);


            tableWidget = new LandTableWidget(this);
            this->setCentralWidget(tableWidget);

            statusBar()->setMinimumHeight(30);

            connect (
                tableWidget->tableView()->selectionModel(),
                &QItemSelectionModel::selectionChanged,
                this,
                &MainWindow::tableSelectionChanged
            );
            
        }

    void MainWindow::update()
    {
        tableWidget->model()->tryFetchData();
    }

    void MainWindow::editLand()
    {
        this -> setEnabled (false);
        Land land = tableWidget -> model() -> getLand ( selectedRow );
        EditDialog * dialog = new EditDialog ( land, this );
        this -> setEnabled (true);      
        dialog -> show();
    }

    void MainWindow::showContacts()
    {
        ClientDialog * contactsDialog = new ClientDialog ( this );
        contactsDialog -> show();
    }

    void MainWindow::createLand()
    {
        EditDialog * dialog = new EditDialog ( this );
        dialog -> show();
    }

    void MainWindow::deleteLand()
    {
        QMessageBox msgBox (
            QMessageBox::Warning, 
            tr("Confirmation"),
            tr("You are about to delete a land data. This action cannot be undone. Are you sure?"), 
            { }, 
            this
        );

        msgBox.addButton ( tr ("&Continue"), QMessageBox::AcceptRole);
        msgBox.addButton ( tr ("&Cancel"), QMessageBox::RejectRole);
        if (msgBox.exec() == QMessageBox::AcceptRole) 
        {
            ( ( Application * ) Application::instance() ) -> getRequester() -> adminDelete 
            ( 
                tableWidget -> model() -> getLandId ( selectedRow ),
                this,
                [] ( QNetworkReply * reply ) 
                {
                    ( ( Application * ) Application::instance() ) -> mainWindow -> update();
                }
            );
        }
    }

    void MainWindow::tableSelectionChanged (const QItemSelection & selected, const QItemSelection & deselected)
    {
        auto items = tableWidget->tableView()->selectionModel()->selectedRows();
        if (items.count() != 1)
        {
            deleteAction->setEnabled (false);
            editAction->setEnabled (false);
            return;
        }

        deleteAction->setEnabled (true);
        editAction->setEnabled (true);

        selectedRow = items[0].row();
    }
}
