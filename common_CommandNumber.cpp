#include "common_CommandNumber.h"
#include "common_Resources.h"
#include "common_Socket.h"
#include <iostream>
#include <string>
#include <vector>

#define BUFFER_SIZE 2

CommandNumber::CommandNumber() {}

CommandNumber::~CommandNumber() {}

void CommandNumber::send(Socket &skt, std::string &message) {
	char n = 'n';
	skt.send(&n,1);

	std::vector<unsigned char> vhex = bigEndianFromShortDec(std::stoi(message));

	char* hex = reinterpret_cast<char*>(vhex.data());

	skt.send(hex,BUFFER_SIZE);
}

std::string CommandNumber::receive(Socket &skt) {
	char buffer[BUFFER_SIZE];
	skt.recv(buffer,BUFFER_SIZE);

	std::vector<unsigned char> vhex;
	vhex.assign(buffer,buffer+BUFFER_SIZE);

	unsigned int num = bigEndianToShortDec(vhex);
	return std::to_string(num);
}

