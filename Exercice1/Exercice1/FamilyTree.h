#ifndef FAMILY_TREE_H
#define FAMILY_TREE_H

#include "Person.h"

class FamilyTree
{
public:
	FamilyTree();
	FamilyTree(Person *familyMember);
	~FamilyTree();

	void addChild(Person *motherTarget, Person *fatherTarger, Person* child);
	void addChild(Person *parentTarget, Person* child);
	void addParent(Person *parentTarget, Person* child);
	void addBrother(Person *brotherTarget, Person* toAdd);



	int		size();
	void	descendantsInOrder(Person const& p);
	void	descendantsPreOrder(Person const& p);
	void	descendantsPostOrder(Person const& p);
	void	addFamilyMember(Person* p);
	void	whoHasEyesThatColor(Color c);
	void	ancestorsWhoHasEyesThatColor(Color c);
	float	averageAge();

private:
	Person* m_familyMember;
};

#endif