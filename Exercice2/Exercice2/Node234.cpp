#include "Node234.h"

template<typename T>
bool operator==(Node234<T> n1, Node234<T> n2)
{
	return (n1.getKeys() == n2.getKeys() 
		&& n1.getLeaves() == n2.getLeaves());
}