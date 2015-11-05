#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>
#include <stack>

template <typename T>
class BinarySearchTree 
{
private:
	struct BinaryNode 
	{
		T element;
		BinaryNode* left;
		BinaryNode* right;
		BinaryNode(const T& e, BinaryNode* l = NULL, BinaryNode* r = NULL) : element(e), left(l), right(r) {}
	};

public:
	BinarySearchTree(BinaryNode* r = NULL) : root_(r) {}
	BinarySearchTree(const BinarySearchTree& rhs) { operator=(rhs); }
	~BinarySearchTree() { makeEmpty(); }

	const BinarySearchTree& operator=(const BinarySearchTree& rhs)
	{
		if (this != &rhs) {
			makeEmpty();
			root_ = clone(rhs.root_);
		}
		return * this;
	}

	// max and min
	const T& findMin() const { return findMin(root_)->element; }
	const T& findMax() const { return findMax(root_)->element; }

	bool contains(const T& x) const { return contains(x, root_); }
	bool isEmpty() const { return (root_ == NULL); }

	void makeEmpty() { makeEmpty(root_); }
	void insert(const T& x) { insert(x, root_); }
	void remove(const T& x) { remove(x, root_); }

	// 遍历
	void preOrder()
	{
		preOrder(root_);
		std::cout << std::endl;
	}
	void inOrder()
	{
		inOrder(root_);
		std::cout << std::endl;
	}
	void postOrder()
	{
		postOrder(root_);
		std::cout << std::endl;
	}

private:
	// 递归版本
	BinaryNode* findMin(BinaryNode* t) const 
	{
		if (t == NULL) return NULL;
		return (t->left ? findMin(t->left) : t);
	}

	BinaryNode* findMax(BinaryNode* t) const 
	{
		if (t == NULL) return NULL;
		return (t->right ? findMax(t->right) : t);
	}

	bool contains(const T& x, BinaryNode* t) const 
	{
		if (t == NULL) return false;
		if (x < t->element)
			return contains(x, t->left);
		else if (t->element < x)
			return contains(x, t->right);
		else
			return true;
	}

	void makeEmpty(BinaryNode*& t) 
	{
		if (t != NULL) {
			makeEmpty(t->left);
			makeEmpty(t->right);
			delete t;
		}
		t = NULL;
	}

	void remove(const T& x, BinaryNode*& t) const
	{
		if (t == NULL) return;
		if (x < t->element)
			remove(x, t->left);
		else if (t->element < x)
			remove(x, t->right);
		else {  // equal
			if (t->left && t->right) {
				BinaryNode* pMin = findMin(t->right);
				t->element = pMin->element;
				remove(pMin->element, t->right);
			} else {
				BinaryNode* old = t;
				t = t->left ? t->left : t->right;
				delete old;
			}
		}
	}

	void insert(const T& x, BinaryNode*& t) const
	{
		if (t == NULL) {
			t = new BinaryNode(x, NULL, NULL);
		} else if (x < t->element)
			insert(x, t->left);
		else if (t->element < x)
			insert(x, t->right);
	}

	BinaryNode* clone(BinaryNode* t) const
	{
		if (t == NULL)
			return NULL;
		return new BinaryNode(t->element, clone(t->left), clone(t->right));
	}

	// 前序
	void preOrder(BinaryNode* t)
	{
		if (t) {
			std::cout << t->element << ' ';
			preOrder(t->left);
			preOrder(t->right);
		}
	}

	// 中序
	void inOrder(BinaryNode* t)
	{
		if (t) {
			inOrder(t->left);
			std::cout << t->element << ' ';
			inOrder(t->right);
		}
	}

	// 后序
	void postOrder(BinaryNode* t)
	{
		if (t) {
			postOrder(t->left);
			postOrder(t->right);
			std::cout << t->element << ' ';
		}
	}


// 非递归版本
public:
	void preOrder_non_recursion()
	{
		std::stack<BinaryNode*> s;
		s.push(root_);
		while (!s.empty()) {
			BinaryNode* t = s.top();
			s.pop();
			std::cout << t->element << ' ';
			if (t->right)
				s.push(t->right);
			if (t->left)
				s.push(t->left);
		}
		std::cout << std::endl;
	}

	void inOrder_non_recursion()
	{
		std::stack<BinaryNode*> s;
		BinaryNode* pCur = root_;
		while (pCur || !s.empty()) {
			while (pCur) {
				s.push(pCur);
				pCur = pCur->left;
			}
			if (!s.empty()) {
				pCur = s.top();
				s.pop();
				std::cout << pCur->element << ' ';
				pCur = pCur->right;
			}
		}
		std::cout << std::endl;
	}

	void postOrder_non_recursion()
	{
		if (root_ == NULL)
			return;
		std::stack<std::pair<BinaryNode*, int>> s;
		s.push(std::make_pair(root_, 0));
		while (!s.empty()) {
			BinaryNode* pCur = s.top().first;
			int times = s.top().second;
			s.pop();
			if (times == 0) {  // 第一次压栈
				s.push(std::make_pair(pCur, 1));
				if (pCur->right)
					s.push(std::make_pair(pCur->right, 0));
				if (pCur->left)
					s.push(std::make_pair(pCur->left, 0));
			} else {
				std::cout << pCur->element << ' ';
			}
		}
		std::cout << std::endl;
	}


private:
	BinaryNode* root_;
};

























#endif