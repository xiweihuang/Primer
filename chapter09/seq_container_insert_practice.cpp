// 1.编写程序，从标准输入读取 string 序列，存入一个 deque 中。编写一个循环，用迭代器打印 deque 中的元素

// 2.重写上题的程序，用 list 替代 deque。列出程序要做出哪些改变。

// 3.编写程序，从一个 list<int> 拷贝元素到两个 deque 中。值为偶数的所有元素都拷贝到一个 deque 中，而奇数值元素都拷贝到另一个 deque 中。

#include <iostream>
#include <stdio.h>
#include <string>
#include <deque>
#include <list>

using namespace std;

void exercise1() {
	deque<string> ds;
	string str;
	while (cin >> str) {
		ds.push_back(str);
	}

	for (auto beg = ds.cbegin(); beg != ds.cend(); ++beg) {
		printf("%s  ", (*beg).c_str());
	}

	printf("\n");
}

void exercise2() {
	list<string> ls;
	string str;
	while (cin >> str) {
		ls.push_back(str);
	}
	for (auto beg = ls.cbegin(); beg != ls.cend(); ++beg) {
		printf("%s  ", (*beg).c_str());
	}
	printf("\n");
}

void exercise3() {
	list<int> li = {21, 412, 3, 12, 421, 7457645, 432, 41, 72, 83};
	deque<int> d1, d2;
	for (auto &val : li) {
		if (val % 2 == 0)
			d1.push_back(val);
		else
			d2.push_back(val);
	}
	for (auto &val : d1)
		printf("%d  ", val);

	printf("\n");

	for (auto &val : d2)
		printf("%d  ", val);

	printf("\n");
}

int main()
{
	// exercise1();
	// exercise2();
	exercise3();
	return 0;
}
