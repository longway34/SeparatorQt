/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TCPCommandSet.cpp
 * Author: longway
 * 
 * Created on 19 января 2018 г., 21:40
 */

#include "tcpcommandset.h"
#include <QMessageBox>

void TCPCommandSet::go(int num){
    if(num < 0){
        for(int i=0; i<size(); i++){
            ITCPCommand *command = (TCPCommand*)this->at(i);
            command->setNum(i);
            connect(command, SIGNAL(commandComplite(int)), this, SLOT(go(int)));
            connect(command, SIGNAL(showLogMessage(QString)), this, SLOT(onShowLogMessages(QString)));
        }
    }
    num++;
    if(num > -1 && num < size()){
        ITCPCommand *command = this->at(num);
        command->send();
    }
    if(num == size()){
        for(int i=0; i<size(); i++){
            ITCPCommand *command = this->at(i);
            command->setNum(i);
            disconnect(command, SIGNAL(commandComplite(int)), this, SLOT(go(int)));
            disconnect(command, SIGNAL(showLogMessage(QString)), this, SLOT(onShowLogMessages(QString)));
        }
        emit commandSetComplite();
    }
}

QVector<ITCPCommand *> TCPCommandSet::findByName(EnumCommands name){
    QVector<ITCPCommand*> res;
    for(int i=0; i< size(); i++){
        ITCPCommand *command = at(i);
        if(command->getCode() == name){
            res.push_back(command);
        }
    }
    return res;
}

