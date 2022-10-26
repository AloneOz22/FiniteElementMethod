#include "finite_element_method.h"

std::vector<double> finite_element_method::local_coeficients(element& local_element) {
	try {
		std::vector<double> result;
		std::vector<std::vector<double>> coordinates;
		std::vector<double> values;
		matrix local;
		switch (local_element.get_type()) {
		case 4:
			result = std::vector<double>(4);
			coordinates = { {1,1,1,1},
				{local_element.get_first_node_ptr()->get_x(), local_element.get_second_node_ptr()->get_x(), local_element.get_third_node_ptr()->get_x(),local_element.get_fourth_node_ptr()->get_x()},
				{local_element.get_first_node_ptr()->get_y(), local_element.get_second_node_ptr()->get_y(), local_element.get_third_node_ptr()->get_y(),local_element.get_fourth_node_ptr()->get_y()},
				{local_element.get_first_node_ptr()->get_z(), local_element.get_second_node_ptr()->get_z(), local_element.get_third_node_ptr()->get_z(),local_element.get_fourth_node_ptr()->get_z()} };
			values = { local_element.get_first_node_ptr()->get_value(),
				local_element.get_second_node_ptr()->get_value(),
				local_element.get_third_node_ptr()->get_value(),
				local_element.get_fourth_node_ptr()->get_value() };
			local = matrix(4, coordinates);
			local = local.transposition();
			result = local.inverse() * values;
			break;
		//case 3:
		//	result = std::vector<double>(3);
		//	coordinates = { {1,1,1},
		//		{local_element.get_first_node_ptr()->get_x(), local_element.get_second_node_ptr()->get_x(), local_element.get_third_node_ptr()->get_x()},
		//		{local_element.get_first_node_ptr()->get_y(), local_element.get_second_node_ptr()->get_y(), local_element.get_third_node_ptr()->get_y()} };
		//	values = { local_element.get_first_node_ptr()->get_value(),
		//		local_element.get_second_node_ptr()->get_value(),
		//		local_element.get_third_node_ptr()->get_value() };
		//	local = matrix(3, coordinates);
		//	local = local.transposition();
		//	result = local.inverse() * values;
		//	break;
		default:
			std::cout << "Something in local_matrix is going wrong..." << std::endl;
			break;
		}
		return result;
	}
	catch (std::exception e) {
		std::cout << e.what() << std::endl;
		return std::vector<double>{0};
	}
}

matrix finite_element_method::form_matrix(element& local_element) {
	try {
		std::vector<std::vector<double>> coordinates;
		matrix result;
		switch (local_element.get_type()) {
		case 4:
			coordinates = { {1,1,1,1},
				{local_element.get_first_node_ptr()->get_x(), local_element.get_second_node_ptr()->get_x(), local_element.get_third_node_ptr()->get_x(),local_element.get_fourth_node_ptr()->get_x()},
				{local_element.get_first_node_ptr()->get_y(), local_element.get_second_node_ptr()->get_y(), local_element.get_third_node_ptr()->get_y(),local_element.get_fourth_node_ptr()->get_y()},
				{local_element.get_first_node_ptr()->get_z(), local_element.get_second_node_ptr()->get_z(), local_element.get_third_node_ptr()->get_z(),local_element.get_fourth_node_ptr()->get_z()} };
			result = matrix(4, coordinates).transposition().inverse();
			break;
		//case 3:
			//coordinates = { {1,1,1},
			//	{local_element.get_first_node_ptr()->get_x(), local_element.get_second_node_ptr()->get_x(), local_element.get_third_node_ptr()->get_x()},
			//	{local_element.get_first_node_ptr()->get_y(), local_element.get_second_node_ptr()->get_y(), local_element.get_third_node_ptr()->get_y()} };
			//result = matrix(3, coordinates).transposition().inverse();
			//break;
		default:
			std::cout << "Something in form_functions is going wrong..." << std::endl;
			break;
		}
		return result;
	}
	catch (std::exception e) {
		std::cout << e.what() << std::endl;
		return matrix(1);
	}
}

