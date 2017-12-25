#ifndef SPRSETTINGSPOROGSMODEL_H
#define SPRSETTINGSPOROGSMODEL_H

#include <QObject>
#include "_types.h"
#include "models/isprmodeldata.h"
#include "models/sprvariable.h"
#include "models/sprkprvariable.h"

class SPRSettingsPorogsModel : public ISPRModelData
{
public:
    SPRSettingsPorogsModel(QObject *parent=nullptr);
    SPRSettingsPorogsModel(QDomDocument *_doc, QObject *parent = nullptr);
    virtual ~SPRSettingsPorogsModel();

    SPRVariable<TypeSelection> *typeSelection;
    SPRKPRVariable *forMinStone;
    SPRKPRVariable *forMaxStone;
    SPRVariable<double> *xRayCorrection;
};

#endif // SPRSETTINGSPOROGSMODEL_H
