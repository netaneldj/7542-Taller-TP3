#ifndef SERVER_TEXTFILEINTERPRETER_H_
#define SERVER_TEXTFILEINTERPRETER_H_

#include <string>
#include <vector>
#include "common_Guesser.h"

class TextFileInterpreter {
public:
	TextFileInterpreter(std::string fileName, std::vector<std::string> &list);

	~TextFileInterpreter();

private:
	void process(std::string fileName, std::vector<std::string> &list);
	Guesser g;
};

#endif /* SERVER_TEXTFILEINTERPRETER_H_ */
