#include "triplet_array.h"

triplet_array::triplet_array(std::vector<triplet>& arr) {
	this->arr = arr;
	max_i = 0;
	for (triplet trip : this->arr) {
		if (trip.i > max_i) {
			max_i = trip.i;
		}
	}
}

void triplet_array::sort_by_i() {
	for (int i = 0; i < arr.size() - 1; i++) {
		triplet max = arr[i];
		int index = i;
		for (int j = i + 1; j < arr.size(); j++) {
			if (arr[j].i > max.i) {
				max = arr[j];
				index = j;
			}
		}
		arr[index] = arr[i];
		arr[i] = max;
	}
}

void triplet_array::shrink() {
	for (int i = 0; i < arr.size() - 1; i++) {
		for (int j = i; j < arr.size(); j++) {
			if (arr[i].i == arr[j].i && arr[i].j == arr[j].j) {
				arr[i].value += arr[j].value;
				arr[j].i = -1;
			}
		}
	}
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i].i == -1) {
			arr.erase(arr.begin() + i);
		}
	}
	arr.shrink_to_fit();
}