#include "common_Guesser.h"
#include "common_Resources.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>

Guesser::Guesser() {}

Guesser::~Guesser() {}

bool Guesser::validClientInput(std::string &input) {
	if (input==HELP) return true;
	if (input==SOURRENDER) return true;
	if (isNumber(input) and sizeNum(input)) return true;
	if (not sizeArgs(input)) std::cout << ERROR_ARGS;
	else
		std::cout << "Error: comando inválido. "
			"Escriba AYUDA para obtener ayuda\n";
	return false;
}

bool Guesser::validServerInput(std::string &input) {
	if (not sizeArgs(input)) {
		std::cerr << ERROR_ARGS;
		return false;
	}
	if (not inRange(input)) {
		std::cerr << ERROR_OUT_OF_RANGE;
		return false;
	}
	if (repeat(input)) {
		std::cerr << ERROR_FORMAT;
		return false;
	}
	return true;
}

std::string Guesser::analyzeCoincidences(std::string &input,
		std::string &num) {
	int good = 0, regular = 0;
	std::string response;

	if (input.size()!=3 or repeat(input)) return INVALID_MSG;

	for(std::string::size_type i = 0; i < input.size(); ++i) {
	    size_t found = num.find(input[i]);
	    if (found != std::string::npos) {
	    	if (i==found) {
	    		good++;
	    	} else {
	    		regular++;
	    	}
	    }
	}

	if (good > 0 and regular > 0)
		response = std::to_string(good) + " bien, "
		+ std::to_string(regular) + " regular";
	else if (good > 0) response = std::to_string(good) + " bien";
	else if (regular > 0) response = std::to_string(regular) + " regular";
	else
		response = "3 mal";
	return response;
}

std::string Guesser::processClientRequest(std::string &input,
		std::string &num, int &chance) {
	if (input==num) return WIN_MSG;
	if (input==SOURRENDER or chance==10) return LOSE_MSG;
	if (input==HELP) {
		return "Comandos válidos:\n\t"
				"AYUDA: despliega la lista de comandos válidos\n\t"
				"RENDIRSE: pierde el juego automáticamente\n\t"
				"XXX: Número de 3 cifras a ser enviado al servidor "
				"para adivinar el número secreto";
	}
    chance++;
    return this->analyzeCoincidences(input,num);
}

bool Guesser::sizeArgs(std::string &input) {
	std::stringstream ss(input);
	std::string token;
	int args = 0;

	while (std::getline(ss,token, ' ')) {
		args++;
	}
	return args==1;
}

bool Guesser::inRange(std::string &value) {
	int num = std::stoi(value);

	return (100<num and num<999);
}

bool Guesser::repeat(std::string &value) {
	for(std::string::size_type i = 0; i < value.size(); i++) {
		for(std::string::size_type j = 0; j < value.size(); j++) {
		    if (i!=j and value[i]==value[j]) return true;
		}
	}
	return false;
}

bool Guesser::sizeNum(std::string &value) {
	if (value.length() > 5) return false;
	std::stringstream hex;
	hex << std::hex << std::stoi(value);
	return hex.str().length()<=4;
}

