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

void FamilyTree::addChildMother(Person *mother, Person* child) {
	child->setMother(mother);
	if (mother->getChild() == nullptr) {
		mother->setChild(child);
	}
	else {
		//Une mère a un lien vers un seul fils, mais si ces fils ne sont pas du même père ?
	}
}

void FamilyTree::addChildFather(Person *father, Person* child) {
	child->setFather(father);
	if (father->getChild() == nullptr) {
		father->setChild(child);
	}
	else {
		//Une père a un lien vers un seul fils, mais si ces fils ne sont pas de la même mère ?
	}
}



void FamilyTree::addBrother(Person *brotherTarget, Person* toAdd) {
	//set father and mother
	toAdd->setFather(brotherTarget->getFather());
	toAdd->setMother(brotherTarget->getMother());

	//insert toAdd between brotherTarget and brotherTarget->BrotherL
	Person *leftBrother = brotherTarget->getBrotherL();
	brotherTarget->setBrotherL(toAdd);

	if (leftBrother != nullptr) {
		toAdd->setBrotherL(leftBrother);
	}
}

void FamilyTree::removePerson(Person *toRemove){}
void FamilyTree::removeBrother(Person *toRemove) {}
void FamilyTree::removeFather(Person *toRemove){}
void FamilyTree::removeMother(Person *toRemove){}
void FamilyTree::removeChild(Person *toRemove) {}


int	 FamilyTree::size() {}

void FamilyTree::descendantsInOrder(Person const& p) {}

void FamilyTree::descendantsPreOrder(Person const& p) {}

void FamilyTree::descendantsPostOrder(Person const& p) {}

void FamilyTree::addFamilyMember(Person* p) {}

void FamilyTree::whoHasEyesThatColor(Color c) {}

void FamilyTree::ancestorsWhoHasEyesThatColor(Color c) {}

float FamilyTree::averageAge() {}