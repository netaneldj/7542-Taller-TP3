#include "client_Client.h"
#include <iostream>
#include <fstream>

Client::Client(char* host, char* port) {
	this->skt.connect(host, port);
}

Client::~Client() {}

void Client::run() {
    std::string input;
    std::string response;

    while (std::getline(std::cin, input)) {
    	if (p.validClientInput(input)) {
        	this->send(input);
        	response = this->receive();
            std::cout << response << "\n";
            if (response=="Ganaste" or response=="Perdiste") break;
        }
    }
    this->skt.close();
}

void Client::send(std::string msg) {
    p.send(this->skt, msg);
}

std::string Client::receive() {
    return p.receive(this->skt);
}



