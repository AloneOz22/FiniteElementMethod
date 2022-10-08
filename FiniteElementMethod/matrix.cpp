#include "matrix.h"

matrix::matrix(int cols, int rows, std::vector<std::vector<double>> values) {
	try {
		this->cols = cols;
		this->rows = rows;
		this->values = std::vector<std::vector<double>>(cols);
		for (int i = 0; i < cols; i++) {
			this->values[i] = std::vector<double>(rows);
			for (int j = 0; j < rows; j++) {
				this->values[i][j] = values[i][j];
			}
		}
	}
	catch (std::exception e) {
		std::cout << e.what() << std::endl;
	}
}

matrix::matrix(int cols, int rows) {
	try {
		this->cols = cols;
		this->rows = rows;
		this->values = std::vector<std::vector<double>>(cols);
		for (int i = 0; i < cols; i++) {
			this->values[i] = std::vector<double>(rows);
			for (int j = 0; j < rows; j++) {
				this->values[i][j] = 0;
			}
		}
	}
	catch (std::exception e) {
		std::cout << e.what() << std::endl;
	}
}

matrix::matrix(int dim, std::vector<std::vector<double>> values) {
	try {
		this->cols = dim;
		this->rows = dim;
		this->values = std::vector<std::vector<double>>(cols);
		for (int i = 0; i < dim; i++) {
			this->values[i] = std::vector<double>(dim);
			for (int j = 0; j < dim; j++) {
				this->values[i][j] = values[i][j];
			}
		}
	}
	catch (std::exception e) {
		std::cout << e.what() << std::endl;
	}
}

matrix::matrix(int dim) {
	try {
		this->cols = dim;
		this->rows = dim;
		this->values = std::vector<std::vector<double>>(cols);
		for (int i = 0; i < dim; i++) {
			this->values[i] = std::vector<double>(dim);
			for (int j = 0; j < dim; j++) {
				this->values[i][j] = 0;
			}
		}
	}
	catch (std::exception e) {
		std::cout << e.what() << std::endl;
	}
}

matrix::matrix() {
	try {
		this->cols = 0;
		this->rows = 0;
		this->values = std::vector<std::vector<double>>(0);
	}
	catch (std::exception e) {
		std::cout << e.what() << std::endl;
	}
}

matrix matrix::operator +(matrix second) {
	try {
		if (this->cols != second.cols || this->rows != second.rows) {
			throw "Error! Dimensions of matrices are not equal!";
		}
		matrix result(this->cols, this->rows, this->values);
		for (int i = 0; i < this->cols; i++) {
			for (int j = 0; j < this->rows; j++) {
				result.values[i][j] = this->values[i][j] + second.values[i][j];
			}
		}
		return result;
	}
	catch (const char* message) {
		std::cout << message << std::endl;
		return matrix(this->cols, this->rows, this->values);
		}
}

matrix matrix::operator -(matrix second) {
	try {
		if (this->cols != second.cols || this->rows != second.rows) {
			throw "Error! Dimensions of matrices are not equal!";
		}
		matrix result(this->cols, this->rows, this->values);
		for (int i = 0; i < this->cols; i++) {
			for (int j = 0; j < this->rows; j++) {
				result.values[i][j] = this->values[i][j] - second.values[i][j];
			}
		}
		return result;
	}
	catch (const char* message) {
		std::cout << message << std::endl;
		return matrix(this->cols, this->rows, this->values);
	}
}

matrix matrix::operator *(matrix second) {
	try {
		matrix result(second.cols, this->rows);
		for (int i = 0; i < second.rows; i++) {
			for (int j = 0; j < this->cols; j++) {
				for (int k = 0; k < second.cols; k++) {
					result.values[i][j] += this->values[i][k] * second.values[k][j];
				}
			}
		}
		return result;
	}
	catch (std::exception e) {
		std::cout << e.what() << std::endl;
		return matrix(this->cols, this->rows, this->values);
	}
}

std::vector<double> matrix::operator *(std::vector<double> col) {
	try {
		if (this->cols != col.capacity()) {
			throw "Dims aren't equal!";
		}
		std::vector<double> result = std::vector<double>(this->cols);
		for (int i = 0; i < this->cols; i++) {
			result[i] = 0;
			for (int j = 0; j < this->rows; j++) {
				result[i] += this->values[i][j] * col[j];
			}
		}
		return result;
	}
	catch (char* message) {
		std::cout << message << std::endl;
		return std::vector<double>{0};
	}
}

