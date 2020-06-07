#include "common_Resources.h"

#include <arpa/inet.h>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <string.h>
#include <stdio.h>

bool isNumber(const std::string& s) {
    return !s.empty() && std::find_if(s.begin(),
        s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

uint32_t bigEndianToLongDec(std::vector<unsigned char> buffer) {
    uint32_t response;
    memcpy(&response, buffer.data(), sizeof(response));
    return ntohl(response);
}

uint16_t bigEndianToShortDec(std::vector<unsigned char> number) {
    uint16_t response;
    memcpy(&response, number.data(), sizeof(response));
    return ntohs(response);
}

std::vector<unsigned char> bigEndianFromShortDec(uint16_t num) {
    std::vector<unsigned char> buffer(2);
    uint16_t netNum = htons(num);
    memcpy(buffer.data(), &netNum, 2);
    return buffer;
}
std::vector<unsigned char> bigEndianFromLongDec(uint32_t num) {
    std::vector<unsigned char> buffer(4);
    uint32_t netNum = htonl(num);
    memcpy(buffer.data(), &netNum, 4);
    return buffer;
}

