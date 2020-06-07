#include "server_Server.h"
#include "server_TextFileInterpreter.h"
#include <vector>
#include <iostream>
#include <mutex>
#include "server_ClientManager.h"

Server::Server(char* port, char* fileName) :
s(m), interpreter(fileName, numbers), manager(port, numbers, s) {
	this->manager.start();
}

Server::~Server() {}

void Server::run() {
	try {
	    std::string input;
	    while (input != "q") {
	        std::cin >> input;
	    }
	    this->manager.stop();
	    s.show();
	} catch (...) {
		std::cerr << "Failed Server Run" << std::endl;
	}
}



