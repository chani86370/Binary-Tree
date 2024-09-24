#pragma once
#include <iostream>
#include "QueueVector.h"
using namespace std;

//-----------------------------------
//  class Tree (Binary Trees)
// process nodes in Pre/In/Post  order
//-----------------------------------
template <class T>
class Tree
{
protected:
	//--------------------------------------------------------
	//  inner class Node
	//      a single Node from a binary tree
	//--------------------------------------------------------
	class Node
	{
	public:
		Node* left;
		Node* right;
		T value;
		Node(T val) : value(val), left(NULL), right(NULL) {}
		Node(T val, Node* l, Node* r) : value(val), left(l), right(r) {}
	};		//end of Node class

	//data member of tree
	Node* root;

public:
	Tree() { root = NULL; }	 // initialize tree
	~Tree();
	int isEmpty() const;
	void clear() { clear(root); root = NULL; }
	void preOrder() { preOrder(root); }
	void inOrder() { inOrder(root); }
	void postOrder() { postOrder(root); }
	int height() { return height(root); }
	void reflect() { reflect(root); }
	void breadthScan();
	virtual void process(T val) { cout << val << " "; }
	virtual void add(T val) = 0;
	virtual bool search(T val) = 0;
	virtual void remove(T val) = 0;


private:
	//private function for not give acsses to user
	void  clear(Node* current);
	void  preOrder(Node* current);
	void  inOrder(Node* current);
	void  postOrder(Node* current);
	int height(Node* current);
	void reflect(Node* current);
};







//----------------------------------------------------------
//  class Tree implementation
//----------------------------------------------------------
template <class T>
Tree<T>::~Tree() // deallocate tree
{
	if (root != NULL)
		clear(root);
}
template <class T>
void Tree<T>::clear(Node* current)
{
	if (current)
	{    // Release memory associated with children
		if (current->left)
			clear(current->left);
		if (current->right)
			clear(current->right);
		delete current;
	}
}

template <class T>
int Tree<T>::isEmpty() const
{
	return  root == NULL;
}

template<class T>
inline void Tree<T>::breadthScan()
{
	QueueVector <Node*> q;
	if (root)
	{
		q.enqueue(root);
		while (!q.isEmpty())
		{
			Node* node = q.dequeue();
			cout << node->value << " ";
			if (node->left != nullptr)
				q.enqueue(node->left);
			if (node->right != nullptr)
				q.enqueue(node->right);
		}
	}
}



// preOrder processing of tree rooted at current
template <class T>
void Tree<T>::preOrder(Node* current)
{    // visit Node, left child, right child
	if (current)
	{   // process current Node
		process(current->value);
		// then visit children
		preOrder(current->left);
		preOrder(current->right);
	}
}

// inOrder processing of tree rooted at current
template <class T>
void Tree<T>::inOrder(Node* current)
{    // visit left child, Node, right child
	if (current)
	{
		inOrder(current->left);
		process(current->value);
		inOrder(current->right);
	}
}

// postOrder processing of tree rooted at current
template <class T>
void Tree<T>::postOrder(Node* current)
{    // visit left child, right child, node
	if (current)
	{
		postOrder(current->left);
		postOrder(current->right);
	}
}

template<class T>
inline int Tree<T>::height(Node* current)
{

	if (!current)
		return -1;
	else
	{
		int right = height(current->right);
		int left = height(current->left);
		return(max(right, left)) + 1;
	}
}
template<class T>
inline void Tree<T>::reflect(Node* current)
{
	if (current != nullptr) {
		if (current->right)
		{
			Node* temp = current->right;
			current->right = current->left;
			current->left = temp;
			reflect(current->right);
			reflect(current->left);
		}
		else
		{
			if (current->left)
			{
				Node* temp = current->right;
				current->right = current->left;
				current->left = temp;
				reflect(current->right);
				reflect(current->left);
			}
		}
	}

}

