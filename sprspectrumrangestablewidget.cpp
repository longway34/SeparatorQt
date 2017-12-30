#include <QMessageBox>
#include <QWidget>

#include "sprspectrumrangestablewidget.h"
#include "sprspectrumranges.h"

SPRSpectrumRangesTableWidget::SPRSpectrumRangesTableWidget(QWidget *parent) :
    QWidget(parent)
{
    ui.setupUi(this);

    QFont font = parentWidget()->font();
    setFont(font);

    connect(this, SIGNAL(doShow()), ui.wSpectrumTable, SLOT(widgetsShow()));
    connect(ui.bEquialent, SIGNAL(clicked(bool)), this, SLOT(viewChange(bool)));
}


void SPRSpectrumRangesTableWidget::widgetsShow()
{
    ui.wSpectrumTable->widgetsShow();
}

ISPRModelData *SPRSpectrumRangesTableWidget::getModel()
{
    return ui.wSpectrumTable->getModel();
}

ISPRModelData *SPRSpectrumRangesTableWidget::setModel(ISPRModelData *data)
{
    ui.wSpectrumTable->setModel((SPRSpectrumRangesTableModel*)data);
    return data;
}

void SPRSpectrumRangesTableWidget::viewChange(QTableWidget *, int, int)
{
    ui.bEquialent->setEnabled(true);
}

void SPRSpectrumRangesTableWidget::viewChange(bool)
{
    QLineEdit *focusedLe = (QLineEdit*)ui.wSpectrumTable->focusWidget();
    if(!focusedLe){
        QMessageBox msg(QMessageBox::Icon::Critical, tr("Нет выбранного элемента..."), tr("Нет выбранного элемента..."), QMessageBox::Ok);
        msg.exec();
        return;
    }
    if(!focusedLe->objectName().startsWith("leTable")){
        QMessageBox msg(QMessageBox::Icon::Critical, tr("Нет выбранного элемента..."), tr("Нет выбранного элемента..."), QMessageBox::Ok);
        msg.exec();
        return;
    }

    int column = QVariant(focusedLe->property("col")).toInt();
    uint val = focusedLe->text().toUInt();
    EnumElements el = static_cast<EnumElements>(QVariant(focusedLe->property("element")).toInt());
    SPRSpectrumRangesTableModel *mod = (SPRSpectrumRangesTableModel*)ui.wSpectrumTable->getModel();
    uint th = mod->getThreads()->getData();

    for(int i=0; i<th; i++){
        if(column == 0){
            ((SPRSpectrumRangesModel*)mod->items[i])->elements[el].min->setData(val);
        } else {
            ((SPRSpectrumRangesModel*)mod->items[i])->elements[el].max->setData(val);
        }
    }
    ui.wSpectrumTable->widgetsShow();
}
