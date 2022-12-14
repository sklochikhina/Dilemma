#include <exception>
#include <iostream>

#include "game_runner.h"

int main(int argc, char** argv) {

	if (argc < 4) {
		std::cerr << "Invalid number of arguments: names of at least 3 strategies" << std::endl;
		CLI ui;
		ui.print_help();
		return -1;
	}

	try {
		CLI ui;				// user input
		ui.print_help();

		Arguments args = ui.parsing_args(argc, argv);

		Runner* runner;

		if (Mode::DETAILED == args.mode)
			runner = new Detailed_runner(read_matrix(args.matrix_file), args.strategies);
		else
			runner = new Fast_runner(read_matrix(args.matrix_file), args.strategies, args.steps);

		runner->run(ui);
	}

	catch (std::exception& excp) {
		std::cerr << "Caught exception: " << excp.what() << std::endl;
		return -1;
	}

	return 0;
}
