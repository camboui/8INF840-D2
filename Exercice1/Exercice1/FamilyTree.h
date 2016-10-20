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
	void addChildMother(Person *mother, Person* child);
	void addChildFather(Person *father, Person* child);
	void removePerson(Person *toRemove);
	void removeChild(Person *target);



	Person* getFamilyMember() { return m_familyMember; };
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