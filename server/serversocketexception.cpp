#include "serversocketexception.h"

ServerSocketException::ServerSocketException(const std::string& msg):
    _msg(msg)
{
}

ServerSocketException::ServerSocketException(const ServerSocketException &other):
    _msg(other._msg)
{
}

ServerSocketException::ServerSocketException(ServerSocketException&& other):
    _msg(std::move(other._msg))
{
}

ServerSocketException::~ServerSocketException()
{
}

const char *ServerSocketException::what() const noexcept
{
    return _msg.c_str();
}
