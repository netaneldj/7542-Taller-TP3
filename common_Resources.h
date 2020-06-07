#ifndef COMMON_RESOURCES_H_
#define COMMON_RESOURCES_H_

#include <string>
#include <vector>

#define ERROR_ARGS "Error: argumentos invalidos.\n"
#define ERROR_OUT_OF_RANGE "Error: archivo con números fuera de rango\n"
#define ERROR_FORMAT "Error: formato de los números inválidos\n"
#define INVALID_MSG "Número inválido. Debe ser de 3 cifras no repetidas"
#define LOSE_MSG "Perdiste"
#define WIN_MSG "Ganaste"
#define SOURRENDER "RENDIRSE"
#define HELP "AYUDA"

bool isNumber(const std::string &s);

uint32_t bigEndianToLongDec(std::vector<unsigned char> hex);

uint16_t bigEndianToShortDec(std::vector<unsigned char> hex);

std::vector<unsigned char> bigEndianFromShortDec(uint16_t num);

std::vector<unsigned char> bigEndianFromLongDec(uint32_t num);

#endif /* COMMON_RESOURCES_H_ */
