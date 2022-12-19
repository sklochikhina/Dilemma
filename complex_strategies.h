#pragma once

#include "strategy.h"

class Majority : public Strategy {	//  выбирает ту же стратегию, что и большинство
public:
	void make_choice() override;
	Choice get_choice() override;
	void handle_result(const Result& res) override;
private:
	Choice _choice = Choice::COOPERATE;
	std::size_t num_coop = 0;	// сколько стратегий сотрудничали в предыдущем раунде
	std::size_t num_betr = 0;	// сколько стратегий предали в предыдущем раунде
};

class Mimic : public Strategy {		// подражает той стратегии, которая на предыдущем раунде набрала большее количество очков
public:
	void make_choice() override;
	Choice get_choice() override;
	void handle_result(const Result& res) override;
private:
	Choice _choice = Choice::COOPERATE;
};
