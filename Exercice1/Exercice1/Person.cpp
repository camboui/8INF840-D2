#include "Person.h"


#include <limits>
#include <iostream>
using namespace std;



Person::Person(string firstName, string lastName, int birthYear, int deathYear, Color color) :
	m_firstName(firstName), m_lastName(lastName), m_birthYear(birthYear), m_deathYear(deathYear), m_eyesColor(color)
{
	m_brother = this;
	m_child = nullptr;
	m_mother = nullptr;
	m_father = nullptr;
}

Person::Person(string firstName, string lastName, int birthYear, Color color) :
	m_firstName(firstName), m_lastName(lastName), m_birthYear(birthYear), m_eyesColor(color)
{
	m_brother = this;
	m_child = nullptr;
	m_mother = nullptr;
	m_father = nullptr;
	m_deathYear = numeric_limits<int>::max();
}

bool Person::isAgeCorrectForMother()
{
	if (this->getMother() == nullptr)
		return true;

	bool olderThanMother = this->getMother()->getBirthYear() < this->getBirthYear();
	bool youngerThanDeath = this->getMother()->getDeathYear() > this->getBirthYear();
	return olderThanMother && youngerThanDeath;
}


bool Person::isAgeCorrectForFather()
{
	if (this->getFather() == nullptr)
		return true;

	bool olderThanFather = this->getFather()->getBirthYear() < this->getBirthYear();
	bool youngerThanDeath = this->getFather()->getDeathYear() > this->getBirthYear();
	return olderThanFather && youngerThanDeath;
}


void Person::addChildToMother(Person * child)
{
	child->setMother(this);
	if (!child->isAgeCorrectForMother())
		throw logic_error("Children can't be older than parent");
	//if there is no child
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
		//add child at the good place
		this->m_child->addBrother(child);
	}
}


void Person::addChildToFather(Person * child)
{
	child->setFather(this);
	if (!child->isAgeCorrectForFather())
		throw logic_error("Children can't be older than parent");
	//if there is no child
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
		//add child at the good place
		this->m_child->addBrother(child);
	}
}

void Person::addBrother(Person * brother)
{
	brother->setMother(this->getMother());
	brother->setFather(this->getFather());
	if (!brother->isAgeCorrectForFather() || !brother->isAgeCorrectForMother())
		throw logic_error("Children can't be older than parent");

	//find end of brothers
	Person*current = this;
	while (current->m_brother != this) {
		current = current->m_brother;
	}
	//make it loop
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
		//add every brother of the first child
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
		//add every brother of the first brother
		while (current->m_brother != this) {
			current = current->m_brother;
			brothers.push_back(current);
		}
	}
	return brothers;
}

//look for the higher size from point to top
int Person::sizeUpper()
{
	int sizeUpperMother(0), sizeUpperFather(0);
	if (getMother() != nullptr) {
		sizeUpperMother = 1 + getMother()->sizeUpper();
	}
	if (getFather() != nullptr) {
		sizeUpperFather = 1 + getFather()->sizeUpper();
	}
	if (sizeUpperFather > sizeUpperMother) {
		return sizeUpperFather;
	}
	else {
		return sizeUpperMother;
	}
}

//look for the higher size from point to bottom
int Person::sizeLower()
{
	int size = 0;
	std::vector<Person*> children = getChildren();
	for (unsigned int i = 0; i < children.size(); i++)
	{
		int sizeI = 1 + children[i]->sizeLower();
		if (sizeI >= size) {
			size = sizeI;
		}
	}
	return size;
}

//According to blood relationship
int Person::numberOfPersonsInFamily()
{
	int nbPersUp(0);
	nbPersUp = numberOfPersonsInFamilyUpper();
	int nbPersLowMe = numberOfPersonsInFamilyLower();
	return 1 + nbPersUp + nbPersLowMe;
}

