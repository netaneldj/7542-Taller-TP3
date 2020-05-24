#ifndef SERVER_SERVER_H_
#define SERVER_SERVER_H_

#include "server_TextFileInterpreter.h"
#include "common_Socket.h"
#include "common_Protocol.h"
#include "common_Score.h"
#include <string>
#include <vector>
#include "server_ClientManager.h"

class Server {
public:
	Server(char* port, char* fileName, Score &s);

	~Server();

    void run();

    void showStatus();

private:
    std::vector<std::string> numbers;
    Score &s;
    Protocol p;
    TextFileInterpreter interpreter;
    ClientManager manager;
};

#endif /* SERVER_SERVER_H_ */
