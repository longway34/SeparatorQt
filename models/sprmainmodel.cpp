#include "sprmainmodel.h"
#include <QDir>

void SPRMainModel::setDoc(QDomDocument *value)
{
    doc = value;

    settingsMainModel = new SPRSettingsMainModel(doc, this);

    settingsPorogsModel = new SPRSettingsPorogsModel(doc, this);
    settingsPorogsModel->setThreads(settingsMainModel->getThreads());

    settingsRentgenModel = new SPRSettingsRentgenModel(doc, this);
    settingsRentgenModel->setThreads(settingsMainModel->getThreads());
    settingsRentgenModel->setRentgens(settingsMainModel->getRentgens());

    settingsIMSModel = new SPRSettingsIMSModel(doc, this);
    settingsIMSModel->setIms(settingsMainModel->getIms());

    settingsControlModel = new SPRSettingsControlModel(doc, this);

    settingsFormulaModel = new SPRSettingsFormulaModel(doc, this);
    settingsFormulaModel->setCondition(settingsPorogsModel->getConditions());

    spectrumZonesTableModel = new SPRSpectrumZonesTableModel(doc, this);
    spectrumZonesTableModel->setThreads(settingsMainModel->getThreads());
}

SPRQStringVariable *SPRMainModel::getSpectrumFName() const
{
    return spectrumFName;
}

void SPRMainModel::setSpectrumFName(SPRQStringVariable *value)
{
    spectrumFName = value;
}

SPRMainModel::SPRMainModel(QDomDocument *_doc, ISPRModelData *parent): ISPRModelData(_doc, parent),
    settingsControlModel(nullptr),
    settingsFormulaModel(nullptr),
    settingsIMSModel(nullptr),
    settingsMainModel(nullptr),
    settingsPorogsModel(nullptr),
    settingsRentgenModel(nullptr),
    spectrumZonesTableModel(nullptr)
{
    setDoc(_doc);
}

SPRMainModel::SPRMainModel(QString docFName, ISPRModelData *parent): ISPRModelData(docFName, parent),
    settingsControlModel(nullptr),
    settingsFormulaModel(nullptr),
    settingsIMSModel(nullptr),
    settingsMainModel(nullptr),
    settingsPorogsModel(nullptr),
    settingsRentgenModel(nullptr),
    spectrumZonesTableModel(nullptr)

{
    fPath = "";
    if(docFName.contains(QDir::separator())){
        QStringList fPathl = docFName.split(QDir::separator());
        while(fPathl.size()>0){
            fPath += fPathl.front(); fPathl.pop_front();
        }
    }
    bool y = QDir::setCurrent("F:\\Projects\\Separator\\");
    QDomDocument *doc;

    QFile in(docFName);
    if(in.open(QIODevice::ReadOnly)){
        if(document.setContent(&in)){
            doc = &document;
            in.close();
        }
    }
    setDoc(doc);
}

QDomDocument *SPRMainModel::getDoc() const
{
    return doc;
}
