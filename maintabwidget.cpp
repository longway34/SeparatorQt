#include "maintabwidget.h"

MainTabWidget::MainTabWidget(QWidget *parent) :
    QTabWidget(parent)
{
    ui.setupUi(this);

}

MainTabWidget::MainTabWidget(QDomDocument *_doc, QWidget *parent)
{
    doc = _doc;

    ui.setupUi(this);

    mainModel = new SPRMainModel(doc);

    ui.tabSettings->setModel(mainModel);
    
//    if(QDir::setCurrent("F:\\Projects\\Separator\\Real spectors")){
//        QFile inp("СРФ4.spc");
//        ui.wSpectrumList->setModel(tmodel, &inp);
//    }
}
