#ifndef BROTHERHOOD_H
#define BROTHERHOOD_H

#include <vector>
class Couple;
class Person;
class Brotherhood
{
public:
	Brotherhood();
	Brotherhood(Person* firstChild);
	Brotherhood(Person* firstChild, Couple* parents);
	~Brotherhood();
	void add(Person* child) { m_brotherhood.push_back(child); };
	int size() { return (int) m_brotherhood.size(); };
	Couple* getParents() { return m_parents; };
	void setParents(Couple* parents) { m_parents = parents; };
private:
	std::vector<Person*> m_brotherhood;
	Couple* m_parents;
};

#endif
