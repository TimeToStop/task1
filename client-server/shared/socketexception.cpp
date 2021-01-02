#include "socketexception.h"

SocketException::SocketException(const std::string& msg):
    _msg(msg)
{
}

SocketException::SocketException(const SocketException &other):
    _msg(other._msg)
{
}

SocketException::SocketException(SocketException&& other):
    _msg(std::move(other._msg))
{
}

SocketException::~SocketException()
{
}

const char *SocketException::what() const noexcept
{
    return _msg.c_str();
}
