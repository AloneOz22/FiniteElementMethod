#pragma once
#include "vector_for_algebra.h"
#include "finite_element_method.h"

static class bcg {

public:
	static std::vector<double> bcg_method(sparse_matrix& global, std::vector<double>& right_part);
};