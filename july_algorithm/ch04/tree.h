#ifndef TREE_H
#define TREE_H

#include <iostream>

template <typename T>
class BinaryTree
{
public:
	BinaryTree() {}

	BinaryTree(const BinaryTree& rhs)
	{
		operator=(rhs);
	}

	~BinaryTree()
	{
		makeEmpty();
	}

	const T& findMin() const
	{
		return findMin(root_)->value;
	}

	const T& findMax() const
	{
		return findMax(root_)->value;
	}

	bool contains(const T& x) const
	{
		return contains(x, root_);
	}

	bool isEmpty() const
	{
		return (root_ == NULL);
	}

	void printTree() const
	{
		printTree(root_);
	}

	// 前序
	void preOrder() const
	{
		preOrder(root_);
		std::cout << std::endl;
	}

	// 中序
	void inOrder() const
	{
		inOrder(root_);
		std::cout << std::endl;

	}

	// 后序
	void postOrder() const
	{
		postOrder(root_);
		std::cout << std::endl;
	}

	void makeEmpty()
	{
		makeEmpty(root_);
	}
	void insert(const T& x)
	{
		insert(x, root_);
	}

	void remove(const T& x)
	{
		remove(x, root_);
	}

	const BinaryTree& operator=(const BinaryTree& rhs)
	{
		if (this != &rhs) {
			makeEmpty();
			root_ = clone(rhs.root_);
		}
		return *this;
	}


private:
	struct TreeNode
	{
		T value;
		TreeNode* pLeft;
		TreeNode* pRight;
		TreeNode(const T& v, TreeNode* left, TreeNode* right) : value(v), pLeft(left), pRight(right) {}
	};

private:
	// 插入一个结点
	void insert(const T& x, TreeNode*& t) const
	{
		if (t == NULL)
			t = new TreeNode(x, NULL, NULL);  // 这里的t是一个引用
		else if (x < t->value)
			insert(x, t->pLeft);
		else if (t->value < x)
			insert(x, t->pRight);
		// else
	}

	void remove(const T& x, TreeNode*& t) const
	{
		if (t == NULL)
			return;
		if (x < t->value)
			remove(x, t->pLeft);
		else if (t->value < x)
			remove(x, t->pRight);
		else if (t->pLeft != NULL && t->pRight != NULL) {
			t->value = findMin(t->pRight)->value;
			remove(t->value, t->pRight);
		} else {
			TreeNode* oldNode = t;
			t = (t->pLeft != NULL) ? t->pLeft : t->pRight;
			delete oldNode;
		}
	}

	TreeNode* findMin(TreeNode* t) const
	{
		if (t == NULL)
			return NULL;
		if (!t->pLeft)
			return t;
		return findMin(t->pLeft);
	}

	TreeNode* findMax(TreeNode* t) const
	{
		if (t != NULL) {
			while (t->pRight != NULL)
				t = t->pRight;
		}
		return t;
	}

	bool contains(const T& x, TreeNode* t) const
	{
		if (t == NULL) {
			return false;
		} else if (x < t->value) {
			return contains(x, t->pLeft);
		} else if (t->value < x) {
			return contains(x, t->pRight);
		} else {
			return true;  // match
		}
	}

	void makeEmpty(TreeNode*& t)
	{
		if (t != NULL) {
			makeEmpty(t->pLeft);
			makeEmpty(t->pRight);
			delete t;
		}
		t = NULL;
	}

	void printTree(TreeNode* t) const
	{
		if (t == NULL)
			return;
		std::cout << t->value << std::endl;
		printTree(t->pLeft);
		printTree(t->pRight);
	}

	// 前序遍历
	void preOrder(TreeNode* t) const
	{
		if (!t)
			return;
		std::cout << t->value << ' ';
		preOrder(t->pLeft);
		preOrder(t->pRight);
	}

	// 中序遍历
	void inOrder(TreeNode* t) const
	{
		if (t) {
			inOrder(t->pLeft);
			std::cout << t->value << ' ';
			inOrder(t->pRight);
		}
	}

	// 后序遍历
	void postOrder(TreeNode* t) const
	{
		if (t) {
			postOrder(t->pLeft);
			postOrder(t->pRight);
			std::cout << t->value << ' ';
		}
	}


	TreeNode* clone(TreeNode* t) const
	{
		if (t == NULL)
			return NULL;
		return new TreeNode(t->value, clone(t->pLeft), clone(t->pRight));
	}
	

private:
	TreeNode* root_;
};

#endif