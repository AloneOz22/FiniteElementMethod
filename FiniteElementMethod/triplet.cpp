#include "triplet.h"

triplet::triplet(int i, int j, double value) {
	this->i = i;
	this->j = j;
	this->value = value;
}

void triplet::add_to_triplet(triplet*& point, double value) {
	point->value += value;
}