#include <QHeaderView>
#include "sprspectrumrangestable.h"
#include "sprspectrumranges.h"

SPRSpectrumRangesTable::SPRSpectrumRangesTable(QWidget *parent):
    QTableWidget(parent), model(nullptr)
{
}

void SPRSpectrumRangesTable::setModel(SPRSpectrumRangesTableModel *value)
{
    model = value;

    QStringList nameH;
    setColumnCount(model->items.size()); setRowCount(1);
    for(int i=0; i<model->items.size(); i++){
        nameH.append(tr("Канал ")+QString::number(i));
        SPRSpectrumRanges *ranges = new SPRSpectrumRanges();
        ranges->setFont(this->font());
        ranges->setModel(model->items.at(i));

        setCellWidget(0, i, ranges);
        connect(ranges, SIGNAL(tableChange(QTableWidget*,int,int)), SLOT(viewChange(QTableWidget*,int,int)));
        setColumnWidth(i, ranges->sizeHint().width());
        setContentsMargins(0,0,0,0);
        setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    }
    setHorizontalHeaderLabels(nameH);
    verticalHeader()->setVisible(false);
    resizeRowsToContents();
}

void SPRSpectrumRangesTable::widgetsShow()
{
    if(model){
        for(int i=0; i< model->items.size(); i++){
            if(i < model->getThreads()->getData()){
                cellWidget(0, i)->setVisible(true);
                ((SPRSpectrumRanges*)(cellWidget(0,i)))->widgetsShow();

            } else {
                cellWidget(0, i)->setVisible(false);
            }
        }
    }
}

QPoint SPRSpectrumRangesTable::getSelectedPosition()
{
    SPRSpectrumRanges* range = (SPRSpectrumRanges*)focusWidget();
    QPoint res(range->getSelectedPosition());
    res.setX(res.x() + ((SPRSpectrumRangesModel*)range->getModel())->tIndex * 2);
    return res;
}

ISPRModelData *SPRSpectrumRangesTable::getModel()
{
    return model;
}

void SPRSpectrumRangesTable::viewChange(QTableWidget *table, int row, int col)
{
    emit this->tableChange(table, row, col);
}
