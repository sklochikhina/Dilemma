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
