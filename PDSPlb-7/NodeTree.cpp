#include "NodeTree.h"
BinaryTree::BinaryTree() {
	head = nullptr;
}

bool BinaryTree::checkEmpty(Node* item)
{
	return item == nullptr;
}


string BinaryTree::UpDown(Node* item) {
	string answer = "";
	if (checkEmpty(item)) return answer;
	if (!checkEmpty(item)) {
		answer += to_string(item->value) + "|";
	}
	if (!checkEmpty(item->LeftNode)) {
		answer += UpDown(item->LeftNode);
	}
	if (!checkEmpty(item->RightNode)) {
		answer += UpDown(item->RightNode);
	}
	return answer;
}

string BinaryTree::DownUp(Node* item) {
	string answer = "";
	if (checkEmpty(item)) return answer;
	if (!checkEmpty(item->LeftNode)) {
		answer += DownUp(item->LeftNode);
	}
	if (!checkEmpty(item->RightNode)) {
		answer += DownUp(item->RightNode);
	}
	if (!checkEmpty(item)) {
		answer += to_string(item->value) + "|";
	}
	return answer;
}

string BinaryTree::LeftRight(Node* item) {
	string answer = "";
	if (checkEmpty(item)) return "";
	if (!checkEmpty(item->LeftNode)) {
		answer += LeftRight(item->LeftNode);
	}
	if (!checkEmpty(item)) {
		answer += to_string(item->value) + "|";
	}
	if (!checkEmpty(item->RightNode)) {
		answer += LeftRight(item->RightNode);
	}
	return answer;
}

void BinaryTree::AddNew(Node* item, int value) {
	head = AddNewRecursive(item, value);
}


BinaryTree::Node* BinaryTree::AddNewRecursive(Node* item, int value) {
	if (item == nullptr) {
		return new Node(value);
	}

	if (value < item->value) {
		item->LeftNode = AddNewRecursive(item->LeftNode, value);
	}
	else if (value > item->value) {
		item->RightNode = AddNewRecursive(item->RightNode, value);
	}

	return item;
}

void BinaryTree::DellTree(Node* item) {
	if (checkEmpty(item)) return;
	if (!checkEmpty(item->LeftNode)) {
		DellTree(item->LeftNode);
		item->LeftNode = nullptr;
	}
	if (!checkEmpty(item->RightNode)) {
		DellTree(item->RightNode);
		item->RightNode = nullptr;
	}
	if (item = head) {
		head = nullptr;
	}
}