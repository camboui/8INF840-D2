#include <cstdlib>
#include <iostream>

#include "FamilyTree.h"
#include "Person.h"

using namespace std;

void main(void)
{
	FamilyTree ftree = FamilyTree(new Person("jean", "sebastien", 1917, -1, Color::BLUE));
	cout << "" << endl;
}