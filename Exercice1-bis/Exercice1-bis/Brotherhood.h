#ifndef BROTHERHOOD_H
#define BROTHERHOOD_H

#include <vector>

#include "Person.h"

class Brotherhood
{
public:
	Brotherhood();
	~Brotherhood();
	void add(Person* child) { m_brotherhood.push_back(child); };
	void size() { m_brotherhood.size(); };
private:
	std::vector<Person*> m_brotherhood;
};

#endif
