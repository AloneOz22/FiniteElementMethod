#include "mesh.h"
#include "matrix.h"
#include "finite_element_method.h"
#include <iostream>

int main() {
	node first(1, 0, 0, 0);
	node second(2, 1, 0, 0);
	node third(3, 0, 1, 0);
	node fourth(4, 0, 0, 1);
	element tetrahedron(first, second, third, fourth, 1, 4, 0);
	std::cout << finite_element_method::element_characteristic(tetrahedron);
	return 0;

}