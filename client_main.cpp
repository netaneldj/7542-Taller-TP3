#include "client_Client.h"
#include <iostream>

#define ARGS_HOST 1
#define ARGS_PORT 2

int main(int argc, char *argv[]) {
	if (argc != 3) {
        std::cout << "Uso: ./client <host> <puerto>\n";
        return 1;
    }
    char *host = argv[ARGS_HOST];
    char *port = argv[ARGS_PORT];
    Client client(host, port);
    client.run();
    return 0;
}

