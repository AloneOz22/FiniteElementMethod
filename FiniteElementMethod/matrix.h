#pragma once
#include <vector>
#include <iostream>
#include <thread>
#include <mutex>
#include <cmath>
#include <condition_variable>

const double EPS = 0.0000000001;

class matrix
{
private:

	int cols;
	int rows;

	std::vector<std::vector<double>> values;

	double minimal_determinant();
	matrix minor(int col, int row);

public:

	matrix(int cols, int rows, std::vector<std::vector<double>> values);
	matrix(int cols, int rows);
	matrix(int dim, std::vector<std::vector<double>> values);
	matrix(int dim);
	matrix();

	matrix operator +(matrix second);
	matrix operator -(matrix second);
	matrix operator *(matrix second);
	std::vector<double> operator *(std::vector<double> col);
	std::vector<double> operator *(std::vector<int> col);
	matrix operator *(int val);
	matrix operator *(double val);
	
	matrix zero(int dim);
	matrix one(int dim);
	matrix inverse();
	matrix transposition();

	double determinant();
	void print_transposed();

};

