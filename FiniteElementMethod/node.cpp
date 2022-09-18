#include "node.h"

node::node(int num, long double x, long double y, long double z) {
	this->num = num;
	this->x = x;
	this->y = y;
	this->z = z;
}

int node::getNum() {
	return num;
}

long double node::getX() {
	return x;
}

long double node::getY() {
	return y;
}

long double node::getZ() {
	return z;
}
