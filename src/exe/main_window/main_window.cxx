#include "./main_window.hxx"

#include <QtWidgets>

namespace ZG::Panel{

    MainWindow::MainWindow(QWidget *parent, Qt::WindowFlags flags)  
        : QMainWindow(parent, flags){
            
            setWindowTitle(QString::fromUtf8("Admin panel - Zemga"));
            setWindowIcon(QIcon(":/exe_res/icon.png"));
            
            QMenu * fileMenu = this->menuBar()->addMenu(tr("&File"));
            QToolBar * updateToolBar = addToolBar(tr("Update"));

            QAction *newAct = new QAction(tr("&Update"), this);
            newAct->setShortcuts(QKeySequence::Refresh);
            newAct->setStatusTip(tr("Update loaded lands"));
            connect(newAct, &QAction::triggered, this, &MainWindow::update);
            updateToolBar->addAction(newAct);

            LandTableWidget * centralWidget = new LandTableWidget(this);
            this->setCentralWidget(centralWidget);

        }

    void MainWindow::update(){

    }
}
