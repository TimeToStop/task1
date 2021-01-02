#include <iostream>
#include <atomic>
#include <condition_variable>
#include <pthread.h>
#include <thread>
#include <unistd.h>

#include <list>

std::mutex m;
std::condition_variable cv;
bool is_exit = false;
bool has_data_to_process = false;
std::list<std::string> data;

void proccess()
{
    std::cout << "Sub proccess started " << std::endl;
    while(true)
    {
        std::unique_lock<std::mutex> lk(m);
        cv.wait(lk, []() {return has_data_to_process || is_exit;});

        if (is_exit)
        {
            break;
        }
        else
        {
            has_data_to_process = false;

            for(const std::string& message : data)
            {
                sleep(2);
                std::cout << "Message = " << message << std::endl;
            }

            data.clear();
        }
    }

    std::cout << "Sub proccess end" << std::endl;
}

void readMessage()
{
    std::cout << "Read messages" << std::endl;
    std::string buffer;
    is_exit = false;

    while(buffer != "exit")
    {
        std::cin >> buffer;

        {
            std::lock_guard<std::mutex> lk(m);
            has_data_to_process = true;
            data.push_back(buffer);
        }

        cv.notify_one();
    }

    is_exit = true;
    std::cout << "Read messages end" << std::endl;
}

//int main()
//{
//    std::cout << "Create thread detached" << std::endl;

//    std::thread t(proccess);
//    t.detach();

//    std::cout << "Program started: " << std::endl;
//    readMessage();
//    std::cout << "Program has end" << std::endl;
//    return 0;
//}
