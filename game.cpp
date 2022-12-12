#include "game.h"
#include "strategy.h"

void Game::step() {
	
	for (std::size_t i = 0; i < _strategies.size(); i++) {
		_strategies[i]->make_choice();
		_res._choices[i] = _strategies[i]->get_choice();
	}

	_res._payoffs = _matrix.get_payoffs(_res._choices);

	for (std::size_t i = 0; i < _strategies.size(); i++)
		_res._scores[i] += _res._payoffs[i];

	for (auto& strategy : _strategies)
		strategy->handle_result(_res);
}

Game::Game(const Matrix& matrix, std::vector<Strategy*> strategies) :
	_matrix(matrix),
	_strategies(std::move(strategies)),
	_res() {}

Result Game::get_result() { return _res; }

Result::Result(int cols) :_choices(cols), _payoffs(cols), _scores(cols) {}