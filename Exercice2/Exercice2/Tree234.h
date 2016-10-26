#ifndef TREE234_H
#define TREE234_H

#include "Node234.h"
#include "RedBlackTree.h"
#include <algorithm>

template <typename T>
class Tree234
{
public:
	Tree234();
	Tree234(vector<T> keys);

	bool isEmpty();
	Node234<T>* findNode(const T & key);
	void addKey(const T & key);
	void deleteKey(const T & key);
	RedBlackTree<T> toRBTree();
private:

	Node234<T>* m_head;
	vector<T> findNext(Node234<T>* node, T key);
	void recAddKey(T key, Node234<T>* first, Node234<T>* upperNode);
	void recDeleteKey(const T& delKey, Node234<T>* first, Node234<T>* delNode);
	Node234<T>* recFindNode(const T & key, Node234<T>* first);
	RedBlackNode<T>* rectoRBTree(Node234<T>* n, RedBlackNode<T>* parent);
};

template<typename T>
Tree234<T>::Tree234()
{
	m_head = new Node234<T>();
}

template<typename T>
Tree234<T>::Tree234(vector<T> keys)
{
	try {
		m_head = new Node234<T>(keys);
	}
	catch (logic_error error) {
		cout << error.what();
		m_head = new Node234<T>();
		for (int i; i < keys.size(); i++)
			addKey(keys[i]);
	}
}


template<typename T>
bool Tree234<T>::isEmpty()
{
	return (m_head->getNumberOfKeys() == 0);
}

template<typename T>
Node234<T>* Tree234<T>::findNode(const T & key)
{
	return recFindNode(key, m_head);
}

template<typename T>
Node234<T>* Tree234<T>::recFindNode(const T & key, Node234<T>* first)
{
	vector<T> keys = first->getKeys();
	if (std::find(keys.begin(), keys.end(), key) != keys.end()) {
		return first;
	}
	if (first->isLeaf()) {
		return nullptr;
	}

	vector<T> temp = findNext(first, key);
	int leafIndex = std::find(temp.begin(), temp.end(), key) - temp.begin();
	return recFindNode(key, first->getLeaf(leafIndex));
}


template <typename T>
void Tree234<T>::addKey(const T & key)
{
	recAddKey(key, m_head, nullptr);
}

template<typename T>
void Tree234<T>::deleteKey(const T & delKey)
{
	recDeleteKey(delKey, m_head, nullptr);
}

template<typename T>
RedBlackTree<T> Tree234<T>::toRBTree()
{
	return RedBlackTree<T>(rectoRBTree(m_head, nullptr));
}

template<typename T>
RedBlackNode<T>* Tree234<T>::rectoRBTree(Node234<T>* n, RedBlackNode<T>* parent)
{
	int nbLeaves = n->getLeaves().size();
	if (nbLeaves == 0) {
		int nbKeys = n->getKeys().size();
		if (nbKeys == 1) {
			RedBlackNode<T>* newNode = new RedBlackNode<T>(BLACK, n->getKey(0));
			newNode->setParentNode(parent);
			if (parent != nullptr) {
				newNode->setColor(RED);
			}
			return newNode;
		}
		else if (nbKeys == 2) {
			RedBlackNode<T>* newNodeR = new RedBlackNode<T>(RED, n->getKey(0));
			RedBlackNode<T>* newNodeB = new RedBlackNode<T>(BLACK, n->getKey(1));
			newNodeR->setParentNode(newNodeB);
			newNodeB->setParentNode(parent);

			newNodeB->setLeftNode(newNodeR);
			return newNodeB;
		}
		else if (nbKeys == 3) {
			RedBlackNode<T>* newNodeB = new RedBlackNode<T>(BLACK, n->getKey(1));
			RedBlackNode<T>* newNodeR1 = new RedBlackNode<T>(RED, n->getKey(0));
			RedBlackNode<T>* newNodeR2 = new RedBlackNode<T>(RED, n->getKey(2));
			newNodeB->setParentNode(parent);
			newNodeR1->setParentNode(newNodeB);
			newNodeR2->setParentNode(newNodeB);

			newNodeB->setLeftNode(newNodeR1);
			newNodeB->setRightNode(newNodeR2);

			return newNodeB;
		}
	}
	else if (nbLeaves == 2) {
		RedBlackNode<T>* newNode = new RedBlackNode<T>(BLACK, n->getKey(0));
		newNode->setParentNode(parent);
		newNode->setLeftNode(rectoRBTree(n->getLeaf(0), newNode));
		newNode->setRightNode(rectoRBTree(n->getLeaf(1), newNode));
		return newNode;
	}
	else if (nbLeaves == 3) {
		RedBlackNode<T>* newNodeR = new RedBlackNode<T>(RED, n->getKey(0));
		RedBlackNode<T>* newNodeB = new RedBlackNode<T>(BLACK, n->getKey(1));
		newNodeR->setParentNode(newNodeB);
		newNodeB->setParentNode(parent);

		newNodeB->setLeftNode(newNodeR);
		newNodeB->setRightNode(rectoRBTree(n->getLeaf(2), newNodeB));

		newNodeR->setLeftNode(rectoRBTree(n->getLeaf(0), newNodeR));
		newNodeR->setRightNode(rectoRBTree(n->getLeaf(1), newNodeR));

		return newNodeB;
	}
	else if (nbLeaves == 4) {
		RedBlackNode<T>* newNodeB = new RedBlackNode<T>(BLACK, n->getKey(1));
		RedBlackNode<T>* newNodeR1 = new RedBlackNode<T>(RED, n->getKey(0));
		RedBlackNode<T>* newNodeR2 = new RedBlackNode<T>(RED, n->getKey(2));
		newNodeB->setParentNode(parent);
		newNodeR1->setParentNode(newNodeB);
		newNodeR2->setParentNode(newNodeB);

		newNodeB->setLeftNode(newNodeR1);
		newNodeB->setRightNode(newNodeR2);

		newNodeR1->setLeftNode(rectoRBTree(n->getLeaf(0), newNodeR1));
		newNodeR1->setRightNode(rectoRBTree(n->getLeaf(1), newNodeR1));

		newNodeR2->setLeftNode(rectoRBTree(n->getLeaf(2), newNodeR2));
		newNodeR2->setRightNode(rectoRBTree(n->getLeaf(3), newNodeR2));

		return newNodeB;
	}
	else {
		throw logic_error("to many leaves for a 234 tree");
	}
}

