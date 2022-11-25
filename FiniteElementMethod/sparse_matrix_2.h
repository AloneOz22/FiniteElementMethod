#pragma once

#include "triplet_array.h"

class sparse_matrix_2
{
public:
	std::vector<double> diag;
	std::vector<double> up_elems;
	std::vector<double> down_elems;
	sparse_matrix_2(triplet_array arr);
	std::vector<double> operator *(std::vector<double> right_part);
};

