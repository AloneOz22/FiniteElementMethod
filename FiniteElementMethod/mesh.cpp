#include "mesh.h"

mesh::mesh(std::string path) {
	try {
		std::ifstream file(path);
		std::string helpString;
		for (int i = 0; i < 5; i++) {
			getline(file, helpString);
		}
		int nodesNum = stoi(helpString);
		for (int i = 0; i < nodesNum; i++) {
			int num;
			double x, y, z;
			file >> num >> x >> y >> z;
			nodes.push_back(node(num, x, y, z));
		}
		for (int i = 0; i < 4; i++) {
			getline(file, helpString);
		}
		int elementsNum = stoi(helpString);
		for (int i = 0; i < elementsNum; i++) {
			int num, type, tag, firstNode, secondNode, thirdNode, fourthNode, helpInt;
			file >> num >> type >> helpInt >> tag >> helpInt;
			switch (type) {
			case 15:
				file >> firstNode;
				elements.push_back(element(nodes[firstNode - 1], num, 15, tag));
				break;
			case 1:
				file >> firstNode >> secondNode;
				elements.push_back(element(nodes[firstNode - 1], nodes[secondNode - 1], num, 1, tag));
				break;
			case 2:
				file >> firstNode >> secondNode >> thirdNode;
				elements.push_back(element(nodes[firstNode - 1], nodes[secondNode - 1], nodes[thirdNode - 1], num, 2, tag));
				break;
			case 4:
				file >> firstNode >> secondNode >> thirdNode >> fourthNode;
				elements.push_back(element(nodes[firstNode - 1], nodes[secondNode - 1], nodes[thirdNode - 1], nodes[fourthNode - 1], num, 4, tag));
				break;
			default:
				std::cout << "Something is going wrong..." << std::endl;
				break;
			}
		}
	}
	catch (std::exception e) {
		std::cout << e.what() << std::endl;
	}
}

node* mesh::getNodePtr(int index) {
	return &nodes[index];
}

element* mesh::getElementPtr(int index) {
	return &elements[index];
}

void mesh::saveMesh(std::string path) {
	try {
		std::ofstream file(path);
		file << "$MeshFormat" << std::endl;
		file << 2.2 << " " << 0 << " " << 8 << " " << std::endl;
		file << "$EndMeshFormat" << std::endl;
		file << "$Nodes" << std::endl;
		file << nodes.size() << std::endl;
		for (int i = 0; i < nodes.size(); i++) {
			file << nodes[i].getNum() << " " << nodes[i].getX() << " " << nodes[i].getY() << " " << nodes[i].getZ() << std::endl;
		}
		file << "$EndNodes" << std::endl;
		file << "$Elements" << std::endl;
		file << elements.size() << std::endl;
		for (int i = 0; i < elements.size(); i++) {
			switch (elements[i].getType())
			{
			case 15:
				file << elements[i].getNum() << " " << elements[i].getType() << " " << 2 << " " << elements[i].getTag() << " " << elements[i].getTag() << " " <<
					elements[i].getFirstNodePtr()->getNum() << std::endl;
				break;
			case 1:
				file << elements[i].getNum() << " " << elements[i].getType() << " " << 2 << " " << elements[i].getTag() << " " << elements[i].getTag() << " " <<
					elements[i].getFirstNodePtr()->getNum() << " " << elements[i].getSecondNodePtr()->getNum() << std::endl;
				break;
			case 2:
				file << elements[i].getNum() << " " << elements[i].getType() << " " << 2 << " " << elements[i].getTag() << " " << elements[i].getTag() << " " <<
					elements[i].getFirstNodePtr()->getNum() << " " << elements[i].getSecondNodePtr()->getNum() << " " << elements[i].getThirdNodePtr()->getNum() << std::endl;
				break;
			case 4:
				file << elements[i].getNum() << " " << elements[i].getType() << " " << 2 << " " << elements[i].getTag() << " " << elements[i].getTag() << " " <<
					elements[i].getFirstNodePtr()->getNum() << " " << elements[i].getSecondNodePtr()->getNum() << " " << elements[i].getThirdNodePtr()->getNum() << " " <<
					elements[i].getFourthNodePtr()->getNum() << std::endl;
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
