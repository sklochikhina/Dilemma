#include <string>
#include <algorithm>

#include "matrix.h"
#include "game_runner.h"

std::vector<Strategy*>* make_strategies_from_names(const std::vector<std::string>& names) {
	assert(COLS == names.size());
	std::vector<Strategy*>* strategies = new std::vector<Strategy*>;
	strategies->reserve(COLS);

	for (auto& name : names)
		strategies->push_back(create_strategy(name));

	return strategies;
}

DetailedRunner::DetailedRunner(const Matrix& matrix, std::vector<std::string>& names) :
	game(matrix, make_strategies_from_names(names)),
	_names(std::move(names)) {}

FastRunner::FastRunner(const Matrix& matrix, std::vector<std::string>& names, std::size_t& steps) :
	game(matrix, make_strategies_from_names(names)),
	_names(std::move(names)),
	_steps(steps) {}

void DetailedRunner::run(CLI& interface) {
	while (interface.read_comand()) {
		game.step();
		interface.print_intermediate(_names, game.get_result());
	}
	interface.print_after_game(_names, game.get_result());
}

void FastRunner::run(CLI& interface) {
	for (std::size_t i = 0; i < _steps; i++)
		game.step();
	interface.print_after_game(_names, game.get_result());
}
