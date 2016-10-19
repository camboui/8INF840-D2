#include "FamilyTree.h"



FamilyTree::FamilyTree()
{
}

FamilyTree::FamilyTree(Person *familyMember):m_familyMember(familyMember)
{
}

FamilyTree::~FamilyTree()
{
}

void FamilyTree::addChild(Person *mother, Person *father, Person* child) {}

int	 FamilyTree::size() {}

void FamilyTree::descendantsInOrder(Person const& p) {}

void FamilyTree::descendantsPreOrder(Person const& p) {}

void FamilyTree::descendantsPostOrder(Person const& p) {}

void FamilyTree::addFamilyMember(Person* p) {}

void FamilyTree::whoHasEyesThatColor(Color c) {}

void FamilyTree::ancestorsWhoHasEyesThatColor(Color c) {}

float FamilyTree::averageAge() {}