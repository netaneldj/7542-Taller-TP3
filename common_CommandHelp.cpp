#include "common_CommandHelp.h"
#include <iostream>
#include <string>

CommandHelp::CommandHelp() {}

CommandHelp::~CommandHelp() {}

void CommandHelp::send(Socket &skt, std::string message) {
	char msg = 'h';
	skt.send(&msg,sizeof(msg));
}

std::string CommandHelp::receive(char* response, size_t length) {
	return "AYUDA";
}

