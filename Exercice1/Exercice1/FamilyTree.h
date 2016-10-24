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
	//give the list of all Person in the family of p who has eye color c
	vector<Person*>	whoHasEyesThatColor(Person * p, Color c, Order order);
	//give the list of all Person in the ancestors of p who has eye color c
	vector<Person*>	ancestorsWhoHasEyesThatColor(Person * p, Color c, Order order);
	float	averageAge(Order order);
	int numberOfPersonsInFamily(Person*p);
	//give the list of all Person in the family of p
	vector<Person*> peopleInFamily(Person*p, Order order);
	//give the list of all ancestors in the family of p
	vector<Person*> ancestors(Person * p, Order order);
	//give the list of all descendants in the family of p
	vector<Person*> descendants(Person*p, Order order);
private:
	Person* m_familyMember;
};

#endif