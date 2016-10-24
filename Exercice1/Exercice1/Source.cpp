#include <cstdlib>
#include <iostream>
#include <string>
#include "FamilyTree.h"
#include "Person.h"

using namespace std;
void printVector(vector <Person*> p, string vectorName);

void main(void)
{

	Person *A = new Person("A", "_", 1800, 1850, Color::GRAY);
	Person *B = new Person("B", "_", 1800, 1850, Color::AMBER);
	Person *C = new Person("C", "_", 1800, 1850, Color::BROWN);
	Person *D = new Person("D", "_", 1820, 1870, Color::BLUE);
	Person *E = new Person("E", "_", 1820, 1870, Color::GREEN);
	Person *F = new Person("F", "_", 1820, 1870, Color::HAZEL);
	Person *G = new Person("G", "_", 1850, 1920, Color::AMBER);
	Person *H = new Person("H", "_", 1850, 1920, Color::GREEN);
	Person *I = new Person("I", "_", 1850, 1920, Color::GRAY);
	Person *J = new Person("J", "_", 1850, 1920, Color::BLUE);
	Person *K = new Person("K", "_", 1880, 1950, Color::BROWN);
	Person *L = new Person("L", "_", 1880, 1950, Color::AMBER);
	Person *M = new Person("M", "_", 1880, Color::GRAY);
	Person *N = new Person("N", "_", 1880, 1950, Color::HAZEL);
	Person *O = new Person("O", "_", 1930, Color::BROWN);
	vector<Person*> people{ A,B,C,D,E,F,G,H,I,J,K,L,M,N,O };

	//    A    B    ?      C
	//     \  /      \    /
	//      D        {E  F}
	//        \      /
	//      G  {H  I}     J
	//       \ /    \    /
	//        K     {L M N}
	//                /
	//               O

	//build tree of I
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

	//show tree dependencies
	//for (int i = 0; i < people.size(); i++) {
	//	people[i]->printInfo();
	//}

	cout << "Tree size : " << ftree.size() << endl << endl;

	//Show numberOfPersonsInFamily According to blood relationship
	for (unsigned int i = 0; i < people.size(); i++) {
		cout << "numberOfPersonsInFamily " << people[i]->getFirstName().c_str()
			<< " " << ftree.numberOfPersonsInFamily(people[i]) << endl;
	}
	cout << endl;

	//Show peopleInFamily According to blood relationship PRE-ORDER
	for (unsigned int i = 0; i < people.size(); i++) {
		vector<Person*> temp = ftree.peopleInFamily(people[i], Order::PRE);
		cout << "peopleInFamily (" << people[i]->getFirstName().c_str() << "): ";
		for (unsigned int j = 0; j < temp.size(); j++) {
			cout << temp[j]->getFirstName().c_str() << " - ";
		}
		cout << endl;
	}


	cout << endl << "PRE-ORDER" << endl;
	//Show peopleInFamily According to blood relationship POST-ORDER
	for (unsigned int i = 0; i < people.size(); i++) {
		vector<Person*> temp = ftree.descendants(people[i], Order::PRE);
		cout << "descendants (" << people[i]->getFirstName().c_str() << "): ";
		for (unsigned int j = 0; j < temp.size(); j++) {
			cout << temp[j]->getFirstName().c_str() << " - ";
		}
		cout << endl;
	}

	cout << endl << "POST-ORDER" << endl;
	//Show peopleInFamily According to blood relationship POST-ORDER
	for (unsigned int i = 0; i < people.size(); i++) {
		vector<Person*> temp = ftree.descendants(people[i], Order::POST);
		cout << "descendants (" << people[i]->getFirstName().c_str() << "): ";
		for (unsigned int j = 0; j < temp.size(); j++) {
			cout << temp[j]->getFirstName().c_str() << " - ";
		}
		cout << endl;
	}
	cout << endl << "NO IN-ORDER available : not a binary tree" << endl;

	//Show whoHasEyesThatColor According to blood relationship
	vector<string> names = { "AMBER","BLUE","BROWN","GRAY","GREEN","HAZEL" };
	for (unsigned int i = Color::AMBER; i <= Color::HAZEL; i++) {
		vector<Person*> temp = ftree.whoHasEyesThatColor(I, Color(i), Order::PRE);

		cout << endl << "whoHasEyesThatColor (Family(I)," << names[i].c_str() << "): ";
		for (unsigned int j = 0; j < temp.size(); j++) {
			cout << temp[j]->getFirstName().c_str() << " - ";
		}
	}
	cout << endl;


	//Show whoHasEyesThatColor According to ancestors
	for (unsigned int i = Color::AMBER; i <= Color::HAZEL; i++) {
		vector<Person*> temp = ftree.ancestorsWhoHasEyesThatColor(I, Color(i), Order::PRE);

		cout << endl << "ancestorsWhoHasEyesThatColor (" << names[i].c_str() << ",I): ";
		for (unsigned int j = 0; j < temp.size(); j++) {
			cout << temp[j]->getFirstName().c_str() << " - ";
		}
	}
	cout << endl;

	cout << endl << "Average age : " << ftree.averageAge(Order::PRE) << endl;

	system("PAUSE");
}

void printVector(vector <Person*> p, string vectorName)
{
	cout << endl << vectorName.c_str() << " :";
	for (unsigned int i = 0; i < p.size(); i++)
	{
		cout << p[i]->getFirstName().c_str() << " - ";
	}
	cout << endl;
}