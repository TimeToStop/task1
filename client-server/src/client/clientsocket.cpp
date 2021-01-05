#include "clientsocket.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

ClientSocket::ClientSocket():
    _socket(-1)
{   
}

ClientSocket::~ClientSocket()
{
    close();
}

void ClientSocket::connect(int port)
{
    sockaddr_in addr;

    _socket = ::socket(AF_INET, SOCK_STREAM, 0);
    if(_socket < 0)
    {
        throw SocketException("Cannot create socket");
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    if(::connect(_socket, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        throw SocketException("Cannot connect socket");
    }
}

void ClientSocket::send(const std::string& data)
{
     ::send(_socket, data.c_str(), data.size() + 1, 0);
}

void ClientSocket::close()
{
    ::close(_socket);
}
