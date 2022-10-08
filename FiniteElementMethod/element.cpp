#include "element.h"

element::element(node& first_node, node& second_node, node& third_node, node& fourth_node, int num, int type, int tag) {
	this->first_node = &first_node;
	this->second_node = &second_node;
	this->third_node = &third_node;
	this->fourth_node = &fourth_node;
	this->num = num;
	this->type = type;
	this->tag = tag;
}

element::element(node& first_node, node& second_node, node& third_node, int num, int type, int tag) {
	this->first_node = &first_node;
	this->second_node = &second_node;
	this->third_node = &third_node;
	this->fourth_node = nullptr;
	this->num = num;
	this->type = type;
	this->tag = tag;
}

element::element(node& first_node, node& second_node, int num, int type, int tag) {
	this->first_node = &first_node;
	this->second_node = &second_node;
	this->third_node = nullptr;
	this->fourth_node = nullptr;
	this->num = num;
	this->type = type;
	this->tag = tag;
}

element::element(node& first_node, int num, int type, int tag) {
	this->first_node = &first_node;
	this->second_node = nullptr;
	this->third_node = nullptr;
	this->fourth_node = nullptr;
	this->num = num;
	this->type = type;
	this->tag = tag;
}

node* element::get_first_node_ptr() {
	return first_node;
}

node* element::get_second_node_ptr() {
	return second_node;
}

node* element::get_third_node_ptr() {
	return third_node;
}

node* element::get_fourth_node_ptr() {
	return fourth_node;
}

int element::get_num() {
	return num;
}

int element::get_type() {
	return type;
}

int element::get_tag() {
	return tag;
}
