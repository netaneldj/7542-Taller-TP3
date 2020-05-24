#include "common_Command.h"

Command::Command() {}

Command::~Command() {}

void Command::send(Socket &skt, std::string message) {

}

std::string Command::receive(char* response, size_t length) {
	return "";
}

