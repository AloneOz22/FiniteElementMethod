#include "mesh.h"
#include "matrix.h"
#include "finite_element_method.h"
#include "sparse_matrix.h"
#include <iostream>

int main() {
	/*node first(1, 0, 0, 0);
	node second(2, 1, 0, 0);
	node third(3, 0, 1, 0);
	node fourth(4, 0, 0, 1);
	element tetrahedron(first, second, third, fourth, 1, 4, 0);
	std::cout << finite_element_method::element_characteristic(tetrahedron);*/
	std::vector<triplet> arr = std::vector<triplet>();
	arr.push_back(triplet(0, 3, 5));
	arr.push_back(triplet(1, 0, 3));
	arr.push_back(triplet(1, 2, 1));
	arr.push_back(triplet(2, 2, 7));
	arr.push_back(triplet(3, 0, 2));
	std::vector<double> right_part{ 4, 2, 7, 5};
	triplet_array triplets = triplet_array(arr);
	sparse_matrix A = sparse_matrix(triplets);
	std::vector<double> result = A * right_part;
	for (int i = 0; i < result.size(); i++) {
		std::cout << result[i] << std::endl;
	}
	return 0;

}