#ifndef base_h
#define base_h

#include <iostream>

typedef struct tagSNode
{
	int value;
	tagSNode* pNext;
	tagSNode(int v) : value(v), pNext(NULL) {}
}SNode;

void Print(SNode* p)
{
	if (p) {
		auto pCur = p->pNext;
		while (pCur) {
			auto value = pCur->value;
			std::cout << value;
			pCur = pCur->pNext;
			if (pCur)
				std::cout << "->";
		}
		std::cout << std::endl;
	}
}

void Destroy(SNode* p)
{
	SNode* next;
	while (p) {
		next = p->pNext;
		delete p;
		p = next;

	}
}

#endif