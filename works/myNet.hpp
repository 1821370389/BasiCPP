#ifndef __MY_NET_HPP__
#define __MY_NET_HPP__

#include <string>
#include <unistd.h>
#include <netinet/in.h>


/* TCP服务器 */
class TcpServer
{
public:

    TcpServer();
    ~TcpServer();


    /* 启动服务器,开始监听指定端口 */
    bool Start(int port, int maxLisentNum);

    /* 等待客户端连接 */
    int Accept();

    /* 接收数据 */
    std::string Recv(int sockfd);

    /* 发送数据 */
    bool Send(int sockfd, const std::string& data);

    /* 关闭连接 */
    bool Close(int sockfd);

private:
    int sockfd;
};

/* TCP客户端 */
class TcpClient
{
public:
    TcpClient();
    ~TcpClient();

    /* 连接指定服务器和端口 */
    bool Connect(const std::string& ip, int port);

    /* 接收数据 */
    std::string Recv();

    /* 发送数据 */
    bool Send(const std::string& data);


private:
    int sockfd;
};

/* UDP服务器 */
class UdpServer
{
public:
    UdpServer();
    ~UdpServer();

    /* 启动服务器,开始监听指定端口 */
    bool Start(int port);

    /* 接收数据 */
    std::string RecvFrom(struct sockaddr_in* client_addr = NULL, socklen_t* len = NULL);

    /* 发送数据给指定客户端 */
    bool SendTo(const std::string& data, const struct sockaddr_in& client_addr);

private:
    int sockfd;
};

/* UDP客户端 */
class UdpClient
{
public:
    UdpClient();
    ~UdpClient();

    /* 设置服务器信息 */
    bool Start(const std::string& ip, int port);

    /* 接收数据 */
    std::string RecvFrom();

    /* 发送数据给指定客户端 */
    bool SendTo(const std::string& data);


private:
    int sockfd;
    struct sockaddr_in* server_addr;
    socklen_t* len;
};

#endif