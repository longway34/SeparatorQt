#include "sprsettingsporogsmodel.h"

SPRSettingsPorogsModel::SPRSettingsPorogsModel(QObject *parent)
{
    typeSelection = nullptr;
    forMinStone = nullptr;
    forMaxStone = nullptr;
    xRayCorrection = nullptr;
}

SPRSettingsPorogsModel::SPRSettingsPorogsModel(QDomDocument *_doc, QObject *parent):
    ISPRModelData(_doc)
{
    typeSelection = new SPRVariable<TypeSelection>(doc,SPR_POROGS_TYPE_SELECTION_XPATH, DEF_SPR_POROGS_TYPE_SELECTION, this);
    forMinStone = new SPRKPRVariable(doc, SPR_POROGS_FOR_MIN_STONE_XPATH, DEF_SPR_POROGS_FOR_MIN_STONE, this);
    forMaxStone = new SPRKPRVariable(doc, SPR_POROGS_FOR_MAX_STONE_XPATH, DEF_SPR_POROGS_FOR_MAX_STONE, this);
    xRayCorrection = new SPRVariable<double>(doc, SPR_POROGS_X_RAY_CORRECTION_XPATH, DEF_SPR_POROGS_X_RAY_CORRECTION, this);
}

SPRSettingsPorogsModel::~SPRSettingsPorogsModel()
{
    if(typeSelection) delete typeSelection; typeSelection = nullptr;
    if(forMinStone) delete forMinStone; forMinStone = nullptr;
    if(forMaxStone) delete forMaxStone; forMaxStone = nullptr;
    if(xRayCorrection) delete xRayCorrection; xRayCorrection = nullptr;

}
