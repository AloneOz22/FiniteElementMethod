#include "BCG.h"

std::vector<double> bcg::bcg_method(sparse_matrix &global, std::vector<double> &right_part) {
	std::vector<double> _x0 = std::vector<double>(right_part.size());
	for (auto x : _x0) {
		x = 1;
	}
	std::vector<double> _r0 = std::vector<double>(right_part.size());
	std::vector<double> _Ax0 = global * _x0;
	for (int i = 0; i < _r0.size(); i++) {
		_r0[i] = right_part[i] - _Ax0[i];
	}
	vector_for_algebra x0 = vector_for_algebra(_x0);
	vector_for_algebra p0 = vector_for_algebra(_r0);
	vector_for_algebra p0_ = vector_for_algebra(_r0);
	vector_for_algebra r0 = vector_for_algebra(_r0);
	vector_for_algebra r0_ = vector_for_algebra(_r0);
	for (int iteration = 0;; iteration++) {
		double alpha = r0.norm() / (vector_for_algebra(global * p0.V) * p0_);
		vector_for_algebra next_x = x0 + (p0 * alpha);
		vector_for_algebra next_r = r0 - (vector_for_algebra(global * p0.V));
		vector_for_algebra next_r_ = r0_ - (vector_for_algebra(global.transpose() * p0_.V));
		double beta = (next_r * next_r_) / (r0 * r0_);
		if (next_r.norm() < 0.001) {
			std::cout << "Done!" << std::endl;
			x0 = next_x;
			break;
		}
		if (beta < 0.000001) {
			std::cout << "Bad solution!";
			break;
		}
		p0 = next_r + p0 * beta;
		p0_ = next_r_ + p0_ * beta;
		r0 = next_r;
		r0_ = next_r_;
		x0 = next_x;
	}
	return x0.V;
}