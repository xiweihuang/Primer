#ifndef TREE_H
#define TREE_H

#include <iostream>

struct TreeNode
{
	int value;
	TreeNode* pLeft;
	TreeNode* pRight;
	TreeNode(int v) : value(v), pLeft(NULL), pRight(NULL) {}
};

class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();

	bool Insert(int value)
	{
		return _Insert(root_, value);
	}
	
	bool Delete(int value);

	TreeNode* Find(int value) const
	{
		return _Find(root_, value);
	}


private:
	void Destroy(TreeNode* root);

	bool _Insert(TreeNode*& root, int value)
	{
		if (!root) {
			root = new TreeNode(value);
			return true;
		}

		if (value < root->value)
			return _Insert(root->pLeft, value);
		else if (value > root->value)
			return _Insert(root->pRight, value);
		return false;

	}

	bool _Insert2(int value);

	TreeNode* _Find(TreeNode* root, int value)
	{
		if (!root)
			return NULL;
		TreeNode* pNode = root;
		while (pNode) {
			if (value < pNode->value)
				pNode = pNode->pLeft;
			else if (value > pNode->value)
				pNode = pNode->pRight
			else
				return pNode;
		}
		return NULL;
	}

private:
	TreeNode* root_;
};

#endif