#include "common_CommandString.h"
#include "common_Resources.h"
#include "common_Socket.h"
#include <iostream>
#include <string>
#include <vector>

#define HEADER_SIZE 4

CommandString::CommandString() {}

CommandString::~CommandString() {}

void CommandString::send(Socket &skt, std::string &message) {
	std::vector<unsigned char> mlength = bigEndianFromLongDec(message.length());
	char* hex = reinterpret_cast<char*>(mlength.data());
	skt.send(hex,HEADER_SIZE);

	const char* msg = message.c_str();
	skt.send(msg,message.length());
}

std::string CommandString::receive(Socket &skt) {
	char header[HEADER_SIZE];
	skt.recv(header,HEADER_SIZE);

	std::vector<unsigned char> vlength;
	vlength.assign(header,header+HEADER_SIZE);

	unsigned int length = bigEndianToLongDec(vlength);

	char* body;
	body = new char[length];
	skt.recv(body,length);
	std::string response(body,length);
	delete[] body;

    return response;
}

