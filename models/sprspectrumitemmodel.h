#ifndef SPRSPECTRUMITEMMODEL_H
#define SPRSPECTRUMITEMMODEL_H

#include <QObject>
#include "models/isprmodeldata.h"
#include "models/sprspectrumrangestablemodel.h"

#define DEF_SPECTRUM_DATA_BUF_LENGTH    708
#define DEF_SPECTRUM_DATA_LENGTH        512

typedef class spectumData{
    uint16_t bufLength;
    uint8_t  *buf;
public:
    char *name;
    uint32_t *thread;
    uint8_t *red, *green, *blue;
    uint16_t *spect;
    uint32_t *summ;
    uint32_t *peak_value;
    uint32_t *peak;
    double *Rs;
    uint32_t  *Ns, *Fe, *Cu, *Mo, *Zn, *Mg;
    double *H1, *H2, *H3;
    double *time, *center;
    uint32_t *year, *month, *day, *hours, *min, *sec;

    spectumData(): buf(nullptr){
        setData();
    }
    ~spectumData(){
        free(buf);
    }
    void setData(uint8_t* inp = nullptr, uint16_t inplength = DEF_SPECTRUM_DATA_BUF_LENGTH);
    void recomplite();

} SpectrumData;

Q_DECLARE_METATYPE(SpectrumData)

class SPRSpectrumItemModel : public ISPRModelData
{
    SPRSpectrumRangesTableModel *rangesTable;
    SpectrumData spData;

public:
    SPRSpectrumItemModel(QDomDocument *_doc);
    SPRSpectrumItemModel(SPRSpectrumRangesTableModel *_rangesTable);

    virtual ~SPRSpectrumItemModel(){
        if(QVariant(property("delete_ranges")).toBool()){
            delete rangesTable; rangesTable = nullptr;
            setProperty("delete_ranges", QVariant(false));
        }
    }

    ISPRModelData *setModel(SPRSpectrumRangesTableModel *_ranges){
        setRangesTable(_ranges);
        spData.recomplite();
        return _ranges;
    }

    SPRSpectrumRangesTableModel *getRangesTable() const;
    SPRSpectrumRangesModel *getRanges(){
        if(spData.thread){
            if(*spData.thread > 0 && *spData.thread < MAX_SPR_MAIN_THREADS){
                if(rangesTable){
                    return rangesTable->items[*spData.thread];
                }
            }
        }
    }
    void setRangesTable(SPRSpectrumRangesTableModel *value);
    SpectrumData *getSpData();
    void setSpData(uint8_t *buf, uint16_t len = DEF_SPECTRUM_DATA_BUF_LENGTH);

};

#endif // SPRSPECTRUMITEMMODEL_H
