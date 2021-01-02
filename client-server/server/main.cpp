#include <iostream>

#include "serversocket.h"

int main()
{
    try
    {
        std::string str;
        ServerSocket s(1000);
        s.init(3000);
        int client = s.accept();

        while(str != "exit")
        {
            str = s.read(client);

            if (str.size() >= 2 && str.size() % 32 == 0)
            {
                std::cout << "Correct data accepted:\n" << str << std::endl;
            }
            else
            {
                std::cout << "Error:\nIncorrect data:\n" << str << std::endl;
            }
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
