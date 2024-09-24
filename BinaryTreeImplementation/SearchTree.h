#pragma once
#include "Tree.h"
#include <iostream>

using namespace std;

template<class T>

class SearchTree : public Tree<T>
{

public:
	void add(T value);
	bool  search(T value)
	{
		return search(Tree<T>::root, value);
	}
	void remove(T val) { remove(val, Tree<T>::root); }
	T successor(T val);
	void deleteDuplicates() { deleteDuplicates(Tree<T>::root); }


private:
	void add(typename Tree<T>::Node* current, T val);
	bool search(typename Tree<T>::Node* current, T val);
	void remove(T val, typename Tree<T>::Node* current);
	typename  Tree<T>::Node* findVal(T val, typename Tree<T>::Node* current);
	typename  Tree<T>::Node* findParent(typename Tree<T>::Node* current, typename Tree<T>::Node* root);
	typename  Tree<T>::Node* minNum(typename Tree<T>::Node* current);
	void deleteNode(typename Tree<T>::Node* current);
	void deleteDuplicates(typename Tree<T>::Node* current);
	typename Tree<T>::Node* spointer(T val);
	typename Tree<T>::Node* pointer(typename Tree<T>::Node* current, T val);
	typename Tree<T>::Node* max(typename Tree<T>::Node* current);
};

template <class T>
void SearchTree<T>::add(T val)
{
	// add value to binary search tree 
	if (!Tree<T>::root)
	{
		Tree<T>::root = new typename Tree<T>::Node(val);
		return;
	}
	add(Tree<T>::root, val);
}




template<class T>
inline T SearchTree<T>::successor(T val)
{
	typename Tree<T>::Node* z = findVal(val, Tree<T>::root);
	if (z->right != nullptr)
		return (minNum(z->right))->value;
	else
	{
		typename Tree<T>::Node* y = findParent(z, Tree<T>::root);
		while (y != nullptr && z == y->right)
		{
			z = y;
			y = findParent(y, Tree<T>::root);
		}
		if (y)
			return y->value;
		throw "no successor";

	}

}



template <class T>
void SearchTree<T>::add(typename Tree<T>::Node* current, T val)
{
	if (current->value < val)

		if (!current->right)
		{
			current->right = new typename Tree<T>::Node(val);
			return;
		}
		else add(current->right, val);
	else

		if (!current->left)
		{
			current->left = new typename Tree<T>::Node(val);
			return;
		}
		else add(current->left, val);
}

template <class T>
bool SearchTree<T>::search(typename Tree<T>::Node* current, T val)
{
	// see if argument value occurs in tree
	if (!current)
		return false;	// not found
	if (current->value == val)
		return true;
	if (current->value < val)
		return search(current->right, val);
	else
		return search(current->left, val);
}

template<class T>
inline void SearchTree<T>::remove(T val, typename Tree<T>::Node* current)
{
	if (!current)
		return;
	// see if argument value occurs in tree
	if (current->value == val) {
		//if (!current->left && !current->right)
		//	//this->Tree<T>::
		//	clear(current);
			
		 if (current->left && current->right) {
			typename Tree<T>::Node* success = spointer(val);
			typename Tree<T>::Node* child = success->right;
			current->value = success->value;
			if (findParent( success, Tree<T>::root)->left == success)
				findParent(success, Tree<T>::root)->left = child;
			else
				findParent(success, Tree<T>::root)->right = child;
			delete success;
			success = nullptr;
		}
		else {
			typename Tree<T>::Node* child = current->right ? current->right : current->left;
			typename Tree<T>::Node* childParent = findParent(child, Tree<T>::root);
			typename Tree<T>::Node* currentParent = findParent(current, Tree<T>::root);
			if (!findParent(current, Tree<T>::root)) {//if deleting root of tree
				delete current;
				current = child;
				childParent = nullptr;
			}
			else if (findParent(current, Tree<T>::root) && findParent(current, Tree<T>::root)->right == current) {
				currentParent->right = child;
				childParent = currentParent;
				delete current;
			}
			else if (findParent(current, Tree<T>::root) && findParent(current, Tree<T>::root)->left == current) {
				findParent(current, Tree<T>::root)->left = child;
				childParent = findParent(current, Tree<T>::root);
				delete current;
			}
			child = nullptr;
		}
		return;
	}
	else if (current->value < val) {
		remove( val,current->right);
	}
	else if (current->value > val) {
		remove(val,current->left );
	}
	return;
	/*typename Tree<T>::Node* q = findVal(val, current);
	deleteNode(q);*/
}

template<class T>
inline typename Tree<T>::Node* SearchTree<T>::findVal(T val, typename Tree<T>::Node* current)
{
	typename Tree<T>::Node* z = current;
	while (z != nullptr)
	{

		if (val == (z->value))
			return z;
		if (val <= (z->value))
			z = z->left;
		else
			z = z->right;
	}
	return z;
}

