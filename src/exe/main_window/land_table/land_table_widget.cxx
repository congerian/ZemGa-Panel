#include "./land_table_widget.hxx"

ZG::Panel::LandTableWidget::LandTableWidget(QWidget *parent) : QWidget(parent) {
    layout = new QGridLayout(this);
    layout->setSpacing(0);
    layout->setContentsMargins(0,0,0,0);

    tableView = new QTableView();
    tableView->setFrameShape(QFrame::NoFrame);
    tableView->setShowGrid(false);
    tableView->verticalHeader()->setVisible(false);

    setLayout(layout);

    layout->addWidget(tableView, 0, 0, 0, 0);


    model = new LandTableModel (this);
    QSortFilterProxyModel * proxy = new QSortFilterProxyModel (model);
    
    proxy->setSourceModel (model);
    proxy->setSortRole (LandTableModel::SortRole);

    tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableView->setSortingEnabled (true);
    tableView->setModel (proxy);
    tableView->setColumnWidth(0, 100);
    
    for (int i = 1; i < proxy->columnCount(); ++i) tableView->setColumnWidth(i, 50);


}
