#ifndef SERVERSOCKET_H
#define SERVERSOCKET_H

#include <string>

class ServerSocket
{
public:
    ServerSocket(int buffer_size);
    ~ServerSocket();

    void init(int port);
    std::string read();
    void close();

private:
    int _listener;
    const int _buffer_size;
    char* _data;
};

#endif // SERVERSOCKET_H
