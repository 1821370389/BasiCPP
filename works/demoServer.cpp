#include<iostream>
#include "myNet.hpp"
#include <unistd.h>

int main()
{
#if 0
    // TCP
    TcpServer server;
    server.Start(8888,20);
    
    int fd = server.Accept();
    std::cout << "fd = " << fd << std::endl;
    std::string data = server.Recv(fd);
    std::cout << "data = " << data << std::endl;
    server.Send(fd, data);
    server.Close(fd);
#else
    UdpServer server;
    server.Start(8888);
    std::cout << "server start" << std::endl;

    struct sockaddr_in client;
    socklen_t len = sizeof(client);
    std::string data = server.RecvFrom(&client, &len);
    std::cout << "data = " << data << std::endl;
    server.SendTo(data, client);

#endif 
    return 0;
}