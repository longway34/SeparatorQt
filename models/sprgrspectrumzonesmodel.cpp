#include "sprgrspectrumzonesmodel.h"
#include "_types.h"

SPRSpectrumRangesModel *SPRGrSpectrumZonesModel::getRanges() const
{
    return ranges;
}

SPRGrSpectrumZonesModel *SPRGrSpectrumZonesModel::setRanges(SPRSpectrumRangesModel *value)
{
    ranges = value;
    compliteData();
    return
}

QVector<QwtIntervalSample> SPRGrSpectrumZonesModel::getZonesData() const
{
    return zonesData;
}

SPRGrSpectrumZonesModel *SPRGrSpectrumZonesModel::setSpect(SPRSpectrumItemModel *value)
{
    spect = value;
    return compliteData();
}

SPRGrSpectrumZonesModel *SPRGrSpectrumZonesModel::compliteData()
{
    if(ranges){
        zonesData.clear();
        QVector<QwtIntervalSample> intervals;
        foreach (EnumElements el, ranges->elements.keys()) {
            uint xmin = ranges->elements[el].min->getData();
            uint xmax = ranges->elements[el].max->getData();
            double value = 0.5;
            if(spect){
                uint16_t *rawSpect = spect->getSpData()->spect;
                if(rawSpect){
                    for(int i=xmin; i < xmax; i++){
                        if(rawSpect[i] > value){
                            value = rawSpect[i];
                        }
                    }
                }
            }
            QwtIntervalSample interval(value, double(xmin), double(xmax));
            zonesData.push_back(interval);
        }
    }
    return isComplite();
}

SPRGrSpectrumZonesModel *SPRGrSpectrumZonesModel::isComplite()
{
    if(zonesData.size() > 0){
        return this;
    } else {
        return nullptr;
    }
}

SPRGrSpectrumZonesModel::SPRGrSpectrumZonesModel(SPRSpectrumRangesModel *_ranges, SPRSpectrumItemModel _spect):
    ranges(nullptr), spect(nullptr)
{
    ranges = _ranges;
    spect = _spect;
    zonesData.clear();

    compliteData();
}
