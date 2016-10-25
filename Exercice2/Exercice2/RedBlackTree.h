#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#include "RedBlackNode.h"

template <typename T>
class RedBlackTree
{
public:
	RedBlackTree<T>();	
	RedBlackTree<T>(RedBlackNode<T>* head);
	RedBlackNode<T>*	findKey(T key);
	void				addKey(T key);
	void				deleteKey(T key);

private:
	RedBlackNode<T>*	m_head;
	RedBlackNode<T>*	recFindKey(T key, RedBlackNode<T>* node);
	void				recAddKey(T key, RedBlackNode<T>* node);
	void				recDeleteKey(T key);
};

template <typename T>
void leftRotate(RedBlackNode<T>* node);
template <typename T>
void rightRotate(RedBlackNode<T>* node);
template <typename T>
void insertCase1(RedBlackNode<T>* node);
template <typename T>
void insertCase2(RedBlackNode<T>* node);
template <typename T>
void insertCase3(RedBlackNode<T>* node);
template <typename T>
void insertCase4(RedBlackNode<T>* node);
template <typename T>
void insertCase5(RedBlackNode<T>* node);

template <typename T>
RedBlackTree<T>::RedBlackTree()
{
	m_head = nullptr;
}

template<typename T>
RedBlackTree<T>::RedBlackTree(RedBlackNode<T>* head):
	m_head(head)
{
}

template<typename T>
RedBlackNode<T>* RedBlackTree<T>::findKey(T key)
{
	return recFindKey(key, m_head);
}

template<typename T>
RedBlackNode<T>* RedBlackTree<T>::recFindKey(T key, RedBlackNode<T>* node)
{
	if (node != nullptr) {
		if (key != node->getKey()) {
			if (key > node->getKey()) {
				return recFindKey(key, node->getRightNode());
			}
			else {
				return recFindKey(key, node->getLeftNode());
			}
		}
		else {
			return node;
		}
	}
	else {
		return node;
	}
}


template<typename T>
void RedBlackTree<T>::addKey(T key)
{
	if (m_head != nullptr) {
		recAddKey(key, m_head);
	}
	else {
		m_head = new RedBlackNode<T>(BLACK, key);
	}
	
}

template<typename T>
void RedBlackTree<T>::recAddKey(T key, RedBlackNode<T>* node)
{
	if (node->getLeftNode() != nullptr || node->getRightNode() != nullptr) {
		if (key != node->getKey()) {
			if (key > node->getKey()) {
				if (node->getRightNode() != nullptr) {
					recAddKey(key, node->getRightNode());
				}
				else {
					RedBlackNode<T>* newNode = new RedBlackNode<T>(RED, key);
					newNode->setParentNode(node);
					node->setRightNode(newNode);
					insertCase1(newNode);
				}
			}
			else {
				if (node->getLeftNode() != nullptr) {
					recAddKey(key, node->getLeftNode());
				}
				else {
					RedBlackNode<T>* newNode = new RedBlackNode<T>(RED, key);
					newNode->setParentNode(node);
					node->setLeftNode(newNode);
					insertCase1(newNode);
				}
			}
		}
		else {
			cout << "Key already in the tree" << endl;
			return;
		}
	}
	else {
		RedBlackNode<T>* newNode = new RedBlackNode<T>(RED, key);
		newNode->setParentNode(node);
		if (key > node->getKey()) {
			node->setRightNode(newNode);
		}
		else {
			node->setLeftNode(newNode);
		}
		insertCase1(newNode);
	}
}


template<typename T>
void RedBlackTree<T>::deleteKey(T key)
{
}

template<typename T>
void RedBlackTree<T>::recDeleteKey(T key)
{
}

template<typename T>
void insertCase1(RedBlackNode<T>* node)
{
	if (node->getParentNode() == nullptr) {
		//node is the head of the tree
		node->setColor(BLACK);
	}
	else {
		insertCase2(node);
	}
}

template<typename T>
void insertCase2(RedBlackNode<T>* node)
{
	if (node->getParentNode()->getColor() == BLACK) {
		return; /* Tree is still valid */
	}
	else {
		insertCase3(node);
	}
}

