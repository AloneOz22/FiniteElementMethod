#pragma once
#include "node.h"
#include <vector>

class element
{
private:
	node* first_node;
	node* second_node;
	node* third_node;
	node* fourth_node;

	int num;
	int type;
	int tag;
public:
	std::vector<node*> node_list;

	element(node& first_node, node& second_node, node& third_node, node& fourth_node, int num, int type, int tag);
	element(node& first_node, node& second_node, node& third_node, int num, int type, int tag);
	element(node& first_node, node& second_node, int num, int type, int tag);
	element(node& first_node, int num, int type, int tag);
	node* get_first_node_ptr();
	node* get_second_node_ptr();
	node* get_third_node_ptr();
	node* get_fourth_node_ptr();
	int get_num();
	int get_type();
	int get_tag();
};


