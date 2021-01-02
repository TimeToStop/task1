#include <iostream>

#include "clientsocket.h"

int main()
{
    try
    {
        std::string str;
        ClientSocket s;
        s.connect(3000);

        std::cout << "Client connected to server on port 3000:" << std::endl;
        while(str != "exit")
        {
            std::cin >> str;
            s.send(str);
        }

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

