#ifndef SPRSETTINGSSPECTRUMRANGESMODEL_H
#define SPRSETTINGSSPECTRUMRANGESMODEL_H

#include <QObject>
#include <QDomDocument>
#include "isprmodeldata.h"
#include "models/sprspectrumrangesmodel.h"
#include "sprvariable.h"

class SPRSettingsSpectrumRangesModel : public ISPRModelData
{
public:
    SPRVariable<uint> *threads;
    SPRSpectrumRangesModel **items;

    SPRSettingsSpectrumRangesModel(){}
    SPRSettingsSpectrumRangesModel(QDomDocument *doc);
    virtual ~SPRSettingsSpectrumRangesModel();
    void setThreads(SPRVariable<uint> *value);
};

#endif // SPRSETTINGSSPECTRUMRANGESMODEL_H
