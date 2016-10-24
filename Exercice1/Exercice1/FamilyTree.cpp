#include "FamilyTree.h"
#include <math.h>
#include <algorithm>

FamilyTree::FamilyTree()
{}

FamilyTree::FamilyTree(Person *familyMember):m_familyMember(familyMember)
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

vector<Person*> FamilyTree::descendantsInOrder(Person * p)
{
	return vector<Person*>();
}

vector<Person*> FamilyTree::descendantsPreOrder(Person * p)
{
	return vector<Person*>();
}

vector<Person*> FamilyTree::descendantsPostOrder(Person * p)
{
	return vector<Person*>();
}

vector<Person*> FamilyTree::whoHasEyesThatColor(Color c)
{
	vector<Person*> allFamily = this->getFamilyMember()->peopleInFamily();
	vector<Person*> goodColor;
	for (vector<Person*>::iterator it = allFamily.begin(); it != allFamily.end(); ++it) {
		if ((*it)->getEyesColor() == c)
			goodColor.push_back(*it);
	}
	return goodColor;
}

vector<Person*> FamilyTree::ancestorsWhoHasEyesThatColor(Person * p, Color c)
{
	return vector<Person*>();
}


float FamilyTree::averageAge()
{
	vector<Person*> allFamily = this->getFamilyMember()->peopleInFamily();
	float sum = 0;
	for (vector<Person*>::iterator it = allFamily.begin(); it != allFamily.end(); ++it) {
		if ((*it)->getDeathYear() != numeric_limits<int>::max())
			sum+= 2017 - (*it)->getBirthYear();
		else
			sum += (*it)->getDeathYear() - (*it)->getBirthYear();

	}

	return sum/allFamily.size();
}