std::vector<double> matrix::operator *(std::vector<int> col) {
	try {
		if (this->cols != col.capacity()) {
			throw "Dims aren't equal!";
		}
		std::vector<double> result = std::vector<double>(this->cols);
		for (int i = 0; i < this->cols; i++) {
			result[i] = 0;
			for (int j = 0; j < this->rows; j++) {
				result[i] += this->values[i][j] * col[j];
			}
		}
		return result;
	}
	catch (char* message) {
		std::cout << message << std::endl;
		return std::vector<double>{0};
	}
}

matrix matrix::operator *(int val) {
	try {
		matrix result(this->cols, this->rows, this->values);
		for (int i = 0; i < result.cols; i++) {
			for (int j = 0; j < result.rows; j++) {
				result.values[i][j] *= val;
			}
		}
		return result;
	}
	catch (std::exception e) {
		std::cout << e.what() << std::endl;
		return 0;
	}
}

matrix matrix::operator *(double val) {
	try {
		matrix result(this->cols, this->rows, this->values);
		for (int i = 0; i < result.cols; i++) {
			for (int j = 0; j < result.rows; j++) {
				result.values[i][j] *= val;
			}
		}
		return result;
	}
	catch (std::exception e) {
		std::cout << e.what() << std::endl;
		return 0;
	}
}

matrix matrix::zero(int dim) {
	matrix result = matrix(dim);
	return result;
}

matrix matrix::one(int dim) {
	matrix result = matrix(dim);
	for (int i = 0; i < dim; i++) {
		result.values[i][i] = 1;
	}
	return result;
}

matrix matrix::inverse() {
	try {
		if (this->determinant() < EPS) {
			throw "det(A) == 0!";
		}
		matrix union_matrix = matrix::zero(this->cols);
		for (int i = 0; i < union_matrix.cols; i++) {
			for (int j = 0; j < union_matrix.rows; j++) {
				union_matrix.values[i][j] = pow(-1, (i + 1) + (j + 1)) * this->minor(i, j).determinant();
			}
		}
		matrix result = matrix::zero(this->cols);
		result = union_matrix * (1 / this->determinant());
		return result;
	}
	catch (char* message) {
		std::cout << message << std::endl;
		return matrix::zero(2);
	}
}

matrix matrix::minor(int col, int row) {
	try {
		if (this->cols - 1 != this->rows - 1) {
			throw "cols != rows!";
		}
		matrix result(this->cols - 1, this->rows - 1);
		bool i_changed = false;
		for (int i = 0; i < this->cols - 1; i++) {
			bool j_changed = false;
			int i_index = i;
			if (i_index == col || i_changed) {
				i_index++;
				i_changed = true;
			}
			for (int j = 0; j < this->rows - 1; j++) {
				int j_index = j;
				if (j_index == row || j_changed) {
					j_index++;
					j_changed = true;
				}
				result.values[i][j] = this->values[i_index][j_index];
			}
		}
		return result;
	}
	catch (char* message) {
		std::cout << message << std::endl;
		return matrix::zero(2);
	}
}

double matrix::minimal_determinant() {
	try {
		if (this->cols != 2 || this->rows != 2) {
			throw "Dimension is not 2!";
		}
		double result = this->values[0][0] * this->values[1][1] - this->values[0][1] * this->values[1][0];
		return result;
	}
	catch (char* message) {
		std::cout << message << std::endl;
		return 0;
	}
}

double matrix::determinant() {
	try {
		if (this->cols != this->rows) {
			throw "cols != rows!";
		}
		double result = 0;
		if (this->cols == 2 && this->rows == 2) {
			result = this->minimal_determinant();
		}
		else {
			for (int i = 0; i < cols; i++) {
				result += this->minor(i, 0).determinant() * pow(-1, i) * this->values[i][0];
			}
		}
		return result;
	}
	catch (char* message) {
		std::cout << message << std::endl;
		return 0;
	}
}

matrix matrix::transposition() {
	matrix result = matrix(this->cols);
	try {
		for (int i = 0; i < this->cols; i++) {
			for (int j = 0; j < this->rows; j++) {
				result.values[i][j] = this->values[j][i];
			}
		}
		return result;
	}
	catch (std::exception e) {
		std::cout << e.what() << std::endl;
		return matrix();
	}
}

void matrix::print_transposed() {
	for (int i = 0; i < this->cols; i++) {
		for (int j = 0; j < this->rows; j++) {
			std::cout << this->values[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

