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


int Person::sizeUpper()
{
	int sizeUpperMother(0), sizeUpperFather(0);
	if (getMother() != nullptr) {
		sizeUpperMother = 1+getMother()->sizeUpper();
	} 
	if (getFather() != nullptr) {
		sizeUpperFather = 1+getFather()->sizeUpper();
	} 
	if (sizeUpperFather > sizeUpperMother) {
		return sizeUpperFather;
	}
	else {
		return sizeUpperMother;
	}
}

int Person::sizeLower()
{
	int size = 0;
	std::vector<Person*> children = getChildren();
	for (int i = 0; i < children.size(); i++)
	{
		int sizeI = 1 + children[i]->sizeLower();
		if (sizeI > size) {
			size = sizeI;
		}
	}
	return size;
}

int Person::numberOfPersonsInFamily()
{
	int nbPersUp(0);
	if (getFather() != nullptr) {
		nbPersUp++;
	}
	if (getMother() != nullptr) {
		nbPersUp++;
	}
	nbPersUp += getFather()->numberOfPersonsInFamilyUpper();
	nbPersUp += getMother()->numberOfPersonsInFamilyUpper();
	int nbPersLowMe = numberOfPersonsInFamilyLower();
	std::vector<Person*> bros = getBrothers();
	int nbPersLowBros(0);
	for (int i = 0; i < bros.size(); i++) {
		nbPersLowBros += bros[i]->numberOfPersonsInFamilyLower();
	}
	return nbPersUp;
	//return 1 + nbPersUp + nbPersLowMe + nbPersLowBros + bros.size();
}

int Person::numberOfPersonsInFamilyUpper() {
	//cout << "numberOfPersonsInFamilyUpper of " << m_firstName.c_str() << endl;
	int nbPersUp(0);
	if (this != nullptr) {
		if (getMother() != nullptr) {
			nbPersUp += getMother()->numberOfPersonsInFamilyUpper();
			nbPersUp ++;
		}
		if (getFather() != nullptr) {
			nbPersUp = getFather()->numberOfPersonsInFamilyUpper();
			nbPersUp ++;
		}
		std::vector<Person*> bros = getBrothers();
		nbPersUp += bros.size();
		for (int i = 0; i < bros.size(); i++) {
			nbPersUp += bros[i]->numberOfPersonsInFamilyLower();
		}
	}
	return nbPersUp;
}

int Person::numberOfPersonsInFamilyLower() {
	//cout << "numberOfPersonsInFamilyLower of " << m_firstName.c_str() << endl;
	int nbPersLowMyChildren(0);
	int nbChildren(0);
	if (this != nullptr) {
		std::vector<Person*> children = getChildren();
		nbChildren = children.size();
		for (int i = 0; i < children.size(); i++) {
			nbPersLowMyChildren += children[i]->numberOfPersonsInFamilyLower();
		}
	}
	return nbPersLowMyChildren + nbChildren;
}