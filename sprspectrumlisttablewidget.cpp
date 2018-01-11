#include "sprspectrumlisttablewidget.h"
#include <QHeaderView>





SPRSpectrumListTableWidget::SPRSpectrumListTableWidget(QWidget *parent) :
    QWidget(parent)
{
    ui.setupUi(this);


    ui.table->horizontalHeader()->setSectionsMovable(true);
    ui.table->clear();
}
