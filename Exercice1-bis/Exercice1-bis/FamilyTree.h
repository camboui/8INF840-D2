#ifndef FAMILY_TREE_H
#define FAMILY_TREE_H

#include "Person.h"

class FamilyTree
{
public:
	FamilyTree();
	~FamilyTree();

	Person* getFamilyMember() { return m_familyMember; };
	void setFamilyMember(Person* familyMember) { m_familyMember = familyMember; };

	void	addMember(Person*  new_member);
	int		size();
	void	descendantsInOrder(Person const& p);
	void	descendantsPreOrder(Person const& p);
	void	descendantsPostOrder(Person const& p);
	void	addFamilyMember(Person* p);
	void	whoHasEyesThatColor(EyesColor c);
	void	ancestorsWhoHasEyesThatColor(EyesColor c);
	float	averageAge();

private:
	Person* m_familyMember;
};

#endif
