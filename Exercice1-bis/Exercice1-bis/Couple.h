#ifndef COUPLE_H
#define COUPLE_H

#include "Person.h"
#include "Brotherhood.h"

class Couple
{
public:
	Couple();
	~Couple();
	Person* getMan() { return m_man; };
	Person* getWoman() { return m_woman; };
	Brotherhood getChildren() { return m_children; };
	void setMan(Person* man) { m_man = man; };
	void setWoman(Person* woman) { m_woman = woman; };
	void addChildren(Person* child) { m_children.add(child); };
	int numberOfChildren() { return m_children.size(); };
private:
	Person* m_man;
	Person* m_woman;
	Brotherhood m_children;
};
#endif
