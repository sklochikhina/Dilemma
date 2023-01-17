#include "complex_strategies.h"
#include "factory.h"
#include <algorithm>

Choice Majority::make_choice() {
	return (num_coop > num_betr) ? Choice::COOPERATE : Choice::BETRAY;
}

void Majority::handle_result(const Result& res) {
	for (auto& choice : res._choices) {
		if (Choice::COOPERATE == choice)
			num_coop++;
		else
			num_betr++;
	}
}


Choice Mimic::make_choice() { return _choice; }

void Mimic::handle_result(const Result& res) {
    auto max = max_element(res._scores.begin(), res._scores.end());
    auto index = distance(res._scores.begin(), max);
    _choice = res._choices[index];
}
