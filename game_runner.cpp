#include <string>
#include <algorithm>

#include "matrix.h"
#include "game_runner.h"

std::vector<Strategy*> make_strategies_from_names(const std::vector<std::string>& names) {
	assert(COLS == names.size());
	std::vector<Strategy*> strategies;
	strategies.reserve(COLS);

	for (auto& name : names)
		strategies.push_back(create_strategy(name));

	return strategies;
}

Detailed_runner::Detailed_runner(const Matrix& matrix, std::vector<std::string> names) :
	game(matrix, make_strategies_from_names(names)),
	_names(std::move(names)) {}

Fast_runner::Fast_runner(const Matrix& matrix, std::vector<std::string> names, std::size_t steps) :
	game(matrix, make_strategies_from_names(names)),
	_names(std::move(names)),
	_steps(steps) {}

void Detailed_runner::run(CLI& interface) {
	while (interface.read_comand()) {
		game.step();
		interface.print_intermediate(_names, game.get_result());
	}
	interface.print_after_game(_names, game.get_result());
}

void Fast_runner::run(CLI& interface) {
	for (std::size_t i = 0; i < _steps; i++)
		game.step();
	interface.print_after_game(_names, game.get_result());
}
