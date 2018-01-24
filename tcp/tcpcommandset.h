/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TCPCommandSet.h
 * Author: longway
 *
 * Created on 19 января 2018 г., 21:40
 */

#ifndef TCPCOMMANDSET_H
#define TCPCOMMANDSET_H

#include "tcp/tcpcommand.h"
#include "QVector"

//template <class T>
class TCPCommandSet: public QObject, public QVector<ITCPCommand*> {
    Q_OBJECT
public:
    TCPCommandSet():QVector<ITCPCommand*>(){}
    TCPCommandSet(QVector<ITCPCommand*> vect): QVector<ITCPCommand*>(vect){}
    
    virtual QByteArray *getDataIn(){return NULL;}
    QVector<ITCPCommand *> findByName(EnumCommands name);
public slots:
    virtual void go(int num = -1);
    void onShowLogMessages(QString str){
        emit showLogMessage(str);
    }

signals:
    void commandSetComplite();
    void showLogMessage(QString);
};


#endif /* TCPCOMMANDSET_H */

