//John Darren De Lara - X00072126		LAB4B

/*Reference:
https://www.youtube.com/watch?v=COZK7NATh4k
https://www.youtube.com/watch?v=Ut90klNN264
https://www.youtube.com/watch?v=yEwSGhSsT0U
*/

#include <iostream>
#include <string>

using namespace std;

//template <typename T>
struct treeNode {
	int data;
	treeNode *leftPtr;
	treeNode *rightPtr;
};

treeNode *GetNewNode(int data) {
	treeNode *newNode = new treeNode();
	newNode->data = data;
	newNode->leftPtr = newNode->rightPtr = NULL;
	return newNode;
}

treeNode *Insert(treeNode *root, int data) {
	if (root == NULL)
	{
		root = GetNewNode(data);
	}
	else if (data <= root->data)
	{
		root->leftPtr = Insert(root->leftPtr, data);
	}
	else
	{
		root->rightPtr = Insert(root->rightPtr, data);
	}
	return root;
}
//to get the min value, have to loop down the leftmost leaf
int minValue(treeNode* node) {	treeNode *current = node;	while (current->leftPtr != NULL)	{		current = current->leftPtr;	}	return(current->data);}
int maxValue(treeNode* node) {
	treeNode *current = node;	while (current->rightPtr != NULL)	{		current = current->rightPtr;	}	return(current->data);
}

int isBst(treeNode *node) {
	if (node == NULL)
		return 1;

	//false if min value in the right subtree is greater than the rootnode
	if (node->rightPtr != NULL && minValue(node->rightPtr) < node->data)
		return 0;

	//false if max value in the left subtree is less than the rootnode
	if(node->leftPtr != NULL && maxValue(node->leftPtr) > node->data)
		return 0;

	//false if, the left or right is not a BST
	if (!isBst(node->leftPtr) || !isBst(node->rightPtr))
		return 0;

	//if it does not fall under one if the false statement, it is a BST
	return 1;
}

int isBSTRecur(treeNode* node, int min, int max) {
	if (node == NULL)
		return 1;
	//false if node is < min or > max
	if (node->data < min || node->data > max)
		return 0;

	//recursively call the isBSTRecur to narrow down
	//the min and max values, looking at eeach node only once
	return
		isBSTRecur(node->leftPtr, min, node->data - 1) &&
		isBSTRecur(node->rightPtr, node->data + 1, max);
}

int isBST2(treeNode* node) {
	return(isBSTRecur(node, INT_MIN, INT_MAX));
}

int main()
{
	//Q1
	treeNode *rootPtr = NULL;
	rootPtr = Insert(rootPtr, 5);
	rootPtr = Insert(rootPtr, 2);
	rootPtr = Insert(rootPtr, 7);
	rootPtr = Insert(rootPtr, 1);
	rootPtr = Insert(rootPtr, 6);

	cout << "Part 1..." << endl;
	cout << "The mininum number is " << minValue(rootPtr) << endl;
	cout << "The maximum number is " << maxValue(rootPtr) << endl;
	cout << " " << endl;

	//Q2
	cout << "Part 2..." << endl;

	treeNode *root = GetNewNode(5);
	root->leftPtr = GetNewNode(2);
	root->rightPtr = GetNewNode(7);
	root->leftPtr->leftPtr = GetNewNode(1);
	root->leftPtr->rightPtr = GetNewNode(6);

	if (isBst(root))
	{
		cout << "It is a Binary Search Tree " << endl;
	}
	else
	{
		cout << "It is not a Binary Search Tree " << endl;
	}

	if (isBST2(root))
	{
		cout << "It is a Binary Search Tree " << endl;
	}
	else
	{
		cout << "It is not a Binary Search Tree " << endl;
	}

	system("pause");
	return 0;
}