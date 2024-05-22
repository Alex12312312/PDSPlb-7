#pragma once
#include "string"
using namespace std;

class BinaryTree {	
public:
	struct Node {
		Node* LeftNode;
		Node* RightNode;
		int value;
		Node(int data) : value(data), LeftNode(nullptr), RightNode(nullptr) {};
	};
	BinaryTree();
	Node* head;
	bool checkEmpty(Node*);
	void AddNew(Node*, int);
	Node* AddNewRecursive(Node*, int);
	string UpDown(Node*);
	string DownUp(Node*);
	string LeftRight(Node*);
	void DellTree(Node*);
};