#pragma once

#include <iostream>
#include <vector>

const std::size_t COLS = 3;	// columns

enum class Choice {
	COOPERATE = 0,
	BETRAY = 1,
};

struct Result {
	Result(int cols = COLS);

	std::vector<Choice> _choices;
	std::vector<int> _payoffs;
	std::vector<int> _scores;
};

class Strategy {
public:
	virtual Choice make_choice() = 0;
	virtual void handle_result(const Result& res) = 0;
	virtual ~Strategy() {};
};
