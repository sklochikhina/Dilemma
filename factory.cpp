#include "factory.h"

#include <map>
#include <functional>
#include <memory>
#include <stdexcept>

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