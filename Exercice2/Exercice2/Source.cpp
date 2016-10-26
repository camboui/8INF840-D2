#include <fstream>
#include <sstream>
#include <iostream>

#include "Tree234.h"
#include "RedBlackTree.h"
#include "LegoParser.h"
#include "TreeConverter.h"

using namespace std;



int main()
{
	
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
	for (unsigned int i = 0; i < legos.size(); i++) {
		Node234<Lego>* n = tree.findNode(legos[i]);
		cout << legos[i].getId().c_str() << ", value found on node : ";
		for (unsigned int j = 0; j < n->getKeys().size(); j++) {
			cout << n->getKey(j).getId().c_str() << " | ";
		}
		cout << endl;
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
	/*
	tree.deleteKey(legos[0]);
	n = tree.findNode(legos[0]);
	if ( n == nullptr){
		cout << "deletion succeeded" << endl;
	}
	else{
		cout << "deletion failed : " << n->getKey(0).getId() << " <-> " << legos[0].getId() << endl;
	}
	*/
	cout << endl << "Transforming to Red Black Tree..." << endl;
	RedBlackTree<Lego> rbtree = toRedBlackTree(tree);

	for (unsigned int i = 0; i < legos.size(); i++) {
		RedBlackNode<Lego>* n = rbtree.findKey(legos[i]);
		if (n != nullptr) {
			if (n->getColor() == RED)
				cout << n->getKey().getId().c_str() << ": RED" << endl;
			else if (n->getColor() == BLACK)
				cout << n->getKey().getId().c_str() << ": BLACK" << endl;
		}
	}

	Tree234<Lego> newtree234 = Tree234<Lego>();
	newtree234 = toTree234(rbtree);
	for (unsigned int i = 0; i < legos.size(); i++) {
		Node234<Lego>* n = tree.findNode(legos[i]);
		cout << legos[i].getId().c_str() << ", value found on node : ";
		for (unsigned int j = 0; j < n->getKeys().size(); j++) {
			cout << n->getKey(j).getId().c_str() << " | ";
		}
		cout << endl;
	}
	/*
	vector<int> vals = { 4,35,10,13,3,30,15,12,7,40,20,11,6 };
	//vector<int> vals = { 1,2,3,4 };
	Tree234<int> tree234;
	for (unsigned int i = 0; i < vals.size(); i++) {
		tree234.addKey(vals[i]);
	}

	for (unsigned int i = 0; i < vals.size(); i++) {
		Node234<int>* n = tree234.findNode(vals[i]);
		cout << vals[i] << ", value found on node : ";
		for (unsigned int j = 0; j < n->getKeys().size(); j++) {
			cout << n->getKey(j) << " | ";
		}
		cout << endl;
	}

	cout << endl << "Transforming to Red Black Tree..." << endl;
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

	Tree234<int> newtree234 = Tree234<int>();
	newtree234 = convertRedBlackTreeIntoTree234(rbtree);

	for (unsigned int i = 0; i < vals.size(); i++) {
		Node234<int>* n = tree234.findNode(vals[i]);
		cout << vals[i] << ", value found on node : ";
		for (unsigned int j = 0; j < n->getKeys().size(); j++) {
			cout << n->getKey(j) << " | ";
		}
		cout << endl;
	}
	*/

	system("pause");
	return 0;
}




