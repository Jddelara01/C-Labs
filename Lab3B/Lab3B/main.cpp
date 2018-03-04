//John Darren De Lara - X00072126	Lab3B

/*Reference:
https://www.youtube.com/watch?v=sf_9w653xdE&list=PLTxllHdfUq4d-DE16EDkpeb8Z68DU7Z_Q
http://www.cplusplus.com/forum/general/21855/
http://interactivepython.org/runestone/static/pythonds/Trees/TreeTraversals.html
*/

#include <iostream>
#include <string>
//#include "BinaryTree.h"					//comment it out if you will use the template class

using namespace std;

template <class T>
class BinarySearchTree {
private:
	struct treeNode {
		T data;
		treeNode *leftPtr;
		treeNode *rightPtr;
	};
	treeNode *root;

	void addPrivate(T data, treeNode *nodePtr) {
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

	//use the method if the data type is char
	bool searchNode(T data, treeNode *tnPtr)
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
	BinarySearchTree() {
		root = NULL;
	}

	treeNode *CreateLeaf(T data)
	{
		treeNode *tn = new treeNode;
		tn->data = data;
		tn->leftPtr = NULL;
		tn->rightPtr = NULL;

		return tn;
	}

	void add(T data) {
		addPrivate(data, root);
	}

	//use the method if the data type is char
	bool searchNode(T data) {
		return searchNode(data, root);
	}

	//to print all the tree values in ascending order
	//it is using a in-order traversal
	void printInOrder() {
		printInOrder(root);
	}
};

int main() {
	//if the data type in the binary tree class is int
	/*int treeData[5] = { 50, 25, 1, 75, 64 };
	BinaryTree bt;

	for (int i = 0; i < 5; i++) {
		bt.add(treeData[i]);
	}

	cout << bt.height() << endl;*/

	/******************************************************************************/

	//if the data type in the binary tree class is char
	//char treeData[5] = { 'g', 'a', 'z', 'b', 'y'};
	//BinaryTree bt;

	//for (int i = 0; i < 5; i++) {
	//	bt.add(treeData[i]);
	//}

	//cout << bt.height() << endl;

	//bt.searchNode('y');

	//cout << " " << endl;

	////printing all values in the tree in ascending order
	////it is using a in-order traversal
	//bt.printInOrder();

	/******************************************************************************/

	//using the template class
	char treeData[5] = { 'g', 'a', 'z', 'b', 'y'};
	BinarySearchTree<char> bt;

	for (int i = 0; i < 5; i++) {
		bt.add(treeData[i]);
	}

	bt.searchNode('z');

	cout << " " << endl;

	//printing all values in the tree in ascending order
	//it is using a in-order traversal
	bt.printInOrder();

	system("pause");
	return 0;
}