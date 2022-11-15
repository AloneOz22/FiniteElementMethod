#include "mesh.h"
#include "matrix.h"
#include "finite_element_method.h"
#include "sparse_matrix.h"
#include <iostream>

int main() {
	mesh msh("Example.msh");
	sparse_matrix global = finite_element_method::global_matrix(msh);
	for (auto elem : msh.elements) {
		if (elem.get_type() == 4) {
			matrix coef = finite_element_method::local_c_matrix(elem);
			coef.print_transposed();
			std::cout << std::endl;
		}
	}
	return 0;

}