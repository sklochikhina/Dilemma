#include "complex_strategies.h"
#include "factory.h"

Choice Majority::get_choice() { return _choice; }

void Majority::handle_result(const Result& res) {
	for (auto& choice : res._choices) {
		if (Choice::COOPERATE == choice)
			num_coop++;
		else
			num_betr++;
	}
}

void Majority::make_choice() {
	(num_coop > num_betr) ? _choice = Choice::COOPERATE : _choice = Choice::BETRAY;
}

Choice Mimic::get_choice() { return _choice; }

void Mimic::handle_result(const Result& res) {
	int max = 0;
	for (std::size_t i = 0; i < res._scores.size(); i++)
		if (res._scores[i] > max) {
			max = res._scores[i];
			_choice = res._choices[i];
		}
}

void Mimic::make_choice() {}
