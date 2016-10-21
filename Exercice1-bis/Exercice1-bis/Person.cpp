#include "Person.h"

Person::~Person()
{
}

Person::Person(std::string firstName, std::string lastName, int birthYear, int deathYear, EyesColor color):
	m_firstName(firstName), m_lastName(lastName), m_birthYear(birthYear),m_deathYear(deathYear), m_eyesColor(color)
{
	m_brotherhood = new Brotherhood(this);
	std::vector<Couple*> v;
	m_couplesList = v;
}

Person::Person(std::string firstName, std::string lastName, int birthYear, EyesColor color) :
	m_firstName(firstName), m_lastName(lastName), m_birthYear(birthYear), m_eyesColor(color)
{
	m_brotherhood = new Brotherhood(this);
	std::vector<Couple*> v;
	m_couplesList = v;
}
