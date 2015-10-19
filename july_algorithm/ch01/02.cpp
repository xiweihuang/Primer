/********

【链表相加】
给定两个链表，分别表示两个非负整数。
它们的数字逆序存储在链表中，且每个结点只存储一个数字，计算两个数的和，并且返回和的链表头指针。
如：
输入：2->4->3  5->6->4
输出：7->0->8

【用stl的list实现】

********/
#include <iostream>
#include <memory>
#include <list>
using namespace std;


shared_ptr<list<int>> Add(list<int>& list1, list<int>& list2)
{
	auto pSum = make_shared<list<int>>();
	auto p1 = list1.begin();
	auto p2 = list2.begin();
	int carry = 0;
	int value = 0;

	for (; p1 != list1.end() && p2 != list2.end(); ++p1, ++p2) {
		auto sum = *p1 + *p2 + carry;
		carry = sum/10;
		value = sum%10;
		pSum->push_back(value);
	}

	auto pb = p1 != list1.end() ? p1 : p2;
	auto pe = p1 != list1.end() ? list1.end() : list2.end();
	for (; pb != pe; ++pb) {
		auto sum = *pb + carry;
		carry = sum/10;
		value = sum%10;
		pSum->push_back(value);
	}

	if (carry != 0) {
		pSum->push_back(carry);
	}

	return pSum;
}


void print(const list<int>& li)
{
	for (const auto& v : li) {
		cout << v << "->";
	}
	cout << endl;
}


void test1()
{
	srand(time(0));

	list<int> list1;
	for (int i = 0; i < 6; ++i) {
		list1.push_back(rand() % 10);
	}

	list<int> list2;
	for (int i = 0; i < 9; ++i) {
		list2.push_back(rand() % 10);
	}

	print(list1);
	print(list2);

	auto list_sum = Add(list1, list2);
	print(*list_sum);

}

int main()
{
	test1();
	return 0;
}