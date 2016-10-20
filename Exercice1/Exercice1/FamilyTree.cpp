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
	motherTarget->setChild(child);
	fatherTarget->setChild(child);

	child->setMother(motherTarget);
	child->setFather(fatherTarget);
	vector<Person*> motherChildren = motherTarget->getChildren();
	vector<Person*> fatherChildren = fatherTarget->getChildren();
	//... useless
}

void addChild(Person *parentTarget, Person* child) {}
void addParent(Person *parentTarget, Person* child) {}
void addBrother(Person *brotherTarget, Person* toAdd) {}


int	 FamilyTree::size() {}

void FamilyTree::descendantsInOrder(Person const& p) {}

void FamilyTree::descendantsPreOrder(Person const& p) {}

void FamilyTree::descendantsPostOrder(Person const& p) {}

void FamilyTree::addFamilyMember(Person* p) {}

void FamilyTree::whoHasEyesThatColor(Color c) {}

void FamilyTree::ancestorsWhoHasEyesThatColor(Color c) {}

float FamilyTree::averageAge() {}