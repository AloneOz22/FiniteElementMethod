#include "finite_element_method.h"

std::vector<double> finite_element_method::local_matrix(element& local_element) {
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
		case 3:
			result = std::vector<double>(3);
			coordinates = { {1,1,1},
				{local_element.get_first_node_ptr()->get_x(), local_element.get_second_node_ptr()->get_x(), local_element.get_third_node_ptr()->get_x()},
				{local_element.get_first_node_ptr()->get_y(), local_element.get_second_node_ptr()->get_y(), local_element.get_third_node_ptr()->get_y()} };
			values = { local_element.get_first_node_ptr()->get_value(),
				local_element.get_second_node_ptr()->get_value(),
				local_element.get_third_node_ptr()->get_value() };
			local = matrix(3, coordinates);
			local = local.transposition();
			result = local.inverse() * values;
			break;
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

matrix finite_element_method::form_functions(element& local_element) {
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
		case 3:
			coordinates = { {1,1,1},
				{local_element.get_first_node_ptr()->get_x(), local_element.get_second_node_ptr()->get_x(), local_element.get_third_node_ptr()->get_x()},
				{local_element.get_first_node_ptr()->get_y(), local_element.get_second_node_ptr()->get_y(), local_element.get_third_node_ptr()->get_y()} };
			result = matrix(3, coordinates).transposition().inverse();
			break;
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
