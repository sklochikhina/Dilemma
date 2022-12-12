#pragma once

#include <vector>
#include <memory>
#include <cassert>

#include "strategy.h"
#include "matrix.h"

class Game {
public:
	Game(const Matrix& matrix, std::vector<Strategy*> strategies);
	void step();
	Result get_result();
private:
	Matrix _matrix;
	std::vector<Strategy*> _strategies;
	Result _res;
};