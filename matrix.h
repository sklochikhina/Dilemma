#pragma once

#include <fstream>
#include "strategy.h"

class Matrix {
public:
	Matrix();
	Matrix(const Matrix& other) = default;
	~Matrix() = default;
	std::vector<int> get_payoffs(const std::vector<Choice>& choices); // 3 выигрыша
	// добавить проверку матрицы на консистентность
private:
	std::vector<std::vector<int>> _matrix;
};

Matrix read_matrix(const std::string& file_path);