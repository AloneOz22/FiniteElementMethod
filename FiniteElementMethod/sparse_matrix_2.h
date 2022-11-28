#pragma once

#include "triplet_array.h"
#include "mesh.h"
#include "matrix.h"
#include <fstream>

class sparse_matrix_2
{
public:
	std::vector<double> values;
	std::vector<int> i_ptr;
	std::vector<int> j_ptr;
	sparse_matrix_2();
	sparse_matrix_2(triplet_array &trip_arr, int dim);
	std::vector<double> operator *(std::vector<double> right_part);
	double get_value(int i, int j);
	void set_value(int i, int j, double val);
	double row_to_zero(int row);
	sparse_matrix_2 transpose();
	void print(std::string path);
	
};

