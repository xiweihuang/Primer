#include "BinarySearchTree.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	BinarySearchTree<int> bt;
	vector<int> v = {10, 28, 12, 53, 21, 9, 30, 8, 11, 5, 7};
	for (int i = 0; i < v.size(); ++i) {
		bt.insert(v[i]);
	}
	// bt.preOrder();
	// cout << "=======" << endl;
	// bt.preOrder_non_recursion();

	// bt.inOrder();
	// cout << "=============" << endl;
	// bt.inOrder_non_recursion();

	bt.postOrder();
	cout << "===============" << endl;
	bt.postOrder_non_recursion();
	
	// bt.printTree();
	// cout << bt.findMax() << endl;
	// cout << bt.findMin() << endl;

	// BinarySearchTree<int> tt(bt);
	// bt.makeEmpty();
	// bt.preOrder();
	// cout << "=====" << bt.isEmpty() << endl;
	// tt.remove(10);
	// tt.preOrder();
	return 0;
}