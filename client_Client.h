#ifndef CLIENT_CLIENT_H_
#define CLIENT_CLIENT_H_

#include <string>
#include "common_Socket.h"
#include "common_Thread.h"
#include "common_Protocol.h"

class Client : public Thread {
public:
	Client(char* host, char* port);

	~Client() override;

	void run() override;

private:
    Socket skt;

    Protocol p;

    void send(std::string msg);

    std::string receive();
};

#endif /* CLIENT_CLIENT_H_ */
