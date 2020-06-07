#ifndef SERVER_SERVER_H_
#define SERVER_SERVER_H_

#include "server_Score.h"
#include "server_TextFileInterpreter.h"
#include "common_Socket.h"
#include "common_Protocol.h"
#include <string>
#include <vector>
#include <mutex>
#include "server_ClientManager.h"

class Server {
public:
	Server(char* port, char* fileName);

	~Server();

    void run();

    void showStatus();

private:
    std::vector<std::string> numbers;
    std::mutex m;
    Score s;
    TextFileInterpreter interpreter;
    ClientManager manager;
};

#endif /* SERVER_SERVER_H_ */
