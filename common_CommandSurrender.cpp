#include "common_CommandSurrender.h"
#include "common_Socket.h"
#include <string>

CommandSurrender::CommandSurrender() {}

CommandSurrender::~CommandSurrender() {}

void CommandSurrender::send(Socket &skt, std::string &message) {
	char msg = 's';

	skt(&msg,sizeof(msg));
}

std::string CommandSurrender::receive(Socket &skt) {
	return "RENDIRSE";
}

