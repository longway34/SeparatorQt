#include "sprspectrumrangestablemodel.h"

SPRVariable<uint> *SPRSpectrumRangesTableModel::getThreads() const
{
    return threads;
}

void SPRSpectrumRangesTableModel::setThreads(SPRVariable<uint> *value)
{
    if(value){
        if(QVariant(property("delete_threads")).toBool()){
            if(threads) delete threads;
            setProperty("delete_threads", QVariant(false));
        }
        threads = value;
    }
}

SPRSpectrumRangesTableModel::SPRSpectrumRangesTableModel()
{

}

SPRSpectrumRangesTableModel::SPRSpectrumRangesTableModel(QDomDocument *_doc):
    ISPRModelData(_doc), threads(nullptr)
{

    threads = new SPRVariable<uint>(doc,SPR_SETTINGS_MAIN_THREADS_XPATH, DEF_SPR_MAIN_THREADS, this);
    setProperty("delete_threads", QVariant(true));

    for(int i=0; i<MAX_SPR_MAIN_THREADS; i++){
        items.push_back(new SPRSpectrumRangesModel(doc, i));
    }
}

SPRSpectrumRangesTableModel::~SPRSpectrumRangesTableModel()
{
    if(threads && QVariant(property("delete_threads")).toBool()){
        delete threads; threads = nullptr;
        setProperty("delete_threads", QVariant(false));
    }
}
