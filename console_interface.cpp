#include "console_interface.h"

#include <iostream>

#include "strategy.h"

Arguments CLI::parsing_args(int argc, char** argv) {
	Arguments args;
	std::size_t pos = 0;
	std::string argument;
	std::string before;
	std::string after;

	for (int i = 1; i < argc; i++) {

		argument = argv[i];

		if ("--" == argument.substr(0, 2)) {

			pos = argument.find('=');

			if (pos == std::string::npos) {
				if ("help" == argument.substr(2, 4)) {
					CLI help;
					help.print_help();
					break;
				}
				else
					throw std::invalid_argument("Invalid argument");
			}

			after = argument.substr(pos + 1, argument.length() - (pos + 1));

			before = argument.substr(2, pos - 2);

			if (after.empty())
				throw std::invalid_argument("Invalid argument after =");

			if ("mode" == before) {

				if ("detailed" == after) {
					args.mode = Mode::DETAILED;
					continue;
				}

				else if ("fast" == after) {
					args.mode = Mode::FAST;
					continue;
				}

				else
					throw std::invalid_argument("Invalid mode");
			}

			else if ("steps" == before)
				args.steps = std::stoul(after);

			else if ("matrix" == before)
				args.matrix_file = after;

			else
				throw std::invalid_argument("Invalid argument in long option");
		}
		else
			args.strategies.emplace_back(argument);
	}

	if (args.strategies.size() > 3)
		throw std::invalid_argument("Not suppotred mode");

	return args;
}

bool CLI::read_comand() {
	std::string str;
	std::cout << "\nIf that's enough print \"quit\", else print anything else: ";
	std::cin >> str;
	std::cout << std::endl;

	if ("quit" == str)
		return false;

	return true;
}

void CLI::print_after_game(const std::vector<std::string>& names, const Result& result) {
	std::cout << std::string("FINAL SCORES FOR THE TRIPLE") << std::endl;
	for (std::size_t i = 0; i < names.size(); i++)
		std::cout << "[" << names[i] << ":\t" << result._scores[i] << "]" << std::endl;
}

void CLI::print_final(const std::map<std::string, int>& map) {
	std::cout << "------RESULTS FOR ALL STRATEGIES------" << std::endl;
	for (auto& strategy : map)
		std::cout << "[" << strategy.first << ":\t" << strategy.second << "]" << std::endl;
}

void CLI::print_intermediate(const std::vector<std::string>& names, const Result& result) {
	std::cout << "--------------" << std::endl;
	for (std::size_t i = 0; i < names.size(); i++) {
		std::string choice = "cooperate";
		if (Choice::BETRAY == result._choices[i])
			choice = "betray";
		std::cout << "[" << names[i] << ":\t" << choice << ", "
				  << result._payoffs[i] << ", " << result._scores[i] << "]" << std::endl;
	}
	std::cout << "--------------" << std::endl;
}

void CLI::print_help() {
	std::cout << "Mandatory arguments: names of at least 3 strategies" << std::endl;
	std::cout << "Possible options:" << std::endl;
	std::cout << "--help for outputing these options" << std::endl;
	std::cout << "--mode=[detailed|fast|tournament], --detailed by default for 3 strategies, --tournament for > 3 (OPTIONAL)" << std::endl;
	std::cout << "--steps=<n>, n = 10 by default (OPTIONAL)" << std::endl;
	std::cout << "--matrix=<filename> for full path to game matrix (OPTIONAL)" << std::endl << std::endl;

	std::cout << "The SIMPLE available strategies:" << std::endl;
	std::cout << "cooperate\t- always cooperate" << std::endl;
	std::cout << "betray\t\t- always betray" << std::endl;
	std::cout << "change\t\t- always change" << std::endl;
	std::cout << "random\t\t- choosing randomly" << std::endl << std::endl;

	std::cout << "The COMPLEX available strategies:" << std::endl;
	std::cout << "mimic\t\t- choosing a strategy that scored more points" << std::endl;
	std::cout << "majority\t- choosing a strategy that a majority chose" << std::endl << std::endl;
}
