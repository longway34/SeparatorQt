#ifndef SPRSPECTRUMRANGESTABLEMODEL_H
#define SPRSPECTRUMRANGESTABLEMODEL_H

#include <QObject>
#include <QDomDocument>

#include "models/isprmodeldata.h"
#include "models/sprvariable.h"
#include "models/sprspectrumrangesmodel.h"

class SPRSpectrumRangesTableModel : public ISPRModelData
{
    SPRVariable<uint> *threads;
public:
    QVector<SPRSpectrumRangesModel*> items;

    SPRSpectrumRangesTableModel();
    SPRSpectrumRangesTableModel(QDomDocument *_doc);
    ~SPRSpectrumRangesTableModel();

    SPRVariable<uint> *getThreads() const;
    void setThreads(SPRVariable<uint> *value);
};

#endif // SPRSPECTRUMRANGESTABLEMODEL_H
