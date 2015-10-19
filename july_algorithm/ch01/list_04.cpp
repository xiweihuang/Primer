/**********

【链表划分】
给定一个链表和一个值x，将链表划分成两部分，使得划分后小于x的结点在前，大于等于x的结点在后。
在这两部分中要保持原链表中的出现顺序。
如：
给定链表 1->4->3->2->5->2 和 x = 3，返回 1->2->2->4->3->5

**********/


#include "list_base.h"
#include <iostream>
using namespace std;

void Partition(SNode* pHead, int pivotKey)
{
	// 两个链表的头指针
	SNode s1(0);
	SNode s2(0);
	auto pLeftHead = &s1;
	auto pRightHead = &s2;

	// 两个链表的当前最后一个元素
	auto left = pLeftHead;
	auto right = pRightHead;
	auto pCur = pHead->pNext;
	while (pCur) {
		auto value = pCur->value;

		if (value < pivotKey) {
			left->pNext = pCur;
			left = pCur;
		} else {
			right->pNext = pCur;
			right = pCur;
		}

		pCur = pCur->pNext;
	}

	// 将right链接到left尾部
	left->pNext = pRightHead->pNext;
	right->pNext = NULL;

	// 将整理好的链表赋值给当前链表头部
	pHead->pNext = pLeftHead->pNext;

}

void test1()
{
	srand(time(0));
	SNode* pHead = new SNode(0);
	for (int i = 0; i < 10; ++i) {
		SNode* p = new SNode(rand() % 100);
		p->pNext = pHead->pNext;
		pHead->pNext = p;
	}

	Print(pHead);
	Partition(pHead, 30);
	Print(pHead);
	Destroy(pHead);
}



int main()
{
	test1();
	return 0;
}


