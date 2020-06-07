#include "server_ClientTalker.h"
#include "common_Socket.h"
#include "common_Protocol.h"
#include <utility>
#include <string>
#include "common_Guesser.h"
#include "common_Resources.h"

ClientTalker::ClientTalker(Socket socket, std::string &num, Score &s) : s(s) {
	this->skt = std::move(socket);
	this->num = num;
	this->chance = 1;
	this->alive = true;
}

ClientTalker::~ClientTalker() {
    this->skt.close();
    this->join();
}

void ClientTalker::run() {
	try {
	    while (this->isAlive()) {
	        std::string request = receive();
	        std::string response = g.processClientRequest(request,num,chance);
	        send(response);
	        if (response==WIN_MSG) s.addWinner();
	        else if (response==LOSE_MSG) s.addLoser();
	        if (response==LOSE_MSG or response==WIN_MSG)this->alive = false;
	    }
	} catch (...) {
		std::cerr << "Failed ClientTalker Run" << std::endl;
	}
}

std::string ClientTalker::receive() {
	return p.receive(this->skt);
}

void ClientTalker::send(std::string &response) {
    p.send(this->skt, response);
}

bool ClientTalker::isAlive() {
    return this->alive;
}
