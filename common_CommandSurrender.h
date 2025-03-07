#ifndef COMMON_COMMANDSURRENDER_H_
#define COMMON_COMMANDSURRENDER_H_

#include "common_Command.h"
#include "common_Socket.h"
#include <string>

class CommandSurrender : public Command {
public:
	CommandSurrender();

	~CommandSurrender();

	//Envia el mensaje convertido a formato protocolo
	void send(Socket &skt, std::string &message) override;

	//Devuelve el mensaje en formato string
	std::string receive(Socket &skt) override;
};

#endif /* COMMON_COMMANDSURRENDER_H_ */
