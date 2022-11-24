#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "node.h"
#include "element.h"

class mesh
{	
public:
	std::vector<node> nodes;
	std::vector<element> elements;
	//std::vector<element> tetrahedrons;
	std::vector<element> triangles;
	mesh(std::string path);
	node* get_node_ptr(int num);
	element* get_element_ptr(int num);
	void save_mesh(std::string path);
};

