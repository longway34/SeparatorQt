#include "mainwindow.h"
#include "sprspectrumranges.h"

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

    ui.tSpectrumPorogs->setModel(new SPRSpectrumRangesTableModel(doc));

//    SPRSpectrumRanges *rang = (SPRSpectrumRanges*)ui.tSpectrumPorogs->cellWidget(0,0);
//    ui.tabSpectrumRanges->layout()->addWidget(rang);

}
