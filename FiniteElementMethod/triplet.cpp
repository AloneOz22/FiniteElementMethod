#include "triplet.h"

triplet::triplet(int i, int j, double value) {
	this->i = j;
	this->j = i;
	this->value = value;
}

triplet::triplet() {
	this->i = 0;
	this->j = 0;
	this->value = 0;
}
