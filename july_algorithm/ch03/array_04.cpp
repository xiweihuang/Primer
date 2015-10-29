/**********

【零子数组】
 求对于长度为N的数组A,求连续子数组的 和最接近0的值。
如:
 数组A、1, -2, 3, 10, -4, 7, 2, -5
 它是所有子数组中,和最接近0的是哪个?


思考:如果需要返回绝对值最小的子数组本 身呢?

**********/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class PreSum
{
public:
	PreSum(int sum = 0, int index = 0) : sum_(sum), index_(index) {}
	bool operator<(PreSum& rhs)
	{
		return sum_ < rhs.sum_;
	}
	int operator-(const PreSum& rhs)
	{
		return sum_ - rhs.sum_;
	}
public:
	int sum_;
	int index_;
};


int MinSubArray(const int* a, const int size)
{
	// PreSum sum[size];
	vector<PreSum> sum;
	sum.emplace_back(0, 0);
	for (int i = 1; i < size; ++i) {
		int cur_sum = sum.back().sum_ + a[i];
		sum.emplace_back(cur_sum, i);
	}
	sort(sum.begin(), sum.end());
	// sort(sum);

	int minSum = abs(sum[0] - sum[1]);
	for (int i = 1; i < sum.size() - 1; ++i) {
		int dis = abs(sum[i] - sum[i + 1]);
		if (dis < minSum) {
			minSum = dis;
		}
	}
	return minSum;
}

// int MinSubArray(const int* a, const int size)
// {
// 	int sum[size];
// 	sum[0] = 0;
// 	for (int i = 1; i < size; ++i) {
// 		sum[i] = sum[i-1] + a[i];
// 	}
// 	sort(sum, sum+size);

// 	int minSum = abs(sum[0] - sum[1]);
// 	for (int i = 1; i < size - 1; ++i) {
// 		int dis = abs(sum[i] - sum[i+1]);
// 		if (dis < minSum) {
// 			minSum = dis;
// 		}
// 	}
// 	return minSum;
// }

int main()
{
	int a[] = {1, -2, 3, 10, -4, 7, 2, -5};
	cout << MinSubArray(a, sizeof(a) / sizeof(int)) << endl;
	return 0;
}