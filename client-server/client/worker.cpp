#include "worker.h"

Worker::Worker()
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

void Worker::addMessage(const std::string &)
{

}

void Worker::exit()
{

}
