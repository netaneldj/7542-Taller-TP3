#include "client_Client.h"
#include "common_Guesser.h"
#include "common_Resources.h"
#include "common_Socket.h"
#include <iostream>
#include <fstream>

Client::Client(char* host, char* port) {
	this->skt.connect(host, port);
}

Client::~Client() {
    this->skt.close();
}

void Client::run() {
	std::string input;
	std::string response;

	while (std::getline(std::cin, input)) {
	    try {
			if (g.validClientInput(input)) {
				this->send(input);
				response = this->receive();
				std::cout << response << "\n";
				if (response==WIN_MSG or response==LOSE_MSG) break;
			}
	    } catch (SocketError &e) {
	    	continue;
	    } catch (std::exception &e) {
	    	std::cerr << e.what() << std::endl;
	    	break;
	    } catch (...) {
	    	std::cerr << "Unknown Error on Client Run" << std::endl;
	    	break;
	    }
	}
}

void Client::send(std::string &msg) {
    p.send(this->skt, msg);
}

std::string Client::receive() {
    return p.receive(this->skt,'T');
}



