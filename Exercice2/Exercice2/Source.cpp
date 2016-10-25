#include <fstream>
#include <sstream>
#include <iostream>

#include "Tree234.h"
#include "LegoParser.h"

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
	
	if (tree.isEmpty()) {
		cout << "tree is empty" << endl;
	}
	else {
		cout << "tree is not empty" << endl;
	}

	Node<Lego>* n = tree.findNode(legos[0]);
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

	system("pause");
	return 0;
}