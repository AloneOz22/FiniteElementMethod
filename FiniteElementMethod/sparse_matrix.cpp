#include "sparse_matrix.h"

sparse_matrix::sparse_matrix() {
	values = std::vector<double>{};
	i_pointer = std::vector<int>{};
	j_pointer = std::vector<int>{};
}

sparse_matrix::sparse_matrix(std::vector<double> values, std::vector<int> i_pointer, std::vector<int> j_pointer) {
	this->values = values;
	this->i_pointer = i_pointer;
	this->j_pointer = j_pointer;
}

sparse_matrix::sparse_matrix(std::vector<triplet> triplets) {
	
	j_pointer = std::vector<int>{};
	values = std::vector<double>{};
	int max_i = 0;
	
	for (int i = 0; i < triplets.size(); i++) {
		if (triplets[i].i > max_i) {
			max_i = triplets[i].i;
		}
	}

	i_pointer = std::vector<int>(max_i + 2);
	
	for (int i = 0; i < i_pointer.size(); i++) {
		i_pointer[i] = 0;
	}
	
	for (int i = 0; i < triplets.size(); i++) {
		i_pointer[triplets[i].i + 2] += 1;
	}
	for (int i = 0; i < triplets.size(); i++) {
		for (int j = 0; j < i_pointer.size(); j++) {
			if (triplets[i].i == j ) {

			}
		}
	}
}

void sparse_matrix::add_to_existing_element(double value, int i, int j) {

}