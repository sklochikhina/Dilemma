#pragma once

#include "strategy.h"
#include "complex_strategies.h"
#include "simple_strategies.h"

#include <map>
#include <functional>
#include <memory>
#include <stdexcept>

class Factory {
public:
	virtual Strategy* create() = 0;
	virtual ~Factory() {};
};

// ---------------- BETRAY ---------------- //
class BetrayFactory : public Factory {
public:
	Strategy* create() {
		return new Betray;
	}
};

// ---------------- COOPERATE ---------------- //
class CoooperateFactory : public Factory {
public:
	Strategy* create() {
		return new Cooperate;
	}
};

// ---------------- RANDOM ---------------- //
class RandomFactory : public Factory {
public:
	Strategy* create() {
		return new Random;
	}
};

// ---------------- CHANGE ---------------- //
class ChangeFactory : public Factory {
	Strategy* create() {
		return new Change;
	}
};

const std::vector<std::string> _creators = { "cooperate",
												"betray",
												"random",
												"change", };

inline bool search_strategy_by_id(const std::string& id) {
	auto it = std::find(_creators.begin(), _creators.end(), id);

	if (it == _creators.end())
		throw std::invalid_argument("Invalid id for the factory");

	return true;
}

inline Strategy* create_strategy(const std::string& id) {

	search_strategy_by_id(id);
	Factory* strategy;

	if ("cooperate" == id) {
		CoooperateFactory coop;
		strategy = &coop;
	}
	else if ("betray" == id) {
		BetrayFactory betr;
		strategy = &betr;
	}
	else if ("random" == id) {
		RandomFactory rand;
		strategy = &rand;
	}
	else {
		ChangeFactory change;
		strategy = &change;
	}
	// добавить сложные стратегии //

	return strategy->create();
}