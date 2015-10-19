/**********

【排序链表中去重2】
给定排序的链表，删除重复元素，只保留重复元素第一次出现的结点
如：
给定：2->3->3->5->7->8->8->8->9->9->10
返回：2->3->5->7->8->9->10


若题目变成:若发现重复元素,则重复元素
全部删除,代码应该怎么实现呢?
如:
给定:2→3→3→5→7→8→8→8→9→9→10 
返回:2→5→7→10

**********/


#include "list_base.h"
#include <iostream>
using namespace std;

void DeleteDuplicateNode(SNode* pHead)
{
	SNode* pPre = pHead;
	SNode* pCur = pPre->pNext;
	while (pCur) {
		SNode* pNext = pCur->pNext;
		bool bDup = false;
		while (pNext && (pCur->value == pNext->value)) {
			// 删除pcur,
			pPre->pNext = pNext;
			delete pCur;
			pCur = pNext;
			pNext = pCur->pNext;
			bDup = true;
		}

		if (bDup) {  // 此刻的pCur与原数据重复，删之
			pPre->pNext = pNext;
			delete pCur;
		} else {
			pPre = pCur;
		}
		pCur = pNext;
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