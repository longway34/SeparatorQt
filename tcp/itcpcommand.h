#ifndef ITCPCOMMAND_H
#define ITCPCOMMAND_H

#include <QObject>
#include <QTcpSocket>
#include <QTimer>
#include <QMutex>

typedef enum:uint8_t{
            getstate    = 0x0A,
            testim      = 0x0B,
            initada     = 0x0C,
            getver      = 0x0D,
            stoptest    = 0x0F,
            setspk      = 0x10,
            getspk      = 0x11,
            setsepar    = 0x20,
            getsepar    = 0x21,
            startsep    = 0x22,
            stopset     = 0x23,
            getkspk     = 0x24,
            getgist     = 0x25,
            startpuw    = 0x27,
            setpuw      = 0x28,
            stoppuw     = 0x29,
            setudeu     = 0x30,
            setren      = 0x31,
            getren      = 0x32,
            onren       = 0x33,
            offren      = 0x34,
            setrgu      = 0x35,
            settemp     = 0x37,
            gettemp     = 0x38,
            expon       = 0x40,
            expoff      = 0x41,
            onsep       = 0x50,
            offsep      = 0x51,
            oniw        = 0x52,
            offiw       = 0x53,
            onosw       = 0x54,
            offosw      = 0x55,
            setrgu2     = 0x56,
            getrgu2     = 0x57,
            setim       = 0x58,
            setptdeu    = 0x63,
            setm50      = 0x65,
            getm50      = 0x66,
            getblk      = 0x67,
            setlog      = 0x68,

            timeout     = 0xFE,
            nocommand   = 0xFF
}EnumCommands;


class ServerConnect: public QTcpSocket{
    QString name;
    uint    port;
    QMutex  mutex;
public:
    ServerConnect(): QTcpSocket(), name("127.0.0.1"), port(3425){}
    ServerConnect(QString _name, uint _port): QTcpSocket(){
        name = _name; port = _port;
    }
    QTcpSocket *getSocket(){return this;}
    QString getName(){return name;}
    uint getPort(){return port;}
    bool _connect(){
        bool res = false;
        mutex.lock();
        connectToHost(name, port, QIODevice::ReadWrite);
        mutex.unlock();
        res = this->state() == QAbstractSocket::SocketState::ConnectedState;
        return res;
    }
    QMutex *getMutex(){ return &mutex;}
};

class ITCPCommand: public QObject
{
    Q_OBJECT

protected:
    ServerConnect *server;
    EnumCommands code;
    QTimer timer;
    int timeOut;
    int num;
protected slots:
    virtual void onTimeOut()=0;
    virtual void onReadyRead()=0;
public:
    ITCPCommand(): server(), code(nocommand){}
    ITCPCommand(ServerConnect *_server, EnumCommands _code): server(_server), code(_code){
    }

    inline char *bCode(){return (char*)(&code);}

    virtual void send() = 0;

    ServerConnect *getServer() const
    {
        return server;
    }
    void setServer(ServerConnect *value)
    {
        server = value;
    }

    EnumCommands getCode() const
    {
        return code;
    }

    int getNum() const
    {
        return num;
    }
    void setNum(int value)
    {
        num = value;
    }

    int getTimeOut() const
    {
        return timeOut;
    }
    void setTimeOut(int value)
    {
        timeOut = value;
    }

signals:
    void commandComplite(int);
    void commandErrorWrite(int, EnumCommands);
    void commandErrorRead(int, EnumCommands);
    void commandErrorConnect(int, EnumCommands);
    void showLogMessage(QString);

};

#endif // ITCPCOMMAND_H
