#pragma once

#include <vector>
#include "triplet.h"
class sparse_matrix
{
public:
	std::vector<double> values;
	std::vector<int> i_pointer;
	std::vector<int> j_pointer;
	sparse_matrix();
	sparse_matrix(std::vector<double> values, std::vector<int> i_pointer, std::vector<int> j_pointer);
	sparse_matrix(std::vector<triplet> triplets);
	void add_element(double value, int i, int j);
	void add_to_existing_element(double value, int i, int j);
	std::vector<double> operator *(std::vector<double> right_part);
};

