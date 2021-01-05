#include <iostream>

#include <algorithm>

#include "clientsocket.h"
#include "worker.h"

bool validate(const std::string& str)
{
    if(str.size() <= 64)
    {
        for(char c : str)
        {
            if (c < '0' || c > '9')
            {
                std::cerr << "Error: input contains non digit character" << std::endl;
                return false;
            }
        }

        return true;
    }
    else
    {
        std::cerr << "Error: lenght of string is greater than 64" << std::endl;
        return false;
    }
}

int main()
{
    try
    {
        std::string str;
        ClientSocket s;
        Worker w(&s);
        w.startDetached();
        s.connect(3000);

        std::cout << "Client connected to server on port 3000:" << std::endl;

        while(true)
        {
            std::getline(std::cin, str);

            if (str == "") continue;
            if (str == "exit")
            {
                s.send(str);
                break;
            }

            if (validate(str))
            {
                std::string s;
                std::sort(str.begin(), str.end());

                for(char c : str)
                {
                    int val = c - '0';

                    if(val % 2 == 0)
                    {
                        s += "KB";
                    }
                    else
                    {
                        s += c;
                    }
                }

                w.addMessage(s);
            }
        }

        w.exit();
        s.close();
        return 0;
    }
    catch (SocketException& e)
    {
        std::cerr << "Error: " << std::endl;
        std::cerr << e.what() << std::endl;
        return -1;
    }
}

