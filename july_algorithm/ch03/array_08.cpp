/**********

【字符串的全排列--非递归方法】
给定字符串 S[0...N-1]，设计算法，枚举S的全排列。

**********/

#include <iostream>
#include <vector>
#include <algorithm>
#include "RunTime.h"
using namespace std;

void Print(const vector<int>& a)
{
	for (auto& v : a) {
		cout << v << ' ';
	}
	cout << endl;
}

void Reverse(vector<int>& a, int from, int to)
{
	while (from < to) {
		swap(a[from], a[to]);
		++from;
		--to;
	}
}

bool FindNext(vector<int>& a)
{
	int i = a.size() - 2;
	while (i >= 0 && a[i] >= a[i + 1])
		--i;
	if (i < 0)
		return false;

	// index 是最后一个能增大的
	// 能增大多少？
	// 交换
	int j = a.size() - 1;
	while (a[j] <= a[i])
		j--;
	swap(a[i], a[j]);

	// 剩余部分翻转
	Reverse(a, i + 1, a.size() - 1);
	return true;
}

void Permutation(vector<int>& a)
{
	sort(a.begin(), a.end());
	// Print(a);

	while (FindNext(a)) {
		// Print(a);
	}
}

void Permutation2(vector<int>& a)
{
	sort(a.begin(), a.end());
	// Print(a);

	do {
		// Print(a);
	} while (next_permutation(a.begin(), a.end()));
}

int main()
{
	// vector<int> a = {9, 8, 7, 6, 5, 4, 3, 2, 1};
	vector<int> a = {9, 8, 7, 6, 5, 4, 3, 2, 1, 8, 7, 6};

	
	RunTime rt;
	rt.start();

	Permutation(a);
	// Permutation2(a);

	rt.stop();
	rt.show_run_time();
	return 0;
}