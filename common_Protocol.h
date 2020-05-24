#ifndef COMMON_PROTOCOL_H_
#define COMMON_PROTOCOL_H_

#include "common_Score.h"
#include "common_Socket.h"
#include "common_CommandHelp.h"
#include "common_CommandNumber.h"
#include "common_CommandString.h"
#include "common_CommandSurrender.h"
#include <string>

class Protocol {
public:
	Protocol();

	~Protocol();

    bool validClientInput(std::string input);

    bool validServerInput(std::string input);

    void send(Socket &skt, std::string message);

    std::string receive(Socket& skt);

    std::string processClientRequest(std::string input,
    		std::string num, int &chance, Score &score);

    std::string analyzeCoincidences(std::string input,
    		std::string num, Score &score);

private:
    CommandHelp help;
    CommandNumber number;
    CommandString string;
    CommandSurrender surrender;
    bool repeat(std::string value);
    bool inRange(std::string value);
    bool isNumber(const std::string &s);
    bool sizeArgs(std::string &str);
};

#endif /* COMMON_PROTOCOL_H_ */
