#include "Brotherhood.h"



Brotherhood::Brotherhood()
{
	m_parents = nullptr;
}

Brotherhood::Brotherhood(Person* firstChild)
{
	m_brotherhood.push_back(firstChild);
}

Brotherhood::Brotherhood(Person* firstChild, Couple* parents)
{
	m_brotherhood.push_back(firstChild);
	m_parents = parents;
}


Brotherhood::~Brotherhood()
{
}
