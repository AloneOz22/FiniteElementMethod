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

sparse_matrix::sparse_matrix(triplet_array& triplets, int dim) {
	j_pointer = std::vector<int>();
	values = std::vector<double>();
	i_pointer = std::vector<int>(dim + 1);

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

double sparse_matrix::get_value(int i, int j) {
	double result = 0;
	if (i != 0) {
		for (int j_ptr = i_pointer[i - 1]; j_ptr < i_pointer[i]; j_ptr++) {
			if (j_pointer[j_ptr] == j) {
				result = this->values[j_ptr];
			}
		}
	}
	else {
		for (int j_ptr = 0; j_ptr < i_pointer[i]; j_ptr++) {
			if (j_pointer[j_ptr] == j) {
				result = this->values[j_ptr];
			}
		}
	}
	return result;
}

void sparse_matrix::set_value(int i, int j, double value) {
	if (i != 0) {
		for (int j_ptr = i_pointer[i - 1]; j_ptr < i_pointer[i]; j_ptr++) {
			if (j_pointer[j_ptr] == j) {
				this->values[j_ptr] = value;
			}
		}
	}
	else {
		for (int j_ptr = 0; j_ptr < i_pointer[i]; j_ptr++) {
			if (j_pointer[j_ptr] == j) {
				this->values[j_ptr] = value;
			}
		}
	}
}

sparse_matrix sparse_matrix::transpose() {
	std::vector<triplet> triplets = {};
	for (int j = 0; j < i_pointer[0]; j++) {
		triplets.push_back(triplet(0, j_pointer[j], values[j]));
	}
	for (int i = 1; i < i_pointer.size(); i++) {
		for (int j = i_pointer[i - 1]; j < i_pointer[i]; j++) {
			triplets.push_back(triplet(i, j_pointer[j], values[j]));
		}
	}
	for (auto trip : triplets) {
		int changer = trip.i;
		trip.i = trip.j;
		trip.j = changer;
	}
	triplet_array arr = triplet_array(triplets);
	sparse_matrix result = sparse_matrix(arr, this->i_pointer.size() - 1);
	return result;
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
