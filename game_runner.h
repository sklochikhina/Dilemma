#pragma once

#include <vector>
#include <string>

#include "factory.h"
#include "console_interface.h"
#include "game.h"

class CLI;

class Runner {
public:
	virtual ~Runner() = default;
	virtual void run(CLI& interface) = 0;
};

class FastRunner : public Runner {
public:
	FastRunner(const Matrix& matrix, std::vector<std::string> names, std::size_t steps);
	void run(CLI& interface) override;
private:
	Game game;
	std::vector<std::string> _names;
	std::size_t _steps;
};

class DetailedRunner : public Runner {
public:
	DetailedRunner(const Matrix& matrix, std::vector<std::string> names);
	void run(CLI& interface) override;
private:
	Game game;
	std::vector<std::string> _names;
};
