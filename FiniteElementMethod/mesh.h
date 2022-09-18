#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "node.h"
#include "element.h"

class mesh
{
private:
	std::vector<node> nodes;
	std::vector<element> elements;
public:
	mesh(std::string path);
	node* getNodePtr(int num);
	element* getElementPtr(int num);
	//void loadMesh(std::string path);
	void saveMesh(std::string path);
};

