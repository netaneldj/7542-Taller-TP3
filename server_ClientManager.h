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

private:
    Socket skt_s;
    Score &s;
    int index;
    std::vector<std::string> numbers;
    std::list<ClientTalker*> clients;

    void deleteOldClients();
};

#endif /* SERVER_CLIENTMANAGER_H_ */
