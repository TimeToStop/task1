#ifndef SOCKETEXCEPTION_H
#define SOCKETEXCEPTION_H

#include <stdexcept>

class SocketException : public std::exception
{
public:
    SocketException(const std::string& msg);
    SocketException(const SocketException& other);
    SocketException(SocketException&& other);
    virtual ~SocketException();

    virtual const char* what() const noexcept override final;

private:
    std::string _msg;
};

#endif // SOCKETEXCEPTION_HS
