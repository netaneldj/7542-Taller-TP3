#ifndef COMMON_COMMAND_H_
#define COMMON_COMMAND_H_

#include "common_Socket.h"
#include <string>

class Command {
public:
	Command();

	virtual ~Command();

	//Envia el mensaje convertido a formato protocolo
	virtual void send(Socket &skt, std::string message);

	//Devuelve el mensaje en formato string
	virtual std::string receive(char* response, size_t length);
};

#endif /* COMMON_COMMAND_H_ */
