// 插入迭代器
#include <stdio.h>
#include <vector>
#include <deque>
#include <list>

using namespace std;

void inserter() {
	vector<int> vi = {1, 2, 3, 4, 5};
	auto it = inserter(vi, vi.begin());
	*it = 20;
	*it = 30;
	for (auto &val : vi)
		printf("%d\n", val);
}

void output_int(const list<int> &lst) {
	for (auto &val : lst) {
		printf("%d\n", val);
	}
	printf("=====\n");
}

void frontInserter() {
	list<int> lst = {1, 2, 3, 4};
	list<int> lst2, lst3;
	copy(lst.cbegin(), lst.cend(), front_inserter(lst2));  // 4 3 2 1
	copy(lst.cbegin(), lst.cend(), inserter(lst3, lst3.begin()));  // 1 2 3 4

	output_int(lst2);
	printf("=====\n");
	output_int(lst3);
}

void output_deque();
void exercise_10_27();
void exercise_10_28();


int main()
{
	// inserter();
	// frontInserter();
	// exercise_10_27();
	exercise_10_28();
	return 0;
}


// 10.27
void exercise_10_27() {
	vector<int> vi = {2, 1, 2, 3, 5, 5, 8, 2};
	sort(vi.begin(), vi.end());

	list<int> lst;
	unique_copy(vi.begin(), vi.end(), back_inserter(lst));
	for (auto &val : lst) {
		printf("%d\n", val);
	}
}

void output_deque(const deque<int> &deq) {
	for (auto &val : deq)
		printf("%d\n", val);
	printf("=====\n");
}

void exercise_10_28() {
	vector<int> vi = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	deque<int> deq1, deq2, deq3;
	copy(vi.begin(), vi.end(), back_inserter(deq1));  // 1 2 3 ...
	copy(vi.begin(), vi.end(), front_inserter(deq2));  // 9 8 7 ...
	copy(vi.begin(), vi.end(), inserter(deq3, deq3.begin()));  // 1 2 3 4 5 6 7 8 9

	// output_deque(deq1);
	// output_deque(deq2);
	// output_deque(deq3);

	list<int> lst1, lst2, lst3;
	copy(vi.begin(), vi.end(), back_inserter(lst1));
	copy(vi.begin(), vi.end(), front_inserter(lst2));
	copy(vi.begin(), vi.end(), inserter(lst3, lst3.end()));

	output_int(lst1);
	output_int(lst2);
	output_int(lst3);
}













