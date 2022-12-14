#include <string>

#include "game.h"

static const std::size_t ROWS = 8;

enum class Scores {
	CCC = 0,
	CCD,
	CDC,
	CDD,
	DCC,
	DCD,
	DDC,
	DDD,
};

int choices_to_idx(const std::vector<Choice>& choices) {
	return static_cast<int>(choices[0]) * 4
		+ static_cast<int>(choices[1]) * 2 
		+ static_cast<int>(choices[2]) * 1;
}

Matrix::Matrix() {
	_matrix = {
		std::vector<int>{7, 7, 7},
		std::vector<int>{3, 3, 9},
		std::vector<int>{3, 9, 3},
		std::vector<int>{0, 5, 5},
		std::vector<int>{9, 3, 3},
		std::vector<int>{5, 0, 5},
		std::vector<int>{5, 5, 0},
		std::vector<int>{1, 1, 1}, };
}

std::vector<int> Matrix::get_payoffs(const std::vector<Choice>& choices) { return _matrix[choices_to_idx(choices)]; }

std::vector<int>& Matrix::operator [](std::size_t row) {
	return _matrix[row];
}

bool Matrix::check_matrix(const std::string& file_name) {
	return true;
}

Matrix read_matrix(const std::string& file_name) {
	if (file_name.empty())
		return Matrix{};

	std::ifstream stream(file_name);
	if (!stream.is_open())
		throw std::invalid_argument("Can't open matrix file");

	Matrix matrix{};
	std::vector<int> inputs(COLS, 0);
	std::vector<int> row(inputs);

	for (int i = 0; i < ROWS; i++) {
		if (stream >> inputs[0] >> inputs[1] >> inputs[2]) {
			for (int j = 0; j < COLS; j++)
				row[j] = inputs[j];

			matrix[i] = row;
		}
		else
			throw std::invalid_argument("Invalid matrix");
	}
	matrix.check_matrix(file_name);
	return matrix;
}
