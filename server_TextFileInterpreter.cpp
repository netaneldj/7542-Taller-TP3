#include "server_TextFileInterpreter.h"
#include <iostream>
#include <fstream>

TextFileInterpreter::TextFileInterpreter(std::string fileName, std::vector<std::string> &list) {
	this->process(fileName,list);
}

TextFileInterpreter::~TextFileInterpreter(){}

void TextFileInterpreter::process(std::string fileName, std::vector<std::string> &list) {
	std::ifstream File(fileName);
	std::string line;

	while(not File.eof()){
		getline(File,line,'\n');
		if (line.size()==0) break;
		if (g.validServerInput(line))list.push_back(line);
	}
}

