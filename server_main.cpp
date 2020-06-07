#include "server_Server.h"
#include <iostream>

#define ARGS_PORT 1
#define ARGS_NUMS 2

int main(int argc, char *argv[]) {
    if (argc != 3) {
    	std::cout <<"Uso: ./server <puerto> <números>\n";
    	return 1;
    }
    char* port = argv[ARGS_PORT];
    char* numsFileName = argv[ARGS_NUMS];
    try {
        Server server(port, numsFileName);
        server.run();
        return 0;
    } catch(...) {
    	return 1;
    }
}
