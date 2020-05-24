#include "server_ClientTalker.h"
#include "common_Socket.h"
#include "common_Protocol.h"
#include <string>

#define HELP_MSG "Comandos válidos:\n\tAYUDA: despliega la lista de comandos válidos\n\tRENDIRSE: pierde el juego automáticamente\n\tXXX: Número de tres cifras a ser enviado al servidor para adivinar el número secreto"
#define LOSE_MSG "Perdiste"
#define WIN_MSG "Ganaste"
#define INVALID_MSG "Número inválido. Debe ser de 3 cifras no repetidas"

ClientTalker::ClientTalker(Socket socket, std::string num, Score &s) : s(s) {
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
    while (this->alive) {
        std::string request = receive();
        std::string response = p.processClientRequest(request,num,chance,s);
        send(response);
        if (response==LOSE_MSG or response==WIN_MSG)this->alive = false;
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
