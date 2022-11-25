#include "mesh.h"
#include "matrix.h"
#include "finite_element_method.h"
#include "sparse_matrix.h"
#include "BCG.h"


int main() {
	mesh msh = mesh("test.msh");
	sparse_matrix global = finite_element_method::global_matrix(msh);
	std::vector<double> right_part = finite_element_method::right_part(msh, global);
	std::vector<double> result = bcg::bcg_method(global, right_part);
	for (auto val : result) {
		std::cout << val << std::endl;
	}
	return 0;

}