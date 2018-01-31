#include "sprsettingswidget.h"
//#include "sprspectrumranges.h"
//#include "models/sprsettingsmainmodel.h"
#include <QDir>

SPRSettingsWidget::SPRSettingsWidget(QWidget *parent):
    QWidget(parent)
{
    ui.setupUi(this);
}

SPRSettingsWidget::SPRSettingsWidget(QDomDocument *_doc, QWidget *parent):
    QWidget(parent)
{
    ui.setupUi(this);
    setDoc(_doc);
}

void SPRSettingsWidget::setDoc(QDomDocument *_doc)
{
    doc = _doc;

    model = new SPRMainModel(doc, nullptr);
//    if(QDir::setCurrent("F:\\Projects\\Separator\\Real spectors")){
//        QFile inp("СРФ4.spc");
//        ui.wSpectrumList->setModel(tmodel, &inp);
//    }

}

SPRMainModel *SPRSettingsWidget::setModel(SPRMainModel *_model)
{
    ISPRModelData *imodel;
    model = _model;


    imodel = ui.wSettingsMainWidget->setModel(model->getSettingsMainModel());
    connect(this,SIGNAL(doShow()), ui.wSettingsMainWidget, SLOT(widgetsShow()));
    connect(ui.wSettingsMainWidget,SIGNAL(doShow()), this, SLOT(widgetsShow()));

    imodel = ui.wSettingsPorogsWidget->setModel(model->getSettingsPorogsModel());
    connect(this,SIGNAL(doShow()), ui.wSettingsPorogsWidget, SLOT(widgetsShow()));
    connect(ui.wSettingsPorogsWidget, SIGNAL(doShow()), this, SLOT(widgetsShow()));

    imodel = ui.wSettingsFormulaWidget->setModel(model->getSettingsFormulaModel());
    connect(this,SIGNAL(doShow()), ui.wSettingsFormulaWidget, SLOT(widgetsShow()));
    connect(ui.wSettingsFormulaWidget,SIGNAL(doShow()), this, SLOT(widgetsShow()));

    imodel = ui.wSettingsRentgen->setModel(model->getSettingsRentgenModel());
    connect(this,SIGNAL(doShow()), ui.wSettingsRentgen, SLOT(widgetsShow()));

    imodel = ui.wSettingsIMSWidget->setModel(model->getSettingsIMSModel());
    connect(this, SIGNAL(doShow()), ui.wSettingsIMSWidget, SLOT(widgetsShow()));

    imodel = ui.wSettingsControl->setModel(model->getSettingsControlModel());
    connect(this, SIGNAL(doShow()), ui.wSettingsControl, SLOT(widgetsShow()));

    imodel = ui.wSpectrumZonesWidget->setModel(model->getSpectrumZonesTableModel());
    connect(this, SIGNAL(doShow()), ui.wSpectrumZonesWidget, SLOT(widgetsShow()));

    emit doShow();

    return model;
}
