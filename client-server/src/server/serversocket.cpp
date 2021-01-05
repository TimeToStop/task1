#include "serversocket.h"

#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

ServerSocket::ServerSocket(int buffer_size):
    _listener(0),
    _buffer_size(buffer_size),
    _data(new char[buffer_size + 1])
{
}

ServerSocket::~ServerSocket()
{
    close();
    delete[] _data;
}

void ServerSocket::init(int port)
{
    sockaddr_in addr;
    _listener = ::socket(AF_INET, SOCK_STREAM, 0);

    if(_listener < 0)
    {
        throw SocketException("Failed to create a listener socket");
    }

    addr.sin_family = AF_INET;
    addr.sin_port = ::htons(port);
    addr.sin_addr.s_addr = ::htonl(INADDR_ANY);

    if(bind(_listener, (sockaddr *)&addr, sizeof(addr)) < 0)
    {
        throw SocketException("Failed to bind listener to address");
    }

    ::listen(_listener, 1);
}

int ServerSocket::accept()
{
    int socket = 0;

    socket = ::accept(_listener, NULL, NULL);
    if(socket < 0)
    {
        throw SocketException("Failed to accept socket connection");
    }

    return socket;
}

std::string ServerSocket::read(int socket)
{
    int bytes_read = ::recv(socket, _data, _buffer_size, 0);
    _data[bytes_read/sizeof(char)] = 0;
    return std::string(_data);
}

void ServerSocket::close()
{
    ::close(_listener);
}
