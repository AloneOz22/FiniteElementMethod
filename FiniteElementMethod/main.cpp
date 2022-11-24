#include "mesh.h"
#include "matrix.h"
#include "finite_element_method.h"
#include "sparse_matrix.h"
#include <iostream>

int main() {
	mesh msh = mesh("example.msh");
	sparse_matrix global = finite_element_method::global_matrix(msh);
	std::vector<double> right_part = finite_element_method::right_part(msh, global);
	for (auto val : right_part) {
		std::cout << val << std::endl;
	}
	return 0;

}