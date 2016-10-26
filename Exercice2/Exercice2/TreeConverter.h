#ifndef TREE_CONVERTER_H
#define TREE_CONVERTER_H

#include "Tree234.h"
#include "RedBlackTree.h"


template<typename T>
RedBlackNode<T>* nextLeaf(RedBlackNode<T>* node)
{
	if (node != nullptr) {
		if (node->getLeftNode() != nullptr) {
			return nextLeaf(node->getLeftNode());
		}
		else if (node->getRightNode() != nullptr) {
			return nextLeaf(node->getRightNode());
		}
		else {
			if (node->getParentNode() != nullptr) {
				if (node->getParentNode()->getLeftNode() == node) {
					node->getParentNode()->setLeftNode(nullptr);
				}
				else {
					node->getParentNode()->setRightNode(nullptr);
				}
			}
			RedBlackNode<T>* tmp = node;
			node = nullptr;
			return tmp;
		}
	}
	return nullptr;
}

template<typename T>
Tree234<T> toTree234(RedBlackTree<T> rbtree)
{
	Tree234<T> tree = Tree234<T>();
	RedBlackNode<T>* current = new RedBlackNode<T>();
	RedBlackNode<T>* prev = new RedBlackNode<T>();
	current = nextLeaf(rbtree.m_head);
	while (current != prev) {
		tree.addKey(current->getKey());
		prev = current;
		current = nextLeaf(rbtree.m_head);
	}
	return tree;
}



template<typename T>
RedBlackNode<T>* rectoRBTree(Node234<T>* n, RedBlackNode<T>* parent)
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
RedBlackTree<T> toRedBlackTree(Tree234<T> tree234)
{
	return RedBlackTree<T>(rectoRBTree(tree234.m_head, nullptr));
}


#endif
