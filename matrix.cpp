#include <string>

#include "game.h"

static const std::size_t ROWS = 8;

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

Matrix read_matrix(const std::string& file_name) {
	if (file_name.empty())
		return Matrix{};
	return Matrix{};
	// добавить чтение файла с матрицей //
}