#include <iostream>
#include "genBST.h"

using namespace std;

int main() {
	BST<int> tree;
	
	tree.insert(13);
	tree.insert(10);
	tree.insert(25);
	tree.insert(2);
	tree.insert(12);
	tree.insert(20);
	tree.insert(31);
	tree.insert(29);
	
	cout << "Preorder: ";
	tree.preorder();
	cout << endl;
	
	cout << "Inorder: ";
	tree.inorder();
	cout << endl;
	
	cout << "Postorder: ";
	tree.postorder();
	cout << endl;
	
	cout << "Breadth First: ";
	tree.breadthFirst();
	cout << endl;
	
	cout << "Iterative Preorder: ";
	tree.iterativePreorder();
	cout << endl;
	
	cout << "Iterative Inorder: ";
	tree.iterativeInorder();
	cout << endl;
	
	cout << "Iterative Postorder: ";
	tree.iterativePostorder();
	cout << endl;
	
	cout << "Morris Inorder: ";
	tree.MorrisInorder();
	cout << endl;
	
	int value = 20;
	
	if(tree.search(value) != 0) {
		cout << "El valor " << value << " si existe en el arbol." << endl;
	}
	else {
		cout << "El valor " << value << " no existe en el arbol." << endl;
	}
	
	cout << endl;
	cout << "Eliminando 25 por merging..." << endl;
	
	tree.findAndDeleteByMerging(25);
	
	cout << "Inorder despues de eliminar 25: ";
	tree.inorder();
	cout << endl;
	
	cout << endl;
	cout << "Eliminando 10 por copying..." << endl;
	
	tree.findAndDeleteByCopying(10);
	
	cout << "Inorder despues de eliminar 10: ";
	tree.inorder();
	cout << endl;
	
	return 0;
}
