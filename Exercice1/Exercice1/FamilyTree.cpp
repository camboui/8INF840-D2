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

void FamilyTree::addChild(Person *motherTarget, Person *fatherTarget, Person* child) {

}

void FamilyTree::addChildMother(Person *mother, Person* child) {

}

void FamilyTree::addChildFather(Person *father, Person* child) {}




void FamilyTree::removePerson(Person *toRemove){}

void FamilyTree::removeFather(Person *target){}

void FamilyTree::removeMother(Person *target){}

void FamilyTree::removeChild(Person *target) {}


int	 FamilyTree::size() {}

void FamilyTree::descendantsInOrder(Person const& p) {}

void FamilyTree::descendantsPreOrder(Person const& p) {}

void FamilyTree::descendantsPostOrder(Person const& p) {}

void FamilyTree::addFamilyMember(Person* p) {}

void FamilyTree::whoHasEyesThatColor(Color c) {}

void FamilyTree::ancestorsWhoHasEyesThatColor(Color c) {}

float FamilyTree::averageAge() {}