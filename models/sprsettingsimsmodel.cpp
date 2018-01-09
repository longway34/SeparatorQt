#include "sprsettingsimsmodel.h"


SPRVariable<uint> *SPRSettingsIMSModel::getIms() const
{
    return ims;
}

void SPRSettingsIMSModel::setIms(SPRVariable<uint> *value)
{
    if(value){
        ims = value;
        setProperty("delete_ims", QVariant(false));
    }
}
SPRSettingsIMSModel::SPRSettingsIMSModel(){
    ims = nullptr; setProperty("delete_ims", QVariant(false));
    tMeteringMinStone = nullptr;
    tMeteringMaxStone =nullptr;
    tMeteringMaxMaxStone =nullptr;
    tDurationMinStone = nullptr;
    tDurationMaxStone = nullptr;
    tDurationMaxMaxStone = nullptr;
    tDelayMinStone = nullptr;
    tDelayMaxStone = nullptr;
    tDelayMaxMaxStone = nullptr;

    kSpeedOreA = nullptr;
    kSpeedOreB = nullptr;

    limitAbrasion = nullptr;
    blockImsParam = nullptr;

    withMaxMaxStone = nullptr;
}

SPRSettingsIMSModel::SPRSettingsIMSModel(QDomDocument *_doc, QObject *parent):
    ISPRModelData(_doc)
{
    ims = new SPRVariable<uint>(doc, SPR_SETTINGS_MAIN_IMS_XPATH, DEF_SPR_MAIN_IMS, this);
    setProperty("delete_ims", QVariant(true));

    tMeteringMinStone = new SPRVariable<uint>(doc, SPR_IMS_T_METTERING_MIN_STONE_XPATH, DEF_SPR_IMS_T_METTERING_MIN_STONE, this);
    tMeteringMaxStone = new SPRVariable<uint>(doc, SPR_IMS_T_METTERING_MAX_STONE_XPATH, DEF_SPR_IMS_T_METTERING_MAX_STONE, this);
    tMeteringMaxMaxStone = new SPRVariable<uint>(doc, SPR_IMS_T_METTERING_MAX_MAX_STONE_XPATH, DEF_SPR_IMS_T_METTERING_MAX_NAX_STONE, this);

    tDelayMinStone = new SPRVariable<uint>(doc, SPR_IMS_T_DELAY_MIN_STONE_XPATH, DEF_SPR_IMS_T_DELAY_MIN_STONE, this);
    tDelayMaxStone = new SPRVariable<uint>(doc, SPR_IMS_T_DELAY_MAX_STONE_XPATH, DEF_SPR_IMS_T_DELAY_MAX_STONE, this);
    tDelayMaxMaxStone = new SPRVariable<uint>(doc, SPR_IMS_T_DELAY_MAX_MAX_STONE_XPATH, DEF_SPR_IMS_T_DELAY_MAX_MAX_STONE, this);

    tDurationMinStone = new SPRVariable<uint>(doc, SPR_IMS_T_DURATION_MIN_STONE_XPATH, DEF_SPR_IMS_T_DURATION_MIN_STONE, this);
    tDurationMaxStone = new SPRVariable<uint>(doc, SPR_IMS_T_DURATION_MAX_STONE_XPATH, DEF_SPR_IMS_T_DURATION_MAX_STONE, this);
    tDurationMaxMaxStone = new SPRVariable<uint>(doc, SPR_IMS_T_DURATION_MAX_MAX_STONE_XPATH, DEF_SPR_IMS_T_DURATION_MAX_MAX_STONE, this);

    blockImsParam = new SPRVariable<uint>(doc, SPR_IMS_BLOCK_PARAM_XPATH, DEF_SPR_IMS_BLOCK_PARAM, this);
    kSpeedOreA = new SPRVariable<double>(doc, SPR_IMS_SPEAD_ORE_A, DEF_SPR_IMS_SPEAD_ORE_A, this);
    kSpeedOreB = new SPRVariable<double>(doc, SPR_IMS_SPEAD_ORE_B, DEF_SPR_IMS_SPEAD_ORE_B, this);
    limitAbrasion = new SPRVariable<qulonglong>(doc, SPR_IMS_LIMIT_ABRASION_XPATH, DEF_SPR_IMS_LIMIT_ABRASION, this);

    withMaxMaxStone = new SPRVariable<bool>(doc, SPR_IMS_WITH_MAX_STONE, DEF_SPR_IMS_WITH_MAX_STONE, this);

    for(int i=0; i<MAX_SPR_MAIN_IMS; i++){
        QString xpath = SPR_IMS_ABRASIONS_XPATH_PREFIX+QString::number(i)+"]";
        SPRVariable<qulonglong> *var = new SPRVariable<qulonglong>(doc, xpath, DEF_SPR_IMS_ABRASION, this);
        abrasions.push_back(var);
    }
}

SPRSettingsIMSModel::~SPRSettingsIMSModel()
{
    if(ims && QVariant(property("delete_ims")).toBool()){
        delete ims; ims = nullptr;
    }

    if(tMeteringMinStone) delete tMeteringMinStone; tMeteringMinStone = nullptr;
    if(tMeteringMaxStone) delete tMeteringMaxStone; tMeteringMaxStone = nullptr;

    if(tDelayMinStone) delete tDelayMinStone; tDelayMinStone = nullptr;
    if(tDelayMaxStone) delete tDelayMaxStone; tDelayMaxStone = nullptr;

    if(tDurationMinStone) delete tDurationMinStone; tDurationMinStone = nullptr;
    if(tDurationMaxStone) delete tDurationMaxStone; tDurationMaxStone = nullptr;

    if(kSpeedOreA) delete kSpeedOreA; kSpeedOreA = nullptr;
    if(kSpeedOreB) delete kSpeedOreB; kSpeedOreB = nullptr;

    if(blockImsParam) delete blockImsParam; blockImsParam = nullptr;
    if(limitAbrasion) delete limitAbrasion; limitAbrasion = nullptr;

    if(withMaxMaxStone) delete withMaxMaxStone; withMaxMaxStone = nullptr;

    for(int i=0; i<abrasions.size(); i++){
        if(abrasions[i]) delete abrasions[i]; abrasions.pop_front();
    }
}
