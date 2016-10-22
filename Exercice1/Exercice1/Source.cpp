#include <cstdlib>
#include <iostream>

#include "FamilyTree.h"
#include "Person.h"

using namespace std;

void main(void)
{
	Person *A = new Person("A", "_", 1917, 2000, Color::GRAY);
	Person *B = new Person("B", "_", 1917, 2000, Color::AMBER);
	Person *C = new Person("C", "_", 1917, 2000, Color::BROWN);
	Person *D = new Person("D", "_", 1917, 2000, Color::BLUE);
	Person *E = new Person("E", "_", 1917, 2000, Color::GREEN);
	Person *F = new Person("F", "_", 1917, 2000, Color::HAZEL);
	Person *G = new Person("G", "_", 1917, 2000, Color::AMBER);
	Person *H = new Person("H", "_", 1917, 2000, Color::GREEN);
	Person *I = new Person("I", "_", 1917, 2000, Color::GRAY);
	Person *J = new Person("J", "_", 1917, 2000, Color::BLUE);
	Person *K = new Person("K", "_", 1917, 2000, Color::BROWN);
	Person *L = new Person("L", "_", 1917, 2000, Color::AMBER);
	Person *M = new Person("M", "_", 1917, 2000, Color::GRAY);
	Person *N = new Person("N", "_", 1917, 2000, Color::HAZEL);
	Person *O = new Person("O", "_", 1917, 2000, Color::BROWN);




	FamilyTree ftree = FamilyTree(I);
	ftree.addChildToFather(M, O);
	ftree.addChild(I, J, M);
	ftree.addBrother(M, N);
	ftree.addBrother(M, L);


	
	
	ftree.addChild(G, H, K);
	ftree.addBrother(I, H);
	ftree.addChild(D, E, I);
	//
	//ftree.addChildToFather(C, E);
	//ftree.addBrother(E, F);
	//
	//ftree.addChild(A, B, D);

	I->printInfo();
	H->printInfo();
	K->printInfo();
	system("PAUSE");
}