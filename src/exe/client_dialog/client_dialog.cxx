#include "./client_dialog.hxx"

#include <QtWidgets>

namespace ZG::Panel{

ClientDialog::ClientDialog (QWidget *parent, Qt::WindowFlags flags)  
    : QMainWindow (parent, flags)
    {
        
        resize (800, 600);

        setWindowTitle (QString::fromUtf8 ("Admin panel - Zemga"));
        setWindowIcon (QIcon (":/exe_res/icon.png"));
        
        QToolBar * toolBar = addToolBar (tr ("Actions"));

        updateAction = new QAction (tr ("&Update"), this);
        updateAction->setShortcuts (QKeySequence::Refresh);
        updateAction->setStatusTip (tr ("Update loaded lands"));
        connect (updateAction, &QAction::triggered, this, &ClientDialog::update);
        toolBar -> addAction (updateAction);

        tableWidget = new ClientTableWidget(this);
        this->setCentralWidget(tableWidget);

        statusBar() -> setMinimumHeight(30);
        
    }

void ClientDialog::update()
{
    tableWidget->model()->tryFetchData();
}

}
