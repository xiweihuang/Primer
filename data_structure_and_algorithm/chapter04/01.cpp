template <typename Comparable>
class BinarySearchTree
{
public:
	BinarySearchTree();
	BinarySearchTree(const BinarySearchTree& rhs);
	~BinarySearchTree();

	const Comparable& findMin() const
	{
		return findMin(root);
	}

	const Comparable& findMax() const
	{
		return findMax(root);
	}

	bool contains(const Comparable& x) const
	{
		return contains(x, root);
	}

	bool isEmpty() const;
	void printTree() const;

	void makeEmpty();
	void insert(const Comparable& x)
	{
		insert(x, root);
	}
	void remove(const Comparable& x)
	{
		remove(x, root);
	}

	const BinarySearchTree& operator=(const BinarySearchTree& rhs);

private:
	struct BinaryNode
	{
		Comparable element;
		BinaryNode* left;
		BinaryNode* right;

		BinaryNode(const Comparable& theElement, BinaryNode* lt, BinaryNode* rt)
		  : element(theElement), left(lt), right(rt) {}
	};

	BinaryNode* root;

	void insert(const Comparable& x, BinaryNode*& t) const
	{
		if (t == NULL)
			t = new BinaryNode(x, NULL, NULL);
		else if (x < t->element)
			insert(x, t->left);
		else if (t->element < x)
			insert(x, t->right);
	}

	void remove(const Comparable& x, BinaryNode*& t) const
	{
		if (t == NULL)
			return;
		if (x < t->element)
			remove(x, t->left);
		else if (t->element < x)
			remove(x, t->right);
		else if (t->left != NULL && t->right != NULL) {
			t->element = findMin(t->right)->element;
			remove(t->element, t->right);
		}
		else {
			BinaryNode* oldNode = t;
			t = (t->left != NULL) ? t->left : t->right;
			delete oldNode;
		}
	}

	// recursion
	BinaryNode* findMin(BinaryNode* t) const
	{
		if (t == NULL)
			return NULL;
		if (t->left == NULL)
			return t;
		return findMin(t->left);
	}

	// not recursion
	BinaryNode* findMax(BinaryNode* t) const
	{
		if (t != NULL) {
			while (t->right != NULL) {
				t = t->right;
			}
		}
		return t;
	}

	bool contains(const Comparable& x, BinaryNode* t) const
	{
		if (t == NULL) {
			return false;
		} else if (x < t->element) {
			return contains(x, t->left);
		} else if (t->element < x) {
			return contains(x, t->right);
		} else {
			return true;  // Match
		}
	}

	void makeEmpty(BinaryNode*& t);
	void printTree(BinaryNode* t) const;
	BinaryNode* clone(BinaryNode* t) const;
};