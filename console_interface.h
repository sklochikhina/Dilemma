#pragma once

#include <string>
#include <vector>
#include <map>

const std::size_t DEFAULT_STEPS = 10;

struct Result;

enum class Mode {
	DETAILED = 0,
	FAST,
};

struct Arguments {
	std::vector<std::string> strategies{};
	std::size_t steps = DEFAULT_STEPS;
	Mode mode = Mode::DETAILED;
	std::string matrix_file{};
};

class CLI {
public:
	Arguments parsing_args(int argc, char* argv);
	bool read_comand();
	void print_after_game(const std::vector<std::string>& names, const Result& result);
	void print_intermediate(const std::vector<std::string>& names, const Result& result);
	void print_final(const std::map<std::string, int>& map);
	void print_help();
};