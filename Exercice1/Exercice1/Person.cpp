#include "Person.h"


using namespace std;


/*Creates a Person with all attributes*/
Person::Person(string firstName, string lastName, int birthYear, int deathYear, Color color,
	Person*father, Person*mother, vector<Person*> children) :
	m_firstName(firstName), m_lastName(lastName), m_birthYear(birthYear), m_deathYear(deathYear),
	m_eyesColor(color), m_father(father), m_mother(mother), m_children(children)
{}

/*Creates a Person with all attributes but brothers and children*/
Person::Person(string firstName, string lastName, int birthYear, int deathYear, Color color,
	Person*father, Person*mother): 
	m_firstName(firstName), m_lastName(lastName), m_birthYear(birthYear), m_deathYear(deathYear),
	m_eyesColor(color), m_father(father), m_mother(mother)
{}


Person::Person(string firstName, string lastName, int birthYear, int deathYear, Color color):
	m_firstName(firstName), m_lastName(lastName), m_birthYear(birthYear), m_deathYear(deathYear),
	m_eyesColor(color), m_father(nullptr), m_mother(nullptr)
{}

Person::~Person()
{
}
