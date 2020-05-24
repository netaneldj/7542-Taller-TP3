#include "server_Server.h"
#include "common_Score.h"
#include <iostream>
#include <mutex>

#define ARGS_PORT 1
#define ARGS_NUMS 2

int main(int argc, char *argv[]) {
    if (argc != 3) {
    	std::cout <<"Uso: ./server <puerto> <números>\n";
    	return 1;
    }
    char* port = argv[ARGS_PORT];
    char* numsFileName = argv[ARGS_NUMS];
    std::mutex m;
    try {
    	Score s(m);
        Server server(port, numsFileName, s);
        server.run();
        return 0;
    } catch(...) {
    	return 1;
    }
}
