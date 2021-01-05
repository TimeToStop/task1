#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H

#include "../shared/socketexception.h"

#include <string>

class ClientSocket
{
public:
    ClientSocket();
    ~ClientSocket();

    void connect(int port);
    void send(const std::string&);
    void close();

private:
    int _socket;
};

#endif // CLIENTSOCKET_H
