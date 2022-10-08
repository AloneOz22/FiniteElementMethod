#pragma once
#include "node.h"

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


