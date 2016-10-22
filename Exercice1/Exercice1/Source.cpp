#include <cstdlib>
#include <iostream>

#include "FamilyTree.h"
#include "Person.h"

using namespace std;

void main(void)
{
	Person *A = new Person("A", "_", 1917, 2000, Color::BLUE);
	Person *B = new Person("B", "_", 1917, 2000, Color::BLUE);
	Person *C = new Person("C", "_", 1917, 2000, Color::BLUE);
	Person *D = new Person("D", "_", 1917, 2000, Color::BLUE);
	Person *E = new Person("E", "_", 1917, 2000, Color::BLUE);
	Person *F = new Person("F", "_", 1917, 2000, Color::BLUE);
	Person *G = new Person("G", "_", 1917, 2000, Color::BLUE);
	Person *H = new Person("H", "_", 1917, 2000, Color::BLUE);
	Person *I = new Person("I", "_", 1917, 2000, Color::BLUE);
	Person *J = new Person("J", "_", 1917, 2000, Color::BLUE);
	Person *K = new Person("K", "_", 1917, 2000, Color::BLUE);
	Person *L = new Person("L", "_", 1917, 2000, Color::BLUE);
	Person *M = new Person("M", "_", 1917, 2000, Color::BLUE);
	Person *N = new Person("N", "_", 1917, 2000, Color::BLUE);
	Person *O = new Person("O", "_", 1917, 2000, Color::BLUE);




	FamilyTree ftree = FamilyTree(I);
	ftree.addChildToFather(M, O);
	ftree.addChild(I, J, M);
	ftree.addBrother(M, N);
	ftree.addBrother(M, L);



	ftree.addChild(G, I, K);
	ftree.addBrother(I, H);

	I->printInfo();

	ftree.addChild(D, E, I);
	ftree.addChildToFather(C, E);
	ftree.addBrother(E, F);

	ftree.addChild(A, B, D);

	
	system("PAUSE");
}