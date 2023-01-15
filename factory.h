#pragma once

#include "strategy.h"
#include "complex_strategies.h"
#include "simple_strategies.h"
#include <algorithm>

class Factory {
public:
	Strategy* create(const std::string& name);
	virtual ~Factory() {};
};

bool search_strategy_by_id(const std::string& id);

Strategy* create_strategy(const std::string& id);
