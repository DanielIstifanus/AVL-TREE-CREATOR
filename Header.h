#pragma once
#include <iostream>
using namespace std;
class AVL { //public or private: you should decide

public:
	struct Node {
		int data;
		Node* left;
		Node* right;
		int height;

	};
	Node* root;
	
	Node* findMin(Node*);
	Node* findMax(Node*);
	Node* remove(int, Node*);
	int height(Node*);
	int getBalance(Node*);
	Node* parent(Node*);
	int childCount(Node*); 
	bool isRoot(Node*);
	bool isInternal(Node*);
	bool isExternal(Node*);
	bool search(Node*, int);
	int size();
	void inOrder();
	void postOrder();
	void preOrder();
	AVL();
	~AVL();
	void makeRoot(Node *);
	AVL(const AVL&);
	AVL& operator=(const AVL&);
	Node* root1();
	bool isFull();
	bool isComplete();
	bool isAVL();
	void insert(int);
	void remove(int);
	void displayAVL();

private:
	Node* insert(int, Node*);
	Node* singleRightRotate(Node*&);
	Node* singleLeftRotate(Node*&);
	Node* doubleLeftRightRotate(Node*&);
	Node* doubleRightLeftRotate(Node*&);
	bool findValue(Node*, int);
	Node* getParent(Node*, Node*, Node*);
	void displayNode(Node*);
	void makePost(Node *);
	void makePre(Node *);
	void makeIn(Node *N);
	int max(int, int);
	void clearAVL(Node* );
	void copyAVL(const Node*);
	bool completeChecker(Node*, int, int);
	int sizeCounter(Node*);
	bool fullChecker(Node*);
};
