#ifndef COMMON_COMMANDHELP_H_
#define COMMON_COMMANDHELP_H_

#include "common_Command.h"
#include <string>

class CommandHelp : public Command{
public:
	CommandHelp();

	~CommandHelp();

	//Envia el mensaje convertido a formato protocolo
	void send(Socket &skt, std::string message) override;

	//Devuelve el mensaje en formato string
	std::string receive(char* response, size_t length) override;
};

#endif /* COMMON_COMMANDHELP_H_ */
