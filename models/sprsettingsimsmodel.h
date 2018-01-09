#ifndef SPRSETTINGSIMSMODEL_H
#define SPRSETTINGSIMSMODEL_H

#include <QObject>
#include <models/isprmodeldata.h>
#include <models/sprvariable.h>

class SPRSettingsIMSModel : public ISPRModelData
{
    SPRVariable<uint> *ims;
public:
    SPRVariable<uint> *tMeteringMinStone;
    SPRVariable<uint> *tMeteringMaxStone;
    SPRVariable<uint> *tMeteringMaxMaxStone;

    SPRVariable<uint> *tDelayMinStone;
    SPRVariable<uint> *tDelayMaxStone;
    SPRVariable<uint> *tDelayMaxMaxStone;

    SPRVariable<uint> *tDurationMinStone;
    SPRVariable<uint> *tDurationMaxStone;
    SPRVariable<uint> *tDurationMaxMaxStone;

    SPRVariable<bool> *withMaxMaxStone;

    SPRVariable<uint> *blockImsParam;
    SPRVariable<double> *kSpeedOreA;
    SPRVariable<double> *kSpeedOreB;

    SPRVariable<qulonglong> *limitAbrasion;
    QVector<SPRVariable<qulonglong>*> abrasions;


    SPRSettingsIMSModel();
    SPRSettingsIMSModel(QDomDocument *_doc, QObject *parent = nullptr);
    virtual ~SPRSettingsIMSModel();

    SPRVariable<uint> *getIms() const;
    void setIms(SPRVariable<uint> *value);
};

#endif // SPRSETTINGSIMSMODEL_H
