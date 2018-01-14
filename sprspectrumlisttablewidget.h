#ifndef SPRSPECTRUMLISTTABLEWIDGET_H
#define SPRSPECTRUMLISTTABLEWIDGET_H

#include "ui_sprspectrumlisttablewidget.h"
#include "models/sprspectrumrangestablemodel.h"
#include "models/sprspectrumrangestablemodel.h"
#include "models/sprgrspectrumitemmodel.h"
#include "isprwidget.h"

#include "qwt_plot_curve.h"
#include "qwt_plot_histogram.h"
#include "qwt_plot_grid.h"

typedef struct graphItem{
    QwtPlotCurve *spect;
    QMap<EnumElements, QwtPlotHistogram*> zones;
    int thread;

    graphItem(): spect(nullptr){}
    graphItem(QwtPlotCurve *_spect): spect(_spect){}
    void setVisible(bool visible, bool current){
        foreach(EnumElements el, zones.keys()){
            zones[el]->setVisible(current);
        }
        if(spect){
            spect->setVisible(visible);
            QColor cpen(spect->pen().color());
            if(current){
                QPen pen(cpen, 2);
                spect->setPen(pen);
                cpen.setAlpha(64);
                QBrush brush(cpen);
                spect->setBrush(brush);
            } else {
                QPen pen(cpen,0.5);
                spect->setPen(pen);
                cpen.setAlpha(0);
                spect->setBrush(QBrush(cpen));
            }
        }
    }
//    ~graphItem(){
//        if(spect)
//            delete spect;
//        if(zones)
//            delete zones;}
} GraphItem;


class SPRSpectrumListTableWidget : public QWidget, public ISPRWidget
{
    Q_OBJECT

    SPRSpectrumRangesTableModel *rangesModel;
    QVector<SPRGrSpectrumItemModel*> spectGrData;


    QwtPlotGrid *grid;
    QVector<GraphItem> grItems;

    GraphItem nullGrItems;

    void initNullGraphItems();

public:
    explicit SPRSpectrumListTableWidget(QWidget *parent = 0);

    ISPRModelData *setModel(SPRSpectrumRangesTableModel *_rangesModel, QFile *inp = nullptr);
    void setSpectrumsData(QFile *inp);

public slots:
    void widgetsShow();
    void onChangeSpectColor(int row);
    void onChangeZoneColor(EnumElements el, QColor color){
        for(int i=0; i < grItems.size(); i++){
            QPen pen = grItems[i].zones[el]->pen();
            int alfa = pen.color().alpha();
            color.setAlpha(alfa);
            pen.setColor(color);
            grItems[i].zones[el]->setPen(pen);
            QBrush brush = grItems[i].zones[el]->brush();
            alfa = brush.color().alpha();
            color.setAlpha(alfa);
            brush.setColor(color);
            grItems[i].zones[el]->setBrush(brush);
        }

        widgetsShow();
    }

private:
    Ui::SPRSpectrumListTableWidget ui;

    // ISPRWidget interface
public:
    virtual SPRSpectrumRangesTableModel *getModel();

signals:
    void doShow();

    // ISPRWidget interface
protected slots:
    virtual void viewChange(int row, int col);
    virtual void viewChange(int row);
    virtual void viewChange(QColor);
    void onChangeZoneRange(EnumElements el, int thread, int col);

    // ISPRWidget interface
protected:

    // ISPRWidget interface
protected:
};

#endif // SPRSPECTRUMLISTTABLEWIDGET_H