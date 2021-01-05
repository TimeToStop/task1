#ifndef SERVERSOCKET_H
#define SERVERSOCKET_H

#include "../shared/socketexception.h"

#include <string>

class ServerSocket
{
public:
    ServerSocket(int buffer_size);
    ~ServerSocket();

    void init(int port);
    int accept();
    std::string read(int socket);
    void close();

private:
    int _listener;
    const int _buffer_size;
    char* _data;
};

#endif // SERVERSOCKET_H
