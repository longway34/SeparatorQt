#include <QLineEdit>
#include <QTableWidget>

#include "isprwidget.h"

ISPRWidget::ISPRWidget()
{

}

ISPRModelData *ISPRWidget::setModel(ISPRModelData *data)
{
    return data;
}

QLineEdit *ISPRWidget::setNumberCell(QTableWidget *table, int row, int col, int value, int min, int max, const QString toolType)
{
   QLineEdit *leNum = new QLineEdit(QString::number(value), table);
   leNum->setFrame(false); leNum->setAlignment(Qt::AlignCenter);
   leNum->setValidator(new QIntValidator(min, max, leNum/*table->item(row, col)->*/));
   table->setCellWidget(row, col, leNum);
   leNum->setProperty("row", row); leNum->setProperty("col", col);

   QVariant qv_tw;
   qv_tw.setValue<QTableWidget*>(table);
   leNum->setProperty("tw", qv_tw);

   leNum->setObjectName("leTable");
   leNum->setToolTip(toolType);
   return leNum;
}

