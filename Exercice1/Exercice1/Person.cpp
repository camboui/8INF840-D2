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

Person::~Person()
{
}
