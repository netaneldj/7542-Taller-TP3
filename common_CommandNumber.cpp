#include "common_CommandNumber.h"
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>

CommandNumber::CommandNumber() {}

CommandNumber::~CommandNumber() {}

void CommandNumber::send(Socket &skt, std::string message) {
	std::stringstream integer(message);
	std::stringstream hex;
	std::string temp;
	const char* protocol;
	int num;

	integer >> num;
	hex << std::hex << num;

	temp = hex.str() + 'n';
	std::reverse(temp.begin(),temp.end());

	while (temp.length()<5)temp.append("0");

	protocol = temp.c_str();
	skt.send(protocol,temp.length());
}

std::string CommandNumber::receive(char* response, size_t length) {
	std::stringstream ss;
	unsigned int num;
	std::string msg;

	msg = response;
	std::reverse(msg.begin(),msg.end());
	num = stoi(msg, 0, 16);
	msg = std::to_string(num);
	return msg;
}

