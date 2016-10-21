#include "Person.h"



Person::Person()
{
}


Person::~Person()
{
}

Person::Person(std::string firstName, std::string lastName, int birthYear, int deathYear, EyesColor color, std::vector<Couple*> couplesList, Brotherhood* brotherhood)
{
}

Person::Person(std::string firstName, std::string lastName, int birthYear, int deathYear, EyesColor color, Brotherhood * brotherhood)
{
}

Person::Person(std::string firstName, std::string lastName, int birthYear, int deathYear, EyesColor color, std::vector<Couple*> couplesList)
{
}

Person::Person(std::string firstName, std::string lastName, int birthYear, int deathYear, EyesColor color)
{
}

Person::Person(std::string firstName, std::string lastName, int birthYear, int deathYear, EyesColor color, Couple* parents)
{
}

Person::Person(std::string firstName, std::string lastName, int birthYear, EyesColor color, std::vector<Couple*> couplesList, Brotherhood * brotherhood)
{
}

Person::Person(std::string firstName, std::string lastName, int birthYear, EyesColor color, Brotherhood * brotherhood)
{
}

Person::Person(std::string firstName, std::string lastName, int birthYear, EyesColor color, std::vector<Couple*> couplesList)
{
}

Person::Person(std::string firstName, std::string lastName, int birthYear, EyesColor color) :
	m_firstName(firstName), m_lastName(lastName), m_birthYear(birthYear), m_eyesColor(color)
{
	m_brotherhood = new Brotherhood(this);
}


Person::Person(std::string firstName, std::string lastName, int birthYear, EyesColor color, Couple* parents) :
	m_firstName(firstName), m_lastName(lastName), m_birthYear(birthYear), m_eyesColor(color)
{
	m_brotherhood = new Brotherhood(this, parents);
}