int Person::numberOfPersonsInFamilyUpper() {
	int nbPersUp(0);

	if (this != nullptr) {
		//goes up if it can
		if (getMother() != nullptr) {
			nbPersUp += getMother()->numberOfPersonsInFamilyUpper();
			nbPersUp++;
		}
		if (getFather() != nullptr) {
			nbPersUp += getFather()->numberOfPersonsInFamilyUpper();
			nbPersUp++;
		}
		//don't forget to count brothers
		std::vector<Person*> bros = getBrothers();
		nbPersUp += bros.size();
		for (unsigned int i = 0; i < bros.size(); i++) {
			nbPersUp += bros[i]->numberOfPersonsInFamilyLower();
		}
	}
	return nbPersUp;
}

int Person::numberOfPersonsInFamilyLower() {
	int nbPersLowMyChildren(0);
	int nbChildren(0);
	if (this != nullptr) {
		std::vector<Person*> children = getChildren();
		nbChildren = children.size();
		for (unsigned int i = 0; i < children.size(); i++) {
			nbPersLowMyChildren += children[i]->numberOfPersonsInFamilyLower();
		}
	}
	return nbPersLowMyChildren + nbChildren;
}




//According to blood relationship
vector<Person*> Person::peopleInFamily(Order order)
{
	vector<Person*> people;
	if (order == Order::PRE)
		people.push_back(this);
	//find ancestors and descendants adding also brothers
	vector<Person*> temp1 = peopleInFamilyUpper(order);
	people.insert(people.end(), temp1.begin(), temp1.end());

	vector<Person*> temp2 = peopleInFamilyLower(order);
	people.insert(people.end(), temp2.begin(), temp2.end());

	if (order == Order::POST)
		people.push_back(this);
	return people;
}


vector<Person*> Person::Ancestors(Person *initialNode, Order order) {
	vector<Person*> people;
	vector<Person*> temp;

	if (this != nullptr) {
		if (getMother() != nullptr) {
			if (order == Order::PRE)
				people.push_back(getMother());

			temp = getMother()->Ancestors(initialNode, order);
			people.insert(people.end(), temp.begin(), temp.end());

			if (order == Order::POST)
				people.push_back(getMother());
		}
		if (getFather() != nullptr) {
			if (order == Order::PRE)
				people.push_back(getFather());

			temp = getFather()->Ancestors(initialNode, order);
			people.insert(people.end(), temp.begin(), temp.end());

			if (order == Order::POST)
				people.push_back(getFather());
		}
		//Don't look at initialNode brothers
		if (this != initialNode) {
			std::vector<Person*> bros = getBrothers();
			people.insert(people.end(), bros.begin(), bros.end());
		}// insert himself, as requested in homework
		else {
			people.push_back(this);
		}
	}

	return people;
}


vector<Person*> Person::peopleInFamilyUpper(Order order) {
	vector<Person*> people;
	vector<Person*> temp;
	if (this != nullptr) {
		if (getMother() != nullptr) {
			if (order == Order::PRE)
				people.push_back(getMother());

			temp = getMother()->peopleInFamilyUpper(order);
			people.insert(people.end(), temp.begin(), temp.end());

			if (order == Order::POST)
				people.push_back(getMother());
		}
		if (getFather() != nullptr) {
			if (order == Order::PRE)
				people.push_back(getFather());

			temp = getFather()->peopleInFamilyUpper(order);
			people.insert(people.end(), temp.begin(), temp.end());

			if (order == Order::POST)
				people.push_back(getFather());
		}

		std::vector<Person*> bros = getBrothers();
		for (unsigned int i = 0; i < bros.size(); i++) {
			if (order == Order::PRE)
				people.push_back(bros[i]);

			temp = bros[i]->peopleInFamilyLower(order);
			people.insert(people.end(), temp.begin(), temp.end());

			if (order == Order::POST)
				people.push_back(bros[i]);
		}
	}

	return people;
}

vector<Person*> Person::peopleInFamilyLower(Order order) {
	vector<Person*> people;
	vector<Person*> temp;
	if (this != nullptr) {
		std::vector<Person*> children = getChildren();
		for (unsigned int i = 0; i < children.size(); i++) {
			if (order == Order::PRE)
				people.push_back(children[i]);

			temp = children[i]->peopleInFamilyLower(order);
			people.insert(people.end(), temp.begin(), temp.end());

			if (order == Order::POST)
				people.push_back(children[i]);
		}
	}
	return people;
}