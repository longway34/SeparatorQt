#include "sprspectrumitemmodel.h"

void spectumData::setData(uint8_t *inp, uint16_t inplength)
{

    if(!buf){
        bufLength = DEF_SPECTRUM_DATA_BUF_LENGTH;
        buf = (uint8_t*)malloc(bufLength);
        memset(buf, 0, bufLength);

        name = (char*)buf;
        thread = (uint32_t*)(buf + 0x28); // 40
        red = buf + 0x2C; green = buf + 0x2D; blue = buf + 0x2E; // 44 45 46
        spect = (uint16_t*)(buf + 0x30); // 48
        summ = (uint32_t*)(buf + 0x230); // 560
        peak_value = (uint32_t*)(buf + 0x234); // 564
        peak = (uint32_t*)(buf + 0x238); // 568
        Rs = (double*)(buf + 0x23C); // 572
        H1 = (double*)(buf + 0x244); H2 = (double*)(buf + 0x24C); H3 = (double*)(buf + 0x254); // 580 588 596
        time = (double*)(buf + 0x25C); // 604
        center = (double*)(buf + 0x268); // 616
        Ns = (uint32_t*)(buf + 0x278); // 632
        Fe = (uint32_t*)(buf + 0x27C); // 636
        Cu = (uint32_t*)(buf + 0x280); // 640
        Mo = (uint32_t*)(buf + 0x284); // 644
        Zn = (uint32_t*)(buf + 0x288); // 648
        Mg = (uint32_t*)(buf + 0x28C); // 652
        year = (uint32_t*)(buf + 0x2AC); // 684
        month = (uint32_t*)(buf + 0x2B0);  // 688
        day = (uint32_t*)(buf + 0x2B4);  // 692
        hours = (uint32_t*)(buf + 0x2B8); // 696
        min = (uint32_t*)(buf + 0x2BC); // 700
        sec = (uint32_t*)(buf + 0x2C0); // 704

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

