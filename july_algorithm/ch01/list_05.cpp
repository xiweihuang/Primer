/**********

【排序链表中去重】
给定排序的链表，删除重复元素，只保留重复元素第一次出现的结点
如：
给定：2->3->3->5->7->8->8->8->9->9->10
返回：2->3->5->7->8->9->10

**********/

#include "list_base.h"
#include <iostream>
using namespace std;

void DeleteDuplicateNode(SNode* pHead)
{
	SNode* pCur = pHead->pNext;
	while (pCur) {
		int curVal = pCur->value;
		SNode* pNext = pCur->pNext;
		if (pNext && pNext->value == curVal) {
			pCur->pNext = pNext->pNext;
			delete pNext;
		} else {
			pCur = pCur->pNext;
		}
	}
}

void test1()
{
	SNode* pHead = new SNode(0);

	int data[] = {2, 3, 3, 5, 7, 8, 8, 8, 9, 9, 30};
	int size = sizeof(data) / sizeof(int);
	for (int i = size - 1; i >= 0; --i) {
		SNode* p = new SNode(data[i]);
		p->pNext = pHead->pNext;
		pHead->pNext = p;
	}

	Print(pHead);
	DeleteDuplicateNode(pHead);
	Print(pHead);
	Destroy(pHead);
}

int main()
{
	test1();
	return 0;
}