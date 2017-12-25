#include "sprsettingsrentgenmodel.h"

void SPRSettingsRentgenModel::setRentgens(SPRVariable<uint> *value)
{
    if(value){
        if(QVariant(property("delete_rentgens")).toBool()){
            if(rentgens) delete rentgens;
            setProperty("delete_rentgens", QVariant(false));
        }
        rentgens = value;
    }
}

void SPRSettingsRentgenModel::setThreads(SPRVariable<uint> *value)
{
    if(value){
        if(QVariant(property("delete_threads")).toBool()){
            if(threads) delete threads;
            setProperty("delete_threads", QVariant(false));
        }
        threads = value;
    }
}

SPRSettingsRentgenModel::SPRSettingsRentgenModel(QObject *parent)
{
    iTubes = nullptr;
    uTubes = nullptr;
    deuCodes = nullptr;
    cpCodes = nullptr;
    timeOnRA = nullptr;
    timeOffRA = nullptr;
    timeHotRA = nullptr;
    diffParamAllow = nullptr;
    diffParamDisallow = nullptr;
    timeMoveRGU = nullptr;
    woControlPlace = nullptr;
    threads = nullptr;
    setProperty("delete_threads", QVariant(false));
    rentgens = nullptr;
    setProperty("delete_rentgens", QVariant(false));
}

SPRSettingsRentgenModel::SPRSettingsRentgenModel(QDomDocument *_doc, QObject *parent):
    ISPRModelData(_doc)
{
    iTubes = (SPRVariable<uint>**) malloc(sizeof(SPRVariable<uint>*) * MAX_SPR_MAIN_RENTGENS);
    uTubes = (SPRVariable<uint>**) malloc(sizeof(SPRVariable<uint>*) * MAX_SPR_MAIN_RENTGENS);
    deuCodes = (SPRVariable<uint>**) malloc(sizeof(SPRVariable<uint>*) * MAX_SPR_MAIN_THREADS);
    cpCodes = (SPRVariable<uint>**) malloc(sizeof(SPRVariable<uint>*) * MAX_SPR_MAIN_THREADS);

    iTubes[0] = new SPRVariable<uint>(doc, SPR_RENTGEN_I_TUBE_0_XPATH, DEF_SPR_RENTGEN_I_TUBE,this);
    iTubes[1] = new SPRVariable<uint>(doc, SPR_RENTGEN_I_TUBE_1_XPATH, DEF_SPR_RENTGEN_I_TUBE,this);
    uTubes[0] = new SPRVariable<uint>(doc, SPR_RENTGEN_U_TUBE_0_XPATH, DEF_SPR_RENTGEN_U_TUBE,this);
    uTubes[1] = new SPRVariable<uint>(doc, SPR_RENTGEN_U_TUBE_1_XPATH, DEF_SPR_RENTGEN_U_TUBE,this);

    deuCodes[0] = new SPRVariable<uint>(doc, SPR_RENTGEN_DEU_CODE_0_XPATH, DEF_SPR_RENTGEN_DEU_CODE,this);
    deuCodes[1] = new SPRVariable<uint>(doc, SPR_RENTGEN_DEU_CODE_1_XPATH, DEF_SPR_RENTGEN_DEU_CODE,this);
    deuCodes[2] = new SPRVariable<uint>(doc, SPR_RENTGEN_DEU_CODE_2_XPATH, DEF_SPR_RENTGEN_DEU_CODE,this);
    deuCodes[3] = new SPRVariable<uint>(doc, SPR_RENTGEN_DEU_CODE_3_XPATH, DEF_SPR_RENTGEN_DEU_CODE,this);
    cpCodes[0] = new SPRVariable<uint>(doc, SPR_RENTGEN_CP_CODE_0_XPATH, DEF_SPR_RENTGEN_CP_CODE,this);
    cpCodes[1] = new SPRVariable<uint>(doc, SPR_RENTGEN_CP_CODE_1_XPATH, DEF_SPR_RENTGEN_CP_CODE,this);
    cpCodes[2] = new SPRVariable<uint>(doc, SPR_RENTGEN_CP_CODE_2_XPATH, DEF_SPR_RENTGEN_CP_CODE,this);
    cpCodes[3] = new SPRVariable<uint>(doc, SPR_RENTGEN_CP_CODE_3_XPATH, DEF_SPR_RENTGEN_CP_CODE,this);

    timeOnRA = new SPRVariable<uint>(doc, SPR_RENTGEN_TIME_ON_RA_XPATH, DEF_SPR_RENTGEN_TIME_ON_RA,this);
    timeOffRA = new SPRVariable<uint>(doc, SPR_RENTGEN_TIME_OFF_RA_XPATH, DEF_SPR_RENTGEN_TIME_OFF_RA,this);
    timeHotRA = new SPRVariable<uint>(doc, SPR_RENTGEN_TIME_HOT_RA_XPATH, DEF_SPR_RENTGEN_TIME_HOT_RA,this);

    diffParamAllow = new SPRVariable<uint>(doc, SPR_RENTGEN_DIFF_PARAM_ALLOW, DEF_SPR_RENTGEN_DIFF_PARAM_ALLOW,this);
    diffParamDisallow = new SPRVariable<uint>(doc, SPR_RENTGEN_DIFF_PARAM_DISALLOW, DEF_SPR_RENTGEN_DIFF_PARAM_DISALLOW,this);

    woControlPlace = new SPRVariable<bool>(doc, SPR_RENTGEN_WO_CONTROL_PLACE, DEF_SPR_RENTGEN_WO_CONTROL_PLACE,this);
    timeMoveRGU = new SPRVariable<uint>(doc, SPR_RENTGEN_TIME_MOVE_RGU, DEF_SPR_RENTGEN_TIME_MOVE_RGU,this);

    threads  = new SPRVariable<uint>(doc, SPR_SETTINGS_MAIN_THREADS_XPATH, DEF_SPR_MAIN_THREADS, this);
    setProperty("delete_threads", QVariant(true));
    rentgens = new SPRVariable<uint>(doc,SPR_SETTINGS_MAIN_RENTGENS_XPATH, DEF_SPR_MAIN_RENTGENS, this);
    setProperty("delete_rentgens", QVariant(true));
}

