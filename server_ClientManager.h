#ifndef SERVER_CLIENTMANAGER_H_
#define SERVER_CLIENTMANAGER_H_

#include "common_Thread.h"
#include "common_Socket.h"
#include "common_Score.h"
#include "server_ClientTalker.h"
#include <list>

class ClientManager : public Thread {
public:
	ClientManager(char* port, std::vector<std::string> &numbers, Score &s);

	~ClientManager() override;

    void run() override;

private:
    Socket skt_s;
    Score &s;
    int index;
    std::vector<std::string> numbers;
    std::list<ClientTalker*> clients;

    void garbageCollector();
};

#endif /* SERVER_CLIENTMANAGER_H_ */
