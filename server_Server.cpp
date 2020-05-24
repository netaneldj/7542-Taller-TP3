#include "server_Server.h"
#include "server_TextFileInterpreter.h"
#include <vector>
#include <iostream>
#include "server_ClientManager.h"

Server::Server(char* port, char* fileName, Score &s) :
s(s), interpreter(this->p, fileName, numbers), manager(port, numbers, s) {
	this->manager.start();
}

Server::~Server() {}

void Server::run() {
    std::string input;
    while (input != "q") {
        std::cin >> input;
    }
    s.show();
}



