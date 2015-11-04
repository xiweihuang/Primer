#include "tree.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	BinaryTree<int> bt;
	vector<int> v = {10, 28, 12, 53, 21, 9, 30, 8, 11, 5, 7};
	for (int i = 0; i < v.size(); ++i) {
		bt.insert(v[i]);
	}
	bt.preOrder();
	bt.inOrder();
	bt.postOrder();
	// bt.printTree();
	// cout << bt.findMax() << endl;
	// cout << bt.findMin() << endl;

	// BinaryTree<int> tt(bt);
	// bt.makeEmpty();
	// bt.printTree();
	// cout << "=====" << bt.isEmpty() << endl;
	// tt.remove(10);
	// tt.printTree();
	return 0;
}