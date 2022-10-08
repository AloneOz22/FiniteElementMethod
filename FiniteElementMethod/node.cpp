#include "node.h"

node::node(int num, double x, double y, double z) {
	this->num = num;
	this->value = 100;
	this->x = x;
	this->y = y;
	this->z = z;
}

int node::get_num() {
	return num;
}

double node::get_x() {
	return x;
}

double node::get_y() {
	return y;
}

double node::get_z() {
	return z;
}

double node::get_value() {
	return value;
}
