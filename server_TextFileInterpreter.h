#ifndef SERVER_TEXTFILEINTERPRETER_H_
#define SERVER_TEXTFILEINTERPRETER_H_

#include "common_Protocol.h"
#include <string>
#include <vector>

class TextFileInterpreter {
public:
	TextFileInterpreter(Protocol p, std::string fileName, std::vector<std::string> &list);

	~TextFileInterpreter();

private:
	void process(Protocol p, std::string fileName, std::vector<std::string> &list);
};

#endif /* SERVER_TEXTFILEINTERPRETER_H_ */
