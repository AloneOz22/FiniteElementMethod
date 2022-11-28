#include "triplet_array.h"

triplet_array::triplet_array(std::vector<triplet>& arr) {
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr.size() - 1; j++) {
			if (i != j) {
				if (arr[i].i == arr[j].i && arr[i].j == arr[j].j) {
					arr[i].value += arr[j].value;
					arr[j].value = 0;
					triplet help = arr[j];
					arr[j] = arr.back();
					arr.back() = help;
					arr.pop_back();
				}
			}
		}
	}
	for (int i = 0; i < arr.size(); i++) {
		for (int j = i + 1; j < arr.size(); j++) {
			if (arr[i].i > arr[j].i) {
				triplet help = arr[i];
				arr[i] = arr[j];
				arr[j] = help;
			}
		}
	}
	for (int i = 0; i < arr.size() - 1; i++) {
		for (int j = i + 1; j < arr.size(); j++) {
			if (arr[i].i == arr[j].i) {
				if (arr[i].j > arr[j].j) {
					triplet help = arr[i];
					arr[i] = arr[j];
					arr[j] = help;
				}
			}
		}
	}
	arr.shrink_to_fit();
	this->arr = arr;
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