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
		std::vector<int>{7, 7, 7},	// CCC
		std::vector<int>{3, 3, 9},	// CCD
		std::vector<int>{3, 9, 3},	// CDC
		std::vector<int>{0, 5, 5},	// CDD
		std::vector<int>{9, 3, 3},	// DCC
		std::vector<int>{5, 0, 5},	// DCD
		std::vector<int>{5, 5, 0},	// DDC
		std::vector<int>{1, 1, 1}, };	// DDD
}

std::vector<int> Matrix::get_payoffs(const std::vector<Choice>& choices) { return _matrix[choices_to_idx(choices)]; }

std::vector<int>& Matrix::operator [](std::size_t row) {
	return _matrix[row];
}

bool Matrix::check_matrix(const std::vector<std::vector<char>>& letters) {
	std::vector<std::vector<char>> LETTERS = {
			std::vector<char>{'C', 'C', 'C'},
			std::vector<char>{'C', 'C', 'D'},
			std::vector<char>{'C', 'D', 'C'},
			std::vector<char>{'C', 'D', 'D'},
			std::vector<char>{'D', 'C', 'C'},
			std::vector<char>{'D', 'C', 'D'},
			std::vector<char>{'D', 'D', 'C'},
			std::vector<char>{'D', 'D', 'D'}, };

	for (int i = 0; i < ROWS; i++)
		if (letters[i] != LETTERS[i])
			throw std::invalid_argument("Invaid matrix");

	// CCC, DDD
	if (!(_matrix[0][0] == _matrix[0][1] && _matrix[0][0] == _matrix[0][2]) || 
		!(_matrix[7][0] == _matrix[7][1] && _matrix[7][0] == _matrix[7][2]))
		throw std::invalid_argument("Invaid matrix");

	// CCD, CDC, DCC (для выбора "сотрудничать")
	else if (!(_matrix[1][0] == _matrix[1][1] && _matrix[1][0] == _matrix[2][0] && _matrix[1][0] == _matrix[2][2] 
			&& _matrix[1][0] == _matrix[4][1] && _matrix[1][0] == _matrix[4][2]))
		throw std::invalid_argument("Invaid matrix");

	// DCD, CDD, DDC (для выбора "предать")
	else if (!(_matrix[5][0] == _matrix[3][1] && _matrix[5][0] == _matrix[3][2] && _matrix[5][0] == _matrix[5][2]
			&& _matrix[5][0] == _matrix[6][0] && _matrix[5][0] == _matrix[6][1]))
		throw std::invalid_argument("Invaid matrix");

	// CDD, DCD, DDC (для выбора "сотрудничать")
	else if (!(_matrix[3][0] == _matrix[5][1] && _matrix[3][0] == _matrix[6][2]))
		throw std::invalid_argument("Invaid matrix");

	// CCD, CDC, DCC (для выбора "предать")
	else if (!(_matrix[1][2] == _matrix[2][1] && _matrix[1][2] == _matrix[4][0]))
		throw std::invalid_argument("Invaid matrix");

	const int C1 = _matrix[3][0];	// CDD
	const int C2 = _matrix[1][0];	// CCD
	const int C3 = _matrix[0][0];	// CCC
	const int D1 = _matrix[4][0];	// DCC
	const int D2 = _matrix[6][0];	// DDC
	const int D3 = _matrix[7][0];	// DDD

	if (!(D1 > C3 && C3 > D2 && D2 > C2 && C2 > D3 && D3 > C1))
		throw std::invalid_argument("Invaid matrix");
	if (!(3 * C3 > 2 * C2 + D1))
		throw std::invalid_argument("Invaid matrix");
	if (!(3 * C3 + 2 * D2 + C1))
		throw std::invalid_argument("Invaid matrix");

	return true;
}

Matrix read_matrix(const std::string& file_name) {
	if (file_name.empty())
		return Matrix{};

	std::ifstream stream(file_name);
	if (!stream.is_open())
		throw std::invalid_argument("Can't open matrix file");

	Matrix matrix{};
	std::vector<std::vector<char>> letters(8, std::vector<char>(3, 0));
	std::vector<char> sym(COLS, 0);
	std::vector<int> point(COLS, 0);

	for (int i = 0; i < ROWS; i++) {
		if (stream >> sym[0] >> sym[1] >> sym[2] >> point[0] >> point[1] >> point[2]) {
			for (int j = 0; j < COLS; j++)
				letters[i][j] = sym[j];

			matrix[i] = point;
		}
		else
			throw std::invalid_argument("Invalid matrix");
	}
	matrix.check_matrix(letters);
	stream.close();

	return matrix;
}
