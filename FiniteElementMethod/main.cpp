#include "mesh.h"
#include "matrix.h"
#include <iostream>

int main() {
	std::vector<std::vector<double>> vv = std::vector<std::vector<double>>(3);
	for (int i = 0; i < 3; i++) {
		vv[i] = std::vector<double>(3);
		for (int j = 0; j < 3; j++) {
			vv[i][j] = (i + 1) * 10 + (j + 1);
		}
	}
	std::vector<double> v{ 2, 7, 8 };
	matrix m(3, vv);
	m.print_transposed();
	std::vector<double> result = m * v;
	for (int i = 0; i < 3; i++) {
		std::cout << result[i] << " ";
	}
	return 0;

}