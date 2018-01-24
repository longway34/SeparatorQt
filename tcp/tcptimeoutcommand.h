/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TCPTimeOutCommand.h
 * Author: longway
 *
 * Created on 19 января 2018 г., 17:56
 */

#ifndef TCPTIMEOUTCOMMAND_H
#define TCPTIMEOUTCOMMAND_H

#include "tcp/tcpcommand.h"

class TCPTimeOutCommand: public ITCPCommand{
    
    Q_OBJECT
    int parts;
    int cParts;
public:
    TCPTimeOutCommand(int _time, int _parts = -1):ITCPCommand(){
        code = timeout;
        timeOut = _time;
        parts = _parts;
        cParts = 0;
    }
    virtual ~TCPTimeOutCommand(){}
    
    virtual void send(){
        if(timeOut > 0){
            connect(&timer, SIGNAL(timeout()), this, SLOT(onTimeOut()));
            timer.setInterval(timeOut);
            timer.start();

        } else {
            emit commandComplite(num);
        }
    }

signals:
    void partsComplite(int parts, int allParts);


    // ITCPCommand interface
protected slots:
    virtual void onTimeOut();
    virtual void onReadyRead();

    // ITCPCommand interface
protected:
    virtual void setDataOut();
};

void TCPTimeOutCommand::setDataOut()
{
}

void TCPTimeOutCommand::onTimeOut()
{
    if(parts < 0){
        timer.stop();
        emit commandComplite(timeOut);
    } else {
        if(cParts >= parts){
            timer.stop();
            emit commandComplite(parts);
        } else {
            emit partsComplite(cParts, parts);
            cParts++;
        }
    }
}

void TCPTimeOutCommand::onReadyRead()
{
}

#endif /* TCPTIMEOUTCOMMAND_H */

