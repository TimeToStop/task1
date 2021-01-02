#ifndef SERVERSOCKETEXCEPTION_H
#define SERVERSOCKETEXCEPTION_H

#include <stdexcept>

class ServerSocketException : public std::exception
{
public:
    ServerSocketException(const std::string& msg);
    ServerSocketException(const ServerSocketException& other);
    ServerSocketException(ServerSocketException&& other);
    virtual ~ServerSocketException();

    virtual const char* what() const noexcept override final;

private:
    std::string _msg;
};

#endif // SERVERSOCKETEXCEPTION_H
