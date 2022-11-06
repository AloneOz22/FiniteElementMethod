#include "sparse_matrix.h"

sparse_matrix::sparse_matrix() {
	values = std::vector<double>{};
	i_pointer = std::vector<int>{};
	j_pointer = std::vector<int>{};
}

sparse_matrix::sparse_matrix(std::vector<double>& values, std::vector<int>& i_pointer, std::vector<int>& j_pointer) {
	this->values = values;
	this->i_pointer = i_pointer;
	this->j_pointer = j_pointer;
}

sparse_matrix::sparse_matrix(triplet_array& triplets) {
	j_pointer = std::vector<int>();
	values = std::vector<double>();
	i_pointer = std::vector<int>(triplets.max_i + 1);

	//Формируем i_pointer
	for (int i = 0; i < i_pointer.size(); i++) {
		i_pointer[i] = 0;
		for (auto& trip : triplets.arr) {
			if (trip.i == i) {
				i_pointer[i]++;
			}
		}
	}

	for (int i = 1; i < i_pointer.size(); i++) {
		i_pointer[i] += i_pointer[i - 1];
	}

	//Формируем values и j_pointer
	for (int i = 0; i < i_pointer.size(); i++) {
		for (auto& trip : triplets.arr) {
			if (trip.i == i) {
				j_pointer.push_back(trip.j);
				values.push_back(trip.value);
			}
		}
	}
}

std::vector<double> sparse_matrix::operator *(std::vector<double>& right_part) {
	std::vector<double> result = std::vector<double>(i_pointer.size());
	result[0] = 0;
	for (int i = 0; i < i_pointer[0]; i++) {
		result[0] += right_part[j_pointer[i]] * values[i];
	}
	for (int i = 1; i < result.capacity(); i++) {
		result[i] = 0;
		for (int j = i_pointer[i - 1]; j < i_pointer[i]; j++) {
			result[i] += right_part[j_pointer[j]] * values[j];
		}
	}
	return result;
}
