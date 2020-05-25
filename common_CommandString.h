#ifndef COMMON_COMMANDSTRING_H_
#define COMMON_COMMANDSTRING_H_

#include "common_Command.h"
#include <string>

class CommandString : public Command {
public:
	CommandString();

	~CommandString();

	//Envia el mensaje convertido a formato protocolo
	void send(Socket &skt, std::string message) override;

	//Devuelve el mensaje en formato string
	std::string receive(char* response, size_t length) override;
};

#endif /* COMMON_COMMANDSTRING_H_ */
