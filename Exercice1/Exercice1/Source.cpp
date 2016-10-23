#include <cstdlib>
#include <iostream>

#include "FamilyTree.h"
#include "Person.h"

using namespace std;
void printVector(vector <Person*> p, string vectorName);

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


	//    A    B    ?      C
	//     \  /      \    /
	//      D        {E  F}
	//        \      /
	//      G  {H  I}     J
	//       \ /    \    /
	//        K     {L M N}
	//                /
	//               O

	FamilyTree ftree = FamilyTree(I);
	ftree.addChildToFather(M, O);
	ftree.addChild(I, J, M);
	ftree.addBrother(M, N);
	ftree.addBrother(M, L);
	ftree.addChild(G, H, K);
	ftree.addBrother(I, H);
	ftree.addChild(D, E, I);
	ftree.addChildToFather(C, E);
	ftree.addBrother(E, F);
	ftree.addChild(A, B, D);


	
	cout << "FamilyTree size :" << ftree.size() << endl;
	cout << "Average age : " << ftree.averageAge() << endl;

	vector<Person*>	d = ftree.descendantsInOrder(A);
	d = ftree.descendantsPreOrder(A);
	printVector(d, "descendantsPreOrder");

	d = ftree.descendantsPostOrder(A);
	printVector(d, "descendantsPostOrder");

	d = ftree.whoHasEyesThatColor(Color::BLUE);
	printVector(d, "whoHasEyesThatColor");

	d = ftree.ancestorsWhoHasEyesThatColor(A, Color::BLUE);
	printVector(d, "ancestorsWhoHasEyesThatColor");
	
	cout << endl << ftree.getFamilyMember()->numberOfPersonsInFamily() << endl;

	//A->printInfo();
	//B->printInfo();
	//C->printInfo();
	//D->printInfo();
	//E->printInfo();
	//F->printInfo();
	//I->printInfo();
	//H->printInfo();
	//I->printInfo();
	//J->printInfo();
	//K->printInfo();
	//L->printInfo();
	//M->printInfo();
	//N->printInfo();
	//O->printInfo();

	system("PAUSE");
}

void printVector(vector <Person*> p, string vectorName)
{
	cout << endl << vectorName.c_str()<< " :";
	for (unsigned int i = 0; i < p.size(); i++)
	{
		cout << p[i]->getFirstName().c_str() << " - ";
	}
	cout << endl;

}