template<typename T>
void Tree234<T>::recDeleteKey(const T & delKey, Node234<T>* first, Node234<T>* delNode)
{
	int nextLeafIndex;
	Node234<T>* nodeL = nullptr;
	Node234<T>* nodeR = nullptr;
	Node234<T>* newNode = nullptr;
	Node234<T>* nextNode = nullptr;
	vector<T> temp;

	int keyIndex = std::find(first->getKeys().begin(), first->getKeys().end(), delKey) - first->getKeys().begin();

	if (keyIndex != first->getNumberOfKeys())
		delNode = first;

	if (first->isLeaf()) {
		if (first == delNode) {
			if (keyIndex != first->getNumberOfKeys()) {
				first->deleteKey(keyIndex);
				return;
			}
		}
		if (delNode != nullptr) {
			keyIndex = std::find(delNode->getKeys().begin(), delNode->getKeys().end(), delKey) - delNode->getKeys().begin();
			if (keyIndex != delNode->getNumberOfKeys()) {
				delNode->deleteKey(keyIndex);
			}
			try {
				delNode->addKey(first->getKey(0));
			}
			catch (logic_error error) {
				cout << error.what();
			}
			first->deleteKey(0);
			return;
		}
		throw logic_error("Key not found in the tree");
	}

	temp = findNext(delNode, delKey);
	if (delNode == nullptr) {
		nextLeafIndex = std::find(temp.begin(), temp.end(), delKey) - temp.begin();
	}
	else {
		nextLeafIndex = std::find(temp.begin(), temp.end(), delKey) - temp.begin() + 1;
	}
	nextNode = first->getLeaf(nextLeafIndex);

	if (nextNode->getNumberOfKeys() == 1) {
		if (nextLeafIndex > 0) {
			nodeL = first->getLeaf(nextLeafIndex - 1);
		}
		if (nextLeafIndex < first->getNumberOfLeaves() - 1) {
			nodeR = first->getLeaf(nextLeafIndex + 1);
		}

		if (nodeL != nullptr && nodeL->getNumberOfKeys() != 1) {
			newNode = nodeL;
			try {
				nextNode->addKey(first->getKey(nextLeafIndex - 1));
			}
			catch (logic_error error) {
				cout << error.what();
			}
			if (!newNode->isLeaf()) {
				nextNode->addLeaf(newNode->getLeaf(newNode->getNumberOfLeaves() - 1));
				newNode->deleteLeaf(newNode->getNumberOfLeaves() - 1);
			}

			first->deleteKey(nextLeafIndex - 1);
			try {
				first->addKey(newNode->getKey(newNode->getNumberOfLeaves() - 1));
			}
			catch (logic_error error) {
				cout << error.what();
			}
			newNode->deleteKey(newNode->getNumberOfLeaves() - 1);
		}
		else if (nodeR != nullptr && nodeR->getNumberOfLeaves() != 1)
		{
			newNode = nodeR;
			try {
				nextNode->addKey(first->getKey(nextLeafIndex));
			}
			catch (logic_error error) {
				cout << error.what();
			}
			if (!newNode->isLeaf()) {
				nextNode->addLeaf(newNode->getLeaf(0));
				newNode->deleteLeaf(0);
			}

			first->deleteKey(nextLeafIndex);
			try {
				first->addKey(newNode->getKey(0));
			}
			catch (logic_error error) {
				cout << error.what();
			}
			newNode->deleteKey(0);
		}
		else {
			newNode = new Node234<T>();

			if (nodeL != nullptr) {
				if (!nextNode->isLeaf()) {
					for (int i = 0; i < nodeL->getNumberOfLeaves(); i++) {
						newNode->addLeaf(nodeL->getLeaf(i));
					}
					for (int i = 0; i < nextNode->getNumberOfLeaves(); i++) {
						newNode->addLeaf(nextNode->getLeaf(i));
					}
				}
				try {
					newNode->addKey(nodeL->getKey(0));
					newNode->addKey(first->getKey(nextLeafIndex - 1));
					newNode->addKey(nextNode->getKey(0));
				}
				catch (logic_error error) {
					cout << error.what();
				}
				first->deleteLeaf(nextLeafIndex);
				first->deleteLeaf(nextLeafIndex - 1);
				first->deleteKey(nextLeafIndex - 1);
				first->addLeaf(newNode, nextLeafIndex - 1);
			}

			else if (nodeR != nullptr) {
				if (!nextNode->isLeaf()) {
					for (int i = 0; i < nextNode->getNumberOfLeaves(); i++) {
						newNode->addLeaf(nextNode->getLeaf(i));
					}
					for (int i = 0; i < nodeR->getNumberOfLeaves(); i++) {
						newNode->addLeaf(nodeR->getLeaf(i));
					}
				}
				try {
					newNode->addKey(nextNode->getKey(0));
					newNode->addKey(first->getKey(nextLeafIndex));
					newNode->addKey(nodeR->getKey(0));
				}
				catch (logic_error error) {
					cout << error.what();
				}
				first->deleteLeaf(nextLeafIndex + 1);
				first->deleteLeaf(nextLeafIndex);
				first->deleteKey(nextLeafIndex);
				first->addLeaf(newNode, nextLeafIndex);
			}
			nextNode = newNode;
		}
	}

	recDeleteKey(delKey, nextNode, delNode);

}

