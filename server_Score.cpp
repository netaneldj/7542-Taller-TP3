#include "server_Score.h"

#include <iostream>

Score::Score(std::mutex &m) : m(m) {
	this->winers = 0;
	this->losers = 0;
}

Score::~Score() {}

void Score::addWinner() {
	std::unique_lock<std::mutex> bloqueo(m);
	this->winers++;
}

void Score::addLoser() {
	std::unique_lock<std::mutex> bloqueo(m);
	this->losers++;
}

void Score::show() {
	std::cout << "Estadísticas:\n\tGanadores:  " << this->winers <<
			"\n\tPerdedores: " << this->losers << "\n";
}

