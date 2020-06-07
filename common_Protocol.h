#ifndef COMMON_PROTOCOL_H_
#define COMMON_PROTOCOL_H_

#include "common_Socket.h"
#include <string>

class Protocol {
public:
	Protocol();

	~Protocol();

    void send(Socket &skt, std::string message);

    std::string receive(Socket& skt, char type = 'C');
};

#endif /* COMMON_PROTOCOL_H_ */
