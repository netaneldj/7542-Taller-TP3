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
    this->alive = true;
}

ClientManager::~ClientManager() {
    for (ClientTalker *c : clients) {
        delete c;
    }
    this->skt_s.close();
    this->join();
}

void ClientManager::run() {
	while (this->isAlive()) {
	    try {
			Socket clientSkt;
			clientSkt = this->skt_s.accept();
			ClientTalker *client = new ClientTalker(
					std::move(clientSkt),numbers[(index%numbers.size())],s);
			client->start();
			clients.push_back(client);
			deleteOldClients();
			index++;
	    }
	    catch (SocketError &e) {
	        continue;
	    }
	    catch (std::exception &e) {
	        std::cerr << e.what() << std::endl;
	        break;
	    }
	    catch (...) {
	        std::cerr << "Unknown Error on ClientManager Run" << std::endl;
	        break;
	    }
	}
}

void ClientManager::deleteOldClients() {
    std::list<ClientTalker *>::iterator iterator = clients.begin();
    while (iterator != clients.end()) {
        if (!(*iterator)->isAlive()) {
            delete *iterator;
            iterator = clients.erase(iterator);
        } else {
        	iterator++;
        }
    }
}

bool ClientManager::isAlive() {
    return this->alive;
}

void ClientManager::stop() {
    this->alive = false;
}

