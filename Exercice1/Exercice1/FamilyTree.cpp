#include "FamilyTree.h"



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
	return 0;
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
	return vector<Person*>();
}

vector<Person*> FamilyTree::ancestorsWhoHasEyesThatColor(Person * p, Color c)
{
	return vector<Person*>();
}


float FamilyTree::averageAge()
{
	return 0.0f;
}