template<typename T>
void insertCase3(RedBlackNode<T>* node)
{
	if ((node->getUncleNode() != nullptr) && (node->getUncleNode()->getColor() == RED)) {
		node->getParentNode()->setColor(BLACK);
		node->getUncleNode()->setColor(BLACK);
		node->getGrandParentNode()->setColor(RED);
		insertCase1(node->getGrandParentNode());
	}
	else {
		insertCase4(node);
	}
}

template<typename T>
void insertCase4(RedBlackNode<T>* node)
{
	if ((node == node->getParentNode()->getRightNode()) && (node->getParentNode() == node->getGrandParentNode()->getLeftNode())) {
		leftRotate(node);
		node = node->getLeftNode();
	}
	else if ((node == node->getParentNode()->getLeftNode()) && (node->getParentNode() == node->getGrandParentNode()->getRightNode())) {		
		rightRotate(node);
		node = node->getRightNode(); 
	}
	insertCase5(node);
}

template<typename T>
void insertCase5(RedBlackNode<T>* node)
{
	node->getParentNode()->setColor(BLACK);
	node->getGrandParentNode()->setColor(RED);
	if (node == node->getParentNode()->getLeftNode())
		rightRotate(node->getParentNode());
	else
		leftRotate(node->getParentNode());
}

/*
template<typename T>
void RedBlackTree<T>::fixTree(RedBlackNode<T>* node)
{
	if (node->getParentNode() == nullptr) {
		//node is the head of the tree
		node->setColor(BLACK);
	}
	else if (node->getParentNode()->getColor() == RED) {
		if (node->getUncleNode() != nullptr && node->getUncleNode()->getColor() == RED) {
			//the parent and the uncle are RED
			node->getParentNode()->setColor(BLACK);
			node->getUncleNode()->setColor(BLACK);
			node->getGrandParentNode()->setColor(RED);
			fixTree(node->getGrandParentNode());
		}
		else {
			if ((node == node->getParentNode()->getRightNode()) && (node->getParentNode() == node->getGrandParentNode()->getLeftNode())) {
				//node is the left child
				leftRotate(node->getParentNode());
				node = node->getLeftNode();
			}
			else if ((node == node->getParentNode()->getLeftNode()) && (node->getParentNode() == node->getGrandParentNode()->getRightNode())) {
				//node is the right child
				rightRotate(node->getRightNode());
				node = node->getRightNode();
			}
			node->getParentNode()->setColor(BLACK);
			node->getGrandParentNode()->setColor(RED);
			if (node == node->getParentNode()->getLeftNode()) {
				rightRotate(node->getGrandParentNode());
			}
			else {
				leftRotate(node->getGrandParentNode()); 
				node->getParentNode()->setColor(BLACK);
			}
		}
	}
}
*/

template<typename T>
void leftRotate(RedBlackNode<T>* node)
{
	RedBlackNode<T>* temp;
	temp = node->getRightNode();
	node->setRightNode(temp->getLeftNode());
	if (temp->getLeftNode() != nullptr) {
		temp->getLeftNode()->setParentNode(node);
	}
	temp->setParentNode(node->getParentNode());
	if (node == node->getParentNode()->getLeftNode()) {
		node->getParentNode()->setLeftNode(temp);
	}
	else {
		node->getParentNode()->setRightNode(temp);
	}
	temp->setLeftNode(node);
	node->setParentNode(temp);
}

template<typename T>
void rightRotate(RedBlackNode<T>* node)
{
	RedBlackNode<T>* temp;
	temp = node->getParentNode();
	temp->setLeftNode(node->getRightNode());
	if (temp->getLeftNode() != nullptr) {
		temp->getLeftNode()->setParentNode(temp);
	}
	node->setParentNode(temp->getParentNode());
	if (temp == temp->getParentNode()->getLeftNode()) {
		temp->getParentNode()->setLeftNode(node);
	}
	else {
		temp->getParentNode()->setRightNode(node);
	}
	node->setRightNode(temp);
}


#endif