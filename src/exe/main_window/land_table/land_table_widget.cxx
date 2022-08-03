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

    model = new LandTableModel(this);
    tableView->setModel(model);
}
