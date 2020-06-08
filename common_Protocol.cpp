#include "common_Protocol.h"
#include "common_Socket.h"
#include "common_Command.h"
#include <bits/unique_ptr.h>
#include <iostream>
#include <memory>

Protocol::Protocol() {}

Protocol::~Protocol() {}

void Protocol::send(Socket &skt, std::string message) {
    std::unique_ptr<Command> command = Command::getCommand(message);
    command->send(skt,message);
}

std::string Protocol::receive(Socket& skt, char type) {
	std::unique_ptr<Command> command = Command::getCommand(skt,type);
	std::string response = command->receive(skt);
	return response;
}
