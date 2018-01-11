#ifndef SPRGRSPECTRUMITEMMODEL_H
#define SPRGRSPECTRUMITEMMODEL_H

#include <QObject>
#include <QWidget>

#include "models/sprspectrumitemmodel.h"

class SPRGrSpectrumItemModel : public QObject
{
    Q_OBJECT

    SPRSpectrumItemModel *spect;

    QPolygonF samples;

    SPRGrSpectrumItemModel *complite();
    SPRGrSpectrumItemModel *isComplite(){
        return (samples.size() > 0);
    }

public:
    explicit SPRGrSpectrumItemModel(QObject *parent = nullptr);

    SPRGrSpectrumItemModel *setSpect(SPRSpectrumItemModel *value);

    QPolygonF getSamples() const;

signals:

public slots:
};

#endif // SPRGRSPECTRUMITEMMODEL_H
