#include "client_Client.h"
#include <iostream>

#define ARGS_HOST 1
#define ARGS_PORT 2

int main(int argc, char *argv[]) {
	try {
		if (argc != 3) {
			std::cout << "Uso: ./client <host> <puerto>\n";
			return 0;
		}

		char *host = argv[ARGS_HOST];
		char *port = argv[ARGS_PORT];

		Client client(host, port);
		client.run();
	} catch (...) {
		std::cerr << "Failen Client main" << std::endl;
	}
	return 0;
}

