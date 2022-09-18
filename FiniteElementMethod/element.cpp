#include "element.h"

element::element(node& firstNode, node& secondNode, node& thirdNode, node& fourthNode, int num, int type, int tag) {
	this->firstNode = &firstNode;
	this->secondNode = &secondNode;
	this->thirdNode = &thirdNode;
	this->fourthNode = &fourthNode;
	this->num = num;
	this->type = type;
	this->tag = tag;
}

element::element(node& firstNode, node& secondNode, node& thirdNode, int num, int type, int tag) {
	this->firstNode = &firstNode;
	this->secondNode = &secondNode;
	this->thirdNode = &thirdNode;
	this->fourthNode = nullptr;
	this->num = num;
	this->type = type;
	this->tag = tag;
}

element::element(node& firstNode, node& secondNode, int num, int type, int tag) {
	this->firstNode = &firstNode;
	this->secondNode = &secondNode;
	this->thirdNode = nullptr;
	this->fourthNode = nullptr;
	this->num = num;
	this->type = type;
	this->tag = tag;
}

element::element(node& firstNode, int num, int type, int tag) {
	this->firstNode = &firstNode;
	this->secondNode = nullptr;
	this->thirdNode = nullptr;
	this->fourthNode = nullptr;
	this->num = num;
	this->type = type;
	this->tag = tag;
}

node* element::getFirstNodePtr() {
	return firstNode;
}

node* element::getSecondNodePtr() {
	return secondNode;
}

node* element::getThirdNodePtr() {
	return thirdNode;
}

node* element::getFourthNodePtr() {
	return fourthNode;
}

int element::getNum() {
	return num;
}

int element::getType() {
	return type;
}

int element::getTag() {
	return tag;
}
