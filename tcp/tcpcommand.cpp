/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TCPCommand.cpp
 * Author: longway
 * 
 * Created on 18 января 2018 г., 15:33
 */

#include "tcpcommand.h"

void TCPCommand::setDataOut(){
    dataOut = QByteArray::fromRawData(bCode(), 1);
}

void TCPCommand::send(){
    if(code != nocommand){
        if(server->getSocket()->state() != QAbstractSocket::SocketState::ConnectedState){
            if(!server->_connect()){
                emit commandErrorConnect(*bCode(), code);

                emit showLogMessage(QString(tr("Error connect from command ")) +
                                    QString::number(num) + QString(tr(" with code "))+
                                    QString::number(*bCode()));
                return;
            }
        }

        server->getMutex()->lock();
        connect(server, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
        server->write(dataOut);
        if(server->waitForBytesWritten()){
            qDebug() << "send "<< bCode() << " command " << dataOut.toHex(':');
        } else {
            server->getMutex()->unlock();
            emit commandErrorWrite(num, code);
            emit showLogMessage(QString(tr("Error write from command ")) +
                                QString::number(num) + QString(tr(" with code "))+
                                QString::number(*bCode()));
        }
    }
}

void TCPCommand::onTimeOut(){
    qDebug() << "result " << bCode() << " command " << dataIn.toHex(':') << " past timeout " << timeOut;
    emit showLogMessage(QString(tr("Command ")) +
                        QString::number(num) + QString(tr(" with code "))+
                        QString::number(*bCode())+
                        QString(" out: ")+dataOut.toHex(':')+
                        QString(" result: ")+dataIn.toHex(':')+ dataIn.toInt()+
                        QString(tr( "past timeout"))+
                        QString::number(timer.interval()));
    timer.stop();
    emit commandComplite(num);
}

void TCPCommand::onReadyRead(){
    dataIn.clear();
    while(server->getSocket()->bytesAvailable() > 0){
        dataIn.append(server->getSocket()->read(1));
    }
    server->getMutex()->unlock();

    disconnect(server->getSocket(), SIGNAL(readyRead()), this, SLOT(onReadyRead()));
    if(timeOut > 0){
        timer.start(timeOut);
    } else {
        qDebug() << "result " << bCode() << " command " << dataIn.toHex(':');
        emit commandComplite(num);
        emit showLogMessage(QString(tr("Command ")) +
                            QString::number(num) + QString(tr(" with code "))+
                            QString::number(*bCode())+
                            QString(" out: ")+dataOut.toHex(':')+
                            QString(" result: ")+dataIn.toHex(':'));
    }
}
