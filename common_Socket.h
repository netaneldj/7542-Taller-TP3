#ifndef COMMON_SOCKET_H_
#define COMMON_SOCKET_H_

#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>

class Socket {

private:
    int s;
    int skt;
    struct addrinfo *addr;
    struct addrinfo *ptr;

public:
    Socket();

    Socket(int skt);

    ~Socket();

    bool connect(char *host, char *port);

    bool bind(char *port);

    bool listen();

    Socket accept();

    void close();

    int send(const char* msg, size_t length);

    int recv(char* response, size_t length);

    bool addrinfo(char *host, char* port);

    Socket(Socket &&other);

    Socket &operator=(Socket &&other);

};

#endif /* COMMON_SOCKET_H_ */
