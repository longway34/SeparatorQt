#include "sprgrspectrumitemmodel.h"

SPRGrSpectrumItemModel *SPRGrSpectrumItemModel::setSpect(SPRSpectrumItemModel *value)
{
    spect = value;
    return complite();
}

QPolygonF SPRGrSpectrumItemModel::getSamples() const
{
    return samples;
}

SPRGrSpectrumItemModel *SPRGrSpectrumItemModel::complite()
{
    if(spect){
        uint16_t *rawSpect = spect->getSpData()->spect;
        if(rawSpect){
            samples.clear();
            for(int i=0; i < DEF_SPECTRUM_DATA_LENGTH; i++){
                samples.push_back(QPointF(qreal(i), qreal(rawSpect[i])));
            }
        }
    }
    return isComplite();
}

SPRGrSpectrumItemModel::SPRGrSpectrumItemModel(QObject *parent) : QObject(parent), spect(nullptr)
{
    samples.clear();
}
