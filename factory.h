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
	Strategy* create(const std::string& name) {
		if ("cooperate" == name) {
			return new Cooperate;
		}
		else if ("betray" == name) {
			return new Betray;
		}
		else if ("random" == name) {
			return new Random;
		}
		else if ("change" == name) {
			return new Change;
		}
		else if ("majority" == name) {
			return new Majority;
		}
		// добавить ещё одну сложную стратегию //
	}
	virtual ~Factory() {};
};

const std::vector<std::string> _creators = { "cooperate",
												"betray",
												"random",
												"change",
												"majority", };

inline bool search_strategy_by_id(const std::string& id) {
	auto it = std::find(_creators.begin(), _creators.end(), id);

	if (it == _creators.end())
		throw std::invalid_argument("Invalid id for the factory");

	return true;
}

inline Strategy* create_strategy(const std::string& id) {
	search_strategy_by_id(id);
	Factory* strategy{};
	return strategy->create(id);
}
