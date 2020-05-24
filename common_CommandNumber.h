#ifndef COMMON_COMMANDNUMBER_H_
#define COMMON_COMMANDNUMBER_H_

#include "common_Command.h"

class CommandNumber : public Command{
public:
	CommandNumber();

	~CommandNumber();

	//Envia el mensaje convertido a formato protocolo
	void send(Socket &skt, std::string message) override;

	//Devuelve el mensaje en formato string
	std::string receive(char* response, size_t length) override;
};

#endif /* COMMON_COMMANDNUMBER_H_ */
