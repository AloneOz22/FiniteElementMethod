#pragma once
class node
{
private:
	int num;
	double x;
	double y;
	double z;
	double value;
public:
	node(int num, double x, double y, double z);
	int get_num();
	double get_x();
	double get_y();
	double get_z();
	double get_value();
};

