#include "mesh.h"
#include "matrix.h"
#include "finite_element_method.h"
#include "sparse_matrix_2.h"
#include "BCG.h"


int main() {
	//std::vector<triplet> arr = std::vector<triplet>(9);
	//std::vector<double> right_part = { 0, 5, 3, 1 };
	//arr[0] = triplet(0, 1, 5);
	//arr[1] = triplet(0, 1, -3);
	//arr[2] = triplet(0, 1, 1);
	//arr[3] = triplet(1, 3, 3);
	//arr[4] = triplet(2, 1, 1);
	//arr[5] = triplet(2, 2, 6);
	//arr[6] = triplet(3, 1, 2);
	//arr[7] = triplet(3, 3, -2);
	//arr[8] = triplet(1, 0, 1);
	//std::vector<std::vector<double>> V = { {0, 3, 0, 0}, {1, 0, 0, 3}, {0, 1, 6, 0}, {0, 2, 0, -2} };
	//triplet_array trips = triplet_array(arr);
	//matrix B = matrix(4, V);
	//sparse_matrix_2 A = sparse_matrix_2(trips, 4);
	////A = A.transpose();
	//auto result_1 = B.inverse() * right_part;
	//auto result_2 = bcg::bcg_method(A, right_part);
	//for (int i = 0; i < result_1.size(); i++) {
	//	std::cout << result_1[i] << " " << result_2[i] << std::endl;
	//	std::cout << result_1[i] << std::endl;
	//}
	mesh msh = mesh("Example.msh");
	sparse_matrix_2 global = finite_element_method::global_matrix(msh);
	global.print("global before.txt");
	std::vector<double> right_part = finite_element_method::right_part(msh, global);
	std::vector<double> result_1 = bcg::bcg_method_2(global, right_part);
	std::vector<double> result_2 = global * result_1;
	vector_for_algebra V1 = vector_for_algebra(result_1);
	vector_for_algebra V2 = vector_for_algebra(result_2);
	std::cout << (vector_for_algebra(right_part) - V2).norm() << std::endl;
	for (int i = 0; i < result_1.size(); i++) {
		std::cout << result_1[i] << " " << right_part[i] << " " << result_2[i] << std::endl;
	}
	std::cout << (vector_for_algebra(right_part) - V2).norm() << std::endl;
	/*vector_for_algebra V1 = vector_for_algebra(result_1);
	vector_for_algebra V2 = vector_for_algebra(result_2);
	std::cout << (V2 - V1).norm() << std::endl;
	for (int i = 0; i < result_1.size(); i++) {
		std::cout << result_1[i] << " " << result_2[i] << std::endl;
	}
	global.print("global after.txt");*/
	return 0;

}