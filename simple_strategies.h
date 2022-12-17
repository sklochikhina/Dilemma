#pragma once

#include "strategy.h"

class Betray : public Strategy {	// всегда предаёт
public:
	void make_choice() override;
	Choice get_choice() override;
	void handle_result(const Result& res) override;
private:
	Choice _choice = Choice::BETRAY;
};

class Cooperate : public Strategy {	// всегда сотрудничает
public:
	void make_choice() override;
	Choice get_choice() override;
	void handle_result(const Result& res) override;
private:
	Choice _choice = Choice::COOPERATE;
};

class Random : public Strategy {	// выбирает случайно
public:
	void make_choice() override;
	Choice get_choice() override;
	void handle_result(const Result& res) override;
private:
	Choice _choice = Choice::COOPERATE;
};

class Change : public Strategy {	// постоянно меняет решение
public:
	void make_choice() override;
	Choice get_choice() override;
	void handle_result(const Result& res) override;
private:
	Choice _choice = Choice::COOPERATE;
};
