#include <iostream>
#include "FamilyTree.h"

using namespace std;

int main(void) {

	FamilyTree ftree = FamilyTree();


	Person jeanPatrick = Person("jean", "patrick", 1900, EyesColor::BLUE);
	Person jeanneMarie = Person("jeanne", "marie", 1900, EyesColor::AMBER);
	Couple coupleJeanJeanne = Couple(&jeanPatrick, &jeanPatrick);
	Person quentinMace = Person("quentin", "mace", 1993, EyesColor::BROWN);
	Person bob = Person("bob", "mace", 1993, EyesColor::BROWN);

	ftree.addParentsToAChild(&bob, &jeanPatrick, &jeanneMarie);




	return 0;
}