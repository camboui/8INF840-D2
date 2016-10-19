#include "Person.h"


using namespace std;


/*Creates a Person with all attributes*/
Person::Person(string firstName, string lastName, int birthYear, int deathYear, Color color,
	Person*father, Person*mother, Person*brotherL, Person*brotherR, Person*child):
	m_firstName(firstName), m_lastName(lastName), m_birthYear(birthYear), m_deathYear(deathYear),
	m_eyesColor(color), m_father(father), m_mother(mother), m_brotherL(brotherL), m_brotherR(brotherR), m_child(child)
{}

/*Creates a Person with all attributes but brothers and children*/
Person::Person(string firstName, string lastName, int birthYear, int deathYear, Color color,
	Person*father, Person*mother): 
	m_firstName(firstName), m_lastName(lastName), m_birthYear(birthYear), m_deathYear(deathYear),
	m_eyesColor(color), m_father(father), m_mother(mother)
{}

/*Return a list of all children for a parent*/
vector<Person*> Person::getChildren() {
	vector<Person*> children;
	if (getChild() == nullptr)
		return children;

	children.push_back(getChild());

	Person *brother = getChild();
	while (brother->getBrotherL != nullptr)
	{
		children.push_back(brother->getBrotherL);
		brother = brother->getBrotherL;
	}

	Person *brother = getChild();
	while (brother->getBrotherR != nullptr)
	{
		children.push_back(brother->getBrotherR);
		brother = brother->getBrotherR;
	}

	return children;
}

Person::~Person()
{
}
