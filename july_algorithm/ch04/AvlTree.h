#ifndef AVL_TREE_H
#define AVL_TREE_H

template <typename T>
class AvlTree 
{
private:
	struct AvlNode
	{
		T element;
		AvlNode* left;
		AvlNode* right;
		int height;

		AvlNode(const T& e, AvlNode* l = NULL, AvlNode* r = NULL, int h = 0)
		  : element(e), left(l), right(r), height(h) {}
	};

private:
	int height(AvlNode* t) const
	{
		return t == NULL ? -1 : t->height;
	}

	void insert(const T& x, AvlNode*& t)
	{
		if (t == NULL) {
			t = new AvlNode(x);
		} else if (x < t->element) {
			insert(x, t->left);
			if (height(t->left) - height(t->right) == 2) {
				if (x < t->left->element)
					rotateWithLeftChild(t);
				else
					doubleWithLeftChild(t);
			}
		} else if (t->element < x) {
			insert(x, t->right);
			if (height(t->right) - height(t->left) == 2) {
				if (t->right->element < x)
					rotateWithRightChild(t);
				else
					doubleWithRightChild(t);
			}
		} else {
			// do something
		}
		t->height = max(height(t->left), height(t->right)) + 1;
	}

	void rotateWithLeftChild(AvlNode*& k2)
	{
		// AvlNode* k1 = k2->left;
		
	}

};

#endif