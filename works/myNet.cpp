#include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>
#include "myNet.hpp"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


/* TCP服务器 */
TcpServer::TcpServer()
{
    this->sockfd = -1;
}
TcpServer::~TcpServer()
{
    close(this->sockfd);
}
bool TcpServer::Start(int port, int maxLisentNum)
{
    /* 创建套接字 */
    this->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(this->sockfd < 0)
    {
        perror("socket error");
        return false;
    }

    /* 初始化地址信息 */
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    int ret = bind(this->sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if (ret == -1)
    {
        perror("bind error");
        return false;
    }

    ret = listen(this->sockfd, maxLisentNum);
    if (ret == -1)
    {
        perror("listen error");
        return false;
    }
}

/* 等待客户端连接 */
int TcpServer::Accept()
{
    struct sockaddr_in client_addr;
    socklen_t len = sizeof(client_addr);
    int newfd = accept(this->sockfd, (struct sockaddr*)&client_addr, &len);
    if (newfd < 0)
    {
        perror("accept error");
        return -1;
    }
    return newfd;
}

/* 接收数据 */
std::string TcpServer::Recv(int sockfd)
{
    /* 接收数据长度 */
    size_t dataLen;
    int ret = recv(sockfd, &dataLen, sizeof(dataLen), 0);
    if (ret < 0)
    {
        perror("recv error");
        return "";
    }
    else if (ret == 0)
    {
        std::cout << "client closed" << std::endl;
        return "";
    }
    
    /* 接收数据 */
    char *buf = new char[dataLen + 1];
    memset(buf, 0, dataLen + 1);
    ret = recv(sockfd, buf, dataLen, 0);
    if (ret < 0)
    {
        perror("recv error");
        return "";
    }
    else if (ret == 0)
    {
        std::cout << "client closed" << std::endl;
        return "";
    }
    std::string data(buf, dataLen);
    delete[] buf;
    return data;
}

/* 发送数据 */
bool TcpServer::Send(int sockfd, const std::string& data)
{
    /* 获取数据长度 */
    size_t dataLen = data.size();

    /* 发送数据长度 */
    int ret = send(sockfd, &dataLen, sizeof(dataLen), 0);
    if (ret < 0)
    {
        perror("send error");
        return false;
    }

    /* 发送数据 */
    ret = send(sockfd, data.c_str(), dataLen, 0);
    if (ret < 0)
    {
        perror("send error");
        return false;
    }
    return true;
}

/* TCP客户端 */
TcpClient::TcpClient()
{
    this->sockfd = -1;
}
TcpClient::~TcpClient()
{
    close(this->sockfd);
}

/* 连接指定服务器和端口 */
bool TcpClient::Connect(const std::string& ip, int port)
{
    /* 创建套接字 */
    this->sockfd = socket(AF_INET, SOCK_STREAM,0);
    if (this->sockfd < 0)
    {
        perror("socket error");
        return false;
    }

    /* 初始化地址信息 */
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(ip.c_str());

    /* 连接服务器 */
    int ret = connect(this->sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if (ret < 0)
    {
        perror("connect error");
        return false;
    }
    return true;
}

/* 接收数据 */
std::string TcpClient::Recv()
{
    /* 接收数据长度 */
    size_t dataLen;
    int ret = recv(this->sockfd, &dataLen, sizeof(dataLen), 0);
    if (ret < 0)
    {
        perror("recv error");
        return "";
    }
    else if (ret == 0)
    {
        std::cout << "server closed" << std::endl;
        return "";
    }

    /* 接收数据 */
    char *buf = new char[dataLen + 1];
    memset(buf, 0, dataLen + 1);
    ret = recv(this->sockfd, buf, dataLen, 0);
    if (ret < 0)
    {
        perror("recv error");
        return "";
    }
    else if (ret == 0)
    {
        std::cout << "server closed" << std::endl;
        return "";
    }
    std::string data(buf, dataLen);
    delete[] buf;
    return data;
} 

/* 发送数据 */
bool TcpClient::Send(const std::string& data)
{
    /* 获取数据长度 */
    size_t dataLen = data.size();

    /* 发送数据长度 */
    int ret = send(this->sockfd, &dataLen, sizeof(dataLen), 0);
    if( ret < 0)
    {
        perror("send error");
        return false;
    }
    if (ret == 0)
    {
        std::cout << "server closed" << std::endl;
        return false;
    }

    /* 发送数据 */
    ret = send(this->sockfd, data.c_str(), dataLen, 0);
    if( ret < 0)
    {
        perror("send error");
        return false;
    }
    if (ret == 0)
    {
        std::cout << "server closed" << std::endl;
        return false;
    }
    return true;
}


/* UDP服务器 */
UdpServer::UdpServer()
{
    this->sockfd = -1;
}
UdpServer::~UdpServer()
{
    close(this->sockfd);
}

/* 启动服务器,开始监听指定端口 */
bool UdpServer::Start(int port)
{
    /* 创建套接字 */
    this->sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (this->sockfd < 0)
    {
        perror("socket error");
        return false;
    }

    /* 初始化地址信息 */
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    /* 绑定地址信息 */
    int ret = bind(this->sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if (ret < 0)
    {
        perror("bind error");
        return false;
    }
    return true;
}

/* 接收数据 */
std::string UdpServer::RecvFrom(struct sockaddr_in* client_addr = NULL, socklen_t* len = NULL)
{
    /* 接收数据长度 */
    size_t dataLen;
    if (client_addr == NULL || len == NULL)
    {
        client_addr = new struct sockaddr_in;
        len = new socklen_t;
        *len = sizeof(struct sockaddr_in);
    }
    
    int ret = recvfrom(this->sockfd, &dataLen, sizeof(dataLen), 0, (struct sockaddr*)client_addr, len);
    if (ret < 0)
    {
        perror("recvfrom error");
        return "";
    }
    else if (ret == 0)
    {
        std::cout << "client closed" << std::endl;
        return "";
    }

    /* 接收数据 */
    char *buf = new char[dataLen + 1];
    memset(buf, 0, dataLen + 1);
    ret = recvfrom(this->sockfd, buf, dataLen, 0, (struct sockaddr*)client_addr, len);
    if (ret < 0)
    {
        perror("recvfrom error");
        return "";
    }
    else if (ret == 0)
    {
        std::cout << "client closed" << std::endl;
        return "";
    }
    std::string data(buf, dataLen);
    delete[] buf;
    return data;
}

/* 发送数据 */
bool UdpServer::SendTo(const std::string& data, const struct sockaddr_in& client_addr)
{
    /* 获取数据长度 */
    size_t dataLen = data.size();

    /* 发送数据长度 */
    int ret = sendto(this->sockfd, &dataLen, sizeof(dataLen), 0, (struct sockaddr*)&client_addr, sizeof(client_addr));
    if (ret < 0)
    {
        perror("sendto error");
        return false;
    }
    if (ret == 0)
    {
        std::cout << "client closed" << std::endl;
        return false;
    }

    /* 发送数据 */
    ret = sendto(this->sockfd, data.c_str(), dataLen, 0, (struct sockaddr*)&client_addr, sizeof(client_addr));
    if (ret < 0)
    {
        perror("sendto error");
        return false;
    }
    if (ret == 0)
    {
        std::cout << "client closed" << std::endl;
        return false;
    }
    return true;
}


/* UDP客户端 */
UdpClient::UdpClient()
{
    this->sockfd = -1;
}
UdpClient::~UdpClient()
{
    close(this->sockfd);
}

/* 接收数据 */
std::string UdpServer::RecvFrom(struct sockaddr_in* client_addr = NULL, socklen_t* len = NULL)
{
    /* 接收数据长度 */
    size_t dataLen;
    if (client_addr == NULL || len == NULL)
    {
        client_addr = new struct sockaddr_in;
        len = new socklen_t;
        *len = sizeof(struct sockaddr_in);
    }
    
    int ret = recvfrom(this->sockfd, &dataLen, sizeof(dataLen), 0, (struct sockaddr*)client_addr, len);
    if (ret < 0)
    {
        perror("recvfrom error");
        return "";
    }
    else if (ret == 0)
    {
        std::cout << "client closed" << std::endl;
        return "";
    }

    /* 接收数据 */
    char *buf = new char[dataLen + 1];
    memset(buf, 0, dataLen + 1);
    ret = recvfrom(this->sockfd, buf, dataLen, 0, (struct sockaddr*)client_addr, len);
    if (ret < 0)
    {
        perror("recvfrom error");
        return "";
    }
    else if (ret == 0)
    {
        std::cout << "client closed" << std::endl;
        return "";
    }
    std::string data(buf, dataLen);
    delete[] buf;
    return data;
}

/* 发送数据 */
bool UdpServer::SendTo(const std::string& data, const struct sockaddr_in& client_addr)
{
    /* 获取数据长度 */
    size_t dataLen = data.size();

    /* 发送数据长度 */
    int ret = sendto(this->sockfd, &dataLen, sizeof(dataLen), 0, (struct sockaddr*)&client_addr, sizeof(client_addr));
    if (ret < 0)
    {
        perror("sendto error");
        return false;
    }
    if (ret == 0)
    {
        std::cout << "client closed" << std::endl;
        return false;
    }

    /* 发送数据 */
    ret = sendto(this->sockfd, data.c_str(), dataLen, 0, (struct sockaddr*)&client_addr, sizeof(client_addr));
    if (ret < 0)
    {
        perror("sendto error");
        return false;
    }
    if (ret == 0)
    {
        std::cout << "client closed" << std::endl;
        return false;
    }
    return true;
}