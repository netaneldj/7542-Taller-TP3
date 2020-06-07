#ifndef SERVER_CLIENTTALKER_H_
#define SERVER_CLIENTTALKER_H_

#include "server_Score.h"
#include "common_Thread.h"
#include "common_Protocol.h"
#include <string>
#include "common_Guesser.h"

class ClientTalker : public Thread {
public:
	ClientTalker(Socket socket, std::string &num, Score &s);

	~ClientTalker();

	void run() override;

	bool isAlive();

private:
	 Socket skt;
	 Protocol p;
	 Score &s;
	 Guesser g;
	 std::string num;
	 bool alive;
	 int chance;

	 std::string receive();

	 void send(std::string &response);
};

#endif /* SERVER_CLIENTTALKER_H_ */
