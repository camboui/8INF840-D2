#include <fstream>
#include <sstream>
#include <iostream>

#include "Tree234.h"
#include "RedBlackTree.h"
#include "LegoParser.h"

using namespace std;

int main()
{
	/*
	LegoParser lp("50_pieces.txt");
	vector<Lego> legos = lp.parseFile();
	Tree234<Lego> tree;


	if (tree.isEmpty()) {
		cout << "tree is empty" << endl;
	}
	else {
		cout << "tree is not empty" << endl;
	}

	for (unsigned int i = 0; i < legos.size(); i++){
		tree.addKey(legos[i]);
		//cout << legos[i].getId().c_str() << "," << legos[i].getDescription().c_str() << "," << legos[i].getCategory().c_str() << endl;
	}

	if (tree.isEmpty()) {
		cout << "tree is empty" << endl;
	}
	else {
		cout << "tree is not empty" << endl;
	}

	Node234<Lego>* n = tree.findNode(legos[0]);
	cout << "Found node : " << endl;
	cout << n->getKey(0).getId().c_str() << "," << n->getKey(0).getDescription().c_str() << "," << n->getKey(0).getCategory().c_str() << endl;

	tree.deleteKey(legos[0]);
	n = tree.findNode(legos[0]);
	if ( n == nullptr){
		cout << "deletion succeeded" << endl;
	}
	else{
		cout << "deletion failed : " << n->getKey(0).getId() << " <-> " << legos[0].getId() << endl;
	}
	*/

	vector<int> vals = { 4,35,10,13,3,30,15,12,7,40,20,11,6 };
	Tree234<int> tree234;
	for (unsigned int i = 0; i < vals.size(); i++) {
		tree234.addKey(vals[i]);
	}

	for (unsigned int i = 0; i < vals.size(); i++) {
		Node234<int>* n = tree234.findNode(vals[i]);
	}


	RedBlackTree<int> rbtree = tree234.toRBTree();

	for (unsigned int i = 0; i < vals.size(); i++) {
		RedBlackNode<int>* n = rbtree.findKey(vals[i]);
		if (n != nullptr) {
			if (n->getColor() == RED)
				cout << n->getKey() << ": RED" << endl;
			else if (n->getColor() == BLACK)
				cout << n->getKey() << ": BLACK" << endl;
		}
	}


	//RedBlackTree<int> rbtree = RedBlackTree<int>();
	//
	//rbtree.addKey(04);
	//rbtree.addKey(35);
	//rbtree.addKey(10);
	//rbtree.addKey(13);
	//rbtree.addKey(03);
	//rbtree.addKey(30);
	//rbtree.addKey(15);
	//rbtree.addKey(12);
	//rbtree.addKey(07);
	//rbtree.addKey(40);
	//rbtree.addKey(20);
	//rbtree.addKey(11);
	//rbtree.addKey(06);



	
	system("pause");
	return 0;
}