#ifndef ISPRMODELDATA_H
#define ISPRMODELDATA_H

#include <QObject>
#include <QWidget>
#include <QList>
#include <QDomDocument>
#include <QFile>
#include <iostream>

//#include "models/isprvariable.h"

class ISPRModelData : public QObject
{
    Q_OBJECT

protected:
    QDomDocument document;
    QDomDocument *doc;
    QDomElement root;

public:
    ISPRModelData(){}
    ISPRModelData(QString fname);
    ISPRModelData(QDomDocument *_doc);

//    void addControlVariable(ISPRVariable* var){
//        if(var){
//            connect(this, SIGNAL(store()), var, SLOT(setData()));
//        }
//    }
    QDomDocument *getDoc() const;
    void setDoc(QDomDocument *value);

signals:
    void goStore();
public slots:
    virtual void store(QString fname);
    virtual void store();
};

#endif // ISPRMODELDATA_H
