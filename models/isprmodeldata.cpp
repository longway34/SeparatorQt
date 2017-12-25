#include <QDebug>
#include "isprmodeldata.h"

QDomDocument *ISPRModelData::getDoc() const
{
    return doc;
}

void ISPRModelData::setDoc(QDomDocument *value)
{
    doc = value;
    root = doc->documentElement();
}


ISPRModelData::ISPRModelData(QString fname)
{
//    QDomDocument document;
    QFile in(fname);
    if(in.open(QIODevice::ReadOnly)){
        if(!document.setContent(&in)){
            qDebug() << "Error!!! read content from " << fname << "new file created now...";
            document.createElement("SEPARATOR");
        }
    }
    setDoc(&document);
}

ISPRModelData::ISPRModelData(QDomDocument *_doc)
{
    setDoc(_doc);
}

void ISPRModelData::store(QString fname)
{
    store();
    if(!fname.isEmpty()){
        QFile fout(fname);
        if(fout.open(QIODevice::WriteOnly)){
            QTextStream out(&fout);
            out << doc->toString();
            fout.close();
        }
    }
}

void ISPRModelData::store(){
    emit goStore();
}
