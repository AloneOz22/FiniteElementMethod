#include "BCG.h"

std::vector<double> bcg::bcg_method(sparse_matrix_2 &global, std::vector<double> &right_part) {
	std::vector<double> x0 = right_part;
	for (auto val : x0) {
		val = 1.1;
	}
	std::vector <double> Ax0 = global * x0;
	vector_for_algebra AX0 = vector_for_algebra(Ax0);
	std::vector<double> r0 = right_part;
	vector_for_algebra R0 = vector_for_algebra(r0);
	vector_for_algebra F = vector_for_algebra(right_part);
	R0 = F - AX0;
	vector_for_algebra R0_ = R0;
	vector_for_algebra P0 = R0;
	vector_for_algebra P0_ = R0_;
	vector_for_algebra Pj = P0;
	vector_for_algebra Pj_ = P0_;
	vector_for_algebra Rj = R0;
	vector_for_algebra Rj_ = R0_;
	vector_for_algebra X0 = vector_for_algebra(x0);
	vector_for_algebra Xj = X0;
	std::vector<double> result = {};
	for (int i = 0; i < 10000; i++) {
		double alpha = (Rj * Rj_) / (vector_for_algebra(global * Pj.V) * Pj_);
		vector_for_algebra next_x = Xj + (Pj * alpha);
		vector_for_algebra next_r = Rj - (vector_for_algebra(global * Pj.V) * alpha);
		vector_for_algebra next_r_ = Rj_ - (vector_for_algebra(global.transpose() * Pj_.V) * alpha);
		double beta = (next_r * next_r_) / (Rj * Rj_);
		if (next_r.norm() <= 0.001 || i ==1999) {
			result = next_x.V;
			std::cout << next_r.norm() << " " << next_r_.norm() << " " << R0.norm() << " " << beta << std::endl;;
			break;
		}
		if (beta < 0.001) {
			std::cout << "Incorrect solve" << std::endl;
			break;
		}
		Pj = next_r + (Pj * beta);
		Pj_ = next_r_ + (Pj_ * beta);
		std::cout << next_r.norm() << " " << i << std::endl;
	}
	return result;
}

std::vector<double> bcg::bcg_method_2(sparse_matrix_2& global, std::vector<double>& right_part) {
	std::vector<double> x0 = right_part;
	for (auto val : x0) {
		val = 1.1;
	}
	std::vector <double> Ax0 = global * x0;
	vector_for_algebra AX0 = vector_for_algebra(Ax0);
	std::vector<double> r0 = right_part;
	vector_for_algebra R0 = vector_for_algebra(r0);
	vector_for_algebra F = vector_for_algebra(right_part);
	R0 = F - AX0;
	vector_for_algebra R = R0;
	vector_for_algebra R_ = R0;
	vector_for_algebra next_R = R0;
	vector_for_algebra next_R_ = R0;
	vector_for_algebra v = vector_for_algebra(right_part);
	vector_for_algebra p = vector_for_algebra(right_part);
	for (int i = 0; i < v.V.size(); i++) {
		v.V[i] = 0;
		p.V[i] = 0;
	}
	double rho = 1;
	double alpha = 1;
	double omega = 1;
	vector_for_algebra X = vector_for_algebra(x0);
	for (int i = 0; i < 2000; i++) {
		double next_rho = (R_ * R);
		double beta = (next_rho * alpha) / (rho * omega);
		vector_for_algebra next_p = R + (p - v * omega) * beta;
		vector_for_algebra next_v = vector_for_algebra(global * next_p.V);
		double next_alpha = next_rho / (R_ * next_v);
		vector_for_algebra s = R - (next_v * next_alpha);
		vector_for_algebra t = vector_for_algebra(global * s.V);
		double next_omega = (t * s) / (t * t);
		vector_for_algebra next_X = X + (s * next_omega) + (next_p * next_alpha);
		next_R = s - (t * next_omega);
		double val = next_R.norm() / F.norm();
		std::cout << val << " " << i << std::endl;
		if (val < 0.0000001) {
			X = next_X;
			std::cout << std::endl;
			break;
		}
		rho = next_rho;
		alpha = next_alpha;
		omega = next_omega;
		v = next_v;
		p = next_p;
		R = next_R;
		X = next_X;
	}
	return X.V;
}