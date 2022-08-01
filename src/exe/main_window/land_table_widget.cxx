#include "./land_table_widget.hxx"

ZG::Panel::LandTableWidget::LandTableWidget(QWidget *parent) : QWidget(parent) {
    layout = new QGridLayout();
    layout->setSpacing(0);
    layout->setContentsMargins(0,0,0,0);

    table = new QTableWidget(5, 5);
    table->setFrameShape(QFrame::NoFrame);
    table->setShowGrid(false);
    table->verticalHeader()->setVisible(false);

    setLayout(layout);
    
    layout->addWidget(table, 0, 0, 1, 2);

    for(int i = 0; i < layout->columnCount(); ++i){
        layout->setColumnMinimumWidth(i, 150);
        layout->setColumnStretch(i, 1);
    }
    for(int j = 0; j < layout->rowCount(); ++j){
        layout->setRowMinimumHeight(j, 150);
        layout->setRowStretch(j, 1);
    }

    for(int i = 0; i < layout->columnCount(); ++i){
        for(int j = 0; j < layout->rowCount(); ++j){
            QLayoutItem * layoutItem = layout->itemAtPosition(j, i);
            if (!layoutItem){
                QWidget * widget = new QWidget();
                QPalette pal = QPalette();
                pal.setColor(QPalette::Window, QColor(i*30+81, j*30+65, (i+j)*30));
                widget->setAutoFillBackground(true);
                widget->setPalette(pal);
                widget->update();
                layout->addWidget(widget, j, i, 1, 1);
            }
        }
    }
}
