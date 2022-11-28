#pragma once

#include "matrix.h"
#include "mesh.h"
#include "sparse_matrix_2.h"

class finite_element_method
{
private:
	static double scalar_product(std::vector<double> first, std::vector<double> second);
public:
	static sparse_matrix_2 global_matrix(mesh& msh);
	static matrix local_c_matrix(element& local_element);
	static std::vector<double> local_coeficients(element& local_element);
	static double element_characteristic(element& local_element);
	static matrix form_matrix(element& local_element);
	//static std::vector<double> form_functions(element& local_element, double x, double y, double z);
	static matrix form_gradient(element& local_element);
	static std::vector<double> right_part(mesh& msh, sparse_matrix_2& global);
};

