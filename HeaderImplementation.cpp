#include <iostream>
#include "Header.h"
using namespace std;

//Implementing the insert function
AVL::Node*  AVL::insert(int x, Node* t)
{
	if (t == NULL)
	{
		t = new Node;
		t->data = x;
		t->height = 0;
		t->left = NULL;
		t->right = NULL;
	}
	else if (x < t->data)
	{
		t->left = insert(x, t->left);
		if (height(t->left) - height(t->right) == 2)
		{
			if (x < t->left->data)
				t = singleRightRotate(t);
			else
				t = doubleRightLeftRotate(t);
		}
	}
	else if (x > t->data)
	{
		t->right = insert(x, t->right);
		if (height(t->right) - height(t->left) == 2)
		{
			if (x > t->right->data)
				t = singleLeftRotate(t);
			else
				t = doubleLeftRightRotate(t);
		}
	}
	t->height = max(height(t->left), height(t->right)) + 1;
	return t;
}

//Implementing the rotate single right funtion
AVL::Node   *AVL::singleRightRotate(Node*& X)
{
	Node *temp = X->left;
	Node *temp1 = temp->right; 
	temp->right = X;
	X->left = temp1;
	X->height = max(height(X->left),height(X->right)) + 1;
	temp->height = max(height(temp->left),height(temp->right)) + 1;
	return temp;
}

//Implementing the find max of 2 interger function
int AVL::max(int a, int b)
{
	return (a > b) ? a : b;
}

//Implementing the rotate single left funtion
AVL::Node* AVL::singleLeftRotate(Node*& X)
{
	Node *temp = X->right;
	Node *temp1 = temp->left;
	temp->left = X;
	X->right = temp1;
	X->height = max(height(X->left), height(X->right)) + 1;
	temp->height = max(height(temp->left), height(temp->right)) + 1;
	return temp;
}


//Implementing the rotate double left funtion
AVL::Node* AVL::doubleLeftRightRotate(Node*& N)
{
	N->right = singleRightRotate(N->right);
	return singleLeftRotate(N);
}


//Implementing the rotate double right funtion
AVL::Node* AVL::doubleRightLeftRotate(Node*& N)
{
	N->left = singleLeftRotate(N->left);
	return singleRightRotate(N);
}

//Implementing the findMin of the AVL tree function
AVL::Node* AVL::findMin(Node*N)
{
	if (N == NULL)
		return NULL;
	else if (N->left == NULL)
		return N;
	else
		return findMin(N->left);
}


//Implementing the findMax of the AVL tree function
AVL::Node*  AVL::findMax(Node* N)
{
	if (N == NULL)
		return NULL;
	else if (N->right == NULL)
		return N;
	else
		return findMax(N->right);
}


//Implementing the remove integer from the AVL tree function
AVL::Node*  AVL::remove(int Y, Node* X)
{
	Node* temp;
	if (X== NULL)
		return NULL;
	else if (Y < X->data)
		X->left = remove(Y, X->left);
	else if (Y > X->data)
		X->right = remove(Y, X->right);
	else if (X->left && X->right)
	{
		temp = findMin(X->right);
		X->data = temp->data;
		X->right = remove(X->data, X->right);
	}
	else
	{
		temp = X;
		if (X->left == NULL)
			X = X->right;
		else if (X->right == NULL)
			X= X->left;
		delete temp;
	}
	if (X == NULL)
		return X;
	X->height = max(height(X->left), height(X->right)) + 1;
	if (height(X->left) - height(X->right) == 2)
	{
		if (height(X->left->left) - height(X->left->right) == 1)
			return singleLeftRotate(X);
		else
			return doubleLeftRightRotate(X);
	}
	else if (height(X->right) - height(X->left) == 2)
	{
		if (height(X->right->right) - height(X->right->left) == 1)
			return singleRightRotate(X);
		else
			return doubleRightLeftRotate(X);
	}
	return X;
}


//Implementing the function to return the height of AVL tree
int  AVL::height(Node* N)
{
	if (!N)
		return 0;
	return N->height;
}


//Implementing the function to return the balance of AVL tree
int  AVL::getBalance(Node* N)
{
	if (N==NULL)
		return 0;
	return height(N->left) - height(N->right);
}


//Implementing the function to return Parent of a Node
AVL::Node* AVL::parent(Node* N)
{
	return getParent(this->root, N, NULL);
}



//Implementing a function to return the Parent to the Parent function
AVL::Node* AVL::getParent(Node* A, Node* B, Node* C)
{	
	if (A== NULL)
	{
		return NULL;
	}
	if (A->data == B->data)
	{
		return C;
	}
	else
	{
		Node* temp = getParent(A->left, B, A);
		if (temp != NULL)
			return temp;
		Node* temp1 = getParent(A->right, B, A);
		if (temp1 != NULL)
			return temp1;
		return NULL;
	}
}


//Implementing the function to return the child count of a node
int AVL::childCount(Node* N)
{
	if (N == NULL)
		return 0;
	else
		return childCount(N->left) +1+ childCount(N->right);
}


