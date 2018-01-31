#ifndef SPRFORMULAITEMMODEL_H
#define SPRFORMULAITEMMODEL_H

#include <QObject>
#include "_types.h"
#include "models/isprmodeldata.h"
#include "models/sprvariable.h"
#include "models/sprelementvariable.h"

class SPRFormulaItemModel :public ISPRModelData

{
public:

    SPRElementVariable *ElementUp1;
    SPRElementVariable *ElementUp2;
    SPRVariable<double> *MulUp;
    SPRElementVariable *ElementDown1;
    SPRElementVariable *ElementDown2;
    SPRElementVariable *ElementDown3;
    SPRElementVariable *ElementDown4;
    SPRVariable<double> *MulDown;
    SPRVariable<double> *min, *max;

    int index;

    SPRFormulaItemModel(QObject *parent=nullptr);
    SPRFormulaItemModel(QDomDocument *_doc, int _index = 0, ISPRModelData *parent = nullptr);
    virtual ~SPRFormulaItemModel();
};

#endif // SPRFORMULAITEMMODEL_H
