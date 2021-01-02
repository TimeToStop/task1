#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#include <cstring>

int main()
{
    char buffer[1000];

    int sock;
    sockaddr_in addr;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0)
    {
        std::cout << "Cannot create socket" << std::endl;
        exit(1);
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(3425);
    addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    if(connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
       std::cout << "Cannot connect socket" << std::endl;
        exit(2);
    }

    while(strcmp(buffer, "exit") != 0)
    {
        scanf("%s", buffer);
        send(sock, buffer, strlen(buffer), 0);
    }

    close(sock);
    return 0;
}

