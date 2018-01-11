#ifndef SPRGPECTRUMITEMMODEL_H
#define SPRGPECTRUMITEMMODEL_H

#include <QObject>

#include "models/sprspectrumrangesmodel.h"
#include "models/sprspectrumitemmodel.h"

#include "qwt.h"
#include "qwt_plot.h"
#include "qwt_legend.h"

#include "qwt_plot_histogram.h"
#include "qwt_interval.h"
#include "qwt_series_data.h"

#include "qwt_plot_curve.h"

class SPRGrSpectrumZonesModel: public QObject
{
    Q_OBJECT

    SPRSpectrumRangesModel *ranges;
    SPRSpectrumItemModel *spect;

    QVector<QwtIntervalSample> zonesData;

    SPRGrSpectrumZonesModel *compliteData();
    SPRGrSpectrumZonesModel *isComplite();
public:
    explicit SPRGrSpectrumZonesModel(QObject *parent = nullptr):QObject(parent){}
    SPRGrSpectrumZonesModel(SPRSpectrumRangesModel *_ranges, SPRSpectrumItemModel _spect = nullptr);

    SPRSpectrumRangesModel *getRanges() const;
    SPRGrSpectrumZonesModel *setRanges(SPRSpectrumRangesModel *value);
    QVector<QwtIntervalSample> getZonesData() const;
    SPRGrSpectrumZonesModel *setSpect(SPRSpectrumItemModel *value);
};

#endif // SPRGPECTRUMITEMMODEL_H
