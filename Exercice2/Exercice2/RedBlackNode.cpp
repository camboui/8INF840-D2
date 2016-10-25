#include "RedBlackNode.h"

template<typename T>
bool operator==(RedBlackNode<T> n1, RedBlackNode<T> n2)
{
	return (n1.getKey() == n2.getKey()
		&& n1.getLeftNode() == n2.getLeftNode()
		&& n1.getRightNode() == n2.getRightNode());
}

