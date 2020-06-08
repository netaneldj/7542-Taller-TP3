#ifndef COMMON_COMMAND_H_
#define COMMON_COMMAND_H_

#include "common_Socket.h"
#include <bits/unique_ptr.h>
#include <string>
#include <memory>

class Command {
public:
	Command();

	virtual ~Command();

    static std::unique_ptr<Command> getCommand(std::string &message);

    static std::unique_ptr<Command> getCommand(Socket &skt, char type);

	//Envia el mensaje convertido a formato protocolo
	virtual void send(Socket &skt, std::string &message);

	//Devuelve el mensaje en formato string
	virtual std::string receive(Socket &skt);
};

#endif /* COMMON_COMMAND_H_ */
