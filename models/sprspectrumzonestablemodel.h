#ifndef SPRSPECTRUMZONESTABLEMODEL_H
#define SPRSPECTRUMZONESTABLEMODEL_H

#include <QObject>
#include <QDomDocument>

#include "models/isprmodeldata.h"
#include "models/sprvariable.h"
#include "models/sprspectrumzonesmodel.h"

class SPRSpectrumZonesTableModel : public ISPRModelData
{
    SPRVariable<uint> *threads;
public:
    QVector<SPRSpectrumZonesModel*> items;

    SPRSpectrumZonesTableModel();
    SPRSpectrumZonesTableModel(QDomDocument *_doc, ISPRModelData *parent = nullptr);
    ~SPRSpectrumZonesTableModel();

    SPRVariable<uint> *getThreads() const;
    void setThreads(SPRVariable<uint> *value);
};

#endif // SPRSPECTRUMZONESTABLEMODEL_H
