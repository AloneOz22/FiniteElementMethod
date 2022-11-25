#pragma once

#include <vector>
#include <cmath>

class vector_for_algebra
{
public:
	std::vector<double> V;
	vector_for_algebra();
	vector_for_algebra(std::vector<double> vec);
	vector_for_algebra operator +(vector_for_algebra V2);
	vector_for_algebra operator -(vector_for_algebra V2);
	vector_for_algebra operator *(double value);
	double operator *(vector_for_algebra V2);
	double norm();
	void normalising();

};

