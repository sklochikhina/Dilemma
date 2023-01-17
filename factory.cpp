#include "factory.h"

#include <functional>
#include <memory>
#include <stdexcept>

const std::vector<std::string> creators = { "cooperate",
											"betray",
											"random",
											"change",
											"majority",
											"mimic", };

Strategy* Factory::create(const std::string& name) {
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
	else {
		return new Mimic;
	}
}

void Factory::help() {
	std::cout << "The SIMPLE available strategies:" << std::endl;
	std::cout << "cooperate\t- always cooperate" << std::endl;
	std::cout << "betray\t\t- always betray" << std::endl;
	std::cout << "change\t\t- always change" << std::endl;
	std::cout << "random\t\t- choosing randomly" << std::endl << std::endl;

	std::cout << "The COMPLEX available strategies:" << std::endl;
	std::cout << "mimic\t\t- choosing a strategy that scored more points" << std::endl;
	std::cout << "majority\t- choosing a strategy that a majority chose" << std::endl << std::endl;
}

bool search_strategy_by_id(const std::string& id) {
	auto it = std::find(creators.begin(), creators.end(), id);

	if (it == creators.end())
		throw std::invalid_argument("Invalid id for the factory");

	return true;
}

Strategy* create_strategy(const std::string& id) {
	search_strategy_by_id(id);
	Factory* strategy{};
	return strategy->create(id);
}
