#include "sprspectrumitemmodel.h"

void spectumData::setData(uint8_t *inp, uint16_t inplength)
{
    if(!buf){
        bufLength = DEF_SPECTRUM_DATA_BUF_LENGTH;
        buf = (uint8_t*)malloc(bufLength);
        memset(buf, 0, bufLength);

        name = (char*)buf;
        thread = (uint32_t*)(buf + 40);
        red = buf + 44; green = buf + 45; blue = buf + 46;
        spect = (uint16_t*)(buf + 48);
        summ = (uint32_t*)(buf + 560);
        peak_value = (uint32_t*)(buf + 564);
        peak = (uint32_t*)(buf + 568);
        Rs = (double*)(buf + 572);
        H1 = (double*)(buf + 580); H2 = (double*)(buf + 588); H3 = (double*)(buf + 596);
        time = (double*)(buf + 604); center = (double*)(buf + 616);
        Ns = (uint32_t*)(buf + 632); Fe = (uint32_t*)(buf + 636); Cu = (uint32_t*)(buf + 640); Mo = (uint32_t*)(buf + 644); Zn = (uint32_t*)(buf + 648); Mg = (uint32_t*)(buf + 652);
        year = (uint32_t*)(buf + 684); month = (uint32_t*)(buf + 688); day = (uint32_t*)(buf + 692); hours = (uint32_t*)(buf + 696); min = (uint32_t*)(buf + 700); sec = (uint32_t*)(buf + 704);

    }
    if(inp){
        if(inplength == bufLength){
            memcpy(buf, inp, bufLength);
            return;
        }
        if(inplength == DEF_SPECTRUM_DATA_LENGTH){
            memcpy(inp, spect, inplength);
            recomplite();
            return;
        }
        qDebug() << "Error Data Length... Try " << QString::number(DEF_SPECTRUM_DATA_BUF_LENGTH) << " to all spectrum data or " << QString::number(DEF_SPECTRUM_DATA_LENGTH) << " for spectrum only...";
    }
}

void spectumData::recomplite()
{

}

SPRSpectrumRangesTableModel *SPRSpectrumItemModel::getRangesTable() const
{
    return rangesTable;
}

void SPRSpectrumItemModel::setRangesTable(SPRSpectrumRangesTableModel *value)
{
    rangesTable = value;
    setProperty("delete_ranges", QVariant(false));
}

SpectrumData *SPRSpectrumItemModel::getSpData()
{
    return &spData;
}

void SPRSpectrumItemModel::setSpData(uint8_t *buf, uint16_t len)
{
    spData.setData(buf, len);
}

SPRSpectrumItemModel::SPRSpectrumItemModel(QDomDocument *_doc) : ISPRModelData(_doc)
{
    rangesTable = new SPRSpectrumRangesTableModel(doc);
    setProperty("delete_ranges", QVariant(true));
}

SPRSpectrumItemModel::SPRSpectrumItemModel(SPRSpectrumRangesTableModel *_rangesTable)
{
    setRangesTable(_rangesTable);
}

