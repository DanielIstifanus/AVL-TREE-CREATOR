#include <iostream>
#include "Header.h"
using namespace std;
int main()
{
	//Defining the AVL and calling the insert function to add values to the AVL tree
	AVL T;
	T.insert(6);
	T.insert(27);
	T.insert(10);
	T.insert(3);
	T.insert(1);
	T.insert(4);
	T.insert(112);
	T.insert(35);
	T.insert(65);
	T.insert(45);
	T.insert(30);
	T.insert(75);
	T.insert(90);

	//Calling the postOrder function to display the AVL
	cout << "PostOrder: ";
	T.postOrder();
	cout << endl << endl;

	//Calliing the preOrder function to display the AVL
	cout << "PreOrder: ";
	T.preOrder();
	cout << endl << endl;

	//Calliing the preOrder function to display the AVL
	cout << "InOrder: ";
	T.inOrder();
	cout << endl << endl;


	//Calling the findmin and findmax functions and displaying the minimum and maximum values from the AVL tree
	int x, y;
	x=T.findMin(T.root)->data;
	y = T.findMax(T.root)->data;
	cout << "The minimum from the AVL is " << x << endl << endl;
	cout << "The maximum from the AVL is " << y << endl << endl;

	//Displaying the height of the tree
	cout << "The height of the AVL is: " << T.height(T.root)<<endl << endl;

	//Displaying the balance factor of the tree
	cout << "The balacncing factor of the AVL is: " << T.getBalance(T.root)<<endl << endl;

	//Displaying the parent data of a Node and the ChildCount
	cout << "The parent of the third left node from the root is " << T.parent(T.root->left->left->left)->data << endl << endl;
	cout << "The child count of the second left node from the root is " << T.childCount(T.root->left->left) << endl<<endl;

	//Displaying the root of the AVL tree
	cout << "The root of the the AVL is " << T.root1()->data << endl;
	cout << endl;


	//Using the remove function to remove an integer from the AVL tree
	T.remove(30);
	cout << "The new AVL after 30 is removed is: " << endl;
	T.displayAVL();
	cout << endl;
	cout << endl;

	//Displaying the size of the AVL tree
	cout << "The size of the AVL is " << T.size() << endl;
	cout << endl;


	//Displaying the AVL after using the copy constructor
	AVL D1(T);
	cout << "Using the copy constructor: " << endl;;
	D1.displayAVL();
	cout << endl;
	cout << endl;

	//Displaying the AVL after using the operator overload function(=)
	AVL D2 = T;
	cout << "Using the equals to operator overload function : " << endl;;
	D2.displayAVL();
	cout << endl<<endl;

	bool temp;

	//Checking if a Node is internal
	temp = T.isInternal(T.root->left);
	if (temp == true)
	{
		cout << (T.root->left)->data << " is an internal data." << endl;
	}
	else
	{
		cout << (T.root->left)->data << " is not an internal data."<< endl;
	}
	cout << endl;

	//Checking if a Node is external
	temp = T.isExternal(T.root->right->right->right);
	if (temp == true)
	{
		cout << (T.root->right->right->right)->data << " is an External data." << endl;
	}
	else
	{
		cout << (T.root->right->right->right)->data << " is not an External data." << endl;
	}
	cout << endl;

	//Checking if a Node is a root
	temp = T.isRoot(T.root->right->left);
	if (temp == true)
	{
		cout << (T.root->right->left)->data << " is the root of the AVL." << endl;
	}
	else
	{
		cout << (T.root->right->left)->data << " is not the root of the AVL." << endl;
	}
	cout << endl;

	//Checking if the tree is an AVL
	temp = T.isAVL();
	if (temp == true)
	{
		cout << "The tree is an AVL." << endl;
	}
	else
	{
		cout << "The tree is not an AVL." << endl;
	}
	cout << endl;


	//Checking if a Tree is complete
	temp = T.isComplete();
	if (temp == true)
	{
		cout << "The AVL is complete." << endl;
	}
	else
	{
		cout << "The AVL is not complete." << endl;
	}
	cout << endl;


	//Checking if a Tree is full
	temp = T.isFull();
	if (temp == true)
	{
		cout << "The AVL is full." << endl;
	}
	else
	{
		cout << "The AVL is not full." << endl;
	}
	cout << endl;


	//Finding a integer from the AVL tree
	int r = 35;
	temp = T.search(T.root,r);
	if (temp == true)
	{
		cout <<r<< " was found in the AVL." << endl;
	}
	else
	{
		cout <<r<< " was not found in the AVL." << endl;
	}
	cout << endl;



	system("pause");
	return 0;

}