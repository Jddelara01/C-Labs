//John Darren De Lara - x00072126
#pragma once

#include <iostream>
#include <string>

using namespace std;

class BinaryTree {
private:
	struct treeNode {
		char data;
		treeNode *leftPtr;
		treeNode *rightPtr;
	};
	treeNode *root;

	void addPrivate(char data, treeNode *nodePtr) {
		if (root == NULL) 
		{
			root = CreateLeaf(data);
		}
		else if (data < nodePtr->data)
		{
			if (nodePtr->leftPtr != NULL) {
				addPrivate(data, nodePtr->leftPtr);
			}
			else
			{
				nodePtr->leftPtr = CreateLeaf(data);
			}
		}
		else if (data > nodePtr->data)
		{
			if (nodePtr->rightPtr != NULL) {
				addPrivate(data, nodePtr->rightPtr);
			}
			else
			{
				nodePtr->rightPtr = CreateLeaf(data);
			}
		}
		else 
		{
			cout << "The data " << data << " has already been added to the tree" << endl;
		}

	}

	int height(treeNode *count)
	{
		if (count == NULL)
		{
			return -1;
		}

		int left = height(count->leftPtr);
		int right = height(count->rightPtr);

		if (left > right) 
		{
			return 1 + left;
		}
		else
		{
			return 1 + right;
		}
	}

	//use the method if the data type is char
	bool searchNode(char data, treeNode *tnPtr)
	{
		if (tnPtr->data == data)
		{
			cout << "true" << endl;
			return true;
		}
		else
		{
			cout << "false" << endl;
			return false;
		} 

	}

	//to print all the tree values in ascending order
	//using a in-order traversal
	void printInOrder(treeNode *nodePtr) 
	{
		if (root != NULL)
		{
			if (nodePtr->leftPtr != NULL)
			{
				printInOrder(nodePtr->leftPtr);
			}
			cout << nodePtr->data << " " << endl;
			if (nodePtr->rightPtr != NULL)
			{
				printInOrder(nodePtr->rightPtr);
			}
		}
		else 
		{
			cout << "Tree is empty..." << endl;
		}
	}

public:
	BinaryTree() {
		root = NULL;
	}

	treeNode *CreateLeaf(char data)
	{
		treeNode *tn = new treeNode;
		tn->data = data;
		tn->leftPtr = NULL;
		tn->rightPtr = NULL;

		return tn;
	}

	void add(char data) {
		addPrivate(data, root);
	}

	int height() {
		return height(root);
	}

	//use the method if the data type is char
	bool searchNode(char data) {
		return searchNode(data, root);
	}

	//to print all the tree values in ascending order
	//it is using a in-order traversal
	void printInOrder() {
		printInOrder(root);
	}
};
