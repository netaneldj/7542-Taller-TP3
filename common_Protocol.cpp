#include "common_Protocol.h"
#include "common_Socket.h"
#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>

#define ERROR_COMMAND "Error: comando inválido. Escriba AYUDA para obtener ayuda\n"
#define ERROR_ARGS "Error: argumentos invalidos.\n"
#define ERROR_OUT_OF_RANGE "Error: archivo con números fuera de rango\n"
#define ERROR_FORMAT "Error: formato de los números inválidos\n"
#define INVALID_MSG "Número inválido. Debe ser de 3 cifras no repetidas"
#define HELP_MSG "Comandos válidos:\n\tAYUDA: despliega la lista de comandos válidos\n\tRENDIRSE: pierde el juego automáticamente\n\tXXX: Número de tres cifras a ser enviado al servidor para adivinar el número secreto"
#define LOSE_MSG "Perdiste"
#define WIN_MSG "Ganaste"
#define NUMBER_SIZE 4
#define STRING_SIZE 3

Protocol::Protocol() {}

Protocol::~Protocol() {}

void Protocol::send(Socket &skt, std::string message) {
	if (message=="AYUDA") help.send(skt,message);
	else if (message=="RENDIRSE") surrender.send(skt,message);
	else if (isNumber(message)) number.send(skt,message);
	else string.send(skt,message);
}

std::string Protocol::receive(Socket& skt) {
	std::string lengthStr;
	std::stringstream ss;
	std::string response = "";
	char buffer1[1] = "";
	char* buffer3;
	int received = 0;

	received = skt.recv(buffer1,1);
	if (buffer1[0]=='h') response = help.receive(buffer1,received);
	else if (buffer1[0]=='s') response = surrender.receive(buffer1,received);
	else if (buffer1[0]=='n') {
		char buffer2[NUMBER_SIZE];
		received = skt.recv(buffer2,NUMBER_SIZE);
		response = number.receive(buffer2,received);
	} else {
		char buffer2[STRING_SIZE] = "";
		lengthStr=buffer1[0];
		received = skt.recv(buffer2,STRING_SIZE);
		for (int i=0; i<STRING_SIZE; i++) lengthStr+=buffer2[i];
		std::reverse(lengthStr.begin(),lengthStr.end());
		received = stoi(lengthStr, 0, 16);

		buffer3= new char[received];
		received = skt.recv(buffer3,received);
		response = string.receive(buffer3,received);
	}
    return response;
}

bool Protocol::validClientInput(std::string input) {
	if (input=="AYUDA") return true;
	if (input=="RENDIRSE") return true;
	if (isNumber(input) and input.length()<=4) return true;
	if (not sizeArgs(input)) std::cout << ERROR_ARGS;
	else std::cout << ERROR_COMMAND;
	return false;
}

bool Protocol::validServerInput(std::string input) {
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

std::string Protocol::analyzeCoincidences(std::string input, std::string num, Score &score) {
	int good = 0, regular = 0;
	std::string response;

	if (input.size()!=3 or repeat(input)) return INVALID_MSG;

	for(std::string::size_type i = 0; i < input.size(); ++i) {
	    size_t found = num.find(input[i]);
	    if (found != std::string::npos) {
	    	if (i==found) good++;
	    	else regular++;
	    }
	}

	if (good > 0 and regular > 0) response = std::to_string(good) + " bien, " + std::to_string(regular) + " regular";
	else if (good > 0) response = std::to_string(good) + " bien";
	else if (regular > 0) response = std::to_string(regular) + " regular";
	else response = "3 mal";
	return response;
}

std::string Protocol::processClientRequest(std::string input, std::string num, int &chance, Score &score) {
	if (input==num) {
		score.addWinner();
		return WIN_MSG;
	}
	if (input=="RENDIRSE" or chance==10){
		score.addLoser();
		return LOSE_MSG;
	}
	if (input=="AYUDA") return HELP_MSG;
    chance++;
    return this->analyzeCoincidences(input,num, score);
}

bool Protocol::isNumber(const std::string& s) {
    return !s.empty() && std::find_if(s.begin(),
        s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

bool Protocol::sizeArgs(std::string &input) {
	std::stringstream ss(input);
	std::string token;
	int args = 0;

	while (std::getline(ss,token, ' ')) {
		args++;
	}
	return args==1;
}

bool Protocol::inRange(std::string value) {
	std::stringstream integer(value);
	int num;

	integer >> num;
	return (100<num and num<999);
}

bool Protocol::repeat(std::string value) {
	for(std::string::size_type i = 0; i < value.size(); i++) {
		for(std::string::size_type j = 0; j < value.size(); j++) {
		    if (i!=j and value[i]==value[j]) return true;
		}
	}
	return false;
}
