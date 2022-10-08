#pragma once

#include "matrix.h"
#include "mesh.h"

class finite_element_method
{
	static std::vector<double> local_matrix(element& local_element);
	static matrix form_functions(element& local_element);
	static matrix global_matrix();
};

