#include "server_Server.h"
#include "server_TextFileInterpreter.h"
#include "server_ClientManager.h"
#include <vector>
#include <iostream>
#include <mutex>


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
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	} catch (...) {
		std::cerr << "Unknown Error on Server Run" << std::endl;
	}
}



