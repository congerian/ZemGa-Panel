#include "./land_table_widget.hxx"

ZG::Panel::LandTableWidget::LandTableWidget(QWidget *parent) : QWidget(parent) {
    _layout = new QGridLayout(this);
    _layout->setSpacing(0);
    _layout->setContentsMargins(0,0,0,0);

    _tableView = new QTableView();
    _tableView->setFrameShape(QFrame::NoFrame);
    _tableView->setShowGrid(false);
    _tableView->verticalHeader()->setVisible(false);

    setLayout(_layout);

    _layout->addWidget(_tableView, 0, 0, 0, 0);


    _model = new LandTableModel (this);
    QSortFilterProxyModel * proxy = new QSortFilterProxyModel (_model);
    
    proxy->setSourceModel (_model);
    proxy->setSortRole (LandTableModel::SortRole);

    _tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    _tableView->setSortingEnabled (true);
    _tableView->setModel (proxy);

    for (int i = 0; i < proxy->columnCount(); ++i) _tableView->setColumnWidth(i, 100);


}

QTableView * ZG::Panel::LandTableWidget::tableView()
{
    return _tableView;
}

ZG::Panel::LandTableModel * ZG::Panel::LandTableWidget::model()
{
    return _model;
}