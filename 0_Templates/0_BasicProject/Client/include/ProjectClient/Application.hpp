#pragma once

#ifdef _WIN32
#include <WinSock2.h>
#include <WS2tcpip.h>
#pragma comment(lib, "Ws2_32.lib")
typedef SOCKET NetSocket;
#elif !_WIN32
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <netinet/in.h>
#include <arpa/inet.h>
typedef int NetSocket;
#endif

#include <iostream>

class Application
{
public:
    Application() = default;
    ~Application() = default;
    void Run();
};



