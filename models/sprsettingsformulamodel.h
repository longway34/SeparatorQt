#ifndef SPRSETTINGSFORMULAMODEL_H
#define SPRSETTINGSFORMULAMODEL_H

#include <QObject>
#include <QVector>
#include <QDomDocument>

#include <models/isprmodeldata.h>
#include <models/sprformulaitemmodel.h>
#include <models/sprvariable.h>


class SPRSettingsFormulaModel : public ISPRModelData
{
protected:
    SPRVariable<TypeConditions> *conditions;
public:
    QVector<SPRFormulaItemModel*> itemsModel;

    SPRSettingsFormulaModel(QObject *parent = nullptr)
    {
        conditions = nullptr;
        setProperty("delete_conditions", QVariant(false));
        itemsModel.clear();
    }
    SPRSettingsFormulaModel(QDomDocument *doc, ISPRModelData *parent = nullptr):
        ISPRModelData(doc, parent)
    {

        for(int i=0; i<DEF_SPR_FORMULA_NUMBER; i++){
            SPRFormulaItemModel *mod = new SPRFormulaItemModel(doc, i, parent);
            itemsModel.push_back(mod);
            connect(this, SIGNAL(goStore()), itemsModel[i], SLOT(store()));
        }

        conditions = new SPRVariable<TypeConditions>(doc, SPR_POROGS_CONDITION_XPATH, DEF_SPR_FORMULA_CONDITION, this);
        setProperty("delete_conditions", QVariant(true));
    }
    virtual ~SPRSettingsFormulaModel(){
        if(conditions && QVariant(property("delete_conditions")).toBool()) delete conditions; conditions = nullptr;
    }
    virtual ISPRModelData *setModel(ISPRModelData *model){
        SPRFormulaItemModel * mod = (SPRFormulaItemModel*)model;
        itemsModel[mod->index] = mod;
        connect(this,SIGNAL(goStore()), mod, SLOT(store()));
        return model;
    }

    void setCondition(SPRVariable<TypeConditions> *value);
    SPRVariable<TypeConditions> *getConditions() const;
};

#endif // SPRSETTINGSFORMULAMODEL_H
