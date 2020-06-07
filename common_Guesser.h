#ifndef COMMON_GUESSER_H_
#define COMMON_GUESSER_H_

#include <string>

class Guesser {
public:
	Guesser();

	~Guesser();

    bool validClientInput(std::string &input);

    bool validServerInput(std::string &input);

    std::string processClientRequest(std::string &input,
    		std::string &num, int &chance);

    std::string analyzeCoincidences(std::string &input,
    		std::string &num);


private:
    bool repeat(std::string &value);
    bool inRange(std::string &value);
    bool sizeArgs(std::string &str);
    bool sizeNum(std::string &value);
};

#endif /* COMMON_GUESSER_H_ */
