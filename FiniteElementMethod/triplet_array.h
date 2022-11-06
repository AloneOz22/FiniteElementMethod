#pragma once

#include <vector>
#include "triplet.h"

class triplet_array
{
public:
	std::vector<triplet> arr;
	int max_i;
	triplet_array(std::vector<triplet>&);
	void sort_by_i();
	void shrink();
};

