#include "server_ClientTalker.h"
#include "common_Socket.h"
#include "common_Protocol.h"
#include "common_Guesser.h"
#include "common_Resources.h"
#include "common_Socket.h"
#include <utility>
#include <string>

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
	while (this->isAlive()) {
		try {
			std::string request = receive();
			std::string response = g.processClientRequest(request,num,chance);
			send(response);
			if (response==WIN_MSG) s.addWinner();
			else if (response==LOSE_MSG) s.addLoser();
			if (response==LOSE_MSG or response==WIN_MSG)this->alive = false;
		} catch(SocketError &e) {
			continue;
		} catch(std::exception &e) {
			std::cerr << e.what() << std::endl;
			break;
		} catch (...) {
			std::cerr << "Unknown Error on ClientTalker Run" << std::endl;
			break;
		}
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
