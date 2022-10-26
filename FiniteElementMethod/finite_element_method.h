#pragma once

#include "matrix.h"
#include "mesh.h"
#include "sparse_matrix.h"

class finite_element_method
{
private:
	static double scalar_product(std::vector<double> first, std::vector<double> second);
public:
	static matrix local_c_matrix(element& local_element);
	static std::vector<double> local_coeficients(element& local_element);
	static double element_characteristic(element& local_element);
	static matrix form_matrix(element& local_element);
	static std::vector<double> form_functions(element& local_element, double x, double y, double z);
	static matrix form_gradient(element& local_element);
	//static sparce_matrix global_matrix();
};

