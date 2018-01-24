#ifndef TCPGETSTATECOMMAND_H
#define TCPGETSTATECOMMAND_H

#include <QObject>
#include "tcpcommandset.h"

class TCPGetStateCommand : public TCPCommandSet
{
public:
    TCPGetStateCommand(ServerConnect *_server);
    int8_t getState();
    int8_t getError();
};

#endif // TCPGETSTATECOMMAND_H
