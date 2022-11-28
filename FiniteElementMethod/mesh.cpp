#include "mesh.h"

mesh::mesh(std::string path) {
	try {
		std::ifstream file(path);
		std::string helpString;
		do {
			getline(file, helpString);
		} while (helpString != "$Nodes");
		int nodesNum;
		file >> nodesNum;
		for (int i = 0; i < nodesNum; i++) {
			int num;
			double x, y, z;
			file >> num >> x >> y >> z;
			nodes.push_back(node(num, x, y, z));
		}
		for (int i = 0; i < 3; i++) {
			getline(file, helpString);
		}
		int elementsNum;
		file >> elementsNum;
		for (int i = 0; i < elementsNum; i++) {
			int num, type, tag, firstNode, secondNode, thirdNode, fourthNode, helpInt;
			file >> num >> type >> helpInt >> tag >> helpInt;
			switch (type) {
			/*case 15:
				file >> firstNode;
				elements.push_back(element(nodes[firstNode - 1], num, 15, tag));
				break;
			case 1:
				file >> firstNode >> secondNode;
				elements.push_back(element(nodes[firstNode - 1], nodes[secondNode - 1], num, 1, tag));
				break;*/
			case 2:
				num = i;
				file >> firstNode >> secondNode >> thirdNode;
				//elements.push_back(element(nodes[firstNode - 1], nodes[secondNode - 1], nodes[thirdNode - 1], num, 2, tag));
				triangles.push_back(element(nodes[firstNode - 1], nodes[secondNode - 1], nodes[thirdNode - 1], num, 2, tag));
				break;
			case 4:
				num = i;
				file >> firstNode >> secondNode >> thirdNode >> fourthNode;
				elements.push_back(element(nodes[firstNode - 1], nodes[secondNode - 1], nodes[thirdNode - 1], nodes[fourthNode - 1], num, 4, tag));
				//tetrahedrons.push_back(elements.back());
				break;
			default:
				//std::cout << "Something in mesh loading is going wrong..." << std::endl;
				getline(file, helpString);
				break;
			}
		}
	}
	catch (std::exception e) {
		std::cout << e.what() << std::endl;
	}
}

node* mesh::get_node_ptr(int index) {
	return &nodes[index];
}

element* mesh::get_element_ptr(int index) {
	return &elements[index];
}

void mesh::save_mesh(std::string path) {
	try {
		std::ofstream file(path);
		file << "$MeshFormat" << std::endl;
		file << 2.2 << " " << 0 << " " << 8 << " " << std::endl;
		file << "$EndMeshFormat" << std::endl;
		file << "$Nodes" << std::endl;
		file << nodes.size() << std::endl;
		for (int i = 0; i < nodes.size(); i++) {
			file << nodes[i].get_num() << " " << nodes[i].get_x() << " " << nodes[i].get_y() << " " << nodes[i].get_z() << std::endl;
		}
		file << "$EndNodes" << std::endl;
		file << "$Elements" << std::endl;
		file << elements.size() << std::endl;
		for (int i = 0; i < elements.size(); i++) {
			switch (elements[i].get_type())
			{
			case 15:
				file << elements[i].get_num() << " " << elements[i].get_type() << " " << 2 << " " << elements[i].get_tag() << " " << 
					elements[i].get_tag() << " " << elements[i].get_first_node_ptr()->get_num() << std::endl;
				break;
			case 1:
				file << elements[i].get_num() << " " << elements[i].get_type() << " " << 2 << " " << elements[i].get_tag() << " " <<
					elements[i].get_tag() << " " << elements[i].get_first_node_ptr()->get_num() << " " << elements[i].get_second_node_ptr()->get_num() << 
					std::endl;
				break;
			case 2:
				file << elements[i].get_num() << " " << elements[i].get_type() << " " << 2 << " " << elements[i].get_tag() << " " <<
					elements[i].get_tag() << " " << elements[i].get_first_node_ptr()->get_num() << " " << elements[i].get_second_node_ptr()->get_num() <<
					" " << elements[i].get_third_node_ptr()->get_num() << std::endl;
				break;
			case 4:
				file << elements[i].get_num() << " " << elements[i].get_type() << " " << 2 << " " << elements[i].get_tag() << " " <<
					elements[i].get_tag() << " " << elements[i].get_first_node_ptr()->get_num() << " " << elements[i].get_second_node_ptr()->get_num() << 
					" " << elements[i].get_third_node_ptr()->get_num() << " " << elements[i].get_fourth_node_ptr()->get_num() << std::endl;
				break;
			default:
				file << "There is something wrong..." << std::endl;
				break;
			}
		}
		file << "$EndElements" << std::endl;
		file.close();
	}
	catch (std::exception e) {
		std::cout << e.what() << std::endl;
	}
}
