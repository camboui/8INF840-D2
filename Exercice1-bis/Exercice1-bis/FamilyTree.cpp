#include "FamilyTree.h"



FamilyTree::FamilyTree()
{
}


FamilyTree::~FamilyTree()
{
}

void FamilyTree::addMember(Person * new_member)
{
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

void FamilyTree::addFamilyMember(Person * p)
{
	//if parents are known
	Couple* parent = p->getParents();
	if (parent != nullptr) {
		parent->addChildren(p);
	}

	//if brothers are known
	Brotherhood * brotherhood = p->getBrotherhood();
	if (brotherhood != nullptr) {
		p->setParents(brotherhood->getParents());
	}


	Brotherhood * children = p->getOwnCouple()->getChildren();
	if (children != nullptr) {
		children->setParents(p);
	}

}

void FamilyTree::whoHasEyesThatColor(EyesColor c)
{
}

void FamilyTree::ancestorsWhoHasEyesThatColor(EyesColor c)
{
}

float FamilyTree::averageAge()
{
	return 0.0f;
}
