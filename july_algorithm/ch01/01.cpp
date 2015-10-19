/********

【链表相加】
给定两个链表，分别表示两个非负整数。
它们的数字逆序存储在链表中，且每个结点只存储一个数字，计算两个数的和，并且返回和的链表头指针。
如：
输入：2->4->3  5->6->4
输出：7->0->8

分析：因为两个数都是逆序存储，正好可以从头向后依次相加，完成“两个数的竖式计算”。

********/

#include <iostream>
#include "base.h"
using namespace std;


int getValueAndMove(SNode*& pNode)
{
	int value = 0;
	if (pNode) {
		value = pNode->value;
		pNode = pNode->pNext;
	}
	return value;
}


SNode* Add(SNode* pHead1, SNode* pHead2)
{
	SNode* pSum = new SNode(0);
	SNode* pTail = pSum;  // 总是指向尾结点
	SNode* p1 = pHead1->pNext;
	SNode* p2 = pHead2->pNext;
	SNode* pCur;
	int carry = 0;  // 进位
	int value;

	while (p1 || p2) {
		int val1 = getValueAndMove(p1);
		int val2 = getValueAndMove(p2);
		value = val1 + val2 + carry;
		carry = value/10;
		value %= 10;
		pCur = new SNode(value);
		pTail->pNext = pCur;
		pTail = pCur;
	}

	// 处理较长的链
	// SNode* p = p1 ? p1 : p2;
	// while (p) {
	// 	value = p->value + carry;
	// 	carry = value/10;
	// 	value %= 10;
	// 	pCur = new SNode(value);
	// 	pTail->pNext = pCur;
	// 	pTail = pCur;
	// 	p = p->pNext;
	// }

	// 处理可能存在的进位
	if (carry != 0) {
		pTail->pNext = new SNode(carry);
	}

	return pSum;
}


void test1();


int main()
{
	test1();
	return 0;
}

// 测试1
void test1()
{
	srand(time(0));

	SNode* pHead1 = new SNode(0);
	int i;
	for (int i = 0; i < 6; ++i) {
		SNode* p = new SNode(rand() % 10);
		p->pNext = pHead1->pNext;
		pHead1->pNext = p;
	}

	SNode* pHead2 = new SNode(0);
	for (int i = 0; i < 9; ++i) {
		SNode* p = new SNode(rand() % 10);
		p->pNext = pHead2->pNext;
		pHead2->pNext = p;
	}

	Print(pHead1);
	Print(pHead2);

	SNode* pSum = Add(pHead1, pHead2);
	Print(pSum);

	Destroy(pHead1);
	Destroy(pHead2);
	Destroy(pSum);

}


