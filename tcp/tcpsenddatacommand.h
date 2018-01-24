/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TCPSendDataCommand.h
 * Author: longway
 *
 * Created on 19 января 2018 г., 16:35
 */

#ifndef TCPSENDDATACOMMAND_H
#define TCPSENDDATACOMMAND_H

#include "tcp/tcpcommand.h"

class TCPSendDataCommand: public TCPCommand {
    
    Q_OBJECT
    
public:
    TCPSendDataCommand(ServerConnect *_server, EnumCommands _code, int _num, int _timeOut):
            TCPCommand(_server, _code, _num, _timeOut){
    }
    TCPSendDataCommand(ServerConnect *_server, EnumCommands _code, QByteArray _data, int _num = -1, int _timeOut = -1):
            TCPCommand(_server, _code, _num, _timeOut){
                setData(_data);
            }
    virtual ~TCPSendDataCommand(){}
    
    void setData(QByteArray _data){
        dataOut.append(_data);
    }
private:

};

#endif /* TCPSENDDATACOMMAND_H */

