#include "mesh.h"
#include <iostream>

int main() {

	std::string loadPath = "C:\\Users\\lenovo\\Desktop\\Mesh\\geometry_files_pack\\res.msh";
	std::string savePath = "C:\\Users\\lenovo\\Desktop\\Mesh\\geometry_files_pack\\resOfFEM.msh";
	mesh newMesh(loadPath);
	newMesh.saveMesh(savePath);

	return 0;

}