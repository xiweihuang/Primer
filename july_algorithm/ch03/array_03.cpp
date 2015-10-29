/**********

【查找旋转数组的最小值】
 假定一个排序数组以某个未知元素为支点做 了旋转
如:原数组0 1 2 4 5 6 7旋转后得到 4 5 6 7 0 1 2。
请找出旋转后数组的最小值。 假定数组中没有重复数字。


**********/

#include <iostream>
#include <vector>
using namespace std;

int FindMin(const vector<int>& num)
{
	int left = 0;
	int right = num.size() - 1;
	while (left < right) {
		int mid = (right + left) / 2;
		if (num[mid] > num[right])
			left = mid + 1;
		else if (num[mid] < num[right])
			right = mid;
	}
	return num[left];
}

int main()
{
	vector<int> num = {4, 5, 6, -1, 0, 1, 2};
	cout << FindMin(num) << endl;
	return 0;
}