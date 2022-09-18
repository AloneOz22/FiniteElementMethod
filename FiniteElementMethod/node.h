#pragma once
class node
{
private:
	int num;
	long double x;
	long double y;
	long double z;
public:
	node(int num, long double x, long double y, long double z);
	int getNum();
	long double getX();
	long double getY();
	long double getZ();
};

