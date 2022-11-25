#include "vector_for_algebra.h"

vector_for_algebra::vector_for_algebra() {
	this->V = std::vector<double>{};
}
vector_for_algebra::vector_for_algebra(std::vector<double> vec) {
	this->V = vec;
}
vector_for_algebra vector_for_algebra::operator +(vector_for_algebra V2) {
	if (this->V.size() != V2.V.size()) {
		throw std::exception("Error in vector! Dims are not equal!");
	}
	std::vector<double> result = this->V;
	for (int i = 0; i < result.size(); i++) {
		result[i] += V2.V[i];
	}
	return vector_for_algebra(result);
}
vector_for_algebra vector_for_algebra::operator -(vector_for_algebra V2) {
	if (this->V.size() != V2.V.size()) {
		throw std::exception("Error in vector! Dims are not equal!");
	}
	std::vector<double> result = this->V;
	for (int i = 0; i < result.size(); i++) {
		result[i] -= V2.V[i];
	}
	return vector_for_algebra(result);
}
vector_for_algebra vector_for_algebra::operator *(double value) {
	std::vector<double> result = this->V;
	for (int i = 0; i < result.size(); i++) {
		result[i] *= value;
	}
	return vector_for_algebra(result);
}
double vector_for_algebra::operator *(vector_for_algebra V2) {
	if (this->V.size() != V2.V.size()) {
		throw std::exception("Error in vector! Dims are not equal!");
	}
	double result = 0;
	for (int i = 0; i < this->V.size(); i++) {
		result += this->V[i] * V2.V[i];
	}
	return result;
}
double vector_for_algebra::norm() {
	double result = 0;
	for (auto val : V) {
		result += val * val;
	}
	result = std::sqrt(result);
	return result;
}
void vector_for_algebra::normalising() {
	double norm_val = this->norm();
	if (norm_val < 0.0001) {
		throw std::exception("Error in normalising! ||V|| < 0!");
	}
	for (auto val : V) {
		val /= norm_val;
	}
}
