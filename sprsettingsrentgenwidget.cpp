#include "sprsettingsrentgenwidget.h"

SPRSettingsRentgenWidget::SPRSettingsRentgenWidget(QWidget *parent) :
    QWidget(parent)
{
    ui.setupUi(this);
}


void SPRSettingsRentgenWidget::widgetsShow()
{
}

ISPRModelData *SPRSettingsRentgenWidget::setModel(SPRSettingsRentgenModel *value){
    if(model){
        model = value;
        connect(this, SIGNAL(doStore()), model, SLOT(store()));

        ui.wSettingsRentgenMainWidget->setModel(model);
        connect(this, SIGNAL(doShow()), ui.wSettingsRentgenMainWidget, SLOT(widgetsShow()));

        ui.wSettingsRentgenControlWidget->setModel(model);
    }
}

void SPRSettingsRentgenWidget::viewChange(QTableWidget *, int, int)
{
}