template<typename T>
vector<T> Tree234<T>::findNext(Node234<T>* node, T key)
{
	vector<T> temp;
	temp.push_back(key);
	temp.reserve(temp.size() + node->getKeys().size());
	temp.insert(temp.end(), node->getKeys().begin(), node->getKeys().end());
	sort(temp.begin(), temp.end());
	return temp;
}

template<typename T>
void Tree234<T>::recAddKey(T key, Node234<T>* first, Node234<T>* upperNode)
{
	if (first->getNumberOfKeys() >= 3)
	{
		unsigned int medianIndex = first->getMedianIndex();
		Node234<T>* leftNewNode(new Node234<T>());
		Node234<T>* rightNewNode(new Node234<T>());

		for (unsigned int i = 0; i < medianIndex; i++) {
			try {
				leftNewNode->addKey(first->getKey(i));
			}
			catch (logic_error error) {
				cout << error.what();
			}
		}
		for (unsigned int i = medianIndex + 1; i < first->getKeys().size(); i++) {
			try {
				rightNewNode->addKey(first->getKey(i));
			}
			catch (logic_error error) {
				cout << error.what();
			}
		}

		int leafIndex = 0;

		if (!first->isLeaf()) {
			for (unsigned int i = 0; i <= medianIndex; i++) {
				leftNewNode->addLeaf(first->getLeaf(i));
			}
			for (unsigned int i = medianIndex + 1; i < first->getLeaves().size(); i++) {
				rightNewNode->addLeaf(first->getLeaf(i));
			}
		}
		if (first == m_head) {
			upperNode = new Node234<T>();
			m_head = upperNode;
		}
		else {
			leafIndex = std::find(upperNode->getLeaves().begin(), upperNode->getLeaves().end(), first) - upperNode->getLeaves().begin();
			upperNode->deleteLeaf(leafIndex);
		}

		T medianKey = first->getKey(medianIndex);
		try {
			upperNode->addKey(medianKey);
		}
		catch (logic_error error) {
			cout << error.what();
		}
		upperNode->addLeaf(leftNewNode, leafIndex);
		upperNode->addLeaf(rightNewNode, leafIndex + 1);
		first = upperNode;
	}

	if (first->isLeaf()) {
		try {
			first->addKey(key);
		}
		catch (logic_error error) {
			cout << error.what();
		}
	}
	else {
		vector<T> temp = findNext(first, key);
		int nextLeafIndex = std::find(temp.begin(), temp.end(), key) - temp.begin();
		recAddKey(key, first->getLeaf(nextLeafIndex), first);
	}
}

#endif