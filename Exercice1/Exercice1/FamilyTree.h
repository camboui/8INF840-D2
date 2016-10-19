#ifndef FAMILY_TREE_H
#define FAMILY_TREE_H

#include "Person.h"

class FamilyTree
{
public:
	FamilyTree();
	~FamilyTree();

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