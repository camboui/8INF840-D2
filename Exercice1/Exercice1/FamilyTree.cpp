#include "FamilyTree.h"



FamilyTree::FamilyTree()
{}

FamilyTree::FamilyTree(Person *familyMember):m_familyMember(familyMember)
{}

FamilyTree::~FamilyTree()
{}

void FamilyTree::addChild(Person * motherTarget, Person * fatherTarget, Person * child)
{
	motherTarget->addChildToFather(child);
	fatherTarget->addChildToMother(child);
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

void FamilyTree::descendantsInOrder(Person const & p)
{
}

void FamilyTree::descendantsPreOrder(Person const & p)
{
}

void FamilyTree::descendantsPostOrder(Person const & p)
{
}

void FamilyTree::whoHasEyesThatColor(Color c)
{
}

void FamilyTree::ancestorsWhoHasEyesThatColor(Color c)
{
}

float FamilyTree::averageAge()
{
	return 0.0f;
}



