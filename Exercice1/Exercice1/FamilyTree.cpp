#include "FamilyTree.h"



FamilyTree::FamilyTree()
{}

FamilyTree::FamilyTree(Person *familyMember):m_familyMember(familyMember)
{}

FamilyTree::~FamilyTree()
{}


void FamilyTree::addChild(Person *motherTarget, Person *fatherTarget, Person* child) {
	addChildMother(motherTarget, child);
	addChildFather(fatherTarget, child);
}

void FamilyTree::addChildMother(Person *mother, Person* child) {
	child->setMother(mother);
	mother->getChildren().push_back(child);
}

void FamilyTree::addChildFather(Person *father, Person* child) {
	child->setFather(father);
	father->getChildren().push_back(child);
}


void FamilyTree::removeChild(Person *target) {
	vector<Person*> children = target->getChildren();
	int i = 0;
	while (i < children.size() && children[i] != target)
	{
		i++;
	}
	children.erase(children.begin() + i);
}

void FamilyTree::removePerson(Person *toRemove) {
	if (toRemove->getChildren().size() != 0) {
		throw logic_error("Can't remove someone who has children");
	}

	//remove child from mother
	if (toRemove->getMother() != nullptr) {
		removeChild(toRemove->getMother());
	}
	//remove child from father
	if (toRemove->getFather() != nullptr) {
		removeChild(toRemove->getFather());
	}

	toRemove->~Person();
}



int	 FamilyTree::size() {}

void FamilyTree::descendantsInOrder(Person const& p) {}

void FamilyTree::descendantsPreOrder(Person const& p) {}

void FamilyTree::descendantsPostOrder(Person const& p) {}

void FamilyTree::whoHasEyesThatColor(Color c) {}

void FamilyTree::ancestorsWhoHasEyesThatColor(Color c) {}

float FamilyTree::averageAge() {}