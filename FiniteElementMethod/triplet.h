#pragma once

#include<algorithm>
class triplet
{
public:
	int i;
	int j;
	double value;
	triplet(int i, int j, double value);
	void add_to_triplet(triplet*& point, double value);
};

