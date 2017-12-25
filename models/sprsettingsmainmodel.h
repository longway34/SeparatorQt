#ifndef SPRSETTINGSMAINMODEL_H
#define SPRSETTINGSMAINMODEL_H

#include <QObject>
#include "_types.h"
#include "models/isprmodeldata.h"
#include "models/sprcolorvariable.h"
#include "models/sprdatevariable.h"
#include "models/sprqstringvariable.h"
#include "models/sprvariable.h"

class SPRSettingsMainModel : public ISPRModelData
{
public:
    SPRSettingsMainModel(QObject *parent=nullptr);
    SPRSettingsMainModel(QDomDocument *_doc, QObject *parent = nullptr);
    virtual ~SPRSettingsMainModel();

    SPRQStringVariable *name;
    SPRQStringVariable *ipAddress;
    SPRVariable<uint> *ipPort;
    SPRVariable<uint> *rentgens;
    SPRVariable<uint> *ims;
    SPRVariable<uint> *threads;
//    SPRVariable<uint> *ims_row_count;
    SPRVariable<TypePRAM> *typePRAM;
    SPRVariable<TypeThermo> *typeThermo;
    SPRColorVariable *color;
//    SPRDateVariable *date;
//    SPRQStringVariable *version;

};

#endif // SPRSETTINGSMAINMODEL_H
