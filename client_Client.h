#ifndef CLIENT_CLIENT_H_
#define CLIENT_CLIENT_H_

#include <string>
#include "common_Socket.h"
#include "common_Protocol.h"
#include "common_Guesser.h"

class Client {
public:
	Client(char* host, char* port);

	~Client();

	void run();

private:
    Socket skt;

    Protocol p;

    Guesser g;

    void send(std::string &msg);

    std::string receive();
};

#endif /* CLIENT_CLIENT_H_ */
