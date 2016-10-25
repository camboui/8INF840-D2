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



	RedBlackTree<int> rbtree = RedBlackTree<int>();
	
	rbtree.addKey(1);
	rbtree.addKey(2);
	rbtree.addKey(5);
	rbtree.addKey(7);
	rbtree.addKey(8);
	rbtree.addKey(11);
	rbtree.addKey(14);
	rbtree.addKey(15);
	rbtree.addKey(4);
	
	cout << rbtree.findKey(1)->getColor() << endl;
	cout << rbtree.findKey(2)->getColor() << endl;
	cout << rbtree.findKey(5)->getColor() << endl;
	cout << rbtree.findKey(7)->getColor() << endl;
	cout << rbtree.findKey(8)->getColor() << endl;
	cout << rbtree.findKey(11)->getColor() << endl;
	cout << rbtree.findKey(14)->getColor() << endl;
	cout << rbtree.findKey(15)->getColor() << endl;
	cout << rbtree.findKey(4)->getColor() << endl;

	system("pause");
	return 0;
}