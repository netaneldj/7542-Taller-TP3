#include "common_Command.h"
#include "common_CommandHelp.h"
#include "common_CommandNumber.h"
#include "common_CommandString.h"
#include "common_CommandSurrender.h"
#include "common_Resources.h"
#include <memory>

Command::Command() {}

Command::~Command() {}

std::unique_ptr<Command>
Command::getCommand(std::string &message) {
    if (message == HELP)
        return std::unique_ptr<Command>(new CommandHelp());
    else if (message == SOURRENDER)
        return std::unique_ptr<Command>(new CommandSurrender());
    else if (isNumber(message))
        return std::unique_ptr<Command>(new CommandNumber());
    return std::unique_ptr<Command>(new CommandString());
}

std::unique_ptr<Command>
Command::getCommand(Socket &skt, char type) {
	if (type=='T') return std::unique_ptr<Command>(new CommandString());

	char header[1] = "";
	skt.recv(header,1);

	if (header[0]=='h')
		return std::unique_ptr<Command>(new CommandHelp());
	else if (header[0]=='s')
		return std::unique_ptr<Command>(new CommandSurrender());
	else if (header[0]=='n')
		return std::unique_ptr<Command>(new CommandNumber());
	return NULL;
}

void Command::send(Socket &skt, std::string &message) {}

std::string Command::receive(Socket &skt) {
	return "";
}

