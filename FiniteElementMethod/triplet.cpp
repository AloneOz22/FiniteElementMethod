#include "triplet.h"

triplet::triplet(int i, int j, double value) {
	this->i = i;
	this->j = j;
	this->value = value;
}

triplet::triplet() {
	this->i = 0;
	this->j = 0;
	this->value = 0;
}
