#include <iostream>
#include <functional>
#include <random>

#include "simple_strategies.h"


Choice Betray::make_choice() { return Choice::BETRAY; }

void Betray::handle_result(const Result& res) {}


Choice Cooperate::make_choice() { return Choice::COOPERATE; }

void Cooperate::handle_result(const Result& res) {}


Choice Random::make_choice() {
	std::srand(time(nullptr));
	bool choice = std::rand() % 2;
	return (0 == choice) ? Choice::COOPERATE : Choice::BETRAY;
}

void Random::handle_result(const Result& res) {}


Choice Change::make_choice() {
	if (_choice == Choice::COOPERATE)
		_choice = Choice::BETRAY;
	else
		_choice = Choice::COOPERATE;
	return _choice;
}

void Change::handle_result(const Result& res) {}
