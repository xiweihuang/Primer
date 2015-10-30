/**********

【最大间隔】
给定整数数组A[0...N-1]，求这N个数排序后最大间隔。
如：1，7，14，9，4，13的最大间隔为4


**********/

#include <iostream>
using namespace std;

struct SBucket
{
	bool bValid;
	int nMin;
	int nMax;

	SBucket() : bValid(false) {}

	void Add(int n)
	{
		if (!bValid) {
			nMin = nMax = n;
			bValid = true;
		} else {
			if (n > nMax)
				nMax = n;
			else if (n < nMin)
				nMin = n;
		}
	}
};

int CalcMaxGap(const int* A, const int size)
{
	SBucket* pBucket = new SBucket[size];
	int nMax = A[0];
	int nMin = A[0];
	for (int i = 1; i < size; ++i) {
		if (nMax < A[i])
			nMax = A[i];
		else if (nMin > A[i])
			nMin = A[i];
	}

	// 依次将数据放入桶中
	int delta = nMax - nMin;
	int nBucket;  // 某个数应该在哪个桶中
	for (int i = 0; i < size; ++i) {
		nBucket = (A[i] - nMin) * size / delta;
		if (nBucket >= size) {
			nBucket = size - 1;
		}
		pBucket[nBucket].Add(A[i]);
	}

	// 计算有效桶的间隔
	int i = 0;
	int nGap = delta / size;
	int gap;
	for (int j = 1; j < size; ++j) {  // i是前一个桶，j是后一个桶
		if (pBucket[j].bValid) {
			gap = pBucket[j].nMin - pBucket[i].nMax;
			if (nGap < gap)
				nGap = gap;
			i = j;
		}
	}

	delete[] pBucket;
	return nGap;
}

int main()
{
	int A[] = {1, 7, 14, 9, 4, 13};
	cout << CalcMaxGap(A, sizeof(A) / sizeof(int)) << endl;
	return 0;
}

