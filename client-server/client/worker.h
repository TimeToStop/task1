#ifndef WORKER_H
#define WORKER_H

#include <atomic>
#include <condition_variable>
#include <pthread.h>
#include <thread>
#include <unistd.h>

#include <list>

#include <string>

class Worker
{
public:
    Worker();
    ~Worker();

    void startDetached();
    void addMessage(const std::string&);
    void exit();

    void process();

private:
    std::mutex _m;
    std::condition_variable _cv;
    bool _is_exit;
    bool _has_data_to_process;
    std::list<std::string> _data;
};

#endif // WORKER_H
