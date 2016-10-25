#include "Node.h"

template<typename T>
bool operator==(Node<T> n1, Node<T> n2) 
{
	return (n1.getKeys() == n2.getKeys() 
		&& n1.getLeaves() == n2.getLeaves());
}