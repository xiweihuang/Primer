/********

【链表的部分翻转】
给定一个链表，翻转该链表从 m 到 n 的位置。
要求直接翻转而非申请新空间。
如：
给定 1->2->3->4->5, m=2, n=4
返回 1->4->3->2->5

假定给出的参数满足：1 <= m <= n <= 链表长度

********/

#include <iostream>
#include "base.h"
using namespace std;


void Reverse(SNode* pHead, int from, int to)
{
	// pHead  pPre  pCur  pNext
	// 画图来确定这几个指针有什么作用
	auto pCur = pHead->pNext;
	for (int i = 0; i < from - 1; ++i) {
		pHead = pCur;
		pCur = pCur->pNext;
	}

	auto pPre = pCur;
	pCur = pCur->pNext;
	for (int i = from; i < to; ++i) {
		auto pNext = pCur->pNext;
		pPre->pNext = pNext;
		pCur->pNext = pHead->pNext;
		pHead->pNext = pCur;
		pCur = pNext;
	}
}

void test1();

int main()
{
	test1();
	return 0;
}

void test1()
{
	SNode* pHead = new SNode(0);
	int i;
	srand(time(0));
	for (i = 0; i < 10; ++i) {
		SNode* p = new SNode(rand() % 100);
		p->pNext = pHead->pNext;
		pHead->pNext = p;
	}
	Print(pHead);
	Reverse(pHead, 2, 3);
	Print(pHead);
	Destroy(pHead);
}
