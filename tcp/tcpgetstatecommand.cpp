#include "tcpgetstatecommand.h"

TCPGetStateCommand::TCPGetStateCommand(ServerConnect *_server):
    TCPCommandSet()
{
    this->append(new TCPCommand(_server, getstate));
}

int8_t TCPGetStateCommand::getState()
{

}
