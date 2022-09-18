#pragma once
#include "node.h"

class element
{
private:
	node* firstNode;
	node* secondNode;
	node* thirdNode;
	node* fourthNode;
	int num;
	int type;
	int tag;
public:
	element(node& firstNode, node& secondNode, node& thirdNode, node& fourthNode, int num, int type, int tag);
	element(node& firstNode, node& secondNode, node& thirdNode, int num, int type, int tag);
	element(node& firstNode, node& secondNode, int num, int type, int tag);
	element(node& firstNode, int num, int type, int tag);
	node* getFirstNodePtr();
	node* getSecondNodePtr();
	node* getThirdNodePtr();
	node* getFourthNodePtr();
	int getNum();
	int getType();
	int getTag();
};


