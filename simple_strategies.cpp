#include <iostream>
#include <functional>
#include <random>

#include "simple_strategies.h"

Choice Betray::get_choice() { return _choice; }

void Betray::handle_result(const Result& res) {}

void Betray::make_choice() { _choice = Choice::BETRAY; }


Choice Cooperate::get_choice() { return _choice; }

void Cooperate::handle_result(const Result& res) {}

void Cooperate::make_choice() { _choice = Choice::COOPERATE; }


Choice Random::get_choice() { return _choice; }

void Random::handle_result(const Result& res) {}

void Random::make_choice() {
	std::srand(time(nullptr));
	bool choice = std::rand() % 2;
	(0 == choice) ? _choice = Choice::COOPERATE : _choice = Choice::BETRAY;
}


Choice Change::get_choice() { return _choice; }

void Change::handle_result(const Result& res) {}

void Change::make_choice() {
	if (_choice == Choice::COOPERATE) {
		_choice = Choice::BETRAY;
		return;
	}
	_choice = Choice::COOPERATE;
}
