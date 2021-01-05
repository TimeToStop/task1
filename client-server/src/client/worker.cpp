#include "worker.h"

#include <iostream>
#include <string>

Worker::Worker(ClientSocket* socket):
    _socket(socket),
    _m(),
    _cv(),
    _is_exit(false),
    _has_data_to_process(false),
    _data()
{   
}

Worker::~Worker()
{
}

void Worker::startDetached()
{
    std::thread t(&Worker::process, this);
    t.detach();
}

void Worker::addMessage(const std::string& msg)
{
    _m.lock();
    _has_data_to_process = true;
    _data.push_back(msg);
    _m.unlock();
    _cv.notify_one();
}

void Worker::exit()
{
    _m.lock();
    _is_exit = true;
    _m.unlock();
    _cv.notify_one();
}

void Worker::process()
{
    while(true)
    {
        std::unique_lock<std::mutex> lk(_m);
        _cv.wait(lk);

        if (_is_exit)
        {
            break;
        }
        else
        {
            _has_data_to_process = false;

            for(const std::string& message : _data)
            {
                std::cout << "Message = " << message << std::endl;

                long summ = 0;

                for(char c : message)
                {
                    if ('0' <= c && c <= '9')
                    {
                        summ += (int)(c - '0');
                    }
                }

                _socket->send(std::to_string(summ));
            }

            _data.clear();
        }
    }
}
