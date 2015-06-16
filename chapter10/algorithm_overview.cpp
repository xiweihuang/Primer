#include <algorithm>
#include <vector>
#include <iostream>
#include <deque>
#include <list>

using namespace std;

void test() {
	// int arr[] = {10, 20, 30};
	// vector<int> vec(arr, arr+3);
	// vector<int> vec = {10, 20, 30};
	// int val = 20;
	// auto result = find(vec.begin(), vec.end(), val);
	// cout << *result << endl;

	int ia[] = {27, 210, 12, 47, 109, 83};
	int val = 83;
	int *result = find(ia, ia+5, val);
	if (result != ia+5)
		printf("%d\n", *result);
	else
		printf("can't find\n");
}

void exercise1();

int main()
{
	// test();
	exercise1();
	return 0;
}

void exercise1() {
	// list<int> vi = {10, 20, 10, 30, 40, 50, 10, 60};
	vector<int> vi = {10, 20, 10, 30, 40, 50, 10, 60};
	auto times = count(vi.begin(), vi.begin()+6, 10); // 支持快速随机访问的，迭代器才能夸很多个元素来加。string  vector  deque
	printf("%ld\n", times);

	list<string> ls = {"Kobe", "Jordan", "Kobe", "James", "Durcant", "Kobe"};
	auto iter_end = ls.begin();
	for (int i = 0; i != 2; ++i) {
		++iter_end;
	}
	auto times2 = count(ls.begin(), iter_end, "Kobe");
	printf("%ld\n", times2);
}