#include "sprspectrumlisttablewidget.h"
#include "sprspectrumlisttablewidget.h"
#include <QHeaderView>

void SPRSpectrumListTableWidget::initNullGraphItems()
{
    foreach(EnumElements el, DEF_SPR_FORMULA_ELEMENTS_PROPERTY.keys()){
        QwtPlotHistogram *nullHist = new QwtPlotHistogram();
        ElementsProperty ep = DEF_SPR_FORMULA_ELEMENTS_PROPERTY[el];
        nullHist->setSamples(QVector<QwtIntervalSample>({QwtIntervalSample(0.001, ep.min, ep.max)}));
        nullHist->setPen(QPen(ep.color, 1, Qt::SolidLine));
        nullHist->setBrush(QBrush(ep.color));
        nullGrItems.zones[el] = nullHist;
        nullHist->attach(ui.qwtPlot);
    }

    ui.qwtPlot->setAxisScale(QwtPlot::xBottom, 0, MAX_SPR_SPECTOR_CHANNELS);
}

SPRSpectrumListTableWidget::SPRSpectrumListTableWidget(QWidget *parent) :
    QWidget(parent)
{
    ui.setupUi(this);
    ui.qwtPlot->setCanvasBackground(QBrush(Qt::black));


    connect(ui.tListSpectrumItem, SIGNAL(cellClicked(int,int)), this, SLOT(viewChange(int,int)));
    connect(ui.tListSpectrumItem, SIGNAL(rowSelected(int)), this, SLOT(viewChange(int)));
    connect(ui.tRangesChannel, SIGNAL(changeColor(EnumElements,QColor)), this, SLOT(onChangeZoneColor(EnumElements,QColor)));
    connect(ui.tRangesChannel, SIGNAL(tableChange(EnumElements,int,int)), this, SLOT(onChangeZoneRange(EnumElements,int,int)));
    initNullGraphItems();

//    ui.gbSpectrumElements->setMinimumWidth(150);

}

ISPRModelData *SPRSpectrumListTableWidget::setModel(SPRSpectrumRangesTableModel *_rangesModel, QFile *inp)
{
    rangesModel = _rangesModel;
    if(rangesModel){
        ui.tListSpectrumItem->setModel(inp, rangesModel);
        ui.tListSpectrumItem->selectRow(0);
        ui.tRangesChannel->setModel(rangesModel);

        connect(ui.tRangesChannel, SIGNAL(changeColor(EnumElements,QColor)), this, SLOT(onChangeZoneColor(EnumElements,QColor)));

        int rc = ui.tListSpectrumItem->rowCount();
        for(int row=0; row<rc; row++){
            uint32_t thread = *ui.tListSpectrumItem->getModel(row)->getSpData()->thread;

            SPRSpectrumRangesModel *ranges = rangesModel->items[thread];

            SPRGrSpectrumItemModel *gr = new SPRGrSpectrumItemModel(ranges, ui.tListSpectrumItem->getModel(row));

            QwtPlotCurve *curve = new QwtPlotCurve();
            curve->setSamples(gr->getSamples());
            QColor col(ui.tListSpectrumItem->getColorSpectrum(row));
            QPen pen(ui.tListSpectrumItem->getColorSpectrum(row), 1, Qt::SolidLine);
            curve->setPen(pen);
            col.setRgba(qRgba(255,255,255,64));
            QBrush brush(col);
            curve->setBrush(brush);


            GraphItem gri(curve);
            gri.thread = thread;

            foreach(EnumElements el, ranges->elements.keys()){
                QwtPlotHistogram *zonesItemHistogram = new QwtPlotHistogram();
                zonesItemHistogram->setSamples(gr->getIntervalSamples()[el]);

                QColor col(gr->getColorZone(el));
                QPen pen(col, 2, Qt::SolidLine);
                col.setAlpha(32);
                QBrush brush(col);
                zonesItemHistogram->setPen(pen);
                zonesItemHistogram->setBrush(brush);

                zonesItemHistogram->attach(ui.qwtPlot);
                gri.zones[el] = zonesItemHistogram;
            }

            curve->attach(ui.qwtPlot);

            grItems.push_back(gri);
            spectGrData.push_back(gr);
        }
    }
    ui.tListSpectrumItem->selectRow(0);
    ui.tListSpectrumItem->setCurrentCell(0, 3);

    widgetsShow();
    return rangesModel;
}

void SPRSpectrumListTableWidget::widgetsShow()
{

    for(int row=0; row<ui.tListSpectrumItem->rowCount(); row++){
        bool sel = ui.tListSpectrumItem->isSelectedItem(row);
        if(row < grItems.size()){
            bool current = ui.tListSpectrumItem->currentRow() == row;
            grItems[row].setVisible(sel, current);
        }
    }

    ui.qwtPlot->replot();
}

void SPRSpectrumListTableWidget::onChangeSpectColor(int row)
{
    QColor color(ui.tListSpectrumItem->getColorSpectrum(row));
    grItems[row].spect->setPen(color);
    widgetsShow();
}


SPRSpectrumRangesTableModel *SPRSpectrumListTableWidget::getModel()
{
    return rangesModel;
}


void SPRSpectrumListTableWidget::viewChange(int row, int col)
{
    int thr = ui.tListSpectrumItem->getThread(row);
    ui.tRangesChannel->setFirtChannel(thr);
    QList<bool> higgen;
    for(int ch=0; ch<rangesModel->items.size(); ch++){
        bool val = ch == thr ? false : true;
        higgen.push_back(val);
    }

    QSize s = ui.tRangesChannel->sizeHint();
    ui.tRangesChannel->setHddenChannels(higgen);
    s = ui.tRangesChannel->sizeHint();
    ui.gbSpectrumElements->setMaximumWidth(ui.tRangesChannel->sizeHint().width());
    widgetsShow();
}


void SPRSpectrumListTableWidget::viewChange(int row)
{
    widgetsShow();
}

/**
 * @brief graphItem::setVisible
 * @param visible
 * @param current
 */




void SPRSpectrumListTableWidget::viewChange(QColor)
{
}

void SPRSpectrumListTableWidget::onChangeZoneRange(EnumElements el, int thread, int col)
{
    for(int i=0; i<grItems.size(); i++){
        if(grItems[i].thread == thread){


            double value = grItems[i].zones[el]->sample(0).value;
            SPRSpectrumRangesModel *ranges = getModel()->items[thread];

            QwtIntervalSample samp(value, ranges->elements[el].min->getData(), ranges->elements[el].max->getData());
            grItems[i].zones[el]->setSamples(QVector<QwtIntervalSample>{samp});
        }
    }
    widgetsShow();
}
