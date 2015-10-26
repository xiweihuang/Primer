/*

【最大子序列和】


*/

#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

// 解法1 时间复杂度O(N*N*N)
int maxSubSum1(const vector<int>& vec)
{
	int maxSum = 0;
	int vecSize = vec.size();
	for (int i = 0; i < vecSize; ++i) {
		for (int j = i; j < vecSize; ++j) {
			int thisSum = 0;

			for (int k = i; k <= j; ++k) {
				thisSum += vec[k];
			}

			if (thisSum > maxSum)
				maxSum = thisSum;

		}
	}
	return maxSum;
}


// 解法2 时间复杂度O(N*N)
int maxSubSum2(const vector<int>& vec)
{
	int maxSum = 0;
	int vecSize = vec.size();
	for (int i = 0; i < vecSize; ++i) {
		int thisSum = 0;
		for (int j = i; j < vecSize; ++j) {
			thisSum += vec[j];

			if (thisSum > maxSum)
				maxSum = thisSum;
		}
	}
	return maxSum;
}


// 解法3 O(NlogN)
/*
	“分治”策略
	把问题分为两个大致相等的子问题，然后递归地对它们求解，这是“分”的部分
	“治”阶段将两个子问题的解合并到一起并可能再做少量的附加工作，最后得到整个问题的解
*/
int maxSubSumRec(const vector<int>& a, int left, int right)
{
	if (left == right) {
		if (a[left] > 0)
			return a[left];
		return 0;
	}

	int center = (left + right) / 2;
	int maxLeftSum = maxSubSumRec(a, left, center);
	int maxRightSum = maxSubSumRec(a, center + 1, right);

	int maxLeftBorderSum = 0, leftBorderSum = 0;
	for (int i = center; i >= left; --i) {
		leftBorderSum += a[i];
		if (leftBorderSum > maxLeftBorderSum)
			maxLeftBorderSum = leftBorderSum;
	}

	int maxRightBorderSum = 0, rightBorderSum = 0;
	for (int j = center + 1; j <= right; ++j) {
		rightBorderSum += a[j];
		if (rightBorderSum > maxRightBorderSum)
			maxRightBorderSum = rightBorderSum;
	}

	return max(max(maxLeftSum, maxRightSum), (maxLeftBorderSum + maxRightBorderSum));
}
int maxSubSum3(const vector<int>& a)
{
	return maxSubSumRec(a, 0, a.size() - 1);
}


// 解法4 O(N)
int maxSubSum4(const vector<int>& a)
{
	int maxSum = 0, thisSum = 0;

	for (int j = 0; j < a.size(); ++j) {
		thisSum += a[j];

		if (thisSum > maxSum) {
			maxSum = thisSum;
		} else if (thisSum < 0) {
			thisSum = 0;
		}
	}

	return maxSum;
}

int main()
{
	vector<int> vec = {-2, 11, -4, 13, -5, -2, -2, 11, -4, 13, -5, -2, -2, 11, -4, 13, -5, -2, 
	-2, 11, -4, 13, -5, -2, -2, 11, -4, 13, -5, -2, -2, 11, -4, 13, -5, -2, -2, 11, -4, 13, -5, -2, 
-2, 11, -4, 13, -5, -2, -2, 11, -4, 13, -5, -2, -2, 11, -4, 13, -5, -2, -2, 11, -4, 13, -5, -2, -2, 11, -4, 13, -5, -2, 
-2, 11, -4, 13, -5, -2, -2, 11, -4, 13, -5, -2, -2, 11, -4, 13, -5, -2, -2, 11, -4, 13, -5, -2, 
-2, 11, -4, 13, -5, -2, -2, 11, -4, 13, -5, -2, -2, 11, -4, 13, -5, -2, -2, 11, -4, 13, -5, -2, 
-2, 11, -4, 13, -5, -2, -2, 11, -4, 13, -5, -2, -2, 11, -4, 13, -5, -2, -2, 11, -4, 13, -5, -2, 
-2, 11, -4, 13, -5, -2, -2, 11, -4, 13, -5, -2, -2, 11, -4, 13, -5, -2, -2, 11, -4, 13, -5, -2, 
-2, 11, -4, 13, -5, -2, -2, 11, -4, 13, -5, -2, -2, 11, -4, 13, -5, -2, -2, 11, -4, 13, -5, -2, 
-2, 11, -4, 13, -5, -2, -2, 11, -4, 13, -5, -2, -2, 11, -4, 13, -5, -2, -2, 11, -4, 13, -5, -2, 
-2, 11, -4, 13, -5, -2, -2, 11, -4, 13, -5, -2, -2, 11, -4, 13, -5, -2, -2, 11, -4, 13, -5, -2, -2, 11, -4, 13, -5, -2, 
-2, 11, -4, 13, -5, -2, -2, 11, -4, 13, -5, -2, -2, 11, -4, 13, -5, -2, -2, 11, -4, 13, -5, -2
};

	auto start = clock();

	int maxSum = -1;
	// maxSum = maxSubSum1(vec);
	// maxSum = maxSubSum2(vec);
	// maxSum = maxSubSum3(vec);
	maxSum = maxSubSum4(vec);


	auto finish = clock();
	auto times = (double)(finish - start)/CLOCKS_PER_SEC;
	cout << times*1000 << endl;

	cout << maxSum << endl;
	return 0;
}
