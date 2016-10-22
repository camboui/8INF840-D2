#ifndef FAMILY_TREE_H
#define FAMILY_TREE_H

#include "Person.h"

class FamilyTree
{
public:
	FamilyTree();
	FamilyTree(Person *familyMember);
	~FamilyTree();


	void addChild(Person *motherTarget, Person *fatherTarget, Person* child);
	void addChildToMother(Person *mother, Person* child);
	void addChildToFather(Person *father, Person* child);
	void addBrother(Person *target, Person* brother);
	void addMother(Person *target, Person* mother);
	void addFather(Person *target, Person* father);



	Person* getFamilyMember() { return m_familyMember; };
	int		size();
	void	descendantsInOrder(Person const& p);
	void	descendantsPreOrder(Person const& p);
	void	descendantsPostOrder(Person const& p);
	void	whoHasEyesThatColor(Color c);
	void	ancestorsWhoHasEyesThatColor(Color c);
	float	averageAge();

private:
	Person* m_familyMember;
};

#endif