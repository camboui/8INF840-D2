#include "Person.h"

#include <iostream>
using namespace std;



Person::Person(string firstName, string lastName, int birthYear, int deathYear, Color color) :
	m_firstName(firstName), m_lastName(lastName),m_birthYear(birthYear),m_deathYear(deathYear),m_eyesColor(color)
{
	m_brother = this;
	m_child = nullptr;
	m_mother = nullptr;
	m_father = nullptr;
}

Person::Person(string firstName, string lastName, int birthYear, Color color):
	m_firstName(firstName), m_lastName(lastName), m_birthYear(birthYear), m_eyesColor(color)
{
	m_brother = this;
	m_child = nullptr;
	m_mother = nullptr;
	m_father = nullptr;
}


void Person::addChildToMother(Person * child)
{
	child->setMother(this);
	if (this->m_child == nullptr) {
		this->m_child = child;

		//Update all brother's mother
		Person*current = this->m_child;
		while (current->m_brother != this->m_child) {
			current = current->m_brother;
			current->setMother(this);
		}
	}
	else {
		this->m_child->addBrother(child);
	}
}


void Person::addChildToFather(Person * child)
{
	child->setFather(this);
	if (this->m_child == nullptr) {
		this->m_child = child;

		//Update all brother's father
		Person*current = this->m_child;
		while (current->m_brother != this->m_child) {
			current = current->m_brother;
			current->setFather(this);
		}
	}
	else {
		this->m_child->addBrother(child);
	}
}

void Person::addBrother(Person * brother)
{
	brother->setMother(this->getMother());
	brother->setFather(this->getFather());

	Person*current = this;
	while (current->m_brother != this) {
		current = current->m_brother;
	}

	current->m_brother = brother;
	brother->m_brother = this;
}


void Person::printInfo()
{
	cout << this->getFirstName().c_str() << ":" << endl;
	if (this->getMother() != nullptr)
		cout << "Mother : " << this->getMother()->getFirstName().c_str() << endl;
	if (this->getFather() != nullptr)
		cout << "Father : " << this->getFather()->getFirstName().c_str() << endl;

	cout << "Children : ";
	vector<Person*> children = getChildren();
	for (unsigned int i = 0; i < children.size(); i++) {
		cout << children[i]->getFirstName().c_str() << " - ";
	}

	cout << endl << "Brothers : ";
	vector<Person*> brothers = getBrothers();
	for (unsigned int i = 0; i < brothers.size(); i++) {
		cout << brothers[i]->getFirstName().c_str() << " - ";
	}
	cout << endl;
}



vector<Person*> Person::getChildren()
{
	vector<Person*> children;
	Person* current = this->m_child;
	if (current != nullptr) {
		children.push_back(current);
		while (current->m_brother != this->m_child) {
			current = current->m_brother;
			children.push_back(current);
		}
	}
	return children;
}

vector<Person*> Person::getBrothers()
{
	vector<Person*> brothers;
	Person*current = this;
	if (current->m_brother != nullptr) {
		while (current->m_brother != this) {
			current = current->m_brother;
			brothers.push_back(current);
		}
	}
	return brothers;
}
