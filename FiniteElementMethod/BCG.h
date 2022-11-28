#pragma once
#include "vector_for_algebra.h"
#include "finite_element_method.h"
#include "sparse_matrix_2.h"

static class bcg {

public:
	static std::vector<double> bcg_method(sparse_matrix_2& global, std::vector<double>& right_part);
	static std::vector<double> bcg_method_2(sparse_matrix_2& global, std::vector<double>& right_part);

};