SPRSettingsRentgenModel::~SPRSettingsRentgenModel()
{
    if(iTubes){
        for(int i=0; i < MAX_SPR_MAIN_RENTGENS; i++){
            if(iTubes[i]) delete iTubes[i]; iTubes[i] = nullptr;
        }
        delete iTubes; iTubes = nullptr;
    }
    if(uTubes){
        for(int i=0; i < MAX_SPR_MAIN_RENTGENS; i++){
            if(uTubes[i]) delete uTubes[i]; uTubes[i] = nullptr;
        }
        delete uTubes; uTubes = nullptr;
    }
    if(deuCodes){
        for(int i=0; i< MAX_SPR_MAIN_THREADS; i++){
            if(deuCodes[i]) delete deuCodes[i]; deuCodes = nullptr;
        }
        delete deuCodes;
    }
    if(cpCodes){
        for(int i=0; i< MAX_SPR_MAIN_THREADS; i++){
            if(cpCodes[i]) delete cpCodes[i]; cpCodes = nullptr;
        }
        delete cpCodes;
    }

    if(timeOnRA) delete timeOnRA; timeOnRA = nullptr;
    if(timeOffRA) delete timeOffRA; timeOffRA = nullptr;
    if(timeHotRA) delete timeHotRA; timeHotRA = nullptr;

    if(diffParamAllow) delete diffParamAllow; diffParamAllow = nullptr;
    if(diffParamDisallow) delete diffParamDisallow; diffParamDisallow = nullptr;

    if(timeMoveRGU) delete timeMoveRGU; timeMoveRGU = nullptr;
    if(woControlPlace) delete woControlPlace; woControlPlace = nullptr;
    if(threads && QVariant(property("delete_threads")).toBool()) delete threads; threads = nullptr;
    setProperty("delete_threads", QVariant(false));
    if(rentgens && QVariant(property("delete_rentgens")).toBool()) delete rentgens; rentgens = nullptr;
    setProperty("delete_rentgens", QVariant(false));
}
