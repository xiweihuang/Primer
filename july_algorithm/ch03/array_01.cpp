/**********

【局部最大值】

 给定一个无重复元素的数组A[0...N-1],求 找到一个该数组的局部最大值。规定:在数 组边界外的值无穷小。即:A[0]>A[-1], A[N-1] >A[N]。
 显然,遍历一遍可以找到全局最大值,而全 局最大值显然是局部最大值。
 可否有更快的办法?

7  8  6  5  10  4

8 和 10 都是其中一个局部最大值

**********/

#include <iostream>
#include <vector>
using namespace std;

int LocalMaximum(const vector<int>& A)
{
	int left = 0;
	int right = A.size() - 1;
	int mid;
	while (left < right) {
		mid = (left + right) / 2;
		if (A[mid] > A[mid + 1])
			right = mid;
		else
			left = mid + 1;
	}
	return A[left];
}

int main()
{
	vector<int> vec = {7, 8, 6, 5, 10, 4};
	cout << LocalMaximum(vec) << endl;
	return 0;
}
