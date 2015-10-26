/*

【运行时间中的对数】

三个例子：
1.二分搜索  O(logN)  (128, 64, 32, 16, 8, 4, 2, 1, 0, -1)这样子理解
  对于数据稳定(不允许插入和删除)的应用中，非常有用

2.欧几里得算法

3.幂运算

*/

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
int binarySearch(const vector<T>& a, const T& x)
{
	int left = 0;
	int right = a.size() - 1;

	while (left <= right) {
		int mid = (right + left) / 2;
		if (a[mid] == x) {
			return mid;
		} else if (a[mid] > x) {
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}

	return -1;
}



int main()
{
	vector<int> vec = {7, 8, 11, 21, 45, 67, 89};
	int index = binarySearch(vec, 8);
	cout << index << endl;
	return 0;
}
