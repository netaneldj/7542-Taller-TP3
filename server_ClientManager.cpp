#include "server_ClientManager.h"
#include "server_ClientTalker.h"
#include "common_Socket.h"
#include <utility>
#include <vector>
#include <string>

ClientManager::ClientManager(char* port,
		std::vector<std::string> &numbers, Score &s) : s(s), numbers(numbers) {
    Socket serverSocket;
    serverSocket.bind(port);
    this->skt_s = std::move(serverSocket);
    this->skt_s.listen();
    this->index = 0;
}

ClientManager::~ClientManager() {
    for (ClientTalker *c : clients) {
        delete c;
    }
    this->skt_s.close();
    this->join();
}

void ClientManager::run() {
    while (true) {
        Socket clientSkt;
        try {
            clientSkt = this->skt_s.accept();
        }
        catch (...) {
            break;
        }
        ClientTalker *client = new ClientTalker(
        		std::move(clientSkt),numbers[(index%numbers.size())],s);
        client->start();
        clients.push_back(client);
        garbageCollector();
        index++;
    }
}

void ClientManager::garbageCollector() {
    std::list<ClientTalker *>::iterator it = clients.begin();
    while (it != clients.end()) {
        if (!(*it)->isAlive()) {
            delete *it;
            it = clients.erase(it);
        } else {
            it++;
        }
    }
}

