#include "common_CommandString.h"
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>

CommandString::CommandString() {}

CommandString::~CommandString() {}

void CommandString::send(Socket &skt, std::string message) {
	std::stringstream hex;
	std::string temp;
	const char* protocol;

	hex << std::hex << message.length();
	temp = hex.str();
	std::reverse(temp.begin(),temp.end());
	while (temp.length()<4)temp.append("0");
	temp.append(message);
	protocol = temp.c_str();
	skt.send(protocol,temp.length());
}

std::string CommandString::receive(char* response, size_t length) {
	std::string msg = "";

	for (size_t i=0; i<length; i++) msg+=response[i];
	return msg;
}

