#include "Person.h"

#include <iostream>
using namespace std;



Person::Person(string firstName, string lastName, int birthYear, int deathYear, Color color) :
	m_firstName(firstName), m_lastName(lastName),m_birthYear(birthYear),m_deathYear(deathYear),m_eyesColor(color)
{
	m_brother = nullptr;
	m_child = nullptr;
	m_mother = nullptr;
	m_father = nullptr;
}

Person::Person(string firstName, string lastName, int birthYear, Color color):
	m_firstName(firstName), m_lastName(lastName), m_birthYear(birthYear), m_eyesColor(color)
{
	m_brother = nullptr;
	m_child = nullptr;
	m_mother = nullptr;
	m_father = nullptr;
}


void Person::addChildToMother(Person * child)
{
	child->setMother(this);
	if (this->m_child == nullptr) {
		this->m_child = child;
	}
	else {
		child->m_brother = this->m_child;
		this->m_child = child;
	}
}


void Person::addChildToFather(Person * child)
{
	child->setFather(this);
	if (this->m_child == nullptr) {
		this->m_child = child;
	}
	else {
		child->m_brother = this->m_child;
		this->m_child = child;
	}
}

void Person::addBrother(Person * brother)
{
	Person* current = this;
	while (current->m_brother != nullptr){
		current = current->getBrother();
	}
	brother->setMother(current->getMother());
	brother->setFather(current->getFather());
	current->m_brother = brother;	
}

void Person::printInfo()
{
	cout << this->getFirstName().c_str() << ":"<< endl;
	if (this->getMother() != nullptr)
		cout << "Mother : " << this->getMother()->getFirstName().c_str()  << endl;
	if (this->getFather() != nullptr)
		cout << "Father : " << this->getFather()->getFirstName().c_str()  << endl;
	
}


vector<Person*> Person::getChildren()
{
	vector<Person*> children;
	Person* current = this->m_child;
	if (m_child != nullptr) {
		while (current->m_brother != nullptr) {
			children.push_back(current);
			current = current->getBrother();
		}
	}
	return children;
}
