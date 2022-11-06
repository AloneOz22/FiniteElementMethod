#pragma once

#include "triplet_array.h"
class sparse_matrix
{
public:
	std::vector<double> values;
	std::vector<int> i_pointer;
	std::vector<int> j_pointer;
	sparse_matrix();
	sparse_matrix(std::vector<double>& values, std::vector<int>& i_pointer, std::vector<int>& j_pointer);
	sparse_matrix(triplet_array& arr);
	std::vector<double> operator *(std::vector<double>& right_part);
};

