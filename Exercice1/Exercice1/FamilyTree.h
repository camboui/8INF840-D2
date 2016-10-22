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



	Person* getFamilyMember() { return m_familyMember;};
	int		size();
	vector<Person*>	descendantsInOrder(Person * p);
	vector<Person*>	descendantsPreOrder(Person * p);
	vector<Person*>	descendantsPostOrder(Person * p);
	vector<Person*>	whoHasEyesThatColor(Color c);
	vector<Person*>	ancestorsWhoHasEyesThatColor(Person * p, Color c);
	float	averageAge();

private:
	Person* m_familyMember;
};

#endif