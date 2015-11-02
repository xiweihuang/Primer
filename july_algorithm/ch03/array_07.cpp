/**********

【字符串的全排列--递归方法】
给定字符串 S[0...N-1]，设计算法，枚举S的全排列。

**********/

#include <iostream>
#include <vector>
#include <unordered_map>
#include "RunTime.h"
using namespace std;

void Print(const vector<int>& a)
{
	for (auto& v : a) {
		cout << v << ' ';
	}
	cout << endl;
}

// 有重复字符的情况
// 第i个字符（前）与第j个字符（后）交换时，要求[i,j)中没有与第j个字符相等的数
bool IsDuplicate(const vector<int>& a, int n, int t)
{
	while (n < t) {
		if (a[n] == a[t])
			return true;
		n++;
	}
	return false;
}

void Permutation(vector<int>& a, int n)
{
	if (n == a.size() - 1) {
		// Print(a);
		return;
	}
	for (int i = n; i < a.size(); ++i) {
		if (!IsDuplicate(a, n, i)) {
			swap(a[i], a[n]);
			Permutation(a, n+1);
			swap(a[i], a[n]);
		}
	}
}

// 空间换时间的做法（为什么实测这种做法反而更慢？不用 unordered_map 呢？）
void Permutation2(vector<int>& a, int n)
{
	if (n == a.size() - 1) {
		// Print(a);
		return;
	}
	unordered_map<int, bool> dup;
	for (int i = n; i < a.size(); ++i) {
		if (dup.find(a[i]) == dup.end()) {
			dup[a[i]] = true;
			swap(a[i], a[n]);
			Permutation2(a, n + 1);
			swap(a[i], a[n]);
		}
	}
}

int main()
{
	vector<int> a = {9, 8, 7, 6, 5, 4, 3, 2, 1, 8, 7, 6};
	
	RunTime rt;
	rt.start();

	Permutation(a, 0);
	// Permutation2(a, 0);

	rt.stop();
	rt.show_run_time();

	return 0;
}