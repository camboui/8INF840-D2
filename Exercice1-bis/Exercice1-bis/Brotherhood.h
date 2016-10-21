#ifndef BROTHERHOOD_H
#define BROTHERHOOD_H

#include <vector>


class Person;
class Brotherhood
{
public:
	Brotherhood(std::vector<Person*> brotherhood);
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
