#include "common_Resources.h"

#include <arpa/inet.h>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <string.h>
#include <stdio.h>

#define UINT16_SIZE 2
#define UINT32_SIZE 4

bool isNumber(const std::string& s) {
    return !s.empty() && std::find_if(s.begin(),
        s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

uint32_t bigEndianToLongDec(std::vector<unsigned char> hex) {
    uint32_t response;
    memcpy(&response, hex.data(), sizeof(response));
    return ntohl(response);
}

uint16_t bigEndianToShortDec(std::vector<unsigned char> hex) {
    uint16_t response;
    memcpy(&response, hex.data(), sizeof(response));
    return ntohs(response);
}

std::vector<unsigned char> bigEndianFromShortDec(uint16_t num) {
    std::vector<unsigned char> hex(UINT16_SIZE);
    uint16_t uint16 = htons(num);
    memcpy(hex.data(), &uint16, UINT16_SIZE);
    return hex;
}
std::vector<unsigned char> bigEndianFromLongDec(uint32_t num) {
    std::vector<unsigned char> hex(UINT32_SIZE);
    uint32_t uint32 = htonl(num);
    memcpy(hex.data(), &uint32, UINT32_SIZE);
    return hex;
}

