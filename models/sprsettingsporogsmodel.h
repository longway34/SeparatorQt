#ifndef SPRSETTINGSPOROGSMODEL_H
#define SPRSETTINGSPOROGSMODEL_H

#include <QObject>
#include "_types.h"
#include "models/sprporogsmodel.h"
#include "models/isprmodeldata.h"
#include "models/sprvariable.h"
#include "models/sprkprvariable.h"

class SPRSettingsPorogsModel : public ISPRModelData
{
    SPRVariable<TypeConditions> *conditions;
    SPRVariable<uint> *threads;
    SPRPorogsModel *porogs;
public:
    SPRSettingsPorogsModel(QObject *parent=nullptr);
    SPRSettingsPorogsModel(QDomDocument *_doc, QObject *parent = nullptr);
    virtual ~SPRSettingsPorogsModel();

    SPRKPRVariable *forMinStone;
    SPRKPRVariable *forMaxStone;
    SPRVariable<double> *xRayCorrection;
    SPRVariable<TypeSelection> *typeSelection;

    SPRVariable<TypeConditions> *getConditions() const;
    void setConditions(SPRVariable<TypeConditions> *value);
    SPRVariable<TypeSelection> *getTypeSelection() const;
    void setSelection(SPRVariable<TypeSelection> *value);
    SPRPorogsModel *getPorogs() const;
    SPRVariable<double> *getPorog(int thr, int condNum) const;
    SPRVariable<uint> *getThreads() const;
    void setThreads(SPRVariable<uint> *value);
};

#endif // SPRSETTINGSPOROGSMODEL_H
