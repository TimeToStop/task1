#include <iostream>

#include "serversocket.h"
#include "serversocketexception.h"

int main()
{
    try
    {
        std::string str;
        ServerSocket s(1000);
        s.init(3000);

        while(str != "exit")
        {
            str = s.read();
        }

        s.close();
    }
    catch (ServerSocketException& e)
    {
        std::cerr << "Error: " << std::endl;
        std::cerr << e.what() << std::endl;
    }
}
