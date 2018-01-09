#include "mainwindow.h"
#include "sprspectrumranges.h"
#include "models/sprsettingsmainmodel.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    ui.setupUi(this);


}

MainWindow::MainWindow(QDomDocument *_doc, QWidget *parent):
    QMainWindow(parent)
{
    doc = _doc;
    ui.setupUi(this);

    ISPRModelData *model;
    mainModel = new SPRSettingsMainModel(doc);

//    this->addWidgetAndModel(ui.wSettingsMianWidget, mainModel);
//    this->addWidgetAndModel(ui.wSpectrumPorogsWidget, new SPRSpectrumRangesTableModel(doc));
//    this->addWidgetAndModel(ui.wSettingsPorogsWidget, new SPRSettingsPorogsModel(doc));
//    this->addWidgetAndModel(ui.wSettingsFormulaWidget, new SPRSettingsFormulaModel(doc));
    
    model = ui.wSettingsMianWidget->setModel(mainModel);
    connect(this, SIGNAL(doStore()), model, SLOT(store()));
    connect(this,SIGNAL(doShow()), ui.wSettingsMianWidget, SLOT(widgetsShow()));
    connect(ui.wSettingsMianWidget,SIGNAL(doShow()), this, SLOT(widgetsShow()));
    connect(ui.wSettingsMianWidget, SIGNAL(doShow()), this, SLOT(widgetsShow()));

    model = ui.wSpectrumPorogsWidget->setModel(new SPRSpectrumRangesTableModel(doc));
    ui.wSpectrumPorogsWidget->setThreads(mainModel->getThreads());
    connect(this, SIGNAL(doStore()), model, SLOT(store()));
    connect(this,SIGNAL(doShow()), ui.wSpectrumPorogsWidget, SLOT(widgetsShow()));
    connect(ui.wSettingsPorogsWidget, SIGNAL(doShow()), this, SLOT(widgetsShow()));
    
    SPRSettingsPorogsModel *porogsModel = new SPRSettingsPorogsModel(doc);
    ui.wSettingsPorogsWidget->setModel(porogsModel);
    ui.wSettingsPorogsWidget->setThreads(mainModel->getThreads());
    connect(this, SIGNAL(doStore()), porogsModel, SLOT(store()));
    connect(this,SIGNAL(doShow()), ui.wSettingsPorogsWidget, SLOT(widgetsShow()));
    connect(ui.wSettingsPorogsWidget,SIGNAL(doShow()), this, SLOT(widgetsShow()));

    model = ui.wSettingsFormulaWidget->setModel(new SPRSettingsFormulaModel(doc));
    ui.wSettingsFormulaWidget->setConditions(porogsModel->getConditions());
    connect(this, SIGNAL(doStore()), model, SLOT(store()));
    connect(this,SIGNAL(doShow()), ui.wSettingsFormulaWidget, SLOT(widgetsShow()));
    connect(ui.wSettingsFormulaWidget,SIGNAL(doShow()), this, SLOT(widgetsShow()));

    SPRSettingsRentgenModel *rentgenModel = new SPRSettingsRentgenModel(doc);
    connect(this, SIGNAL(doStore()), rentgenModel, SLOT(store()));
    rentgenModel->setRentgens(mainModel->getRentgens());
    rentgenModel->setThreads(mainModel->getThreads());

    model = ui.wSettingsRentgen->setModel(rentgenModel);
    ui.wSettingsRentgen->setThreads(mainModel->getThreads());
    ui.wSettingsRentgen->setRentgens(mainModel->getRentgens());
    connect(this,SIGNAL(doShow()), ui.wSettingsRentgen, SLOT(widgetsShow()));
    
    model = ui.wSettingsIMSWidget->setModel(new SPRSettingsIMSModel(doc));
    ui.wSettingsIMSWidget->setIms(mainModel->ims);
    connect(this, SIGNAL(doStore()), model, SLOT(store()));
    connect(this, SIGNAL(doShow()), ui.wSettingsIMSWidget, SLOT(widgetsShow()));

    model = ui.wSettingsControl->setModel(new SPRSettingsControlModel(doc));
    connect(this, SIGNAL(doStore()), model, SLOT(store()));
    connect(this, SIGNAL(doShow()), ui.wSettingsControl, SLOT(widgetsShow()));

//    model = ui.wSettingsRentgenAutoWidget->
}

//ISPRWidget *MainWindow::addWidgetAndModel(ISPRWidget *widget, ISPRModelData *model)
//{
//    connect(this,SIGNAL(doStore()), model, SLOT(store()));
//    connect(this, SIGNAL(doShow()), widget, SLOT(widgetsShow()));
//    return widget;
//}


void MainWindow::widgetsShow()
{
    emit doShow();
}

ISPRModelData *MainWindow::getModel()
{

}

void MainWindow::viewChange()
{
    emit doShow();
}

void MainWindow::viewChange(int)
{
    viewChange();
}

void MainWindow::viewChange(QTableWidget *, int, int)
{
    viewChange();
}