//Implementing a function to check if a Node is the root
bool AVL::isRoot(Node* N)
{	
	if (N->data == this->root->data)
		return true;
	else
		return false;
}

//Implementing a function to heck if a Node is internal
bool  AVL::isInternal(Node* N)
{
	if (N->left != NULL || N->right != NULL)
		return true;
	else
		return false;

}



//Implementing a function to check if a Node is external
bool  AVL::isExternal(Node* N)
{
	if (N->left != NULL || N->right != NULL)
		return false;
	else
		return true;
}



//Function that is being called in the Search function that recursively searched the AVL for the integer
bool AVL::findValue(Node* N, int t)
{
	if (N == NULL)
		return false;
	if (N->data == t)
	{
		return true;
	}
	else
	{
	    findValue(N->left, t);
		findValue(N->right, t);
	}
}

//bool function to Seaarch if an integer is in the AVL 
bool  AVL::search(Node* N, int t)
{
	 return findValue(N, t);

}
int AVL::sizeCounter(Node* N)
{
	if (N == NULL)
		return 0;
	else
		return sizeCounter(N->left) +1+ sizeCounter(N->right);
}

//Implementing a function to find the size of an AVL tree
int  AVL::size()
{
	return sizeCounter(this->root) ;
}

//Function called in the postorder function that prints the data of the AVL recurvisively
void AVL::makePost(Node *N)
{
	if (N == NULL)
		return;
	makePost(N->left);
	makePost(N->right);
	cout << N->data<<"	";
}
void  AVL::postOrder()
{
	makePost(this->root);
}


//Function called in the preorder function that prints the data of the AVL recurvisively
void AVL::makePre(Node *N)
{
	if (N == NULL)
		return;
	cout << N->data << "	";
	makePre(N->left);
	makePre(N->right);

}


//Function called in the inorder function that prints the data of the AVL recurvisively
void AVL::makeIn(Node *N)
{
	if (N == NULL)
		return;

	makeIn(N->left);
	cout << N->data << "	";
	makeIn(N->right);

}

//InOrder Function
void  AVL::inOrder()
{
	makeIn(this->root);
}

//PreOrder function
void  AVL::preOrder()
{
	makePre(this->root);
}

//Default constructor
AVL::AVL ()
{
	this->root = NULL;

}

//Destructor Implementation
AVL::~AVL ()
{
	clearAVL(this->root);
	delete root;
	root = NULL;
}

//Copy constructor
AVL::AVL (const AVL& N)
{
	this->root = N.root;
	this->root->height = N.root->height;
	this->root->left = N.root->left;
	this->root->right = N.root->right;
	
}

//FUnction that makes a node the root
void AVL::makeRoot(Node * N)
{
	this->root = N;
}

//Copy function that copys each data of the root to the AVL 
void AVL::copyAVL(const Node* N)
{
	if (N == NULL)
		return;
	this->insert(N->data);

	copyAVL(N->left);

	copyAVL(N->right);

}


//Recursive void function that is called in the destrucor to delete nodes
void AVL::clearAVL(Node* N)
{

	if (N!=NULL)

	{

		clearAVL(N->left);

		clearAVL(N->right);

		delete N;

	}
}

//Implementing the equals to overload function
 AVL&  AVL::operator=(const AVL& N)
{
	 this->root = N.root;
	 this->root->height = N.root->height;
	 this->root->left = N.root->left;
	 this->root->right = N.root->right;
	 return *this;
	 
}


 //Function that returns the root of an AVL tree
AVL::Node* AVL::root1()
{
	return this->root;
}

bool AVL::fullChecker(Node* N)
{
	if (N == NULL)
		return true;
	if (N->left == NULL && N->right == NULL)
		return true;
	if ((N->left) && (N->right))
		return (fullChecker(N->left) && fullChecker(N->right));
	return false;
}


//Implementing function to check if a function is Full
bool  AVL::isFull()
{
	return fullChecker(this->root);
}

//Bool function that checks if an AVL is complee recursively
bool AVL::completeChecker(Node* N,  int x, int y)
{
	if (N == NULL)
		return true;
	if (y <= x)
		return false;
	return (completeChecker(N->left, 2 * x + 1, y) && completeChecker(N->right, 2 * x + 2, y));
}


//Function to check if an AVL tree is complete
bool  AVL::isComplete()
{
	return completeChecker(this->root,0,this->size());
}

//Function to check if a tree is an AVL
bool AVL::isAVL()
{
	if (getBalance(this->root) == 0|| getBalance(this->root) == abs(1))

		return true;

	else

		return false;

}

//Function that inserts integer to an AVL but takes only integer argument
void  AVL::insert(int x)
{
	this->root = insert(x, this->root);
}


//Function that removes integer to an AVL but takes only integer argument
void  AVL::remove(int x)
{
	this->root = remove(x, this->root);
}

//A display function that calls the call the function that actually does the printing
void AVL::displayAVL()
{
	displayNode(this->root);
}


//Display function to print the AVL tree data
void AVL::displayNode(Node* N)
{
	if (N == NULL)
		return;
	cout << N->data << "	";
	displayNode(N->left);
	displayNode(N->right);
}

