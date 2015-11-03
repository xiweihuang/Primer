/**********

【Cantor数组】
已知数组A[0...N-1]乱序着前N个正整数，现统计后缀数组A[i+1...N-1]中小于元素A[i]的数目，并存放在数组C[i]中。
如：A={4,6,2,5,3,1}，得到数组C={3,4,1,2,1,0}。
问：给定数组C={3,4,1,2,1,0}，如何恢复数组A？

我们称A为原数组，C为Cantor数组。

**********/

#include <iostream>
#include <vector>
using namespace std;

void CantorExpansion(const vector<int>& a, vector<int>& b)
{
	for (int i = 0; i < a.size(); ++i) {
		int cnt = 0;
		for (int j = i + 1; j < a.size(); ++j) {
			if (a[j] < a[i]) {
				++cnt;
			}
		}
		b.push_back(cnt);
	}
}

void CantorExpansionR(const vector<int>& a, vector<int>& result)
{
	// 取值范围
	vector<int> pat = {10, 13, 18, 20, 31};
	for (int i = 0; i < a.size(); ++i) {
		result.push_back(pat[a[i]]);
		pat.erase(pat.begin() + a[i]);
	}
}



int main()
{
	// vector<int> a = {4, 6, 2, 5, 3, 1};
	// vector<int> b;
	// CantorExpansion(a, b);

	vector<int> result;
	vector<int> b = { 3, 1, 2, 0, 0 };
	CantorExpansionR(b, result);

	for (auto& v : result) {
		cout << v << ' ';
	}
	cout << endl;
	return 0;
}