//template<class T>
//inline typename Tree<T>::Node* SearchTree<T>::findParent(typename Tree<T>::Node* node, typename Tree<T>::Node* current)
//{
//	//if we search all the tree or the current is the root of the tree
//	if (current == nullptr || current == node)
//		return nullptr;
//	if (current->left == node || current->right == node)
//		return current;
//	if (node->value <= current->value)
//		return findParent(node, current->left);
//	else
//		return findParent(node, current->right);
//}
template<class T>
typename Tree<T>::Node* SearchTree<T>::findParent(typename Tree<T>::Node* node, typename Tree<T>::Node* current)
{
	typename Tree<T>::Node* parent = nullptr;
	while (current != nullptr && current != node)
	{
		//if is the parent
		if (current->left == node || current->right == node)
			return current;
		if (node == nullptr)
			return nullptr;
		if (node->value <= current->value)
		{
			parent = current;
			current = current->left;
		}
		else
		{
			parent = current;
			current = current->right;
		}
	}
	return parent;
}

template<class T>
inline typename Tree<T>::Node* SearchTree<T>::minNum(typename Tree<T>::Node* current)
{
	while (current->left != nullptr)
		current = current->left;
	return current;
}

template<class T>
inline void SearchTree<T>::deleteNode(typename Tree<T>::Node* current)
{
	if (current != nullptr)
	{
		if (current->left == nullptr && current->right == nullptr)
		{
			typename Tree<T>::Node* y = findParent(current, Tree<T>::root);
			if (y != nullptr)
			{
				if (y->right == current)
					y->right = nullptr;
				else
					y->left = nullptr;
				delete current;
			}

		}
		else
		{
			if (current->right == nullptr)
			{
				typename Tree<T>::Node* y = findParent(current, Tree<T>::root);
				if (y != nullptr)
				{
					if (y->right == current)
					{
						y->right = current->left;
						delete current;
					}

					else
					{
						y->left = current->left;
						delete current;
					}
				}
			}
			if (current->left == nullptr)
			{
				typename Tree<T>::Node* y = findParent(current, Tree<T>::root);
				if (y->right == current)
					y->right = current->right;
				else
					y->left = current->right;
				delete current;
			}
			if (current->left != nullptr && current->right != nullptr)
			{
				typename Tree<T>::Node* z = minNum(current);
				current->value = z->value;
				deleteNode(z);
			}
		}
	}
}

template<class T>
inline void SearchTree<T>::deleteDuplicates(typename Tree<T>::Node* current)
{
	//if (current != nullptr)
	//{
	//	typename Tree<T>::Node* z = current;
	//	if (current->left != nullptr)
	//	{
	//		if (current->left->value == current->value)
	//		{
	//			deleteNode(current);
	//			deleteDuplicates(current);//if it's contain three or more same
	//		}
	//		else
	//		{
	//			z = z->left;
	//			while (z->right)
	//			{
	//				z = z->right;
	//				if (z->value == current->value)
	//					remove(current->value, Tree<T>::root);
	//			}
	//		}

	//	}
	//	deleteDuplicates(current->left);
	//	deleteDuplicates(current->right);
	//}
	// visit Node, left child, right child
	if (current)
	{
		// then visit children
		if (current->left)
			deleteDuplicates(current->left);
		if (current->right)
			deleteDuplicates(current->right);
		// process current Node
		if (search(current->left, current->value)) {
			remove( current->value, current->left);
		}
	}
	return;
}
template<class T>
inline typename Tree<T>::Node* SearchTree<T>::spointer(T val)
{

	if (val == max(Tree<T>::root)->value)
		throw "no successor";
	typename Tree<T>::Node* ptrMe = pointer(Tree<T>::root, val);
	if (ptrMe->right) {
		return minNum(ptrMe->right);
	}
	typename Tree<T>::Node* ptrPar = findParent(ptrMe, Tree<T>::root);
	while (ptrPar && ptrPar->right == ptrMe) {
		ptrMe = ptrPar;
		ptrPar = findParent(ptrPar, Tree<T>::root);
	}
	return ptrPar;
}
template<class T>
inline typename Tree<T>::Node* SearchTree<T>::max(typename Tree<T>::Node* current)
{
	if (!current->right)
		return current;
	return max(current->right);
}
template<class T>
typename Tree<T>::Node* SearchTree<T>::pointer(typename Tree<T>::Node* current, T val)
{
	if (!current)
		return nullptr;	// not found
	if (current->value == val)
		return current;
	if (current->value < val)
		return pointer(current->right, val);
	else
		return pointer(current->left, val);
}


