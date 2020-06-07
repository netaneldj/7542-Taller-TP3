#ifndef SERVER_CLIENTMANAGER_H_
#define SERVER_CLIENTMANAGER_H_

#include "server_Score.h"
#include "common_Thread.h"
#include "common_Socket.h"
#include "server_ClientTalker.h"
#include <vector>
#include <string>
#include <list>

class ClientManager : public Thread {
public:
	ClientManager(char* port, std::vector<std::string> &numbers, Score &s);

	~ClientManager() override;

    void run() override;

    bool isAlive();

    void stop();

private:
    Socket skt_s;
    Score &s;
    int index;
    bool alive;
    std::vector<std::string> numbers;
    std::list<ClientTalker*> clients;

    void deleteOldClients();
};

#endif /* SERVER_CLIENTMANAGER_H_ */
