#include "_types.h"

static const EnumElements elementsValue[MAX_SPR_SPECTOR_ELEMENTS] = {Ns, Fe, Cu, Mo, Zn, Mg};

static const ElementsProperty elementsProperty[MAX_SPR_SPECTOR_ELEMENTS] = {
    {"Ns", "Рассеенка", QColor(255,0,255,100), 80, 256},
    {"Fe", "Железо", QColor(255, 0, 0, 100), 20, 40},
    {"Cu", "Медь", QColor(0,255,0,100), 40, 60},
    {"Mo", "Молибден", QColor(0,0,255,100), 60, 80},
    {"Zn", "Цинк", QColor(255,255,0,100), 80, 100},
    {"Mg", "Магний", QColor(0,255,255,100), 100, 120},

};

//SeparatorSettingsRentgenModel::SeparatorSettingsRentgenModel(quint16 tubes, quint16 threads){
//    iTubes = (quint16*)malloc(sizeof(quint16) * tubes);
//    uTubes = (quint16*)malloc(sizeof(quint16) * tubes);
//    for(int i=0; i<tubes; i++){
//        iTubes[i] = DEF_SPR_RENTGEN_I_TUBE;
//        uTubes[i] = DEF_SPR_RENTGEN_U_TUBE;
//    }
//    deuCodes = (quint16*)malloc(sizeof(quint16) * threads);
//    cpCodes = (quint16*)malloc(sizeof(quint16) * threads);
//    for(int i=0; i<threads; i++){
//        deuCodes[i] = DEF_SPR_RENTGEN_DEU_CODE;
//        cpCodes[i] = DEF_SPR_RENTGEN_CP_CODE;
//    }
//    timeOnRA = DEF_SPR_RENTGEN_TIME_ON_RA;
//    timeOffRA = DEF_SPR_RENTGEN_TIME_OFF_RA;
//    timeHotRA = DEF_SPR_RENTGEN_TIME_HOT_RA;

//    diffParamAllow = DEF_SPR_RENTGEN_DIFF_PARAM_ALLOW;
//    diffParamDisallow = DEF_SPR_RENTGEN_DIFF_PARAM_DISALLOW;
//    woControlPlace = DEF_SPR_RENTGEN_WO_CONTROL_PLACE;
//    timeMoveRGU = DEF_SPR_RENTGEN_TIME_MOVE_RGU;
//}

//SeparatorSettingsRentgenModel::~SeparatorSettingsRentgenModel(){
//    if(iTubes) delete iTubes;
//    if(uTubes) delete uTubes;
//    if(deuCodes) delete deuCodes;
//    if(cpCodes) delete cpCodes;
//}

