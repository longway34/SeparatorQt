/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TCPCommand.h
 * Author: longway
 *
 * Created on 18 января 2018 г., 15:33
 */

#ifndef TCPCOMMAND_H
#define TCPCOMMAND_H

#include <QObject>
#include <QTcpSocket>
#include <QTimer>
#include <QByteArray>
#include <QDebug>

#include "tcp/itcpcommand.h"

class TCPCommand : public ITCPCommand{
    
    Q_OBJECT
    
protected:
    QByteArray dataOut;
    QByteArray dataIn;

    virtual void setDataOut();
public:
    TCPCommand(): ITCPCommand(NULL, nocommand){
        setNum(-1); setTimeOut(-1);
    }
    
    TCPCommand(ServerConnect *_server, EnumCommands _code, int _num = -1, int _timeOut = -1):
        ITCPCommand(_server, _code)
    {
        this->setNum(_num); setTimeOut(_timeOut);
        setDataOut();
    }
    
    virtual void send();
    virtual ~TCPCommand(){}
    
protected slots:
    virtual void onTimeOut();
    virtual void onReadyRead();

public:
    QByteArray *getDataOut(){
        return &dataOut;
    }
    virtual QByteArray *getDataIn(){
        return &dataIn;
    }
    virtual void setDataOut(QByteArray dataOut) {
        this->dataOut = dataOut;
    }

};

#endif /* TCPCOMMAND_H */

