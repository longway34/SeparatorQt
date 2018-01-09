#ifndef SPRSETTINGSIMSWIDGET_H
#define SPRSETTINGSIMSWIDGET_H

#include "ui_sprsettingsimswidget.h"
#include "isprwidget.h"
#include "models/sprsettingsimsmodel.h"

#include <qwt_plot_curve.h>
#include <qwt_plot_grid.h>
#include <qwt_plot_histogram.h>
#include <qwt_plot_barchart.h>
#include <qwt_plot_zoomer.h>
#include <qwt_legend.h>

class SPRSettingsIMSWidget : public QWidget, public ISPRWidget
{
    Q_OBJECT
    SPRSettingsIMSModel *model;
public:
    explicit SPRSettingsIMSWidget(QWidget *parent = 0);

    ISPRModelData *getModel();
    void setIms(SPRVariable<uint> *ims){model->setIms(ims);}

private:
    Ui::SPRSettingsIMSWidget ui;

    QwtPlotCurve *curveRed;
    QwtPlotCurve *curveGreen;

    QwtPlotHistogram *gist;

    QwtPlotGrid *grid;
    QwtPlotBarChart *bars;
    QwtPlotZoomer *zoom100;
    QwtLegend *legend;
    // ISPRWidget interface
public:

    ISPRModelData *setModel(SPRSettingsIMSModel *value);

    void repaintGraphicSetts(double);
public slots:
    virtual void viewChange();
    virtual void viewChange(bool val);
    virtual void widgetsShow();
};

#endif // SPRSETTINGSIMSWIDGET_H
