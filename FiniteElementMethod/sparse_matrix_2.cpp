#include "sparse_matrix_2.h"

sparse_matrix_2::sparse_matrix_2() {

}

sparse_matrix_2::sparse_matrix_2(triplet_array &trip_arr, int dim) {
	i_ptr = std::vector<int>(dim + 1);
	for (auto i : i_ptr) {
		i = 0;
	}
	i_ptr[0] = 1;
	for (auto trip : trip_arr.arr) {
		i_ptr[trip.i + 1]++;
	}
	for (int i = 1; i < i_ptr.size(); i++) {
		i_ptr[i] += i_ptr[i - 1];
	}
	for (int i = 1; i < i_ptr.size(); i++) {
		for (auto trip : trip_arr.arr) {
			if (trip.i == i - 1) {
				j_ptr.push_back(trip.j);
				values.push_back(trip.value);
			}
		}
	}
}
std::vector<double> sparse_matrix_2::operator *(std::vector<double> right_part) {
	std::vector<double> result = std::vector<double>(right_part.capacity());
	for (int k = 0; k < right_part.size(); k++) {
		result[k] = 0;
		for (int i = i_ptr[k]; i < i_ptr[k + 1]; i++) {
			result[k] += values[i - 1] * right_part[j_ptr[i - 1]];
		}
	}
	return result;
}

double sparse_matrix_2::get_value(int i, int j) {
	double result = 0;
	for (int J = i_ptr[i] - 1; J < i_ptr[i + 1]; J++) {
		if (j_ptr[J] == j) {
			result = values[J];
			break;
		}
	}
	return result;
}

void sparse_matrix_2::set_value(int i, int j, double value) {
	for (int J = i_ptr[i]; J < i_ptr[i + 1]; J++) {
		bool exist = false;
		if (j_ptr[J] == j) {
			values[J] = value;
			break;
		}
		if (!exist) {
			for (int I = i + 1; I < i_ptr.size(); I++) {
				i_ptr[I]++;
			}
			j_ptr.insert(j_ptr.begin() + i_ptr[i + 1], j);
			values.insert(values.begin() + i_ptr[i + 1], value);
		}
	}
}

double sparse_matrix_2::row_to_zero(int row) {
	double diag_value = 0;
	for (int J = i_ptr[row] - 1; J < i_ptr[row + 1] - 1; J++) {
		if (j_ptr[J] != row) {
			values[J] = 0;
		}
		else {
			diag_value = values[J];
			values[J] = 1;
		}
	}
	return diag_value;
}

sparse_matrix_2 sparse_matrix_2::transpose() {
	std::vector<triplet> arr = std::vector<triplet>();
	for (int i = 1; i < i_ptr.size(); i++) {
		for (int j = i_ptr[i - 1] - 1; j < i_ptr[i] - 1; j++) {
			arr.push_back(triplet(j_ptr[j], i - 1, values[j]));
		}
	}
	triplet_array trips = triplet_array(arr);
	sparse_matrix_2 result = sparse_matrix_2(trips, i_ptr.size() - 1);
	return result;
}

void sparse_matrix_2::print(std::string path) {
	std::ofstream fout = std::ofstream(path);
	//std::vector<std::vector<double>> vals = std::vector<std::vector<double>>();
	//for (int i = 0; i < this->i_ptr.size() - 1; i++) {
	//	vals.push_back(std::vector<double>());
	//	for (int j = 0; j < this->i_ptr.size() - 1; j++) {
	//		vals[i].push_back(this->get_value(i, j));
	//	}
	//}
	//matrix A = matrix(i_ptr.size() - 1, vals);
	//A.print_transposed();
	for (auto i : i_ptr) {
		fout << i << " ";
	}
	fout << std::endl;
	for (auto j : j_ptr) {
		fout << j << " ";
	}
	fout << std::endl;
	for (auto val : values) {
		fout << val << " ";
	}
}
