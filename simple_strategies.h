#pragma once

#include "strategy.h"

class Betray : public Strategy {	// всегда предаёт
public:
	Choice make_choice() override;
	void handle_result(const Result& res) override;
};

class Cooperate : public Strategy {	// всегда сотрудничает
public:
	Choice make_choice() override;
	void handle_result(const Result& res) override;
};

class Random : public Strategy {	// выбирает случайно
public:
	Choice make_choice() override;
	void handle_result(const Result& res) override;
};

class Change : public Strategy {	// постоянно меняет решение
public:
	Choice make_choice() override;
	void handle_result(const Result& res) override;
private:
	Choice _choice = Choice::COOPERATE;
};
