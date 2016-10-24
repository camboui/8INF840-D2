#include "FamilyTree.h"
#include <math.h>
#include <algorithm>

FamilyTree::FamilyTree()
{}

FamilyTree::FamilyTree(Person *familyMember) :m_familyMember(familyMember)
{}

FamilyTree::~FamilyTree()
{}

void FamilyTree::addChild(Person * motherTarget, Person * fatherTarget, Person * child)
{
	fatherTarget->addChildToFather(child);
	motherTarget->addChildToMother(child);
}

void FamilyTree::addChildToMother(Person * mother, Person * child)
{
	mother->addChildToMother(child);
}

void FamilyTree::addChildToFather(Person * father, Person * child)
{
	father->addChildToFather(child);
}

void FamilyTree::addBrother(Person * target, Person * brother)
{
	target->addBrother(brother);
}

void FamilyTree::addMother(Person * target, Person * mother)
{
	target->setMother(mother);
}

void FamilyTree::addFather(Person * target, Person * father)
{
	target->setFather(father);
}

int FamilyTree::size()
{
	if (m_familyMember != nullptr) {
		return 1 + m_familyMember->sizeLower() + m_familyMember->sizeUpper();
	}
	else {
		return 0;
	}
}

vector<Person*> FamilyTree::whoHasEyesThatColor(Person * p, Color c, Order order)
{
	//get people from family and check for color
	vector<Person*> allFamily = p->peopleInFamily(order);
	vector<Person*> goodColor;
	for (vector<Person*>::iterator it = allFamily.begin(); it != allFamily.end(); ++it) {
		if ((*it)->getEyesColor() == c)
			goodColor.push_back(*it);
	}
	return goodColor;
}

vector<Person*> FamilyTree::ancestorsWhoHasEyesThatColor(Person * p, Color c, Order order)
{
	//get people from ancestors and check for color
	vector<Person*> allFamilyUpper = p->Ancestors(p, order);
	vector<Person*> goodColor;
	for (vector<Person*>::iterator it = allFamilyUpper.begin(); it != allFamilyUpper.end(); ++it) {
		if ((*it)->getEyesColor() == c)
			goodColor.push_back(*it);
	}
	return goodColor;
}


float FamilyTree::averageAge(Order order)
{
	//get people from family and sum age
	vector<Person*> allFamily = this->getFamilyMember()->peopleInFamily(order);
	float sum = 0;
	for (vector<Person*>::iterator it = allFamily.begin(); it != allFamily.end(); ++it) {
		if ((*it)->getDeathYear() == numeric_limits<int>::max())
			sum += 2017 - (*it)->getBirthYear();
		else
			sum += (*it)->getDeathYear() - (*it)->getBirthYear();
	}

	return sum / allFamily.size();
}

int FamilyTree::numberOfPersonsInFamily(Person * p)
{
	return p->numberOfPersonsInFamily();
}

vector<Person*> FamilyTree::peopleInFamily(Person * p, Order order)
{
	return p->peopleInFamily(order);
}

vector<Person*> FamilyTree::ancestors(Person * p, Order order)
{
	return p->Ancestors(p, order);
}

vector<Person*> FamilyTree::descendants(Person * p, Order order)
{
	return p->peopleInFamilyLower(order);
}



