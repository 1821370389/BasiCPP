#include<iostream>
#include "myNet.hpp"
#include <unistd.h>


int main()
{
#if 0
    TcpClient client;
    client.Connect("172.16.157.12",8888);
    client.Send("Hello World!");
    std::cout << client.Recv() << std::endl;
    sleep(5); 
#else
    UdpClient client;
    std::cout << "udp client" << std::endl;
    client.Start("172.16.157.12", 8888);
    client.SendTo("Hello World!");
    std::cout << client.RecvFrom() << std::endl;
    sleep(3);

#endif
    return 0;
}