double finite_element_method::element_characteristic(element& local_element) {
	try {
		std::vector<std::vector<double>> coordinates;
		matrix characteristic;
		double result = 0;
		switch (local_element.get_type()) {
		case 4:
			coordinates = { {1,1,1,1},
				{local_element.get_first_node_ptr()->get_x(), local_element.get_second_node_ptr()->get_x(), local_element.get_third_node_ptr()->get_x(),local_element.get_fourth_node_ptr()->get_x()},
				{local_element.get_first_node_ptr()->get_y(), local_element.get_second_node_ptr()->get_y(), local_element.get_third_node_ptr()->get_y(),local_element.get_fourth_node_ptr()->get_y()},
				{local_element.get_first_node_ptr()->get_z(), local_element.get_second_node_ptr()->get_z(), local_element.get_third_node_ptr()->get_z(),local_element.get_fourth_node_ptr()->get_z()} };
			characteristic = matrix(4, coordinates);
			result = characteristic.determinant() / 3;
			break;
		//case 3:
		//	coordinates = { {1,1,1},
		//		{local_element.get_first_node_ptr()->get_x(), local_element.get_second_node_ptr()->get_x(), local_element.get_third_node_ptr()->get_x()},
		//		{local_element.get_first_node_ptr()->get_y(), local_element.get_second_node_ptr()->get_y(), local_element.get_third_node_ptr()->get_y()} };
		//	characteristic = matrix(3, coordinates);
		//	result = characteristic.determinant();
		//	break;
		default:
			std::cout << "Something in form_functions is going wrong..." << std::endl;
			break;
		}
		return result;
	}
	catch (std::exception e) {
		std::cout << e.what() << std::endl;
		return -1;
	}
}

std::vector<double> finite_element_method::form_functions(element& local_element, double x, double y, double z) {
	try {
		matrix form = form_matrix(local_element);
		std::vector<double> result;
		switch (local_element.get_type()) {
		case 4:
			result = std::vector<double>(4);
			for (int i = 0; i < 4; i++) {
				result[i] = form.get_value(i, 0) + form.get_value(i, 1) * x + form.get_value(i, 2) * y + form.get_value(i, 3) * z;
			}
			break;
		default:
			std::cout << "Something in form_functions is going wrong...";
			break;
		}
		return result;
	}
	catch (std::exception e) {
		std::cout << e.what() << std::endl;
		return std::vector<double>(0);
	}
}

matrix finite_element_method::form_gradient(element& local_element) {
	try {
		matrix form = form_matrix(local_element);
		matrix result;
		switch (local_element.get_type()) {
		case 4:
			result = matrix(4, 3);
			for (int i = 0; i < 4; i++) {
				result.set_value(i, 0, form.get_value(i, 1));
				result.set_value(i, 1, form.get_value(i, 2));
				result.set_value(i, 2, form.get_value(i, 3));
			}
			break;
		default:
			std::cout << "Something in form_gradient is going wrong...";
			break;
		}
		return result;
	}
	catch (std::exception e) {
		std::cout << e.what() << std::endl;
		return matrix(1);
	}
}

double finite_element_method::scalar_product(std::vector<double> first, std::vector<double> second) {
	try {
		double result = 0;
		for (int i = 0; i < first.size(); i++) {
			result += first[i] * second[i];
		}
		return result;
	}
	catch (std::exception e) {
		std::cout << e.what() << std::endl;
		return -1;
	}
}

matrix finite_element_method::local_c_matrix(element& local_element) {
	try {
		double volume = element_characteristic(local_element);
		matrix grad = form_gradient(local_element);
		matrix result = matrix::zero(4);
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				result.set_value(i, j, fabs(element_characteristic(local_element)) * scalar_product(grad.get_vector(i), grad.get_vector(j)));
			}
		}
	}
	catch (std::exception e) {
		std::cout << e.what() << std::endl;
		return -1;
	}
}
