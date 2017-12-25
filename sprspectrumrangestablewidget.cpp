#include "sprspectrumrangestablewidget.h"
#include "sprspectrumranges.h"

SPRSpectrumRangesTableWidget::SPRSpectrumRangesTableWidget(QWidget *parent) :
    QWidget(parent)
{
    ui.setupUi(this);

    connect(SIGNAL(doShow()), ui.wSpectrumTable, SLOT(widgetsShow()));
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

void SPRSpectrumRangesTableWidget::setModel(ISPRModelData *data)
{
    ui.wSpectrumTable->setModel(data);


}

void SPRSpectrumRangesTableWidget::viewChange(QTableWidget *, int, int)
{
    ui.bEquialent->setEnabled(true);
}

void SPRSpectrumRangesTableWidget::viewChange(bool)
{
    QPoint point(ui.wSpectrumTable->getSelectedPosition());
    EnumElements el = ui.wSpectrumTable->getSelectedElement();


}
